#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;

        int arr[20][6];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i][0];

            for(int j=1;j<arr[i][0]+1;j++)
            {
                cin>>arr[i][j];
            }
        }
        int flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i){
                    unordered_set<int>un;
                    for(int k=1;k<arr[i][0]+1;k++){
                        un.insert(arr[i][k]);
                    }
                    for(int k=1;k<arr[j][0]+1;k++){
                        un.insert(arr[j][k]);
                    }
                    if(un.size()==5){
                        flag=1;
                    }
                }
            }
        }
        if(flag==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}