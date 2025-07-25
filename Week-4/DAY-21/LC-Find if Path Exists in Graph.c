There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
You want to determine if there is a valid path that exists from vertex source to vertex destination.
Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

Example 1:
Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
  
Example 2:
Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.

#include <stdlib.h>
#include <stdbool.h>

// Helper DFS function
bool dfs(int node, int destination, bool* visited, int** graph, int* graphColSize) {
    if (node == destination) return true;
    visited[node] = true;

    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, destination, visited, graph, graphColSize)) {
                return true;
            }
        }
    }

    return false;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    // Step 1: Build adjacency list
    int** graph = (int**)malloc(sizeof(int*) * n);
    int* graphColSize = (int*)calloc(n, sizeof(int));
    int* graphCap = (int*)calloc(n, sizeof(int));  // track current allocated size

    // Allocate initial space for neighbors (dynamically grow if needed)
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(sizeof(int) * 2);  // start with small space
        graphCap[i] = 2;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Add v to u's list
        if (graphColSize[u] == graphCap[u]) {
            graphCap[u] *= 2;
            graph[u] = (int*)realloc(graph[u], sizeof(int) * graphCap[u]);
        }
        graph[u][graphColSize[u]++] = v;

        // Add u to v's list (since undirected)
        if (graphColSize[v] == graphCap[v]) {
            graphCap[v] *= 2;
            graph[v] = (int*)realloc(graph[v], sizeof(int) * graphCap[v]);
        }
        graph[v][graphColSize[v]++] = u;
    }

    // Step 2: DFS traversal
    bool* visited = (bool*)calloc(n, sizeof(bool));
    bool result = dfs(source, destination, visited, graph, graphColSize);

    // Cleanup
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(graphColSize);
    free(graphCap);
    free(visited);

    return result;
}
