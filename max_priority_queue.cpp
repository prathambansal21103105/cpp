#include<vector>
class PriorityQueue {
    // Declare the data members here
    vector<int>pq;
   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int child=pq.size()-1;
        int parent=(child-1)/2;
        while(child>0){
            if(pq[parent]<pq[child]){
                int temp=pq[parent];
                pq[parent]=pq[child];
                pq[child]=temp;
                child=parent;
                parent=(child-1)/2;
            }
            else{
                break;
            }
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty()){
            return 0;
        }
        else{
            return pq[0];
        }
    }

    int removeMax() {
        // Implement the removeMax() function here
        int temp=pq[0];
        int return1=pq[0];
        pq[0]=pq[pq.size()-1];
        pq[pq.size()-1]=temp;
        pq.pop_back();
        int parent=0;
        int child1=(2*parent)+1;
        int child2=(2*parent)+2;
        int child=0;
        if(pq[child1]>pq[child2]){
            child=child1;
        }
        else{
            child=child2;
        }
        while(child<pq.size()){
            if(pq[parent]<pq[child]){
                int temp=pq[parent];
                pq[parent]=pq[child];
                pq[child]=temp;
                parent=child;
                child1=(2*parent)+1;
                child2=(2*parent)+2;
                if(pq[child1]>pq[child2]){
                    child=child1;
                }
                else{
                    child=child2;
                }
            }
            else{
                break;
            }
        }
        return return1;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
};