#include "header.h"

void task4(TEAMNODE* head_last8, char* outPath)
{
    // Deschide fișierul de output și verifică erorile
    FILE* outFile;
    if((outFile = fopen(outPath, "at")) == NULL){
        printf("Error opening the output file.\n");
        return;
    }
    
    TEAMNODE* headcopy = head_last8;
    TreeNode* rootBST = NULL;

    // Construirea arborelui binar de căutare (BST) cu ultimele 8 echipe rămase în competiție
    while(headcopy->next != NULL){
        rootBST = insert(rootBST, headcopy->team);
        headcopy = headcopy->next;
    }

    // Afișarea echipelor din arborele BST în ordine descrescătoare
    fprintf(outFile, "\n");
    fprintf(outFile, "TOP 8 TEAMS:\n");
    reversedInorder(rootBST, outFile);
    
    fclose(outFile);
    free(headcopy);
}
