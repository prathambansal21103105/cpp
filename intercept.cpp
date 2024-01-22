#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        double input[n][2];
        for(int i=0;i<n;i++){
            double a;
            double b;
            cin>>a>>b;
            input[i][0]=a;
            input[i][1]=b; 
        }
        double slope[n];
        slope[0]=1;
        double x1=input[0][0];
        double y1=input[0][1];
        for(int i=1;i<n;i++){
            double x=input[i][0];
            double y=input[i][1];
            double slope1=(y-y1)/(x-x1);
            slope[i]=abs(slope1);
        }
        unordered_map<double,double>map1;
        for(int i=1;i<n;i++){
            if(map1.count(slope[i])==0){
                map1[slope[i]]=1;
            }
            else{
                map1[slope[i]]+=1;
            }
        }
        cout<<map1.size()<<endl;
        t-=1;
    }
    return 0;
}