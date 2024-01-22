#include <iostream>
#include <string>
#include<vector>
using namespace std;

void helper(string input, string test, vector<int> &output){
    
}

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    vector<string> out;
    helper(input,"",out);
    for(int i=0;i<out.size();i++){
        cout<<out[i]<<endl;
    }
    return 0;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
