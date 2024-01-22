#include<stdio.h>
int factorial(int n1){
    if(n1==0){
        return 1; 
    }
    else if(n1==1){
        return 1;
    }
    else{
        return n1*factorial(n1-1);
    }

}
int main(){
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    int fact;
    fact=factorial(n);
    printf("%d\n",fact);
    return 0;
} 