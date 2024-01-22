#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        long int input[n];
        long int input1[n];
        vector<long int>min1;
        vector<long int>max1;
        for(int i=0;i<n;i++){
            cin>>input[i];
            if(input[i]<0){
                min1.push_back(input[i]);
            }
            else{
                max1.push_back(input[i]);
            }
            input1[i]=abs(input[i]);
        }
        long int maxans1=input1[0];
        long int minans1=input1[0];
        for(int i=0;i<n;i++){
            if(input1[i]>maxans1){
                maxans1=input1[i];
            }
            if(input1[i]<minans1){
                minans1=input1[i];
            }
        }
        if(min1.size()!=0){
            long int mina=min1[0];
            long int maxa=min1[0];
            for(int i=0;i<min1.size();i++){
                if(min1[i]>maxa){
                    maxa=min1[i];
                }
                if(min1[i]<mina){
                    mina=min1[i];
                }
            }
            if(max1.size()==0){
                long int minans=maxa*maxa;
                long int maxans=mina*mina;
                cout<<minans<<" "<<maxans<<endl;
            }
            else{
                long int minb=max1[0];
                long int maxb=max1[0];
                for(int i=0;i<max1.size();i++){
                    if(max1[i]>maxb){
                        maxb=max1[i];
                    }
                    if(max1[i]<minb){
                        minb=max1[i];
                    }   
                }
                long int minans2=mina*maxb;
                long int maxans2=maxans1*maxans1;
                cout<<minans2<<" "<<maxans2<<endl;
            }

        }
        else{
            maxans1=maxans1*maxans1;
            minans1=minans1*minans1;
            cout<<minans1<<" "<<maxans1<<endl;
        }
        t-=1;
    }
    return 0;
}