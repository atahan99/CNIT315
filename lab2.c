/*
Lab 2
Description : This program will help a robot to find a path in a maze using recursive methods and display all the progress of the robot in the maze. Lastly it will show the correct path found. 

Atahan Kucuk


*/

#include <stdio.h>
#include <stdlib.h>
#define N 6


//Declaring variables
int success = 0; 
int startX, startY, X, Y, endX, endY; 

// This variables will be used to call different path finding cases
int east = 1;
int west = 2;
int south = 3;
int north = 4;
int backtracking = 5;  
//Define maze
char maze[N][N] = {
        {'S', '#', '#', '#', '#', '#'},
        {'.', '.', '.', '.', '#', '#'},
        {'.', '#', '#', '.', '#', '#'},
        {'.', '.', '#', '#', '#', '#'},
        {'#', '.', '#', '.', '.', 'G'},
        {'#', '.', '.', '.', '#', '#'},
    
    };
    /*
    '.' = Where the robot can move
    '#' = obstacles
    'S' = starting point
    'G' = goal 
    */


//Print function
void printMaze(char print[N][N]) {

    for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                    printf("%c ", print[i][j]);
                    if(j==5){
                        printf("\n");
                    }
        }
        if(i==5){
            printf("\n");
        };
    }
}


//Finding the starting and ending locations and registering them
void mazeGo(int path){
    if(!path){
        for(int i=0; i<N ; i++){
            for(int j=0;j<N;j++){
            if(maze[i][j] == 'S'){
                startX, X = j;
                startY, Y = i;
                maze[i][j]='+';
                printMaze(maze); 
            }
            if(maze[i][j] == 'G'){
                endX = j;
                endY = i;
                maze[i][j]='+';
                printMaze(maze);
            }
            }
        }
    }

// If the robot finds the goal register a success
    if((X == endX) && (Y == endY)){
        success = 1 ; 
        maze[startY][startX] = 'S';
        maze[endY][endX] = 'G';
        
    }



// Code for how the robot find its way
switch(path){

    // '+' sign shows the path that the robot takes
    // '*' sign shows the backtracking path 
    case 1:
        if (X+1 > 5){
            return;
        }
        if((maze[Y][X+1] == '#') || (maze[Y][X+1] == '+') || (maze[Y][X+1] == '*') ){
            return;
        }
        printf("Going East\n");
        X++;
        maze[Y][X] = '+';
        printMaze(maze);

        break;
    case 2:
        if (X-1 < 0){
            return;
        }
        if((maze[Y][X-1] == '#') || (maze[Y][X-1] == '+') || (maze[Y][X-1] == '*') ){
            return;
        }
        printf("Going West\n");
        X--;
        maze[Y][X] = '+';
        printMaze(maze);
        break;

    case 3: 
        if (Y+1 > 5){
            return;
        }
        if((maze[Y+1][X] == '#') || (maze[Y+1][X] == '+') || (maze[Y+1][X] == '*') ){
            return;
        }
        printf("Going South\n");
        Y++;
        maze[Y][X] = '+';
        printMaze(maze);
        break;
        

    case 4:
        if (Y < 0){
            return;
        }
        if((maze[Y-1][X] == '#') || (maze[Y-1][X] == '+') || (maze[Y-1][X] == '*')){
            return;
        }

        printf("Going North\n");
        Y--;
        maze[Y][X] = '+';
        printMaze(maze);
        break;
        

//backtracking
    case 5: 
   
    
    if(maze[Y][X+1] == '+'){

        printf("Going back east\n");
        maze[Y][X] = '*';
        X++;
        printMaze(maze);
        return;
    }
    if(maze[Y][X-1] == '+'){

        printf("Going back west\n");
        maze[Y][X] = '*';
        X--;
        printMaze(maze);
        return;
    }
    if(maze[Y+1][X] == '+'){

        printf("Going back South\n");
        maze[Y][X] = '*';
        Y++;
        printMaze(maze);
        return;
    }
    if(maze[Y-1][X] == '+'){

        printf("Going back North \n");
        maze[Y][X] = '*';
        Y--;
        printMaze(maze);
        return;
    }
    default:
    break;

}


if(success){
    printf("The robot has found the solution path\n");
    printMaze(maze);
    exit(0);

//Calling the path finding functions
}else{
    mazeGo(east);
    mazeGo(west);
    mazeGo(south);
    mazeGo(north);
    mazeGo(backtracking);
    
    
}

}

int main() {

    printMaze(maze);
    mazeGo(0);
    return(0) ;
}