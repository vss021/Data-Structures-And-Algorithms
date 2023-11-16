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

