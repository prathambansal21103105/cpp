#include<iostream>
#include<vector>
using namespace std;

int getIndex(vector<int>v,int k){
    int s=-1;
    for(int i=0;i<v.size();i++){
        if (v[i]==k){
            s=i;
            break;
        }
    }
    return s;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        vector<int>v;
        vector<int>::iterator it;
        it=v.begin();
        while(n>0){
            int ai;
            cin>>ai;
            if(getIndex(v,ai)==-1){
                v.push_back(ai);
            }
            else{
                int x=getIndex(v,ai);
                v.erase(it+x);
                cout<<v.size()<<endl;
            }    
            n-=1;
        }
        t-=1;
    }
    return 0;
}