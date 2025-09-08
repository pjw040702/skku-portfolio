#include <iostream>

int N, M;
int ** matrix;

int isNotCleaned(int r, int c){
    if(r>=0 && c>=0 && r<N && c<M && matrix[r][c] == 0) return 1;
    return 0;
}

int canMoveToThisPosition(int r, int c){
    if(r>=0 && c>=0 && r<N && c<M && matrix[r][c] != 1) return 1;
    else return 0;
}

class Robot{
    public:
    int r;
    int c;
    int pos;
    
    public:
    int count(){
        int count = 0;
        while(1){
            if(matrix[r][c] == 0){
                matrix[r][c] = 2;
                count++;
                continue;
            }
            if(!isNotCleaned(r-1, c) && !isNotCleaned(r+1, c) && !isNotCleaned(r, c-1) && !isNotCleaned(r, c+1)){
                if(robotCanMove(0)){
                    move(0);
                    continue;
                }
                else break;
            }
            else{
                rotate();
                if(pos==0 && isNotCleaned(r-1, c)){
                    move(1);
                }
                else if(pos==1 && isNotCleaned(r, c+1)){
                    move(1);
                }
                else if(pos==2 && isNotCleaned(r+1, c)){
                    move(1);
                }
                else if(pos==3 && isNotCleaned(r, c-1)){
                    move(1);
                }
                continue;
            }
        }
        return count;
    }

    int robotCanMove(int isForward){
        if(isForward){
            if(pos==0) return canMoveToThisPosition(r-1, c);
            if(pos==1) return canMoveToThisPosition(r, c+1);
            if(pos==2) return canMoveToThisPosition(r+1, c);
            if(pos==3) return canMoveToThisPosition(r, c-1);
        }
        else if(!isForward){
            if(pos==0) return canMoveToThisPosition(r+1, c);
            if(pos==1) return canMoveToThisPosition(r, c-1);
            if(pos==2) return canMoveToThisPosition(r-1, c);
            if(pos==3) return canMoveToThisPosition(r, c+1);
        }
    }
    
    void move(int isForward){
        if(isForward){
            if(pos==0) r = r-1;
            if(pos==1) c = c+1;
            if(pos==2) r = r+1;
            if(pos==3) c = c-1;
        }
        else if(!isForward){
            if(pos==0) r = r+1;
            if(pos==1) c = c-1;
            if(pos==2) r = r-1;
            if(pos==3) c = c+1;
        }
    }

    void rotate(){
        pos = (pos+3)%4;
    }
};


int main()
{
    Robot robot;
    std::cin>>N>>M;
    matrix = new int*[N];
    for(int i = 0; i<N; i++)
        matrix[i] = new int[M];

    std::cin>>robot.r>>robot.c>>robot.pos;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            std::cin>>matrix[i][j];
        }
    }

    std::cout<<robot.count();
    
    return 0;
}