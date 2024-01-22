#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        int price1 = 100-a;
        int price2 = 2 * (100-b);
        cout<<price1<<" "<<price2<<endl;
        if(price1<price2){
            cout<<"FIRST"<<endl;
        }
        else if(price1>price2){
            cout<<"SECOND"<<endl;
        }
        else{
            cout<<"BOTH"<<endl;
        }
    }

    return 0;
}