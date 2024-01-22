#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t>0){
	    int n;
	    cin>>n;
	    char input[1000000];
	    cin>>input;
        string plus="";
        string minus="";
	    int countplus=0;
	    int countminus=0;
        priority_queue<int>pq;
	    for(int i=0;i<n;i++){
	        if(int(input[i])==43){
                plus=input[i];
	            countplus+=1;
	        }
	        if(int(input[i])==45){
                minus=input[i];
	            countminus+=1;
	        }
	        if(int(input[i])>=48 and int(input[i])<=57){
                pq.push(int(input[i])-48);
	        }
	    }

        int total=pq.size()-countplus-countminus;
        string output="";
        int range=pq.size();
        for(int i=0;i<range;i++){
            if(i<total){
                output+= to_string(pq.top());
                pq.pop();
            }
            else if(i>=total and i<total+countplus){
                output+=plus;
                output+= to_string(pq.top());
                pq.pop();
            }
            else{
                output+=minus;
                output+= to_string(pq.top());
                pq.pop();
            }
        }
        cout<<output<<endl;
	    t-=1;
	}
	return 0;
}