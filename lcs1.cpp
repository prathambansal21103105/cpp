#include<iostream>
#include<climits>
using namespace std;

int lcs(string s, string t){
    int a=s.length();
    int b=t.length();
    int** arr=new int*[a+1];
    for(int i=0;i<a+1;i++){
        arr[i]=new int[b+1];
        for(int j=0;j<b+1;j++){
            arr[i][j]=0;
        }
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(s[a-i]==t[b-j]){
                arr[i][j]=1+arr[i-1][j-1];
            }
            else{
                arr[i][j]=max(arr[i-1][j-1],max(arr[i-1][j],arr[i][j-1]));
            }
        }
    }
    return arr[a][b];
}
// int lcs(string s, string t){
//     if(s.length()==0 or t.length()==0){
//         return 0;
//     }
//     int a=0;
//     int b=0;
//     int c=0;
//     int d=0;
//     if(s[0]==t[0]){
//         a=1+lcs(s.substr(1),t.substr(1));
//     }
//     b=lcs(s.substr(1),t);
//     c=lcs(s,t.substr(1));
//     d=lcs(s.substr(1),t.substr(1));
//     int ans=max(a,max(b,max(c,d));
//     return ans;
// }
int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;
    int ans=lcs(s,t);
    cout<<ans<<endl;
    return 0;
}