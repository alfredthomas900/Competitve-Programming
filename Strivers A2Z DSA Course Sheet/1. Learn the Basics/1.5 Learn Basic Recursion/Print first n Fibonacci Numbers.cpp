//Given a number N, find the first N Fibonacci numbers. The first two number of the series are 1 and 1.
//
//Example 1:
//
//Input:
//N = 5
//Output: 1 1 2 3 5
//Example 2:
//
//Input:
//N = 7
//Output: 1 1 2 3 5 8 13
//Your Task:
//Your task is to complete printFibb() which takes single argument N and returns a list of first N Fibonacci numbers.
//
//Expected Time Complexity: O(N).
//Expected Auxiliary Space: O(N).
//Note: This space is used to store and return the answer for printing purpose.
//
//Constraints:
//1<= N <=84


//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution {
public:
    //Function to return list containing first n fibonacci numbers.

    vector<long long> printFibb(int n)
    {
        //code here
        vector<long long> fibbase;
        if (n == 0) {
            fibbase.push_back(0);
            return fibbase;
        }
        else if (n == 1) {
            fibbase.push_back(1);
            return fibbase;
        }
        else {

            vector<long long> fib(n);
            fib[0] = 1;
            fib[1] = 1;
            for (int i = 2; i < n; i++)
                fib[i] = fib[i - 1] + fib[i - 2];
            return fib;
        }

    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking number of elements
        int n;
        cin >> n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);

        //printing the elements of vector
        for (long long i : ans)cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends