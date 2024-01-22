#include<stdio.h>
int main(){
    char c;
    scanf("%s",&c);
    switch(c){
        case 'a':
        printf("Hello\n");
        break;

        case 'b':
        printf("Halo\n");
        break;

        default:
        printf("bye\n");
        break;
    }
    return 0;
}