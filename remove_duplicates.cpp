#include<isotream>
using namespace std;
void removeConsecutiveDuplicates(char input[]){
    if(input[0]=='\0'){
        return;
    }
    else{
        if(input[0]!=input[1]){
            removeConsecutiveDuplicates(input+1);
        }
        else{
            int i;
            for(i=1;input[i]!='\0';i++){
                input[i-1]=input[i];
            }
            input[i-1]='\0';
            removeConsecutiveDuplicates(input);
        }
    }
}
int main(){
    char input[100];
    cin>>input;
    removeConsecutiveDuplicates(input);
    cout<<input<<endl;
    return 0;
}