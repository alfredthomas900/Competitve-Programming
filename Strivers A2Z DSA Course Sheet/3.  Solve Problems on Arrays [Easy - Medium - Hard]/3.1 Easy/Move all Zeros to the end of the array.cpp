// Problem Statement:
//  You are given an array of integers, your task is to move all the zeros
//  in the array to the end of the array and move non-negative integers to the front by maintaining their order.

// Examples:

// Example 1:
// Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
// Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
// Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

// Example 2:
// Input: 1,2,0,1,0,4,0
// Output: 1,2,1,4,0,0,0
// Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order


// Solution 1: Brute Force

// Algorithm:

// Create a temp array of length input array
// Traverse through array and if a non negative elements encounter then put this element in the temp array at zero index and increment index
// Fill the zeros in remaining places of temp array


#include <bits/stdc++.h>
using namespace std;

void moveZerosToEnd(int arr[], int n) {

	int temp[n];
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			temp[k] = arr[i];
			k++;
		}
	}

	// while(k < n) {
	// 	temp[k] = 0;
	// 	k++;
	// }

	for (int i = k; i < n; i++) {
		temp[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		cout << temp[i] << " ";
	}
	cout << endl;


}


int main() {
	int arr[] = {1, 2, 0, 1, 0, 4, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	moveZerosToEnd(arr, n);

}

// Time complexity: O(n); Space complexity: O(n)


// Solution 2: Optimal Approach

// Algorithm:

// Start traversing from the first occurrence index of Zero
// Take 2 variables (i,j), i will be at the first occurrence of zero and j is at i+1
// If element at j index is not zero then swap elements at i,j and increment i,j
// If the element at j index is zero then only increment j.


#include<bits/stdc++.h>
using namespace std;

void moveZerosToEnd(int arr[], int n) {

	// finding the first zero occurrence
	int k = 0;
	while (k < n) {
		if (arr[k] == 0) {
			break;
		}
		k++;
	}

	// finding zeros and immediate non-zero elements & swapping them
	int i = k, j = k + 1;
	while (i < n && j < n) {
		if (arr[j] != 0) {
			swap(arr[i], arr[j]);
			i++;
		}
		j++;
	}

	for (i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}



int main() {
	int arr[] = {1, 2, 0, 1, 0, 4, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	moveZerosToEnd(arr, n);

}

// Time complexity: O(n); Space complexity: O(1)

