#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100  // 定义图的最大节点数

// 定义队列结构
typedef struct {
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;

// 初始化队列
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// 判断队列是否为空
int isEmpty(Queue* q) {
    return q->front == -1;
}

// 向队列中插入元素
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue is full\n");
        return;
    } else {
        if (q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// 从队列中取出元素
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

// 广度优先搜索函数
void bfs(int graph[MAX_NODES][MAX_NODES], int startNode, int n) {
    int visited[MAX_NODES] = {0};  // 初始化所有节点为未访问状态
    Queue q;
    initQueue(&q);

    // 访问起始节点并加入队列
    visited[startNode] = 1;
    enqueue(&q, startNode);

    printf("BFS traversal starting from node %d:\n", startNode);

    while (!isEmpty(&q)) {
        int currentNode = dequeue(&q);
        printf("%d ", currentNode);

        // 检查所有邻接节点
        for (int i = 0; i < n; i++) {
            if (graph[currentNode][i] == 1 && !visited[i]) {  // 如果节点相连且未访问
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, startNode;
    int graph[MAX_NODES][MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    bfs(graph, startNode, n);

    return 0;
}
