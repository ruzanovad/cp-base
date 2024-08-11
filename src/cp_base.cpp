#include "cp_base.h"

#include <iostream>
#include <stack>

int bin_search::binary_search(vector<int>& a, int x) {
  // у нас ответ в l, полуинтервалы
  int l = 0, r = a.size();
  // l < r-1, при ситуации [l, l+1) возможный ответ уже хранится в l
  while (r - l > 1) {
    int mid = (l + r) / 2;  // [l, r)
    if (a[mid] <= x) {
      l = mid;  // продолжаем искать в [mid, r)
    } else
      r = mid;  // ищем в [l, mid)
  }
  if (a[l] == x)
    return l;
  else
    return -1;
}

int bin_search::first_element_greater_or_equal_to(vector<int>& a, int x) {
  // у нас ответ в r, полуинтервал (l, r]
  int l = -1, r = a.size() - 1;
  // логично искать с конца, потому что ищем бОльший элемент
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (a[mid] >= x) {  // первый элемент больший или равный
      r = mid;
    } else
      l = mid;
  }
  if (a[r] >= x)  // проверяем условие
    return r;
  else
    return -1;
}

int bin_search::last_element_less_or_equal_to(vector<int>& a, int x) {
  int l = 0, r = a.size();  // у нас ответ в l, [l, r)
  while (r - l > 1) {       // логично искать с начала
    int mid = (l + r) / 2;
    if (a[mid] <= x) {
      l = mid;
    } else
      r = mid;
  }
  if (a[l] <= x)  // проверяем условие
    return l;
  else
    return -1;
}

int bin_search::first_element_greater_than(vector<int>& a, int x) {
  int l = -1, r = a.size() - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (a[mid] > x) {  // первый элемент строго больший или равный
      r = mid;  // если нашли строго больший, уменьшаем отрезок поиска до (l, r]
    } else
      l = mid;
  }
  if (a[r] > x)
    return r;
  else
    return -1;
}

double bin_search::invariant_with_precision(double a, double b, double x,
                                            double eps) {
  double l = a, r = b;
  while (r - l > eps) {
    double mid = l + (r - l) / 2;
    if (mid * mid < x) {  // function
      l = mid;
    } else
      r = mid;
  }
  return r;
}

double bin_search::invariant_with_iters(double a, double b, double x) {
  const int C = 200;
  double l = a, r = b;
  for (int i = 0; i < C; ++i) {
    double mid = l + (r - l) / 2;
    if (mid * mid < x) {  // function
      l = mid;
    } else
      r = mid;
  }
  return r;
}

double bin_search::ternary_search_with_iters(double a, double b, int iters) {
  double l = a, r = b;
  for (int i = 0; i < iters; ++i) {
    double m1 = l + (r - l) / 3;
    double m2 = l + 2 * (r - l) / 3;
    double f1 = m1 * m1;
    double f2 = m2 * m2;  // f(m2)
    if (f1 > f2)
      l = m1;
    else
      r = m2;
  }
  return (r + l) / 2;
}

double bin_search::ternary_search_with_precision(double a, double b,
                                                 double eps) {
  double l = a, r = b;
  while (r - l > eps) {
    double m1 = l + (r - l) / 3;
    double m2 = l + 2 * (r - l) / 3;
    double f1 = m1 * m1;
    double f2 = m2 * m2;
    if (f1 > f2)
      l = m1;
    else
      r = m2;
  }
  return (r + l) / 2;
}

double bin_search::golden_section_search(double a, double b, double eps) {
  double l = a, r = b;
  double q = (3 - sqrt(5));
  double m1 = l + q * (r - l);
  double m2 = r - q * (r - l) / 3;
  double f1 = m1 * m1;
  double f2 = m2 * m2;
  while (r - l > eps) {

    if (f1 > f2) {
      l = m1;
      m1 = m2;
      f1 = f2;
      m2 = r - q * (r - l);
      f2 = m2 * m2;
    } else {
      r = m2;
      m2 = m1;
      f2 = f1;
      m1 = l + q * (r - l);
      f1 = m1 * m1;
    }
  }
  return (r + l) / 2;
}

//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
int bin_search::fast_search_in_array(vector<int>& a, int l, int r) {
  int leftIndex = last_element_less_or_equal_to(a, l);
  int rightIndex = first_element_greater_or_equal_to(a, r);
  if (leftIndex == -1) {   // все элементы больше l
    if (rightIndex == -1)  // все элементы меньше r
      return a.size();
    return a[rightIndex] == r ? rightIndex + 1 : rightIndex;
  }
  if (rightIndex == -1) {
    return a[leftIndex] == l ? a.size() - leftIndex - 1 : a.size() - leftIndex;
  }
  return a[rightIndex] == r ? rightIndex + 1
                            : rightIndex -
                                  (a[leftIndex] == l ? a.size() - leftIndex - 1
                                                     : a.size() - leftIndex) +
                                  1;
}

unsigned long long number_theory::gcd(unsigned long long int a,
                                      unsigned long long int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

unsigned long long number_theory::gcd_no_recursion(unsigned long long int a,
                                                   unsigned long long int b) {
  while (b != 0) {
    unsigned long long c = a % b;
    a = b;
    b = c;
  }
  return a;
}

number_theory::gcd_result number_theory::extended_gcd(
    unsigned long long int a, unsigned long long int b) {
  // база
  if (b == 0) {
    return gcd_result(a, 1, 0);
  }
  gcd_result res = extended_gcd(b, a % b);

  gcd_result new_res(res.x, res.q, res.p - (a / b) * res.q);
  return new_res;
}

bool number_theory::is_prime(unsigned long long int x) {
  if (x == 1)
    return false;
  for (unsigned long long i = 2; i * i <= x; ++i) {
    if (x % i == 0)
      return false;
  }
  return true;
}

vector<pair<unsigned long long, unsigned long long>> number_theory::factorize(
    unsigned long long int x) {
  unsigned long long y = x;
  vector<pair<unsigned long long, unsigned long long>> f;
  for (unsigned long long i = 2; i * i <= x; ++i) {
    if (y % i == 0) {
      unsigned long long counter = 0;
      while (y % i == 0) {
        y /= i;
        counter++;
      }
      f.emplace_back(i, counter);
    }
  }
  if (y != 1)
    f.emplace_back(y, 1);
  return f;
}

unsigned long long number_theory::bin_pow(unsigned long long int a,
                                          unsigned long long int p,
                                          unsigned long long int mod) {
  if (p == 0ULL)
    return 0ULL;
  if (p == 1ULL)
    return a % mod;
  unsigned long long pw = bin_pow(a, p >> 1, mod);
  if (p & 1)
    return ((a % mod) * pw) % mod;
  return (pw * pw) % mod;
}

void number_theory::linear_sieve(size_t n) {
  // lp - least prime divisor
  vector<size_t> lp(n, 0);
  vector<size_t> primes;
  for (size_t y = 2; y <= n; ++y) {
    if (lp[y] == 0) {
      lp[y] = y;
      primes.push_back(y);
    }
    for (size_t j = 0;
         j < primes.size() && primes[j] < lp[y] && y * primes[j] <= n; ++j) {
      lp[y * primes[j]] = primes[j];
    }
  }
}

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
