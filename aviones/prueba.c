#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY 1000









int main() {


  /* posicion en xYy del AVION */
  int avion = 0;
  
  int movimiento = 0;

  /* variable de movimiento del AVION */
  int teclado= 0;
  int xMax = 0, N = 0;

  /* inicializacion de ncurses */
  initscr();
  noecho();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  int nx = 0;

  while(1){
    getmaxyx(stdscr,N,xMax);
    clear();

    // inicializa colores
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);

    
    //dibuja el AVION
    attron(COLOR_PAIR(2));
      mvprintw(-11+N,5 + avion, "/\\");
      mvprintw(-10+N,5 + avion, "\\ \\");
      mvprintw(-9+N, 6 + avion, "\\ \\");
      mvprintw(-8+N, 6 + avion, "/  \\");
      mvprintw(-7+N, 5 + avion, "<===>\\");mvprintw(N-7,8 + nx,"=>");
      mvprintw(-6+N, 5 + avion, "<    )>");
      mvprintw(-5+N, 5 + avion, "<===>/");mvprintw(N-5,8 + nx,"=>");
      mvprintw(-4+N, 6 + avion, "\\  /");
      mvprintw(-3+N, 6 + avion, "/ /");
      mvprintw(-2+N, 5 + avion, "/ /");
      mvprintw(-1+N, 5 + avion, "\\/");
      
 
      switch( teclado = getch()){
     
        // W
        case 119:
        
          N -2; 
          break;
        // S,
        case 115:
          N +2;
          break;
        //D
         case 100:
         avion +=2 ; nx +=2;
         break;
         //A
         case 97:
         avion -= 2 ; nx -=2;
         break;

		  


        default:
          attron(COLOR_PAIR(2));
          mvprintw(4,5, "TECLA:");
          mvprintw(4,12, "%d", teclado);
          refresh();
          getch();
          break;
    
    
    
  }
  refresh();
    usleep(DELAY);
}
endwin();
  return 0;
}