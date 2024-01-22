#include<stdio.h>
int main(){
    int a=8;
    float b=7.333;    
    //a.b tells that a spaces will be total taken to print the float and b decimal places
    printf("Hello World\n");  
    //0.1 tells that in the float value we need only one decimal place to print
    printf("The value of a is %d and the value of b is %0.1f\n",a,b);
    return 0;         
    // %c tells character %d tells integer %f tells float %l tells long integer %lf tells double %Lf tells double long
    //const float b means now b is a constant float so we can not reassign the value of b
    // \a produces a visible or audible signal showing alert
}


