// -*-mode: c++-*-
#ifndef CLEET_COUNT_AND_SAY_H_
#define CLEET_COUNT_AND_SAY_H_

#include <iostream>
#include <string>
#include <map>

constexpr char DIGITS[] = "0123456789";

class Solution {
private:
  static void close(char seq_char, int seq_count, std::string& result) {
    if (seq_count < 10) {
      result.append(1, DIGITS[seq_count]);
    } else {
      result.append(std::to_string(seq_count));
    }
    result.append(1, seq_char);
  }

  std::map<int, std::string> cache_;

public:
  std::string countAndSay(int n) {
    std::string result{"1"};
    if (n > 1) {
      const auto lookup = cache_.find(n);
      if (lookup != cache_.end()) {
        return lookup->second;
      }

      std::string previous(countAndSay(n - 1));
      result.clear();
      char seq_char = previous.at(0);
      int seq_count = 1;
      for (size_t p = 1; p < previous.size(); ++p) {
        char ch = previous.at(p);
        if (ch == seq_char) {
          ++seq_count;
        } else {
          close(seq_char, seq_count, result);
          seq_char = ch;
          seq_count = 1;
        }
      }
      close(seq_char, seq_count, result);
      cache_.insert(std::map<int, std::string>::value_type(n, result));
    }
    return result;
  }
};
#endif // CLEET_COUNT_AND_SAY_H_
