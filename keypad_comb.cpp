#include<iostream>
#include<string>
using namespace std;
void keypad_comb(int n){
    if(n==0 or n==1){
        cout<<""<<endl;
    }
    else{
    
    keypad_comb(n/10);
    int lastdigit=n/10;
    string str="";
    if(lastdigit==2){
        str="abc";
    }
    else if(lastdigit==3){
        str="def";
    }
    else if(lastdigit==4){
        str="ghi";
    }
    else if(lastdigit==5){
        str="jkl";
    }
    else if(lastdigit==6){
        str="mno";
    }
    else if(lastdigit==7){
        str="pqrs";
    }
    else if(lastdigit==8){
        str="tuv";
    }
    else if(lastdigit==9){
        str="wxyz";
    }
    
    }
}
int main(){
    int n;
    cin>>n;
    keypad_comb(n);
    return 0;
}