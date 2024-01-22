#include<iostream>
using namespace std;
void reverseStringWordWise(char input[]){
    int i=0;
    while(input[i]!='\0'){
        i+=1;
    }
    int len_org=i;
    int j=0;
    int k=len_org-1;
    while(j<k){
        int temp=input[j];
        input[j]=input[k];
        input[k]=temp;
        j+=1;
        k-=1;
    }
    int count=0;
    for(int l=0;l<len_org;l++){
        if(l==len_org-1){
            while(count<l){
                int temp=input[count];
                input[count]=input[l];
                input[l]=temp;
                count+=1;
                l-=1;
            }
            break;
        }    
        else if(input[l]==' '){
            int r=l-1;
            while(count<r){
                int temp=input[count];
                input[count]=input[r];
                input[r]=temp;
                count+=1;
                r-=1;
            }
            if(count==r){
                count=l+1;
            }
            else if (count>r){
                count=l+1;
            }
        else if(l==len_org-1){
            while(count<l){
                int temp=input[count];
                input[count]=input[l];
                input[l]=temp;
                count+=1;
                l-=1;
            }
            break;
        }    
        }
        else{
            continue;
        }
    }
}    // hg f ed cba
int main(){
    char s[100];
    cin.getline(s,100);
    reverseStringWordWise(s);
    int i=0;
    while(s[i]!='\0'){
        cout<<s[i];
        i+=1;
    }
    cout<<endl;
    return 0;
}