#include <iostream>
#include<vector>
using namespace std;
int b=0;
int c=0;
void helper(int input[], int size, vector<int>&v){
    if(size==0){
        b+=1;
        if(b==9){
            return;
        }
        cout<<b<<endl;
        cout<<"yes1"<<endl;
        if(v.empty()){
            cout<<endl;
        }
        else{
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
        while(!v.empty()){
            v.pop_back();
        }
    }
    c+=1;
    if(c==10){
        return;
    }
    cout<<"yes"<<endl;
    helper(input+1,size-1,v);
    v.push_back(input[0]);
    helper(input+1,size-1,v);
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    vector<int>v;
    helper(input,size,v);
}
int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}


