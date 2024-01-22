#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    long long int input[100000];
    long long int a=2;
    for(int i=0;i<100000;i++){
        input[i]=a;
        a=a%10000000;
        a*=2;
    }
    while(t>0){
        int length;
        cin>>length;
        string s;
        cin>>s;
        int y=1;
        long long int x=0;
        int count=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1'){
                x+=pow(2,count);
            }
            count+=1;
        }
        long long int min=x;
        int ans=1;
        while(y<=length){
            int r=x/input[y-1];
            if((x xor r)<=min){
                min=x xor r;
                ans=y;
            }
            y+=1;
        }
        cout<<ans<<endl;
        t-=1;
    }
    return 0;
}

/*
#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int length;
        cin>>length;
        string s;
        cin>>s;
        int count1=0;
        for(int i=0;i<length;i++){
            count1+=1;
            if(s[i+1]=='1'){
                break;
            }
        }
        cout<<count1<<endl;
        t-=1;
    }
    return 0;
}
*/