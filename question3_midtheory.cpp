#include <stdio.h>
#include <stdlib.h>

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

struct Node* createNode(char c) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->ch = c;
    newNode->freq = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertNode(struct Node** root, char c) {
    if (*root == NULL) {
        *root = createNode(c);
        return;
    }
    if ((*root)->ch == c) {
        (*root)->freq++;
        return;
    }
    if ((*root)->left == NULL) insertNode(&((*root)->left), c);
    else insertNode(&((*root)->right), c);
}

void levelOrder(struct Node* root) {
    if (!root) return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("(%c, %d) ", temp->ch, temp->freq);
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
}

int main() {
    char str[50];
    printf("Enter string: ");
    scanf("%s", str);
    
    struct Node* root = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        insertNode(&root, str[i]);
    }

    printf("Character Frequencies:\n");
    levelOrder(root);
    return 0;
}

