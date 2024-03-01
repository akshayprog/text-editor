#include <stdio.h>
#include <stdlib.h>

struct Node {
  char* line;
  struct Node* line; 
};

struct Node *lineArray[25];

void create() {
    FILE *file = fopen("file.txt", "w+");
  if (file == NULL) {
    printf("File not created\n");
  } else {
    printf("File is created\n");
  }
}
void createWithName(char* name) {
    FILE *file = fopen(name, "w+");
  if (file == NULL) {
    printf("File not Found\n");
  } else {
    printf("File is opened\n");
  }
}
void createWithDestination(char* name, char* destination) {
     // Concatenate directory path and file name to create the full path
  char *full_path =
      malloc(strlen(destination) + strlen(name) + 2);  // 2 for '/' and null terminator
  if (full_path == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return;
  }

  sprintf(full_path, "%s/%s", dir, name);

  // Open file at the specified directory
  FILE *file = fopen(full_path, "w+");
  if (file == NULL) {
    printf("Failed to create file at destination\n");
  } else {
    printf("File created at destination\n");
    fclose(file);
  }

  free(full_path);
}

void read(char* name) {
  char in;
  FILE *fp = fopen(name, "r");
  while(fp == NULL) {
    printf("File not found");
  }
  while((in = fgetc(fp))!=EOF) {
    printf("%c", in);
  }
}

int main(int argc, char** argv) {
    char* command = argv[1];
    char* name = argv[2];
    char* destination = argv[3];

    if(strcmp(command, "editor") == 0) {
        if(argc == 2) {
            create();
        }
        else if(name!=NULL && command!=NULL && destination == NULL ) {
            createWithName();
        }
        else if(name!=NULL && command!=NULL && destination != NULL) {
            createWithDestination();
        }
    }
}