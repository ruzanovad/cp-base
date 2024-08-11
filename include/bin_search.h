// #ifndef cp_base
// #define cp_base

#include <cmath>
#include <string>
#include <vector>

using namespace std;

namespace bin_search {
// Returns index of value if found and -1 else
// Полуинтервал [l, r)
// Необходимо следить за переполнением, если что l + (r - l)/2
int binary_search(vector<int>& a, int x);

// Аналог lower_bound, из библиотеки <algorithm>
// Берется l = -1, r = n-1, потому что мы смотрим полуинтервал (l, r]
int first_element_greater_or_equal_to(vector<int>& a, int x);

// Аналог upper_bound в плюсах, из библиотеки <algorithm>
// l = -1 и r = n работает, (интервал), но надо понимать инвариант на отрезке, чтобы
// четко выполнялся
int first_element_greater_than(vector<int>& a, int x);

int last_element_less_or_equal_to(vector<int>& a, int x);

int fast_search_in_array(vector<int>& a, int l, int r);

double invariant_with_precision(double a, double b, double x,
                                double eps = 1e-9);

// с ограниченным количеством итераций
// инвариант на месте функции ( многочлен... и тд )
double invariant_with_iters(double a, double b, double x);

// Пусть дана функция f(x), унимодальная на некотором отрезке [l;r].
//
//  Под унимодальностью понимается один из двух вариантов.
//  Первый: функция сначала строго возрастает, потом достигает максимума (в одной точке или целом отрезке),
//  потом строго убывает.
//  Второй вариант, симметричный: функция сначала убывает убывает, достигает минимума, возрастает.
//  В дальнейшем мы будем рассматривать первый вариант, второй будет абсолютно симметричен ему.
//
// Требуется найти максимум функции f(x) на отрезке [l;r].
//  (Здесь ищем минимум)
double ternary_search_with_iters(double a, double b, int iters = 200);

// Ищем минимум унимодальной функции
double ternary_search_with_precision(double a, double b, double eps = 1e-6);

// https://neerc.ifmo.ru/wiki/index.php?title=%D0%9F%D0%BE%D0%B8%D1%81%D0%BA_%D1%81_%D0%BF%D0%BE%D0%BC%D0%BE%D1%89%D1%8C%D1%8E_%D0%B7%D0%BE%D0%BB%D0%BE%D1%82%D0%BE%D0%B3%D0%BE_%D1%81%D0%B5%D1%87%D0%B5%D0%BD%D0%B8%D1%8F
// https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%B7%D0%BE%D0%BB%D0%BE%D1%82%D0%BE%D0%B3%D0%BE_%D1%81%D0%B5%D1%87%D0%B5%D0%BD%D0%B8%D1%8F
//  Мучаемся чтобы не пересчитывать функцию сто раз (если тяжелое вычисление)
double golden_section_search(double a, double b, double eps = 1e-6);
}  // namespace bin_search

// #endif  // cp_base