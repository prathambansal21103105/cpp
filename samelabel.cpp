#include<iostream>
#include<vector>
#include<string>
using namespace std;

int dfs(int start, vector<int> adj[], int visited[], string labels, char target, int check[]){
    visited[start]=1;
    int retval=0;
    if(labels[start]==target){
        retval+=1;
    }
    for(int i=0;i<adj[start].size();i++){
        if(visited[adj[start][i]]==0 and check[adj[start][i]]==0){
            retval+=dfs(adj[start][i],adj,visited,labels,target,check);
        }
    }
    return retval;
}

void bfs(int start,vector<int>& bfsarr,vector<int>adj[],vector<int>& seq){
    int visited[100000]={0};
    bfsarr.push_back(start);
    seq.push_back(start);
    while(bfsarr.size()!=0){
        int front=bfsarr[0];
        visited[front]=1;
        bfsarr.erase(bfsarr.begin());
        for(int i=0;i<adj[front].size();i++){
            if(visited[adj[front][i]]==0){
                bfsarr.push_back(adj[front][i]);
                seq.push_back(adj[front][i]);    
            }
        }
    }
}

vector<int> countSubTrees(int n, vector<vector<int> > edges, string labels){
    vector<int>adj[n];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    int check[n];
    for(int i=0;i<n;i++){
        check[i]=0;
    }
    
    vector<int>bfsarr;
    vector<int>seq;
    bfs(0,bfsarr,adj,seq);
    int ans[100000]={0};
    for(int i=0;i<seq.size();i++){
        int visited[100000]={0};
        ans[seq[i]]=dfs(seq[i],adj,visited,labels,labels[seq[i]],check);
        check[seq[i]]=1;
    }
    vector<int>ans2;
    for(int j=0;j<n;j++){
        ans2.push_back(ans[j]);
    }
    return ans2;
}
    
int main(){

    int n;
    cin>>n;

    vector<vector<int> >edges;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        vector<int>v;
        v.push_back(a);
        v.push_back(b);
        edges.push_back(v);
    }

    string labels;
    cin>>labels;

    vector<int>ans=countSubTrees(n,edges,labels);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}