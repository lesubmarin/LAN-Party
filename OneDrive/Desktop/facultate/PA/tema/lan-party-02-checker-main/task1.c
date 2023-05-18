#include "header.h"

void task1(char* inPath, char* outPath, TEAMNODE **head)
{
    FILE *inFile;
    inFile = fopen(inPath, "rt");
    checkErr(inFile, "Eroare la deschiderea fisierului");

    (*head)->team = (TEAM *)malloc(sizeof(TEAM));
    (*head)->next = NULL;
    fscanf(inFile, "%d", &(*head)->listSize);
    int numTeams = (*head)->listSize;
    for(int i = 0; i < numTeams; i++){
        TEAMNODE* newTeam = (TEAMNODE *)malloc(sizeof(TEAMNODE));
        newTeam->team = (TEAM *)malloc(sizeof(TEAM));
        newTeam->team->name = (char*) malloc(SIZE * sizeof(char));
        newTeam->next = *head;
        fscanf(inFile, "%d", &newTeam->team->teamSize);
        fgetc(inFile);
        fgets(newTeam->team->name, SIZE, inFile);
        newTeam->team->name[strcspn(newTeam->team->name, "\r\n")] = 0;
        populateTeam(inFile, &newTeam);
        *head = newTeam;
        (*head)->listSize = numTeams;
    }
    display(*head, outPath);
    fclose(inFile);
}