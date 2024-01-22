#include<stdio.h>
int main(){
    int j;
    for(int i=0, j=0;i<=5;i++,j++){
        printf("%d %d\n",i,j);
    }
    return 0;
}
// here for multiple iterator; to initialize them use (,)
// for giving conditions for multiple iterators use (,) and use(;)between different instructions
// expression 3 that we use i++ is optional
// you can simply write i++; in your for loop