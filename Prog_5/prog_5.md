# Graph Traversal: BFS and DFS using Adjacency Matrix

This project implements an **undirected graph** using a 2D array (Adjacency Matrix) and provides two fundamental traversal algorithms: Breadth-First Search (BFS) and Depth-First Search (DFS).

---

## (a) Data Structure Definition

The graph is represented using an **Adjacency Matrix**, which is a square matrix used to represent a finite graph.

* **`adjacency_matrix[MAX][MAX]`**: A 2D array where `matrix[i][j] = 1` indicates an edge exists between vertex `i` and vertex `j`. For an undirected graph, the matrix is symmetric ($matrix[i][j] = matrix[j][i]$).
* **`visited[MAX]`**: An array used to keep track of vertices already processed during traversal to prevent infinite loops.
* **`MAX`**: A constant defining the maximum number of vertices the graph can hold.



---

## (b) Function Descriptions

### 1. `void DFS(int v)` (Depth-First Search)
* **Purpose**: Traverses the graph by going as deep as possible along each branch before backtracking.
* **Logic**: It uses **Recursion** (system stack). 
    * Mark the current vertex as visited and print it.
    * For every adjacent vertex that hasn't been visited, call `DFS` recursively.

### 2. `void BFS(int start)` (Breadth-First Search)
* **Purpose**: Traverses the graph level by level, visiting all neighbors of a node before moving to the next level.
* **Logic**: It uses an **Iterative approach with a Queue**.
    *  Place the starting vertex in a queue and mark it as visited.
    *  While the queue is not empty, dequeue a vertex, print it, and enqueue all its unvisited neighbors.



---

## (c) Main Method Organization

The `main()` function manages the graph's lifecycle through these stages:

1.  **Graph Setup**: It prompts the user for the number of vertices and initializes the matrix with `0` (no edges).
2.  **Edge Input**: It accepts pairs of vertices $(u, v)$. Because the graph is **undirected**, it sets both `matrix[u][v]` and `matrix[v][u]` to `1`.
3.  **BFS Execution**: Resets the `visited` array and calls the `BFS` function starting from vertex 0.
4.  **DFS Execution**: Resets the `visited` array again and calls the `DFS` function starting from vertex 0.

---

## (d) Sample Output

Consider a graph with 4 vertices forming a square with one diagonal: (0-1, 1-2, 2-3, 3-0, 0-2).

```text
Enter number of vertices: 4
Enter number of edges: 5
Enter edges (u v):
0 1
1 2
2 3
3 0
0 2

BFS traversal starting from vertex 0:
0 1 2 3 

DFS traversal starting from vertex 0:
0 1 2 3

