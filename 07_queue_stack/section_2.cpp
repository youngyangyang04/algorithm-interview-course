/* ************************************************************************
> File Name:     面试题：用队列实现栈&用栈实现队列 （综合考察对栈和队列的理解）
> Author:        SunXiuyang
> leetcode 题解: https://github.com/youngyangyang04/leetcode-master 
 ************************************************************************/

// 232.用栈实现队列 
// 文字版题解：https://github.com/youngyangyang04/leetcode/blob/master/problems/0232.用栈实现队列.md
class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    /** Push element x to the back of queue. */
    void push(int x) {
        stIn.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        //只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if (stOut.empty()) {
            // 从stIn导入数据直到stIn为空
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        int res = this->pop(); // 直接使用已有的pop函数
        stOut.push(res); // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

// 225.用队列实现栈 
// 文字版题解：https://github.com/youngyangyang04/leetcode/blob/master/problems/0225.用队列实现栈.md
class MyStack {
public:
    queue<int> que1;
    queue<int> que2; // 辅助队列
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        que1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = que1.size();
        size--;
        while (size--) { // 将que1 导入que2，但要留下最后一个元素
            que2.push(que1.front());
            que1.pop();
        }

        int result = que1.front(); // 留下的最后一个元素就是我们要返回的值
        que1.pop();
        que1 = que2; // 再将que2赋值给que1
        while(!que2.empty()) { // 清空que2
            que2.pop();
        }
        return result;
    }

    /** Get the top element. */
    int top() {
        return que1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que1.empty();
    }
};

