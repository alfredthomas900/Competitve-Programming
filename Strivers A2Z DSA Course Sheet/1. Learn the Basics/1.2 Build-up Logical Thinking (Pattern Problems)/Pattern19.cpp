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
//
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********
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
        for(int i = 1; i <= 2*n ; i++)
        {
            int stars = i <= n ? (n - i) + 1 : i - n; 
            for(int j = 1; j <= stars; j++) { //Print the 1st half of the stars
                cout << "*";
            }
            int spaces = i <= n ? (2*i) - 2 : 2*n - 2*(i - n); 
            for(int s = spaces; s > 0 ; s--) { //loop for printing the spaces in between
                cout << " ";
            }
            for(int j = 1; j <= stars ; j++) { //Print the 2nd half of the stars
                cout << "*";
            }
            cout << "\n";
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