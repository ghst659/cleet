// -*-mode: c++-*-
#ifndef CLEET_DATA_H_
#define CLEET_DATA_H_

#include <vector>
#include <string>
#include <set>

struct ListNode {  // Definition for singly-linked list.
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {  // Definition for a binary tree node.
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

namespace data {
  // Trims fluff characters from the beginning and end of the text, returning text.
  std::string& trim(const std::set<char>& fluff, std::string* text);
  // Splits text on fluff characters, returning a list of tokens between delimiters.
  // Consecutive delimiters count as one delimiter.
  std::vector<std::string> split(const std::set<char>& fluff, const std::string& text);
  // Creates a TreeNode* tree based on the char* specification, returning the root.
  TreeNode* make_tree(const char* spec);
  // Deletes the TreeNode* trees, bottoms-up.
  void delete_tree(TreeNode* root);
  // Returns a list of TreeNode values in BFS order.
  std::vector<std::string> list_tree(const TreeNode* root);
} // namespace data
#endif // CLEET_DATA_H_
