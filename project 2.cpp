#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int screenWidth = 100;
    char fullName[50];
    int animationSpeed = 1;

    printf("Enter the Your name: ");
    scanf("%s", fullName);

    int nameLength = strlen(fullName);
    int position = screenWidth;

    while (1) {
        system("cls");

        for (int i = 0; i < screenWidth; i++) {
            if (i >= position && i < position + nameLength) {
                printf("%c", fullName[i - position]);
            } else {
                printf(" ");
            }
        }
        printf("\n");

        position -= animationSpeed;

        if (position + nameLength <= 0) {
            position = screenWidth;
        }
        usleep(100000);
    }

    return 0;
}
