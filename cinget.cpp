#include<iostream>
using namespace std;
// int main(){
//     char c;
//     cin>>c;
//     int count=0;
//     while(c!='$'){
//         count++;
//         cin>>c;
//     }
//     cout<<count<<endl;
//     return 0;
// }
// it doesn't count space and new line as a variable
int main(){
    char c;
    c=cin.get();
    int count=0;
    while(c!='$'){
        count++;
        c=cin.get();
    }
    cout<<count<<endl;
} // cin.get() counts space enter tab as characters
