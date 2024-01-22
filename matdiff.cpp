#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t>0){
        int n;
        cin>>n;

        int matrix[n][n];
        int k=1;
        int l=n*n;
        if(n%2==1){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(((i+j)%2)==0){
                        matrix[i][j]=k;
                        k+=1;
                    }
                    else{
                        matrix[i][j]=l;
                        l-=1;
                    }
                    cout<<matrix[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        else{
            int k=1;
            int l=n*n;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i%2==0){
                        if(j%2==0){
                            matrix[i][j]=k;
                            if(j==n-2){
                                k+=(n/2);
                            }
                            else{
                                k+=1;
                            }
                        }
                        else{
                            matrix[i][j]=l;
                            if(j==n-1){
                                l-=(n/2);
                            }
                            else{
                                l-=1;
                            }
                        }
                    }
                    else{
                        if(j%2==0){
                            matrix[i][j]=l;
                            if(j==n-2){
                                l-=(n/2);
                            }
                            else{
                                l+=1;
                            }
                        }
                        else{
                            matrix[i][j]=k;
                            if(j==n-1){
                                k+=(n/2);
                            }
                            else{
                                k-=1;
                            }
                        }
                    }
                    cout<<matrix[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        t-=1;
    }
    return 0;
}

/*
8 7 6 5 4 3 2 1

24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1


*/