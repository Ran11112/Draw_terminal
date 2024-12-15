#ifndef DRAWTERMINAL_H
#define DRAWTERMINAL_H


#define height 50
#define width 50

typedef struct {
  int Display[height][width];

}Screen;

//init the display
void init_display(Screen *screen);


//To config the terminal.. or something
void setNonBlockingInput();

//Display function to display
void display_function(Screen screen);

//To clear display buffer
void clear_display(Screen* screen);

//clear terminal.. also sets refresh rate kindof like FPS
void clear_terminal();






//Drawing functions

//Draw a pixel
void draw_pixal(Screen* screen, int x, int y);

//Draw a square
void draw_square(Screen* screen, int x, int y, int side, int fill);

//Draw circle
void draw_circle(Screen* screen, int h, int k, int r );





#endif