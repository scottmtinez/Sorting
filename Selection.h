#ifndef SELECTION_H_
#define SELECTION_H_

#include "Partition.h"

class Selection: public Partition {

public:

	Selection(int *array, int n) :
			Partition(array, n) {
	}

	int select(int k) {
		return select(0, n - 1, k);
	}

private:

	int select(int left, int right, int k) { // complete this function
    if(left == right)
      {
        return array[left];
      }
    
    int pivot = generateRandomPivot(left, right);
    int partitionIndex = partition(left, right, pivot);

    if(k == partitionIndex-left+1)
      {
        return pivot;
      }
    else if(k < partitionIndex-left+1)
      {
        return select(left, partitionIndex-1, k);
      }
    else
      {
        return select(partitionIndex+1, right, k-(partitionIndex-left+1));
      }
    }
};
	


#endif /* SELECTION_H_ */


