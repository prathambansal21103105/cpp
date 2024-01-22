//q1
#include<iostream>
using namespace std;
int linearsearch(int arr[], int size, int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,4,7,7,8,9,18,27,31,56,81};
    int size=11;
    cout<<linearsearch(arr,size,1)<<endl;
    cout<<linearsearch(arr,size,81)<<endl;
    cout<<linearsearch(arr,size,7)<<endl;
    cout<<linearsearch(arr,size,3)<<endl;
    cout<<"Searching complexity: O(n)"<<endl;
    return 0;
}

//q2
#include<iostream>
using namespace std;

int binarysearch(int arr[], int st, int en, int tar, int val){
    if(st<=en){
        int mid=(st+en)/2;
        if(arr[mid]==tar){
            val=mid;
            return binarysearch(arr,st,mid-1,tar,val);
        }
        else if(arr[mid]>tar){
            return binarysearch(arr,st,mid-1,tar,val);
        }
        else{
            return binarysearch(arr,mid+1,en,tar,val);
        }
    }
    else{
        return val;
    }
}

int main(){
    int arr[]={1,4,7,7,8,9,18,27,31,56,81};
    int size=11;
    int st=0;
    int en=10;
    int ans=binarysearch(arr,0,10,1,INT_MAX);
    if(ans==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    ans=binarysearch(arr,0,10,81,INT_MAX);
    if(ans==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    ans=binarysearch(arr,0,10,7,INT_MAX);
    if(ans==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    ans=binarysearch(arr,0,10,3,INT_MAX);
    if(ans==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    return 0;
}

//q3
#include<iostream>
using namespace std;

void selectionsort(int arr[], int size){
    int count=0;
    int iter=0;
    for(int i=0;i<size-1;i++){
        int minel=arr[i];
        int mindex=i;
        for(int j=i+1;j<size;j++){
            count++;
            if(arr[j]<minel){
                mindex=j;
                minel=arr[j];
            }
        }
        int temp=arr[i];
        arr[i]=arr[mindex];
        arr[mindex]=temp;
        iter++;
    }
    cout<<"No. of iterations: "<<iter<<endl;
    cout<<"No. of comparisons: "<<count<<endl;

}
int main(){
    int arr[]={18,56,27,7,8,4,9,31,81,1};
    int size=10;
    selectionsort(arr,size);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//q4
#include<iostream>
using namespace std;
void bubblesort(int v[], int size){
    int count=0;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            count++;
            if(v[j]>v[j+1]){
                int temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
    cout<<"No. of comparisons: "<<count<<endl;
}
int main(){
    int arr[]={18,56,27,7,8,4,9,31,81,1};
    int size=10;
    bubblesort(arr, size);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}

//q5
#include<iostream>
using namespace std;
void insertionsort(int v[], int size){
    int count=0;
    for(int i=1;i<size;i++){
        int j=i-1;
        count++;
        while(j>=0 and v[j]>v[j+1]){
            count++;
            int temp = v[j];
            v[j] = v[j+1];
            v[j+1]=temp;
            j--;
        }
    }
    cout<<"No. of comparisons: "<<count<<endl;
}

int main(){
    int arr[]={18,56,27,7,8,4,9,31,81,1};
    int size=10;
    insertionsort(arr,size);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//q6
#include<iostream>
using namespace std;

void merge(int arr1[], int arr2[], int mergearr[], int s1, int s2, int s3){
    int k=0;
    int i=0;
    int j=0;
    while(k<s3){
        if(i<s1 and j<s2){
            if(arr1[i]<=arr2[j]){
                mergearr[k]=arr1[i];
                i++;
            }
            else{
                mergearr[k]=arr2[j];
                j++;
            }
        }
        else if(i<s1){
            mergearr[k]=arr1[i];
            i++;
        }
        else if(j<s2){
            mergearr[k]=arr2[j];
            j++;
        }
        k++;
    }
}
int main(){
    int arr1[]={7,8,18,27,56};
    int arr2[]={1,4,9,31,81};
    int n=10;
    int mergearr[10];
    merge(arr1,arr2,mergearr,5,5,n);
    for(int i=0;i<n;i++){
        cout<<mergearr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//q7
#include<iostream>
using namespace std;
void mergesort(int input[],int si,int ei){
    if(si>=ei){
        return;
    }
    else{
        int mid=(si+ei)/2;
        mergesort(input,si,mid);
        mergesort(input,mid+1,ei);
        int new_arr[ei+1-si];
        int j=si;
        int k=mid+1;
        for(int i=0;i<=ei-si;i++){
            if(j<=mid and k<=ei){
                if(input[j]<input[k]){
                    new_arr[i]=input[j];
                    j+=1;
                }
                else{
                    new_arr[i]=input[k];
                    k+=1;
                }
            }
            else{
                if(j>mid){
                    new_arr[i]=input[k];
                    k+=1;
                }
                else{
                    new_arr[i]=input[j];
                    j+=1;
                }
            }
        }
        for(int i=0;i<=ei-si;i++){
            input[i+si]=new_arr[i];
        }
    }
}
void mergeSort(int input[],int n){
    mergesort(input,0,n-1);
}
int main(){
    int n=10;;
    int input[]={18,56,27,7,8,4,9,31,81,1};
    mergeSort(input,n);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}