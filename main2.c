#include <stdio.h>
#include <stdlib.h>

void create() {
    FILE *ptr;
    ptr = fopen("file.txt", "w+");
}
void createWithName(char* name) {

}
void createWithDestination(char* name, char* destination) {

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