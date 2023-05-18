#include "header.h"

void task3(TEAMNODE* head, char* outPath, TEAMNODE** head_last8)
{
    FILE* outFile;
    if ((outFile = fopen(outPath, "wt")) == NULL) {
        printf("Error opening the output file.\n");
        return;
    }

    Queue* q = createQueue();
    TEAMNODE* headcopy = head;
    
    while(headcopy->next != NULL){
        removeSpace(headcopy->team->name);
        headcopy = headcopy->next;
    }
    
    headcopy = head;

    while (headcopy != NULL && headcopy->next != NULL) {
        enQueue(q, headcopy->team, headcopy->next->team);
        headcopy = headcopy->next->next;
    }
    headcopy = head;

    while(headcopy->next != NULL){
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
        printQueue(q, outFile);
        fprintf(outFile, "\n");

        while (!isEmptyQueue(q)) {
            if (q->front->team1->points > q->front->team2->points) {
                q->front->team1->points++;
                push(&winners, q->front->team1);
                push(&losers, q->front->team2);
            } else {
                q->front->team2->points++;
                push(&winners, q->front->team2);
                push(&losers, q->front->team1);
            }
            deQueue(q);
        }
        fprintf(outFile, "WINNERS OF ROUND NO:%d\n", round);
        printWinners(winners, outFile);
        if(round < maxRounds){
            fprintf(outFile, "\n");
        }
        deleteStack(&losers);

        Node* winnersCopy = winners;
        while (winnersCopy != NULL && winnersCopy->next != NULL) {
            enQueue(q, winnersCopy->team, winnersCopy->next->team);
            winnersCopy = winnersCopy->next->next;
        }

        if(countTeams(winners) == 8){
            Node* winnersCopy = winners;
            reverse(&winnersCopy);
            while(!isEmpty(winnersCopy)){
                TEAMNODE* newNode = (TEAMNODE*)malloc(sizeof(TEAMNODE));
                newNode->team = winnersCopy->team;
                newNode->next = *head_last8;
                *head_last8 = newNode;
                winnersCopy = winnersCopy->next;
            }
            deleteStack(&winnersCopy);
        }
        round++;
        deleteStack(&winners);
    }
    deleteQueue(q);
    deleteStack(&winners);
    deleteStack(&losers);

    fclose(outFile);
}
