#include <iostream>
#include <vector>
using namespace std;

// Method 1.

void permutation(string str, vector<string>& ans) {
    // Base case: If the input string is empty, print the current permutation
    if (str.length() == 0) {
        // Print each element of the current permutation
        for (const string& s : ans) {
        }
        cout << endl;
        return;
    }

    // Iterate through each character in the input string
    for (int i = 0; i < str.length(); i++) {
        // Extract the current character
        char ch = str[i];

        // Create a new string without the current character
        string ros = str.substr(0, i) + str.substr(i + 1);

        // Create a copy of the current permutation vector and add the current character
        vector<string> newAns = ans;
        newAns.push_back(string(1, ch));

        // Recursively call the permutation function with the updated string and permutation
        permutation(ros, newAns);
    }
}


void Permutation(int index, string str, vector<string>&ans)
{

    if(index >= str.length()){
        ans.push_back(str);
        return ;
    }

    for(int i = index; i<str.size(); i++){
        swap(str[i], str[index]);
        Permutation(index+1, str, ans);
        swap(str[i], str[index]);
    }

}
int main(){

    cout<< "Enter the String "<< endl;
    string str;
    cin>> str;
    vector<string> ans;

    permutation(str, ans);
    // Permutation(0, str, ans);

    cout << " Permutation : " << endl;
    for(auto X : ans)
    {
        cout << X << " ";
    }


}