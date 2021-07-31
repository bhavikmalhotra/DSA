#include <iostream>
#include <queue>
using namespace std;
class Prims{
    int vertex;
    int parent;
    int weight;

};
int findMinVertex(int *weight,bool *visited,int n){
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if((weight[i]<weight[minVertex] || minVertex == -1) && !visited[i]){
            minVertex = i;
            //visited[i] = true;
        }
    }
    return minVertex;

}
void prims(int **edges ,int n){
    int *parent = new int[n];
    int *weight = new int[n];
    bool *visited = new bool[n];

    for(int i = 0; i<n ;i++){
        visited[i]=false;
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;

    for(int i =0;i<n;i++){
        //find min vertex
        int minVertex = findMinVertex(weight,visited,n);
        visited[minVertex] = true;
        //comapre
        for(int j =0;j<n;j++){
            if(edges[minVertex][j] && !visited[j]){
                if(edges[minVertex][j] < weight[j]){
                    weight[j] = edges[minVertex][j];
                    parent[j] =  minVertex;

                }
            }
        }
    }   

    for(int i =1 ;i<n; i++){
        if(parent[i]<i){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }    
}
int main(){
    int n,E;
    cin>>n>>E;
    int **edges = new int*[n];
    for(int i = 0; i< n ;i++){
        edges[i] = new int[n];
        for(int j = 0;j<n ;j++){
            edges[i][j]=0;
        }
    }

    for(int i =0;i<E;i++){
        int f,s,w;
        cin>>f >> s>> w;
        edges[f][s] = w;
        edges[s][f] = w;

    }
    cout<<endl;
    prims(edges,n);
    for(int i = 0; i<n;i++){
        delete []edges[i];
    }
    delete []edges;
    
}