#include <iostream>  // nullptr
#include "list.h"

List::List() {
  first_ = nullptr;
}

List::~List() {
  while (!empty()) {
    pop_front();
  }
}

bool List::empty() {
  return first_ == nullptr;
}

void *List::first() {
  return (void *)first_;
}

void *List::next(void *ptr) {
  if (ptr == nullptr) {
    return nullptr;
  } else {
    return (void *) (((Node *)ptr)->_next);
  }
}

int List::value(void *ptr) {
  return ((Node *)ptr)->_value;
}

void List::insert_after(int value, void *ptr) {
  // TODO
}

void List::delete_after(void *ptr) {
  // TODO
}

void List::push_front(int value) {
  Node *tmpPtr = first_;
  first_ = new Node();
  first_->_value = value;
  first_->_next = tmpPtr;
}

int List::pop_front() {
  int retval = first_->_value;
  Node *tmpPtr = first_;
  first_ = first_->_next;
  delete tmpPtr;
  return retval;
}
