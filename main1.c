#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// STRUCTURE OF ADDING TEXT INTO THE LINKED LIST

char line[1000];  // Assuming maximum line length is 1000 characters

struct Node {
  char *line;
  struct Node *next;
};

 struct Node *arr[25];
 int currentLine=-1;
 
 //creatind append function again
 void append2(char *name){
 	currentLine++;
 	arr[currentLine] = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current = arr[currentLine];
    current->next = NULL;
    
    char *token = strtok(name, " "); // Split the line into words
    while (token != NULL) {
        current->line = strdup(token); // Store the word
        current->next = (struct Node *)malloc(sizeof(struct Node));
        current = current->next;
        current->next = NULL;
        token = strtok(NULL, " "); // Get next word
    }
    
 }
 
 void display2() {
	int i;
    for (i = 0; i <= currentLine; ++i) {
        struct Node *ptr = arr[i];
        printf("Line %d:  \n", i + 1);
        while (ptr != NULL && ptr->next != NULL) {
            printf("%s\n", ptr->next);
            ptr = ptr->next;
        }
    }
}
 



void create() {
  FILE *file = fopen("file.txt", "w+");
  if (file == NULL) {
    printf("File not created\n");
  } else {
    printf("File is created\n");
  }
}
void create_source(char *name) {
  FILE *file = fopen(name, "w+");
  if (file == NULL) {
    printf("File not Found\n");
  } else {
    printf("File is opened\n");
  }
}

void create_at_destination(char *name, char *dir) {
  // Concatenate directory path and file name to create the full path
  char *full_path =
      malloc(strlen(dir) + strlen(name) + 2);  // 2 for '/' and null terminator
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

void read(char *name) {
  char in;
  printf("-----READ MODE-----\n");
  FILE *fp = fopen(name, "r");
  if (fp == NULL) {
    printf("File not fount\n");
    return;
  }
  while ((in = getc(fp)) != EOF) {
    printf("%c", in);
  }
  fclose(fp);
}

void write(char *name) {
	
 
  printf("-----WRITE MODE-----\n");
  printf("----------PRESS Ctrl. + Z TO SAVE THE FILE\n");
  read(name);
  
  
   FILE *fp = fopen(name, "a");
  char in;
  if (fp == NULL) {
    printf("File not found\n");
    return;
  }
  while ((in = getchar()) != EOF) {
    putc(in, fp);
  }
  fclose(fp);
}

// function to delete a specified file
void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("File %s deleted successfully.\n", filename);
    } else {
        printf("Unable to delete the file %s.\n", filename);
    }
}






struct Node *head = NULL;
struct Node *current = NULL;

void append(char *line) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->line =
      strdup(line);  // strdup allocates memory and copies the string
  new_node->next = NULL;
  if (head == NULL) {
    head = new_node;
    current = new_node;
  } else {
    current->next = new_node;
    current = new_node;
  }
}
void display() {
  struct Node *ptr = head;
  int i=1;
  while (ptr != NULL) {
  	printf("%d ",i);
    printf("%s\n", ptr->line);
    ptr = ptr->next;
    i++;
  }
}

int main(char argc, char **argv) {
  // [1]-command,[2]-source,[3]-destination,[4]-directory;

  char *command = argv[1];
  char *name = argv[2];
  char *dir = argv[3];
  if (strcmp(command, "editor") == 0) {
//    		printf("hello world !");
    if ( command != NULL && name==NULL && dir==NULL) {
//    	printf("hello editor");
      create();
     
    } else if (name != NULL && command != NULL && dir == NULL) {
      create_source(name);
//       printf("hello world !2");
    } else if (name != NULL && command != NULL && dir != NULL) {
      create_at_destination(name, dir);
    }
  }
  
  if (strcmp(command, "create") == 0){
  	create();
  }
  

  if (strcmp(command, "read") == 0) {
    read(name);
  }

  struct Node arr[25];
  int i;

  if (strcmp(command, "write") == 0) {
    write(name);
  }


	//appending text to the linked list
  if (strcmp(command, "append") == 0) {
    FILE *file = fopen(name, "r");
    if (file == NULL) {
      printf("Error opening file %s\n", name);
      return 1;
    }
printf("----------APPENDED----------\n");
    
    while (fgets(line, sizeof(line), file) != NULL) {
      append2(line);
      
    }
    display2();
    
  }
  
  if(strcmp(command,"remove")==0){
  	deleteFile(name);
  }
  
  return 0;
}

