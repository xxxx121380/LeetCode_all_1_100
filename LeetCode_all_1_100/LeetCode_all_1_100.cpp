﻿// LeetCode_all_1_100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include <functional>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}   
};
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}    
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
    //6 Z 字形变换
    string convert(string s, int numRows) {
        if (s.length() <= numRows || numRows == 1)return s;
        string temp = "";
        for (int i = 0; i < numRows; i++) {
            int t = i;
            temp += s[i];
            int a1 = 2 * numRows - 2;
            int a2 = 2 * i;
            while (true) {
                t = t + a1 - a2;
                if (t < s.length())
                {
                    if (a1-a2 != 0) {
                        temp += s[t];
                    }
                }
                else break;
                t = t +a2;
                if (t < s.length()) {
                    if (a2 != 0) {
                        temp += s[t];
                    }
                }
                else break;
            }
        }
        return temp;
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
    int myAtoi(string s) {

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
    //11 盛最多水的容器 
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxA = 0;
        while (left < right) {
            int minHeight = std::min(height[left], height[right]);
            int width = right - left;
            maxA = max(maxA, minHeight * width);
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return maxA;
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
    //14 最长公共前缀
    string longestCommonPrefix(vector<string>& strs) {
        string min;
        auto shortest = std::min_element(strs.begin(), strs.end(), [](const string& s1, const string& s2) {
            return s1.length() < s2.length();
            });
        if (shortest != strs.end()) {
            min = *shortest;
        }
        else return "";
        for (int i = min.size(); i > 0; i--)
        {
            bool flag = true;
            string ss = min.substr(0, i);
            for (const string& str : strs) {
                if (!std::equal(ss.begin(),ss.end(), str.begin(), str.begin() + i)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return min.substr(0, i);
            }
        }
        return "";
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
    //17 电话号码的字母组合
    vector<string> letterCombinations(string digits) {
        vector<string> words;
        string table[8] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
        if (digits.length() == 0)return words;
        for (int i = 0; i < digits.length(); i++) {
            int t = digits[i] - '2';
            vector<string> tempWords=move(words);
            for (int j = 0; j < table[t].length(); j++)
            {
                if (i==0) {
                    string newWord = "";
                    newWord+=table[t][j];
                    words.push_back(newWord);
                }
                else
                {
                    for (int k = 0; k < tempWords.size(); k++) {
                        string newWord = tempWords[k];
                        newWord += table[t][j];
                        words.push_back(newWord);
                    }
                }
            }
        }
        return words;
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
    //26 删除有序数组中的重复项
    int removeDuplicates(vector<int>& nums) {
        vector<int> t;
        t.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (t[t.size()-1]!=nums[i]) {
                t.push_back(nums[i]);
            }
        }
        nums = t;
        return t.size();
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
    //28 找出字符串中第一个匹配项的下标
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length())return -1;
        bool flag = false;
        size_t pos = haystack.find(needle);
        if (pos != std::string::npos) {
            return pos;
        }
        else {
            return -1;
        }
    }
    int divide(int dividend, int divisor) {
        if (dividend == 0)return 0;
        if (dividend == -2147483648 && divisor == 1)return -2147483648;
        int result = 0;
        if (dividend < 0 && divisor < 0)
        {
            if (dividend > divisor)return 0;
            int d = dividend;
            while (d <= divisor&&result< 2147483647) {
                result++;
                d -=divisor;
            }
        }
        else if (dividend > 0 && divisor > 0)
        {
            if (dividend < divisor)return 0;
            int d = dividend;
            while (d >= divisor && result < 2147483647) {
                result++;
                d -= divisor;
            }            
        }
        else if (dividend < 0 && divisor > 0)
        {
            if (dividend+ divisor >0) return 0;
            int d = dividend;
            while (d <= 0 && result > -2147483648) {
                result--;
                d += divisor;
            }
            result++;
        }
        else if (dividend > 0 && divisor < 0)
        {
            if (dividend+divisor < 0) return 0;
            int d = dividend;
            while (d >= 0&& result > -2147483648) {
                result--;
                d += divisor;
            }
            result++;
        }
        return result;
    }
    //31 下一个排列
    void nextPermutation(vector<int>& nums) {
        int flag = 0;
        if (nums.size() == 1)return;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i])
            {
                flag = i;
                break;
            }
        }
        if (flag == 0)
        {
            std::reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = nums.size() - 1; i >= flag; i--) {
            if (nums[flag-1] < nums[i]) {
                int temp = nums[flag-1];
                nums[flag-1] = nums[i];
                nums[i] = temp;
                break;
            }
        }
        std::reverse(nums.begin()+flag,nums.end());
    }
    //33 搜索旋转排序数组
    //最小点就是旋转点
    int findRotateLoc(vector<int>& nums, int left, int right) {
        if (left == right)
            return left;
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])  // 旋转点在右半部
            return findRotateLoc(nums, mid + 1, right);
        else  // 旋转点在左半部
            return findRotateLoc(nums, left, mid);
    }

    int findLoc(vector<int>& nums, int left, int right, int target) {
        if (left > right)
            return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            return findLoc(nums, left, mid - 1, target);
        else
            return findLoc(nums, mid + 1, right, target);
    }
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1 && nums[0] == target)return 0;
        if (nums.size() == 1 && nums[0] != target)return -1;
        int left = 0;
        int right = nums.size() - 1;
        //先找旋转点
        int rotateLoc = findRotateLoc(nums, left, right);
        if (target == nums[rotateLoc]) return rotateLoc;
        //判断target在旋转点左侧还是右侧后再次二分
        if (rotateLoc == 0)  // 没有旋转
            return findLoc(nums, left, right, target);
        else if (target >= nums[0] && target <= nums[rotateLoc - 1])  // 目标在左侧
            return findLoc(nums, 0, rotateLoc - 1, target);
        else  // 目标在右侧
            return findLoc(nums, rotateLoc, right, target);
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
    //36 有效的数独
    bool isValidSudoku(vector<vector<char>>& board) {
        int check1[9] = { 0,0,0,0,0,0,0,0,0 };
        int check2[9] = { 0,0,0,0,0,0,0,0,0 };
        int check3[9] = { 0,0,0,0,0,0,0,0,0 };
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    int t = board[j][i] - '0';
                    t--;
                    if (check1[t] >= 1)return false;
                    else check1[t]++;
                }
                if (board[i][j] != '.') {
                    int t = board[i][j] - '0';
                    t--;
                    if (check2[t] >= 1)return false;
                    else check2[t]++;
                }
                if (board[3 * (i % 3) + j / 3][3 * (i / 3) + j % 3] != '.') {
                    int t = board[3 * (i % 3) + j / 3][3 * (i / 3) + j % 3] - '0';
                    t--;
                    if (check3[t] >= 1)return false;
                    else check3[t]++;
                }
            }
            fill(check1, check1 + 9, 0);
            fill(check2, check2 + 9, 0);
            fill(check3, check3 + 9, 0);
        }
        return true;
    }

    //58 最后一个单词的长度
    int lengthOfLastWord(string s) {
            size_t first = s.find_first_not_of(' ');
            size_t last = s.find_last_not_of(' ');
            s=s.substr(first, (last - first + 1));
            size_t pos = s.find_last_of(' ');
            if (pos != std::string::npos) {
                return s.length() - pos-1; 
            }
            else {
                return s.length();
            }
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
    //67 二进制求和
    string addBinary(string a, string b) {
        int al = a.size();
        int bl = b.size();
        bool flag = false;
        string result;
        while (al >= 0 || bl >= 0)
        {
            if (a[al] == b[bl])
            {
                
            }
            result = a[al] + b[bl];
        }
    }
    //69 x 的平方根 实际上是考你二分
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        long mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (mid * mid > x) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        if (mid * mid <= x)return mid;
        else return mid-1;
        //return floor(sqrt(x));
    }
    //70 爬楼梯 看似斐波那契数列，实际上是DP的基础形式
    int climbStairs(int n) {
        if (n == 1) return 1;
        int a = 1;
        int b = 1;
        int sum = 1;
        for (int i = 0; i < n - 1; i++) {
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }
    //83 删除排序链表中的重复元素
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        auto node = new ListNode(-1);
        auto cur = node;
        while (head != NULL) {
            if (cur == node || cur->val != head->val) {
                cur->next = new ListNode(head->val);
                cur = cur->next;
            }
            head = head->next;
        }
        return node->next;
    }
    //100 相同的树
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
int main()
{
    Solution solution;
    vector<vector<char>>  test = { {'.', '.', '.', '.', '.', '3', '2', '.', '4'}, {'.', '.', '.', '.', '2', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '6', '.', '.', '.', '.', '7', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', '9', '.', '.', '.', '.'}, {'3', '.', '.', '1', '.', '.', '.', '8', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '.'} };
    solution.isValidSudoku(test);
    //solution.divide(7,-3);
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
