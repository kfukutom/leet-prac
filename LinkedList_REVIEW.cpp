// Reversing a Linked List
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename Elts>
class EltsList {
  private:
    struct Node {
      Node *next;
      Node *prev;
      Elts datum;
    };
    Node *first;
    Node *last;

  public:
    friend class EltsList; // In order to access private member variable(s).

    EltsList () : first(nullptr), last(nullptr) {}
    ~EltsList() {
      Node *current = first;
      Node *next = nullptr;
      while (current != nullptr) {
        next = current->next;
        delete current; // Memory Allocation
        current = next;
      }
    }
    void push_front(const Node& input);
    void push_back(const Node& input);
    void pop_front();
    void pop_back();
    void pop_all(); // inherits from pop_back()
    Elts back() const;
    Elts front() const; 
    Elts empty() const;
};

// Implementation(s):
template <typename Elts>
Elts EltsList<Elts>::back() const {
    assert(last != nullptr);
    return last->datum;
}

template <typename Elts>
Elts EltsList<Elts>::front() const {
  assert(first != nullptr);
  return first->datum;
}

template <typename Elts>
Elts EltsList<Elts>::empty() const {
  return (first = nullptr && last == nullptr);
}

template<typename Elts>
void EltsList<Elts>::push_front(const Node& input) {
  Node *newNode = new Node(input);
  if (first == nullptr) {
    first = last = newNode;
  } else {
    newNode->next = first;
    first->prev = newNode;
    first = newNode;
  }
}

template<typename Elts>
void EltsList<Elts>::push_back(const Node& input) {
  Node *newNode = new Node(input);
  if (first == nullptr) {
    first = last = nullptr;
  } else {
    newNode->prev = last;
    last->next = newnode;
    last = newNode;
  }
}

template<typename Elts>
void EltsList<Elts>::pop_front() {
  assert(!empty());
  Node *temp = first;
  first = first->next;
  if (first != nullptr) {
    first->prev = nullptr;
  } else { last = nullptr; }
  delete temp;
}
