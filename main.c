#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);

  //Letter A
  draw_line(10, 0, 45, 350, s, c); //left leg
  draw_line(50, 350, 90, 0, s, c); //right leg
  draw_line(20, 175, 80, 175, s, c); //middle line

  //Letter n
  draw_line(110, 0, 110, 175, s, c); //left leg
  draw_line(190, 0, 190, 175, s, c); //right leg
  draw_line(111, 175, 190, 175, s, c); //middle line

  //Letter i
  draw_line(250, 0, 250, 175, s, c); //body

  //Letter s
  draw_line(310, 2, 390, 2, s, c); //bottom piece
  draw_line(390, 2, 390, 90, s, c); //right vertical
  draw_line(310, 90, 390, 90, s, c); //middle
  draw_line(310, 90, 310, 175, s, c); //left vertical
  draw_line(310, 175, 390, 175, s, c); //top

  //letter h
  draw_line(410, 0, 410, 350, s, c); //tall vertical
  draw_line(410, 175, 490, 175, s, c); //middle flat
  draw_line(490, 0, 490, 175, s, c); //right vertical

  //OCTANT 1 TEST:
  draw_line(0, 400, 400, 490, s, c);
  draw_line(100, 400, 400, 490, s, c);

  //OCTANT 8 TEST:
  draw_line(0, 490, 400, 400, s, c);
  draw_line(100, 490, 400, 400, s, c);


  display(s);
  save_extension(s, "lines.png");
}
