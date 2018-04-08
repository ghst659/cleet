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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

namespace data {
  // UTILITIES
  std::string& trim(const std::set<char>& fluff, std::string* text);
  std::vector<std::string> split(const std::set<char>& fluff, const std::string& text);
  // SUBSTANCE
  TreeNode* make_tree(const char* spec);
  void delete_tree(TreeNode* root);
  std::vector<std::string> list_tree(const TreeNode* root);
} // namespace data
#endif // CLEET_DATA_H_
