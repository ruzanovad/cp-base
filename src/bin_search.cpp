#include "bin_search.h"

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