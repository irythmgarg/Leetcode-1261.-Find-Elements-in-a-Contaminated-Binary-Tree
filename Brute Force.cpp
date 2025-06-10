// ✍️ Author: Ridham Garg (Thapar Institute of Engineering and Technology)
// 📧 Email: Ridhamgarg000@gmail.com

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
class FindElements {
public:
    TreeNode* root;  // ✅ Store the reconstructed root

    // 🔧 Constructor: Restore original tree values from contaminated tree
    FindElements(TreeNode* root) {
        this->root = root;
        root->val = 0;  // 🔢 Root is always 0 by problem definition
        dfs(root);      // 🌳 Reconstruct tree
    }

    // 🔁 DFS to reconstruct the tree values as per rules
    void dfs(TreeNode* node) {
        if (!node) return;

        if (node->left) {
            node->left->val = 2 * node->val + 1; // ⬅️ Left child rule
            dfs(node->left);
        }

        if (node->right) {
            node->right->val = 2 * node->val + 2; // ➡️ Right child rule
            dfs(node->right);
        }
    }

    // 🔍 Helper function to find target value in tree using DFS
    bool fin(TreeNode* node, int target) {
        if (!node) return false;
        if (node->val == target) return true;

        return fin(node->left, target) || fin(node->right, target);
    }

    // ✅ Find function exposed to user
    bool find(int target) {
        return fin(root, target); // Call DFS from reconstructed root
    }
};
