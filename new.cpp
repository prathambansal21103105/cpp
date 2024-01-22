#include<iostream>
using namespace std;
#include<math.h>
#include<string>

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

int main(){
    
string s="1011";
long long a = toINT(s);
cout<<a<<endl;

    return 0;
}