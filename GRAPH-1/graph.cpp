#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void printBFS(int **edges, int n ,int sv,bool *visited){
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv]=true;
    while(!pendingVertices.empty()){
        int currentINdex = pendingVertices.front();
        pendingVertices.pop();
        cout<<currentINdex<<endl;
      
        for(int i = 0 ; i<n;i++){
            if(i == currentINdex){
                continue;
            }
            if(edges[currentINdex][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i]=true;
            }
            
        }
    }

}
void printDFS(int **edges, int n ,int sv, bool *visited){
    //sv is starting vertex;
    cout<<sv<<endl;
    visited[sv] = true;
    for(int i = 0; i < n ; i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }
            printDFS(edges,n,i,visited);
        }
    }
}

void BFS(int **edges, int n){
    bool *visited = new bool[n];
    for(int i = 0 ; i< n ;i++){
        visited[i]=false;
    }
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            printBFS(edges,n,i,visited);
        }
    }
    delete[]visited;

}
void DFS(int **edges, int n){
    bool *visited = new bool[n];
    for(int i = 0 ; i< n ;i++){
        visited[i]=false;
    }
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            printDFS(edges,n,i,visited);
        }
    }
    delete[]visited;
}
vector<int> getPath(int **edges,int n,int s,int e,bool *visited){
    //vector<int> path = new vector<int>(10);
    //vector<int> path;
    if(s == e){
        vector<int> childPath;
        childPath.push_back(s);
        //visited[s]= true;
        return childPath;
    }
    
    

    for(int i = 0; i<n;i++){
        if(i == s){
            continue;
        }
        /*
        if(i == e){
            path.push_back(i);
            visited[i]=true;
        }*/
        if(!visited[i] && edges[s][i] == 1){
            visited[i]=true;
            vector<int> childPath = getPath(edges,n,i,e,visited);
            if(childPath.size()!=0){
                childPath.push_back(i);
                return childPath;
            }
            //return childPath;
            /*
            for(int i = 0; i<childPath.size();i++){
                path.push_back(i);
                return path;
            }
            */
        }
    }
    vector<int> childPath;
    return childPath;


}
bool hasPathHelper(int **edges,int n,int s, int e,bool *visited){

    if(s == e){
        return true;
    }
    for(int i =0 ; i<n;i++){
        if(!visited[i] && i!=s && edges[s][i]==1){
            visited[i]=true;
            if(hasPathHelper(edges,n,i,e,visited)){
                return true;
            }
        }
    }
    return false;
}

bool hasPath(int **edges,int n,int s, int e){
    bool *visited = new bool[n];
    for(int i = 0 ; i< n ;i++){
        visited[i]=false;
    }
    return hasPathHelper(edges,n,s,e,visited);
    
}
int main(){
    //e is no of edges
    int n,e;
    cin>>n>>e;
    int **edges = new int*[n];

    //intitialize the 2d array as 0
    for(int i = 0; i<n ;i++){
        edges[i] = new int[n];
        for(int j = 0 ; j<n ; j++){
            edges[i][j] = 0;
        }
    }

    //path connect karna
    for(int i = 0; i<e; i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    
    cout<<"DFS"<<endl;
    DFS(edges,n);
    //cout<<"BFS"<<endl;
    //BFS(edges,n);
    cout<<"Has Path"<<endl;
    cout<<hasPath(edges,n,2,1)<<endl;

    cout<<"Get Path"<<endl;
    bool *visited = new bool[n];
    for(int i = 0 ; i< n ;i++){
        visited[i]=false;
    }
    vector<int> out = getPath(edges,n,1,4,visited);
    for(int i = 0; i< out.size();i++){
        cout<<out.at(i);
    }

    //delete
    for(int i = 0 ; i<n; i++){
        delete []edges[i];
    }
    delete []edges;


}