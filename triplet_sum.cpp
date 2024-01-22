#include<iostream>
using namespace std;
int pairSum(int *arr,int start,int end,int target)
{
    int finalCount=0;
    while(start<end)
    {
        if(arr[start]+arr[end]>target)
        {
            end--;
        }
        else if(arr[start]+arr[end]<target)
        {
            start++;
        }
        else
        {
            int startIndex=start;
            int endIndex=end;
            if(arr[start]==arr[end])
            {
                int betweenIndexs=(end-start)+ 1;
                finalCount+=(betweenIndexs*(betweenIndexs- 1))/2;
                return finalCount;
            }
            int newStart=start+ 1;
            int newEnd=end-  1;
            
            while(newStart<=newEnd&&arr[newStart]==arr[start])
                newStart++;
            while(newStart<=newEnd&&arr[newEnd]==arr[end])
                newEnd--;
            int eleFromStart=newStart-start;
            int eleFromEnd=end-newEnd;
            
            finalCount+=(eleFromStart*eleFromEnd);
            
            start=newStart;
            end=newEnd;
        }
    }
    return finalCount;
}
int tripletSum(int*arr,int n,int num)
{
    if(n==0)
    return 0;
    
    sort(arr,arr+n);
    int finalCount=0;
    for(int i=0;i<n;i++)
    {
        int pairSumFor=num-arr[i];
        finalCount+=pairSum(arr,i+ 1,n- 1,pairSumFor);
    }
    return finalCount;
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
        int num;
        cin>>num;
        int ans=tripletSum(input,n,num);
        cout<<ans<<endl;
        t-=1;
    }
    return 0;
}