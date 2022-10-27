// Solution1: Sorting

// Intuition: We can sort the array in ascending order, hence the largest element will be at the last index of the array.

// Approach:

// Sort the array in ascending order.
// Print the (size of the array -1)th index.


#include <bits/stdc++.h>
using namespace std;

int sortarr(vector<int> &arr) {
	sort(arr.begin(), arr.end());
	return arr[arr.size() - 1];
}


int main() {
	vector<int> arr1 = {2, 5, 1, 3, 0};
	vector<int> arr2 = {8, 10, 5, 7, 9};
	cout << " The Largest element in the array is : " << sortarr(arr1) << endl;
	cout << " The Largest element in the array is : " << sortarr(arr2) << endl;
	return 0;
}

// Time Complexity: O(N*log(N)); Space Complexity: O(N)


// Solution2: Using a max variable

// Intuition: We can maintain a max variable which will update whenever the current value is greater than the value in the max variable.

// Approach:

// Create a max variable and initialize it with arr[0].
// Use a for loop and compare it with other elements of the array
// If any element is greater than the max value, update max value with the element’s value
// Print the max variable.

#include <bits/stdc++.h>
using namespace std;

int findLargestElement(vector<int> &arr) {
	int largest = arr[0];
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] > largest) {
			largest = arr[i];
		}
	}
	return largest;

}


int main() {
	vector<int> arr1 = {2, 5, 1, 3, 0};
	vector<int> arr2 = {8, 10, 5, 7, 9};
	cout << " The Largest element in the array is : " << findLargestElement(arr1) << endl;
	cout << " The Largest element in the array is : " << findLargestElement(arr2) << endl;
	return 0;
}