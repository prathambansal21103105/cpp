#include<iostream>
#include<climits>
using namespace std;

void primsalgo(int** edges, bool* visited, int* weight, int* parent, int v){
    int vertex=0;
    int count=0;
    while(count<v-1){
        visited[vertex]=true;
        count+=1;
        for(int i=0;i<v;i++){
            if(edges[vertex][i]!=0){
                if(edges[vertex][i]<weight[i] and visited[i]==false){
                    weight[i]=edges[vertex][i];
                    parent[i]=vertex;
                }
            }
        }
        int min1=INT_MAX;
        for(int i=0;i<v;i++){
            if(weight[i]<min1 and visited[i]==false){
                min1=weight[i];
                vertex=i;
            }
        }
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    int** edges=new int*[v];
    for(int i=0;i<v;i++){
        edges[i]=new int[v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[a][b]=c;
        edges[b][a]=c;
    }
    bool* visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    int*weight=new int[v];
    for(int i=0;i<v;i++){
        weight[i]=INT_MAX;
    }
    int*parent=new int[v];
    parent[0]=-1;
    weight[0]=0;
    primsalgo(edges,visited,weight,parent,v);
    for(int i=1;i<v;i++){
        if(i<parent[i]){
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
        else{
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
    }
    return 0;
}