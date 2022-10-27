// Problem Statement:
// Given two sorted arrays, arr1 and arr2 of size n and m. Find the union of two sorted arrays.
// The union of two arrays can be defined as the common and distinct elements in the two arrays.
// NOTE: Elements in the union should be in ascending order.

// Examples:

// Example 1:
// Input:
// n = 5,m = 5.
// arr1[] = {1,2,3,4,5}
// arr2[] = {2,3,4,4,5}
// Output:
//  {1,2,3,4,5}

// Explanation:
// Common Elements in arr1 and arr2  are:  2,3,4,5
// Distnict Elements in arr1 are : 1
// Distnict Elemennts in arr2 are : No distinct elements.
// Union of arr1 and arr2 is {1,2,3,4,5}

// Example 2:
// Input:
// n = 10,m = 7.
// arr1[] = {1,2,3,4,5,6,7,8,9,10}
// arr2[] = {2,3,4,4,5,11,12}
// Output: {1,2,3,4,5,6,7,8,9,10,11,12}
// Explanation:
// Common Elements in arr1 and arr2  are:  2,3,4,5
// Distnict Elements in arr1 are : 1,6,7,8,9,10
// Distnict Elemennts in arr2 are : 11,12
// Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12}


// Solution 1: Using Map
// Our aim is to find the common elements in arr1 and arr2, and
// the distinct elements of arr1,arr2.
// Use a Single map to find the frequencies of elements in arr1 and arr2.


#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m) {

    map<int, int> freq;
    vector<int> Union;

    for (int i = 0; i < n; i++) {
        freq[arr1[i]]++;
    }
    for (int i = 0; i < m; i++) {
        freq[arr2[i]]++;
    }

    for (auto &it : freq) {
        Union.push_back(it.first);
    }
    return Union;

}



int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> Union = findUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto &it : Union) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}


// TC = O((m+n)log(m+n)); SC = 0(m+n)




// Solution 2: Using Set

// Using set we can find the distinct elements,
// because set does not holds any duplicates.
// Hence we can find the union of arr1 and arr2.

#include <bits/stdc++.h>
using namespace std;


vector<int> findUnion(int arr1[], int arr2[], int n, int m) {

    set<int> st;
    vector<int> Union;
    for (int i = 0; i < n; i++) {
        st.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        st.insert(arr2[i]);
    }

    for (auto &it : st) {
        Union.push_back(it);
    }
    return Union;

}


int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> Union = findUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto &it : Union) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

// TC = O((m+n)log(m+n)); SC = 0(m+n)



// Solution 3: Two Pointers

// Approach:

// Take two pointers let’s say i, j pointing to the 0th index of arr1 and arr2.
// Create a empty vector for storing the union of arr1 and arr2.
// From solution 2 we know that the union is nothing but the distinct elements in arr1 + arr2
// Let’s traverse the arr1 and arr2 using pointers i and j and insert the distinct elements found into union vector.
//     While traversing we may encounter three cases.
//         1. arr1[ i ] == arr2[ j ]
//         Here we found a common element, so insert only one element in the union.
//         Let’s insert arr[i] in union and increment i.
//         NOTE : There may be cases like the element to be inserted is already present in the union,
//         in that case, we are inserting duplicates which is not desired.
//         So while inserting always check whether the last element in the union vector is equal or not to the element to be inserted.
//         If equal we are trying to insert duplicates, so don’t insert the element, else insert the element in the union.
//         This makes sure that we are not inserting any duplicates in the union because we are inserting elements in sorted order.

//         2. arr1[ i ]  < arr2[ j ]
//         arr1[ i ] < arr2[ j ] so we need to insert arr1[ i ] in union.
//         If last element in  union vector is not equal to arr1[ i ],
//         then insert in union else don’t insert. After checking Increment i.

//         3. arr1[ i ] > arr2[ j ]
//         arr1[ i ] > arr2[ j ] so we need to insert arr2[ j ] in union.
//         If the last element in the union vector is not equal to arr2[ j ],
//         then insert in the union, else don’t insert. After checking Increment j.
//         After traversing if any elements are left in arr1 or arr2 check for condition and insert in the union.


#include <bits/stdc++.h>
using namespace std;


vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0;
    vector<int> Union;
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) { // Case 1 and Case 2
            if (Union.size() == 0 || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        }
        else { // Case 3
            if (Union.size() == 0 || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
    }

    // If any elements are left in arr1
    while (i < n) {
        if (Union.back() != arr1[i])
            Union.push_back(arr1[i]);
        i++;
    }

    // If any elements are left in arr2
    while (j < m) {
        if (Union.back() != arr2[j])
            Union.push_back(arr2[j]);
        j++;
    }

    return Union;

}


int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> Union = findUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto &it : Union) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

// TC = O(m+n); SC = 0(m+n)