#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//DP solution
int lcs_DP(string s, string t){
    int m=s.length();
    int n=t.length();
    int output[m+1][n+1];

    for(int i=0;i<=m;i++){
        output[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        output[0][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int ans=0;
            if(s[m-i]==t[n-j]){
                ans=1+output[i-1][j-1];
            }
            else{
                ans=max(output[i-1][j-1],max(output[i-1][j],output[i][j-1]));
            }
            output[i][j]=ans;
        }
    }
    
    return output[m][n];
}

//memoization solution
int lcs_MEM(string s, string t, int** output){
    int m=s.length();
    int n=t.length();
    int ans=0;
    if(s.size()==0 or t.size()==0){
        return 0;
    }
    if(output[m][n]!=-1){
        return output[m][n];
    }
    else{
        if(s[0]==t[0]){
            ans= 1+lcs_MEM(s.substr(1),t.substr(1),output);
        }
        else{
            int a=lcs_MEM(s.substr(1),t,output);
            int b=lcs_MEM(s,t.substr(1),output);
            ans=max(a,b);
        }
    }
    output[m][n]=ans;
    return ans;
}
int lcs_mem(string s, string t){
    int m=s.size();
    int n=t.size();
    int **output=new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            output[i][j]=-1;
        }
    }
    return lcs_MEM(s,t,output);
}

//recursive solution
int lcs(string s, string t){
    if(s.length()==0 or t.length()==0){
        return 0;
    }
    if(s[0]==t[0]){
        return 1+lcs(s.substr(1),t.substr(1));
    }
    else{
        int a=lcs(s.substr(1),t);
        int b=lcs(s,t.substr(1));
        return max(a,b);
    }
}
int main(){
    string s,t;
    s="xyz";
    t="zxay";
    // cin>>s>>t;
    // cout<<lcs(s,t)<<endl;
    // cout<<lcs_mem(s,t)<<endl;
    cout<<lcs_DP(s,t)<<endl;
    return 0;
}