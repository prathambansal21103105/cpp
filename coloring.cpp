#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t>0){
        int n,m,k;
        cin>>n>>m>>k;

        vector<int>a;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        if(k==1){
            cout<<"YES"<<endl;
            t-=1;
            continue;
        }
        else{
            int parts=n/k;
            int extra=n%k;
            int flag=0;
            int sum1=0;
            for(int i=0;i<m;i++){
                if(a[i]<=parts){
                    a[i]=0;
                }
                else{
                    a[i]-=parts;
                    if(a[i]>=2){
                        flag=1;
                    }
                    sum1+=a[i];
                }
            }
            if(sum1>extra){
                flag=1;
            }
            if(flag==1){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
        t-=1;
    }


    return 0;
}

/*
15 6 4
3
3
4 4 4 1 1 1
1 1 1 0 0 0
1 2 3 4 1 2 3 5 1 2 3 6 1 2 3
*/

