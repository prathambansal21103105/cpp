#include<iostream>
#include<math.h>
using namespace std;
bool Pythagorean(int x,int y,int z){
    if(pow(x,2)+pow(y,2)==pow(z,2) or pow(x,2)+pow(z,2)==pow(y,2) or pow(z,2)+pow(y,2)==pow(x,2)){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int x,y,z;
    int max=0;
    cin>>x>>y>>z;

    if (Pythagorean(x,y,z)==1){
        cout<<"Yes its a Pythagorean triplet."<<endl;
    }
    else{
        cout<<"No its not a Pythagorean triplet."<<endl;
    }
    return 0;
}
