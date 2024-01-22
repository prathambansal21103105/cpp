#include<iostream>
#include <string>
using namespace std;
int keypad(int num, string output[]){
    // cout<<"ran"<<endl;
    if(num==0){
        output[0]="";
        return 1;
    }
    string check[8];
    check[0]="abc";
    check[1]="def";
    check[2]="ghi";
    check[3]="jkl";
    check[4]="mno";
    check[5]="pqrs";
    check[6]="tuv";
    check[7]="wxyz";
    int a = keypad((num/10),output);
    int n = num%10;
    int b=check[n-2].size();
    int k=0;
    for(int i=0;i<b-1;i++){
        int j=0;
        for(;j<a;j++){
            output[a+k+j]=output[j];
        }
        k=k+j;
    }
    int m=0;
    for(int i=0;i<b;i++){
        int j=0;
        for(;j<a;j++){
            output[j+m]=output[j+m] +check[n-2][i];
        }
        m = m+j;
    }
    return b*a;

}
// include <iostream>

// #include "solution.h"
// using namespace std;

int main(){

    // int num = 42;
    // string output[10000];
    // int count =keypad(num,output);
    // for(int i=0;i<count and i<10000;i++){
    //     cout<<output[i]<<endl;
    // }
    int num;
    cin >> num;

    string output[1000];
    int count = keypad(num, output);
    
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}