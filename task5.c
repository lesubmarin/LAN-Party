#include "header.h"

void task5(TEAMNODE* head_last8, char* outPath)
{
    // Deschide fișierul de output și verifică erorile
    FILE* outFile;
    if ((outFile = fopen(outPath, "at")) == NULL) {
        printf("Error opening the output file.\n");
        return;
    }
    
    int const last8 = 8;
    TEAM* head_last8Arry = (TEAM*)malloc(last8 * sizeof(TEAM));
    TEAMNODE* headcopy = head_last8;
    int i = 0;
    while(headcopy->next != NULL){
        // Copierea echipei într-un vector
        head_last8Arry[i++] = *(headcopy->team);
        headcopy = headcopy->next;
    }

    // Sortarea echipei în ordine crescătoare
    qsort(head_last8Arry, 8, sizeof(TEAM), compareTeams);
    
    TreeNode* rootAVL = NULL;
    for (int i = 0; i < 8; i++){
        // Inserarea echipei în arborele AVL
        rootAVL = insertAVL(rootAVL, head_last8Arry[i]);
    }

    fprintf(outFile, "\nTHE LEVEL 2 TEAMS ARE:\n");
    // Afișarea nivelului 2 al arborelui AVL în fișierul de ieșire
    printLevel(rootAVL, 3, outFile);

    fclose(outFile);

    // Eliberarea memoriei și ștergerea arborelui AVL
    postorderDelTree(rootAVL);
    free(head_last8Arry);
}