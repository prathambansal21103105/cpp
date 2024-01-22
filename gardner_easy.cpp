#include<iostream>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    
    while(t>0){
        string s;
        cin>>s;
 
        int n=s.length();
        
        if(s[0]=='b' and s[n-1]=='b'){
            string b;
            for(int i=1;i<n-1;i++){
                b+=s[i];
            }
            cout<<s[0]<<" "<<b<<" "<<s[n-1]<<endl;
            t-=1;
            continue;
        }
        else if(s[0]=='a' and s[n-1]=='a'){
            string b;
            for(int i=1;i<n-1;i++){
                b+=s[i];
            }
            cout<<s[0]<<" "<<b<<" "<<s[n-1]<<endl;
            t-=1;
            continue;
        }
        else{
            if(s[0]=='a' and s[n-1]=='b'){
                int flagb=0;
                int indexb=0;
                for(int i=1;i<n-1;i++){
                    if(s[i]=='b'){
                        flagb=1;
                        indexb=i;
                        break;
                    }
                }
                if(flagb==1){
                    string a;
                    string b;
                    string c;
                    c+=s[n-1];
                    for(int i=0;i<n-1;i++){
                        if(i<indexb){
                            a+=s[i];
                        }
                        else{
                            b+=s[i];
                        }
                    }
                    cout<<a<<" "<<b<<" "<<c<<endl;
                    t-=1;
                    continue;
                }
                else{
                    string a;
                    for(int i=0;i<n-2;i++){
                        a+=s[i];
                    }
                    cout<<a<<" "<<'a'<<" "<<'b'<<endl;
                    t-=1;
                    continue;
                }
            }
            else{
                int flaga=0;
                int index1=0;
                for(int i=1;i<n-1;i++){
                    if(s[i]=='a'){
                        flaga=1;
                        index1=i;
                        break;
                    }
                }
                if(flaga==1){
                    string a;
                    string b;
                    string c;
                    b+='a';
                    for(int i=0;i<n;i++){
                        if(i<index1){
                            a+=s[i];
                        }
                        if(i>index1){
                            c+=s[i];
                        }
                    }
                    cout<<a<<" "<<b<<" "<<c<<endl;
                    t-=1;
                    continue;
                }
                else{
                    string a;
                    string b;
                    string c;
                    a+='b';
                    c+='a';
                    for(int i=1;i<n-1;i++){
                        b+=s[i];
                    }
                    cout<<a<<" "<<b<<" "<<c<<endl;
                    t-=1;
                    continue;
                }
            }
        }
 
 
        t-=1;
    }
    return 0;
}