#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Tab
typedef struct Tab {
    int id;
    char url[200];
    struct Tab *prev, *next;
} Tab;

// Structure for Browser
typedef struct {
    Tab *head, *current;
    int nextId;
} Browser;

// Create a new tab
Tab* createTab(int id, const char *url) {
    Tab *newTab = (Tab*)malloc(sizeof(Tab));
    newTab->id = id;
    strcpy(newTab->url, url);
    newTab->prev = newTab->next = NULL;
    return newTab;
}

// Initialize browser
void initializeBrowser(Browser *b) {
    b->head = NULL;
    b->current = NULL;
    b->nextId = 1;
}

// Open a real website in system browser
void openWebsite(const char *url) {
    #ifdef _WIN32
        char command[300];
        sprintf(command, "start %s", url);
        system(command);
    #elif __APPLE__
        char command[300];
        sprintf(command, "open %s", url);
        system(command);
    #else // Linux
        char command[300];
        sprintf(command, "xdg-open %s", url);
        system(command);
    #endif
}

// Visit a new page
void visitPage(Browser *b, const char *url) {
    Tab *newTab = createTab(b->nextId++, url);

    if (b->current == NULL) {
        b->head = newTab;
    } else {
        b->current->next = newTab;
        newTab->prev = b->current;
    }
    b->current = newTab;

    printf("Opened Page %d: %s\n", newTab->id, newTab->url);
    printf("Current Page -> ID: %d | URL: %s\n", b->current->id, b->current->url);

    // Open in default browser
    openWebsite(url);
}

// Go Back
void goBack(Browser *b) {
    if (b->current && b->current->prev) {
        b->current = b->current->prev;
        printf("Went Back -> Page %d: %s\n", b->current->id, b->current->url);
    } else {
        printf("No previous tab!\n");
    }
}

// Go Forward
void goForward(Browser *b) {
    if (b->current && b->current->next) {
        b->current = b->current->next;
        printf("Went Forward -> Page %d: %s\n", b->current->id, b->current->url);
    } else {
        printf("No next tab!\n");
    }
}

// Show Current Tab
void showCurrentTab(Browser *b) {
    if (b->current) {
        printf("Current Page -> ID: %d | URL: %s\n", b->current->id, b->current->url);
    } else {
        printf("No active tab!\n");
    }
}

// Close Current Tab
void closeCurrentTab(Browser *b) {
    if (!b->current) {
        printf("No tab to close!\n");
        return;
    }

    Tab *temp = b->current;

    printf("Closed Page %d: %s\n", temp->id, temp->url);

    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;

    if (temp == b->head) b->head = temp->next;
    if (temp->next) b->current = temp->next;
    else b->current = temp->prev;

    free(temp);

    if (b->current) {
        printf("Now Current -> ID: %d | URL: %s\n", b->current->id, b->current->url);
    } else {
        printf("No tabs open now!\n");
    }
}

// Show History
void showHistory(Browser *b) {
    if (!b->head) {
        printf("No history available!\n");
        return;
    }

    Tab *temp = b->head;
    printf("\n--- Browser History ---\n");
    while (temp) {
        printf("Page %d -> %s\n", temp->id, temp->url);
        temp = temp->next;
    }
    printf("-----------------------\n");
}

// Main Program
int main() {
    Browser browser;
    initializeBrowser(&browser);

    int choice;
    char url[200];

    do {
        printf("\n--- Browser Menu ---\n");
        printf("1. Visit a New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Show Current Tab\n");
        printf("5. Close Current Tab\n");
        printf("6. Show History\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%199s", url);
                visitPage(&browser, url);
                break;
            case 2:
                goBack(&browser);
                break;
            case 3:
                goForward(&browser);
                break;
            case 4:
                showCurrentTab(&browser);
                break;
            case 5:
                closeCurrentTab(&browser);
                break;
            case 6:
                showHistory(&browser);
                break;
            case 7:
                printf("Exiting Browser...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}

