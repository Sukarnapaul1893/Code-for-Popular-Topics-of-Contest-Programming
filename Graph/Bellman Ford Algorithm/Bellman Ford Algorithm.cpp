#include<bits/stdc++.h>

using namespace std;

int bellmanFord(
                    vector< list< pair<int, int> > > adjacencyList,
                    int vertices,
                    int startVertex,
                    vector< pair<int, int> > & shortestDistances
               )
{
    list< pair<int, int> >::iterator traverse;
    int i, j, k;

    // Initialisation
    for (i = 0; i <= vertices; ++i) {
        shortestDistances[i].first = INT_MAX;
        shortestDistances[i].second = -1;
    }

    // Setting distance to source = 0
    shortestDistances[startVertex].first = 0;
    shortestDistances[startVertex].second = 0;

    // The Algorithm that computes Shortest Distances
    for (i = 1; i <= vertices - 1; ++i) {    // Runs 'vertices - 1' times = O(|V|)
        for (j = 1; j <= vertices; ++j) {    // Runs as many times as the edges = O(|E|)
            // The code ahead basically explores the whole of Adjcency List,
            // covering one edge once, so the runtime of the code in this
            // block is O(|E|)

            traverse = adjacencyList[j].begin();

            while (traverse != adjacencyList[j].end()) {
                if (shortestDistances[j].first == INT_MAX) {
                    // Important...!
                    //traverse = traverse->next;
                    ++traverse;
                    continue;
                }

                // Checking for Relaxation
                if ((*traverse).second + shortestDistances[j].first <
                                        shortestDistances[(*traverse).first].first) {
                    // Relaxation
                    shortestDistances[(*traverse).first].first = (*traverse).second
                                        + shortestDistances[j].first;
                    shortestDistances[(*traverse).first].second = j;
                }

                ++traverse;
            }
        }
    }

    // Checking for Negative Cycles
    for (j = 1; j <= vertices; ++j) {
        traverse = adjacencyList[j].begin();

        while (traverse != adjacencyList[j].end()) {
            // Checking for further relaxation
            if ((*traverse).second + shortestDistances[j].first <
                                        shortestDistances[(*traverse).first].first) {
                // Negative Cycle found as further relaxation is possible
                return j;
            }

            ++traverse;
        }
    }

    return -1;
}

int main()
{
    int vertices, edges, v1, v2, weight;

    printf("Enter the Number of Vertices -\n");
    scanf("%d", &vertices);

    printf("Enter the Number of Edges -\n");
    scanf("%d", &edges);

    // Adjacency List is a vector of list.
    // Where each element is a pair<int, int>
    // pair.first -> the edge's destination
    // pair.second -> edge's weight
    vector< list< pair<int, int> > > adjacencyList(vertices + 1);

    printf("Enter the Edges V1 -> V2, of weight W\n");

    for (int i = 1; i <= edges; ++i) {
        scanf("%d%d%d", &v1, &v2, &weight);

        // Adding Edge to the Directed Graph
        adjacencyList[v1].push_back(make_pair(v2, weight));
        //adjacencyList[v2].push_back(make_pair(v1, weight)); //For undirected graph
    }

    vector< pair<int, int> > shortestDistances(vertices + 1);
    // shortestDistances is a vector of pairs
    // pair.first -> the shortest distance from start vertex
    // pair.second -> parent vertex in the shortest path

    int startVertex;

    printf("\nEnter a Start Vertex -\n");
    scanf("%d", &startVertex);

    int returnValue = bellmanFord(adjacencyList, vertices, startVertex, shortestDistances);

    if (returnValue == -1) {
        printf("No Negative Cycles exist in the Graph -\n");
    }
    else {
        printf("Negative Cycles exists in the Graph -\n");
    }
}
