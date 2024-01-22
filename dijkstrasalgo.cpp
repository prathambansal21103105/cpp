#include<iostream>
#include<climits>
using namespace std;

void dijkstrasalgo(int v, int e, int** adj, bool visited[], int path[]){
  int vertex=0;
  int iter=v;
  
  while(iter>0){
    visited[vertex]=true;
    path[0]=0;
    for(int i=0;i<v;i++){
      if(adj[vertex][i]!=0 and visited[i]==false){
        if(adj[vertex][i]+path[vertex]<path[i]){
          path[i]=adj[vertex][i]+path[vertex];
        }
      }
    }
    int min1=INT_MAX;
    int index1=0;
    for(int i=0;i<v;i++){
      if (path[i] < min1 and i != vertex and visited[i] == false) {
        min1 = path[i];
        index1 = i;
      }
    }
    vertex = index1;
    iter-=1;
  }
  for(int i=0;i<v;i++){
    cout<<i<<" "<<path[i]<<endl;
  }
}

int main(){
  int v,e;
  cin>>v>>e;

  int**adj=new int*[v];
  for(int i=0;i<v;i++){
    adj[i]=new int[v];
    for(int j=0;j<v;j++){
      adj[i][j]=0;
    }
  }
  for(int i=0;i<e;i++){
    int a,b,c;
    cin>>a>>b>>c;
    adj[a][b]=c;
    adj[b][a]=c;
  }
  bool visited[v];
  for(int i=0;i<v;i++){
    visited[i]=false;
  }
  int path[v];
  for(int i=0;i<v;i++){
    path[i]=INT_MAX;
  }

  dijkstrasalgo(v,e,adj,visited,path);

  return 0;
}