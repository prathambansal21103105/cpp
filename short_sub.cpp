#include <iostream>
#include <string>
using namespace std;

int solve(string s, string v) {
    // Write your code here
    int a=s.length();
    int b=v.length();
    int mat[a+1][b+1];
    for(int i=0;i<=a;i++){
        mat[i][0]=1;
    }
    for(int j=0;j<=b;j++){
        mat[0][j]=INT_MAX-3;
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            int index=INT_MAX-1;
            for(int k=j-1;k>=0;k--){
                if(v[k]==s[i-1]){
                    index=k;
                    break;
                }
            }
            if(index==INT_MAX-1){
                mat[i][j]=1;
            }
            else{
                mat[i][j]=min(mat[i-1][j],mat[i-1][index]+1);
            }

        }
    }
    int ans=mat[a][b];
    return ans;
}

int solve(string s, string v) {
    // Write your code here
    int a=s.length();
    int b=v.length();
    if(a==0 or a<0){
        return 0;
    }
    int ans1=0;
    int ans2=0;
    int ans1=solve(s.substr(1),v);
    int index=-1;
    for(int i=0;i<b;i++){
        if(s[0]==v[i]){
            index=i;
        }
    }
    if(index>=0){
        int ans2=1+solve(s.substr(1),v.substr(index+1));
    }
    int ans=min(ans1,ans2);
    return ans;
}

int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}