#include<iostream>
#include<vector>
#include<string>
using namespace std;

// string decToBinary(int n,int x)
// {
//     string s="";
//     for (int i = x-1; i >= 0; i--) {
//         int k = n >> i;
//         if (k & 1)
//             s+='1';
//         else
//             s+='0';
//     }
//     return s;
// }
void alt(string x,vector<string>& v1,string str){
    if(x.length()==0){
        v1.push_back(str);
        return;
    }
    else{
        if((x[0]>=65 and x[0]<=90) or (x[0]>=97 and x[0]<=122)){
            alt(x.substr(1),v1,str+x[0]);
            if(x[0]<=90){
                char r=x[0]+32;
                str+=r;
            }
            else{
                char r=x[0]-32;
                str+=r;
            }
            alt(x.substr(1),v1,str);
        }
        else{
            str+=x[0];
            x.substr(1);
            alt(x,v1,str);
        }
    }
}
int main(){
    string x;
    cin>>x;
    int n=0;
    // for(int i=0;i<x.length();i++){
    //     if((x[i]>=65 and x[i]<=90) or (x[i]>=97 and x[i]<=122)){
    //         n++;            
    //     }
    // }
    // vector<string>v;
    vector<string>v1;
    // int y=1<<(n);
    // for(int i=0;i<y;i++){
    //     string s=decToBinary(i,n);
    //     int k=0;
    //     string s1="";
    //     for(int j=0;j<x.length();j++){
    //         if((x[j]>=65 and x[j]<=90) or (x[j]>=97 and x[j]<=122)){
    //             if(s[k]=='0'){
    //                 s1+=x[j];
    //                 k++;
    //             }
    //             else{
    //                 if(x[j]<=90){
    //                     char r=x[j]+32;
    //                     s1+=r;
    //                 }
    //                 else{
    //                     char r=x[j]-32;
    //                     s1+=r;
    //                 }
    //                 k++;
    //             }
    //         }
    //         else{
    //             s1+=x[j];
    //         }
    //     }
    //     v.push_back(s1);
    // }
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    alt(x,v1,"");
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/*
65 90
97 122
*/