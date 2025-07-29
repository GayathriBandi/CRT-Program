#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool dfs(char** board, int m, int n, int i, int j, char* word, int index, bool** visited) {
    if (word[index] == '\0') return true;
    if (i < 0 || i >= m || j < 0 || j >= n) return false;
    if (visited[i][j] || board[i][j] != word[index]) return false;

    visited[i][j] = true;

    bool found =
        dfs(board, m, n, i + 1, j, word, index + 1, visited) ||
        dfs(board, m, n, i - 1, j, word, index + 1, visited) ||
        dfs(board, m, n, i, j + 1, word, index + 1, visited) ||
        dfs(board, m, n, i, j - 1, word, index + 1, visited);

    visited[i][j] = false;
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int m = boardSize;
    int n = boardColSize[0];
    bool** visited = (bool**)malloc(m * sizeof(bool*));
    for (int i = 0; i < m; i++) {
        visited[i] = (bool*)calloc(n, sizeof(bool));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0]) {
                if (dfs(board, m, n, i, j, word, 0, visited)) {
                    for (int k = 0; k < m; k++) free(visited[k]);
                    free(visited);
                    return true;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) free(visited[i]);
    free(visited);
    return false;
}
