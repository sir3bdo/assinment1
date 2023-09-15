#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include"gaming.h"
#include"struct.h"
#include<string.h>
#include"read.h"
#include"write.h"
/*********************************************************/
/*********************************************************/
/*********************************************************/

int main(void)
{
    char c = 'y';
    struct tree* head=malloc(sizeof(struct tree));
    int i = -1;
    char temp[4000][128];
    char str[128];
    FILE* ptr;
    ptr=fopen( "tree.txt", "r");
    while (!feof(ptr))
    {
        i++;
        fgets(str, 128, ptr);
        str[strcspn(str, "\n")] = '\0';       
        strcpy_s(temp[i], 128, str);           
      
    }
    head = readLevelOrder(temp, 0, i);
    fclose(ptr);
    while (c == 'y') {
        game(&head, ptr);
        printf("do u want to play again(y/n)\n");
        scanf_s("%c", &c);
        getchar();
    }
    write(ptr, head);
}