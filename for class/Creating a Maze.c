#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define width 10
#define height 5
char maze[2*height+1][2*width+1];

void initMaze(){
    for (int i=0;i<2*height+ 1;i++) {
        for (int j=0;j<2*width+1;j++) {
            if (i%2==1 && j%2==1) {
            //Cells with both odd coordinates are set to be '?' (path candidates but undecided).
                maze[i][j] = '?';
            } else {
            //All cells are set to be '#' (thus become walls).
                maze[i][j] = '#';
            }
        }
    }
    //he two cells in the upper-left corner are set to be ' ' (thus becomes the entry).
     maze[2][1]=' ';
     maze[2][2]=' ';
}

void createMaze(int x, int y) {
    //Note that choosing an adjacent cell can be done by declaring offset arrays
    int offsetX[4]={-2,2,0,0};
    int offsetY[4]={0,0,-2,2};
    int visited[4]={0,0,0,0};//�����w��ܦ�m
    int attempts=0;//������V���զ���

    while (attempts<4) {
        int direction=rand()%4;

        //�p�G�o��V�h�L�F(1)�A���L
        if (visited[direction]) {
            continue;
        }

        //�O���h�L�F
        visited[direction]=1;
        attempts++;

        int nx=x+offsetX[direction];// up = (x-2, y); down = (x+2, y)
        int ny=y+offsetY[direction];//left = (x, y-2); right = (x, y+2)

        if (nx>0 && nx<2*height && ny>0 && ny<2*width && maze[nx][ny]=='?') {
            maze[(x+nx)/2][(y+ny)/2]=' ';
            maze[nx][ny]=' ';

            //���ձq��e��m (x, y) �H����ܤ@�Ӥ�V�e�i�A�ôM��q�V���X�ݮ�l�����|�C
            createMaze(nx, ny);

            //�p�ƾ��k�s
            for (int i=0; i<4;i++){
                visited[i] = 0;
            }
            attempts = 0;
        }
    }
}

void printMaze(){
    for (int i=0;i<2*height+1;i++) {
        for (int j=0; j<2*width+1;j++) {
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand((unsigned int)time(NULL));
    initMaze();
    createMaze(1, 1);
    printMaze();
    return 0;
}
