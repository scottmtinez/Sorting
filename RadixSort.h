#ifndef RADIXSORT_H_
#define RADIXSORT_H_

#include <iostream>
using namespace std;

class RadixSort {
private:
	int *array;
	int n;

public:

	RadixSort(int *array, int length) {
		this->array = array;
		n = length;
	}

private:

	void countSortOnDigits(int A[], int n, int digits[]) { // complete this function
        int C[10] = {0};
        int T[n];

        for(int i = 0; i <= n-1; i++)
          {
            C[digits[i]]++;
          }

        for(int i = 1; i <= 9; i++)
          {
            C[i] = C[i-1] + C[i];
          }
       
        for(int i = n-1; i <= 0; i++)
          {
            C[digits[i]]--;
            T[C[digits[i]]] = array[i];
          }

      //Use a loop to copy T into A;
        for(int i = 0; i < 10; i++)
          {
            A[i] = T[n];
          }
    }

	void radixSortNonNeg(int A[], int n) { // complete this function
    int M = A[0]; //Max value in array
    for(int i = 1; i < n; i++)
      {
        if(A[i] > M)
          {
            M = A[i]; 
          }
      }

    int digits[n];
    int e = 1;

    while(M/e > 0)
      {
        for(int i = 0; i <= n-1; i++)
          {
            digits[i] = (A[i]/e)%10;
          }
        
        countSortOnDigits(A, n, digits);
        e = e*10;
      }
	}

public:

	void radixSort() { // complete this function
    //Approach #1
    //We first find the minimum number in the array. 
    /*
      int C[10] = {0};
        int T[n];

        for(int i = 0; i <= n-1; i++)
          {
            C[digits[i]]++;
          }

        for(int i = 1; i <= 9; i++)
          {
            C[i] = C[i-1] + C[i];
          }
       
        for(int i = n-1; i <= 0; i++)
          {
            C[digits[i]]--;
            T[C[digits[i]]] = array[i];
          }

      //Use a loop to copy T into A;
        for(int i = 0; i < 10; i++)
          {
            A[i] = T[n];
          }
*/
    }
};

#endif /* RADIXSORT_H_ */
