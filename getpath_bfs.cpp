#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

bool getpathbfs(int **edges, int start, int end, int n, bool *visited, unordered_map<int,int> &map1){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int f=q.front();
        if(f==end){
            return true;
        }
        visited[f]=true;
        q.pop();
        for(int i=0;i<n;i++){
            if(edges[f][i]==1 and visited[i]==false){
                q.push(i);
                if(map1.count(i)==0){
                    map1[i]=f;
                }
            }
        }
    }
    return false;
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
    int start,end;
    cin>>start>>end;
    unordered_map<int,int>map1;
    if(getpathbfs(edges,start,end,v,visited,map1)){
        int curr=end;
        int goal=start;
        vector<int> v1;
        while(curr!=goal){
            v1.push_back(curr);
            curr=map1[curr];
        }
        v1.push_back(curr);
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}