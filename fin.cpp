#include<iostream>
using namespace std;
int firstIndex(int input[],int n,int x){
    if(n==1){
        if (input[0]==x){
            return 0;
        }
        else{
            return -1;
        }
    }
    else{
        if(input[0]==x){
            return 0;
        }
        else{
            int ans;
            ans=firstIndex(input+1,n-1,x);
            if(ans<0){
                return ans;
            }
            else{
                return 1+ans;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int x;
    cin>>x;
    cout<<firstIndex(input,n,x)<<endl;
    return 0;
}

/* 
5
1 2 3 4 5 
3
2







*/ 