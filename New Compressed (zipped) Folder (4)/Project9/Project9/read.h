#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct.h"
struct tree* readLevelOrder(char arr[][128], int i, int n);
void reading(FILE* ptr, struct tree** head);
struct tree* newNode(char data[128]);
struct tree* readLevelOrder(char arr[][128], int i, int n)
{
    struct tree* root = NULL;

    if (i < n)
    {
        root = newNode(arr[i]);
        root->YES = readLevelOrder(arr, 2 * i + 1, n);
        root->NO = readLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}
struct tree* newNode(char data[128])
{
    struct tree* node = (struct tree*)malloc(sizeof(struct tree));
    strcpy_s(node->data, 128, data);
    node->YES = node->NO = NULL;
    return (node);
}