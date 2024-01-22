#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int>d;
    d.push_back(2);
    d.push_back(1);
    for(int i:d){
        cout<<i<<" ";
    }
    // d.pop_front();
    cout<<endl;
    cout<<"Print First Index Element->"<<d.at(1)<<endl;
    cout<<"front"<<d.front()<<endl;
    cout<<"back"<<d.back()<<endl;
    cout<<"Empty or not"<<d.empty()<<endl;
    cout<<"before erase"<<d.size()<<endl;
    d.erase(s.begin(),d.begin()+1);
    cout<<"after erase"<<d.size()<<endl;
    return 0;
} 