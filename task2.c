#include "header.h"

void task2(TEAMNODE** head, char* outPath)
{
    // Calcularea punctelor pentru fiecare echipă
    teamPoints(head);

    // Calcularea valorii minime a punctelor
    float minimVal = minim(*head);

    // Constantă pentru a verifica egalitatea float-urilor
    float const epsilon = 0.0000001;

    TEAMNODE* node = *head;

    // Parcurgerea listei până când dimensiunea ei e cea mai mare putere a lui 2 mai mică decât numărul inițial al echipelor din listă
    while((log2((*head)->listSize) - floor(log2((*head)->listSize))) > epsilon){
        node = *head;
         // Parcurgerea listei pentru a găsi echipa cu punctajul minim
        while(node != NULL){
            if(node->team->points == minimVal){
                // Ștergerea echipei din listă
                deleteTeam(head, node->team);
                (*head)->listSize--;
                // Realocarea memoriei pentru lista de echipe
                *head = realloc(*head, (*head)->listSize);
                break;
            }
            node = node->next;
        }
        // Actualizarea valorii minime a punctelor
        minimVal = minim(*head);
    }
    // Afișarea listei de echipe în fișierul de ieșire
    display(*head, outPath);
}
