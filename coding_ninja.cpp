#include <iostream>
#include <vector>
using namespace std;

bool helper(vector<vector<char>> &board,int n, int m, int r, int c, string str, int**visited){
    // cout<<r<<" "<<c<<endl;
    if(str.length()==1){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(r-1+i>=0 and c-1+j>=0 and r-1+i<n and c-1+j<m and visited[r-1+i][c-1+j]==0 and board[r-1+i][c-1+j]==str[0]){
                    visited[r-1+i][c-1+j]=1;
                    return true;
                }
            }
        }
        return false;
    }
    char target=str[0];
    // cout<<target<<endl;
    bool a=false;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(r-1+i>=0 and c-1+j>=0 and r-1+i<n and c-1+j<m and visited[r-1+i][c-1+j]==0 and board[r-1+i][c-1+j]==str[0]){
                // cout<<board[r-1+i][c-1+j]<<" "<<str[0]<<endl;
                visited[r-1+i][c-1+j]=1;
                // cout<<"yes"<<endl;
                a= a or helper(board,n,m,r-1+i,c-1+j,str.substr(1),visited);
                if(a==true){
                    return true;
                }
                else{
                    // cout<<"yes"<<" "<<str[0]<<endl;
                    visited[r-1+i][c-1+j]=0;
                }
            }
        }
    }
    return a;
}
bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    string target="CODINGNINJA";
    int r,c;
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='C'){
                r=i;
                c=j;
                flag=1;
            }
        }
    }
    if(flag==0){
        return false;
    }
    else{
        int **visited=new int*[n];
        for(int i=0;i<n;i++){
            visited[i]=new int[m];
            for(int j=0;j<m;j++){
                visited[i][j]=0;
            }
        }
        bool a=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='C'){
                    r=i;
                    c=j;
                    visited[r][c]=1;
                    a=a or helper(board,n,m,r,c,target.substr(1),visited);
                }
                if(a==false){
                    visited[r][c]=0;
                }
            }
        }
        return a;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}