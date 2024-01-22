#include<iostream>
using namespace std;  // strings are 1d character arrays
int len_array(char name[]){
    int length=0;
    int i=0;
    while(name[i]!='\0'){
        length+=1;
        i+=1;
    }
    return length;
}
int main(){
    char name[100];
    cout<<"Enter your name:";
    cin>>name;
    cout<<name<<endl;
    int ans=len_array(name);
    cout<<ans<<endl;
    return 0;
}
// now there is null character on 5th index--> '\0'