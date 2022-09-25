#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 18

struct Word
{
    char *str;
    int len;
};

bool isAlpha(char ltr)
{
    bool soln = (('a' <= ltr && ltr <= 'z') || ('A' <= ltr && ltr <= 'Z'));
    return soln;
}

void toggleCase(struct Word *msg)
{
    char ltr;
    int i;

    for (i = 0; i < msg->len; i++)
    {
        ltr = msg->str[i];
        if (isAlpha(ltr))
        {
            if (ltr <= 'Z')
                msg->str[i] = ltr + 32;
            else
                msg->str[i] = ltr - 32;
        }
    }
}

void reverse(struct Word *msg)
{
    int i;
    char *buf = (char *)calloc(LENGTH, sizeof(char));

    buf[LENGTH - 1] = '\0';
    for (i = 0; i < msg->len - 1; i++)
    {
        buf[msg->len - i - 2] = msg->str[i];
    }
    strncpy(msg->str, buf, LENGTH);
}

void unscramble(struct Word *msg)
{
    char ltr;
    char chng = 13;
    int i;

    for (i = 0; i < msg->len; i++)
    {
        ltr = msg->str[i];
        if (isAlpha(ltr))
        {
            if (ltr > 'm' || (ltr > 'M' && ltr <= 'Z'))
            {
                msg->str[i] = ltr - chng;
            }
            else
            {
                msg->str[i] = ltr + chng;
            }
        }
    }
}

int main()
{
    struct Word *secret_msg = (struct Word *)calloc(1, sizeof(struct Word));
    secret_msg->str = (char *)calloc(LENGTH, sizeof(char));
    strncpy(secret_msg->str, "!522 Av XPHy QBBt", LENGTH);

    secret_msg->len = LENGTH;

    unscramble(secret_msg);
    reverse(secret_msg);
    toggleCase(secret_msg);

    printf("%s\n", secret_msg->str);
    free(secret_msg->str);
    free(secret_msg);
    return 0;
}
