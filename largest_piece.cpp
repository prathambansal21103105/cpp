#include <iostream>
#include <vector>
using namespace std;

int helper(vector<vector<int>> &cake, int n, int r, int c, int **visited){
    // cout<<r<<" "<<c<<endl;
    if(cake[r][c]==1 and visited[r][c]==0){
        visited[r][c]=1;
    }
    int a=1;
    if(r+1<n and r+1>=0 and c<n and c>=0 and cake[r+1][c]==1 and visited[r+1][c]==0){
        // cout<<"r+1"<<endl;
        a=a+helper(cake,n,r+1,c,visited);
    }
    // cout<<a<<endl;
    if(r-1<n and r-1>=0 and c<n and c>=0 and cake[r-1][c]==1 and visited[r-1][c]==0){
        a=a+helper(cake,n,r-1,c,visited);
    }
    // cout<<a<<r<<c<<endl;
    if(r<n and r>=0 and c+1<n and c+1>=0 and cake[r][c+1]==1 and visited[r][c+1]==0){
        // cout<<"c+1"<<endl;
        a=a+helper(cake,n,r,c+1,visited);
    }
    // cout<<a<<endl;
    if(r<n and r>=0 and c-1<n and c-1>=0 and cake[r][c-1]==1 and visited[r][c-1]==0){
        a=a+helper(cake,n,r,c-1,visited);
    }
    // cout<<a<<endl;
    return a;
}
int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    int**visited=new int*[n];
    for(int i=0;i<n;i++){
        visited[i]=new int[n];
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
    int r=0;
    int c=0;
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cake[i][j]==1){
                r=i;
                c=j;
                flag=1;
            }
        }
    }
    if(flag==0){
        return 0;
    }
    int max1=helper(cake,n,r,c,visited);
    // cout<<max1<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0 and cake[i][j]==1){
                max1=max(max1,helper(cake,n,i,j,visited));
            }
        }
    }
    return max1;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}