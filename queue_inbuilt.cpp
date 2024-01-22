#include<iostream>
using namespace std;
#include<queue>
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}

/*
enqueue -> push
front -> front
dequeue -> pop    //here pop doesn't return a value whereas dequeue used to return the front element that was deleted
getSize -> size
bool isEmpty -> empty
*/