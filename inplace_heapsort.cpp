void heapSort(int arr[], int n) {
    // Write your code
    int child=0;
    int parent=0;
    int child1=0;
    int child2=0;
    for(int i=1;i<n;i++){
        child=i;
        parent=(i-1)/2;
        while(arr[parent]>arr[child] and parent>=0){
            int temp=arr[child];
            arr[child]=arr[parent];
            arr[parent]=temp;
            child=parent;
            parent=(child-1)/2;
        }
    }
    for(int i=n-1;i>=1;i--){
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        parent=0;
        child1=(2*parent)+1;
        child2=(2*parent)+2;
        while(child1<i){
            int min=parent;
            if(arr[min]>arr[child1]){
                min=child1;
            }
            if(child2<i and arr[child2]<arr[min]){
                min=child2;
            }
            if(min==parent){
                break;
            }
            int temp=arr[min];
            arr[min]=arr[parent];
            arr[parent]=temp;
            parent=min;
            child1=(2*parent)+1;
            child2=(2*parent)+2;
        }
    }
}