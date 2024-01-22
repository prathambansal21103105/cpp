#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        s=s+s;
        if(c=='g'){
            cout<<0<<endl;
            t-=1;
            continue;
        }
        vector<int>count;
        int time=0;
        char goal='g';
        int flag=0;
        for(int i=0;i<n+n;i++){
            if(flag==1){
                time+=1;
            }
            if(s[i]==c){
                if(flag==1){
                    continue;
                }
                else if(flag==0){
                    time=0;
                    flag=1;
                }
            }
            if(s[i]==goal){
                if(time!=0){
                    count.push_back(time);
                }
                flag=0;
                time=0;
            }
        }
        int max1=count[0];
        for(int i=0;i<count.size();i++){
            max1=max(max1,count[i]);
        }
        cout<<max1<<endl;
        t-=1;
    }
    return 0;
}