#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;

        vector<long long>v;
        for(int i=0;i<n;i++){
            long long x;
            cin>>x;
            v.push_back(x);
        }

        int odd=1;
        int even=1;
        for(int i=0;i<n;i++){
            if(v[i]%2==0){
                odd=0;
            }
            else{
                even=0;
            }
        }

        if(odd==1 or even==1){
            cout<<"YES"<<endl;
        }
        else{
            int one=0;
            for(int i=0;i<n;i++){
                if(v[i]==1){
                    one=1;
                    break;
                }
            }
            if(one==0){
                cout<<"YES"<<endl;
            }
            else{
                sort(v.begin(),v.end());
                if(v[0]==0){
                    cout<<"NO"<<endl;
                }
                else{
                    int flag=0;
                    for(int i=0;i<n-1;i++){
                        if(v[i+1]==v[i]+1){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){
                        cout<<"YES"<<endl;
                    }
                    else{
                        cout<<"NO"<<endl;
                    }
                }
            }
        }
        t-=1;
    }
    return 0;
}