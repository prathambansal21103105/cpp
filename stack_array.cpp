#include<climits>
class StackUsingArray{
    int*data;
    int nextIndex;
    int capacity;

    public:
    StackUsingArray(int totalSize){
        data=new int[4];
        nextIndex=0;
        capacity=totalSize;
    }
    bool isEmpty(){
        if(nextIndex==0){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int element){
        if(nextIndex==capacity){
            // cout<<"Stack full"<<endl;
            // return;
            int *newData=new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newData[i]=data[i];
            }
            capacity*=2;
            delete[]data;
            data=newData;
        }
        data[nextIndex]=element;
        nextIndex+=1;
    }
    int top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
    int size(){
        return nextIndex;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex-=1;
        return data[nextIndex];
    }
};