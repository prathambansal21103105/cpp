#include<stdio.h> // take an input from the user and print its table
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=10;i++){
        int sum;
        sum=i*n;
        printf("%d\n",sum);
    }
    return 0;
}