#include<iostream>
using namespace std;
bool isPermutation(char input1[],char input2[]){
    int size1=strlen(input1);
    int size2=strlen(input2);
    int match=0;
    for(int i=0;i<size1;i++){
        for(int j=i;j<size2;j++){
            if (input1[i]==input2[j]){
                match+=1;
                char temp=input2[j];
                input2[j]=input2[i];
                input2[i]=temp;
                break;
            }
        }
    }
    if(match==size1 and match==size2){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    char input1[100];
    cin>>input1;
    char input2[100];
    cin>>input2;
    if(isPermutation(input1,input2)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}