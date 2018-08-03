// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "data.h"
#include "template.h"
#include "gtest/gtest.h"

#include <iostream>

namespace {

  /*
   *
   */

  TEST(Template, Examples) {
    Solution s;
    std::vector<std::string> inputs{
      "",
    };
    std::vector<std::vector<int>> outputs{
      {},
    };
    for (size_t i = 0; i < inputs.size(); ++i) {
      const std::string& feed(inputs.at(i));
      const std::vector<int>& want(outputs.at(i));

      const std::vector<int> got;
      EXPECT_EQ(got, want);
    }
  }
}  // namespace
