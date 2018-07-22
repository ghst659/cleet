// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include "data.h"
#include "gtest/gtest.h"
#include <limits.h>
#include <vector>
#include <string>
#include <set>
#include <utility>

namespace {
  TEST(UtilityTest, Trimming) {
    std::set<char> fluff{'[', ']', '{', '}'};
    std::vector<std::pair<const char*, const char*> > test_cases = {
      {"[1,2,3]", "1,2,3"},
      {"{1,2}", "1,2"},
      {"[1,NULL,2,3,4]", "1,NULL,2,3,4"}, 
      {"[1,NULL,2,3,4}}", "1,NULL,2,3,4"}, 
    };
    for (const auto text_want : test_cases) {
      std::string text(text_want.first);
      data::trim(fluff, &text);
      std::string want(text_want.second);
      EXPECT_EQ(want, text);
    }
  }

  TEST(UtilityTest, Splitting) {
    std::set<char> fluff{',', ' ', '[', ']', '{', '}'};
    std::string text("[1,2,,NULL,4 5}");
    auto got = data::split(fluff, text);
    std::vector<std::string> want{"1", "2", "NULL", "4", "5"};
    EXPECT_EQ(want.size(), got.size());
    for (size_t i = 0; i < want.size(); ++i) {
      EXPECT_EQ(want[i], got[i]);
    }
  }

  TEST(TreeNodeTest, TreeList) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(4);
    std::vector<std::string> text = data::list_tree(root);
    std::vector<std::string> want{"1", "2", "3", "5", "4"};
    EXPECT_EQ(want.size(), text.size());
    for (size_t i = 0; i < want.size(); ++i) {
      EXPECT_EQ(want[i], text[i]);
    }
    data::delete_tree(root);
  }

  TEST(TreeNodeTest, TreeConstruction) {
    const char* spec = "[1,null,2,3,null,4]";
    TreeNode* root = data::make_tree(spec);
    EXPECT_EQ(1, root->val);
    EXPECT_EQ(nullptr, root->left);
    EXPECT_EQ(2, root->right->val);
    // EXPECT_EQ(3, root->right->left->val);
    data::delete_tree(root);
  }

  TEST(ListNodeTest, ListConstruction) {
    const char* spec = "[10,11,12]";
    ListNode* head = data::make_list(spec);
    EXPECT_EQ(10, head->val);
    EXPECT_EQ(11, head->next->val);
    EXPECT_EQ(12, head->next->next->val);
    EXPECT_EQ(nullptr, head->next->next->next);
  }

}  // namespace
