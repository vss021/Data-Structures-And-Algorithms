/*
Topological sorting is a linear ordering of the vertices of a directed acyclic graph (DAG) 
such that for every directed edge uv from vertex u to vertex v, 
u comes before v in the ordering. 
In simpler terms, it's an ordering of the vertices such that all the directed edges go 
from left to right.

 key points about topological sorting:

 1. DAG (Directed Acyclic Graph): Topological sorting is only possible in 
    directed acyclic graphs because cyclic graphs have dependencies that cannot be 
    linearly ordered.

 2 -> Multiple Valid Orders: A DAG can have multiple valid topological orders. 
    This is because there can be multiple ways to order the vertices without 
    violating the dependencies.

 3-> Algorithmic Approaches:
    *-> Kahn's Algorithm: This algorithm uses the concept of in-degrees. 
    In-degrees represent the number of incoming edges to a vertex. 
    The algorithm repeatedly selects vertices with in-degrees of 0 and removes them, 
    updating the in-degrees of their neighbors.

    *-> Depth-First Search (DFS): This approach uses DFS to explore the graph. 
    The topological order is determined by the finishing times of the vertices in the DFS traversal. 
    The last finished vertex becomes the first in the topological order.
*/
/**
How does Kahn's Algorithm work?

   Kahn's Algorithm is a popular algorithm for topological sorting of directed acyclic graphs (DAGs). 
   The algorithm is based on the concept of in-degrees, which represents the number of 
   incoming edges to a vertex.

Here's how Kahn's Algorithm works:

Kahn's Algorithm (V: number of vertices, adj: adjacency list)
    1. Initialize inDegree array with zeros.
    2. Initialize an empty queue.
    3. Initialize an empty result vector for topological order.

    // Step 1: Calculate in-degrees
    
    for each vertex v
        for each neighbor w of v
            inDegree[w]++

    // Step 2: Enqueue vertices with in-degree 0
    for each vertex v
        if inDegree[v] == 0
            enqueue(v)

    // Step 3: Process the queue
    while queue is not empty
        u = dequeue()
        result.push_back(u)

        // Reduce in-degrees of neighbors
        for each neighbor v of u
            inDegree[v]--
            if inDegree[v] == 0
                enqueue(v)

    // Step 4: Check for cycles
    if result.size() != V
        // Graph contains a cycle

    return result


*/

/*
How does DFS Algorithm work?
   Depth-First Search (DFS) can also be used to perform topological sorting of a directed acyclic
    graph (DAG). The idea is to perform a depth-first traversal of the graph and, during the backtracking 
    phase, insert each visited vertex into a stack. The order in which the vertices are popped from the
     stack gives a valid topological order.

Here's a step-by-step explanation of how DFS works for topological sorting:


DFS for Topological Sort (u: current vertex, visited: set of visited vertices, stack: stack to store vertices)

    Mark u as visited.

    For each neighbor v of u:
        If v is not visited:
            Recursively call DFS(v, visited, stack)

    Push u onto the stack.

TopologicalSort (V: number of vertices, adj: adjacency list)

    Initialize a stack to store the result (topological order).
    Initialize a set to track visited vertices.

    For each vertex v:
        If v is not visited:
            Call DFS(v, visited, stack)

    Reverse the stack to get the topological order.

    Return the topological order.


*/