// #include <iostream>
// #include <vector>
// using namespace std;
// #include<vector>
// #include<queue>
// class triplet{
//     public:
//     int element;
//     int r;
//     int c;
//     public:
//     triplet(int val,int row,int col){
//         element=val;
//         r=row;
//         c=col;
//     }
// };

// vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
//     // Write your code here
//     vector<int>out;
//     priority_queue<triplet>pq;
//     for(int i=0;i<input.size();i++){
//         triplet t1((input[i]->at(0))*(-1),i,0);
//         pq.push(t1);
//     }
//     while(!pq.empty()){
//         triplet t2=pq.top();
//         if(t2.c+1<input[t2.r]->size()){
//             triplet t3((input[t2.r]->at(t2.c+1))*(-1),t2.r,t2.c+1);
//             pq.pop();
//             pq.push(t3);
//         }
//         else{
//             pq.pop();
//         }
//         out.push_back((t2.element)*(-1));
//     }
//     return out;
// }

// int main() {
//     int k;
//     cin >> k;

//     vector<vector<int> *> input;

//     for (int j = 1; j <= k; j++) {
//         int size;
//         cin >> size;
//         vector<int> *current = new vector<int>;

//         for (int i = 0; i < size; i++) {
//             int a;
//             cin >> a;
//             current->push_back(a);
//         }

//         input.push_back(current);
//     }

//     vector<int> output = mergeKSortedArrays(input);

//     for (int i = 0; i < output.size(); i++) {
//         cout << output[i] << " ";
//     }

//     return 0;
// };

#include <iostream>
#include <vector>
using namespace std;
#include<vector>
using namespace std;
class triplet{
    public:
    int element;
    int r;
    int c;
    public:
    triplet(int val,int row,int col){
        element=val;
        r=row;
        c=col;
    }
};
class PriorityQueue {
    // Declare the data members here
    vector<triplet>pq;
   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void push(triplet element) {
        // Implement the insert() function here
        pq.push_back(element);
        int child=pq.size()-1;
        int parent=(child-1)/2;
        while(child>0){
            if(pq[parent].element<pq[child].element){
                triplet temp=pq[parent];
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

    triplet top() {
        // Implement the getMax() function here
        if(pq.empty()){
            triplet t1(100,100,100);
            return t1;
        }
        else{
            return pq[0];
        }
    }

    void pop() {
        // Implement the removeMax() function here
        triplet temp=pq[0];
        pq[0]=pq[pq.size()-1];
        pq[pq.size()-1]=temp;
        pq.pop_back();
        cout<<pq.size()<<endl;
        if(pq.size()==2){
            triplet t1=pq[0];
            triplet t2=pq[1];
            if(t1.element>=t2.element){
                pq[0]=t1;
                pq[1]=t2;
            }
            else{
                pq[0]=t2;
                pq[1]=t1;
            }
        }
        else{
        int parent=0;
        int child1=(2*parent)+1;
        int child2=(2*parent)+2;
        int child=0;
        if(pq[child1].element>pq[child2].element){
            child=child1;
        }
        else{
            child=child2;
        }
        while(child<pq.size()){
            if(pq[parent].element<pq[child].element){
                triplet temp=pq[parent];
                pq[parent]=pq[child];
                pq[child]=temp;
                parent=child;
                child1=(2*parent)+1;
                child2=(2*parent)+2;
                if(pq[child1].element>pq[child2].element){
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
        }
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
    void show(){
        for(int i=0;i<pq.size();i++){
            cout<<pq[i].element<<endl;
        }
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    vector<int>out;
    PriorityQueue pq;
    for(int i=0;i<input.size();i++){
        triplet t1((input[i]->at(0))*(-1),i,0);
        pq.push(t1);
    }
    while(!pq.isEmpty()){
        triplet t2=pq.top();
        if(t2.c+1<input[t2.r]->size()){
            triplet t3((input[t2.r]->at(t2.c+1))*(-1),t2.r,t2.c+1);
            pq.pop();
            pq.push(t3);
        }
        else{
            pq.pop();
        }
        out.push_back((t2.element)*(-1));
    }
    return out;
}
int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }
    cout<<endl;

    vector<int> output = mergeKSortedArrays(input);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}