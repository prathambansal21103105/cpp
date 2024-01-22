#include<iostream>
using namespace std;

long long binarysearch(long long lower, long long upper, long long x, long long y){
    long long mid=(lower+upper)/2;
    if(upper<lower){
        return -1;
    }
    if(mid%x==y%mid){
        return mid;
    }
    else{
        if(mid%x<y%mid){
            if(mid+1<=)
            return binarysearch(mid+1,upper,x,y);
        }
        else{
            return binarysearch(lower,mid-1,x,y);
        }
    }
}
/*
1.
x=12
y=46

range= 35 - 46
11 0  1 2 3 4 5 6 7 8 9 10
11 10 9 8 7 6 5 4 3 2 1 0

2.
x=14 
y=48

range=35 - 48
7  8  9  10 11 12 13 0 1 2 3 4 5 6
13 12 11 10 9  8  7  6 5 4 3 2 1 0



*/

int main(){

    int t;
    cin>>t;
    while(t>0){
        long long x,y;
        cin>>x>>y;
        
        if(x==2){
            cout<<2<<endl;
        }
        else if(y%x==0){
            cout<<x<<endl;
        }
        else{
            if(x>y){
                long long ans=x+y;
                cout<<ans<<endl;
            }
            else{
                long long lower=y-x+1;
                long long upper=y;
                long long ans=binarysearch(lower,upper,x,y);
                cout<<ans<<endl;
            }
        }
        t-=1;
    }


    return 0;
}

/*
#include<iostream>
using namespace std;
 
long long binarysearch(long long lower, long long upper, long long x, long long y){
    long long mid=(lower+upper)/2;
    if(upper<lower){
        return -1;
    }
    if(mid%x==y%mid){
        return mid;
    }
    else{
        if(mid%x<y%mid){
            return binarysearch(mid+1,upper,x,y);
        }
        else{
            return binarysearch(lower,mid-1,x,y);
        }
    }
}
 
int main(){
 
    int t;
    cin>>t;
    while(t>0){
        long long x,y;
        cin>>x>>y;
        
        if(x==2){
            cout<<2<<endl;
        }
        else if(y%x==0){
            cout<<x<<endl;
        }
        else{
            if(x>y){
                long long ans=x+y;
                cout<<ans<<endl;
            }
            else{
                long long ans1=y-((y%x)/2);
                cout<<ans1<<endl;
            }
        }
        t-=1;
    }
 
 
    return 0;
}

*/