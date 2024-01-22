#include<iostream>
#include<vector>
using namespace std;
void linearsearch(int arr[], int size, int target, vector<int>& output){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            output.push_back(i);
        }
    }
    if(output.size()==0){
        output.push_back(-1);
    }
    return;
}
int main(){
    int arr[]={1,4,7,7,8,9,18,27,31,56,81};
    int size=11;
    cout<<"Pratham Bansal"<<endl;
    cout<<"SID-2110105"<<endl;
    vector<int>output;
    linearsearch(arr,size,1,output);
    while(output.size()!=0){
        cout<<output[output.size()-1]<<" ";
        output.pop_back();
    }
    cout<<endl;
    linearsearch(arr,size,81,output);
    while(output.size()!=0){
        cout<<output[output.size()-1]<<" ";
        output.pop_back();
    }
    cout<<endl;
    linearsearch(arr,size,7,output);
    while(output.size()!=0){
        cout<<output[output.size()-1]<<" ";
        output.pop_back();
    }
    cout<<endl;
    linearsearch(arr,size,3,output);
    while(output.size()!=0){
        cout<<output[output.size()-1]<<" ";
        output.pop_back();
    }
    cout<<endl;
    cout<<"Searching complexity: O(n)"<<endl;
    return 0;
}