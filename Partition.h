#ifndef PARTITION_H_
#define PARTITION_H_

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
using namespace std;

class Partition {

protected:

	int *array;
	int n;

public:

	Partition(int *array, int n) {
		this->array = array;
		this->n = n;
	}

protected:

	void swap(int x, int y) {
		int temp = array[x];
		array[x] = array[y];
		array[y] = temp;
	}

	int generateRandomPivot(int left, int right) {
		int pivotIndex = left + rand() % (right - left + 1);
		return array[pivotIndex];
	}

	int generateMedianOf3Pivot(int left, int right) {
		int mid = (left + right) / 2;

		if (array[left] > array[mid])
			swap(left, mid);

		if (array[left] > array[right])
			swap(left, right);

		if (array[mid] > array[right])
			swap(mid, right);

		return array[mid];
	}

public:

	int partition(int left, int right, int pivot) { // complete this function
        int pivotIndex = left, partitionIndex = (left-1);
        for(int k = left; k <= right; k++)
            {
                if(array[k] == pivot)
                    {
                      pivotIndex = k;
                    }

                if(array[k] <= pivot)
                    {
                      partitionIndex++;
                    }
            }
        
        swap(pivotIndex, partitionIndex);
        int i = left, j = right;

        while(i < j)
            {
            //increment i as long as (i≤partitionIndex&&A[i]≤pivot);
                if(i <= partitionIndex && array[i] <= pivot)
                    {
                        i++; 
                    }

            //decrement j as long as (j > partitionIndex&&A[j]> pivot);
            //Loop
                else if(j > partitionIndex && array[j] > pivot)
                    {
                        j--; 
                    }
            
            //Another Loop
                else if(i < j)
                    {
                        swap(i, j);
                        i++;
                        j--;
                    }
            }
        return partitionIndex;
	}
};

#endif /* PARTITION_H_ */
