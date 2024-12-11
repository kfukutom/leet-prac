#include <iostream>
#include <vector>
using namespace std;

template <typename Elts>
class EltsList {
    private:
    struct Node {
        Node *next;
        Node *prev;
        Elts datum;
    }
    Node *first;
    Node *last;

    public:
    template <typename Iter_type>
    class Iterator {
        friend class EltsList;
        private:
        Node *nodeptr;
        // above grants access for us to utilize the private class
        // variables in scope of the EltsList constructor!
        public:
        Iter_type max_element(Iter_type begin, Iter_type end); // Let's go implement this!
        Iter_type operator*() const;
    }   
    EltsList() : first(nullptr), last(nullptr) {}
    ~EltsList() {
        Node *nodeptr = first;
        for (; nodeptr && nodeptr != nullptr; nodeptr=nodeptr->next) {
            pop_front();
        }
    }
    operator=(const Node& lhs) {
        Node *nodeptr;
        if (lhs.first == nullptr) { return; }
        while (nodeptr != nullptr) {
            nodeptr->next = new Node;
            nodeptr = nodeptr->next;
            nodeptr->datum = head->data;
            head->next = nullptr;
            nodeptr = nodeptr->next;
        }
        return * this;
    }

    void pop_front();
    void pop_back();
    void pop_at(const int& index);
    void push_front(Node *node);
}

template<typename Elts>
void EltsList<Elts>::pop_front() {
    if (first == nullptr) { return; }
    Node *temp = first;
    first = first->next;
    if (first != nullptr) {
        first->prev = nullptr;
    }
    delete temp;
}

template<typename Elts>
void EltsList<Elts>::pop_back() {
    if (last == nullptr) { return; }
    Node *temp = last;
    last = last->prev;
    if (last != nullptr) {
        last->next = nullptr;
    }
    delete temp;
}

template <typename Elts>
void EltsList<Elts>::pop_at(const int& index) {
    if (first == nullptr || last == nullptr) { return; }
    Node *temp = first;
    int local_count = 0;
    for (; temp && local_count != index-1; temp=temp->next) {
        ++local_count;
    }
    if (index == 0) {
        pop_front();
        return;
    } else if (nodeptr == last) {
        pop_back();
        return;
    } else { // take care of external edge case(s)!
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp; // dynamically allocate our memory!
    }
}

template <typename Elts>
template <typename Iter_type>
Iter_type EltsList<Elts>::Iterator<Iter_type>::max_element(Iter_type first, Iter_type last) {
    if (begin == end) { return end; }
    Iter_type max = begin;
    for (; begin != end; ++begin) {
        if (*max < *begin) {
            max = begin;
        }
    }
    return max;
}

template<typename Elts>
template <typename Iter_type>
Iter_type EltsList<Elts>::Iterator<Iter_type>::operator*() const {
    // dereference operator
    assert(!(!nodeptr));
    return (nodeptr->datum);
}