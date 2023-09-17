// Compile this assignment with: gcc -Wall main.c -o main
// Use this file to create several grpahs and show that your implementation
// of Kruskal's minimum spanning tree algorithm works!
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
#include "my_graph.h"
#include "my_mst.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

int main(int argc, const char * argv[]) {
    graph_t * graph = create_graph();
    graph_add_node(graph, 1);
    graph_add_node(graph, 2);

    calculate_mst(graph);
    return 0;
}
