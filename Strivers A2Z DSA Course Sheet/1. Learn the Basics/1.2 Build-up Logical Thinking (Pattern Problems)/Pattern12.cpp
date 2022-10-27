//Geek is very fond of patterns. Once, his teacher gave him a pattern to solve. He gave Geek an integer n and asked him to build a pattern.
//
//Help Geek to build the pattern.
//
// 
//
//Example 1:
//
//Input: 5
//
//Output:
//1                 1
//1 2             2 1
//1 2 3         3 2 1
//1 2 3 4     4 3 2 1
//1 2 3 4 5 5 4 3 2 1
// 
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
        // code here
        int spaces = 2*n - 2;
        for(int i = 1; i <= n; i++) {
            int temp = i;
            for(int j = 1; j <= i; j++) { 
                cout << j << " ";
            }
            for(int k = 1; k <= spaces; k++) { // Loop for printing spaces
                cout << "  ";
            }
            for(int l = 1; l <= i; l++) {
                cout << temp << " ";
                temp = temp - 1;
            }
            spaces = spaces - 2;
            cout << endl;
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