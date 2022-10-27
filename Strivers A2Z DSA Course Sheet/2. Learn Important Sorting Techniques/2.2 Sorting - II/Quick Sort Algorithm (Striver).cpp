// Quick Sort Algorithm
// Pivot

// Approach
// -> We will be using 2 pointers namely i, j.
// 	Initializing i at index 0 and j at index n-1 ( if the length of the array is n).
// -> We will swap arr[i] and arr[j] if  arr[i] > pivot  and arr[j] < pivot  and will increment i and decrement j .
// 	This goes on until i < j .
// -> Finally when i > j, we will stop swapping arr[i] and arr[j] and swap pivot with arr[j]
// 	so that pivot gets its final position.
// -> We will now recursively repeat this process in the left and right of the pivot
// 	so that we get our final sorted array.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	void quickSort(int arr[], int low, int high) {

		if (low < high) {
			int pivot = partition(arr, low, high); // finding the partition index
			quickSort(arr, low, pivot - 1); // Quicksort for the first half
			quickSort(arr, pivot + 1, high); // Quicksort for the second half
		}
	}

	int partition(int arr[], int low, int high) {

		int pivot = arr[low]; // or arr[end]
		int i = low;
		int j = high;

		while (i < j) {
			while (arr[i] <= pivot && i <= high - 1) {
				i++;
			}
			while (arr[j] > pivot && j >= low) {
				j--;
			}
			if (i < j) {
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[j], arr[low]);
		return j;
	}
};

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {4, 6, 2, 5, 7, 8, 1, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	Solution obj;
	cout << " Before Quick Sort : " << endl;
	printArray(arr, n);
	obj.quickSort(arr, 0, n - 1);
	cout << " After Quick Sort : " << endl;
	printArray(arr, n);
	return 0;
}


// TC = 0(nlogn)
// SC = O(1)