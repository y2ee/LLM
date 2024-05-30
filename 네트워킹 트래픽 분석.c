//winpcap ��ġ �ʿ�

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <graphviz/cgraph.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 1000

// �׷��� ����ü
typedef struct {
    Agnode_t* nodes[MAX_NODES];
    Agedge_t* edges[MAX_EDGES];
    int node_count;
    int edge_count;
} Graph;

// ��Ŷ �м� �Լ�
void analyze_packet(const u_char* packet, int packet_size, Graph* graph) {
    // Ethernet ��� ũ��� 14����Ʈ
    const int ETHERNET_HEADER_SIZE = 14;
    // IPv4 ������� �۽��� IP �ּ��� �������� 26����Ʈ
    const int SOURCE_IP_OFFSET = 26;
    // IPv4 ������� ������ IP �ּ��� �������� 30����Ʈ
    const int DESTINATION_IP_OFFSET = 30;

    // ��Ŷ�� Ethernet ���������� Ȯ��
    if (packet_size < ETHERNET_HEADER_SIZE) {
        fprintf(stderr, "Invalid packet size.\n");
        return;
    }

    // Ethernet �����ӿ��� IP ��Ŷ���� Ȯ��
    if (packet[12] != 0x08 || packet[13] != 0x00) {
        // 0x0800�� IPv4 ���������� ��Ÿ��
        return;
    }

    // �۽��� IP �ּ� ����
    char source_ip[INET_ADDRSTRLEN];
    snprintf(source_ip, INET_ADDRSTRLEN, "%d.%d.%d.%d",
        packet[SOURCE_IP_OFFSET],
        packet[SOURCE_IP_OFFSET + 1],
        packet[SOURCE_IP_OFFSET + 2],
        packet[SOURCE_IP_OFFSET + 3]);

    // ������ IP �ּ� ����
    char destination_ip[INET_ADDRSTRLEN];
    snprintf(destination_ip, INET_ADDRSTRLEN, "%d.%d.%d.%d",
        packet[DESTINATION_IP_OFFSET],
        packet[DESTINATION_IP_OFFSET + 1],
        packet[DESTINATION_IP_OFFSET + 2],
        packet[DESTINATION_IP_OFFSET + 3]);

    // �۽����� ������ ��� �߰�
    Agnode_t* source_node = agnode(graph, source_ip, 1);
    Agnode_t* destination_node = agnode(graph, destination_ip, 1);
    add_node(graph, source_node);
    add_node(graph, destination_node);

    // ���� �߰�
    Agedge_t* edge = agedge(graph, source_node, destination_node, NULL, 1);
    add_edge(graph, edge);
}

// ��Ŷ ó�� �ݹ� �Լ�
void packet_handler(u_char* user_data, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    Graph* graph = (Graph*)user_data;
    analyze_packet(packet, pkthdr->caplen, graph);
}

// �׷��� �ʱ�ȭ �Լ�
void initialize_graph(Graph* graph) {
    graph->node_count = 0;
    graph->edge_count = 0;
}

// �׷����� ��� �߰� �Լ�
void add_node(Graph* graph, Agnode_t* node) {
    if (graph->node_count < MAX_NODES) {
        graph->nodes[graph->node_count++] = node;
    }
    else {
        fprintf(stderr, "Maximum number of nodes reached.\n");
    }
}

// �׷����� ���� �߰� �Լ�
void add_edge(Graph* graph, Agedge_t* edge) {
    if (graph->edge_count < MAX_EDGES) {
        graph->edges[graph->edge_count++] = edge;
    }
    else {
        fprintf(stderr, "Maximum number of edges reached.\n");
    }
}

// ���� ���� �Լ� (����: ������ �����Ǿ��ٰ� ���)
void detect_routing(Graph* graph) {
    printf("Routing detected!\n");
}

// ���� ���� ���� �Լ� (����: ���� ������ �����Ǿ��ٰ� ���)
void detect_routing_loop(Graph* graph) {
    printf("Routing loop detected!\n");
}

// ��Ʈ��ũ Ʈ���� ���� �м� �Լ� (����: Ʈ���� ������ �м��Ͽ��ٰ� ���)
void analyze_traffic_pattern(Graph* graph) {
    printf("Traffic pattern analyzed!\n");
}

// ���� �Լ�
int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    Graph graph;

    // pcap �ڵ� ����
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf); // ��Ʈ��ũ �������̽� �̸��� �°� ����

    if (handle == NULL) {
        fprintf(stderr, "Could not open device: %s\n", errbuf);
        return 1;
    }

    // �׷��� �ʱ�ȭ
    initialize_graph(&graph);

    // ��Ŷ ĸó �� ó��
    pcap_loop(handle, 0, packet_handler, (u_char*)&graph);

    // ���� ����
    detect_routing(&graph);

    // ���� ���� ����
    detect_routing_loop(&graph);

    // ��Ʈ��ũ Ʈ���� ���� �м�
    analyze_traffic_pattern(&graph);

    // pcap �ڵ� ����
    pcap_close(handle);

    return 0;
}
