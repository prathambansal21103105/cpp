#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t>0){
        int n;
        cin>>n;

        int fre[300000];
        for(int i=0;i<300000;i++){
            fre[i]=2;
        }

        int flag=0;
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x<=0 or x>n){
                flag=1;
                break;
            }
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

        vector<int>vac;
        unordered_map<int,int>amap1;
        unordered_map<int,int>amap2;

        int count1=0;
        for(int i=1;i<=n;i++){
            if(fre[i]==1){
                fre[i]-=1;
                amap1[i]=i;
            }
            else if(fre[i]==0){
                if(count1>=2){
                    count1-=2;
                    amap1[i]=vac[vac.size()-1];
                    vac.pop_back();
                    amap2[i]=vac[vac.size()-1];
                    vac.pop_back();
                }
                else{
                    flag=1;
                    break;
                }
            }
            else{
                count1+=2;
                vac.push_back(i);
                vac.push_back(i);
            }
        }

        vector<int>ans1;
        vector<int>ans2;

        int fre1[300000]={0};
        for(int i=0;i<n;i++){
            if(fre1[v[i]]==0){
                ans1.push_back(v[i]);
                ans2.push_back(amap1[v[i]]);
                fre1[v[i]]+=1;
            }
            else{
                ans1.push_back(amap2[v[i]]);
                ans2.push_back(v[i]);
            }
        }
        if(flag==1 or count1>0){
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