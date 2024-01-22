#include<iostream>
using namespace std;

void bfs(int**edges, int n, int curr, bool* visited){
    queue <int>q;
    q.push(curr);
    while(!q.empty()){
        if(visited[q.front()]==true){
            q.pop();
        }
        else{
            cout<<q.front()<<" ";
            visited[q.front()]=true;
            int f=q.front();
            q.pop();
            for(int i=0;i<n;i++){
                if(i==f){
                    continue;
                }
                if(edges[f][i]==1){
                    if(visited[i]){
                        continue;
                    } 
                    else {
                        q.push(i);
                    }
                }
            }
        }
    }
}
void dfs(int** edges,int n,int sv,bool* visited){
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            dfs(edges,n,i,visited);
        }
    }
}
int main(){
    int n;
    int e;
    cin>>n>>e;
    int**edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    dfs(edges,n,0,visited);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(edges,n,i,visited)
        }
    }
    return 0;
}