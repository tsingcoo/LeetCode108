//
// Created by 王青龙 on 2017/3/17.
//

#ifndef LEETCODE108_SOLUTION_H
#define LEETCODE108_SOLUTION_H

#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums){
        if(nums.size() ==0){
            return nullptr;
        }
        if(nums.size() ==1){
            return new TreeNode(nums[0]);
        }
        int middle = nums.size()/2;
        auto root = new TreeNode(nums[middle]);

        std::vector<int> leftInts(nums.begin(), nums.begin()+middle);
        std::vector<int> rightInts(nums.begin()+middle+1, nums.end());


        root->left = sortedArrayToBST(leftInts);
        root->right = sortedArrayToBST(rightInts);

        return root;
    }
};

#endif //LEETCODE108_SOLUTION_H
