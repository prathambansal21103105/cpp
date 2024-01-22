#include<iostream>
#include<climits>
using namespace std;

void dijkstrasalgo(int** edges, bool* visited, int* distance, int v){
    int vertex=0;
    int count=0;
    while(count<v){
        visited[vertex]=true;
        for(int i=0;i<v;i++){
            if(edges[vertex][i]!=0 and visited[i]==false){
                if(distance[vertex]+edges[vertex][i]<distance[i]){
                    distance[i]=distance[vertex]+edges[vertex][i];
                }
            }
        }
        int min1=INT_MAX;
        for(int i=0;i<v;i++){
            if(distance[i]<min1 and visited[i]==false){
                min1=distance[i];
                vertex=i;
            }
        }
        count++;
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
    int* distance=new int[v];
    for(int i=0;i<v;i++){
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    dijkstrasalgo(edges,visited,distance,v);
    for(int i=0;i<v;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    return 0;
}