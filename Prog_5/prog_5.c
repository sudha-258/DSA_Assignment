#include<stdio.h>
#define MAX 20

int adjacency_matrix[MAX][MAX];
int visited[MAX];
int n;

void DFS(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (adjacency_matrix[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    int i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adjacency_matrix[v][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}


int main() {
    int i, j, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // initialize adjacency matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adjacency_matrix[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adjacency_matrix[u][v] = 1;
        adjacency_matrix[v][u] = 1;   // undirected graph
    }

    printf("\nBFS traversal starting from vertex 0:\n");
    BFS(0);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\n\nDFS traversal starting from vertex 0:\n");
    DFS(0);

    return 0;
}