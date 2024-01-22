#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        long long n;
        cin>>n;
        int count1=0;
        long long input[n];
        int count=0;
        for(int i=0;i<n;i++){
            cin>>input[i];
            if(input[i]!=0){
                count+=1;
                if(input[i]==1){
                    count1+=1;
                }
            }
        }
         if(n==1){
            cout<<"alice"<<endl;
            t-=1;
            continue;
        }
        int sum1=0;
        int index1=0;
        for(int i=0;i<n;i++){
            if(input[i]!=0){
                sum1+=1;
                if(sum1==count-1){
                    index1=i;
                    break;
                }
            }
        }
        int count2=0;
        int countnew=0;
        for(int i=0;i<index1;i++){
            if(input[i]==1 or input[i]==-1){
                countnew+=1;
            }
            else{
                if(input[i]!=0){
                    count2+=1;
                }
            }
        }
        if(count2%2==0 and countnew%2==0){
            steps+=0;
        }
        else if(count2%2==0 and countnew%2!=0){
            steps+=1;
        }
        else if(count2%2!=0 and countnew%2==0){
            steps+=0;
        }
        else{
            steps+=1;
        }
        int steps=0;
        if(input[index1]==1 or input[index1]==-1){
            steps+=0;
        }
        else{
            steps+=1;
        }
        if(steps%2!=0){
            cout<<"alice"<<endl;
        }
        else{
            cout<<"bob"<<endl;
        }
        t-=1;
    }
    return 0;
}