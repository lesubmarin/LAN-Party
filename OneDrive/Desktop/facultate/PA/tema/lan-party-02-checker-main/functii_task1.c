#include "header.h"

void populateTeam(FILE* file, TEAMNODE **newTeam)
{
    (*newTeam)->team->player = (PLAYER*)malloc(sizeof(PLAYER) * ((*newTeam)->team->teamSize));
    for(int j = 0; j < (*newTeam)->team->teamSize; j++){
        (*newTeam)->team->player[j].firstName = (char*) malloc(SIZE * sizeof(char));
        (*newTeam)->team->player[j].secondName = (char*) malloc(SIZE * sizeof(char));
        fscanf(file, "%s", (*newTeam)->team->player[j].firstName);
        fscanf(file, "%s", (*newTeam)->team->player[j].secondName);
        fscanf(file, "%d", &(*newTeam)->team->player[j].points);
    }
    int c;
    while ((c = fgetc(file)) != EOF && c != '\n'){
        continue;
    }
}