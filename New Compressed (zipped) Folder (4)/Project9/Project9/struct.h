#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/******************************************************************/
struct tree {
    char data[500];
    struct tree* YES;
    struct tree* NO;
};
FILE* ptr;
/******************************************************************/
struct tree* creatnode(struct tree** newnode, char data[128]) {
    struct tree* node = (struct tree*)malloc(sizeof(struct tree));

    return node;
}
