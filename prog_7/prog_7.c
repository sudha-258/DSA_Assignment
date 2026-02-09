#include <stdio.h>
#define INF 9999
#define MAX 10

int min_distance(int distance[], int visited[], int n) {
    int min = INF, min_index;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && distance[i] <= min) {
            min = distance[i];
            min_index= i;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int n, int source) {
    int distance[MAX], visited[MAX];

    // Initialize distances and visited array
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[source] = 0;

    // Main loop
    for (int count = 0; count < n - 1; count++) {
        int u = min_distance(distance, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] &&
                distance[u] != INF &&
                distance[u] + graph[u][v] < distance[v]) {

                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    // Print result
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, distance[i]);
    }
}

int main() {
    int n, source;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, n, source);

    return 0;
}