#include "header.h"

void task3(TEAMNODE* head, char* outPath, TEAMNODE** head_last8)
{
    // Deschiderea fișierului de output și verificarea erorilor
    FILE* outFile = fopen(outPath, "wt");
    checkErr(outFile, "Eroare la deschiderea fisierului");

    Queue* q = createQueue();
    TEAMNODE* headcopy = head;
    
    // Eliminarea spațiului de la finalul numelor echipelor din lista de echipe (dacă există)
    removeSpaceList(&headcopy);
    
    headcopy = head;
    while(headcopy != NULL && headcopy->next != NULL){
        // Adăugarea perechilor de echipe în coadă
        enQueue(q, headcopy->team, headcopy->next->team);
        headcopy = headcopy->next->next;
    }
    headcopy = head;

    while(headcopy->next != NULL){
        // Afișarea numelor echipelor în fișierul de ieșire
        fprintf(outFile, "%s\n", headcopy->team->name);
        headcopy = headcopy->next;
    }
    free(headcopy);

    fprintf(outFile, "\n");

    int round = 1;
    Node* losers = NULL;
    Node* winners = NULL;
    int maxRounds = log2(head->listSize);

    while(round <= maxRounds){
        losers = NULL;
        winners = NULL;

        fprintf(outFile, "--- ROUND NO:%d\n", round);
        // Afișarea cozii de meciuri în fișierul de ieșire
        printQueue(q, outFile);
        fprintf(outFile, "\n");

        // Actualizarea câștigătorilor și învinșilor
        updateWinnersLosers(&q, &winners, &losers);

        fprintf(outFile, "WINNERS OF ROUND NO:%d\n", round);
        // Afișarea câștigătorilor rundei în fișierul de ieșire
        printWinners(winners, outFile);

        if(round < maxRounds){
            fprintf(outFile, "\n");
        }
        deleteStack(&losers);

        Node* winnersCopy = winners;
        while (winnersCopy != NULL && winnersCopy->next != NULL){
            // Adăugarea perechilor de echipe câștigătoare în coadă
            enQueue(q, winnersCopy->team, winnersCopy->next->team);
            winnersCopy = winnersCopy->next->next;
        }

        // Salvarea ultimelor 8 echipe într-o altă listă pentru task-urile următoare
        last8_save(winners, head_last8);

        round++;
        deleteStack(&winners);
    }
    deleteQueue(q);
    deleteStack(&winners);
    deleteStack(&losers);

    fclose(outFile);
}
