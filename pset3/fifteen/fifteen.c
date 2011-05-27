/***************************************************************************
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements The Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 ***************************************************************************/
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


// constants
// goal: understand what these two constants are for
// .....
#define DIM_MIN 3
#define DIM_MAX 9


// global board
int board[DIM_MAX][DIM_MAX];
int d;


// prototypes
void clear();
void greet();
void swap(int i, int j); // TODO
void init();
void draw();
bool move(int tile);
bool won();
bool check(int row, int column);

int
main(int argc, char *argv[])
{
    // greet user with instructions
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: %s d\n", argv[0]);
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %d x %d and %d x %d, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
     while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();


        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
        }

    // that's all folks
    return 0;
}


/*
 * void
 * clear()
 *
 * Clears screen using ANSI escape sequences.
 */

void
clear()
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}


/*
 * void
 * greet()
 *
 * Greets player.
 */

void
greet()
{
    clear();
    printf("WELCOME TO THE GAME OF FIFTEEN\n");
    usleep(2000000);
}

/*
 * void
 * swap()
 *
 * Swaps second to last value with third to last value of two dimensional
 * array if d is an even value. Will be useful in move(), as well.
 */

void
swap(int i, int j)
{
  int temp;
  for (int a = 0; a < d; a++) {
    for (int b = 0; b < d; b++) {
      if (board[a][b] == 0) {
        temp = board[a][b];
        board[a][b] = board[i][j];
        board[i][j] = temp;
        return;
      }
    }
  }
}

/*
 * void
 * init()
 *
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void
init()
{ 
  int i, j;
  int storeval = d * d; // temporary name for left upmost value
  for (i = 0; i < d; i++) { // rows
    for (j = 0; j < d; j++) { // columns
      board[i][j] = --storeval;
      // TODO
    }
  }
  if (d%2 == 0) { // swap third and second to last tiles
    int temp = board[i-1][j-2];
    board[i-1][j-2] = board[i-1][j-3];
    board[i-1][j-3] = temp;
  }
}


/* 
 * void
 * draw()
 *
 * Prints the board in its current state.
 */

void
draw()
{
  for (int i = 0; i < d; i++) { // rows
    printf("\n");
    for (int j = 0; j < d; j++) { // columns
      if (board[i][j] == 0) {
        printf("%3c| ", 95);
        continue;
      }
      printf("%3d| ", board[i][j]);
    }
  }
  printf("\n\n");
    // TODO
}


/* 
 * bool
 * move(int tile)
 *
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */

bool
move(int tile)
{
  // check block of memory for the tile
  for (int i = 0; i < d; i++) { // row
    for (int j = 0; j < d; j++) { // column
      if (board[i][j] == tile) {
        if (!check(i,j)) // TODO
          return false;
        else {
          swap(i,j); // TODO
          return true;
        }
      }
    }
  }
 return false;
}

/*
 * bool
 * check(int row, int column)
 *
 * Checks whether the tile can be swapped or not. If it can be swapped,
 * check returns true. If it can't, false is returned.
 */

bool 
check(int row, int column)
{
  if (row == d-1) { // last row
    if (column == 0) { // last row FIRST column |_
      if (board[row-1][column] == 0)
        return true;
      else if (board[row][column+1] == 0)
        return true;
    }
    else if (column == d-1) { // last row LAST column _|
      if (board[row-1][column] == 0)
        return true;
      else if (board[row][column-1] == 0)
        return true;
    }
    else { // last row MID column
      if (board[row-1][column] == 0)
        return true;
      else if (board[row][column-1] == 0)
        return true;
      else if (board[row][column+1] == 0)
        return true;
    }
  }
  else if (row == 0) { // first row
    if (column == 0) { // first row FIRST column |^
      if (board[row][column+1] == 0)
        return true;
      else if (board[row+1][column] == 0)
        return true;
    }
    else if (column == d-1) { // first row LAST column ^|
      if (board[row][column-1] == 0)
        return true;
      else if (board[row+1][column] == 0)
        return true;
    }
    else { // top row MID column
      if (board[row+1][column] == 0)
        return true;
      else if (board[row][column+1] == 0)
        return true;
      else if (board[row][column-1] == 0)
        return true;
    }
  }
  else if (column == 0) { // first column |->
    if (board[row-1][column] == 0) // up
      return true;
    else if (board[row+1][column] == 0) // down
           return true;
    else if (board[row][column+1] == 0)
      return true; // -> right
  }
  else if (column == d-1) { // last column <-|
    if (board[row-1][column] == 0) // up
      return true;
    else if (board[row+1][column] == 0) // down
           return true;
    else if (board[row][column-1] == 0)
      return true; // <- left
  }
   else
    {
      if (board[row+1][column] == 0) // row
        return true;
      else if (board[row-1][column] == 0) // down
        return true;
      else if (board[row][column+1] == 0) // ->
        return true;
      else if (board[row][column-1] == 0) // <-
        return true;
    }
  
  return false;
}
/*
 * bool
 * won()
 *
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */

bool
won()
{
  int end = d * d - 1;
  int check = 1;
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++) {
      if (board[i][j] == check && check <= end) {
        check = check + 1;
        continue;
      }
      else if (check > end)
        return true;
      else
        break;
    }
  }
    return false;
}
