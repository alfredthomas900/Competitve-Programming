//Given a 32 bit number X, reverse its binary form and print the answer in decimal.
//
//Example 1:
//
//Input:
//X = 1
//Output:
//2147483648 
//Explanation:
//Binary of 1 in 32 bits representation-
//00000000000000000000000000000001
//Reversing the binary form we get, 
//10000000000000000000000000000000,
//whose decimal value is 2147483648.
//Example 2:
//
//Input:
//X = 5
//Output:
//2684354560 
//Explanation:
//Binary of 5 in 32 bits representation-
//00000000000000000000000000000101
//Reversing the binary form we get, 
//10100000000000000000000000000000,
//whose decimal value is 2684354560.
//Your Task:
//You don't need to read input or print anything. Your task is to complete the function reversedBits() which takes an Integer X as input and returns the answer.
//
//Expected Time Complexity: O(log(X))
//Expected Auxiliary Space: O(1)
//
//Constraints:
//0 <= X < 232



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long X) {
        // code here
        
        int arr[32] = {0};
        int count = 0;
        //creating the binary form of X in arr[]
        while (X > 0) { 
            arr[31 - count] = X % 2;
            count++;
            X = X/2;
        }
        //reversing the binary array
        reverse(arr, arr + 32);

        long long int ans = 0;
        for(int i = 0; i < 32; i++) {
            long long int result = pow(2, 31 - i);
            ans = ans + (arr[i] * result);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends