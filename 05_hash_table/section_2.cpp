/* ************************************************************************
> File Name:     section_2.cpp
> Author:        SunXiuyang
> leetcode 题解: https://github.com/youngyangyang04/leetcode-master 
 ************************************************************************/

// 0242.有效的字母异位词 
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            record[s[i]-'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

// 0383.赎金信 
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for (int i = 0; i < magazine.length(); i++) {
            record[magazine[i]-'a'] ++;  // 通过recode数据记录 magazine里各个字符出现次数
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            record[ransomNote[j]-'a']--; // 遍历ransomNote，在record里对应的字符个数做--操作
            if(record[ransomNote[j]-'a'] < 0) { // 如果小于零说明 magazine里出现的字符，ransomNote没有
                return false;
            }
        }
        return true;
    }
};

// 0575.分糖果
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        std::vector<int> hashTable(200001, -1); // 初始化一个hashtable，因为数字的大小在范围[-100,000, 100,000]内，所以这个hashtable大小要是200001，这样才能取到200000这个下表索引
        for (int i = 0; i < candies.size(); i++) {
            hashTable[candies[i] + 100000]++;
        }
        int count = 0;
        for (int i = 0; i < hashTable.size(); i++) {
            if (hashTable[i] != -1) {
                count ++;
            }
        }
        int half = candies.size() / 2;
        return count > half ? half : count;
    }
};

