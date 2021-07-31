#include <iostream>
#include <algorithm>
using namespace std;

class Edge{
    public:
        int source;
        int dest;
        int weight;
};

bool compare(Edge e1,Edge e2){
    return e1.weight < e2.weight;
}

int findParent(int n ,int *parent){

    if(parent[n]==n){
        return n;
    }

    return findParent(parent[n],parent);


}

void kruskals(Edge *input,int n ,int E){
    //Sort the input array in asc order according to weight;
    sort(input,input+E,compare);

    Edge *output = new Edge[n-1];

    int *parent = new int [n];
    for(int i = 0; i<n;i++){
        parent[i] = i;
    }

    int count = 0;
    int i = 0;

    while(count != n-1){
        Edge currentEdge = input[i];
        //Check if we can add the edge or not;
        int sourceParent = findParent(input[i].source,parent);
        int destParent = findParent(input[i].dest,parent);

        if(sourceParent != destParent){
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    for(int i =0; i<n-1 ;i++){
        if(output[i].source<output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }else{
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }

}

int main(){
    int n,E;
    cin>>n>>E;
    Edge *input = new Edge[E];

    for(int i =0 ;i < E ; i++){
        int s,d,w;
        cin>> s>> d>> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskals(input,n,E);

}