// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "data.h"
#include "binary_tree_right_side_view.h"
#include "gtest/gtest.h"

#include <iostream>
#include <vector>

namespace {

  /*
  // Given a binary tree, imagine yourself standing on the right side
  // of it, return the values of the nodes you can see ordered from
  // top to bottom.
  // Example:
  // Input: [1,2,3,null,5,null,4]
  // Output: [1, 3, 4]
  // Explanation:
  //    1            <---
  //  /   \
  // 2     3         <---
  //  \     \
  //   5     4       <---
  */

  TEST(BinaryTreeRightSideView, Examples) {
    Solution s;
    std::vector<std::string> inputs{
      "[1,2,3,null,5,null,4]",
      "[1,2,3,null,5]",
    };
    std::vector<std::vector<int>> outputs{
      {1, 3, 4},
      {1, 3, 5},
    };
    for (size_t i = 0; i < inputs.size(); ++i) {
      const std::string& nums(inputs.at(i));
      TreeNode* root = data::make_tree(nums.c_str());
      const std::vector<int>& want(outputs.at(i));
      const std::vector<int> got(s.rightSideView(root));
      EXPECT_EQ(got, want);
      data::delete_tree(root);
    }
  }
}  // namespace
