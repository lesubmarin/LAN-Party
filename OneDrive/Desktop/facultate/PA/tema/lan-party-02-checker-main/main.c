#include "header.h"

int main(int argc, char *argv[])
{
    char *taskFilePath = argv[1];
    char *inPath = argv[2];
    char *outPath = argv[3];
    
    int tasksArr[6];
    const int nr_tasks = 5;

    TEAMNODE* head = (TEAMNODE *)malloc(sizeof(TEAMNODE));
    TEAMNODE* head_last8 = (TEAMNODE *)malloc(sizeof(TEAMNODE));

    FILE *taskFile;
    taskFile = fopen(taskFilePath, "rt");
    checkErr(taskFile, "Eroare la deschiderea fisierului");

    for(int i = 0; i < nr_tasks; i++){
        fscanf(taskFile,"%d",&tasksArr[i]);
    }
    
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
    return 0;
}
