//Ram is very fond of patterns. Once, his teacher gave him a pattern to solve. He gave Ram an integer n and asked him to build a pattern.
//
//Help Ram build a  pattern.
//
// 
//
//Example 1:
//
//Input: 5
//
//Output:
// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *
//
//Your Task:
//
//You don't need to input anything. Complete the function printTriangle() which takes  an integer n  as the input parameter and print the pattern.
//
//Constraints:
//
//1<= N <= 20

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
       
        int k = 0;
        for(int i = 1; i <= 2*n - 1; i++)
        {
        	i <= n ? k++ : k--;
        	for(int j = 1; j <= 2*n; j++)
        	{
        		if (j <= k || j >= 2*n + 1 - k)
        			cout<<"*";	
        		else
        			cout<<" ";
        	}
        	cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends