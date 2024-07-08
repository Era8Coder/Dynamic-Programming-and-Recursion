#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

pair<int,int> solve(TreeNode* root){
    if(root == NULL){
        return {0,0};                           // That is we are at the end of the tree or at leaf
    }

    pair<int,int> left_node_choices = solve(root->left);
    pair<int,int> right_node_choices= solve(root->right);
    pair<int,int> options = {0,0};

    options.first = root->val + left_node_choices.second + right_node_choices.second;               // included the root -> val     // case when we are including the current node 
    options.second= max(left_node_choices.first,left_node_choices.second) + max(right_node_choices.first,right_node_choices.second);                             // when we are not including the current node

    return options;
}

int rob(TreeNode* root){
    pair<int,int> ans = solve(root);
    return max(ans.first,ans.second);
}   

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right= new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right= new TreeNode(1);
    cout << rob(root) << endl;
    return 0;
}