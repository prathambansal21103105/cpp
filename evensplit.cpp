#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        char input[1000];
        cin>>input;
        if(n==2){
            cout<<input<<endl;
            t-=1;
            continue;
        }
        int count1=0;
        for(int i=0;i<n;i++){
            if(input[i]=='1'){
                count1+=1;
            }
        }
        int count0=n-count1;
        string output="";
        for(int i=0;i<count0;i++){
            output+='0';
        }
        for(int i=0;i<count1;i++){
            output+='1';
        }
        cout<<output<<endl;
        t-=1;
    }
    return 0;
}