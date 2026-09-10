/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    pair<int,int> generate(TreeNode* node)
    {
        if(!node->left && !node->right)
        {
            ans++;
            return {node->val,1};
        }
        else if(node->left && node->right)
        {
            pair<int,int> x=generate(node->left);
            pair<int,int> y=generate(node->right);
            int sum=x.first+y.first+node->val;
            int n=x.second+y.second+1;
            if(sum/n == node->val)
                ans++;
            return {sum,n};
        }
        else if(node->left)
        {
            pair<int,int> x=generate(node->left);
            int sum=x.first+node->val;
            int n=x.second+1;
            if(sum/n == node->val)
                ans++;
            return {sum,n};
        }
        else
        {
            pair<int,int> x=generate(node->right);
            int sum=x.first+node->val;
            int n=x.second+1;
            if(sum/n == node->val)
                ans++;
            return {sum,n};
        }
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> x = generate(root);
        return ans;
    }
};