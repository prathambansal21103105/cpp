#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string str;
    string s1,s2,s3,s4;
    s1+='i';
    s2+='d';
    s3+='i';
    s3+='d';
    s4+='d';
    s4+='i';
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    for(int j=0;j<n-1;j++){
        if (ar[j]<ar[j+1]){
            if (str[str.size()-1]=='i'){
                continue;
            }
            else{
                str+='i';
            }
        }
        else if (ar[j]>ar[j+1]){
            if(str[str.size()-1]=='d'){
                continue;
            }
            else{
                str+='d';
            }
        }
    }
    if(str==s1 or str==s2 or str==s3 or str==s4){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}