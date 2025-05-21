// graph.cpp
#include <vector>
#include <iostream>
#include <unordered_set>
#include <iomanip>
using namespace std;

struct NodeInfo{
   string name;
   NodeInfo(string s): name(s){}
};

class Graph{
    public:
        Graph(int size){
            // size is the number of vertices
            nodes.resize(size);
            for(auto &e: nodes){
                e = nullptr;
            }
            adjacencyList.resize(size);
        }
        void addEdge(int from, int to){
            adjacencyList[from].insert(to);
        }
        void display(){
            for(int i = 0 ; i < adjacencyList.size(); i++){
                cout << i << " : " ;
                for (auto e : adjacencyList[i]){
                    cout << e << " ";
                }
                cout << endl;
            }

        }
    private:
        vector<NodeInfo*> nodes;
        vector<unordered_set<int>> adjacencyList;
};
/*
Unweighted graph
Edge List E = {  (0, 2), 
                 (2, 3), (2, 1), (2, 4), 
                 (3, 1),  
                 (1, 5), (1, 4),
                 (4, 5)
                 }
*/

/*
Weighted graph
Edge List E = {  (0, 2, 0.5), 
                 (2, 3, 0.1), (2, 1, 0.7), (2, 4, 0.2), 
                 (3, 1, 0.3),  
                 (1, 5, 0.1), (1, 4, 0.9),
                 (4, 5, 0.3)
                 }
*/
int main(int argc, char const *argv[])
{
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 4);
    g.display();
    return 0;
}
