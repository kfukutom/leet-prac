#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

template <typename Elts>
class EltsTree {
  private:
  struct Node {
    Node *left;
    Node *right;
    Elts datum;
  }
  Node *root;

  public:
  void deleteTree(Node *nptr) {
    if (nptr != nullptr) {
      deleteTree(nptr->left);
      deleteTree(nptr->right);
      delete nptr;
    }
  }

  EltsTree () : root(nullptr) {}

  ~EltsTree () {
    deleteTree(root);
  }

  // Level Traversal
  void levelTraversal(Node *root) {
    if (root == nullptr) { return; }
    queue<Node*> Q;
    Q.push(root);

    while(!Q.empty()) {
      int levelSize = Q.size();
      for (int i = 0; i < levelSize; ++i) {
        Node *current = Q.front(); // First in Queue
        Q.pop();
        std::cout << current->datum << std::endl;
        if (current->left) {
          Q.push(current->left);
        }
        if (current->right) {
          Q.push(current->right);
        }
      }
      std::cout << std::endl; 
    }
  }
};