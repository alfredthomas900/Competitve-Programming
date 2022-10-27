//Geek is very fond of patterns. Once, his teacher gave him a star pattern to solve. He gave Geek an integer n and asked him to build a pattern.
//
//Help Geek to build a star pattern.
//
// 
//
//Example 1:
//
//Input: 5
//
//Output:
//
//    *
//   ***  
//  *****
// *******
//*********
//*********
// *******
//  *****
//   ***
//    *
//
//Your Task:
//
//You don't need to input anything. Complete the function printDiamond() which takes  an integer n  as the input parameter and print the pattern.
//
//Constraints:
//
//1<= N <= 20
// 

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) {
        // code here
        int stars1 = 1;
        int spaces1 = n - 1;
        int stars2 = n;
        int spaces2 = 0;
        // First half of the Triangle Pattern
        for(int i = 1; i <= n; i++) { // Loop for each line
            for(int j = 1; j <= spaces1; j++) {  // Loop for printing spaces
                cout << " ";
            }
            for(int k = 1; k <= stars1; k++) { // Loop for printing stars
                cout << "* "; 
            }
            stars1 = stars1 + 1;
            spaces1 = spaces1 - 1;
            cout << endl;
        }
        
        // Second half of the Triangle Pattern
        for(int x = 1; x <= n; x++) { // Loop for each line
            for(int y = 1; y <= spaces2; y++) {  // Loop for printing spaces
                cout << " ";
            }
            for(int z = 1; z <= stars2; z++) { // Loop for printing stars
                cout << "* ";
            }
            stars2 = stars2 - 1;
            spaces2 = spaces2 + 1;
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
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends