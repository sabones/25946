#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
}Node;

int main(void){
    char buffer[1024];
    Node *head = NULL;
    Node *tail = NULL;
    while (fgets(buffer, sizeof buffer, stdin) != NULL) {
    if (buffer[0] == '.') {
        break;
    }
    struct Node *node = malloc(sizeof *node);
    if (node == NULL) {
        perror("malloc");
        break;
    }
    node->data = malloc(strlen(buffer) + 1);
    if (node->data == NULL) {
        perror("malloc");
        free(node);
        break;
    }
    strcpy(node->data, buffer);
    node->next = NULL;
    if (head == NULL) {
        head = node;
    }
    else {
        tail->next = node;
    }
    tail = node;
    }
Node *current = head;
while (current != NULL) {
    printf("%s", current->data);
    current = current->next;
}
current = head;
while (current != NULL) {
    Node *next = current->next;
    free(current->data);
    free(current);
    current = next;
}
}
