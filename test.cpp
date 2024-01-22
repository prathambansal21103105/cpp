#include<iostream>
#include<cstring>
using namespace std;
void minLengthWord(char input[],char output[]){
    int count=0;
    int countarray[100];
    int indexarray[100];
    int c=0;
    int i=0;
    int r=0;
    while(input[r]!='\0'){
        r+=1;
    }
    for(i=0;i<r;i++){
        if(input[i]==' '){
            countarray[c]=count;
            indexarray[c]=i-count;
            c+=1;
            count=0;
        }
        else{
            count+=1;
        }
    }
    countarray[c]=count;
    indexarray[c]=i-count;
    int min=countarray[0];
    int minindex=0;
    for(int l=c;l>=0;l--){
        if(countarray[l]<min){
            min=countarray[l];
            minindex=indexarray[l];
        }
    }
    for(int j=minindex;j<minindex+min;j++){
        cout<<input[j];
    }
    cout<<endl;
}
int main(){
    char input[100];
    cin.getline(input,100);
    char output[100];
    minLengthWord(input,output);
    return 0;
}