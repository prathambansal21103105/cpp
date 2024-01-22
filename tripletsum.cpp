#include<iostream>
using namespace std;
int tripletSum(int input1[],int size1,int x){
    int triplets=0;
    for(int i=0;i<size1;i++){
        int n1=input1[i];
        for(int j=0;j<size1;j++){
            if (j!=i){
                int n2=input1[j];
                for(int k=0;k<size1;k++){
                    if (k!=j and k!=i){
                        int n3=input1[k];
                        int sum=input1[i]+input1[j]+input1[k];
                        if(sum==x){
                            triplets+=1;
                        }
                    }
                }
            }
        }  
    }
    return int(triplets/6);
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int size1;
        cin>>size1;
        int input1[size1];
        for(int i=0;i<size1;i++){
            cin>>input1[i];
        }
        int x;
        cin>>x;
        int ans;
        ans=tripletSum(input1,size1,x);
        cout<<ans<<endl;
        t-=1;
    }
    return 0;
}