#include<stdio.h>

int main(){
    int a,b;
    
    printf("Enter number a:");
    scanf("%d", &a);      // & and % are used to store a value
    
    printf("Enter number b:");
    scanf("%d", &b);

    int sum;
    printf("The sum is %d\n",a+b);
    
    return 0;
}