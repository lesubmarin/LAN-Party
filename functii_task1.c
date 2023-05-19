#include "header.h"

void populateTeam(FILE* file, TEAMNODE **newTeam)
{
    (*newTeam)->team->player = (PLAYER*)malloc(sizeof(PLAYER) * ((*newTeam)->team->teamSize));
    checkErr((*newTeam)->team->player, "Eroare la alocarea memoriei");

    for(int j = 0; j < (*newTeam)->team->teamSize; j++){

        (*newTeam)->team->player[j].firstName = (char*) malloc(SIZE * sizeof(char));
        checkErr((*newTeam)->team->player[j].firstName, "Eroare la alocarea memoriei");

        (*newTeam)->team->player[j].secondName = (char*) malloc(SIZE * sizeof(char));
        checkErr((*newTeam)->team->player[j].secondName, "Eroare la alocarea memoriei");
        
        fscanf(file, "%s", (*newTeam)->team->player[j].firstName);
        fscanf(file, "%s", (*newTeam)->team->player[j].secondName);
        fscanf(file, "%d", &(*newTeam)->team->player[j].points);
        
    }
    int c;
    while ((c = fgetc(file)) != EOF && c != '\n'){
        continue;
    }
}