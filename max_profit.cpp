#include<iostream>
#include<algorithm>
using namespace std;
int maximumProfit(int budget[],int n){
    sort(budget,budget+n);
    int profit=0;
    int max=0;
    for(int i=0;i<n;i++){
        profit=budget[i]*(n-i);
        if(profit>max){
            max=profit;
        }
    }
    return max;
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int ans=maximumProfit(input,n);
    cout<<ans<<endl;
    return 0;
}