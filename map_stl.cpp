#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    map<int,string>m;
    unordered_map<int,string>m1;
    m[1]="babbar";
    m[2]="love";
    m[13]="kumar";
    m.insert({5,"bheem"});

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<m.count(13)<<endl;

    m.erase(13);

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    auto it=m.find(5);
    for(auto i=it;i!=m.end();i++){
        cout<<(*i).first<<endl;
    }

    return 0;
}