// Merge Sort Algorithm

// Approach :
// -> We will be creating 2 functions mergeSort() and merge()
// -> In mergeSort(), we will divide the array around the middle element by making the recursive call :
// 	1.mergeSort(arr,l,mid)   2. mergeSort(arr,mid+1,r)
// 		where l = leftmost index of array, r = rightmost index of array , mid = middle index of array
// -> In merge(),  we will use a temporary array named temp. This will be used to store elements in sorted
// 		order from both the arrays which we divided.
// ->From the temporary array, we will return back the elements in the original array.
// -> Now, let i = leftmost index of array, j = mid+1 index of array , f = leftmost index of array
// 	( this index will be used to store elements in the original array )
// -> While i<= mid && j <= r , we will store elements from both the parts in temporary array in sorted manner
// -> Finally will transfer all elements from the temporary array to the original array.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	void merge(int arr[], int l, int mid, int r) {
		int i = l; // Starting index of Left half of arr
		int j = mid + 1; // Starting index of Right half of arr
		int k = l; // Index used to transfer elements in the temporary array
		int temp[100000]; // Temporary array

		// Storing elements in the temporary array in a sorted manner

		while (i <= mid && j <= r) {
			if (arr[i] < arr[j]) {
				temp[k] = arr[i];
				i++;
				k++;
			}
			else {
				temp[k] = arr[j];
				j++;
				k++;
			}

		}

		// If elements on the left half array are still left

		if (i > mid) {
			while (j <= r) {
				temp[k] = arr[j];
				j++;
				k++;
			}
		}
		// If elements on the right half array are still left
		else {
			while (i <= mid) {
				temp[k] = arr[i];
				i++;
				k++;
			}
		}

		// Transferring all elements from temporary array to arr
		for (int k = l; k <= r; k++) {
			arr[k] = temp[k];
		}
	}

	void mergeSort(int arr[], int l, int r) {
		if (l < r) {
			int mid = (l + r) / 2;
			mergeSort(arr, l, mid); // Left Half
			mergeSort(arr, mid + 1, r); // Right Half
			merge(arr, l, mid, r); // Sorting and Merging the two Halves at each level
		}
	}
};

int main() {
	int arr[] = {9, 4, 7, 6, 3, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

	Solution obj;
	cout << " Before Merge Sort : " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	obj.mergeSort(arr, 0, n - 1);
	cout << " After Merge Sort : " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}

// TC = O(nlogn)
// SC = O(N) due to the extra auxillary array