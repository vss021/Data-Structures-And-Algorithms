#include <iostream>
#include <vector>

using namespace std;

void generateParentheses(vector<string>&ans, string option, int open, int close, int n)
{

    // base case
    if(option.size() == 2*n)
    {
        ans.push_back(option);
        return ;
    }

    // first step add ( in option and open++

    if(open< n){
        generateParentheses(ans, option+'(', open+1, close, n);
    }
    if(close< open){
        generateParentheses(ans, option+')', open, close+1, n);
    }
}

int main()
{

    int n;
    cout << "Enter the Numser : " << endl;
    cin >> n;

    vector < string>  ans;

    string option = "";



    generateParentheses(ans, option, 0, 0, n);

    cout << "Ans is : "<< endl;

    for(auto x : ans)
    {
        for(auto i : x){
            cout << i<< " ";
        }
        cout << endl;
    }

    return 0;
}