// rank ����� ���� ���� (�׷��� ���α׷� ���ᰡ �� ��)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_URL_LENGTH 1024
#define MAX_PAGES 5
#define DAMPING_FACTOR 0.85
#define EPSILON 0.0001

// �׷��� ��带 ��Ÿ���� ����ü
typedef struct Node {
    char url[MAX_URL_LENGTH];
    struct Node* edges[MAX_PAGES];
    int num_edges;
    float page_rank;
} Node;

// �׷����� ��Ÿ���� ����ü
typedef struct Graph {
    Node nodes[MAX_PAGES];
    int num_nodes;
} Graph;

// �� ũ�ѷ� �Լ�
void crawl(Graph* graph, Node* node) {
    printf("Crawling %s\n", node->url);
    // ������������ �����۸�ũ ����
    // ������ ��ũ�� �׷����� �߰��ϰ� ���� ����
}

// ������ ��ŷ ��� �Լ�
void calculate_page_rank(Graph* graph) {
    int i, j;
    float initial_rank = 1.0 / graph->num_nodes;

    // �ʱ� ������ ��ũ ����
    for (i = 0; i < graph->num_nodes; i++) {
        graph->nodes[i].page_rank = initial_rank;
    }

    bool has_converged = false;
    float diff;
    float new_rank[MAX_PAGES];

    // ������ ��ŷ �ݺ� ���
    while (!has_converged) {
        for (i = 0; i < graph->num_nodes; i++) {
            new_rank[i] = (1 - DAMPING_FACTOR) / graph->num_nodes;

            for (j = 0; j < graph->nodes[i].num_edges; j++) {
                Node* neighbor = graph->nodes[i].edges[j];
                new_rank[i] += DAMPING_FACTOR * neighbor->page_rank / neighbor->num_edges;
            }
        }

        // ���� ���� Ȯ��
        diff = 0;
        for (i = 0; i < graph->num_nodes; i++) {
            diff += fabs(new_rank[i] - graph->nodes[i].page_rank);
        }

        if (diff < EPSILON)
            has_converged = true;

        // ���ο� ������ ��ũ ����
        for (i = 0; i < graph->num_nodes; i++) {
            graph->nodes[i].page_rank = new_rank[i];
        }
    }
}

int main() {
    // �ʱ� �׷��� ����
    Graph graph;
    graph.num_nodes = 0;

    // �׷����� �ʱ� ��� �߰�
    strcpy(graph.nodes[graph.num_nodes].url, "http://example.com/page1");
    graph.nodes[graph.num_nodes++].num_edges = 0;

    // �߰� ������ �߰� �� ����
    strcpy(graph.nodes[graph.num_nodes].url, "http://example.com/page2");
    graph.nodes[graph.num_nodes].edges[0] = &graph.nodes[0];
    graph.nodes[graph.num_nodes].num_edges = 1;
    graph.num_nodes++;

    strcpy(graph.nodes[graph.num_nodes].url, "http://example.com/page3");
    graph.nodes[graph.num_nodes].edges[0] = &graph.nodes[0];
    graph.nodes[graph.num_nodes].edges[1] = &graph.nodes[1];
    graph.nodes[graph.num_nodes].num_edges = 2;
    graph.num_nodes++;

    strcpy(graph.nodes[graph.num_nodes].url, "http://example.com/page4");
    graph.nodes[graph.num_nodes].edges[0] = &graph.nodes[0];
    graph.nodes[graph.num_nodes].edges[1] = &graph.nodes[1];
    graph.nodes[graph.num_nodes].edges[2] = &graph.nodes[2];
    graph.nodes[graph.num_nodes].num_edges = 3;
    graph.num_nodes++;

    strcpy(graph.nodes[graph.num_nodes].url, "http://example.com/page5");
    graph.nodes[graph.num_nodes].edges[0] = &graph.nodes[0];
    graph.nodes[graph.num_nodes].edges[1] = &graph.nodes[1];
    graph.nodes[graph.num_nodes].edges[2] = &graph.nodes[2];
    graph.nodes[graph.num_nodes].edges[3] = &graph.nodes[3];
    graph.nodes[graph.num_nodes].num_edges = 4;
    graph.num_nodes++;

    // �׷��� ũ�Ѹ�
    for (int i = 0; i < graph.num_nodes; i++) {
        crawl(&graph, &graph.nodes[i]);
    }

    // ������ ��ŷ ���
    calculate_page_rank(&graph);

    // ��� ���
    for (int i = 0; i < graph.num_nodes; i++) {
        printf("Page: %s, Rank: %f\n", graph.nodes[i].url, graph.nodes[i].page_rank);
    }

    return 0;
}
