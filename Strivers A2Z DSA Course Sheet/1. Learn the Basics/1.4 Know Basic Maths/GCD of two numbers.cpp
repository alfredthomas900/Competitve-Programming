#include<bits/stdc++.h>
using namespace std;


// Solution 1
int main() {
    int num1 = 4, num2 = 8;
    int ans = 0;
    for(int i = 1; i <= min(num1, num2); i++) {
        if(num1 % i == 0 && num2 % i == 0) {
            ans = i;
        }
    }
    cout << " GCD of num1 and num2 is: ", ans;
}

// TC = O(N)


//Solution 2 - using Euclidean’s theorem.

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
int main()
{

	int a = 4, b = 8;
	cout <<"The GCD of the two numbers is "<<gcd(a, b);
}

//TC = O(logɸmin(a,b)),where ɸ is 1.61.