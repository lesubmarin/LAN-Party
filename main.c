#include "header.h"

int main(int argc, char *argv[])
{
    // Extrage argumentele din stdin
    char *taskFilePath = argv[1];
    char *inPath = argv[2];
    char *outPath = argv[3];
    
    // Declară și inițializează variabilele
    const int nr_tasks = 5;
    int* tasksArr = (int*)malloc(nr_tasks*sizeof(int));

    TEAMNODE* head = (TEAMNODE *)malloc(sizeof(TEAMNODE));
    TEAMNODE* head_last8 = (TEAMNODE *)malloc(sizeof(TEAMNODE));

    // Deschide fișierul de task-uri și verifică erorile
    FILE *taskFile;
    taskFile = fopen(taskFilePath, "rt");
    checkErr(taskFile, "Eroare la deschiderea fisierului");

    // Citește task-urile din fișierul de task-uri
    for(int i = 0; i < nr_tasks; i++){
        fscanf(taskFile,"%d",&tasksArr[i]);
    }
    
    // Execută task-urile în funcție de conținutul fișierului de task-uri
    for(int i = 0; i < nr_tasks; i++){
        if(tasksArr[i] == 1){
            switch (i)
            {
            case 0:{
                task1(inPath, outPath, &head);
            }
                break;
            case 1:{
                task2(&head, outPath);
            }
                break;
            case 2:{
                task3(head, outPath, &head_last8);
            }
                break;
            case 3:{
                task4(head_last8, outPath);
            }
                break;
            case 4:{
                task5(head_last8, outPath);
            }
                break;
            default:
                break;
            }
        }
    }

    // Eliberează memoria și închide fișierele deschise
    free(tasksArr);
    free(head);
    free(head_last8);
    
    fclose(taskFile);
    return 0;
}
