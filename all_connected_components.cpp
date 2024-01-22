#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void getdfs(int **edges, int curr, int n, bool *visited, vector<int> &v1){
    visited[curr]=true;
    v1.push_back(curr);
    for(int i=0;i<n;i++){
        if(edges[curr][i]==1 and visited[i]==false){
            getdfs(edges,i,n,visited,v1);
        }
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    if(v==0){
        return 0;
    }
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
    vector<int>v1;
    vector<vector<int> > output;
    getdfs(edges,0,v,visited,v1);
    sort(v1.begin(),v1.end());
    output.push_back(v1);
    for(int i=0;i<v;i++){
        vector<int>vnew;
        if(visited[i]==false){
            getdfs(edges,i,v,visited,vnew);
            sort(vnew.begin(),vnew.end());
            output.push_back(vnew);
        }
    }
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}