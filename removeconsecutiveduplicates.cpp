#include<iostream>
using namespace std;
void removeConsecutiveDuplicates(char input[]){
    char prev=input[0];
    char input1[100];
    input1[0]=input[0];
    int count=0;
    for(int i=1;i<strlen(input);i++){
        if(input[i]==input[i+1] and input[i]!=prev){
            count+=1;
            input1[count]=input[i];
            prev=input[i];
        }
        else if (input[i]!=input[i+1] and input[i]!=prev){
            count+=1;
            input1[count]=input[i];
            prev=input[i];
        }
    }
    for(int i=0;i<strlen(input1)-1;i++){
        input[i]=input1[i];
    }
    for(int i=strlen(input1);i<strlen(input);i++){
        input[i]=' ';
    }
}
int main(){
    char input[100];
    cin>>input;
    removeConsecutiveDuplicates(input);
    cout<<input<<endl;
    return 0;
}

// // When string is empty, return
//     if (input[0] == '\0')
//         return;
 
//     // if the adjacent characters are same
//     if (input[0] == input[1]) {
         
//         // Shift character by one to left
//         int i = 0;
//         while (input[i] != '\0') {
//             input[i] = input[i + 1];
//             i++;
//         }
 
//         // Check on Updated String S
//         removeConsecutiveDuplicates(input);
//     }
 
//     // If the adjacent characters are not same
//     // Check from S+1 string address
//     removeConsecutiveDuplicates(input + 1);