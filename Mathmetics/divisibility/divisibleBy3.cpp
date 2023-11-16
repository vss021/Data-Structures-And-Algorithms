#include <iostream>
using namespace std;

void method1(int num)
{
    int sum = 0;

    while(num)
    {
        sum += num/10;
        num /= 10;
    }

    if(sum%3 == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

void method2(int num)
{
    if(num%3 == 0)
    {
        cout << "Yes" << endl;
    }else{
        cout << "No "<< endl;
    }
}

int main()
{
    int num;
    cout << "Enter the Num : " << endl;
    cin >> num;

    // method 1.
    /**
    if Sum of Nums all digites are divided by 3 then num also divided by 3
    */
    method1(num);


    return 0;
}