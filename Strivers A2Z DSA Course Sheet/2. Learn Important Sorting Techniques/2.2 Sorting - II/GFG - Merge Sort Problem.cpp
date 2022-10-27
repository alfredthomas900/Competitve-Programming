// Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.
// Example 1:

// Input:
// N = 5
// arr[] = {4 1 3 9 7}
// Output:
// 1 3 4 7 9
// Example 2:

// Input:
// N = 10
// arr[] = {10 9 8 7 6 5 4 3 2 1}
// Output:
// 1 2 3 4 5 6 7 8 9 10

// Your Task:
// You don't need to take the input or print anything. Your task is to complete the function merge() which takes arr[], l, m, r as its input parameters and modifies arr[] in-place such that it is sorted from position l to position r, and function mergeSort() which uses merge() to sort the array in ascending order using merge sort algorithm.

// Expected Time Complexity: O(nlogn)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= N <= 105
// 1 <= arr[i] <= 103


//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


// } Driver Code Ends
class Solution
{
public:
	void merge(int arr[], int l, int mid, int r) {
		// Your code here
		int i = l; // Starting index of Left half of arr
		int j = mid + 1; // Starting index of Right half of arr
		int k = l; // Index used to transfer elements in the temporary array
		int temp[1000000]; // Temporary array

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

		while (j <= r) {
			temp[k] = arr[j];
			j++;
			k++;
		}
		while (i <= mid) {
			temp[k] = arr[i];
			i++;
			k++;
		}

		// Transferring all elements from temporary array to arr
		for (int k = l; k <= r; k++) {
			arr[k] = temp[k];
		}
	}
public:
	void mergeSort(int arr[], int l, int r) {
		//code here
		if (l < r) {
			int mid = (l + r) / 2;
			mergeSort(arr, l, mid); // Left Half
			mergeSort(arr, mid + 1, r); // Right Half
			merge(arr, l, mid, r); // Sorting and Merging the two Halves at each level
		}
	}
};

//{ Driver Code Starts.


int main()
{
	int n, T, i;

	scanf("%d", &T);

	while (T--) {

		scanf("%d", &n);
		int arr[n + 1];
		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		Solution ob;
		ob.mergeSort(arr, 0, n - 1);
		printArray(arr, n);
	}
	return 0;
}
// } Driver Code Ends