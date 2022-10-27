//Given an array A of size N, print the reverse of it.
//
//Example:
//
//Input:
//1
//4
//1 2 3 4
//Output:
//4 3 2 1
//Input:
//First line contains an integer denoting the test cases 'T'. T testcases follow. Each testcase contains two lines of input. First line contains N the size of the array A. The second line contains the elements of the array.
//
//Output:
//For each testcase, in a new line, print the array in reverse order.
//
//Constraints:
//1 <= T <= 100
//1 <= N <=100
//0 <= Ai <= 100


#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int n)
{
    int start = 0, end = n - 1, temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    for(int i = 0; i < n; i++)
        cout << arr[i]<<" ";
    cout << endl;
}



int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    	reverseArray(arr, n);
	    
	}
	return 0;
}




//Function to reverse array using an auxiliary array
void reverseArray(int arr[], int n) {
   int ans[n];
   for (int i = n - 1; i >= 0; i--) {
      ans[n - i - 1] = arr[i];
   }
   printArray(ans, n);
}



//Function to reverse array using recursion
void reverseArray(int arr[], int start, int end) {
   if (start < end) {
      swap(arr[start], arr[end]);
      reverseArray(arr, start + 1, end - 1);
   }
}















