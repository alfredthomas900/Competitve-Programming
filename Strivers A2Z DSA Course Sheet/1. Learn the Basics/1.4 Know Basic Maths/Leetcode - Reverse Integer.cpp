//Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
//
//Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
//
// 
//
//Example 1:
//
//Input: x = 123
//Output: 321
//Example 2:
//
//Input: x = -123
//Output: -321
//Example 3:
//
//Input: x = 120
//Output: 21
// 
//
//Constraints:
//
//-231 <= x <= 231 - 1

class Solution {
    public: 
    int reverse(int x) {
        int num = x;
        int rem, rev = 0;
        while(num != 0) {
            rem = num % 10;
            // Checking for overflow in case of positive & negative values
            // For positive values
            if(rev > INT_MAX/10 || (rev == INT_MAX/10 && rem > 7))
                return 0;
            // For negative values
            if(rev < INT_MIN/10 || (rev == INT_MIN/10 && rem < -8))
                return 0;
            rev = rev * 10 + rem;
            num = num/10;
        } 
        return rev;
    }
};
