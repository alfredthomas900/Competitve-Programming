// Problem Statement: Given an array sort the elements of the array using count sort.

// Count Sort:
// Count sort is one of the non-comparison stable sorting algorithms which sorts elements within a range k in O(n+k) time complexity.

// Properties of Count Sort
// 1. It is a linear time algorithm when input lies within a small range k i.e. k should be linear with respect to n.
// 2. It is a non-comparison based sorting algorithm because it counts the occurrences of elements
//    and on that basis, sorting takes place.
// 3. It is a stable sorting algorithm.
// 4. It is used as a subroutine in radix sort.


// Approach 1: Naive Approach
// Count sort counts the occurrences of elements and
// later places them into the array with respect to the number of occurrences.
// The following steps explain this approach.

// We create a count array of size k and initially define every index with a value of 0.
// Since elements lie within a range k and we need to count the occurrence of those elements,
// we store the occurrence of that number at the respective index.
// For every number in that range, we run a loop for the number of times that number occurred in the array
// and continue to place that number in the array for that number of times.
// We end up with the final sorted array.


// #include <bits/stdc++.h>
// using namespace std;

// void countSort(int arr[], int n, int k) {

// 	int count[k];
// 	// Setting the default values for the count[]
// 	for (int i = 0; i < k; i++) {
// 		count[i] = 0;
// 	}

// 	// Counting the frequencies of the elements in arr[]
// 	for (int i = 0; i < n; i++) {
// 		count[arr[i]]++;
// 	}

// 	int index = 0;
// 	for (int i = 0; i < k; i++) {
// 		for (int j = 0; j < count[i]; j++) {
// 			arr[index] = i;
// 			index++;
// 		}
// 	}

// 	cout << "After Count Sort : " << endl;
// 	for (int i = 0; i < n; i++) {
// 		cout << arr[i] << " ";
// 	}
// 	cout << endl;

// }


// int main() {
// 	int arr[] = {5, 6, 5, 2};
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	int k = 7;
// 	countSort(arr, n, k);
// 	return 0;
// }

// TC = O(n*k); SC = O(k)



// Approach 2: Efficient Approach

// With some additions and modifications to the naive approach, we can create a general-purpose algorithm.
// Let’s see how we can do it.

// 1. We create a count array of size k and initially define every index with a value of 0.
// Since elements lie within a range k and we need to count the occurrence of those elements,
// we store the occurrence of that number at the respective index.
// 2. We modify our count array – for every i varying from 0 to k-1,
// we store the number of elements smaller than or equal to the i.
// Now we build our resultant array
// 3. We traverse the original array from the end.

// 1. We traverse the original array from the end.
// 2. We use these elements in the array as the index of our count array
// to determine the number of elements (a) smaller or equal to that element.
// 3. Once we get that number(a), we place that element at that ath position
// i.e. [a-1]th index in the resultant array.
// 4. Once we place it at that position, we reduce a.
// Finally, we copy the contents of our resultant array to the original array.

// Note: We are performing backward iteration in 3. a to keep the algorithm stable.


#include <bits/stdc++.h>
using namespace std;


void countSort(int arr[], int n, int k) {

	int count[k];
	// Setting the default values for the count[]
	for (int i = 0; i < k; i++) {
		count[i] = 0;
	}
	// Counting the frequencies of the elements in arr[]
	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}

	// Here, we modify the count[]
	for (int i = 1; i < k; i++) {
		count[i] = count[i - 1] + count[i];
	}

	int res[n];
	for (int i = n - 1; i >= 0; i--) {
		res[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	cout << "After Count Sort : " << endl;
	for (int i = 0; i < n; i++) {
		arr[i] = res[i];
		cout << arr[i] << " ";
	}
	cout << endl;

}


int main() {
	int arr[] = {5, 6, 5, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 7;
	countSort(arr, n, k);
	return 0;
}

// TC = O(n + k); SC = O(n + k)