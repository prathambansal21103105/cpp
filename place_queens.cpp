#include <bits/stdc++.h>
using namespace std;
int board[11][11];
bool checkpossible(int n, int r, int c) {
  for (int i = r - 1; i >= 0; i--) {
    if (board[i][c] == 1) {
      return false;
    }
  }
  for (int i = r - 1, j = c - 1; i >= 0 and j >= 0; i--, j--) {
    if (board[i][j] == 1) {
      return false;
    }
  }
  for (int i = r - 1, j = c + 1; i >= 0 and j < n; i--, j++) {
    if (board[i][j] == 1) {
      return false;
    }
  }
  return true;
}
void helpersolve(int n, int r) {
  if (r == n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << board[i][j] << " ";
      }
    }
    cout << endl;
    return;
  } else {
    for (int j = 0; j < n; j++) {
      if (checkpossible(n, r, j)) {
        board[r][j] = 1;
        helpersolve(n, r + 1);
        board[r][j] = 0;
      }
    }
  }
  return;
}
void placenqueens(int n) {
  memset(board, 0, 11 * 11 * sizeof(int));
  helpersolve(n, 0);
}
int main() {
  int n;
  cin >> n;
  placenqueens(n);
  return 0;
}