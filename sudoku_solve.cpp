#include<iostream>
using namespace std;
#define N 9

bool findEmptyLocation(int grid[N][N],int &row,int &col){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]==0){
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
bool isSafeInRow(int grid[N][N],int row,int num){
    for(int i=0;i<N;i++){
        if(grid[row][i]==num){
            return false;
        }
    }
    return true;
}
bool isSafeInColumn(int grid[N][N], int col, int num){
    for(int i=0;i<N;i++){
        if(grid[i][col]==num){
            return false;   
        }
    }
    return true;
}
bool isSafeInGrid(int grid[N][N],int row,int col,int num){
    
    int rowFactor=row-(row%3);
    int colFactor=col-(col%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i+rowFactor][j+colFactor]==num){
                return false;
            }
        }
    }
    return true;
}
bool isSafe(int grid[N][N],int row, int col, int num){
    return isSafeInRow(grid,row,num) and isSafeInColumn(grid,col,num) and isSafeInGrid(grid,row,col,num);
}
bool solveSudoku(int grid[N][N]){
    int row,col;
    if(!findEmptyLocation(grid,row,col)){
        return true;
    }
    for(int i=1;i<=9;i++){
        if(isSafe(grid,row,col,i)){
            grid[row][col]=i;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col]=0;
        }
    }
    return false;
}
int main(){
    int grid[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>grid[i][j];
        }
    }
    // for(int i=0;i<N;i++){
    //     string s;
    //     cin>>s;
    //     for(int j=0;j<s.length();j++){
    //         grid[i][j]=s[j]-'0';
    //     }
    // }
    if(solveSudoku(grid)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    // cout<<endl;
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout<<grid[i][j];
    //     }
    //     cout<<endl;
    // }
    return 0;
}
/*
900020750 
600050040 
020400010 
208000000 
070509060 
000000401
010005080
090070004 
082040006
*/