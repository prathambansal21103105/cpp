#include<iostream>
using namespace std;

void partition(int input[],int si,int count,int ei){
    int i=si;
    int j=count+1;
    int k=si;
    for(k=si;k<=ei;k++){
        if(i<=count-1 and j<=ei){
        if(input[i]>=input[count] and input[j]<input[count]){
            int temp=input[i];
            input[i]=input[j];
            input[j]=temp;
            i+=1;
            j+=1;
        }
        else if(input[i]<input[count]){
            i+=1;
        }
        else if(input[j]>=input[count]){
            j+=1;
        }
        }
        else{
            break;
        }
    }
    for(int i=si;i<ei;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
}
void quick_sort(int input[],int si,int ei){
    if(si>=ei){
        return;
    }
    else{
        int pivot=input[si];
        int count=0;
        for(int i=si;i<=ei;i++){
            if(input[i]<pivot){
                count+=1;
            }
        }
        int temp=input[count+si];
        input[count+si]=input[si];
        input[si]=temp;
        partition(input,si,count+si,ei);
        quick_sort(input,si,count+si-1);
        quick_sort(input,count+si+1,ei);              
    }
}
void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    quick_sort(input,0,size-1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}