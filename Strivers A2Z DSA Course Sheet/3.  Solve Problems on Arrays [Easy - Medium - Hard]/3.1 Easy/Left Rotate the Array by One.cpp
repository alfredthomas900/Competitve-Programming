// Problem Statement:
// Given an array of N integers, left rotate the array by one place.

// Examples:

// Example 1:
// Input: N = 5, array[] = {1,2,3,4,5}
// Output: 2,3,4,5,1
// Explanation:
// Since all the elements in array will be shifted
// toward left by one so ‘2’ will now become the
// first index and and ‘1’ which was present at
// first index will be shifted at last.


// Example 2:
// Input: N = 1, array[] = {3}
// Output: 3
// Explanation: Here only element is present and so
// the element at first index will be shifted to
// last index which is also by the way the first index.

// Solution 1: Brute force Approach
// Approach:
// We can take another dummy array of the same length and
// then shift all elements in the array toward the left and
// then at the last element store the index of 0th index of the array and print it.


#include<bits/stdc++.h>
using namespace std;

void leftRotate(int arr[], int n) {
	int temp[n];
	for (int i = 1; i < n; i++) {
		temp[i - 1] = arr[i];
	}
	temp[n - 1] = arr[0];

	// print the final array
	for (int i = 0; i < n; i++) {
		cout << temp[i] << " ";
	}
	cout << endl;
}


int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr)  / sizeof(arr[0]);
	leftRotate(arr, n);
	return 0;
}

// TC = O(n); SC = O(n), due to the extra array



// Solution 2:
// Approach:
// At first, we have to shift the array towards the left so,
// we store the value of the first index in a variable (let it be x).
// Then we iterate the array from the 0th index to the n-1th index (why n-1 i will explain it below)
// And then store the value present in the next index to the current index like this :
// arr[i] = arr[i+1]
// And to prevent its segmentation fault we will iterate it till n - 1.
// At last, put the value of variable x in the last index of the array.


#include<bits/stdc++.h>
using namespace std;

void leftRotate(int arr[], int n) {

	int temp = arr[0];
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = temp;

	// print the final array
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}



int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr)  / sizeof(arr[0]);
	leftRotate(arr, n);
	return 0;
}

// TC = O(n); SC = O(1), as no extra space is used