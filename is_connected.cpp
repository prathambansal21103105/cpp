#include<iostream>
using namespace std;

void getdfs(int **edges, int curr, int n, bool *visited){
    visited[curr]=true;
    for(int i=0;i<n;i++){
        if(edges[curr][i]==1 and visited[i]==false){
            getdfs(edges,i,n,visited);
        }
    }
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
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    getdfs(edges,0,v,visited);
    int flag=0;
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            flag=1;
            break;
        }
    }
    if(flag==1){
        cout<<"false"<<endl;
    }
    else{
        cout<<"true"<<endl;
    }

    return 0;
}