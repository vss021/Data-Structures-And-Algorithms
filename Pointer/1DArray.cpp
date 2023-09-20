#include <iostream>
using namespace std;

int getSum (int *arr, int n){
   int sum = 0;
   for(int i=0; i<n; i++)
   {
      sum += arr[i];
   }

   return sum;
}
int main(){
/*
    int arr[5] = {1, 2, 4, 8, 100};

    cout<<"arr print : "<< arr << endl; // base index of array (starting index of the array)
    cout<<"&arr print : "<< &arr << endl; // same first index
    cout<< "&arr[0] : " << &arr[0]<< endl; // first index
    cout<< "*arr : "<< *arr << endl;
    cout<< "*(arr+1) : "<< *(arr+1) << endl;


    cout<< "size of arr :" << sizeof(arr)<<endl;
    cout<< "size of *arr :" << sizeof(*arr)<<endl;
    
   int arr[10] = {1, 2, 8, 5};
   int *ptr = &arr[0];
   cout<<ptr<<endl;
   ptr = ptr+1; // next element of array
 
   cout<<*ptr<<endl;
   */

//   Char Array
   /*
   char ch[6] = "vijay";
    cout<<ch<< endl;
    char *p = &ch;
    cout<< *p << endl;
   
  float f = 10.5;
  float p = 2.5;
  float *t = &f;
  (*t)++;
  *t = p;
  cout<< *t << f << p<< endl;
  

 char c = 'v';
 cout<< sizeof(c) << endl;

 char* ptr = &c;
 cout<< sizeof(ptr)<< endl;
 */


// int *arr = new int[]

int n;
cin>>n;
// creation 1-D Array 

int *arr = new int[n];
// size is = 8+ n*4;


for(int i=0; i<n; i++)
{
   cin>> arr[i];
}
int ans = getSum(arr, n);
cout<< " answer : "<< ans << endl;
// if we use the heap memory then we need to free that memory 
//  manvelly 
// 1-D array 
delete []arr;

}