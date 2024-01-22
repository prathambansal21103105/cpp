#include<iostream>
using namespace std;

bool is_sorted(int input[],int size){
    if(size<2){
        return true;
    }
    else{
        bool check=input[size-2]<input[size-1];
        return (check and is_sorted(input,size-1));
    }
}

int main(){
    int size;
    cin>>size;
    int input[size];
    for(int i=0;i<size;i++){
        cin>>input[i];
    }
    if(is_sorted(input,size)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}