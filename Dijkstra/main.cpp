//
//  main.cpp
//  Dijkstra
//
//  Created by Patryk Piwowarczyk on 08/06/2022.
//
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
int iter2;
int iteration = 0;
struct Params{

    string inputFile;
    string outputFile;
};
// Structure storing a graph edge
struct Edge {
    int source, dest, weight;
};
 
// Structure storing a heap node
struct Node {
    int vertex, weight;
};
struct Instance{
    vector<Edge> Edges;
    string instanceName;
    int n;
};
// A class representing a graph object
class Graph
{
public:
    // this is a vector of vectors of `Edge` representing an adjacency list (map with weights)
    vector<vector<Edge>> adjList;
 
    //  Constructor of graph
    Graph(vector<Edge> const &edges, int n)
    {
        // resizing the vector to hold `n` elements of type vector<Edge>
        adjList.resize(n);
 
        // adding edges to the directed graph
        for (Edge const &edge: edges)
        {
            // inserting it at the end
            adjList[edge.source].push_back(edge);
        }
    }
};
 
void printPath(vector<int> const &prev, int i, int source)
{
    
    if (i < 0) {
        return;
    }
    printPath(prev, prev[i], source);
    if (i != source) {
        
        cout << ", ";
    }
    cout << i;
}
 
// Comparison object to compare the results to the best one
struct comp
{
    bool operator()(const Node &lhs, const Node &rhs) const {
        return lhs.weight > rhs.weight;
    }
};
 
//Dijkstra calculating function
void findShortestPaths(Graph const &graph, int source, int n)
{
    //int iteration = 0;
    
    // create a min-heap and push source node having distance 0
    priority_queue<Node, vector<Node>, comp> min_heap;
    min_heap.push({source, 0});
 
    // setting the initial distance from the source to `v` as infinity (placeholder before the distances are calculated)
    vector<int> dist(n, INT_MAX);
 
    // setting the distance from the source to itself to zero
    dist[source] = 0;
 
    // boolean array for tracking vertices for which minimum cost has already been found
   
    vector<bool> done(n, false);
    done[source] = true;
 
    // storing the predecessor of a vertex (to a print path)
    vector<int> prev(n, -1);
 
    // running until min-heap is empty (so as long as there aren't more paths to check)
    while (!min_heap.empty())
    {
        //iteration++;
        // Removing and returning the best vertex
        Node node = min_heap.top();
        min_heap.pop();
 
        // getting the vertex number
        int u = node.vertex;
 
        // doing it for each neighbor `v` of `u`
        for (auto i: graph.adjList[u])
        {
            iteration++;
            int v = i.dest;
            int weight = i.weight;
 
            // Relaxation step (updating the cost of all vertices connected to a vertex v if those could would be improved.
            if (!done[v] && (dist[u] + weight) < dist[v])
            {
               
                dist[v] = dist[u] + weight;
                prev[v] = u;
                min_heap.push({v, dist[v]});
            }
        }
        
        // marking the vertex `u` as done so it will be excluded from getting picked up again
        done[u] = true;
    }
    
    for (int i = 0; i < n; i++)
    {
       // cout<<"writing in file" << endl;
        
        if (i != source && dist[i] != INT_MAX)
        {
            iter2++;
            cout << "Src -> Dest: (" << source << " —> " << i << "): Min Length = "
                 << dist[i] << ", Path = [";
            printPath(prev, i, source);
            cout << "]" << endl << "Path Number: " << iter2 << endl;
        }
    }
    cout << "Current iteration number: "<< iteration << endl;
}


void readInstance(string filename, Instance &instance){
    instance.instanceName = filename;
    ifstream file(filename);
    
    if (file.is_open()) {
        string line;
        int i = 0;
        
        while (getline(file, line)) {
            if(i == 0){
                instance.n = stoi(line);
            }
            else{
                istringstream ss(line);
                string aux1, aux2, aux3;
                ss >> aux1;
                ss >> aux2;
                ss >> aux3;
                Edge p;
                p.source = stod(aux1);
                p.dest = stod(aux2);
                p.weight = stod(aux3);
                instance.Edges.push_back(p);
            }
            
            i++;
        }
        
        file.close();
    }
    else {
        cout << "Error opening instance file" << endl;
        exit(1);
    }
}
void readParams(Params &params, int one, char two)
{
   
    params.inputFile = "/Users/patrykpiwowarczyk/Downloads/Lab7/g100.txt";
    
    freopen("/Users/patrykpiwowarczyk/Downloads/Lab7/outputFile.txt","w",stdout);
     
    // Check
    if(params.inputFile == "" ){
        cerr << "Input file needs to be specified" << endl;
        exit(1);
    }
}
int main()
{
    int one;
    char two;
    one = 150;
    two = 120;
    
    cout<<"writing in file" << endl;
    
    Params params;
    readParams(params, one, two);

    Instance instance;
    readInstance(params.inputFile, instance);

    //insert the number of nodes
    int n = 150;
 
    // constructing the graph
    Graph graph(instance.Edges, n);
 
    // running the Dijkstra’s algorithm for every node
    for (int source = 0; source < n; source++) {
        findShortestPaths(graph, source, n);
    }
 
    return 0;
}
