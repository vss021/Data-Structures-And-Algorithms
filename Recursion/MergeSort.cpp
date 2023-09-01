#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)

    {

         // Your code here

         int n1 = m-l+1 , n2 = r-m;

         int a[n1] , b[n2];

         for(int i=0;i<n1;i++) a[i] = arr[i+l];

         for(int i=0;i<n2;i++) b[i] = arr[m+1+i];

         

         int p=0,q=0,h=l;

         while(p<n1 and q<n2)

         {

               if(a[p] < b[q]) arr[h++] = a[p++];

               else arr[h++] = b[q++];

         }

         while(p<n1) arr[h++] = a[p++];

         while(q<n2) arr[h++] = b[q++];

    }


    void mergeSort(int arr[], int l, int r)

    {

        //code here

        if(l<r)

        {

              int m = (l+r)/2;
            // left
              mergeSort(arr,l,m);
            // right
              mergeSort(arr,m+1,r);
            // merge
              merge(arr,l,m,r);

        }

    }
    int main(){

    int arr[5] = {2, 5, 4, 6, 9};
    int n = 5;

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<< arr[i]<< " ";
    }
    return 0;
    
} // namespace std;
