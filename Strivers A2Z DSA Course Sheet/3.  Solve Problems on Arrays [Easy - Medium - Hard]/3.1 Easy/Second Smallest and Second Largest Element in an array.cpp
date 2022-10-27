// Problem Statement:
// Given an array, find the second smallest and
// second largest element in the array.
// Print ‘-1’ in the event that either of them doesn’t exist.

// Examples:

// Example 1:
// Input: [1,2,4,7,7,5]
// Output: Second Smallest : 2
// 	Second Largest : 5
// Explanation: The elements are as follows 1,2,3,5,7,7 and hence second largest of these is 5 and second smallest is 2

// Example 2:
// Input: [1]
// Output: Second Smallest : -1
// 	Second Largest : -1
// Explanation: Since there is only one element in the array,
// it is the largest and smallest element present in the array.
//  There is no second largest or second smallest element present.

#include <bits/stdc++.h>
using namespace std;

int findSecondLargest(int arr[], int n) {

	int smallest = INT_MAX, secondSmallest = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < smallest) {
			secondSmallest = smallest;
			smallest = arr[i];
		}
		else if (arr[i] < secondSmallest && arr[i] != smallest) {
			secondSmallest = arr[i];
		}
	}
	if (secondSmallest == 0) {
		return -1;
	}
	return secondSmallest;

}

int findSecondSmallest(int arr[], int n) {

	int largest = INT_MIN, secondLargest = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > largest) {
			secondLargest = largest;
			largest = arr[i];
		}
		else if (arr[i] > secondLargest && arr[i] != largest) {
			secondLargest = arr[i];
		}
	}
	if (secondLargest == 0) {
		return -1;
	}
	return secondLargest;
}


int main() {
	int arr[] = {1, 2, 4, 6, 7, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << " The Second Smallest element in the array is : " << findSecondSmallest(arr, n) << endl;
	cout << " The Second Largest element in the array is : " << findSecondLargest(arr, n) << endl;
	return 0;
}