#include "./snake.h"
/*************************************************************
*第一步：确定初始化地图，蛇，食物资源
*第二步：使得蛇能够移动－－＞相当与一条链表，根据方向来更改每个节点的坐标
*第三步：判断蛇移动会造成的影响－－＞１．撞墙　２．撞自己　３，正常
*       ４．吃到食物－－＞链表的增长－＞创建新食物
*第四步：搭建框架　初始化地图－＞循环蛇的移动－＞根据输入响应
**************************************************************/

int score = 0;
int state = 1;      //运动状态　,加速　０　正常　１　减速　２
char toward = 'R';  //用户指定方向
int map[COL][ROW]={0}; //当为０时为空白，当为１为边框，当为２为蛇身，当为３为食物
snakeNode *pHead = NULL;    //蛇头
snakeNode *pTail = NULL;    //蛇尾

snakeNode *makeNode()
{
    snakeNode *newNode = (snakeNode*)malloc(LEN_NODE);
    if(NULL == newNode){
        snakeNode *newNode = (snakeNode*)malloc(LEN_NODE);
    }
    newNode->pNext = NULL;
    newNode->pPrev = NULL;
    return newNode;
}
void initMap()
{
    int i = 0;
    for(i=0;i<ROW;i+=2)
        map[0][i] = 1;
    for(i=1;i<COL;i++)
    {
        map[i][0] = 1;
        map[i][ROW-2] = 1;
    }
    for(i=0;i<ROW;i+=2)
        map[COL-1][i] = 1;
    return;
}

void initSnake()
{
    snakeNode *newNode = makeNode();
    pHead = newNode;
    pTail = newNode;
    pHead->pPrev = NULL;
    pTail->pNext = NULL;
    newNode->x = 10;
    newNode->y = 5;
    map[5][10] = 2;
    updateMap();
}

void printFood()
{
    srand(time(0));
    int x = (rand()%(ROW/2-2))*2+2;
    int y = rand()%(COL-2)+1;
    while(map[y][x] != 0)
    {
        x = (rand()%(ROW/2-2))*2+2;
        y = rand()%(COL-2)+1;
    }
    map[y][x] = 3;
    updateMap();
    return;
}

void printScore()
{

void descript(void)
{

void updateMap()    //刷新图形
{
    system("clear");
    descript();
    printScore();
    for(int y=0;y<COL;y++)
    {
        for(int x=0;x<ROW;x++)
        {
                if(map[y][x] == 1 || map[y][x] == 2)
                    printf("■");
                else if(map[y][x] == 0)
                    printf(" ");
                else if(map[y][x] == 3)
                    printf("★");
        }
        printf("\n");
    }
    return;
}
    printf("\t************************************\n");
    printf("\t* Exit:Q Stop:space Speed:F Slow:R *\n");
    printf("\t*      ↑:W 　↓:S  ←:A  →:D         *\n");
    printf("\t************************************\n");
    return;
}
    printf("\033[31m\t\t\tScore:%d\n",score);
    printf("\033[0m");
    return;
}

void snakeUp()
{
    snakeNode *loop = pTail;
    while(loop->pPrev != NULL){
        loop->x = loop->pPrev->x;
        loop->y = loop->pPrev->y;
        map[loop->y][loop->x] = 2;
        loop = loop->pPrev;
    }
    pHead->y -= 1;
    map[pHead->y][pHead->x] = 2;
    return;
}

void snakeDown()
{
    snakeNode *loop = pTail;
    while(loop->pPrev != NULL){
        loop->y = loop->pPrev->y;
        loop->x = loop->pPrev->x;
        map[loop->y][loop->x] = 2;
        loop = loop->pPrev;
    }
    pHead->y += 1;
    map[pHead->y][pHead->x] = 2;
    return;
}

void snakeRight()
{
    snakeNode *loop = pTail;
    while(loop->pPrev != NULL){
        loop->x = loop->pPrev->x;
        loop->y = loop->pPrev->y;
        map[loop->y][loop->x] = 2;
        loop = loop->pPrev;
    }
    pHead->x += 2;
    map[pHead->y][pHead->x] = 2;
    return;
}
void snakeLeft()
{
    snakeNode *loop = pTail;
    while(loop->pPrev != NULL){
        loop->x = loop->pPrev->x;
        loop->y = loop->pPrev->y;
        map[loop->y][loop->x] = 2;
        loop = loop->pPrev;
    }
    pHead->x -= 2;
    map[pHead->y][pHead->x] = 2;
    return;
}


void clearSnake()
{
    snakeNode *loop = pHead;
    while(loop != NULL){
        map[loop->y][loop->x] = 0;
        loop = loop->pNext;
    }
    return;
}
int moveSnake()
{
    if(toward == 'U')   //向上    y-1
    {
        if(map[pHead->y-1][pHead->x] == 3)  //吃到食物
        {
            snakeNode *newNode = makeNode();
            newNode->x = pHead->x;
            newNode->y = pHead->y-1;
            newNode->pNext = pHead;
            pHead->pPrev = newNode;
            pHead = newNode;
            map[pHead->y][pHead->x] = 2;

            score += 10;
            printFood();
        }
        else if(map[pHead->y-1][pHead->x] == 0)//没有东西
        {
            clearSnake();
            snakeUp();
        }
        else    //撞墙或咬到自己
        {
            printf("game over\n");
            return 0;
        }
    }
    else if(toward == 'D')  //向下 y+1
    {
        if(map[pHead->y+1][pHead->x] == 3)  //吃到食物
        {
            snakeNode *newNode = makeNode();
            newNode->x = pHead->x;
            newNode->y = pHead->y+1;
            newNode->pNext = pHead;
            pHead->pPrev = newNode;
            pHead = newNode;
            map[pHead->y][pHead->x] = 2;

            score += 10;
            printFood();
        }
        else if(map[pHead->y+1][pHead->x] == 0)     //没有东西
        {
            clearSnake();
            snakeDown();
        }
        else    //撞墙或咬到自己
        {
             printf("game over\n");
             return 0;
        }
    }
    else if(toward == 'R')  //向右    x+2
    {
        if(map[pHead->y][pHead->x+2] == 3)  //吃到食物
        {
            snakeNode *newNode = makeNode();
            newNode->x = pHead->x+2;
            newNode->y = pHead->y;
            newNode->pNext = pHead;
            pHead->pPrev = newNode;
            pHead = newNode;
            map[pHead->y][pHead->x] = 2;

            score += 10;
            printFood();
        }
        else if(map[pHead->y][pHead->x+2] == 0)//没有东西
        {
            clearSnake();
            snakeRight();
        }
        else    //撞墙或咬到自己
        {
             printf("game over\n");
             return 0;
        }
    }
    else                    //向左  x-2
    {
        if(map[pHead->y][pHead->x-2] == 3) //吃到食物
        {
            snakeNode *newNode = makeNode();
            newNode->x = pHead->x-2;
            newNode->y = pHead->y;
            newNode->pNext = pHead;
            pHead->pPrev = newNode;
            pHead = newNode;
            map[pHead->y][pHead->x] = 2;

            score += 10;
            printFood();
        }
        else if(map[pHead->y][pHead->x-2] == 0)//没有东西
        {
            clearSnake();
            snakeLeft();
        }
        else    //撞墙或咬到自己
        {
             printf("game over\n");
             return 0;
        }

    }
    return 1;
}
int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}

int scanKeyboard()  //对键盘按键的即刻反应
{
    int in;
    struct termios new_settings;
    struct termios stored_settings;
    tcgetattr(0,&stored_settings);
    new_settings = stored_settings;
    new_settings.c_lflag &= (~ICANON);
    new_settings.c_lflag &= (~ECHO);
    new_settings.c_lflag &= (~ISIG);
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] =0;
    tcsetattr(0,TCSANOW,&new_settings);
    in = getchar();
    tcsetattr(0,TCSANOW,&stored_settings);
    return in;
}
/***************************************************************
＊可以根据按下键盘的键值来实现不同功能
＊退出返回　０     q
＊正常返回　１     w：↑　s：↓　a：←　d：→
＊暂停返回　２     空格
＊加速返回　３     f
＊减速返回　４     r
*****************************************************************/
int getWard()
{
    int upKey = scanKeyboard();
    if (upKey==119 && toward != 'D')
    {
        toward = 'U';
    }
    else if ( upKey ==115 && toward != 'U')
    {
        toward = 'D';
    }
    else if (upKey==97 && toward != 'R')
    {
        toward = 'L';
    }
    else if (upKey == 100 && toward != 'L')
    {
        toward = 'R';
    }
    else if(upKey == 113)
    {
        return 0;
    }
    else if(upKey == 32)
    {
        return 2; //暂停
    }
    return 1;
}

int main(void)
{
    initMap();
    initSnake();
    printFood();
    updateMap();
    while(1)
    {
        while(!kbhit())
        {
            if(!moveSnake())
                return 0;
            updateMap();
            if(state == 1)
                usleep(500000);
            else if(state == 0)
                usleep(200000);
            else
                usleep(800000);
        }
        switch(getWard())
        {
            case 0:
                return 0;
            case 2:
            {
                if(scanKeyboard()== 32)
                    break;
            }
            case 3:
                state = 0;
            case 4:
                state = 2;
        }
    }
    return 0;
}
//相关键值　q 113  w 119 e 101 r 114 t 116 a 97  s 115 d 100 f 102 g 103
