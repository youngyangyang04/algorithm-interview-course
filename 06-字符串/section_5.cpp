/* ************************************************************************
> File Name:     第五节：经典KMP算法精讲（2）&面试题实现 strStr()
> Author:        SunXiuyang
> leetcode 题解: https://github.com/youngyangyang04/leetcode-master 
 ************************************************************************/

// 0028.实现strStr() 
class Solution {
public:
    void preKmp(int* next, const string& s){
        next[0] = -1;
        int j = -1;
        for(int i = 1; i < s.size(); i++){
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        preKmp(next, needle);

        int j = -1;
        for (int i = 0; i < haystack.size(); i++) {
            while(j >= 0 && haystack[i] != needle[j + 1]) {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1]) {
                j++;
            }
            if (j == (needle.size() - 1) ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};


