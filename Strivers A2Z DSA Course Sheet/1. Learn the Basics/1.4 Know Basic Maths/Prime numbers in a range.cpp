//Given two integers M and N, generate all primes between M and N including M and N.
//
//Example 1:
//
//Input:
//M=1,N=10
//Output:
//2 3 5 7
//Explanation:
//The prime numbers between 1 and 10
//are 2,3,5 and 7.
//Example 2:
//
//Input:
//M=2, N=5
//Output:
//2,3,5
//Explanation:
//The prime numbers between 2 and 5 are 
//2,3 and 5.
//
//Your Task:
//You don't need to read input or print anything. Your task is to complete the function primeRange() which takes 2 integer inputs M and N and returns a list of all primes between M and N including N and M.
//
//
//Expected Time Complexity:O(N*sqrt(N))
//Expected Auxillary Space:O(1)
//
//
//Constraints:
//1<=M<=N<=106



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  bool isPrime(int N) {
      
    if (N <= 1)  {
        return false;
    }
    int count = 0;
    int sq = sqrt(N);
    for (int i = 1; i <= sq; i++) {
        if(N % i == 0) {
            if(i != N/i) {
                count += 2;
            }
            else {
                count += 1;
            }
            if(count > 2) {
                break;
            }
        }
    }
    
        if (count == 2)
            return true;
    return false;
      
  }
  
  
    vector<int> primeRange(int M, int N) {
        // code here
        vector<int> ans;
        for(int i = M; i <= N; i++) {
            if(isPrime(i)) {
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends