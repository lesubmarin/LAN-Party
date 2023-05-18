#include "header.h"

void task4(TEAMNODE* head_last8, char* outPath)
{
    FILE* outFile;
    if ((outFile = fopen(outPath, "at")) == NULL) {
        printf("Error opening the output file.\n");
        return;
    }
    
    TEAMNODE* headcopy = head_last8;
    TreeNode* root = NULL;
    while(headcopy->next != NULL){
        root = insert(root, headcopy->team);
        headcopy = headcopy->next;
    }
    fprintf(outFile, "\n");
    fprintf(outFile, "TOP 8 TEAMS:\n");
    reversedInorder(root, outFile);
    fclose(outFile);
    free(headcopy);
}