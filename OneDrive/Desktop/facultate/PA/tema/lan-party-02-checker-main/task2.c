#include "header.h"

void delete(TEAMNODE** head, TEAM* team) {
    if (*head == NULL) {
        return;
    }
    TEAMNODE* headcopy = *head;
    if (headcopy->team == team) {
        (*head)->next->listSize = (*head)->listSize;
        *head = (*head)->next;
        free(headcopy);
        return;
    }
    TEAMNODE* prev = *head;
    while (headcopy != NULL) {
        if (headcopy->team == team) {
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

}
void task2(TEAMNODE** head, float** medie, char* outPath)
{
    teamPoints(head);
    float minimVal = minim(*head);
    float const epsilon = 0.0000001;
    TEAMNODE* node = *head;
    while((log2((*head)->listSize) - floor(log2((*head)->listSize))) > epsilon){
            node = *head;
        while (node != NULL)
        {
            if (node->team->points == minimVal)
            {
                delete(head, node->team);
                (*head)->listSize--;
                break;
            }
            node = node->next;
        }
    
        minimVal = minim(*head);
    }
    display(*head, outPath);
}

