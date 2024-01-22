#include<iostream>
#include<string>
using namespace std;
int main(){
    // string* sp=new string;  //creating a string dynamically
    // *sp="def";
    // cout<<sp<<endl;
    // cout<<*sp<<endl;
    // string str="abc";
    // cout<<str<<endl;
    // cout<<str.length()<<endl;
    string s;
    getline(cin,s);       // it helps in taking the whole line as input including the spaces
    cout<<s<<endl;
    s="def";
    cout<<s<<endl;
    if(s[0]=='d'){
        cout<<"YES"<<endl;
    } 
    string s2=s+s;
    cout<<s2<<endl;
    cout<<s2.size()<<endl;      // .size() and .length() do the same thing
    cout<<s2.length()<<endl;
    cout<<s2.substr(3)<<endl;   // here we give the index we want to start with
    cout<<s2.substr(3,3)<<endl;  // here first 3 tells the starting index and the second 3 tells the length
    cout<<s2.find("def")<<endl;
    return 0;
}