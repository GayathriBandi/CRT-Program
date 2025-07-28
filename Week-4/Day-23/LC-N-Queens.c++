The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]
#include <vector>
#include <string>
#include <functional>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        
        std::vector<int> col_occupied(n, 0);
        std::vector<int> diag_occupied(2 * n, 0);
        std::vector<int> anti_diag_occupied(2 * n, 0);
      
        std::vector<std::vector<std::string>> solutions;
      
        std::vector<std::string> board(n, std::string(n, '.'));
      
        std::function<void(int)> backtrack = [&](int row) -> void {
            if (row == n) {
                solutions.push_back(board);
                return;
            }

            for (int column = 0; column < n; ++column) {
                if (!col_occupied[column] && !diag_occupied[row + column] 
                    && !anti_diag_occupied[n - row + column]) {
              
                    board[row][column] = 'Q';
                    col_occupied[column] = diag_occupied[row + column]
                        = anti_diag_occupied[n - row + column] = 1;
                  
                    backtrack(row + 1);
                  
                    col_occupied[column] = diag_occupied[row + column]
                        = anti_diag_occupied[n - row + column] = 0;
                    board[row][column] = '.';
                }
            }
        };

        backtrack(0);
        return solutions;
    }
};
