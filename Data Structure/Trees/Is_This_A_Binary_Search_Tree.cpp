#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max(Node *root)
{
    Node *p = root;
    while (p->right)
        p = p->right;
    return p->data;
}

int min(Node *root)
{
    Node *p = root;
    while (p->left)
        p = p->left;
    return p->data;
}

   bool checkBST(Node* root) {
      if (!root->left && !root->right)
          return true;
      else if (!root->left)
      {
          bool b = checkBST(root->right);
          if (b)
          {
              int m = min(root->right);
              if (root->data < m)
                  return true;
          }
          return false;
      }
      else if (!root->right)
      {
          bool b = checkBST(root->left);
          if (b)
          {
              int m = max(root->left);
              if (root->data > m)
                  return true;
          }
          return false;
      }
      else
      {
          bool b = checkBST(root->left) && checkBST(root->right);
          if (b)
          {
              int mi = min(root->right), ma = max(root->left);
              if (root->data > ma && root->data < mi)
                  return true;
          }
          return false;
      }
   }
