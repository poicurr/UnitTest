#include <gtest/gtest.h>

#include <LinkedList.hpp>
#include <string>

TEST(LinkedListCreate, CheckInitialCondition) {
  LinkedList<int> list;
  ASSERT_EQ(nullptr, list.first);
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  ASSERT_EQ(1, list.first->value);
}

class LinkedListTest : public ::testing::Test {
 protected:
  LinkedList<int> list;

  void SetUp() override {
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
  }
};

TEST_F(LinkedListTest, Destruction) {
  list.remove(list.begin());
  ASSERT_EQ(2, list.first->value);
  list.remove(list.begin());
  ASSERT_EQ(3, list.first->value);
  list.remove(list.begin());
  ASSERT_EQ(nullptr, list.first);
}

TEST_F(LinkedListTest, CheckValues) {
  auto iter = list.begin();
  ASSERT_EQ(1, iter->value);
  ASSERT_EQ(2, iter->next->value);
  ASSERT_EQ(3, iter->next->next->value);
  ASSERT_EQ(nullptr, iter->next->next->next);
  ASSERT_EQ(nullptr, list.end());
}
