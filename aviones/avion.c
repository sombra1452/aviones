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

  while(1){
    getmaxyx(stdscr,N,xMax);
    clear();

    // inicializa colores
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);

    
    //dibuja el AVION
    attron(COLOR_PAIR(2));
      mvprintw(N-11,65 + avion, "/\\");
      mvprintw(N-10,64 + avion, "/ /");
      mvprintw(N-9, 63 + avion, "/ /");
      mvprintw(N-8, 63 + avion, "/  \\");
      mvprintw(N-7, 62 + avion, "/<===>");
      mvprintw(N-6, 61 + avion, "<(    >");
      mvprintw(N-5, 62 + avion, "\\<===>");
      mvprintw(N-4, 63 + avion, "\\  /");
      mvprintw(N-3, 63 + avion, "\\ \\");
      mvprintw(N-2, 64 + avion, "\\ \\");
      mvprintw(N-1, 65 + avion, "\\/");

 
      switch( teclado = getch()){
     
        // W
        case 119:
          N +=2;
          break;
        // S,
        case 115:
          N -=2;
          break;
        //D
         case 100:
         avion +=2;
         break;
         //A
         case 97:
         avion -= 2;
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

