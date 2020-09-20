#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{

private:

   vector<vector<int>> adjacency_list; // mandatory

public:

   Graph() {} //default constructor

   Graph(int); // one argument constructor

   int vertices; // Number of vertices

   void addEdge(int, int);
   vector<int> BFS();// Implement Breadth First Search algorithm, using an STL queue
                    // Using an STL queue is mandatory
   vector<int> BFS_Shortest_Distance(int);// Find Shortest Distance from src vertex
                                        // Using an STL queue is mandatory
   void print_graph(); //optional, for debugging
};

Graph::Graph(int vertices){

    this->vertices = vertices ; 

    adjacency_list.resize(vertices) ;

}

void Graph::addEdge(int v , int e){

    adjacency_list[v].push_back(e);

    adjacency_list[e].push_back(v) ;

}

vector<int> Graph::BFS(){

    bool *visited = new bool[vertices];

    for(int i = 0; i < vertices; i++)

        visited[i] = false;
    // Create a queue for BFS
        queue<int> queue;
        visited[0] = true;
        queue.push(0);
    int s = 0 ;
    vector<int>::iterator i; 
    vector<int> result ;

    while(!queue.empty())

    {

       s = queue.front();
   
        result.push_back(s) ;

        queue.pop();

        for (i = adjacency_list[s].begin(); i != adjacency_list[s].end(); ++i)

        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push(*i);
            }
        }
        }
  return(result) ;

}

vector<int> Graph::BFS_Shortest_Distance(int source) {

    vector<int> r ;

    int dest = 0 ;

    for(dest=0 ; dest < vertices ; dest++ ){

    int distance[vertices] , parent[vertices] ;

    bool *visited = new bool[vertices];

    for(int i = 0; i < vertices; i++) {

        visited[i] = false;

        distance[i] = vertices ;

        parent[i] = -1;

    }

    queue<int> queue;

    visited[source] = true;

    distance[source] = 0 ;

    queue.push(source);

    int s = 0 ;

    vector<int>::iterator i; 

    vector<int> result ;

    while(!queue.empty())

    {

        s = queue.front();

        result.push_back(s) ;

        queue.pop();
        for (i = adjacency_list[s].begin(); i != adjacency_list[s].end(); ++i)

        {

            if (!visited[*i])

            {

                visited[*i] = true;

                distance[*i] = distance[s]+1 ;

                parent[*i] = s ;

                queue.push(*i);

            }

        }

    }

    r.push_back(distance[dest]);

    }

return(r) ;

}

void Graph::print_graph(){

    for(int i =0 ; i<vertices ; i++){

        cout << "\n adjacency list of vertex " << i << "is" ;

        vector<int> :: iterator j ;

        for (auto z : adjacency_list[vertices])

           cout << "-> " << z;

        printf("\n");

        cout << "\n" ;

    }

  

}

