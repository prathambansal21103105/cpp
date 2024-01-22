#include"stdc++.h"
using namespace std;
// #define int long long
// #define endl "\n"

void merge(int arr[],int l,int m,int r)
{
    int left_size=m-l+1,right_size=r-m;
    int left[left_size],right[right_size];
    int i;
    for(i=0;i<left_size;i++)
    {
        left[i]=arr[l+i];
    }
    for(int j=0;j<right_size;j++)
    {
        right[j]=arr[m+1+j];
    }
    
    i=0;
    int j=0,k=l;
    
    while(i<left_size and j<right_size and k<=r)
    {
        if(left[i]<right[j])
        {
            arr[k]=left[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=right[j];
            j++;
            k++;
        }
    }
    
    while(i<left_size and k<=r)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    
    while(j<right_size and k<=r)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[],int l,int r)
{
    int mid=l+(r-l)/2;
    
    if(l<r)
    {
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }

}

int main()
{
    int t;
    cin>>t;
    
    while(t-->0)  
    {
        int n;
        cin>>n;
        
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        merge_sort(arr,0,n-1);
        
        for(auto x:arr)
        {
            cout<<x<<' ';
        }
        cout<<endl;
    }
    return 0;
}