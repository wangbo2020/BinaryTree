#include <iostream>
using namespace std;
#define PRINT(x) cout << #x << endl;

class Node{
public:
  int keyValue;
  Node* leftLeaf;
  Node* rightLeaf;
};


class BinaryTree{
public:
  //Destructor and constructor
  BinaryTree();
  BinaryTree(Node* leaf):root(leaf) {  PRINT(Construction of a binary tree.); }
  ~BinaryTree();
  //Methods
  void Insert(int key);
  Node* Search(int key);
  void DestroyTree();
  void ShowTree();
private:
  //Methods
  void DestroyTree(Node* leaf);
  void Insert(int key, Node* leaf);
  Node* Search(int key, Node* leaf);
  void ShowTree(Node* leaf);
  //Attributes
  Node* root;
};







