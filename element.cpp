#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t>0){
        int n;
        cin>>n;

        vector<int>v;
        int fre[200001];
        for(int i=0;i<200001;i++){
            fre[i]=2;
        }
        int flag=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            fre[x]-=1;
            if(fre[x]<0){
                flag=1;
                break;
            }
        }
        if(flag==1){
            cout<<"NO"<<endl;
            t-=1;
            continue;
        }
        vector<int>ans1;
        vector<int>ans2;
        unordered_map<int,int>check1;
        unordered_map<int,int>check2;

        vector<int>free;
        int sum1=0;
        
        for(int i=1;i<=n;i++){
            if(fre[i]==1){
                fre[i]-=1;
                check1[i]=i;
            }
            else if(fre[i]==0){
                if(sum1>=2){
                    sum1-=2;
                    check1[i]=free[free.size()-1];
                    free.pop_back();
                    check2[i]=free[free.size()-1];
                    free.pop_back();
                }
                else{
                    flag=1;
                    break;
                }
            }
            sum1+=fre[i];
            if(fre[i]==1){
                free.push_back(i);
            }
            else if(fre[i]==2){
                free.push_back(i);
                free.push_back(i);
            }
        }
        int done[200001]={0};
        for(int i=0;i<n;i++){
            if(done[v[i]]==0){
                ans1.push_back(v[i]); 
                ans2.push_back(check1[v[i]]);   
                done[v[i]]+=1;
            }
            else{
                ans2.push_back(v[i]);
                ans1.push_back(check2[v[i]]);
            }
        }

        if(flag==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                cout<<ans1[i]<<" ";
            }
            cout<<endl;
            for(int i=0;i<n;i++){
                cout<<ans2[i]<<" ";
            }
            cout<<endl;
        }

        t-=1;
    }
    return 0;
}