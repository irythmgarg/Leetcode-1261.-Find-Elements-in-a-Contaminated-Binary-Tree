// 📌 Problem: Recover a Contaminated Binary Tree with Fast O(1) Find using Hash Set
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
    TreeNode* root;               // ✅ Pointer to restored root node
    unordered_set<int> st;       // 🔐 HashSet to store all valid node values

    // 🔧 Constructor to restore the binary tree from contaminated version
    FindElements(TreeNode* root) {
        this->root = root;
        root->val = 0;            // 🧱 Root value is always 0
        st.clear();              // 🧽 Clear any previous values
        st.insert(0);            // ➕ Insert root value
        dfs(root);               // 🔁 Begin DFS traversal
    }

    // 🔁 DFS function to assign correct values and populate set
    void dfs(TreeNode* node) {
        if (!node) return;

        if (node->left) {
            node->left->val = 2 * node->val + 1; // ⬅️ Left child value rule
            st.insert(node->left->val);         // 🗂️ Store in hash set
            dfs(node->left);
        }

        if (node->right) {
            node->right->val = 2 * node->val + 2; // ➡️ Right child value rule
            st.insert(node->right->val);         // 🗂️ Store in hash set
            dfs(node->right);
        }
    }

    // ⚡ Optimized find using unordered_set in O(1)
    bool find(int target) {
        return st.find(target) != st.end(); // ✅ Direct lookup
    }
};
