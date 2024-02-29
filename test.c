#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    char word[100]; // Assuming each word is at most 100 characters
    struct Node* next;
};

// Function to read words from the user and create a linked list
struct Node* readWords() {
    struct Node* head = NULL;
    struct Node* current = NULL;

    int numWords;
    printf("How many words do you want to enter? ");
    scanf("%d", &numWords);

    for (int i = 0; i < numWords; ++i) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter word %d: ", i + 1);
        scanf("%s", newNode->word);
        newNode->next = NULL;

        if (head == NULL) {
            head = current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

// Function to write words from the linked list to a text file
void writeToFile(struct Node* head) {
    FILE* file = fopen("words.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (head != NULL) {
        fprintf(file, "%s\n", head->word);
        head = head->next;
    }

    fclose(file);
}

int main() {
    struct Node* wordList = readWords();
    writeToFile(wordList);

    printf("Words written to words.txt successfully!\n");

    // Free memory (optional, but good practice)
    while (wordList != NULL) {
        struct Node* temp = wordList;
        wordList = wordList->next;
        free(temp);
    }

    return 0;
}
