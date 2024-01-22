#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t>0){
        int x,y;
        cin>>x>>y;
        int smaller=min(x,y);
        int larger=max(x,y);
        int steps=0;
      
        while (smaller<larger){
            smaller*=2;
            steps+=1;
            if (smaller>=larger){
                break;
            }
        }
        if (smaller==larger){
            steps+=larger;
        }    
        else{
            steps=-1;
        }
        cout<<steps<<endl;
        t-=1;
    }
    return 0;
} 