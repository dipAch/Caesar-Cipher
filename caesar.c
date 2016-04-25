/*
    ---->        Author : Dipankar Achinta
    ----> Authored Date : 28/04/2013
	Implementation of Caesar Cipher
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

#define PARENT_SIZE 100
#define SPACE_BAR 32
#define PARENT_CHAR_LIMIT 95
#define MESSAGE_BUFFER 200
#define CAESAR_CIPHER 7

void main()
{
    int index_i, index_j, message_len, cipher_const, next;
    char parent[PARENT_SIZE], message[MESSAGE_BUFFER], decoded[MESSAGE_BUFFER];
    for(index_i = 0; index_i < (PARENT_SIZE - 1) && index_i < PARENT_CHAR_LIMIT; index_i++)
    {
        parent[index_i] = SPACE_BAR + index_i;
    }
    parent[index_i] = '\0';

    /* Test code block
    for(index_i = 0; index_i < PARENT_SIZE && index_i < PARENT_CHAR_LIMIT; index_i++)
    {
        printf("\n%c", parent[index_i]);
    }
    */

    do
    {
        clrscr();
        printf("\n\t\t\t\tMESSAGE DECRYPTER....");
        printf("\n\n\nEnter Encrypted Message : ");
        gets(message);
        message_len = strlen(message);
        printf("\n\nEnter Cipher Constant (Magic No.) : ");
        scanf("%d", &cipher_const);
        if(cipher_const == 0)
        {
            cipher_const = CAESAR_CIPHER; // Set To Default
        }
        for(index_j = 0; index_j < message_len && index_j < (MESSAGE_BUFFER - 1); index_j++)
        {
            for(index_i = cipher_const; index_i < (PARENT_CHAR_LIMIT - 1) && index_i < (PARENT_SIZE - 1); index_i++)
            {
                if(message[index_j] == parent[index_i])
                {
                    decoded[index_j] = parent[index_i] - cipher_const;
                }
            }
        }
        decoded[index_j] = '\0';
        printf("\n\nDecrypted Message : %s", decoded);
        printf("\n\n\nPress (1) to Continue and (0) to Halt : ");
        scanf("%d", &next);
        fflush(stdin);
    } while(next != 0);
    printf("\n\n\nPress <ENTER> to <EXIT> Console....");
    getch();
}