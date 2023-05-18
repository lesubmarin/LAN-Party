#include "header.h"

void checkErr(void* p, const char* message)
{
    if(p == NULL){
        printf("Eroare: %s\n", message);
        exit(-1);
    }
}

void display(TEAMNODE* head, char* outPath)
{
    FILE* outFile;
    outFile = fopen(outPath, "wt");
    checkErr(outFile, "Eroare la deschiderea fisierului");

	while(head->next != NULL){
		fprintf(outFile, "%s\n", head->team->name);
		head = head->next;
	}
    fclose(outFile);
}

void removeSpace(char* s)
{
    int length = strlen(s);
    if (length > 0 && s[length-1] == ' '){
        s[length-1] = '\0';
    }
}

int max(int a, int b)
{
    return ((a > b) ? a:b);
}
