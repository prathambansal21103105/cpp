#include<iostream>
#include<vector>
using namespace std;

// void getallways(int a,int arr,int count ,int sum,int n){
//     if(n==0 and sum ==a){
//         *count =*count+1;
//         return;
//     }
//     if(n<=0){
//         return;
//     }
//     if(sum>a){
//         return;
//     }

//     getallways(a,arr+1,count,sum,n-1);
//     getallways(a,arr+1,count,sum+arr[0],n-1);
// }





int getAllWays(int a, int b) {

    vector<int>apowerb;
    apowerb.push_back(1);
    for(int i=2;i<=a;i++){
        int k =i;
        for(int j=0;j<b-1;j++){
            k =k*k;
        }
        if(k>a){
            break;
        }
        apowerb.push_back(k);
    }
    if(apowerb.size()==0 and a!=1){
        return 0;
    }
    
    int n = apowerb.size();
    int *arr = new int [n];
    for(int i=0;i<n;i++){
        arr[i] =apowerb[i];
    }
    bool ans[a+1][n+1];
    
    // cout<<"ran"<<endl;
   ans[0][0] = true;
   for(int i=1;i<=a;i++){
    ans[0][i] =false;

   }
   for(int i=1;i<=n;i++){
    ans[i][0]= true;
   }
   
   for(int i=1;i<=n;i++){
    for(int j=1;j<=a;j++){
        if(arr[i-1]<=j){
            ans[i][j] =ans[i-1][j-arr[i-1]] |ans[i-1][j]; 
        }else{
            ans[i][j]= ans[i-1][j];
        }
    }
   }
   int counter=0;
//    cout<<"ran"<<endl;
    // for(int i=0;i<=n;i++){
    //     cout<<ans[i][a]<<" ";
    // }
    // cout<<endl;
   for(int i=0;i<=n;i++){
        if(ans[i][a]==true){
            counter++;
        }

   }
   return counter;
}
int main(){
    cout<<getAllWays(25,2);
    cout<<endl;
    return 0;
}