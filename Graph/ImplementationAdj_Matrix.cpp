#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Adjust this value based on your needs

void printGraph(int adjacencyMatrix[][MAX_SIZE], int row, int col)
{
    for(int i = 0; i < row + 1; i++){
        for(int j = 0; j < col + 1; j++){
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addEdge(int adjacencyMatrix[][MAX_SIZE], int u, int v)
{
    adjacencyMatrix[u][v] = 1;
}

int main()
{
    int row, col, edg;
    cout << "Enter the Row & col : " << endl;
    cin >> row >> col;

    int adjacencyMatrix[MAX_SIZE][MAX_SIZE];

    for(int i = 0; i < row + 1; i++){
        for(int j = 0; j < col + 1; j++){
            adjacencyMatrix[i][j] = 0;
        }
    }

    cout << "Enter No. of Edges" << endl;
    cin >> edg;
    while(edg--)
    {
        int u, v;
        cout << "enter U & V" << endl;
        cin >> u >> v;
        addEdge(adjacencyMatrix, u, v);
    }

    printGraph(adjacencyMatrix, row, col);
    return 0;
}
