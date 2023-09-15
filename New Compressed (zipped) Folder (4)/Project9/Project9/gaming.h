#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"struct.h"
/***********************************************************************/
void game(struct tree** head, FILE* ptr) {
	struct tree* current = malloc(sizeof(struct tree));
	struct tree* next1 = malloc(sizeof(struct tree));
	struct tree* next2 = malloc(sizeof(struct tree));
	current = (*head);
	char c;
	while (strcmp(current->YES->data , "-1") != 0 && strcmp(current->NO->data, "-1") != 0) {
		printf("%s\n", current->data);
		printf("enter (y/n)\n");
		scanf_s("%c", &c);
		getchar();
		if (c == 'y') {
			current = current->YES;
		}
		else if (c == 'n') {
			current = current->NO;
		}
	}
	printf("you are thinking of: %s\n", current->data);
	printf("did i guess correctly(y/n)\n");
	scanf_s("%c", &c);
	getchar();
	if (c == 'y') {
		return;
	}
	else if (c == 'n') {
		char data1[128];
		current->YES = malloc(sizeof(struct tree));
		current->NO = malloc(sizeof(struct tree));
		current->YES->YES = malloc(sizeof(struct tree));
		current->YES->NO = malloc(sizeof(struct tree));
		current->NO->YES = malloc(sizeof(struct tree));
		current->NO->NO = malloc(sizeof(struct tree));
		strcpy_s(data1, 128, current->data);
		strcpy_s(current->NO->data, 128, data1);
		printf("what do u think of: \n");
		fgets(data1, 128, stdin);
		data1[strcspn(data1, "\n")] = '\0';
		strcpy_s(current->YES->data, 128, data1);
		strcpy_s(current->YES->YES->data, 128, "-1");
		current->YES->YES->YES = NULL;
		current->YES->YES->NO= NULL;
		current->NO->YES->NO = NULL;
		current->NO->YES->YES= NULL;
		current->YES->NO->YES= NULL;
		current->YES->NO->NO= NULL;
		current->NO->NO->NO = NULL;
		current->NO->NO->YES = NULL;
		strcpy_s(current->YES->NO->data, 128, "-1");
		strcpy_s(current->NO->YES->data, 128, "-1");
		strcpy_s(current->NO->NO->data, 128, "-1");
		printf("what should i have asked you ?\n");
		fgets(data1, 128, stdin);
		data1[strcspn(data1, "\n")] = '\0';
		strcpy_s(current->data, 128, data1);
		return;
	}
	return;

}

