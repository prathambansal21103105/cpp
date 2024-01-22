#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        set<int>a;
        int c[n];
        for(int i=0;i<n;i++){
            cin>>c[i];
            a.insert(c[i]);
        }
        if(a.size()==n){
        vector<int>v1;
        vector<int>v2;
        int flag1=0;
            for(int i=0;i<n;i+=1){
                if(flag1==1){
                    v2.push_back(c[i]);
                }
                else if(c[i]<=c[0] and flag1==0){
                    v1.push_back(c[i]);
                }
                else{
                    flag1=1;
                    v2.push_back(c[i]);
                }
            }
        if(v1.empty() or v2.empty()){
            cout<<-1<<endl;
        }
        else{
        cout<<v1.size()<<endl;
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
        cout<<v2.size()<<endl;
        for(int i=0;i<v2.size();i++){
            cout<<v2[i]<<" ";
        }
        cout<<endl;
        }
        }
        else{
            cout<<-1<<endl;
        }
        t-=1;
    }
    return 0;
}