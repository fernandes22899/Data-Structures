#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

void printGraph(map<char, list<char> > &graph)
{
    map<char, list<char> >::iterator graph_it;
    list<char>::iterator it;

    for (graph_it = graph.begin();
         graph_it != graph.end(); graph_it++)
    {
        cout << (*graph_it).first << ": ";
        for (it = (*graph_it).second.begin();
             it != (*graph_it).second.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}

int main() {

    // build the graph
    map<char, list<char> > graph;
    char v1, v2, start, end;


    //Process graph input
    while((cin >> v1) && v1 != '?')
    {
        if (!(cin >> v2))
            break;
        //REPLACE WITH CODE TO STORE EDGE IN GRAPH
        graph[v1].push_back(v2);


    }


    // display stored graph if compiled with -DEBUG_PRINT
#ifdef DEBUG_PRINT
    printGraph(graph);
#endif

    map<char, bool> visited;
    map<char, char> parent;
    queue<char> list;
    //Process queries
    while (cin >> start >> end)
    {
        //REPLACE WITH CODE TO STORE OR PROCESS QUERIES
        cin >> v1; //grab the next '?'
        if (v1 != '?')
        {
          parent[v1] = v2;
        }
        else if( v1 == '?' )
        {
          list.pop();

          visited[start] = true;
          list.push(start);

          while( ( !list.empty() ) && ( list.front() != end ) )
          {
            list.pop();
            if( visited[v2] != true )
              visited[v2] = true;
          }
          if( list.front() == end ){
            cout << "from " << v1 << " to " << v2 << " : path found." << endl;
            return true;
          }
          else{
            cout << "from " << v1 << " to " << v2 << " : path not found." << endl;
            return false;
          }
        }


    }
}
