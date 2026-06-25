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
    	vector<vector<int>> ans;
	void solve(TreeNode* root, vector<int> path,int currSum,int targetSum) {
		if (!root)
			return;
		
		path.push_back(root->val);
		currSum+=root->val;
		if (!root->left && !root->right) {
            if(currSum==targetSum)
			ans.push_back(path);
			return;
		}
		solve(root->left, path,currSum,targetSum);
		solve(root->right, path,currSum,targetSum);
		
	}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        	vector<int>path;
		
		solve(root, path,0,targetSum);
		return ans;
    }
};
