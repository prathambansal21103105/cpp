#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t>0){
        int n,m;
        cin>>n>>m;

        vector<int>v;
        vector<int>pre;
        int sum1=0;
        int flag=0;
        int index1=-1;
        for(int i=0;i<n-1;i++){
            int x;
            cin>>x;
            sum1+=x;
            v.push_back(x);
            pre.push_back(sum1);
            if(sum1>m){
                flag=1;
                index1=i;
            }
        }
        if(m>=sum1){
            cout<<1<<endl;
            t-=1;
            continue;
        }
        int input[n-1];
        
        for(int i=0;i<n-1;i++){
            input[i]=i;
        }
        for(int i=index1;i<n-1;i++){
            input[i]+=1;
        }
        int myscore=index1;
        int pos=1;
        int count=0;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(i==n+1){
                continue;
            }
            else{
                if(input[i]<input[i+1]){
                    pos=pos+count+1;
                    count=0;
                }
                else{
                    count+=1;
                }
            }
            if(input[i]<=myscore){
                ans=pos;
                break;
            }
        }
        if(ans>0){
            cout<<ans<<endl;
        }
        else{
            cout<<n<<endl;
        }


        t-=1;
    }
    return 0;
}