#ifndef INVERSIONCOUNTING_H_
#define INVERSIONCOUNTING_H_
#include <iostream>
using namespace std;
class InversionCounting {

	int *array;
	int *mergedArray;
	int n;

public:

	InversionCounting(int *array, int n) {
		this->array = array;
		this->n = n;
		mergedArray = new int[n];
	}

	~InversionCounting() {
		delete[] mergedArray;
	}

	int countInversions() {
		mergedArray = new int[n];
		return countInversions(0, n - 1);
	}

	int bruteForce() {
		int count = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (array[i] > array[j])
					count++;
		return count;
	}

private:

	int countInversions(int left, int right) { // complete this function
  bruteForce();
    if(left < right)
      {
        //Adjusted Mergesort
        
          int mid = (left + right)/2;
          int countL = countInversions(left, mid);
          int countR = countInversions(mid+1, right);

          //mergedArray = ;

          int i = left;
          int j = 0;

          while(j <= right-left)
            {
              array[i++] = array[j++];
            }
          delete[] array;

        //int countCross = countInversions(left, right+countCross);
        return countL + countR;
      }
    
	}

};
#endif /* INVERSIONCOUNTING_H_ */
