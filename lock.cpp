#include<iostream>
using namespace std;

// bool solve(int input[],int n,int sum1){
//     if(n==0){
//         if(sum1==0 or sum1%360==0){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     bool x=solve(input+1,n-1,sum1-input[0]);
//     bool y=solve(input+1,n-1,sum1+input[0]);

//     return x or y;
// }

// void binary(int x,int n){
//     for(int i=n-1;i>=0;i--){
//         int y=(1<<i);
//         if((x & y) ==0){
//             cout<<0;
//         }
//         else{
//             cout<<1;
//         }
//     }
//     cout<<endl;
// }

void solve(int input[],int n){
    int x=1;
    x=x<<n;
    x=x-1;
    int flag=0;
    
    for(int i=0;i<=x;i++){
        int sum1=0;
        for(int j=0;j<=n-1;j++){
            int y=(1<<j);
            if((y&i)==0){
                sum1+=input[j];
            }
            else{
                sum1-=input[j];
            }
        }
        if(sum1%360==0){
            flag=1;
            break;
        }
    }

    if(flag==1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main(){
    
    int n;
    cin>>n;

    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    solve(input,n);

    // if(solve(input,n,0)){
    //     cout<<"YES"<<endl;
    // }
    // else{
    //     cout<<"NO"<<endl;
    // }

    return 0;
}