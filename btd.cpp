#include<iostream>
#include<cmath>
using namespace std;
int main(){
    string n;
    cin>>n;
    int decimal=0;
    string rn;
    for(int j=0;j<n.size();j++){
        rn=n[j]+rn;
    }
    for(int i=0;i<n.size();i++){
        if(rn[i]=='0'){
            decimal+=0*(pow(2,int(i)));
        }
        else{
            decimal+=1*(pow(2,int(i)));
        }
    }
    cout<<decimal<<endl;
    return 0;
}