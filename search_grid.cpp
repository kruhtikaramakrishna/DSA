#include <stdio.h>
#include <string.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    char grid[m][n + 1];
    for (int i = 0; i < m; i++) {
        scanf("%s", grid[i]);
    }

    char word[50];
    scanf("%s", word);
    int len = strlen(word);

    int found = 0;

    // Search Horizontally (Left to Right)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n - len; j++) {
            int k;
            for (k = 0; k < len; k++) {
                if (grid[i][j + k] != word[k])
                    break;
            }
            if (k == len) {
                printf("start:(%d,%d) end:(%d,%d)\n", i, j, i, j + len - 1);
                found = 1;
            }
        }
    }

    // Search Vertically (Top to Bottom)
    for (int i = 0; i <= m - len; i++) {
        for (int j = 0; j < n; j++) {
            int k;
            for (k = 0; k < len; k++) {
                if (grid[i + k][j] != word[k])
                    break;
            }
            if (k == len) {
                printf("start:(%d,%d) end:(%d,%d)\n", i, j, i + len - 1, j);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("word not found\n");
    }

    return 0;
}

