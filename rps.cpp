#include<iostream>
#include<string>
using namespace std;
void swap(string input1[],int index1,int index2){
    char temp=input1[index1][0];
    input1[index1][0]=input1[index1][index2];
    input1[index1][index2]=temp;
}
int returnPermutations(string input, string output[]){
    if(input.length()==1){
        output[0]+=input[0];
        return 1;
    }   
    else if(input.length()==2){
        output[0]+=input[0];
        output[0]+=input[1];
        output[1]+=input[1];
        output[1]+=input[0];
        return 2;
    }
    else{
        int ans=0;
        int len=input.length();
        int check=len;
        int si=0;
        int count=0;
        string input1[len];
        while(len>0){
            input1[count]=input;
            if(check!=len){
                swap(input1,count,count);
            }
            int small=returnPermutations(input1[count].substr(1),output+ans);
            ans+=small;
            int ei=ans;
            for(int i=si;i<ei;i++){
                output[i]+=input1[count][0];
            }
            si+=small;
            count+=1;
            len-=1;
        }
        return ans;
    }
}
int main(){
    string str;
    cin>>str;
    string output[1000];
    int ans=returnPermutations(str,output);
    for(int i=0;i<ans;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}