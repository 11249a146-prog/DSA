#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n')
        str[len-1] = '\0';

    // Reverse in place
    for (int i = 0, j = strlen(str)-1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("Reversed string: %s\n", str);
    return 0;
}