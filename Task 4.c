#include <stdio.h>
#include <string.h>

void encode(char *input, char *output) {
    int count = 1;
    char current = input[0];

    for (int i = 1; input[i] != '\0'; i++) {
        if (input[i] == current) {
            count++;
        } else {
            sprintf(output, "%s%d%c", output, count, current);
            count = 1;
            current = input[i];
        }
    }

    // Handle the last character
    sprintf(output, "%s%d%c", output, count, current);
}

void decode(char *input, char *output) {
    int i = 0, j = 0;
    while (input[i] != '\0') {
        int count = input[i] - '0';
        i++;
        while (count > 0) {
            output[j++] = input[i];
            count--;
        }
        i++;
    }
    output[j] = '\0';
}

int main() {
    char input[100], encoded[100], decoded[100];

    printf("Enter the string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    encode(input, encoded);
    printf("Encoded string: %s\n", encoded);

    decode(encoded, decoded);
    printf("Decoded string: %s\n", decoded);

    return 0;
}
