The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. 
In this process, births and deaths occur simultaneously.

Given the current state of the board, update the board to reflect its next state.

Note that you do not need to return anything.

 

Example 1:
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
  
Example 2:
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
void gameOfLife(int** board, int boardSize, int* boardColSize) {
    int m = boardSize;
    int n = *boardColSize;
    
    int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                      {0, -1},          {0, 1},
                      {1, -1},  {1, 0}, {1, 1}};
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int liveNeighbors = 0;
            for (int d = 0; d < 8; d++) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    if (board[ni][nj] == 1 || board[ni][nj] == 2)
                        liveNeighbors++;
                }
            }
            
            if (board[i][j] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3)
                    board[i][j] = 2;
            } else {
                if (liveNeighbors == 3)
                    board[i][j] = 3;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 2)
                board[i][j] = 0;
            else if (board[i][j] == 3)
                board[i][j] = 1;
        }
    }
}
