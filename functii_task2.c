#include "header.h"

void deleteTeam(TEAMNODE** head, TEAM* team)
{
    if(*head == NULL){
        return;
    }
    TEAMNODE* headcopy = *head;
    if(headcopy->team == team){
        (*head)->next->listSize = (*head)->listSize;
        *head = (*head)->next;
        free(headcopy);
        return;
    }
    TEAMNODE* prev = *head;
    while(headcopy != NULL){
        if(headcopy->team == team){
            prev->next = headcopy->next;
            free(headcopy);
            return;
        }
        prev = headcopy;
        headcopy = headcopy->next;
    }
}

float minim(TEAMNODE* node)
{
    float minim = FLT_MAX;
    while(node->next != NULL){
        if(node->team->points < minim){
            minim = node->team->points;
        }
        node = node->next;
    }
    return minim;
}

void teamPoints(TEAMNODE** head)
{
    TEAMNODE* headcopy = *head;
    while(headcopy != NULL){
    for(int i = 0; i < headcopy->team->teamSize; i++){
            headcopy->team->points += headcopy->team->player[i].points;
        }
    headcopy->team->points /= headcopy->team->teamSize;
    headcopy = headcopy->next;
    }
    free(headcopy);
}
