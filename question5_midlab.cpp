#include <stdio.h>
#include <string.h>
#define MAX 10

char undo[MAX][50], redo[MAX][50];
int topUndo = -1, topRedo = -1;

void performOperation(char *op) {
    strcpy(undo[++topUndo], op);   // Copy string to undo stack
    topRedo = -1;                  // Clear redo stack
    printf("Performed operation: \"%s\"\n", op);
}

void undoOperation() {
    if (topUndo == -1) {
        printf("Nothing to undo.\n");
        return;
    }
    strcpy(redo[++topRedo], undo[topUndo--]);  // Move last undo to redo
    printf("Undone. ");
    if (topUndo >= 0)
        printf("Next Operation that can be undone is = \"%s\"\n", undo[topUndo]);
}

void redoOperation() {
    if (topRedo == -1) {
        printf("Nothing to redo.\n");
        return;
    }
    strcpy(undo[++topUndo], redo[topRedo--]);   // Move last redo to undo
    printf("Redo completed. ");
    if (topRedo >= 0)
        printf("Next Operation that can be redone is = \"%s\"\n", redo[topRedo]);
}

int main() {
    performOperation("op1");
    performOperation("op2");
    performOperation("op3");

    undoOperation();
    redoOperation();
    performOperation("op4");
    undoOperation();
    
    return 0;
}


