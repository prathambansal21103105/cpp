#include<iostream> // here we simply compare our element with each element in the array 
using namespace std;
int linearsearch(int arr[],int n, int x){
    for(int j=0;j<n;j++){
        if (arr[j]==x){
            return j;
        }
    }
    return -1;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int x;
        cin>>x;
        int ans=linearsearch(arr,n,x);
        cout<<ans<<endl;
        t-=1;
    }
    return 0;
}