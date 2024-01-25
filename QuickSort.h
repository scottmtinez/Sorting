#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "Partition.h"

class QuickSort: public Partition {

public:

	QuickSort(int *array, int n) :
			Partition(array, n) {
	}

	void quicksortMedianOf3() {
		quicksortMedianOf3(0, n - 1);
	}

	void quicksortRandom() {
		quicksortRandom(0, n - 1);
	}

private:

	void quicksortMedianOf3(int left, int right) { // complete this function
        if(left < right)
          {
            int pivot = generateMedianOf3Pivot(left, right);
            int partitionIndex = partition(left, right, pivot);
            quicksortMedianOf3(left, partitionIndex-1);
            quicksortMedianOf3(partitionIndex+1, right);
          }
	}

	void quicksortRandom(int left, int right) { // complete this function
      if(left < right)
        {
          int pivot = generateRandomPivot(left, right);
          int partitionIndex = partition(left, right, pivot);
          quicksortRandom(left, partitionIndex-1);
          quicksortRandom(partitionIndex+1, right);
        }    
    }
};

#endif /* QUICKSORT_H_ */
