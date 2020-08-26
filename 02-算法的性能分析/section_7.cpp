/* ************************************************************************
> File Name:     使用空间换时间思想来解决leetcode上的一道面试题
> Author:        SunXiuyang
> Leetcode刷题攻略: https://github.com/youngyangyang04/leetcode-master 
 ************************************************************************/ 

#include<iostream> 
#include<vector>
using namespace std;

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
void solution(vector<char>& a) {
    char result; // 表示出现次数最多的字母 
    int max_count = 0; // 记录出现的最大次数 
    for(int i = 0; i < a.size(); i++) {
        int num = 0; //记录a[i] 这个字母出现的次数 
        for(int j = 0; j < a.size(); j++) {
            if (a[i] == a[j]) {
                num ++;
            }
        }

        if (num > max_count) { // 如果a[i]出现的次数大于了max_count，就把a[i]和出现的次数都记录下来
            result = a[i];
            max_count = num;
        }
    }

    cout << "出现最多的字母是：" << result << ", 出现的次数："  << max_count << endl;
}

// 时间复杂度：O(n) 
// 空间复杂度：O(1)
void solution_1(vector<char>& a) {
    int record[26] = {0}; // 存放26个字母出现的次数，初始化为0 
    for(int i = 0 ;i < a.size(); i++) {
        record[a[i] - 'a'] ++; //用字符的ASCII来做运算，生成对应的数组下表，数组下表对应的数据就是该字符出现的次数。 
    }
    char result; //记录结果 
    int max_count = 0; //记录出现的最大次数 

    for(int i = 0; i < 26; i++) {
        if (record[i] > max_count) {
            max_count = record[i];
            result = i + 'a'; // 使用ASCII来做运算
        }
    }
    cout << "出现最多的字母是：" << result << ", 出现的次数："  << max_count << endl;
}


// 时间复杂度：O(n^2) 
// 空间复杂度：O(1)
class Solution_1 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (int i = 0; i < magazine.length(); i++) {
            for (int j = 0; j < ransomNote.length(); j++) {
                if(magazine[i] == ransomNote[j]) {
                    ransomNote.erase(ransomNote.begin() + j);
                    break;
                }
            }
        }
        if (ransomNote.length() == 0) {
            return true;
        }
        return false;
    }
};

// 时间复杂度: O(n) 
// 空间复杂度：O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0}; //记录magazine里面字母出现的次数 
        for (int i = 0; i < magazine.length(); i++) {
            record[magazine[i] - 'a'] ++; // 记录26个字母在magazine里出现的次数 
        }

        for (int j = 0; j < ransomNote.length(); j++) {
            record[ransomNote[j] - 'a'] --;
            if (record[ransomNote[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};




int main() {
    // vector<char> a = {'a','a','a','a','a','b','b','b','b','x'};
    // solution_1(a);
    
    cout << Solution().canConstruct("asd", "asffffffjoghjogjho") << endl;
}
