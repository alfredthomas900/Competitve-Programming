//Given a string S, check if it is palindrome or not.
//
//Example 1:
//
//Input: S = "abba"
//Output: 1
//Explanation: S is a palindrome
//Example 2:
//
//Input: S = "abc" 
//Output: 0
//Explanation: S is not a palindrome
// 
//
//Your Task:
//You don't need to read input or print anything. Complete the function isPalindrome()which accepts string S and returns an integer value 1 or 0.
//
//Expected Time Complexity: O(Length of S)
//Expected Auxiliary Space: O(1)
//
//
//Constraints:
//1 <= Length of S<= 105



//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int isPalindrome(string S) {
	   // Your code goes here
	    int n = S.length();
	    string rev = S;
	    char temp;
	    string str = S;
	    int start = 0, end = n - 1;
	    for(int i = 0; i < n/2; i++)
	    {
	        temp = str[start];
	        str[start] = str[end];
	        str[end] = temp;
	        start++;
	        end--;
	        //swap(rev[i], rev[n - i - 1]);
	    }
	    if(S == str)
	        return 1;
	    else
	        return 0;
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends