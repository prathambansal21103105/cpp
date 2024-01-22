#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){

    int n;
    cin>>n;

    int count=0;
    for(int i=2;i<=n;i++){
        int k=i;
        int j=2;
        unordered_set<int>aset;
        while(j<=k){
            if(k%j==0){
                aset.insert(j);
                k=k/j;
                j=2;
            }
            else{
                j++;
            }
        }
        if(aset.size()==2){
            count+=1;
        }
    }
    cout<<count<<endl;

    return 0;
}