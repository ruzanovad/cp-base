#include <gtest/gtest.h>
#include "cp_base.h"

TEST(BinarySearchTest, FindsElement) {
  vector<int> arr = {1, 2, 3, 4, 5};
  int size = 5;

  EXPECT_EQ(bin_search::binary_search(arr, 3), 2);
  EXPECT_EQ(bin_search::binary_search(arr, 1), 0);
  EXPECT_EQ(bin_search::binary_search(arr, 5), 4);
}

TEST(BinarySearchTest, DoesNotFindElement) {
  vector<int> arr = {1, 2, 3, 4, 5};
  int size = 5;

  EXPECT_EQ(bin_search::binary_search(arr, 6), -1);
  EXPECT_EQ(bin_search::binary_search(arr, 0), -1);
}

TEST(GCDTest, BasicCases) {
  EXPECT_EQ(number_theory::gcd(10, 5), 5);
  EXPECT_EQ(number_theory::gcd(54, 24), 6);
  EXPECT_EQ(number_theory::gcd(17, 13), 1);

  EXPECT_EQ(number_theory::gcd_no_recursion(10, 5), 5);
  EXPECT_EQ(number_theory::gcd_no_recursion(54, 24), 6);
  EXPECT_EQ(number_theory::gcd_no_recursion(17, 13), 1);
}

TEST(GCDTest, ZeroCases) {
  EXPECT_EQ(number_theory::gcd(0, 0), 0);  // Typically defined as 0
  EXPECT_EQ(number_theory::gcd(0, 10), 10);
  EXPECT_EQ(number_theory::gcd(10, 0), 10);

  EXPECT_EQ(number_theory::gcd_no_recursion(0, 0),
            0);  // Typically defined as 0
  EXPECT_EQ(number_theory::gcd_no_recursion(0, 10), 10);
  EXPECT_EQ(number_theory::gcd_no_recursion(10, 0), 10);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
