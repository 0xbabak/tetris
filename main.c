#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROWS 3
#define COLS 3
#define NUM_MATRICES 7

void copyMatrix(int matrix[ROWS][COLS], int newmatrix[ROWS][COLS]);
void selectRandomMatrix(int selectedMatrix[ROWS][COLS]);
void flip_left(int part[ROWS][COLS], int resultpart[ROWS][COLS]);
void flip_right(int part[ROWS][COLS], int resultpart[ROWS][COLS]);


int main(){
    int ch;
    int high_score = 0;
    int points;
    printf("[WELCOME TO BABAKS TETRIS GAME]\n");
    printf("High Score:%d\n", high_score);
    printf("to start a new game press enter\nto end the game press'Q'");
    scanf("%c", &ch);
    while(ch != 'Q')
    {
        int M;
        int N;
        int points = 0;
        int area[6][6];
        printf("Please enter the number of rows of area: ");
        scanf("%d", &M);
        printf("Please enter the number of columns of area: ");
        scanf("%d", &N);
        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                area[i][j] = 0;
            }
        }
        srand(time(NULL));
    
        while(ch != 'Q')
        {
            //generate a random part
            int selectedMatrix[ROWS][COLS];
            selectRandomMatrix(selectedMatrix);
            printf("Score: %d\n", points);
            printf("Your generated part: \n");
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    printf("%d  ", selectedMatrix[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            int ln = 0;
            for(int i = 0; i <= M; i++)
            {
                        
                if(ln == 0 || ln == M)
                {
                    for(int j = 0; j < M; j++)
                    {
                        printf("- -");
                    }
                    if(ln == 0)
                    {
                        printf("\n");
                    }
                }
                ln = ln + 1;
                for(int j = 0; j < N && i < M; j++)
                {
                    if(j == 0)
                    {
                        printf("|");
                    }
                    if(j != N-1)
                    {
                        printf("%d  ", area[i][j]);
                    }
                    if(j == N-1)
                    {
                        printf("%d", area[i][j]);
                        printf("|");
                    }
                }
                printf("\n");
            }
            char rotate = 'A';
            int selectedNewMatrix[ROWS][COLS];
            while(rotate != 'N')
            {
                printf("Enter rotation(L: left|R: right|N: no rotation):");
                scanf(" %c", &rotate);
                if(rotate == 'L' || rotate == 'R' || rotate == 'N')
                {  
                    if(rotate == 'R')
                    {
                        flip_right(selectedMatrix, selectedNewMatrix);
                        copyMatrix(selectedNewMatrix, selectedMatrix);
                    }
                    if(rotate == 'L')
                    {
                        flip_left(selectedMatrix, selectedNewMatrix);
                        copyMatrix(selectedNewMatrix, selectedMatrix);
                    }
                    printf("Score: %d\n", points);
                    printf("Your generated part: \n");
                    for(int i = 0; i < 3; i++)
                    {
                        for(int j = 0; j < 3; j++)
                        {
                            printf("%d  ", selectedMatrix[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    ln = 0;
                    for(int i = 0; i <= M; i++)
                    {
                        
                        if(ln == 0 || ln == M)
                        {
                            for(int j = 0; j < M; j++)
                            {
                                printf("- -");
                            }
                            if(ln == 0)
                            {
                                printf("\n");
                            }
                        }
                        ln = ln + 1;
                        for(int j = 0; j < N && i < M; j++)
                        {
                            if(j == 0)
                            {
                                printf("|");
                            }
                            if(j != N-1)
                            {
                                printf("%d  ", area[i][j]);
                            }
                            if(j == N-1)
                            {
                                printf("%d", area[i][j]);
                                printf("|");
                            }
                        }
                        printf("\n");
                    }
                }
                else
                {
                    printf("Please Enter a valid rotation: \n");
                }
            }
    
            int x;
            int value = 0;
            int leftmostN;
            int rightmostN;
            for(int i = 0; i < 3 && value != 1; i++)
            {
                for(int j = 0; j < 3 && value != 1; j++)
                {
                    if(selectedMatrix[j][i] == 1)
                    {
                        value = 1;
                        leftmostN = i;
                    }
                }
            }
            value = 0;
            for(int i = 2; i >= 0 && value != 1; i--)
            {
                for(int j = 2; j >= 0 && value != 1; j--)
                {
                    if(selectedMatrix[j][i] == 1)
                    {
                        value = 1;
                        rightmostN = i;
                    }
                }
            }
            value = 0;
            int lowerM;
            for(int i = 2; i >= 0 && value != 1; i--)
            {
                for(int j = 2; j >= 0 && value != 1; j--)
                {
                    if(selectedMatrix[i][j] == 1)
                    {
                        value = 1;
                        lowerM = i;
                    }
                }
            }
    
    
            int done = 1;
            int validX = 0;
            int shift;
            while(validX != 1)
            {
                value = 0;
                shift = 0;
                int wrong = 0;
                printf("Which Column do you want to place the part: ");
                scanf(" %d", &x);
                x = x - 1;
                if((rightmostN - leftmostN) + x > N)
                {
                    printf("Please enter another value for column the part will fall out of border\n");
                }
                if(x + (rightmostN - leftmostN) <= N)
                {
                    int copyM = M - 1;
                    while(done != 0 && shift <= M)   
                    {
                        int k = leftmostN;
                        int e = lowerM;
                        wrong = 0;
                        for(int i = copyM; e >= 0; i--)
                        {
                            for(int j = x;k <= rightmostN; j++)
                            {
                                if(selectedMatrix[e][k] == 1 && area[i][j] == 1)
                                {
                                    wrong = 1;
                                }
                                k++;
                            }
                            k = leftmostN;
                            e--;
                        }
                        if(wrong == 1)
                        {
                            copyM = copyM - 1;
                            shift = shift + 1;
                            wrong = 0;
                        }
                        else
                        {
                            done = 0;
                        }
                    }
                }
                if(done == 0)
                {
                    validX = 1;
                }
                if(done == 1)
                {
                    printf("Invalid column value. Please enter another value.\n");
                }
            }
            int k = leftmostN;
            int e = lowerM;
            for(int i = M - shift - 1; e >= 0; i--)
            {
                for(int j = x;k <= rightmostN; j++)
                {
                    if(selectedMatrix[e][k] == 1 && area[i][j] == 0)
                    {
                        area[i][j] = selectedMatrix[e][k];
                    }
                    k++;
                }
                e--;
                k = leftmostN;
            }
            int count = 0;
            int removedlines[100];
            for(int i = 0; i < M; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    count = count + area[i][j];
                }
                if(count == N)
                {
                    removedlines[i] = 1;
                    points = points + N;
                }
                count = 0;
            }
            for(int i = 0; i < M; i++)
            {
                if(removedlines[i] == 1)
                {
                    for(int j = i; j > 0; j--)
                    {
                        for(int l = 0; l < N; l++)
                        {
                            area[j][l] = area[j-1][l];
                        }
                    }
                    for(int j = 0; j < N; j++)
                    {
                        area[0][j] = 0;
                    }
                }
            } 
        }
        int gameover = 0;
        int end = 0;
        while(gameover == 0 && end < N)
        {
            if(area[0][end] == 1)
            {
                gameover == 1;
            }
            end++;
        }
        if(gameover == 1)
        {
            ch = 'Q';
        }
    }
    if(points>high_score)
    {
        high_score = points;
    }
}

void flip_right(int part[ROWS][COLS], int resultpart[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultpart[j][ROWS - 1 - i] = part[i][j];
        }
    }
}

void flip_left(int part[ROWS][COLS], int resultpart[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultpart[COLS - 1 - j][i] = part[i][j];
        }
    }
}


void copyMatrix(int matrix[ROWS][COLS], int newmatrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            newmatrix[i][j] = matrix[i][j];
        }
    }
}

void selectRandomMatrix(int selectedMatrix[ROWS][COLS]) {
    int randomIndex = rand() % NUM_MATRICES;

    int I[ROWS][COLS] = {{1,1,1},
                         {0,0,0},
                         {0,0,0}};
    int J[ROWS][COLS] = {{1,0,0},
                         {1,0,0},
                         {1,0,0}};
    int L[ROWS][COLS] = {{0,0,1},
                         {1,1,1},
                         {0,0,0}};
    int Z[ROWS][COLS] = {{1,0,0},
                         {0,0,0},
                         {0,0,0}};
    int S[ROWS][COLS] = {{0,1,1},
                         {1,1,0},
                         {0,0,0}};
    int O[ROWS][COLS] = {{1,1,0},
                         {1,1,0},
                         {0,0,0}};
    int T[ROWS][COLS] = {{1,0,0},
                         {1,0,0},
                         {0,0,0}};

    switch (randomIndex) {
        case 0:
            copyMatrix(I, selectedMatrix);
            break;
        case 1:
            copyMatrix(J, selectedMatrix);
            break;
        case 2:
            copyMatrix(L, selectedMatrix);
            break;
        case 3:
            copyMatrix(Z, selectedMatrix);
            break;
        case 4:
            copyMatrix(S, selectedMatrix);
            break;
        case 5:
            copyMatrix(O, selectedMatrix); 
            break;
        case 6:
            copyMatrix(T, selectedMatrix);
            break;
    }
}



