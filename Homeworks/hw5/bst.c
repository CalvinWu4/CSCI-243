// File:         bst.c
// Author:       Calvin Wu
// Description: 	This program will read text from the standard input and build a binary search tree containing
// the individual words from the input. The program reads input until no more data is available, counting the 
// frequency of occurrence of each word in the input. Once the input has been exhausted, the tree will be traversed 
// with an in-order traversal to produce an alphabetical list of words with their frequencies.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bst.h"

void insert_word(TreeNode** root, const char *word){
    if (*root == NULL){
        TreeNode *tmp = malloc(sizeof(*tmp));
        tmp->word = strdup(word);
        tmp->frequency = 1;
        tmp->left = NULL;
        tmp->right = NULL;
        *root = tmp;
    }
    else{
        TreeNode *tree = *root;
        int strCompare = strcasecmp(word, tree->word);
        if (strCompare == 0){
 	    (tree->frequency)++;
        }
        else if (strCompare<0){
            insert_word(&tree->left, word);
	}
        else {
            insert_word(&tree->right, word);
	}
    }
}

void traverse_tree(const TreeNode* root){
  if (!root) return;
  traverse_tree(root->left);
  printf("%s  %u\n", root->word, root->frequency);  

int main(int argc, char* argv[]) {
  while (getline(&buf, &len, stdin) > 0){
	  const char* token = strtok(buf, " .,!?\n");
	  if (token != NULL){
		  while(token!= NULL){
			insert_word(&root, token);				
		        token = strtok(NULL, " .,!?\n");	
			}
	  }	
  }
  if (buf != NULL){
	  free(buf);
  }
  traverse_tree(root);
  cleanup_tree(root);
  return(EXIT_SUCCESS);
}
