# 📘 Graph Theory – Day 20 (CRT Program)

---

## 📌 Graph Basics

- **Graph**: A graph is a pair `G = (V, E)` where `V` is a set of vertices and `E` is a set of edges connecting pairs of vertices.
- **Order of Graph**: Number of vertices in a graph.
- **Size of Graph**: Number of edges in a graph.
- **Vertex Degree**: Number of edges incident to a vertex.
  - **In-degree (for Directed Graph)**: Number of incoming edges.
  - **Out-degree (for Directed Graph)**: Number of outgoing edges.
- **Undirected Edge**: Edge without direction (e.g., A—B).
- **Directed Edge**: Edge with direction (e.g., A → B).

---

## 📌 Types of Graphs

- **Finite Graph**: A graph with a finite number of vertices and edges.
- **Infinite Graph**: A graph with infinitely many vertices/edges.
- **Trivial Graph**: A graph with only one vertex and no edges.
- **Simple Graph**: No loops or multiple edges between the same pair of vertices.
- **Multi Graph**: Can have multiple edges (parallel edges) between the same pair of vertices.
- **Null Graph**: A graph with no edges.
- **Complete Graph**: Every pair of distinct vertices is connected by an edge. Denoted as `Kₙ`.
- **Pseudo Graph**: A graph that allows loops and multiple edges.
- **Regular Graph**: Every vertex has the same degree.
- **Bipartite Graph**: Vertices can be divided into two disjoint sets such that every edge connects a vertex from one set to the other.
- **Labelled Graph**: Vertices or edges have labels (names/values).
- **Digraph (Directed Graph)**: A graph where edges have directions.
- **Cycle**: A path that starts and ends at the same vertex.
- **Cyclic Graph**: A graph that contains at least one cycle.
- **Subgraph**: A graph formed from a subset of vertices and edges of another graph.
- **Connected Graph**: There exists a path between every pair of vertices.
- **Disconnected Graph**: Some vertices are not reachable from others.
- **Acyclic Graph**: A graph without any cycles.
- **DAG (Directed Acyclic Graph)**: A directed graph with no cycles.
- **Planar Graph**: Can be drawn on a plane without edges crossing.
- **Eulerian Graph**: A graph containing an Eulerian circuit (visit every edge exactly once).
- **Hamiltonian Graph**: Contains a Hamiltonian cycle (visit every vertex exactly once).

---

## 📌 Degree Sequence

The degree sequence of a graph is a non-increasing sequence of vertex degrees.

Example:  
If degrees are `[3, 2, 2, 1]` → Degree sequence is `[3, 2, 2, 1]`.

---

## 📌 Havel-Hakimi Algorithm in C

```c
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int havelHakimi(int degree[], int n) {
    while (1) {
        qsort(degree, n, sizeof(int), compare);

        while (n > 0 && degree[0] == 0)
            n--;

        if (n == 0) return 1;

        int d = degree[0];
        for (int i = 1; i <= d; i++) {
            if (i >= n) return 0;
            degree[i]--;
            if (degree[i] < 0) return 0;
        }
        degree[0] = 0;
    }
}

int main() {
    int degree[] = {3, 3, 2, 2, 2};
    int n = sizeof(degree) / sizeof(degree[0]);

    if (havelHakimi(degree, n))
        printf("The sequence is graphical.\n");
    else
        printf("The sequence is not graphical.\n");

    return 0;
}
```

---

## 📌 Adjacency Matrix in C

```c
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Adjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

---

## 📌 Depth First Search (DFS) in C

```c
#include <stdio.h>

int adj[10][10], visited[10], n;

void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);
    return 0;
}
```

---

## 📌 Breadth First Search (BFS) in C

```c
#include <stdio.h>

int adj[10][10], visited[10], n, queue[10], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == 9) return;
    queue[++rear] = v;
    if (front == -1) front = 0;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void bfs(int start) {
    enqueue(start);
    visited[start] = 1;

    while ((start = dequeue()) != -1) {
        printf("%d ", start);
        for (int i = 0; i < n; i++) {
            if (adj[start][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);
    return 0;
}
```

---

📝 *Save this file as* `graphs.md` and use it for your CRT prep!

