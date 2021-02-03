/* ------------------------------------------------------------------|
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

 

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了95.95%的用户
*	内存消耗：11.5 MB, 在所有 C++ 提交中击败了90.12%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int maxProduct(vector<int>& nums) {
    ////创建两个数组存储当前最大值和最小值，因为考虑负号存在的情况
    //vector<int> fmin(nums), fmax(nums);
    //for (int i = 1; i < nums.size(); i++) {
    //    //最小值数组存放fmin(i-1)*nums[i]、nums[i]、fmax(i-1)*nums[i]三个中的最小值
    //    //最大值数组存放这三个数中的最大值
    //    fmin[i] = min(fmax[i - 1] * nums[i], min(nums[i], fmin[i - 1] * nums[i]));
    //    fmax[i] = max(fmax[i - 1] * nums[i], max(nums[i], fmin[i - 1] * nums[i]));
    //}
    //return *max_element(fmax.begin(), fmax.end());
    int premin = nums[0];
    int premax = nums[0];
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int nowmin = min(premin * nums[i], min(nums[i], premax * nums[i]));
        int nowmax = max(premin * nums[i], max(nums[i], premax * nums[i]));
        res = max(res, nowmax);
        premin = nowmin;
        premax = nowmax;
    }
    return res;
}