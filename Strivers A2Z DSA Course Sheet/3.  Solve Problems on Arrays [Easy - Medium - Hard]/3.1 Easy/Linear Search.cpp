// Problem Statement:
// Given an array, and an element num
// the task is to find if num is present in the given array or not.
// If present print the index of the element or print -1.

// Examples:

// Example 1:
// Input: arr[]= 1 2 3 4 5, num = 3
// Output: 2
// Explanation: 3 is present in the 2nd index

// Example 2:
// Input: arr[]= 5 4 3 2 1, num = 5
// Output: 0
// Explanation: 5 is present in the 0th index


#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int x) {

	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	return -1;
}


int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 4;
	int index = linearSearch(arr, n, x);
	cout << " The Element is found at index : " << index << endl;
}


// Time Complexity: O(n); Space Complexity: O(1)

