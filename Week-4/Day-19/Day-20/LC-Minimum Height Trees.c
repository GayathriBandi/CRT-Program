A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
Return a list of all MHTs' root labels. You can return the answer in any order
The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

Example 1:
Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.

Example 2:
Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
 
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20000

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* graph[MAX_NODES];
int degree[MAX_NODES];
int queue[MAX_NODES];
int visited[MAX_NODES];

void addEdge(int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = v;
    node->next = graph[u];
    graph[u] = node;
}

int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    if (n == 1) {
        int* res = (int*)malloc(sizeof(int));
        res[0] = 0;
        *returnSize = 1;
        return res;
    }

    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
        degree[i] = 0;
        visited[i] = 0;
    }

    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        addEdge(a, b);
        addEdge(b, a);
        degree[a]++;
        degree[b]++;
    }

    int head = 0, tail = 0;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1) {
            queue[tail++] = i;
            visited[i] = 1;
        }
    }

    int remaining = n;
    while (remaining > 2) {
        int size = tail - head;
        remaining -= size;

        for (int i = 0; i < size; i++) {
            int leaf = queue[head++];
            Node* curr = graph[leaf];
            while (curr) {
                int neighbor = curr->val;
                if (!visited[neighbor]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        queue[tail++] = neighbor;
                        visited[neighbor] = 1;
                    }
                }
                curr = curr->next;
            }
        }
    }

    int count = tail - head;
    int* res = (int*)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        res[i] = queue[head + i];
    }
    *returnSize = count;
    return res;
}
