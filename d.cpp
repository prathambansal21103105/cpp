#include<iostream>
using namespace std;
int roundoff(float b){
    float c;
    c=b;
    if (b==int(b)){
        return int(b);
    }
    while(true){
        b=b*10;
        if (int(b)%10>=5){
            return int(c)+1;
            break;
        }
        else{
            return int(c);
            break;
        }
        }
    }
int main(){
    int salary;
    cin>>salary;
    char grade;
    cin>>grade;
    int allow;
    if (grade=='A'){
        allow=1700;
    }
    else if (grade=='B'){
        allow=1500;
    }
    else{
        allow=1300;
    }
    float total;
    total=salary+0.2*(salary)+0.5*(salary)+allow-0.11*(salary);
    int ans=roundoff(total);
    cout<<ans<<endl;
    return 0;
}