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
    cout<<"Pratham Bansal"<<endl;
    cout<<"SID-2110105"<<endl;
    int mergearr[10];
    merge(arr1,arr2,mergearr,5,5,n);
    for(int i=0;i<n;i++){
        cout<<mergearr[i]<<" ";
    }
    cout<<endl;
    return 0;
}