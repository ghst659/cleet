#ifndef CLEET_BINARY_TREE_RIGHT_SIDE_VIEW_H_
#define CLEET_BINARY_TREE_RIGHT_SIDE_VIEW_H_
#include <deque>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef std::pair<size_t, TreeNode*> QNode;
class Solution {
private:
  void maybe_enqueue(size_t depth, TreeNode* n, std::deque<QNode>& queue) {
    if (n != nullptr) {
      queue.push_back(QNode(depth, n));
    }
  }
public:
  std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> result;
    std::deque<QNode> queue;
    maybe_enqueue(0, root, queue);
    while (!queue.empty()) {
      QNode item = queue.front();
      queue.pop_front();
      if (item.first + 1 > result.size()) {
        result.push_back(item.second->val);
      }
      size_t next_depth = item.first + 1;
      maybe_enqueue(next_depth, item.second->right, queue);
      maybe_enqueue(next_depth, item.second->left, queue);
    }
    return result;
  }
};

#endif // CLEET_BINARY_TREE_RIGHT_SIDE_VIEW_H_
