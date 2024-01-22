#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int x;
        cin>>x;
        int flag=0;
        for(int j=1;j*j<=x;j++){
            if((x-2*j)%(j+2)==0 && x!=2*j){
                cout<<"YES"<<endl;
                cout<<j<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"NO"<<endl;
        }
        t-=1;
    }
    return 0;
}
 
/*
11 5
21 8
31 11
22 12
41 14
32 16
51 17
42 20
33 21
71 23
52 24
43 26
62 28
91 29
53 31
44 32
63 36
54 38
64 44
55 45



11 5
21 8
31 11
22 12
41 14
32 16
51 17
42 20
61 20
33 21
71 23
52 24
43 26
81 26
62 28
91 29
53 31
44 32
72 32
63 36
54 38
55 45
*/
