#include<iostream>
using namespace std;
void print_Keypad(int n,string str1){
    if(n==0){
        cout<<str1<<endl;
    }
    else{
        int last_digit=n%10;
        string str;
        if(last_digit==2){
            str="abc";
        }
        else if(last_digit==3){
            str="def";
        }
        else if(last_digit==4){
            str="ghi";
        }
        else if(last_digit==5){
            str="jkl";
        }
        else if(last_digit==6){
            str="mno";
        }
        else if(last_digit==7){
            str="pqrs";
        }
        else if(last_digit==8){
            str="tuv";
        }
        else if(last_digit==9){
            str="wxyz";
        }
        for(int i=0;i<str.length();i++){
            print_Keypad(int(n/10),str[i]+str1);
        }
    }
}
int main(){
    int n;
    cin>>n;
    print_Keypad(n,"");
    return 0;
}