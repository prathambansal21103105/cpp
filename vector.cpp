#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>vec;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        vec.push_back(a);
    }
    cout<<vec[0]<<endl;
    return 0;
}