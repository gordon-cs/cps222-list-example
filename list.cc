#include <iostream>  // nullptr
#include "list.h"

List::List() {
  _first = nullptr;
}

List::~List() {
  while (!empty()) {
    pop_front();
  }
}

bool List::empty() {
  return _first == nullptr;
}

void * List::first() {
  return (void *)_first;
}

void * List::next(void *ptr) {
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
  Node *tmpPtr = _first;
  _first = new Node();
  _first->_value = value;
  _first->_next = tmpPtr;
}

int List::pop_front() {
  int retval = _first->_value;
  Node *tmpPtr = _first;
  _first = _first->_next;
  delete tmpPtr;
  return retval;
}
