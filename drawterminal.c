#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h> //for usleep()
#include <termio.h> //used for the termal seeting
#include <fcntl.h> //non-blocking input purpose

#include "drawterminal.h"

#define height 50
#define width 50


/*
typedef struct {
  int Display[height][width];

}Screen;
*/

//Does some terminal setting.. took from chatgpt (don't have much idea but it enables non-blocking input)
void setNonBlockingInput() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t); // Get current terminal settings
    t.c_lflag &= ~ICANON;        // Disable canonical mode
    t.c_lflag &= ~ECHO;          // Disable echoing
    tcsetattr(STDIN_FILENO, TCSANOW, &t); // Apply new settings
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK); // Set non-blocking input
}



//init the display by setting all 0 in each value
void init_display(Screen* screen){
  memset(screen->Display, 0, sizeof(screen->Display));
}

//Display function
void display_function(Screen screen){
  for (int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      if(screen.Display[i][j] == 0){
        printf("  ");
      }else{  //elseif (screen.Display[i][j] == 1) #Updated from this
        printf("██");
      }
    }
    printf("\n");
  }

}

// clear the display array
void clear_display(Screen* screen){
  memset(screen->Display, 0, sizeof(screen->Display));
}

//clears the terminal
void clear_terminal(){
  usleep(100000);
  system("clear");
}







//Draws a pixel
void draw_pixel(Screen *screen,int x, int y){
  screen->Display[y][x] = 1;
}
//Draws a box/square.. well more like a rectangle (looks like it)
void draw_square(Screen *screen, int x, int y, int side, int fill){

  if(fill == 1){
    for(int i = 0; i < side; i++){
      for(int j = 0; j < side; j++){
        screen->Display[x + i][y + j] = 1;
      }
    }
  }else{
    for(int i=0; i < side; i++){
      screen->Display[x+i][y] = 1;
    }
    for(int i=0; i < side; i++){
      screen->Display[x][y + i] = 1;
    }
    for(int i=0; i < side; i++){
      screen->Display[x + i][y + side] = 1;
    }
    for(int i = 0; i < side; i++){
      screen->Display[x + side][y + i] = 1;
    }
  }

}

//Draw circle
void draw_circle(Screen *screen, int h, int k, int r) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Adjust x to account for aspect ratio if needed
            float scaled_x = x * 2; // Adjust based on terminal dimensions
            if ((scaled_x - h) * (scaled_x - h) + (y - k) * (y - k) <= r * r) {
                screen->Display[y][x] = 1; // Mark the point as part of the circle
            }
        }
    }
}

/*
//Main loop
int main(){

  setNonBlockingInput();

 // Screen screen = { .Display = { {0} }};

  int player_x = 10;
  int player_y = 10;
  char input = 'a';

  int movement_x = 1;
  int movement_y = 1;


  /*while (input != 'q')
  {
    draw_pixel(&screen,player_x,player_y);
    display_function(screen);

    input = getchar();

    if(input == 'q') return 0;
    if(input == 'u') player_y -= 1;
    if(input == 'd') player_y += 1;
    if(input == 'l') player_x -= 1;
    if(input == 'r') player_x += 1;

    player_x += movement_x;
    player_y += movement_y;

    if(player_x == width || player_x == 0){
      movement_x = movement_x * -1;
    }
    if(player_y == height || player_y == 0){
      movement_y = movement_y * -1;
    }



    clear_terminal();
    //clear_display(&screen);
  }*/
  
  //draw_circle(&screen, 20,20,15);

  //display_function(screen);



  //Draw
  //draw_square(&screen, 5 , 2, 10, false);

  //Display function call
  //display_function(screen);


  //return 0; 
//} 

