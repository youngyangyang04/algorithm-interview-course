/* ************************************************************************
> File Name:     面试题：前 K 个高频元素（优先级队列的经典应用）
> Author:        SunXiuyang
> leetcode 题解: https://github.com/youngyangyang04/leetcode-master 
 ************************************************************************/

// https://github.com/youngyangyang04/leetcode/blob/master/problems/0347.前K个高频元素.md 
// 0347.前K个高频元素 
class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }

        // 找出前K个高频元素
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;

    }
};
// 时间复杂度：O(nlogk)
// 空间复杂度：O(n)

