/* ************************************************************************
> File Name:     使用leetcode的正确姿势
> Author:        SunXiuyang
> Leetcode刷题攻略: https://github.com/youngyangyang04/leetcode-master 
 ************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()) {
                return {iter->second, i};
                break;
            }
            map.emplace(nums[i], i);
        }
        return {};
    }
};
