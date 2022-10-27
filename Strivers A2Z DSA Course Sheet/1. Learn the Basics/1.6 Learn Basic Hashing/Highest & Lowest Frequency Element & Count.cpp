//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
int findDiff(int arr[], int n) {

	unordered_map<int, int> map;
	for (int i = 0; i < n; i++) {
		map[arr[i]]++;
	}
	for (auto x : map) {
		cout << x.first << " " << x.second << endl;
	}


	int maxCount = 0, minCount = n, maxElement = 0, minElement = n;
	for (auto x : map) {
		maxCount = max(maxCount, x.second);
		minCount = min(minCount, x.second);
		maxElement = max(maxElement, x.first);
		minElement = min(minElement, x.first);

	}
	cout << endl << "Highest Frequency is : " << maxCount;
	cout << endl << "Lowest  Frequency is : " << minCount;
	cout << endl << "Highest Frequency ELement is : " << maxElement;
	cout << endl << "Lowest Frequency ELement is : " << minElement;
	cout << endl << "Difference b/w Highest & lowest frequency is : ";
	return (maxCount - minCount);
}


//{ Driver Code Starts.
int main()
{
	int arr[] = {2, 3, 3, 2, 5, 6, 6 , 6, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << findDiff(arr, n);
	return 0;
}

// } Driver Code Ends