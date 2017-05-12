#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
/*********************/
/* Problems I faced */
//moving left or right made the player go out of bounds.
//solution- only allow left movement when player is greater than one space away from boundary, same for right


/********************/
//goes out of bounds, concept works tho!
//add new function to add connecting paths to edd lines of stars
void printMaze(char maze[10][10],int,int);
void aMaze(char maze[10][10],int,int);
//path creators
void zero3(char maze[10][10],int,int);
void four(char maze[10][10],int,int);
void five9(char maze[10][10],int,int);

int main()
{
    char maze[10][10];
    int x,y;


    aMaze(maze,10,10);

 printMaze(maze,10,10);


    return 0;
}

//print the maze
void printMaze(char maze[10][10],int sizeX,int sizeY)
{
     int x,y,r,c;
     char move;
    // maze[0][2] = 'M';

          for(x=0;x<sizeX;x++)
    {
        for(y=0;y<sizeY;y++)
        {
            if(x == 0 && maze[x][y] == ' ')
            {
                maze[x][y] = 'J';
            }
            printf("%c",maze[x][y]);
        }
        puts("");
    }
//    r = 0;
//    c=2;
    while (r < 10)
    {

             //move = getc(stdin);

                    scanf("%c",&move);



        if (move == 's' && ((r <4 && (c >=2 && c<= 3)) || ((r >= 4 && r <10) && (c >= 7 && c <= 8)))  )
        {

                    maze[r][c]= ' ';
                    r++;
                    maze[r][c] = 'M';

        }



        else if(move == 'w' && r >=0)
              {


                    maze[r][c]= ' ';
                    r--;
                    maze[r][c] = 'M';

              }
               else if(move == 'd' && ((r == 4 && (c >1 && c<8)) || ((r >= 0 && r <= 4) && c == 2 )))
              {


                    maze[r][c]= ' ';
                    c++;
                    maze[r][c] = 'M';


              }
                  else if(move == 'a' && ((((r >= 0 && r <= 4) && c == 3)) || (r == 4 && (c >3 && c<9)) || ((r >= 5 && r <10) && c == 8)) )
              {


                    maze[r][c]= ' ';
                    c--;
                    maze[r][c] = 'M';


              }
                system("cls");
                for(x=0;x<sizeX;x++)
                    {
                        for(y=0;y<sizeY;y++)
                    {
                        printf("%c",maze[x][y]);
                    }
                        puts("");
                    }



    }

}
//create starting points
void aMaze(char maze[10][10],int sizeX,int sizeY)
{
     int x,y,start,Prevpath,count;
    srand(time(NULL));


          for(x=0;x<sizeX;x++)
    {
        start = rand()%10;

        for(y=0;y<sizeY;y++)
        {
            if(x == 0 || ((x%2)== 0))

            {
                if(y == start)
            {
                    maze[x][y]=' ';
//                     if(x > 0)
//            {
//
//
//              if(start <= Prevpath)
//              {
//                  y=Prevpath;
//                  for(count=start; count <=y; count++)
//                  {
//                      maze[x][count] = ' ';
//                  }
//              }
//
//            }

            }
            else{
                maze[x][y] = '*';
            }
            }
            else
            {
               maze[x][y] = '*';
            }
            if(x == 9 && y == Prevpath)
            {
                maze[x][y] = ' ';
            }


            //creates paths, function names are the rows
//            zero3(maze,x,y);
//            four(maze,x,y);
//            five9(maze,x,y);

        }
        if(x%2 == 0)
        {
           Prevpath = start;
        }



}
}

void zero3(char maze[10][10],int x,int y)
{
     if((x == 0 || x == 1 || x == 2 || x == 3) && (y == 2 || y == 3) )

            {
                 maze[x][y] = ' ';
            }
}

void four(char maze[10][10],int x,int y)
{
      if(x == 4 && (y == 2 || y == 3 || y == 4 || y == 5 || y == 6 || y == 7 || y == 8))
            {
                maze[x][y]= ' ';
            }
}

void five9(char maze[10][10],int x,int y)
{
       if((x == 5 || x == 6 || x == 7 || x == 8 || x == 9) && (y == 7 || y == 8))
            {
                maze[x][y] = ' ';
            }
}

