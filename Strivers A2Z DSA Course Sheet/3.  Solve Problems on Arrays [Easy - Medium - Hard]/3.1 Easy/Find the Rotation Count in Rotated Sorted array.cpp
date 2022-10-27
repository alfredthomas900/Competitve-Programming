// Given an array arr[] of size N having distinct numbers
// sorted in increasing order and the array has been right rotated
// (i.e, the last element will be cyclically shifted
// to the starting position of the array) k number of times,
// the task is to find the value of k.

// Examples:

// Input: arr[] = {15, 18, 2, 3, 6, 12}
// Output: 2
// Explanation: Initial array must be {2, 3, 6, 12, 15, 18}.
// We get the given array after rotating the initial array twice.

// Input: arr[] = {7, 9, 11, 12, 5}
// Output: 4


// Input: arr[] = {7, 9, 11, 12, 15};
// Output: 0


// Approach 1 (Using linear search): This problem can be solved using linear search.

// If we take a closer look at examples, we can notice that the number of rotations is equal
// to the index of the minimum element. A simple linear solution is
// find the minimum element and returns its index.

#include <bits/stdc++.h>
using namespace std;

int countRotations(int arr[], int n) {
	int minElement = arr[0];
	int minIndex = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < minElement) {
			minElement = arr[i];
			minIndex = i;
		}
	}
	return minIndex;
}



int main()
{
	int arr[] = { 15, 18, 2, 3, 6, 12 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The Numbers of rotations are : " << countRotations(arr, n) << endl;
	return 0;
}

// Time Complexity: O(N) // Space Complexity: O(1)

// Approach 2: (Efficient Using Binary Search) - Recursively
// Follow the steps mentioned below to implement the idea:

// The minimum element is the only element whose previous is greater than it.
// If there is no previous element, then there is no rotation (the first element is minimum).
// Check this condition for the middle element by comparing it with the (mid-1)th and (mid+1)th elements.
// If the minimum element is not at the middle (neither mid nor mid + 1), then
// If the middle element is smaller than the last element, then the minimum element lies in the left half
// Else minimum element lies in the right half.


#include <bits/stdc++.h>
using namespace std;

int countRotations(int arr[], int low, int high) {

	// This condition is needed to handle the case
	// when the array is not rotated at all
	if (low > high) {
		return 0;
	}
	// If there is only one element left
	if (low == high) {
		return low;
	}

	// Find mid
	int mid = low + (high - low) / 2;

	// Check if element (mid+1) is minimum element.
	// Consider the cases like {3, 4, 5, 1, 2}
	if (mid < high && arr[mid + 1] < arr[mid])
		return (mid + 1);

	// Check if mid itself is minimum element
	if (mid > low && arr[mid] < arr[mid - 1])
		return mid;

	// Decide whether we need to go to left half or
	// right half
	if (arr[high] > arr[mid])
		return countRotations(arr, low, mid - 1);

	return countRotations(arr, mid + 1, high);

}


int main()
{
	int arr[] = { 15, 18, 2, 3, 6, 12 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The Numbers of rotations are : " << countRotations(arr, 0, n - 1) << endl;
	return 0;
}


// Time Complexity: O(log N)
// Space Complexity: O(log N)  [this is the space of recursion stack]



// Approach 2: (Efficient Using Binary Search) - Iteratively
// Follow the steps mentioned below to implement the idea:

#include <bits/stdc++.h>
using namespace std;

// Returns count of rotations
// for an array which is first sorted
// in ascending order, then rotated

// Observation: We have to return
// index of the smallest element
int countRotations(int arr[], int n)
{
	int low = 0, high = n - 1;
	if (arr[low] <= arr[high])
		return 0;
	/*returns 0 if array is already sorted*/
	while (low <= high) {

		// if first element is mid or
		// last element is mid
		// then simply use modulo so it
		// never goes out of bound.
		int mid = low + (high - low) / 2;
		int prev = (mid - 1 + n) % n;
		int next = (mid + 1) % n;

		if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
			return mid;
		else if (arr[mid] <= arr[high])
			high = mid - 1;
		else if (arr[mid] >= arr[0])
			low = mid + 1;
	}
	return 0;
}

// Driver code
int main()
{
	int arr[] = {11, 12, 15, 18, 2, 5, 6, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << countRotations(arr, n);
	return 0;
}

// Time Complexity: O(log N)
// Auxiliary Space: O(1), since no extra space has been taken.