#include <iostream>
using namespace std;

bool Palindrome(string& str, int i, int j)
{
    if(i>j)
        return true;
    
    if(str[i] !=str[j])
        return false;
    else
        return Palindrome(str, i+1, j-1);
}

void reverse(string& str, int i, int j)
{
    if(i>j)
        return ;
    
    swap(str[i], str[j]);
    i++;
    j--;

    return reverse(str,i, j);
}
int main(){

    cout<< "Enter the string : ";
    string name; 
    cin>> name;
    cout<<name << endl;
    reverse(name, 0, name.length()-1);
    cout<< name<< endl;

    if(Palindrome(name, 0, name.length()-1)){
        cout<< "is Palindrome "<< endl;
    }else{
        cout<< "Not palindrome" << endl;
    }
return 0;

    
} // namespace std;
