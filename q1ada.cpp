#include<iostream>
using namespace std;

void partition(int input[], int si, int mid, int ei){
    int i=si;
    int j=ei;
    while(i<mid and j>mid){
        if(input[i]>=input[mid] and input[j]<input[mid]){
            int temp=input[i];
            input[i]=input[j];
            input[j]=temp;
            i++;
            j--;
        }
        else if(input[i]<input[mid]){
            i++;
        }
        else if(input[j]>=input[mid]){
            j--;
        }
        else{
            break;
        }
    }
}
void quicksort(int input[], int si, int ei){
    if(si<ei){
        int count=0;
        for(int i=si;i<=ei;i++){
            if(input[i]<input[si]){
                count++;
            }
        }
        int temp=input[count+si];
        input[count+si]=input[si];
        input[si]=temp;
        int mid=si+count;
        partition(input,si,mid,ei);
        quicksort(input,si,mid-1);
        quicksort(input,mid+1,ei);
    }
    else{
        return;
    }
}
void quickSort(int input[], int size) {
    quicksort(input,0,size-1);
}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    quickSort(input,n);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/*
Time Complexity:
quicksort -> 
avg case= nlogn
best case= nlogn
worst case= n^2

Recurrence relation:
T(n)=T(i)+T(n-1-i)

*/