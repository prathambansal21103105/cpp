#include<iostream>
using namespace std;
int staircase(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else if(n==2){
        return 2;
    }
    else if(n==3){
        return 4;
    }
    else{
        if(n>3){
            int ans=0;
            for(int i=1;i<=3;i++){
                ans=ans+staircase(n-i);
            }
            return ans;
        }
        else{
            return 0;
        }

    }
}
int main(){
    int n;
    cin>>n;
    int ans=staircase(n);
    cout<<ans<<endl;
    return 0;
}