#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        vector<long long>ev1;
        long long n;
        cin>>n;
        long long input[2*n];
        long long countodd=0;
        long long counteven=0;
        for(int i=0;i<2*n;i++){
            cin>>input[i];
            if (input[i]%2==0){
                counteven+=1;
                ev1.push_back(v[i]);
            }
            else{
                countodd+=1;
            }
        }
        long long max1;
        long long min1;
        if (counteven>=countodd){
            max1=counteven;
            min1=countodd;
        }
        else{
            max1=countodd;
            min1=counteven;
        }
        long long ans=(max1-min1)/2;
        if(counteven==countodd){
            cout<<0<<endl;
        }
        else if (countodd>counteven){
            cout<<ans<<endl;
        }
        else{
            long long ans1=0;
            long long diff1=(counteven-countodd)/2;
            long long traverse1=0;
            while(diff1){
                long long count1=0;
            for (int 1=0;i<even; i++){
                if([i]!=0){
                    ev1[i]=ev1[i]/2;
                    if (ev1[i]%2 == 1){
                        count1++;
                        ev1[i]=0;
                    }
                }
            }
            traverse1++;
            if (diff1>count1) {
            ans1+=count1*traverse1;
            diff1=diff1-count1;
            }
            else{
                ans1+= diff1*traverse1;
                break;
            }
            }
            cout<<ans1<<endl;
        }
        t-=1;
    }
    return 0;
}