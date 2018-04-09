// Implementation of data functions

#include "data.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <vector>
#include <iterator>
#include <iostream>
#include <sstream>

namespace data {

  std::string& trim(const std::set<char>& fluff, std::string* text) {
    auto not_fluff = [&fluff](char c) {return fluff.count(c) == 0;};
    auto content_start = std::find_if(text->begin(), text->end(), not_fluff);
    text->erase(text->begin(), content_start);
    auto is_fluff = [&fluff](char c) {return fluff.count(c) == 1;};
    auto tail_start = std::find_if(text->begin(), text->end(), is_fluff);
    text->erase(tail_start, text->end());
    return *text;
  }

  std::vector<std::string> split(const std::set<char>& fluff, const std::string& text) {
    std::vector<std::string> result;
    if (fluff.size() == 1) {
      std::istringstream text_stream(text);
      auto delim = *(fluff.cbegin());
      std::string token;
      while (std::getline(text_stream, token, delim)) {
        result.push_back(token);
      }
    } else {
      std::string token;
      bool in_word = false;
      for (const auto& ch : text) {
        bool is_fluff = fluff.count(ch) != 0;
        if (is_fluff) {
          if (in_word) {
            result.push_back(token);
            token.clear();
          } 
          in_word = false;
        } else {
          token.push_back(ch);
          in_word = true;
        }
      }
      if (in_word) {
        result.push_back(token);
      }
    }
    return result;
  }

  TreeNode* make_tree(const char* raw_spec) {
    TreeNode* result = nullptr;
    std::string spec(raw_spec);
    std::set<char> fluff{',', ' ', '{', '}', '[', ']'};
    std::vector<std::string> tokens = split(fluff, spec);
    std::vector<TreeNode*> nodes;
    std::transform(tokens.cbegin(), tokens.cend(), std::back_inserter(nodes),
                   [](const std::string& s) -> TreeNode* {
                     if (s == "null") {
                       // std::cerr << "null node: " << std::endl;
                       return nullptr;
                     } else {
                       // std::cerr << "new node: " << s << std::endl;
                       int value = std::stoi(s);
                       return new TreeNode(value);
                     }
                   });
    std::deque<TreeNode*> parents;
    for (size_t i = 0; i < nodes.size(); ++i) {
      auto current = nodes[i];
      if (i == 0) {
        result = current;
      } else if (parents.size() > 0) {
        if (i % 2 != 0) {
          parents.front()->left = current;
        } else {
          parents.front()->right = current;
          parents.pop_front();
        }
      }
      if (current != nullptr) {
        parents.push_back(current);
      }
    }
    return result;
  }

  void delete_tree(TreeNode* root) {
    if (root != nullptr) {
      delete_tree(root->left);
      delete_tree(root->right);
      delete root;
    }
  }

  std::vector<std::string> list_tree(const TreeNode* root) {
    std::vector<std::string> result;
    std::deque<const TreeNode*> queue;
    queue.push_back(root);
    while (queue.size() > 0) {
      const TreeNode* current = queue.front();
      queue.pop_front();
      if (current == nullptr) {
        // result.push_back("NULL");
      } else {
        result.push_back(std::to_string(current->val));
        queue.push_back(current->left);
        queue.push_back(current->right);
      }
    }
    return result;
  }

} // namespace data
