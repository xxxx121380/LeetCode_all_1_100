// LeetCode_all_1_100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
    //1 两数之和
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp;
        for (int i = 0; i < nums.size() - 1; i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target)
                {
                    temp.push_back(i);
                    temp.push_back(j);
                    break;
                }
        return temp;
    };
    //16 最接近三数的和
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int temp = nums[0] + nums[1] + nums[2];
        if (size == 3)return temp;
        int min = 99999;
        int result = temp;
        for (int i = 0; i < size - 2; i++)
        {
            int j = i + 1;
            int k = size - 1;
            while (j < k)
            {
                temp = nums[i] + nums[j] + nums[k];
                int tt = abs(temp - target);
                if (tt < min) {
                    min = tt;
                    result = temp;
                }
                if (temp == target) return result;
                if (temp < target) {
                    j++;
                }
                else {
                    k--;
                }

            }
        }
        return result;
    }

    //20 有效的括号
    bool isValid(string s) {
        int l = s.length();
        if (l % 2==1)return false;
        stack<char> inStack;
        for (int i = 0; i < l; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')           
                inStack.push(s[i]);
            else {
                if (inStack.size()!=0&&(inStack.top()+1==s[i] ||inStack.top()+2== s[i]))
                    inStack.pop();
                else return false;
            }
        }
        if (inStack.size() == 0)return true;
        else return false;
    }

    //27 移除元素
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it = nums.begin();
        while (it != nums.end()) {
            if (*it == val) {
                it = nums.erase(it);
            }
            else {
                it++;
            }
        }
        return nums.size();
    }
    //35 搜索插入位置
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            else if (target < nums[mid]) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = { 3,2,2,3 };
    int val = 3;
    cout << solution.removeElement(nums, val);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
