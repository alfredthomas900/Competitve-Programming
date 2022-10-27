// Insertion Sort Algorithm
// Approach:

// Take an element from the unsorted array.
// Place it in its corresponding position in the sorted part.
// Shift the remaining elements accordingly.
// In this approach, start iterating the “outer for loop”  from the 2nd position of the array.
// The “inner while loop” shifts the elements using swapping.


#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
	// Insertion Sort Algorithm
	for (int i = 1; i < n; i++) {
		int currentElement = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > currentElement) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = currentElement;
	}

	cout << " After Insertion Sort : " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {13, 46, 24, 52, 20, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << " Before Insertion Sort : " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	insertionSort(arr, n);
	return 0;
}

// // TC = O(N^2); SC = O(1)