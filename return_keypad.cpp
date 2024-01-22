#include<iostream>
#include<string>
using namespace std;
int keypad(int n,string output[]){
    if(n==0 or n==1){
        output[0]="";
        return 1;
    }
    else{
            int ans=keypad(n/10,output);       
            int lastdigit=n%10;
            string arr[10000];
            string str;
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
            int k=0;
            for(int i=0;i<ans;i++){
                for(int j=0;j<str.length();j++){
                    arr[k]=output[i]+str[j];
                    k++;
                }
            }
            for(int i=0;i<k;i++){
                output[i]=arr[i];
            }
            return ans*str.length();
    }
}
int main(){
    int n;
    cin>>n;
    string*output=new string[1000];
    int ans=keypad(n,output);
    for(int i=0;i<ans;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}

/*
j i  k
0 a  d   ad
1 a  e
2 a  f
*/