#include <iostream>
#include <algorithm>
using namespace std;
int pairSum(int arr[],int n,int num){
    int ans=0;
    for(int i=0;i<n;i++){
        int curr=arr[i];
        int rest=num-arr[i];
        for(int j=0;j<n;j++){
            if(rest==arr[j] and j!=i){
                ans+=1;
            }
        }
    }
    return ans/2;
}
int tripletSum(int *arr, int n, int num)
{
    int ans=0;
    for(int i=0;i<n;i++){
        int curr=arr[i];
        int rest=num-arr[i];
        int temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        int pair=pairSum(arr+1,n-1,rest);
        int temp1=arr[i];
        arr[i]=arr[0];
        arr[0]=temp1;
        ans+=pair;
    }
    return ans/3;
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;
        

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}