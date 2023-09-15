#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    char inputString[1000];
    int i, len, wordCount = 0, letterCount = 0, digitCount = 0, otherCount = 0;
    int vowelCount = 0, consonantCount = 0;

    printf("Enter a string: ");
    gets(inputString);

    len = strlen(inputString);

    for (i = 0; i < len; i++) {
        if (isalpha(inputString[i])) {
            letterCount++;
            if (isVowel(inputString[i])) {
                vowelCount++;
            } else {
                consonantCount++;
            }
        } else if (isdigit(inputString[i])) {
            digitCount++;
        } else if (inputString[i] == ' ' || inputString[i] == '\t') {
            wordCount++;
        } else {
            otherCount++;
        }
    }

    // Counting the last word
    if (len > 0) {
        wordCount++;
    }

    printf("a) Number of words: %d\n", wordCount);
    printf("   Number of letters: %d\n", letterCount);
    printf("   Number of digits: %d\n", digitCount);
    printf("   Number of other characters: %d\n", otherCount);

    printf("b) Separated characters:\n");
    printf("   Letters: %d\n", letterCount);
    printf("   Digits: %d\n", digitCount);
    printf("   Other characters: %d\n", otherCount);

    printf("c) Vowels: %d\n", vowelCount);
    printf("   Consonants: %d\n", consonantCount);

    printf("d) Vowels in the string: ");
    for (i = 0; i < len; i++) {
        if (isalpha(inputString[i]) && isVowel(inputString[i])) {
            printf("%c ", inputString[i]);
        }
    }
    printf("\n");

    printf("   Consonants in the string: ");
    for (i = 0; i < len; i++) {
        if (isalpha(inputString[i]) && !isVowel(inputString[i])) {
            printf("%c ", inputString[i]);
        }
    }
    printf("\n");

    printf("e) Words starting with vowels:\n");
    char* token = strtok(inputString, " ,.");
    while (token != NULL) {
        if (isalpha(token[0]) && isVowel(token[0])) {
            printf("%s\n", token);
        }
        token = strtok(NULL, " ,.");
    }

    printf("   Words starting with consonants:\n");
    token = strtok(inputString, " ,.");
    while (token != NULL) {
        if (isalpha(token[0]) && !isVowel(token[0])) {
            printf("%s\n", token);
        }
        token = strtok(NULL, " ,.");
    }

    return 0;
}
