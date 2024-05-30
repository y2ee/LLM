//winpcap 설치 필요

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <graphviz/cgraph.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 1000

// 그래프 구조체
typedef struct {
    Agnode_t* nodes[MAX_NODES];
    Agedge_t* edges[MAX_EDGES];
    int node_count;
    int edge_count;
} Graph;

// 패킷 분석 함수
void analyze_packet(const u_char* packet, int packet_size, Graph* graph) {
    // Ethernet 헤더 크기는 14바이트
    const int ETHERNET_HEADER_SIZE = 14;
    // IPv4 헤더에서 송신지 IP 주소의 오프셋은 26바이트
    const int SOURCE_IP_OFFSET = 26;
    // IPv4 헤더에서 목적지 IP 주소의 오프셋은 30바이트
    const int DESTINATION_IP_OFFSET = 30;

    // 패킷이 Ethernet 프레임인지 확인
    if (packet_size < ETHERNET_HEADER_SIZE) {
        fprintf(stderr, "Invalid packet size.\n");
        return;
    }

    // Ethernet 프레임에서 IP 패킷인지 확인
    if (packet[12] != 0x08 || packet[13] != 0x00) {
        // 0x0800은 IPv4 프로토콜을 나타냄
        return;
    }

    // 송신지 IP 주소 추출
    char source_ip[INET_ADDRSTRLEN];
    snprintf(source_ip, INET_ADDRSTRLEN, "%d.%d.%d.%d",
        packet[SOURCE_IP_OFFSET],
        packet[SOURCE_IP_OFFSET + 1],
        packet[SOURCE_IP_OFFSET + 2],
        packet[SOURCE_IP_OFFSET + 3]);

    // 목적지 IP 주소 추출
    char destination_ip[INET_ADDRSTRLEN];
    snprintf(destination_ip, INET_ADDRSTRLEN, "%d.%d.%d.%d",
        packet[DESTINATION_IP_OFFSET],
        packet[DESTINATION_IP_OFFSET + 1],
        packet[DESTINATION_IP_OFFSET + 2],
        packet[DESTINATION_IP_OFFSET + 3]);

    // 송신지와 목적지 노드 추가
    Agnode_t* source_node = agnode(graph, source_ip, 1);
    Agnode_t* destination_node = agnode(graph, destination_ip, 1);
    add_node(graph, source_node);
    add_node(graph, destination_node);

    // 엣지 추가
    Agedge_t* edge = agedge(graph, source_node, destination_node, NULL, 1);
    add_edge(graph, edge);
}

// 패킷 처리 콜백 함수
void packet_handler(u_char* user_data, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    Graph* graph = (Graph*)user_data;
    analyze_packet(packet, pkthdr->caplen, graph);
}

// 그래프 초기화 함수
void initialize_graph(Graph* graph) {
    graph->node_count = 0;
    graph->edge_count = 0;
}

// 그래프에 노드 추가 함수
void add_node(Graph* graph, Agnode_t* node) {
    if (graph->node_count < MAX_NODES) {
        graph->nodes[graph->node_count++] = node;
    }
    else {
        fprintf(stderr, "Maximum number of nodes reached.\n");
    }
}

// 그래프에 엣지 추가 함수
void add_edge(Graph* graph, Agedge_t* edge) {
    if (graph->edge_count < MAX_EDGES) {
        graph->edges[graph->edge_count++] = edge;
    }
    else {
        fprintf(stderr, "Maximum number of edges reached.\n");
    }
}

// 루팅 검출 함수 (예제: 루팅이 감지되었다고 출력)
void detect_routing(Graph* graph) {
    printf("Routing detected!\n");
}

// 루팅 루프 검출 함수 (예제: 루팅 루프가 감지되었다고 출력)
void detect_routing_loop(Graph* graph) {
    printf("Routing loop detected!\n");
}

// 네트워크 트래픽 패턴 분석 함수 (예제: 트래픽 패턴을 분석하였다고 출력)
void analyze_traffic_pattern(Graph* graph) {
    printf("Traffic pattern analyzed!\n");
}

// 메인 함수
int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    Graph graph;

    // pcap 핸들 생성
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf); // 네트워크 인터페이스 이름에 맞게 수정

    if (handle == NULL) {
        fprintf(stderr, "Could not open device: %s\n", errbuf);
        return 1;
    }

    // 그래프 초기화
    initialize_graph(&graph);

    // 패킷 캡처 및 처리
    pcap_loop(handle, 0, packet_handler, (u_char*)&graph);

    // 루팅 검출
    detect_routing(&graph);

    // 루팅 루프 검출
    detect_routing_loop(&graph);

    // 네트워크 트래픽 패턴 분석
    analyze_traffic_pattern(&graph);

    // pcap 핸들 종료
    pcap_close(handle);

    return 0;
}
