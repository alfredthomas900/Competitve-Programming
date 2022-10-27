// Problem Statement:
// Find the intersection of two sorted arrays. OR
// in other words, Given 2 sorted arrays,
// find all the elements which occur in both the arrays.

// Examples:

// Example 1:
// Input:
// A: [1 2 3 3 4 5 6]
// , B: [3 3 5]
// Output: 3, 3, 5
// Explanation: We are given two arrays A and B.
// The elements present in both the arrays
// are 3, 3 and 5.

// Example 2:
// Input:
// A: [1 2 3 3 4 5 6]
// , B: [3 5]
// Output: 3, 5
// Explanation: We are given two arrays A and B.
// The elements present in both the arrays are 3 and 5.


// Brute Force Approach:
// For a brute force approach, we are given 2 arrays,
// what we can do is take the element from array A and
// search if it is present in array B.


#include <bits/stdc++.h>
using namespace std;

vector<int> findIntersection(vector<int> &arr1, vector<int> &arr2, int n, int m) {
	vector<int> ans;
	vector<int> visited(m, 0); // to maintain visited
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr1[i] == arr2[j] && visited[j] == 0) {
				//if an element matches and has not been matched with any other before
				ans.push_back(arr2[j]);
				visited[j] = 1;
				break;
			}
			else if (arr2[j] > arr1[i])
				break;
			//because array is sorted , element will not be beyond this
		}
	}
	return ans;
}




int main() {
	vector<int> arr1 = {1, 2, 3, 3, 4, 5, 6, 7};
	vector<int> arr2 = {3, 3, 4, 4, 5, 8};
	int n = arr1.size();
	int m = arr2.size();
	vector<int> result = findIntersection(arr1, arr2, n, m);
	cout << "InterSection of arr1 and arr2 is :" << endl;
	for (auto &it : result) {
		cout << it << " ";
	}
	cout << endl;


	return 0;
}

// TC = O(m * n) or 0(n^2); SC = O(n)



// Solution 2:
// Two Pointer approach
// Algorithm:- {1, 2, 3, 3, 4, 5, 6, 7}; {3, 3, 4, 4, 5, 8};
// 1. Initialize 2 pointers i and j. i=0 and will iterate over Array A, j=0 and will iterate over Array
// 2. Now A[i] is less than B[j], so we are certainly not going to find A[i],
// 	i.e,1 any further in the array. Let’s increment the pointer i and check the next element.
// 3. Again A[i] is less than B[j], so we are certainly not going to find A[i],
// 	i.e,2 any further in the array. Let’s increment the pointer i and check the next element.
// 3. Now, A[i] and B[j] is a match, so push A[i] into the ans vector. And this time we move both i and j.
// 4. Now, A[i] and B[j] is a match, so push A[i] into the ans vector. And this time we move both i and j.
// 	Since we are moving both i and j upon encountering a match, there is no way
// 	that the same element matches duplicate elements in the other array.
// 4. Again A[i] is less than B[j], so we are certainly not going to find A[i],
// 	i.e,4 any further in the array. Let’s increment the pointer i and check the next element.
// 5. Now, A[i] and B[j] is a match, so push A[i] into the ans vector. And this time we move both i and j.
// 	Now when we move j, it goes out of bounds, which means we have traversed the array fully,
// 	and there are no elements left to be matched with array A, so we stop here.
// 6. Just to make the other case clear as well, if A[i] > B[j],i.e,
// 	all elements in A are greater than the current element in B, we move the j pointer.
// 	And the loop continues till either array A or B exists.


#include <bits/stdc++.h>
using namespace std;

vector<int> findIntersection(vector<int> &arr1, vector<int> &arr2, int n, int m) {

	vector<int> ans;
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (arr1[i] < arr2[j]) { // if the current element in i is smaller
			i++;
		}
		else if (arr1[i] > arr2[j]) {
			j++;
		}
		else {
			ans.push_back(arr1[i]); // both elements are equal
			i++;
			j++;
		}
	}

	return ans;


}


int main() {
	vector<int> arr1 = {1, 2, 3, 3, 4, 5, 6, 7};
	vector<int> arr2 = {3, 3, 4, 4, 5, 8};
	int n = arr1.size();
	int m = arr2.size();
	vector<int> result = findIntersection(arr1, arr2, n, m);
	cout << "InterSection of arr1 and arr2 is :" << endl;
	for (auto &it : result) {
		cout << it << " ";
	}
	cout << endl;


	return 0;
}

// TC = O(n); SC = O(1)
