//Tomas Czerniawski. Student

// Algorytmow śledzenia wstecznego

// 2023.02.01

# Backtracking_Algorithms 

Pseudokod:

```
bool isSafe(board[][N], row, col) {
  

  
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

 
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

  
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}


bool solveNQueens( board[][N], row) {
    if (row >= N)
        return true;

    for (col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

```
