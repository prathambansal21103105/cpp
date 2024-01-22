#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t>0){
        int n;
        cin>>n;

        bool flag=true;
        int min=INT_MAX,max=INT_MIN;

        int an[n];
        for (int i=0;i<n;i++){
            cin>>an[i];
        }
        for (int i=0;i<n;i++){

            if(an[i]<min)
            {
                min=an[i];
            }
            if(an[i]>max)
            {
                max=an[i];
            }

            if(an[i]<=min or an[i]>=max)
            {
                continue;
            }
            else
            {
                flag=false;
                break;
            }
        }

        if(flag==true)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }

        t-=1;
    }
    return 0;
}