#pragma once

template <typename T>
struct LinkedList {
  struct Node {
    Node *prev, *next;
    T value;
    Node(T value) : prev{nullptr}, next{nullptr}, value{value} {}
  };

  Node *first, *last;

  LinkedList() : first{nullptr}, last{nullptr} {};
  ~LinkedList() { clear(); }

  Node* begin() { return first; }
  Node* end() { return nullptr; }

  void insertBefore(Node* node, const T& value) {
    Node* newnode = new Node(value);
    newnode->prev = node ? node->prev : last;
    newnode->next = node;
    if (newnode->prev) newnode->prev->next = newnode;
    if (node) node->prev = newnode;
    if (node == first) first = newnode;
    if (!node) last = newnode;
  }

  void remove(Node* node) {
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    if (node == first) first = node->next;
    if (node == last) last = node->prev;
    delete node;
  }

  void clear() {
    while (first) remove(first);
  }

  void push_back(const T& value) { insertBefore(end(), value); }
  void push_front(const T& value) { insertBefore(begin(), value); }
};
