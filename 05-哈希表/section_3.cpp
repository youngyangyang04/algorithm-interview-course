/* ************************************************************************
> File Name:     section_3.cpp
> Author:        SunXiuyang
> Leetcode刷题攻略: https://github.com/youngyangyang04/leetcode-master 
 ************************************************************************/

// 349. 两个数组的交集 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

