#include "string.h"


void reverse(char* word, int length)
{
    char temp;
    for(int i = 0; i < length; i++) {
        temp = word[i];
        word[i] = word[length - i];
        word[length - i] = temp;
    }
}


void inttochar(int val, char* converted)
{
    int i = 0;
    const char digits[] = "0123456789";
    do {
        converted[i] = digits[val % 10];
        val = val / 10;
        i++;
    } while (val != 0);
    converted[i] = '\0';
    reverse(converted, i - 1);
}