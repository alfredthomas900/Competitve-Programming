//Geek is very fond of patterns. Once, his teacher gave him a square pattern to solve. He gave Geek an integer n and asked him to build a pattern.
//
//Help Geek to build the pattern.
//
// 
//
//Example 1:
//
//Input: 4
//
//Output:
//4 4 4 4 4 4 4
//4 3 3 3 3 3 4
//4 3 2 2 2 3 4
//4 3 2 1 2 3 4
//4 3 2 2 2 3 4
//4 3 3 3 3 3 4
//4 4 4 4 4 4 4
//
//Your Task:
//
//You don't need to input anything. Complete the function printSquare() which takes  an integer n  as the input parameter and print the pattern.
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
    void printSquare(int n) {
        // code here
        int c = 0;
        for(int i = 1; i <= 2*n - 1; i++) {
            
            int k = n;
            i <= n ? c++ : c--;
            int temp1 = c, temp2 = c;
            for(int j = 1; j <= 2*n -1; j++) {
                cout << k << " ";
                if(temp1 > 1 && j < n) {
                    k--;
                    temp1--;
                }
                else if(temp2 > 1 && j >= 2*n - c) {
                    k++;
                    temp2--;
                }
            }
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
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends