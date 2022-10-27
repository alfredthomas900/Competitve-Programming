// Bubble Sort Algorithm

// Approach:

// Repeatedly swap 2 adjacent elements if arr[j] > arr[j+1] .
// Here, the maximum element of the unsorted array reaches the end of the unsorted array after each iteration.
// Unlike selection sort, here, sorting is done from the back as shown in the dry run.
//  After (N-1) iterations , we get a sorted array.


#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {

	// Bubble Sort Algorithm
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// swap(arr[j], arr[j + 1]);
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	cout << " After Bubble Sort : " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main() {
	int arr[] = {13, 46, 24, 52, 20, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << " Before Bubble Sort : " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	bubbleSort(arr, n);
	return 0;
}

// TC = O(N^2); SC = O(1)