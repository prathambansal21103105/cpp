#include<iostream>
#include<string>
using namespace std;
int main(){
    char input1[100];
    cin>>input1;
    int len=strlen(input1);  //1 /// len function for a string or char array
    cout<<len<<endl;
    char input2[100];
    cin>>input2;            // to compare to strings if they are equal
    if (strcmp(input1,input2)==0){   //2
        cout<<"true"<<endl;
    }                        // if strings are equal we get 0 , otherwise we get any other number as output
    else{
        cout<<"false"<<endl;
    }
    

    return 0;
}