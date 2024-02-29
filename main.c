#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
        char *line;
        struct Node *next;
    };

 struct Node *lineArray[25];

void create(char *name){
    FILE *fp=fopen(name,"w+");
    if(fp==NULL){
        printf("file is not open\n");
    }
    else{
        printf("file is open\n");
    }
}
void read(char *name) {
    FILE *fp = fopen(name, "r");
    char in;
    while ((in = getc(fp)) != EOF) {
        printf("%c", in);
    }
    fclose(fp);
}




int main(int argc,char *argv[]){


    char *command=argv[1];
    char *name=argv[2];
    char* source=argv[3];

    if(strcmp(command,"editor")==0){
        create(name);
    }
    if(strcmp(command,"read")==0){
        read(name);
    }


    return 0;
}