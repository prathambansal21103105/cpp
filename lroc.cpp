#include<iostream>
using namespace std;
void findLargest(int input[][100],int nRows, int mCols){
    int max1;
    int index1;
    if (nRows==0 and mCols==0){
        cout<<"row "<<0<<" "<<-2147483648;
    }
    else{
    for(int i=0;i<nRows;i++){
        int sum1=0;
        for(int j=0;j<mCols;j++){
            sum1+=input[i][j];
        }
        if (i==0){
            max1=sum1;
            index1=0;
        }
        if (sum1>max1){
            max1=sum1;
            index1=i;
        }
    }
    int max2;
    int index2;
    for(int j=0;j<mCols;j++){
        int sum2=0;
        for(int i=0;i<nRows;i++){
            sum2+=input[i][j];
        }
        if (j==0){
            max2=sum2;
            index2=0;
        }
        if (sum2>max2){
            max2=sum2;
            index2=j;
        }
    }
    if(max1>=max2){
        cout<<"row "<<index1<<" "<<max1<<endl;
    }
    else{
        cout<<"col "<<index2<<" "<<max2<<endl;
    }
    }
}
int main(){
    int t;
    cin>>t;
    while (t>0){
        int n,m;
        cin>>n>>m;
        int input[100][100];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>input[i][j];
            }
        }
        findLargest(input,n,m);
        t-=1;
    }
    return 0;
}