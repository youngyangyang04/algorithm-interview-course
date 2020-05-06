/* ************************************************************************
> File Name:     section_6.cpp
> Author:        SunXiuyang
> 微信公众号:    代码随想录
> Created Time:  Mon Feb 24 18:44:56 2020
> Description:   
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
