#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t>0){
        int n;
        cin>>n;
        vector<int>ab;
        int r=n;
        int cd=1;
        for(int i=0;i<n;i++){
            if(i%2==0){
                cout<<r--<<" ";
            }
            else{
                cout<<cd++<<" ";
            }
        }
        cout<<endl;
        t-=1;
    }
    return 0;
}