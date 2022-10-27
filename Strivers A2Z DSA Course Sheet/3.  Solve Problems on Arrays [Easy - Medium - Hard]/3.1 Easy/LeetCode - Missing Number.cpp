// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.



// Example 1:

// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
// Example 2:

// Input: nums = [0,1]
// Output: 2
// Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
// Example 3:

// Input: nums = [9,6,4,2,3,5,7,0,1]
// Output: 8
// Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.


class Solution {
public:
	int missingNumber(vector<int>& nums) {

		int a = 0;
		int n = nums.size();

		int b = 0;

		// For xor of all array elements
		for (int i = 0; i < n; i++)
			a = a ^ nums[i];
		// For xor of all the elements from 1 to n+1
		for (int i = 1; i <= n; i++)
			b = b ^ i;

		return (a ^ b);
	}
};



// OR Optimal Solution


class Solution {
public:
	int missingNumber(vector<int>& nums) {

		int n = nums.size();

		// Will hold XOR of all elements and numbers from 1 to n
		int xor1;

		// Will have only single set bit of xor1
		int set_bit_no;

		int x = 0; // missing
		// int y = 0; // repeating

		xor1 = nums[0];
		// Get the XOR of all the array elements
		for (int i = 1; i < n; i++) {
			xor1 = xor1 ^ nums[i];
		}

		// XOR the previous result with numbers from 1 to n
		for (int i = 1; i <= n; i++) {
			xor1 = xor1 ^ i;
		}

		// place the (RSB) rightmost set bit in set_bit_no
		set_bit_no = xor1 & ~(xor1 - 1);

		// Now, divide the elements into two sets/buckets by comparing the RSB of xor1 with the bit at the same position in each element.
		// Also, get XORs of two sets. The two XORs are the output elements

		// compare the set_bit_no with the bits of the array elements
		for (int i = 0; i < n; i++) {
			if (nums[i] & set_bit_no) {
				// arr[i] belongs to the first set
				x = x ^ nums[i];
			}
		}

		// compare the set_bit_no with the bits of the numbers from 1 to N
		for (int i = 1; i <= n; i++) {
			if (i & set_bit_no) {
				// i belongs to first set
				x = x ^ i;
			}
		}
		return x;

	}
};