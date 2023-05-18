#include "header.h"

void task2(TEAMNODE** head, char* outPath)
{
    teamPoints(head);
    float minimVal = minim(*head);
    float const epsilon = 0.0000001;
    TEAMNODE* node = *head;
    while((log2((*head)->listSize) - floor(log2((*head)->listSize))) > epsilon){
        node = *head;
        while(node != NULL)
        {
            if(node->team->points == minimVal)
            {
                deleteTeam(head, node->team);
                (*head)->listSize--;
                *head = realloc(*head, (*head)->listSize);
                break;
            }
            node = node->next;
        }
        minimVal = minim(*head);
    }
    display(*head, outPath);
}

