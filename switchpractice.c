#include<stdio.h>
int main(){
    char c;
    scanf("%s",&c);
    switch(c){
        case 'a':
        printf("Hello\n");
        break;
        case'b':
        printf("Hola\n");
        break;
        default:
        printf("Bye\n");
        break;
    }
    return 0;
}