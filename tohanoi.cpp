#include<iostream>
using namespace std;
void towerOfHanoi(int n,char source,char auxiliary,char destination){
    if(n>0){
        if(n==1){
            cout<<source<<" "<<destination<<endl;
        }
        else{
            towerOfHanoi(n-1,source,destination,auxiliary);
            towerOfHanoi(1,source,auxiliary,destination);
            towerOfHanoi(n-1,auxiliary,source,destination);
        }
    }
}
int main(){
    int n;
    cin>>n;
    char source='a';
    char auxiliary='b';
    char destination='c';
    towerOfHanoi(n,source,auxiliary,destination);
    return 0;
}

/*
n=3
S- 1 2 3
A-
D-
3-- S-D   
2-- S-A
3-- D-A
1-- S-D
3-- A-S
2-- A-D
3-- S-D
n=3
a c
a b
c b
a c
b a
b c
a c
*/