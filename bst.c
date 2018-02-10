#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

/// Helper function for the build_tree function, recursively traverse through a subtree to find the proper place for the new node
///
/// @param root a root of a subtree
/// @param new the node to be inserted
///
void build_tree_helper(TreeNode** root, TreeNode* new) {
   if(!(*root)) {
      *root = new;
      return;
   }
   if(new->data < (*root)->data) build_tree_helper(&(*root)->left, new);
   else if(new->data > (*root)->data) build_tree_helper(&(*root)->right, new);
}

void build_tree(TreeNode** root, const int elements[], const int count) {
  int i;
  TreeNode* new;
  for(i = 0; i < count; i++) {
      new = (TreeNode*)malloc(sizeof(TreeNode));
      new->left = NULL;
      new->right = NULL;
      new->data = elements[i];
      build_tree_helper(root, new);
  }
}

void traverse(const TreeNode* root, const TraversalType type) {
  if (!root) return;
  switch(type) {
  case PREORDER:
    printf("%d\n", root->data);
    traverse(root->left, PREORDER);
    traverse(root->right, PREORDER);
    break;
  case INORDER:
    traverse(root->left, INORDER);
    printf("%d\n", root->data);
    traverse(root->right, INORDER);
    break;
  case POSTORDER:
    traverse(root->left, POSTORDER);
    traverse(root->right, POSTORDER);
    printf("%d\n", root->data);
    break;
  }
}

void cleanup_tree(TreeNode* root) { //using a post-order traversal to free the nodes
  if (!root) return;
  cleanup_tree(root->left);
  cleanup_tree(root->right);
  free(root);
}

int main(int argc, char* argv[]) {
  if(argc == 1) { 
    printf("%s\n", "Usage: bst #");
    exit(EXIT_FAILURE);
  }
  int count = atoi(argv[1]);
  int elements[count];
  printf("Enter %d integer values to place in tree:\n", count);
  int i;
  int get;
  for (i = 0; i < count; i++) {
    scanf("%d", &get);
    if (get < 0) {
      printf("%s\n", "# must be greater than 0");
      exit(EXIT_FAILURE);
    }
    elements[i] = get;
  }
  printf("%s\n", "Input values:");
  for (i = 0; i < count; i++) {
    printf("%d\n", elements[i]);
  }
  TreeNode* root;
  root = NULL;
  build_tree(&root, elements, count);
  printf("%s\n", "Preorder:");
  traverse(root, PREORDER);
  printf("%s\n", "Inorder:");
  traverse(root, INORDER);
  printf("%s\n", "Postorder:");
  traverse(root, POSTORDER);
  cleanup_tree(root);
  return 0;
}
