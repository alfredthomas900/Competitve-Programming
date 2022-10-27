// Quick Sort Algorithm
// Pivot

// Approach

// Partition Algorithm:

// There can be many ways to do partition,
// following pseudo-code adopts the method given in the CLRS book.
// The logic is simple, we start from the leftmost element and
// keep track of the index of smaller (or equal to) elements as i.
// While traversing, if we find a smaller element,
// we swap the current element with arr[i].
// Otherwise, we ignore the current element.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	// The main function that implements QuickSort
	// arr[] --> Array to be sorted,
	// low --> Starting index,
	// high --> Ending index
	void quickSort(int arr[], int low, int high) {

		if (low < high) {
			int pivot = partition(arr, low, high); // finding the partition index
			quickSort(arr, low, pivot - 1); // Quicksort for the first half
			quickSort(arr, pivot + 1, high); // Quicksort for the second half
		}
	}


	/* This function takes last element as pivot, places
	the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
	to left of pivot and all greater elements to right
	of pivot */
	int partition(int arr[], int low, int high) {

		int pivot = arr[high]; // pivot element
		int pivotIndex = low; // pivotIndex or Index of smaller element and indicates the
		// right position of pivot found so far

		for (int i = low; i <= high - 1; i++) {
			// If the current element is smaller than the pivot
			if (arr[i] <= pivot) {
				swap(arr[pivotIndex], arr[i]);
				pivotIndex++; // Increment index of smaller element
			}
		}
		swap(arr[high], arr[pivotIndex]);
		return pivotIndex ;

	}
};

// Function to print an array
void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {10, 7, 8, 9, 1, 5}; // {10, 80, 30, 90, 40, 50, 70}
	int n = sizeof(arr) / sizeof(arr[0]);
	Solution obj;
	cout << " Before Quick Sort : " << endl;
	printArray(arr, n);
	obj.quickSort(arr, 0, n - 1);
	cout << " After Quick Sort : " << endl;
	printArray(arr, n);
	return 0;
}