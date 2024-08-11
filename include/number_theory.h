// TODO wtf если оставить ifndef, то не воспринимает
// number_theory.h

// #ifndef cp_base
// #define cp_base
#include <cmath>
#include <string>
#include <vector>

using namespace std;

namespace number_theory {
unsigned long long gcd(unsigned long long a, unsigned long long b);

unsigned long long gcd_no_recursion(unsigned long long a, unsigned long long b);

struct gcd_result {
  unsigned long long x;  // сам нод
  unsigned long long p;  // коэффициент при a
  unsigned long long q;  // коээфициент при b
  explicit gcd_result(unsigned long long x1 = 0ULL, unsigned long long p1 = 0,
                      unsigned long long q1 = 0)
      : x(x1), p(p1), q(q1) {}
};

gcd_result extended_gcd(unsigned long long a, unsigned long long b);

bool is_prime(unsigned long long x);

vector<pair<unsigned long long, unsigned long long>> factorize(
    unsigned long long x);

unsigned long long bin_pow(unsigned long long a, unsigned long long p,
                           unsigned long long mod);

// Решето Эратосфена (линейное)
// В lp равенство 0 обозначает простоту, а неравенство 0 обозначает составное число и его
// наименьший простой делитель
void linear_sieve(size_t n);

}  // namespace number_theory

// #endif