#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int input[n];
        for(int i=0;i<n;i++){
            cin>>input[i]; 
        }
        int fre[n];
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(input[i]==input[j]){
                    count+=1;
                }
            }
            fre[i]=count;
        }
        int max=-1;
        int index=n+1;
        for(int i=0;i<n;i++){
            if(fre[i]>max){
                max=fre[i];
                index=i;
            }
        }
        int indexarr[n];
        int c=0;
        for(int i=0;i<n;i++){
            if(fre[i]==max){
                indexarr[c]=i;
                c++;
            }
        }
        int flag=0;
        for(int j=0;j<c;j++){
            if(input[index]==input[indexarr[j]]){
                continue;
            }
            else{
                cout<<"NO"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"YES"<<endl;
        }
        
        t-=1;
    }
    return 0;
}