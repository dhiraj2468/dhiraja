#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RED_TEXT "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define YELLOW_TEXT "\x1b[33m"
#define BLUE_TEXT "\x1b[34m"
#define MAGENTA_TEXT "\x1b[35m"
#define CYAN_TEXT "\x1b[36m"
#define RESET_TEXT "\x1b[0m"

int main() {
    int screenWidth = 100;
    char fullName[50];
    int animationSpeed = 1;

    printf("Enter Your name: ");
    scanf("%s", fullName);

    int nameLength = strlen(fullName);
    int position = screenWidth;

    while (1) {
        system("cls");

        for (int i = 0; i < screenWidth; i++) {
            if (i >= position && i < position + nameLength) {
                switch (i - position) {
                    case 0:
                        printf(RED_TEXT);
                        break;
                    case 1:
                        printf(GREEN_TEXT);
                        break;
                    case 2:
                        printf(YELLOW_TEXT);
                        break;
                    case 3:
                        printf(BLUE_TEXT);
                        break;
                    case 4:
                        printf(MAGENTA_TEXT);
                        break;
                    case 5:
                        printf(CYAN_TEXT);
                        break;
                    default:
                        printf(RESET_TEXT);
                }
                printf("%c", fullName[i - position]);
            } else {
                printf(" ");
            }
        }
        printf(RESET_TEXT "\n");

        position -= animationSpeed;

        if (position + nameLength <= 0) {
            position = screenWidth;
        }
        usleep(100000);
    }

    return 0;
}
