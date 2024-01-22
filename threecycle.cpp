#include <iostream>
using namespace std;

int cycle(int**edges, int n, int num, int curr, int count){
    // cout<<num<<" "<<curr<<endl;
    // cout<<count<<endl;
    if(count==3 and num==curr){
        // cout<<"yes"<<endl;
        // cout<<num<<" "<<curr<<endl;
        return 1;
    }
    if(count==3){
        return 0;
    }
    if(count==0){
        int ans=0;
        for(int i=0;i<n;i++){
            if(i>curr and edges[curr][i]==1){
                ans+=cycle(edges,n,num,i,count+1);
            }
        }
        return ans;
    }
    else if(count==2){
        int ans=0;
        for(int i=0;i<n;i++){
            if(i!=curr and edges[curr][i]==1){
                ans+=cycle(edges,n,num,i,count+1);
                if(ans==1){
                    return ans;
                }
            }
        }
        return ans;
    }
    else if(count==1){
        int ans=0;
        for(int i=0;i<n;i++){
            if(i!=num and i!=curr and edges[curr][i]==1){
                ans+=cycle(edges,n,num,i,count+1);
            }
        }
        return ans;
    }
}
int main() {
    // Write your code here
    int n,m;
    cin>>n>>m;
    int**edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    // int*visited=new int[n];
    // for(int i=0;i<n;i++){
    //     visited[i]=0;
    // }
    if(n==0){
        cout<<0<<endl;
    }
    else{
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=cycle(edges,n, i, i, 0);    
            // cout<<"ans"<<i<<ans<<endl;
        }
        cout<<ans/3<<endl;
    }
    return 0;
}