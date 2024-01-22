#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using  namespace std;

string smallestEquivalentString(string s1, string s2, string baseStr) {
    int x=s1.length();
    int y=baseStr.length();
    vector<int>parent[26];
    for(int i=0;i<26;i++){
        parent[i].push_back(i);
    }
    for(int i=0;i<x;i++){
        int a=s1[i]-'a';
        int b=s2[i]-'a';
        int newa=INT_MAX;
        int newb=INT_MAX;
        int childa=a;
        int parenta=parent[a][0];
        if(parenta!=childa){
            childa=parenta;
            parenta=parent[parenta][0];
        }
        parent[a][0]=parenta;
        newa=parenta;
        int childb=b;
        int parentb=parent[b][0];
        if(parentb!=childb){
            childb=parentb;
            parentb=parent[parentb][0];
        }
        parent[b][0]=parentb;
        newb=parentb;
        int rep=min(newa,newb);
        parent[newa][0]=rep;
        parent[newb][0]=rep;
    }
    string ans="";
    for(int i=0;i<y;i++){
        char d=baseStr[i];
        int d1=d-'a';
        if(parent[d1][0]==d1){
            ans+=d;
        }
        else{
            int child1=d-'a';
            int parent1=parent[child1][0];
            while(parent1!=child1){
                child1=parent1;
                parent1=parent[parent1][0];
            }
            int sum1='a';
            parent1+=sum1;
            char con=parent1;
            ans+=con;
        }
    }
    return ans;   
}

int main(){
    string a,b,c;
    cin>>a>>b>>c;
    
    string ans=smallestEquivalentString(a,b,c);
    cout<<ans<<endl;

    return 0;
}