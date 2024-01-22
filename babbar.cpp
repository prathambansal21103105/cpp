#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;


void reverseStack(stack<int>&input,stack<int>&helper){
    if(input.size()==0){
        return;
    }
    int temp =input.top();
    input.pop();
    reverseStack(input,helper);
    while(input.size()!=0){
        helper.push(input.top());
        input.pop();
    }
    input.push(temp);
    while(helper.size()!=0){
        input.push(helper.top());
        helper.pop();
    }
    



}


void print(stack<int>input){
    if(input.size()==0){
        return;
    }
    int temp =input.top();
    input.pop();
    print(input);
    cout<<temp<<" ";
}



void  lettersCasePermutation(string s,string outputstring,vector<string>&output) {
        if(s.length()==0){
            output.push_back(outputstring);
            return;
        }
        if((97<=s[0] and 122 >=s[0])){
            lettersCasePermutation(s.substr(1),outputstring+char(s[0]-32),output);
            lettersCasePermutation(s.substr(1),outputstring+s[0],output);
        }
        else if((65<=s[0] and 90>=s[0])){
            lettersCasePermutation(s.substr(1),outputstring+char(s[0]+32),output);
            lettersCasePermutation(s.substr(1),outputstring+s[0],output);
        }
        else{
            lettersCasePermutation(s.substr(1),outputstring+s[0],output);

        }
    }
vector<string> letterCasePermutation(string s) {
        vector<string>output;
        lettersCasePermutation(s,"",output);
        return output;
    }



int main(){
    cout<<"Reverse Stack Problem \n";
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    stack<int>input;
    stack<int>extra;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        input.push(x);
    }
    print(input);
    cout<<"\n";
    reverseStack(input,extra);

    print(input);
    cout<<"\n";

    cout<<"Letter case permutation "<<endl;
    cout<<"Enter your string"<<endl;
    string s;
    cin>>s;
    vector<string>ans = letterCasePermutation(s);
    n = ans.size();
    for(int i=0;i<n;i++){
        cout<<ans[i]<<"\n";
    }
    


}