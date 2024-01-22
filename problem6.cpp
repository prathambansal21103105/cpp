#include<iostream>
using namespace std;
int main(){

    int row;
  
    int n=1;
    
    cin>>row;

    for(int i=1;i<=row;i++){  //loop for kitni rows print krni hai
        for(int j=1;j<=i;j++){ //loop for kitne numbers ek row mein print karne hai jo ki hai equal to no. of the current row
            
            cout<<n<<" ";
            n++;
        
        }
        
        cout<<endl;
    }
    
    
    
    
    
    
    return 0;
}