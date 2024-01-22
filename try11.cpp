#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n,m;
        cin>>n>>m;
        string str;
        cin>>str;
        string str1;
        while(m>0){
            str1+=str;
            m-=1;
        }
        int small=0;
        for(int i=0;i<n;i++){
            if(str[i]=='1'){
                small+=1;
            }
            else{
                small+=0;
            }
        }
        cout<<small;
        int sum=small*m;
        cout<<sum<<endl;
        t-=1;
    }
    return 0;
}