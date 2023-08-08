
#include <iostream>
#include <vector>
using namespace std;

/*
* Time Colmplex => 9^M 
* m => means number of blank space
* 
* Space complexcity => O(1) => because in worst complexcity it will be 9*9 

*/
bool isSafe(int row, int col, vector<vector<int>>& board, int value, int n)
{
    for(int i=0; i<n; i++)
    {
        // row check
        if(board[row][i] == value)
            return false;
        
        if(board[i][col] == value)
            return false;
        
        // 3X3 matrix

        if(board[3*(row/3) + i/3][3*(col/3)+i%3] == value)
            return false;
    }
    return true;
}
bool solve(vector<vector<int>>& board)
{
    int n = board.size();

    for(int row = 0; row<n; row++)
    {
        for(int col = 0; col< n; col++)
        {

            // cell empty 

            if(board[row][col] == 0)
            {
                // adding 1 to 9 element's
                for(int val = 1; val<=9; val++)
                {

                    if(isSafe(row, col, board, val, n)){
                        board[row][col] = val;
                        bool nextNum = solve(board);
 
                        if(nextNum)
                            return true;
                        else
                            board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> & board)
{
    solve(board);
}

int main()
{
    vector<vector <int> > board= 
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
        
    cout << "Enter SudoKu is this : " << endl;

    for(int row = 0; row < board.size(); row++)
    {
        for(int col = 0; col<board.size(); col++)
        {
            cout<< board[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;

    solveSudoku(board);

    cout << "Result is this : " << endl;
    
    for(int row = 0; row < board.size(); row++)
    {
        for(int col = 0; col<board.size(); col++)
        {
            cout<< board[row][col] << " ";
        }
        cout << endl;
    }


    return 0;
}