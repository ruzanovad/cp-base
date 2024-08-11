#include "number_theory.h"

#include <iostream>
#include <stack>


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