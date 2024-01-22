#include<vector>
class PriorityQueue {
    vector<int>pq;
    public:
    PriorityQueue(){

    }
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }
    void insert(int element){
        pq.push_back(element);
        int childIndex=pq.size()-1;
        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;
            if(pq[childIndex]<pq[parentIndex]){
                int temp=pq[childIndex];
                pq[childIndex]=pq[parentIndex];
                pq[parentIndex]=temp;
                childIndex=parentIndex;
                parentIndex=(childIndex-1)/2;
            }
            else{
                break;
            }
        }
    }
    int removeMin() {
        int minEl=pq[0];
        int maxEl=pq[pq.size()-1];
        pq[0]=maxEl;
        pq[pq.size()-1]=minEl;
        pq.pop_back();
        int parentIndex=0;
        int childIndex=0;
        int childIndex1=(parentIndex*2)+1;
        int childIndex2=(parentIndex*2)+2;
        if(pq[childIndex1]<pq[childIndex2]){
            childIndex=childIndex1;
        }
        else{
            childIndex=childIndex2;
        }
        while(childIndex<pq.size()){
            if(pq[parentIndex]>pq[childIndex]){
                int temp=pq[childIndex];
                pq[childIndex]=pq[parentIndex];
                pq[parentIndex]=temp;
                parentIndex=childIndex;
                childIndex1=(parentIndex*2)+1;
                childIndex2=(parentIndex*2)+2;
                if(pq[childIndex1]<pq[childIndex2]){
                    childIndex=childIndex1;
                }
                else{
                    childIndex=childIndex2;
                }
            }
            else{
                break;
            }
        }
        return minEl;
    }
}