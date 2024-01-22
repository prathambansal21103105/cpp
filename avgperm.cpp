#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        if (n==3){
            cout<<3<<" "<<1<<" "<<2<<endl;
        }
        else{
            int input[100000]={0};
            input[0]=n;
            input[n-1]=n-1;
            input[1]=n-2;
            input[n-2]=n-3;
            for(int i=2;i<=n-3;i++){
                input[i]=i-1;
            }
            for(int i=0;i<n;i++){
                cout<<input[i]<<" ";
            }
        }
        cout<<endl;
        t-=1;
    }
    return 0;
}

// 3 -- 1 2 3  
// 4 -- 1 2 3 2 3 4
// 5 -- 1 2 3 2 3 4 3 4 5
// 6 -- 1 2 3 2 3 4 3 4 5 4 5 6
// 7 -- 1 2 3 2 3 4 3 4 5 4 5 6 5 6 7
//       7 5 1 2 3 4 6