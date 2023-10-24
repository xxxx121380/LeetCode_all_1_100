// LeetCode_all_1_100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#include <string>
#include <regex>
#include <unordered_map>
#include <limits>
#include <stdexcept>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}   
};

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
    //2 两数相加
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto node = new ListNode(-1);
        auto cur = node;
        int t1 = 0;//为0标签
        while (l1 != NULL || l2 != NULL || t1) {
            int a1 = 0;
            int a2 = 0;
            if (l1 != NULL) { a1 = l1->val; l1 = l1->next; }
            if (l2 != NULL) {
                a2 = l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode((a1 + a2 + t1) % 10);
            t1 = (a1 + a2 + t1) / 10;
            cur = cur->next;
        }
        return node->next;
    }
    //4 寻找两个正序数组的中位数1
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        int targetIndex = size / 2;
        int i = 0;
        int j = 0;
        int current=0;
        int previous=0;
        while (i + j <= targetIndex) {
            previous = current;
            if (i < nums1.size() && (j >= nums2.size() || nums1[i] <= nums2[j])) {
                current = nums1[i];
                i++;
            }
            else {
                current = nums2[j];
                j++;
            }
        }
        double result;
        if (size % 2 == 0) {
            result = (previous + current) / 2.0;
        }
        else {
            result = current;
        }
        return result;
    }    
    //4 寻找两个正序数组的中位数2
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        merged.reserve(nums1.size() + nums2.size());
        int size = nums1.size() + nums2.size();
        int i = 0;
        int j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (i + j > size / 2)break;
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            }
            else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()) {
            if (i + j > size / 2)break;
            merged.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()) {
            if (i + j > size / 2)break;
            merged.push_back(nums2[j]);
            j++;
        }
        double result;
        if (size % 2 == 0) {
            result = (merged[i + j - 1] + merged[i + j - 2]) / 2.0;
        }
        else
        {
            result = merged[i + j - 1];

        }
        return result;
    }
    //5 最长回文子串
    string longestPalindrome(string s) {
        int length = s.length();
        for (int i = length; i > 1; i--)
        {
            for (int j = 0; j <= length - i; j++)
            {
                bool flag = true;
                for (int k = 0; k < i/2; k++) {
                    if (s[j+k] != s[j+i - k-1])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == false)continue;
                else return s.substr(j, i);
            }
        }
        return s.substr(0,1);
    }
    //7 整数翻转
    //without limit, we can use stol
    int reverse(int x) {
        bool sign = x < 0;
        x = abs(x);
        string str=to_string(x);
        std::reverse(str.begin(), str.end());
        if (str.size()>10)return 0;
        if (str.size() == 10)
        {
            if (!sign && str > "2147483647") return 0;
            if (sign && str > "2147483648") return 0;
        }
        return sign ? -1 * stoi(str) : stoi(str);
    }
    //9 回文数
    bool isPalindrome(int x) {
        if (x < 0)return false;
        string numStr = to_string(x);
        int length = numStr.length();
        int i = 0;
        while (i < length / 2) {
            if (numStr[i] != numStr[length-1 - i])return false;
            i++;
        }
        return true;
    }
    //13 罗马数字转整数
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0;
        int prevValue = 0; 
        for (char ch : s) {
            int currValue = romanMap[ch];
            if (currValue > prevValue) {
                result += currValue - 2 * prevValue;
            }
            else {
                result += currValue;
            }
            prevValue = currValue;
        }

        return result;
    }
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
    //21 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        auto node = new ListNode(-1);
        auto cur = node;
        while (list1 != NULL || list2 != NULL) {
            if (list2 == NULL || (list1!=NULL && list1->val <= list2->val))
            {
                cur->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else if (list1 == NULL ||(list2 != NULL && list1->val >= list2->val))
            {
                cur->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            cur = cur->next;
        }
        return node->next;
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
    //66 加一
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if (digits[size - 1] != 9) {
            digits[size - 1]++;
            return digits;
        }
        else {
            vector<int> result;
            result.push_back((digits[size-1] + 1) % 10);
            int t = (digits[size - 1] + 1) / 10;
            for (int i = size - 2; i >= 0; i--) {
                int s = digits[i] + t;
                result.insert(result.begin(), s % 10);
                t = s / 10;
            }
            if(t==1)result.insert(result.begin(), t);
            return result;
        }
    }
};
int main()
{
    Solution solution;
    string s = "babad";

    cout << solution.longestPalindrome(s);
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
