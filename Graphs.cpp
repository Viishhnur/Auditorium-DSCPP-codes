#include <iostream>
#include <list>
#include<queue>
#include<stack>
#include <vector>
using namespace std;

class Graph {
    vector<list<int>> adjList;
    int size;

    public:
        Graph(int nodes){
            // Created a vector of size n 
            adjList.resize(nodes);
            size = nodes;

        } 
        void addEdge(int,int);
        void printAdjList();
        void printAdjNodes(int);
        vector<int> getAdjNodes(int);
        void printBFS();
        void printDFS();
        void recBFS(int);
        
};


void Graph::addEdge(int n1, int n2) {

    adjList[n1].push_back(n2);
    adjList[n2].push_back(n1);
}
void Graph :: printDFS(){
    // Initialise all false array
    cout << "Depth First Search (DFS) : ";
    bool visited[size] = {false};
    stack<int> st;
    st.push(0);
    while(!st.empty()){
        int Front = st.top();
        cout << Front << " " ;
        visited[Front] = true;
        st.pop();

        vector<int> adjNodes = getAdjNodes(Front);
        int adjNodesSize = adjNodes.size();
        for(int i=0;i<adjNodesSize;i++){
            if(visited[adjNodes[i]]!=true){
                // We did not visit them 
                // So push into queue
                st.push(adjNodes[i]);
            }
        }

        

    }

    cout << endl;

}



void Graph :: printBFS(){

    // Initialise all false array
    cout << "Breadth First Search (BFS) : ";
    bool visited[size] = {false};
    queue<int> qu;
    qu.push(0);
    while(!qu.empty()){
        int Front = qu.front();
        cout << Front << " " ;
        visited[Front] = true;
        qu.pop();

        vector<int> adjNodes = getAdjNodes(Front);
        int adjNodesSize = adjNodes.size();
        for(int i=0;i<adjNodesSize;i++){
            if(visited[adjNodes[i]]!=true){
                // We did not visit them 
                // So push into queue
                qu.push(adjNodes[i]);
            }
        }

        

    }

    cout << endl;

}
void Graph::printAdjList() {
    cout << "\nAdjacency List representation using vector of list : \n\n";
    cout << "Nodes      AdjNodes\n";
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << "           -> ";
        for (int node : adjList[i]) {
            cout << node << ", ";
        }
        cout << endl;
    }
    cout << endl;
}
vector<int> Graph :: getAdjNodes(int node){
    // Get the list at the given node
    vector<int> adjNodes;
    list<int> lst = adjList[node];
    for(int n : lst){
        adjNodes.push_back(n);
    }
    
    return adjNodes;
}
void Graph :: printAdjNodes(int node){
    // Get the list at the given node
    list<int> lst = adjList[node];
    cout << "Adjacent Nodes of " << node << " are : " ;
    for(int n : lst){
        cout << n << " " ;
    }cout << endl;
}

int main() {
    int N;
    cout << "Enter number of nodes: ";
    cin >> N;

    Graph g(N);

    int M;
    cout << "Enter number of edges: ";
    cin >> M;

    for (int i = 1; i <= M; i++) {
        int u, v;
        cout << "Enter connection " << i << " : ";
        cin >> u >> v;
        g.addEdge(u, v);
    }

    // g.printAdjList();

    // int node;
    // cout << "Enter any node : " ;
    // cin >> node;
    // g.printAdjNodes(node);
    g.printBFS();
    cout << endl;

    g.printDFS();
    cout << endl;

    return 0;
}
