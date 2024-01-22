#include <bits/stdc++.h>
#include <vector>
using namespace std;
int x=1;
int board[18][18];
void mazepath(int **input, int n, int row, int col,int rest) {
  if (row == n - 1 and col == n - 1 and input[n - 1][n - 1] == 1) {
    board[row][col]=1;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<board[i][j]<<" ";
      }
    }
    cout<<endl;
    return;
  } 
  else {
    if (input[row][col] == 1) {
      board[row][col]=1;
      int board1[18][18]={0};
      for(int i=0;i<18;i++){
        for(int j=0;j<18;j++){
          board1[i][j]=board[i][j];
        }
      }
      if (row + 1 < n) {
        if(rest==1){
          x+=1;
        }
        else{
          if (input[row + 1][col] == 1 and board[row+1][col]==0) {
            mazepath(input, n, row + 1, col, 3);
          }
          for(int i=0;i<18;i++){
            for(int j=0;j<18;j++){
              board[i][j]=board1[i][j];
            }
          }
        }
      }
      if (col + 1 < n) {
        if(rest==2){
          x+=1;
        }
        else{
          if (input[row][col + 1] == 1 and board[row][col+1]==0) {
            mazepath(input, n, row, col + 1, 4);
          }
          for(int i=0;i<18;i++){
            for(int j=0;j<18;j++){
              board[i][j]=board1[i][j];
            }
          }
        }
      }
      if(row-1>=0){
        if(rest==3){
          x+=1;
        }
        else{
          if (input[row - 1][col] == 1 and board[row-1][col]==0) {
            mazepath(input, n, row - 1, col, 1);
          }
          for(int i=0;i<18;i++){
            for(int j=0;j<18;j++){
              board[i][j]=board1[i][j];
            }
          }
        }
      }
      if(col-1>=0){
        if(rest==4){
          x+=1;
        }
        else{
          if (input[row][col - 1] == 1 and board[row][col-1]==0) {
            mazepath(input, n, row, col - 1, 2);
          }
          for(int i=0;i<18;i++){
            for(int j=0;j<18;j++){
              board[i][j]=board1[i][j];
            }
          }
        }
      }
      return;
    }
    else{
      return;
    }
  }
}
int main() {
  int n;
  cin >> n;
  int **input = new int *[n];
  int arr[n][n];

  for (int i = 0; i < n; i++) {
    input[i] = new int[n];
    for (int j = 0; j < n; j++) {
      cin >> input[i][j];
    }
  }
  vector<int> up;
  for (int i = 0; i < n * n; i++) {
    up.push_back(0);
  }
  memset(board,0,18*18*sizeof(int));
  mazepath(input, n, 0, 0, 0);
  return 0;
}