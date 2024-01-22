#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t>0){
        int l,r,k;
        cin>>l>>r>>k;
        if(l==r and l<=1){
            cout<<"NO"<<endl;
        }
        else if(l==r){
            cout<<"YES"<<endl;
        }
        else{
            int total=r+1-l;
            if(total%2==0){
                int tp=total/2;
                if(k>=tp){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
            else{
                if(l%2==0){
                    int tn=r-l;
                    int tp=tn/2;
                    if(k>=tp){
                        cout<<"YES"<<endl;
                    }
                    else{
                        cout<<"NO"<<endl;
                    }
                }
                else{
                    int tn=r-l;
                    int tp=tn/2;
                    if(k>=tp+1){
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
    return  0;
}