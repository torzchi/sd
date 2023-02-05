#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int n;                                                // number of vertices
int adj_mat[MAX_VERTICES][MAX_VERTICES];            // adjacency matrix
int visited[MAX_VERTICES];                           // keep track of visited vertices

void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++) {
        if (adj_mat[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

struct Queue {
    int front, rear;
    int items[MAX_VERTICES];
};

struct Queue* create_queue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool is_empty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
    q->items[++q->rear] = value;
}

int dequeue(struct Queue* q) {
    return q->items[++q->front];
}

void bfs(int start) {
    struct Queue* q = create_queue();
    int i;
    visited[start] = true;
    enqueue(q, start);
    while (!is_empty(q)) {
        int v = dequeue(q);
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (adj_mat[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(q, i);
            }
        }
    }
}

int main() {
    int i, j, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj_mat[i][j]);
        }
        visited[i] = 0;
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    dfs(start);
    return 0;
}
