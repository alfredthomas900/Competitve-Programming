// Rotate array by K elements

// Problem Statement:
// Given an array of integers, rotating array of elements by k elements either left or right.

// Examples:

// Example 1:
// Input: N = 7, array[] = {1,2,3,4,5,6,7} , k=2 , right
// Output: 6 7 1 2 3 4 5
// Explanation: array is rotated to right by 2 position .

// Example 2:
// Input: N = 6, array[] = {3,7,8,9,10,11} , k=3 , left
// Output: 9 10 11 3 7 8
// Explanation: Array is rotated to right by 3 position.


// Solution :
// Approach 1: Using a temp array

// For Rotating the Elements to left
// Step 1: Copy the first k elements into the temp array.
// Step 2: Shift n-k elements from last by k position to the left
// Step 3: Copy the elements into the main array from the temp array.

// For Rotating the Elements to right
// Step 1: Copy the last k elements into the temp array.
// Step 2: Shift n-k elements from the beginning by k position to the right
// Step 3: Copy the elements into the main array from the temp array.


#include <bits/stdc++.h>
using namespace std;

void leftRotate(int arr[], int n, int k) {

	if (n == 0) {
		return;
	}

	if (k > n) {
		k = k % n;
	}

	int temp[k];

	// Copy the first k elements into the temp array
	for (int i = 0; i < k; i++) {
		temp[i] = arr[i];
	}

	// Shift n-k elements from last by k position to the left
	for (int i = 0; i < n - k; i++) {
		arr[i] = arr[i + k];
	}

	// Copy the elements into the main array from the temp array
	for (int i = n - k; i < n; i++) {
		arr[i] = temp[i - n + k];
	}

}

void rightRotate(int arr[], int n, int k) {

	if (n == 0) {
		return;
	}

	if (k > n) {
		k = k % n;
	}
	int temp[k];

	// Copy the last k elements into the temp array
	for (int i = n - k; i < n; i++) {
		temp[i - n + k] = arr[i];
	}

	// Shift n-k elements from the beginning by k position to the right
	for (int i = n - k - 1; i >= 0; i--) {
		arr[i + k] = arr[i];
	}


	// Copy the elements into the main array from the temp array.
	for (int i = 0; i < k; i++) {
		arr[i] = temp[i];
	}

}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main() {
	int arr1[] = {1, 2, 3, 4, 5, 6, 7};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);

	int arr2[] = {1, 2, 3, 4, 5, 6, 7};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	int k = 2;
	// cout << " On the rotating the array1 by elements to the left : " << endl;
	// leftRotate(arr1, n1, k);
	// printArray(arr1, n1);
	cout << " On the rotating the array2 by elements to the right : " << endl;
	rightRotate(arr2, n2, k);
	printArray(arr2, n2);
	return 0;

}


// Time Complexity: O(n); Space Complexity: O(k) since k array element needs to be stored in temp array






// Approach 2:- Using Reversal Algorithm

// For Rotating Elements to left
// Step 1: Reverse the first k elements of the array
// Step 2: Reverse the last n-k elements of the array.
// Step 3: Reverse the whole array.

// For Rotating Elements to right
// Step 1: Reverse the whole array.
// Step 2: Reverse the first k elements of the array
// Step 3: Reverse the last n-k elements of the array.




#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end) {

	while (start < end) {
		swap(arr[start], arr[end]);
		start++;
		end--;
	}

}


void leftRotate(int arr[], int n, int k) {

	// Reverse the first k elements of the array
	reverseArray(arr, 0 , k - 1);
	// Reverse the last n-k elements of the array.
	reverseArray(arr, k , n - 1);
	// Reverse the whole array.
	reverseArray(arr, 0 , n - 1);

}


void rightRotate(int arr[], int n, int k) {

	// Reverse the whole array.
	reverseArray(arr, 0 , n - 1);
	// Reverse the first k elements of the array
	reverseArray(arr, 0 , k - 1);
	// Reverse the last n-k elements of the array.
	reverseArray(arr, k , n - 1);

}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main() {
	int arr1[] = {1, 2, 3, 4, 5, 6, 7};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int arr2[] = {1, 2, 3, 4, 5, 6, 7};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	int k = 2;
	cout << " On the rotating the array1 by elements to the left : " << endl;
	leftRotate(arr1, n1, k);
	printArray(arr1, n1);
	cout << " On the rotating the array2 by elements to the right : " << endl;
	rightRotate(arr2, n2, k);
	printArray(arr2, n2);
	return 0;

}

// // Time Complexity: O(n); Space Complexity: O(1), no extra space required