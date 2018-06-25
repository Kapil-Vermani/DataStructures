#include <iostream>
template<typename T>
struct Node
{
  public:
    Node(T val):data(val),right(nullptr),left(nullptr)
    {
    
    }
    T data;
    Node<T>* right;
    Node<T>* left;
};
template<typename T>
class GenericTree
{
private:
  Node<T>* root;
void inorderTraversal(Node<T>* root)
{
  if(root != nullptr)
  {
    inorderTraversal(root->left);
    std::cout<<root->data<<std::endl;
    inorderTraversal(root->right);
  }
}
void insertIntoTree(int data,Node<T>*& root)
{
  if(root == nullptr)
  {
    root = new Node<int>(data);
    return;
  }
  else if(data < (root)->data)
  {
    insertIntoTree(data,root->left);
  }
  else
  {
    insertIntoTree(data,root->right);
  }
}
Node<T>* deleteNode(Node<T>* root,T data) 
{
  if(root == nullptr)
  {
    return root;
  }
  else if(data < root->data)
  {
    root->left = deleteNode(root->left,data);
  }
  else if(data > root->data)
  {
    root->right = deleteNode(root->right,data);
  }
  else
  {
    //Three cases

    //When node to be deleted is leaf node
    if((root->left == nullptr) &&
       (root->right == nullptr))
    {
       delete root;
       root = nullptr;
    }
    //When node to be deleted have only one child
    else if(root->left==nullptr)
    {
      Node<T>* temp = root->right;
      delete root;
      root = temp;
    } 
    else if(root->right==nullptr)
    {
      Node<T>* temp = root->left;
      delete root;
      root = temp;
    } 
    else   //both nodes have children
    {
      //find minimum in right subtree which will be the leftmost child
      Node<T>* temp = root->right;
      Node<T>* prev = root->right;
      while(temp->left !=  nullptr)
      {
        prev = temp;
        temp = temp->left;
      }
      root->data = temp->data;
      delete temp;
      temp = nullptr; 
      prev->left = temp;     
    }  
  }
  return root;

}
public:
GenericTree():root(nullptr) {}

void insert(T data)
{
  insertIntoTree(data,root);
}
void print()
{
  inorderTraversal(root);
}
void deleteNode(T data)
{
  root = deleteNode(root,data);
}
//void deleteNode()
};
int main() {
  GenericTree<int> newTree;
  newTree.insert(4);
  newTree.insert(13);
  newTree.insert(33);
  newTree.insert(11);
  newTree.insert(14);
  newTree.print();    
  //newTree.deleteNode(11);
 // std::cout<<"Printing tree after deleting leaf node(11) "<<std::endl;
 // newTree.print();
  //newTree.deleteNode(33);
  //std::cout<<"Printing tree after deleting node with one child(33) "<<std::endl;
  //newTree.print();
  newTree.deleteNode(13);
  std::cout<<"Printing tree after deleting node with two children(13) "<<std::endl;
  newTree.print();
  return 0;
}