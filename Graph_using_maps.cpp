#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class Graph{
    unordered_map<int,list<int>> adjList;
    public:
        void addEdge(int,int,bool);
        vector<vector<int>> AdjMatrix();
        void printAdjList();
        // vector<int> getAdjNode(int);
        void BFS();

};

void Graph :: addEdge(int u,int v,bool direction){
    // If direction = 0 --> undirected graph
    // If direction = 1 --> directed graph
    adjList[u].push_back(v); // This means node u is connect to node v
    if(direction==0){
        // It means it is undirected , if u is connected to v then v is also connected to u
        adjList[v].push_back(u);
    }

}
// vector<vector<int>> Graph :: AdjMatrix(){

// }
// vector<int> Graph :: getAdjNode(int node){




// }

void Graph :: printAdjList(){
    // AdjList is array of linked list
    cout << "\nAdjancency List representation : \n\n";
   
    for(auto i:adjList){
        cout << i.first << " -> ";
        for(auto j:i.second){
            cout << j << " ," ;
        }
        cout << endl;
    }
}
int main(){

    Graph g;
    int N;
    cout << "Enter number of nodes : " ;
    cin >> N ;

    int M ;
    cout << "Enter number of edges : " ;
    cin >> M ;

    for(int i=0;i<M;i++){
        int u,v;
        cout << "Enter edge - " << i+1 << " corresponding nodes : " ;
        cin >> u >> v ;
        g.addEdge(u,v,0);
    }

    g.printAdjList();

    return 0;
}
