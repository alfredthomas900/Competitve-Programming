// Selection Sort Algorithm

// Approach:

// Find the minimum element in the unsorted array and swap it with the element at the beginning.
// The inner loop selects the minimum element in the unsorted array .
// Steps:
// Initialize minimum value(min_idx) to location 0.
// Traverse the array to find the minimum element in the array.
// While traversing if any element smaller than min_idx is found then swap both the values.
// Then, increment min_idx to point to the next element.
// Repeat until the array is sorted.


#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {

	// Selection Sort Algorithm

	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		// if(minIndex!=i)
		// 	swap(arr[minIndex], arr[i]);

		int temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
	}

	cout << " After Selection Sort : " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}


int main() {
	int arr[] = {13, 46, 24, 52, 20, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << " Before Selection Sort : " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	selectionSort(arr, n);
	return 0;
}

// TC = O(N^2); SC = O(1)