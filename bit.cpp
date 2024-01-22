#include<iostream>
using namespace std;

int sum(int bit[], int index){
    int sum1=0;
    for(int i=index;i>0;i-=(i&(-i))){
        sum1+=bit[i];
    }
    return sum;
}
void update(int bit[], int index, int last, int x){
    for(int i=index;i<=last;i+=(i&(-i))){
        bit[i]+=x;
    }
}

int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    int bit[n+1];
    sum(bit,n);
    update(bit,,n,x);
    return 0;
}