// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "count_and_say.h"
#include "gtest/gtest.h"

#include <iostream>
#include <vector>

namespace {

  // The count-and-say sequence is the sequence of integers with the
  // first five terms as following:
  // 1.     1
  // 2.     11
  // 3.     21
  // 4.     1211
  // 5.     111221
  // 1 is read off as "one 1" or 11.
  // 11 is read off as "two 1s" or 21.
  // 21 is read off as "one 2, then one 1" or 1211.
  // Given an integer n, generate the nth term of the count-and-say sequence.
  // Note: Each term of the sequence of integers will be represented as a string.
  // Example 1:
  // Input: 1
  // Output: "1"
  // Example 2:
  // Input: 4
  // Output: "1211"

  TEST(CountAndSayTest, Examples) {
    Solution s;
    std::vector<int> inputs{7, 1, 8, 2, 3, 4, 5, 6};
    std::vector<std::string> outputs{
      "13112221", "1", "1113213211", "11", "21", "1211", "111221", "312211"
        };
    for (size_t i = 0; i < inputs.size(); ++i) {
      const int n(inputs.at(i));
      const std::string& want(outputs.at(i));
      const std::string& got(s.countAndSay(n));
      // std::cerr << "#" << i << ": n = " << n << "; want = " << want << "; got = " << got << std::endl;
      EXPECT_EQ(got, want);
    }
  }
}  // namespace
