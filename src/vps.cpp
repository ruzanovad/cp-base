#include "vps.h"
#include <stack>


bool vps::is_valid(string& s) {
  stack<char> st;
  for (auto& c : s) {
    if (c == '(') {
      st.push(')');
    } else if (c == '{') {
      st.push('}');
    } else if (c == '[') {
      st.push(']');
    } else if (st.empty() || st.top() != c) {
      return false;
    } else {
      st.pop();
    }
  }
  return st.empty();
}

/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
*/
bool vps::is_valid_with_fillings(string& s) {
  int low = 0, high = 0;
  for (auto& c : s) {
    low += 2 * (c == '(') - 1;
    high += 2 * (c == ')') - 1;
    if (high < 0)
      return false;
    low = max(low, 0);
  }
  return low == 0;
}

int vps::depth(string& s) {
  int count = 0;
  int max_num = 0;
  for (char c : s) {
    if (c == '(') {
      count++;
      if (max_num < count)
        max_num = count;
    } else if (c == ')') {
      count--;
    }
  }
  return max_num;
}
