#include "header.h"

TreeNode* newNode(TEAM* team)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    checkErr(node, "Eroare la alocarea memoriei");

    node->team = team;
    node->left = node->right = NULL;
    return node;
}

TreeNode* insert(TreeNode* node, TEAM* head_last8)
{
    if(node == NULL){
        return newNode(head_last8);
    }
    if(head_last8->points < node->team->points){
        node->left = insert(node->left, head_last8);
    }
    else if(head_last8->points > node->team->points){
        node->right = insert(node->right, head_last8);
    }
    else{
        int compareResult = strcmp(head_last8->name, node->team->name);
        if(compareResult < 0){
            node->left = insert(node->left, head_last8);
        } 
        else if(compareResult > 0){
            node->right = insert(node->right, head_last8);
        }
    }
    return node;
}

void reversedInorder(TreeNode* root, FILE* file) 
{
    if (root == NULL){
        return;
    }
    reversedInorder(root->right, file);
    fprintf(file, "%-34s-  %.2f\n", root->team->name, root->team->points);
    reversedInorder(root->left, file);
}
