#include<iostream>
using namespace std;
#include<set>
int main(){
    unordered_set<string>s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        s.insert(str);
    }
}