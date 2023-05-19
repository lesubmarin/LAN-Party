#include "header.h"

int compareTeams(const void* team1, const void* team2) 
{
    const TEAM* t1 = (const TEAM*)team1;
    const TEAM* t2 = (const TEAM*)team2;

    if (t1->points > t2->points)
        return -1;
    if (t1->points < t2->points)
        return 1;

    return strcmp(t2->name, t1->name);
}

int nodeHeight(TreeNode* root)
{
    if(root == NULL){
        return -1;
    }
    else return root->height;
}

TreeNode* rightRotation(TreeNode* z)
{
    TreeNode* y = z->left;
    TreeNode* T3 = y->right;

    y->right = z;
    z->left = T3;

    z->height = max(nodeHeight(z->left), nodeHeight(z->right)) + 1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;

    return y;
}

TreeNode* leftRotation(TreeNode* z)
{
    TreeNode* y = z->right;
    TreeNode* T2 = y->left;

    y->left = z;
    z->right = T2;

    z->height = max(nodeHeight(z->left), nodeHeight(z->right)) + 1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;

    return y;
}

TreeNode* LRRotation(TreeNode* z)
{
    z->left = leftRotation(z->left);
    return rightRotation(z);
}

TreeNode* RLRotation(TreeNode* z)
{
    z->right = rightRotation(z->right);
    return leftRotation(z);
}

TreeNode* insertAVL(TreeNode* node, TEAM team)
{
     if (node == NULL){
        node = (TreeNode*)malloc(sizeof(TreeNode));
        checkErr(node, "Eroare la alocarea memoriei");

        node->team = (TEAM*)malloc(sizeof(TEAM));
        checkErr(node->team, "Eroare la alocarea memoriei");
        
        memcpy(node->team, &team, sizeof(TEAM));
        node->height = 0;
        node->left = node->right = NULL;
        return node;
    }
    if(team.points < node->team->points){
        node->left = insertAVL(node->left, team);
    }
    else if(team.points > node->team->points){
        node->right = insertAVL(node->right, team);
    }
    else{
        int compareResult = strcmp(team.name, node->team->name);
        if(compareResult < 0){
            node->left = insertAVL(node->left, team);
        } 
        else if(compareResult > 0){
            node->right = insertAVL(node->right, team);
        }

    }
    node->height = 1 + max(nodeHeight(node->left), nodeHeight(node->right));
    int k = (nodeHeight(node->left) - nodeHeight(node->right));

    if (k > 1 && compareTeams(&team, node->left->team) > 0){
        return rightRotation(node);
    }

    if (k < -1 && compareTeams(&team, node->right->team) < 0){
        return leftRotation(node);
    }

    if (k > 1 && compareTeams(&team, node->left->team) < 0){
        return LRRotation(node);
    }

    if (k < -1 && compareTeams(&team, node->right->team) > 0){
        return RLRotation(node);
    }
    return node;
}

void printLevel(TreeNode* root, int level, FILE* file)
{
    if(root == NULL){
        return;
    }
    if(level == 1){
        fprintf(file, "%s\n", root->team->name);
    }
    else if(level > 1){
        printLevel(root->right, level-1, file);
        printLevel(root->left, level-1, file);
    }
}
