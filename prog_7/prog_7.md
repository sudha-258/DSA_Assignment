# Dijkstra’s Shortest Path Algorithm

This project implements **Dijkstra’s Algorithm** using an adjacency matrix representation. The program calculates the shortest distance from a single source vertex to all other vertices in a weighted graph.

---

## (a) Data Structure Definition

The implementation relies on several key data structures:

* **Adjacency Matrix (`graph[MAX][MAX]`)**: A 2D array where `graph[i][j]` represents the weight of the edge between vertex `i` and vertex `j`. A value of `0` indicates no direct edge exists.
* **Distance Array (`distance[MAX]`)**: Stores the current shortest distance from the source to each vertex. It is initialized to `INF` (Infinity).
* **Visited Array (`visited[MAX]`)**: A boolean-style array that keeps track of vertices whose shortest distance from the source is already finalized.



---

## (b) Function Descriptions

### 1. `int min_distance(int distance[], int visited[], int n)`
* **Purpose**: To find the unvisited vertex with the minimum distance value.
* **Logic**: It iterates through the `distance` array and returns the index of the vertex that has the smallest value and hasn't been "visited" yet. This is the "Greedy" step of the algorithm.

### 2. `void dijkstra(int graph[MAX][MAX], int n, int source)`
* **Purpose**: The core logic of the algorithm.
* **Logic**:
    1.  **Initialization**: Sets all distances to `INF` and the `source` distance to `0`.
    2.  **Relaxation**: For each vertex, it explores its neighbors. If a shorter path is found through the current vertex $u$ to a neighbor $v$, the distance to $v$ is updated:
        $$distance[v] = distance[u] + graph[u][v]$$
    3.  **Completion**: The process repeats until all reachable vertices are visited.



---

## (c) Main Method Organization

The `main()` function handles the user interface and program flow:

1.  **Graph Input**: Collects the number of vertices and the full adjacency matrix (weights).
2.  **Source Selection**: Asks the user which vertex should be the starting point.
3.  **Execution**: Passes the graph data to the `dijkstra` function.
4.  **Result Display**: Outputs a formatted table showing the shortest distance from the source to every other vertex in the graph.

---

## (d) Sample Output
```text
Enter number of vertices: 3
Enter adjacency matrix (0 if no edge):
0 4 8
4 0 2
8 2 0
Enter source vertex: 0

Vertex 	 Distance from Source
0 	 0
1 	 4
2 	 6

