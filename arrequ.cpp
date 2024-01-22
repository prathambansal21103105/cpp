#include<iostream>
#include<algorithm>
using namespace std;
int mostFrequent(int arr[], int n)
{
    // Sort the array
    sort(arr, arr + n);
 
    // Find the max frequency using linear traversal
    int max_count = 1, res = arr[0], curr_count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else
            curr_count = 1;
       
        if (curr_count > max_count) {
            max_count = curr_count;
            res = arr[i - 1];
        }
    }
 
    return max_count;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int input[n];
        for(int i=0;i<n;i++){
            cin>>input[i];
        }
        int half=0;
        if(n%2!=0){
            half=(n/2)+1;
        }
        else{
            half=n/2;
        }
        int max=mostFrequent(input,n);
        if(max<=half){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        t-=1;
    }
    return 0;
}