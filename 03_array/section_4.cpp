/* ************************************************************************
> File Name:     section_4.cpp
> Author:        SunXiuyang
> 微信公众号:    代码随想录
 ************************************************************************/

// 移除元素 暴力解法 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--; // 因为下表i以后的数值都向前移动了一位，所以i也向前移动一位
                size--;// 此时数组的大小-1
            }
        }
        return size;

    }
};

// 移除元素 快慢指针解法
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0; // index为 慢指针
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {  // i 为快指针
            if (val != nums[fastIndex]) { //将快指针对应的数值赋值给慢指针对应的数值
                nums[slowIndex++] = nums[fastIndex]; 注意这里是slowIndex++ 而不是slowIndex--
            }
        }
        return slowIndex;
    }
};

// 删除重复数组中重复项 快慢指针解法

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // 别忘记空数组的判断
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < (nums.size() - 1); fastIndex++){
            if(nums[fastIndex] != nums[fastIndex + 1]) { // 发现和后一个不相同
                nums[++slowIndex] = nums[fastIndex + 1]; //slowIndex = 0 的数据一定是不重复的，所以直接 ++slowIndex
            }
        }
        return slowIndex + 1; //别忘了slowIndex是从0开始的，所以返回slowIndex + 1
    }
};


