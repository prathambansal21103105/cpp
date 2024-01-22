#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int x,y;
        cin>>x>>y;
        int sum=x+y;
        if ((x+y)%2==0){
            int ans=(x+y)/2;
            cout<<abs(ans-x)<<endl;
        }
        else{
            int ans1=abs(x-((x+y)/2));
            int ans2=abs(y-((x+y)/2));
            if (ans1>=ans2){
                cout<<ans1<<endl;
            }
            else{
                cout<<ans2<<endl;
            }
        }

        t-=1;
    }
    return 0;
}