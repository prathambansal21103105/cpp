#include<iostream>
using namespace std;
// int minJumps(int arr[], int n){
//         // Your code here
//         int curr=0;
//         int add=0;
//         int steps=0;
//         int max=n-1;
//         while(curr<max){
//             add=arr[curr];
//             if(add==0){
//                 return -1;
//             }
//             curr=curr+add;
//             steps+=1;
//         }
//         return steps;
// }
bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        else{
            int num=x;
            int n=0;
            while(x>0){
                int last=x%10;
                n=n*10+last;
                x=x/10;
            }
            if(n==num){
                return true;
            }
            else{
                return false;
            }
        }
    }
int main(){
    int n;
    cin>>n;
    if(isPalindrome(n)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    // int input[n];
    // for(int i=0;i<n;i++){
    //     cin>>input[i];
    // }
    return 0;
}