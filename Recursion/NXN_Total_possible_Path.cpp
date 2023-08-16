#include <iostream>
using namespace std;
/*
The problem is to count all the possible paths from top left to bottom right of a MxN matrix with the constraints 
that from each cell you can either move to right or down.

Example 1:

Input:
M = 3 and N = 3
Output: 6

Explanation:
Let the given input 3*3 matrix is filled 
as such:
A B C
D E F
G H I
The possible paths which exists to reach 
'I' from 'A' following above conditions 
are as follows:ABCFI, ABEHI, ADGHI, ADEFI, 
ADEHI, ABEFI
 

Example 2:

Input:
M = 2 and N = 8
Output: 8
*/

int PossibalePath(int m, int n, int i, int j){

    if(i == m-1 || j == n-1){
        return 1;
    }

    if(i>= m || j>= n){
        return 0;
    }

    return PossibalePath(m, n, i+1, j)+ PossibalePath(m, n, i, j+1);
    /*
    Time Complexity (TC):
The time complexity of the provided code can be quite high due to the recursive nature of the PossiblePath function.
 For each cell (i, j) in the grid, the function makes two recursive calls: PossiblePath(m, n, i + 1, j) and 
 PossiblePath(m, n, i, j + 1). The function explores a binary tree-like structure of recursive calls, 
 and the number of nodes in this tree grows exponentially with the number of rows (m) and columns (n).

 Therefore, the worst-case time complexity can be expressed as O(2^(m*n)),
     where m is the number of rows and n is the number of columns.

Space Complexity (SP):
The space complexity of the code is determined by the maximum depth of the recursive call stack.
 At each step of the recursion, new function calls are added to the stack. The maximum depth of the stack is bounded by the maximum of m and n. 
 Therefore, the space complexity is O(max(m, n)).
    */

}

int main(){

    cout<< "Enter the Nume " <<endl;
    int m,n; 
    cin>> m >> n;

    cout<< "Ans is : " << PossibalePath(m, n, 0, 0)<< endl;
    return 0;
}