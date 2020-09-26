#include "array_merge.h"
#include <stdlib.h>
#include "../mergesort/mergesort.h"
#include "../mergesort/mergesort.c"

bool isIn(int value, int* array) {
	for (int i = 1; i < (array[0] + 1); i++) {
		if (array[i] == value) {
			return true;
		}
	}
	return false;
}

int* getUniques(int maSize, int* messyArray) {
	int caSize = 0;
	int caIndex = 1;

	int* cleanArray = (int*) malloc((maSize + 1) * sizeof(int));
	cleanArray[0] = caSize;

	for (int maIndex = 1; maIndex < maSize; maIndex++) {
		if (!isIn(messyArray[maIndex], cleanArray)) {
			cleanArray[caIndex] = messyArray[maIndex];
			caSize++;
			cleanArray[0] = caSize;
			caIndex++;
		}
	}
	
	return cleanArray;
}
	
int* array_merge(int num_arrays, int* sizes, int** values) {
	int totalSize = 0;

	for (int i = 0; i < num_arrays; i++) {
		totalSize = totalSize + sizes[i];
	}

	// messyArray is to be a temporary array that contains all values
	int* messyArray = (int*) malloc(totalSize * sizeof(int));

	int maIndex = 0;
	for (int sIndex = 0; sIndex < num_arrays; sIndex++) {
		for (int vIndex = 0; vIndex < sizes[sIndex]; vIndex++) {
			messyArray[maIndex] = values[sIndex][vIndex];
			maIndex++;
		}
	}

	mergesort(totalSize, messyArray);

	int* cleanArray = getUniques(totalSize, messyArray);
	free(messyArray);

      	return cleanArray;
}
