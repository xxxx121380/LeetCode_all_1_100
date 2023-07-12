// LeetCode_all_1_100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <regex>
#include <unordered_map>
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
    solution.isPalindrome(11);
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
