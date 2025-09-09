#include <stdio.h>
#include <stdlib.h>

typedef struct RobotCleaner{
int r;
int c;
int pos;
} Robot;

int count(Robot* robot, int** matrix);
int isNotCleaned(int r, int c, int ** matrix);
int canMoveToThisPosition(int r, int c, int ** matrix);
int robotCanMove(Robot* robot, int** matrix, int isForward);
void move(Robot * robot, int** matrix, int isForward);
void rotate(Robot * robot);

static int N, M;
int main()
{
    
    Robot * robot = malloc(sizeof(Robot));
    scanf("%d %d", &N, &M);
    int ** matrix = (int**) malloc(sizeof(int*) * N);
    for(int i = 0; i<N; i++)
        matrix[i] = (int *) malloc(sizeof(int) * M);

    scanf("%d %d %d", &robot->r, &robot->c, &robot->pos);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("\n%d", &matrix[i][j]);
        }
    }

    printf("%d", count(robot, matrix));
}

int count(Robot* robot, int** matrix){
    int count = 0;
    while(1){
        if(matrix[robot->r][robot->c] == 0){
            matrix[robot->r][robot->c] = 2;
            count++;
            continue;
        }
        if(!isNotCleaned(robot->r-1, robot->c, matrix) && !isNotCleaned(robot->r+1, robot->c, matrix) && !isNotCleaned(robot->r, robot->c-1, matrix) && !isNotCleaned(robot->r, robot->c+1, matrix)){
            if(robotCanMove(robot, matrix, 0)){
                move(robot, matrix, 0);
                continue;
            }
            else break;
        }
        else{
            rotate(robot);
            if(robot->pos==0 && isNotCleaned(robot->r-1, robot->c, matrix)){
                move(robot, matrix, 1);
            }
            else if(robot->pos==1 && isNotCleaned(robot->r, robot->c+1, matrix)){
                move(robot, matrix, 1);
            }
            else if(robot->pos==2 && isNotCleaned(robot->r+1, robot->c, matrix)){
                move(robot, matrix, 1);
            }
            else if(robot->pos==3 && isNotCleaned(robot->r, robot->c-1, matrix)){
                move(robot, matrix, 1);
            }
            continue;
        }
    }
    return count;
}

int isNotCleaned(int r, int c, int ** matrix){
    if(r>=0 && c>=0 && r<N && c<M && matrix[r][c] == 0) return 1;
    return 0;
}

int canMoveToThisPosition(int r, int c, int ** matrix){
    if(r>=0 && c>=0 && r<N && c<M && matrix[r][c] != 1) return 1;
    else return 0;
}

int robotCanMove(Robot* robot, int** matrix, int isForward){
    if(isForward){
        if(robot->pos==0) return canMoveToThisPosition(robot->r-1, robot->c, matrix);
        if(robot->pos==1) return canMoveToThisPosition(robot->r, robot->c+1, matrix);
        if(robot->pos==2) return canMoveToThisPosition(robot->r+1, robot->c, matrix);
        if(robot->pos==3) return canMoveToThisPosition(robot->r, robot->c-1, matrix);
    }
    else if(!isForward){
        if(robot->pos==0) return canMoveToThisPosition(robot->r+1, robot->c, matrix);
        if(robot->pos==1) return canMoveToThisPosition(robot->r, robot->c-1, matrix);
        if(robot->pos==2) return canMoveToThisPosition(robot->r-1, robot->c, matrix);
        if(robot->pos==3) return canMoveToThisPosition(robot->r, robot->c+1, matrix);
    }
}

void move(Robot * robot, int** matrix, int isForward){
    if(isForward){
        if(robot->pos==0) robot->r = robot->r-1;
        if(robot->pos==1) robot->c = robot->c+1;
        if(robot->pos==2) robot->r = robot->r+1;
        if(robot->pos==3) robot->c = robot->c-1;
    }
    else if(!isForward){
        if(robot->pos==0) robot->r = robot->r+1;
        if(robot->pos==1) robot->c = robot->c-1;
        if(robot->pos==2) robot->r = robot->r-1;
        if(robot->pos==3) robot->c = robot->c+1;
    }
}

void rotate(Robot * robot){
    robot->pos = (robot->pos+3)%4;
}

