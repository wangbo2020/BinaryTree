#include "BinaryTree.hpp"

BinaryTree::BinaryTree(){
  PRINT(Construction of a binary tree.);
  root = NULL;
}




void BinaryTree::DestroyTree(Node* leaf){
  if (leaf != NULL){
    DestroyTree(leaf->leftLeaf);
    DestroyTree(leaf->rightLeaf);
    delete leaf;
  }
}

void BinaryTree::DestroyTree()
{
  DestroyTree(root);
}

BinaryTree::~BinaryTree(){
  PRINT(Destruction of Binary Tree.);
  DestroyTree();
}



void BinaryTree::Insert(int key, Node* leaf)
{
  if (leaf->keyValue > key)
    {
      if (leaf->leftLeaf != NULL)
	{
	  Insert(key,leaf->leftLeaf);
	}
      else
	{
	  leaf->leftLeaf = new Node;
	  leaf->leftLeaf->keyValue = key;
	  leaf->leftLeaf->leftLeaf = NULL;
	  leaf->leftLeaf->rightLeaf = NULL;
	}
    }
  else if (leaf->keyValue <= key)
    {
      if (leaf->rightLeaf != NULL)
	{
	  Insert(key,leaf->rightLeaf);
	}
      else
	{
	  leaf->rightLeaf = new Node;
	  leaf->rightLeaf->keyValue = key;
	  leaf->rightLeaf->leftLeaf = NULL;
	  leaf->rightLeaf->rightLeaf = NULL;
	}
    } 
}

void BinaryTree::Insert(int key)
{
  cout << "Insertion of " << key << " in the tree." << endl;
  if (root == NULL)
    {
      root = new Node;
      root->keyValue = key;
      root->leftLeaf = NULL;
      root->rightLeaf = NULL;
    }
  else
    {
      Insert(key, root);
    }
}


Node* BinaryTree::Search(int key, Node* leaf){
  if (leaf != NULL)
    {
      if (key == leaf->keyValue)
	{
	  return leaf;
	}
      else if (key < leaf->keyValue)
	{
	  return Search(key, leaf->leftLeaf);
	}
      else
	{
	  return Search(key,leaf->rightLeaf);
	}
    } 
  else
    {
      return NULL;
    } 
}

Node* BinaryTree::Search(int key){
  return Search(key, root);
}

void BinaryTree::ShowTree(Node* leaf)
{
  cout << leaf->keyValue << " ";

  if (leaf->leftLeaf != NULL)
    ShowTree(leaf->leftLeaf);

  if (leaf->rightLeaf != NULL)
    ShowTree(leaf->rightLeaf);
}

void BinaryTree::ShowTree()
{
  if (root != NULL)
    {
      PRINT(Tree content:);
      ShowTree(root);
      cout << endl;
    }
  else
    {
      PRINT(Empty tree.);
    }
}

/*
int main(){
  
  //PRINT(This is a string);
  BinaryTree arbre;
  arbre.ShowTree();
  
  arbre.Insert(1952);
  arbre.Insert(1987);
  arbre.Insert(1990);
  arbre.Insert(52);
  arbre.Insert(14);
  arbre.Insert(60);
  arbre.ShowTree();
  
  //BinaryTree sousArbre = arbre.Search(52);
  //sousArbre.ShowTree();
  //sousArbre.DestroyTree();

  return 0;
}
*/
