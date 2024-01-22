#include<iostream>
#include<climits>
#include<math.h>
#include<string>
using namespace std;
#define int long long

int toINT(string s)
{
    int n= s.length();
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='1')
        {
            ans+=pow(2,n-1-i);
        }
    }

    return ans;
}

signed main(){
    int t;
    cin>>t;
    // int input[100000];
    // int a=2;
    // for(int i=0;i<100000;i++){
    //     input[i]=a;
    //     a*=2;
    // }
    while(t>0){
        int length;
        cin>>length;
        string s;
        cin>>s;
        int x=toINT(s); //
        int d=length;
        int y=1;
        int max=INT_MIN;
        int ans=1;
        while(d>0){
            int r=x/pow(2,y);
            if((x xor r)>=max){
                max=(x xor r);
                ans=y;
            }
           d--;
           y++;
        }
        cout<<ans<<endl;
        t-=1;
    }
    return 0;
}