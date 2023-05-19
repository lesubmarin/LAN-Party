#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <math.h>

#define SIZE 1000

typedef struct Player
{
    char* firstName;
    char* secondName;
    int points;
}PLAYER;

typedef struct Team{
    int teamSize;
    char* name;
    PLAYER* player;
    float points;
}TEAM;

typedef struct TeamNode{
    int listSize;
    TEAM* team;
    struct TeamNode* next;
}TEAMNODE;

typedef struct NodeQueue{
	TEAM* team1;
    TEAM* team2;
	struct NodeQueue* next;
}NodeQueue;

typedef struct Q{
NodeQueue* front; 
NodeQueue* rear;
}Queue;

typedef struct Node{
    TEAM* team;
    struct Node* next;
}Node;

typedef struct N{
    int height;
    TEAM* team;
    struct N* left; 
    struct N* right;
}TreeNode;


//FUNCTII GLOBALE:
void display(TEAMNODE* head, char* outPath);
void checkErr(void* p, const char* message);
void removeSpace(char* str);
void removeSpaceList(TEAMNODE** head);
int max(int a, int b);
void postorderDelTree(TreeNode* root);

//FUNCTII TASK 1:
void task1(char* inPath, char* outPath, TEAMNODE** head);
void populateTeam(FILE* file, TEAMNODE **newTeam);

//FUNCTII TASK2:
void task2(TEAMNODE** node, char* outPath);
float minim(TEAMNODE* node);
void teamPoints(TEAMNODE** head);
void deleteTeam(TEAMNODE** head, TEAM* team);

//FUNCTII TASK3:
void task3(TEAMNODE* head, char* outPath, TEAMNODE** head_last8);
Queue* createQueue();
void enQueue(Queue* q, TEAM* blueteam, TEAM* redteam);
void deQueue(Queue* q);
int isEmptyQueue(Queue* q);
void deleteQueue(Queue* q);
TEAM* top(Node* top);
void push(Node** top, TEAM* newteam);
TEAM* pop(Node** top);
int isEmpty(Node* top);
void deleteStack(Node** top);
void printQueue(Queue* q, FILE* file);
void printWinners(Node* winners, FILE* file);
void reverse(Node** node);
int countTeams(Node* winners);
void updateWinnersLosers(Queue** q, Node** winners, Node** losers);
void last8_save(Node* winners, TEAMNODE** head_last8);

//FUNCTII TASK4:
void task4(TEAMNODE* head_last8, char* outPath);
TreeNode* newNode(TEAM* team);
TreeNode* insert(TreeNode* node, TEAM* head_last8);
void reversedInorder(TreeNode* root, FILE* file);

//FUNCTII TASK5:
void task5(TEAMNODE* head_last8, char* outPath);
int compareTeams(const void* team1, const void* team2);
int nodeHeight(TreeNode* root);
TreeNode* rightRotation(TreeNode* z);
TreeNode* leftRotation(TreeNode* z);
TreeNode* LRRotation(TreeNode* z);
TreeNode* RLRotation(TreeNode* z);
TreeNode* insertAVL(TreeNode* node, TEAM team);
void printLevel(TreeNode* root, int level, FILE* file);