#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        string s;
        cin>>s;
        string t1;
        int l=s.length();
        int i=0;
        int st=0;
        int la=s.length()-1;
        while(l!=0){
            if(t1.length()==0){
                t1+=s[i];
                i+=1;
                st+=1;
            }
            else{
                if(i%2==0){
                    if(s[st]=='0'){
                        t1="0"+t1;
                    }
                    else{
                        t1=t1+"1";
                    }
                    st+=1;
                }
                else{
                    if(s[la]=='0'){
                        t1=t1+"0";
                    }
                    else{
                        t1="1"+t1;
                    }
                    la-=1;
                }
                i+=1;
            }
            l-=1;
        }
        cout<<t1<<endl;
        t-=1;
    }
    return 0;
}