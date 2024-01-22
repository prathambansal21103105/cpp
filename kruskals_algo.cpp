#include <iostream>
#include<algorithm>
using namespace std;

class edge{
    public:
    int st;
    int end;
    int weight;
};
bool myfunc(edge a,edge b){
    if(a.weight<b.weight){
        return true;
    }
    else{
        return false;
    }
}

void kruskalsalgo(edge* edges,int v,int e,int* parent, edge*mst){
    int j=0;
    for(int i=0;i<e;i++){
        if(j==v-1){
            break;
        }
        edge curr=edges[i];
        int sv=curr.st;
        int ev=curr.end;
        if(parent[sv]==sv and parent[ev]==ev){
            mst[j]=curr;
            j++;
            parent[sv]=parent[ev];
        }
        else{
            int temp1=sv;
            int temp2=ev;
            while(temp1!=parent[temp1]){
                temp1=parent[temp1];
            }
            while(temp2!=parent[temp2]){
                temp2=parent[temp2];
            }
            if(temp1!=temp2){
                mst[j]=curr;
                j++;
                parent[temp1]=temp2;
            }
            else{
                continue;
            }
        }
    }
}
int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;

    edge* input= new edge[e];
    for(int i=0;i<e;i++){
        edge e;
        cin>>e.st>>e.end>>e.weight;
        input[i]=e;
    }
    sort(input,input+e,myfunc);
    int* parent=new int[v];
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    edge* mst=new edge[v-1];
    kruskalsalgo(input,v,e,parent,mst);
    for(int i=0;i<v-1;i++){
        if(mst[i].st<mst[i].end){
            cout<<mst[i].st<<" "<<mst[i].end<<" "<<mst[i].weight<<endl;    
        }
        else{
            cout<<mst[i].end<<" "<<mst[i].st<<" "<<mst[i].weight<<endl;
        }
    }
    return 0;
}