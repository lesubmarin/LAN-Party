#include "header.h"

void task1(char* inPath, char* outPath, TEAMNODE **head)
{
    FILE *inFile;
    inFile = fopen(inPath, "rt");
    checkErr(inFile, "Eroare la deschiderea fisierului");

    // Alocarea memoriei pentru echipa din capul listei
    (*head)->team = (TEAM *)malloc(sizeof(TEAM));
    checkErr((*head)->team, "Eroare la alocarea memoriei");
    (*head)->next = NULL;

    // Citirea dimensiunii listei de echipe din fișier
    fscanf(inFile, "%d", &(*head)->listSize);
    int numTeams = (*head)->listSize;

    // Parcurgerea fișierului și adăugarea echipelor în listă
    for(int i = 0; i < numTeams; i++){
        // Alocarea memoriei pentru un nou element al listei
        TEAMNODE* newTeam = (TEAMNODE *)malloc(sizeof(TEAMNODE));
        checkErr(newTeam, "Eroare la alocarea memoriei");

        // Alocarea memoriei pentru echipa nou creată
        newTeam->team = (TEAM *)malloc(sizeof(TEAM));
        checkErr(newTeam->team, "Eroare la alocarea memoriei");

        // Alocarea memoriei pentru numele echipei
        newTeam->team->name = (char*) malloc(SIZE * sizeof(char));
        checkErr(newTeam->team->name , "Eroare la alocarea memoriei");
        
        newTeam->next = *head;
        // Citirea dimensiunii echipei și numele echipei din fișier
        fscanf(inFile, "%d", &newTeam->team->teamSize);
        fgetc(inFile);
        fgets(newTeam->team->name, SIZE, inFile);
        newTeam->team->name[strcspn(newTeam->team->name, "\r\n")] = 0;

        // Popularea echipei cu jucătorii din fișier
        populateTeam(inFile, &newTeam);

        // Actualizarea capului listei cu noul nod de echipă
        *head = newTeam;
        (*head)->listSize = numTeams;
    }
    // Afișarea listei de echipe în fișierul de ieșire
    display(*head, outPath);
    
    fclose(inFile);
}