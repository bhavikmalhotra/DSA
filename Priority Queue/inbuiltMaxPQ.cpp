#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(100);
    pq.push(25);
    pq.push(165);
    pq.push(18);
    pq.push(32);
    pq.push(46);
    cout<<pq.empty()<<endl;
    cout<<pq.size()<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    } 
}


