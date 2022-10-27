// Given an array of N distinct integers.
// The task is to write a program to check if this array is sorted and rotated clockwise.
// Note: A sorted array is not considered as sorted and rotated, i.e., there should be at least one rotation

// Examples:

// Input: arr[] = { 3, 4, 5, 1, 2 }
// Output: YES
// Explanation: The above array is sorted and rotated
// Sorted array: {1, 2, 3, 4, 5}
// Rotating this sorted array clockwise
// by 3 positions, we get: { 3, 4, 5, 1, 2}

// Input: arr[] = {3, 4, 6, 1, 2, 5}
// Output: NO


// Follow the given steps to solve the problem:

// 1. Find the minimum element in the array.
// 2. Now, if the array is sorted and then rotated,
// 	then all the elements before the minimum element will be in increasing order
// 	and all elements after the minimum element will also be in increasing order.
// 3. Check if all elements before the minimum element are in increasing order.
// 4. Check if all elements after the minimum element are in increasing order.
// 5. Check if the last element of the array is smaller than the starting element,
// 	as this would make sure that the array has been rotated at least once.
// 6. If all of the above three conditions satisfies then print YES otherwise print NO

#include <bits/stdc++.h>
using namespace std;

void checkIfSortedRotated(int arr[], int n) {

	int minElement = INT_MAX;
	int maxElement = INT_MIN;
	int minIndex = -1;

	// Find the minimum element and it's index
	for (int i = 0; i < n; i++) {
		if (arr[i] < minElement) {
			minElement = arr[i];
			minIndex = i;
		}
	}

	int flag1 = 1;

	// Check if all the elements before minIndex
	// are in increasing order

	for (int i = 1; i < minIndex; i++) {
		if (arr[i] < arr[i - 1]) {
			flag1 = 0;
			break;
		}
	}

	int flag2 = 1;

	// Check if all the elements after minIndex
	// are in increasing order

	for (int i = minIndex + 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			flag2 = 0;
			break;
		}
	}


	// Check if the last element is smaller than
	//  the starting element
	if (flag1 && flag2 && (arr[n - 1] < arr[0]))
		cout << "YES";
	else
		cout << "NO";

}


int main() {
	int arr[] = {3, 4, 5, 1, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	checkIfSortedRotated(arr, n);
	return 0;
}