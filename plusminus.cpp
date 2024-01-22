#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;

        string s;
        cin>>s;

        int parity=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i+1]=='0'){
                cout<<'+';
            }
            else{
                if(parity%2==0){
                    cout<<'-';
                    parity+=1;
                }
                else{
                    cout<<'+';
                    parity+=1;
                }
            }
        }
        cout<<endl;

        t-=1;
    }
    return 0;
}