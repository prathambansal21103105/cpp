#include<iostream>
using namespace std;

bool haspath(int **edges, int start, int end, int n, bool *visited){
    if(start==end){
        return true;
    }
    visited[start]=true;
    bool a=false;
    for(int i=0;i<n;i++){
        if(edges[start][i]==1 and visited[i]==false){
            a=a or haspath(edges,i,end,n,visited);
        }
    }
    return a;
}
int main(){
    int v,e;
    cin>>v>>e;
    int **edges=new int*[v];
    for(int i=0;i<v;i++){
        edges[i]=new int[v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    int start,end;
    cin>>start>>end;
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    if(haspath(edges,start,end,v,visited)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}