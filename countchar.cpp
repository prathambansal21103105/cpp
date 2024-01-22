#include<iostream>
using namespace std;
int main(){
    char c;
    c=cin.get();
    int charcount=0;
    int digitcount=0;
    int whitespace=0;
    while(c!='$'){
        if(c=='0' or c=='1' or c=='2' or c=='3' or c=='4' or c=='5' or c=='6' or c=='7' or c=='8' or c=='9'){
            digitcount+=1;
        }
        else if(c==' ' or c=='\n' or c=='\t'){
            whitespace+=1;
        }
        else{
            charcount+=1;
        }
        c=cin.get();
    }
    cout<<charcount<<" "<<digitcount<<" "<<whitespace<<endl;
    return 0;
}