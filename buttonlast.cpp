#include<iostream>
using namespace std;
int main(){

    char button;
    cout<<"Please give an alphabet"<<endl;
    cin>>button;

    // if(button=='a'){
    //     cout<<"namaste"<<endl;
    // }
    // else if(button=='b'){
    //     cout<<"Hello"<<endl;
    // }
    // else{
    //     cout<<"I am still learning more"<<endl;
    // }

    switch(button){
        case 'a':
        cout<<"namaste"<<endl;
        break;
        case'b':
        cout<<"hello"<<endl;
        break;
        default:
        cout<<"I am still learning more"<<endl;
        break;

    }





    return 0;
}