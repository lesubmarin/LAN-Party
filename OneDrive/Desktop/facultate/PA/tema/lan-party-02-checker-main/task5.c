#include "header.h"

void task5(TEAMNODE* head_last8, char* outPath)
{
    FILE* outFile;
    if ((outFile = fopen(outPath, "at")) == NULL) {
        printf("Error opening the output file.\n");
        return;
    }
    
    int const last8 = 8;
    TEAM* head_last8Arry = (TEAM*)malloc(last8 * sizeof(TEAM));
    TEAMNODE* headcopy = head_last8;
    int i = 0;
    while (headcopy->next != NULL) {
        head_last8Arry[i++] = *(headcopy->team);
        headcopy = headcopy->next;
    }

    qsort(head_last8Arry, 8, sizeof(TEAM), compareTeams);
    
    TreeNode* root = NULL;
    for (int i = 0; i < 8; i++){
        root = insertAVL(root, head_last8Arry[i]);
    }

    fprintf(outFile, "\nTHE LEVEL 2 TEAMS ARE:\n");
    printLevel(root, 3, outFile);

    free(head_last8Arry);
    fclose(outFile);
}