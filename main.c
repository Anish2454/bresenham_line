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
  draw_line(110, 0, 111, 175, s, c); //left leg
  draw_line(189, 0, 190, 175, s, c); //right leg
  draw_line(111, 175, 190, 175, s, c); //middle line

  //Letter i
  draw_line(250, 0, 251, 175, s, c); //body

  //Letter s
  draw_line(310, 2, 390, 2, s, c); //bottom piece
  draw_line(389, 2, 390, 90, s, c); //right vertical
  draw_line(310, 90, 390, 90, s, c); //middle
  draw_line(310, 90, 311, 175, s, c); //left vertical
  draw_line(310, 175, 390, 175, s, c); //top

  //letter h
  draw_line(410, 0, 411, 350, s, c); //tall vertical
  draw_line(410, 175, 490, 175, s, c); //middle flat
  draw_line(489, 0, 490, 175, s, c); //right vertical

  display(s);
  save_extension(s, "lines.png");
}
