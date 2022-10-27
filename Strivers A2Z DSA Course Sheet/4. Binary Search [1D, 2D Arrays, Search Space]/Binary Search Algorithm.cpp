// Binary Search Algorithm

// 1. Iteration Method:-
// binarySearch(arr, x, low, high)
//       repeat till low = high
//              mid = (low + high)/2
//                  if (x == arr[mid])
//                  return mid

//                  else if (x > arr[mid]) // x is on the right side
//                      low = mid + 1

//                  else                  // x is on the left side
//                      high = mid - 1


#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int x) {

	while (low <= high) {
		int mid = low + (high - low) / 2;

		// Check if x is present at mid
		if (x == arr[mid]) {
			return mid;
		}

		// If x is greater than mid, then ignore the left half
		if (x > arr[mid]) {
			low = mid + 1;
		}

		// If x is smaller than mid, then ignore the right half
		else //if(x < arr[mid]) {
			high = mid - 1;
	}
	// if we reach here, then the element is not present
	return -1;

}


int main() {
	int arr[] = {2, 3, 4, 10, 40};
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int index = binarySearch(arr, 0, n - 1, x);
	(index == -1) ?
	cout << " Element is not present in the array " << endl :
	     cout << " Element is present at index : " << index << endl;
	return 0;
}

// TC = O(n); SC = 0(1)


// 2. Recursive Method (The recursive method follows the divide and conquer approach)

//     binarySearch(arr, x, low, high)
//            if low > high
//                return False

//            else
//                mid = (low + high) / 2
//                    if x == arr[mid]
//                    return mid

//                else if x > arr[mid]        // x is on the right side
//                    return binarySearch(arr, x, mid + 1, high)

//                else                        // x is on the left side
//                    return binarySearch(arr, x, low, mid - 1)

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int x) {

	if (low <= high) {
		int mid = low + (high - low) / 2;

		// Check if x is present at mid
		if (x == arr[mid]) {
			return mid;
		}

		// If element is smaller than mid, then
		// it can only be present in the left subarray
		if (x < arr[mid]) {
			return binarySearch(arr, low, mid - 1, x);
		}

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, high, x);
	}

	// if we reach here, then the element is not present
	return -1;
}



int main() {
	int arr[] = {2, 3, 4, 10, 40};
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int index = binarySearch(arr, 0, n - 1, x);
	(index == -1) ?
	cout << " Element is not present in the array" << endl :
	     cout << " Element is present at index : " << index << endl;
	return 0;
}


// TC = O(logn); SC = 0(logn) due to the recursive stack