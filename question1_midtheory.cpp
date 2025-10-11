#include <stdio.h>
#include <string.h>

struct Member {
    char name[50];
    int steps[30];
};

void analyzeSteps(struct Member members[], int n) {
    for(int i = 0; i < n; i++) {
        int daysAbove10000 = 0, maxStep = 0;
        for(int j = 0; j < 30; j++) {
            if(members[i].steps[j] > 10000) {
                daysAbove10000++;
            }
            if(members[i].steps[j] > maxStep) {
                maxStep = members[i].steps[j];
            }
        }
        printf("\nMember: %s\n", members[i].name);
        printf("Days above 10000 steps : %d\n", daysAbove10000);
        printf("Maximum steps recorded : %d\n", maxStep);
    }
}

int main() {
    int n;
    printf("Enter number of members: ");
    scanf("%d", &n);
    
    struct Member members[n];
    for(int i = 0; i < n; i++) {
        printf("Enter name of member %d: ", i+1);
        scanf("%s", members[i].name);
        printf("Enter 30 days step count:\n");
        for(int j = 0; j < 30; j++) {
            scanf("%d", &members[i].steps[j]);
        }
    }
    
    analyzeSteps(members, n);
    return 0;
}

