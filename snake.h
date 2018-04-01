#ifndef _SNAKE_H_
#define _SNAKE_H_


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include <termios.h>
#include <fcntl.h>

typedef struct snakeNode{
    int x;
    int y;
    struct snakeNode *pNext;
    struct snakeNode *pPrev;
}snakeNode;

#define LEN_NODE sizeof(snakeNode)
#define COL 25
#define ROW 50

snakeNode *makeNode();
void initMap();
void initSnake();
void printFood();
void printScore();
void descript();
void snakeUp();
void snakeDown();
void snakeRight();
void snakeLeft();
void updateMap();
int moveSnake();
int scanKeyboard();
int getWard();
int kbhit(void);
void clearSnake();

#endif // _SNAKE_H_

//\033[nA上移n行
//\033[nB　下移
//\033[nC  右移
//\033[nD　左移
//\033[y;xH 设置光标位置
