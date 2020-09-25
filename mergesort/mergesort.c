#include "mergesort.h"
#include <stdlib.h>

bool needsSorting(int rangeSize) {
	if (rangeSize >= 2) {
		return true;
        } else {
                return false;
        }
}

void mergeRanges(int toSort[], int startIndex, int midPoint, int endIndex) {
	int rangeSize = endIndex - startIndex;
	int *destination = (int*) calloc(rangeSize+ + 1, sizeof(int));
	int firstIndex = startIndex;
	int secondIndex = midPoint;
	int copyIndex = 0;
	while (firstIndex < midPoint && secondIndex < endIndex) {
		if (toSort[firstIndex] < toSort[secondIndex]) {
			destination[copyIndex] = toSort[firstIndex];
			firstIndex++;
		} else {
			destination[copyIndex] = toSort[secondIndex];
			secondIndex++;
		}
		copyIndex++;
	}
	while (firstIndex < midPoint) {
		destination[copyIndex] = toSort[firstIndex];
		copyIndex++;
		firstIndex++;
	}
	while (secondIndex < endIndex) {
		destination[copyIndex] = toSort[secondIndex];
		copyIndex++;
		firstIndex++;
	}
	for (int i = 0; i < rangeSize; i++) {
		toSort[i + startIndex] = destination[i];
	}
	free(destination);
}

void mergeSortRange(int toSort[], int startIndex, int endIndex) {
	int rangeSize = endIndex - startIndex;
        if (needsSorting(rangeSize)) {
		int midPoint = (startIndex + endIndex) / 2;
                mergeSortRange(toSort, startIndex, midPoint);
                mergeSortRange(toSort, midPoint, endIndex);
                mergeRanges(toSort, startIndex, midPoint, endIndex);
        }
}

void mergesort(int size, int toSort[]) {
	  mergeSortRange(toSort, 0, size);
}
