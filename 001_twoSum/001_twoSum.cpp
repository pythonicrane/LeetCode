#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;
		vector<int>::iterator rec;
		for (int i = 0; i < nums.size(); ++i) {
			if ((rec = find(nums.begin(), nums.end(), target - nums[i])) < nums.end()) {
				if (rec - nums.begin() != i) {
					result.push_back(i);
					result.push_back(rec - nums.begin());
					break;
				}
			}
		}
		return result;
	}
};