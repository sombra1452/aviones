



#include <ncurses.h>
#include <unistd.h>


// Declarations
#define DELAY 30000
#define TRUE 1
#define FALSE 0

// Declarations for functions

// void mover_personaje(int axe_max_y, int axe_max_x, char letter);

int main(int argc, char *argv[]) {
    

    /* 
     *  SIZE OF SCREEN
     */
    int axe_x = 0, axe_y = 1;  
    int axe_max_x = 0, axe_max_y = 0;  
    int next_x = 0;
int X = 0;
int Y = 0;
    /*
     *  VELOCITY
     */
    int direction = 1;

    /*
     *  PERSON
     */
    // char letter = 'O';
    

    /*
     *  INIT SCREEN
     */
    initscr();
    noecho();
    curs_set(FALSE);

    
    
    


    // NUMBER OF KEY
    int c;

    while(TRUE) {

        getmaxyx(stdscr, axe_max_y, axe_max_x);
        clear();

        mvprintw(0,0, "My: %d - y: %d - Mx: %d - x: %d", 
                    axe_max_y, axe_y, axe_max_x, axe_x);    
        // mvprintw(axe_y, axe_x, "%c",letter);

       /* DIBUJAR AVION */     
        
        mvprintw(axe_y+2, axe_x+6, ")");
        mvprintw(axe_y+6, axe_x+4, "v ");
        mvprintw(Y+6, X+4, "v ");
        mvprintw(axe_y+5, axe_x+3, "|");
        mvprintw(axe_y+5, axe_x+4, "0");
        mvprintw(axe_y+5, axe_x+5, "|");
        mvprintw(axe_y+4, axe_x, "(");
        mvprintw(axe_y+4, axe_x+1, "=");
        mvprintw(axe_y+4, axe_x+2, "=");
        mvprintw(axe_y+4, axe_x+3, " ");
        mvprintw(axe_y+4, axe_x+4, "?");
        mvprintw(axe_y+4, axe_x+5, " ");
        mvprintw(axe_y+4, axe_x+6, "=");
        mvprintw(axe_y+4, axe_x+7, "=");
        mvprintw(axe_y+4, axe_x+8, ")");
        mvprintw(axe_y+3, axe_x+4, "|");
        mvprintw(axe_y+2, axe_x+2, "(");
        mvprintw(axe_y+2, axe_x+3, "-");
        mvprintw(axe_y+2, axe_x+4, "-");
        mvprintw(axe_y+2, axe_x+5, "-");

      

                

        int char_number;

        switch (char_number=getch()){
            
            // UP : key I
            case 105:
                axe_y -= direction;
                break;

            // LEFT : key J
            case 106:
                axe_x -= direction;
                break;

            // DOWN : key K
            case 107:
                if (axe_y ==  axe_max_y-6) {
                    axe_y = axe_max_y-6;
                } else {
                    axe_y += direction;
                }
                break;

            // RIGHT : key L
            case 108:
                if (axe_x == axe_max_x-9) {
                    axe_x = axe_max_x-9;
                } else {
                    axe_x += direction;
                }
                break;

                
                case 32:
                while (Y >1){
                mvprintw( X, Y+=1,"v");}

                break;

            default:
                break;
        }   
       
              
        // NON OUT OF WINDOW
        
        if (axe_x < 0) {
            axe_x = 0;
        } /*
        else if (axe_x > axe_max_x) {
            axe_x = axe_max_x-1;
        }
        */
        else if (axe_y < 1) {
            axe_y = 1;
        }
        /*
        else if (axe_y > axe_max_y){
            axe_y = axe_max_y-1;
        }
        */
        
        
        // mvprintw(axe_y,axe_x, "%c", letter);
        refresh();
        usleep(DELAY);
 

    } 

/*
    attroff(COLOR_PAIR(1));
    stop_color();
*/
    endwin();

    return 0;
}

