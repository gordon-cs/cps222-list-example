// Tests for List class (list.cc)
#include <iostream>  // nullptr
#include "gtest/gtest.h"
#include "list.h"

TEST(list, empty) {
  List mylist;
  EXPECT_TRUE(mylist.empty());
  EXPECT_EQ(mylist.first(), nullptr);
  EXPECT_EQ(mylist.next(mylist.first()), nullptr);
}

TEST(list, oneItem) {
  List mylist;
  mylist.push_front(5);
  EXPECT_FALSE(mylist.empty());
  EXPECT_NE(mylist.first(), nullptr);
  EXPECT_EQ(mylist.next(mylist.first()), nullptr);
  EXPECT_EQ(mylist.value(mylist.first()), 5);
}

TEST(list, pushPop) {
  List mylist;
  mylist.push_front(10);
  EXPECT_EQ(mylist.pop_front(), 10);
  EXPECT_TRUE(mylist.empty());
}

TEST(list, push2Pop2) {
  List mylist;
  mylist.push_front(15);
  mylist.push_front(20);
  EXPECT_EQ(mylist.value(mylist.next(mylist.first())), 15);
  EXPECT_EQ(mylist.value(mylist.first()), 20);
  EXPECT_EQ(mylist.pop_front(), 20);
  EXPECT_FALSE(mylist.empty());
  EXPECT_EQ(mylist.pop_front(), 15);
  EXPECT_TRUE(mylist.empty());
}

TEST(list, insert) {
  List mylist;
  mylist.push_front(3);
  void *first = mylist.first();
  mylist.insert_after(6, first);
  EXPECT_EQ(mylist.value(mylist.next(first)), 6);
  EXPECT_EQ(mylist.pop_front(), 3);
  EXPECT_EQ(mylist.pop_front(), 6);
}
