#include<iostream>
#include<queue>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
    priority_queue<int>a;
    int n,x,y;
    cin>>n>>x>>y;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    for(int i=0;i<n;i++){
        a.push(-1*input[i]);
    }
    while(y>0){
        int smallest=(-1)*a.top();
        int min=smallest;
        if((min^x)>min){
            a.pop();
            a.push(-(min^x));
        }
        else{
            if(y%2==0){
                break;
            }
            else{
                a.pop();
                a.push(-(min^x));
                break;
            }
        }
        y-=1;
    }
    for(int i=0;i<n;i++){
        int element=a.top();
        element=element*(-1);
        cout<<element<<" ";
        a.pop();
    }
    cout<<endl;
    t-=1;
    }
    return 0;
}

/*
step0 -> 25 20 15 10 5
step1 -> 25 20 17 15 10
step2 -> 30 25 20 17 15
step3 -> 30 27 25 20 17
step4 -> 30 27 25 20 5
step5 -> 30 27 25 20 17
step6 -> 30 27 25 20 5



*/