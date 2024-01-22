#include<iostream>
using namespace std;
bool check(int rest[],int count,int diff){
    if(rest[0]==-1){
        return false;
    }
    else if(rest[0]==diff){
        return true;
    }
    else{
        bool a=check(rest+1,count-1,diff);
        bool b=check(rest+1,count-1,diff-rest[0]);
        return a or b;
    }
}
bool splitArray(int input[],int size){
    int sum=0;
    int sum3=0;
    int sum5=0;
    int rest[100];
    int count=0;
    for(int i=0;i<size;i++){
        sum+=input[i];
        if(input[i]%5==0){
            sum5+=input[i];
        }
        else if(input[i]%3==0 and input[i]%5!=0){
            sum3+=input[i];
        }
        else{
            rest[count]=input[i];
            count+=1;
        }
    }
    rest[count]=-1;
    count+=1;
    int target=sum/2;
    if(sum%2!=0){
        return false;
    }
    else if(sum5==target or sum3==target){
        return true;
    }
    else if(sum%2==0 and sum5<target and sum3<target){
        int diff=target-sum5;
        if(check(rest,count,diff)){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(splitArray(arr,n)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}