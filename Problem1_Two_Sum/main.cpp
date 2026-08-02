#include <iostream>
#include <vector>


/*
https://leetcode.com/problems/two-sum/
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {

	struct Candi {
		int num;
		int index;
	public: 
		Candi(int n, int idx) : num{ n }, index{idx} {}
	};
	vector<Candi> candidates{};


	for (int i{}; i < nums.size(); ++i) {
		if (nums[i] <= target) {
			for (Candi option : candidates) {
				if (option.num + nums[i] == target) {
					vector<int> idxs{ option.index, i };
					return idxs;
				}
			}
			candidates.push_back(Candi{ nums[i], i});
		}
	}
}


int main()
{
	vector<int> nums{ 3,2,4 };
	int target = 6;
	vector<int> answer = twoSum(nums, target);
	for (int a : answer) {
		cout << a << ' ';
	}
}