#include<stdio.h>
int main(){
    int marks[4];
    for (int i=0;i<=3;i++){
        int n;
        printf("Give the marks of %d student-",i+1);
        scanf("%d",&n);
        marks[i]=n;
    }
    for (int j=0;j<=3;j++){
        printf("Marks of %d student is-\n",j+1);
        printf("%d\n",marks[j]);
    }
    return 0; 
}