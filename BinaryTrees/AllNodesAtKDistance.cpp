/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* cur = q.front(); q.pop();
            if(cur->left){ 
                parent[cur->left] = cur;
                q.push(cur->left);
            }
            if(cur->right){
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }
        unordered_map<TreeNode*, bool> vis;
        q.push(target);
        vis[target] = 1;
        while(q.size() && k--){
            int sz = q.size();
            while(sz--){
                TreeNode* cur = q.front(); q.pop();
                if(parent[cur] && !vis[parent[cur]]){
                    q.push(parent[cur]);
                    vis[parent[cur]] = 1;
                }
                if(cur->left && !vis[cur->left]){
                    q.push(cur->left);
                    vis[cur->left] = 1;
                }
                if(cur->right && !vis[cur->right]){
                    q.push(cur->right);
                    vis[cur->right] = 1;
                }
            }
        }
        vector<int> ans;
        while(q.size()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};