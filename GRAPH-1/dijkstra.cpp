#include <iostream>
using namespace std;

int findMinVertex(int *distance,bool *visited,int n){
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if((distance[i]<distance[minVertex] || minVertex == -1) && !visited[i]){
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(int **edges ,int n){
    int *distance = new int[n];
    bool *visited = new bool[n];

    for(int i = 0; i<n; i++){
        visited[i]=false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;

    for(int i = 0; i<n-1; i++){
        int minVertex = findMinVertex(distance,visited,n);
        visited[minVertex] = true;
        for(int j =0;j<n;j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                int dist = distance[minVertex] + edges[minVertex][j];
                if(dist< distance[j]){
                    distance[j] = dist;
                }
            }
        }
    }

    for(int i =0 ;i<n; i++){
        cout<<i<<" "<<distance[i]<<endl;
    }

    delete []distance;
    delete []visited;
     

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
    dijkstra(edges,n);
    for(int i = 0; i<n;i++){
        delete []edges[i];
    }
    delete []edges;
    
}