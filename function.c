#include<stdio.h>
void printstar(){        // this function gives no return value
    printf("*\n");
}
int sum(int a,int b){    
    int sum=a+b;         // this function gives an integer sum as return value
    return sum;
}

int main(){
    printstar();
    int addition=sum(2,3);
    printf("%d\n",addition);
    return 0;
}

// a void function gives no return value
