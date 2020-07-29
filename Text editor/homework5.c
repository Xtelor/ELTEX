#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <curses.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX_NAME_LEN 30

    const char m[3][20] = {
        "F1 - Open file; ",
        "F2 - Save changes; ",
        "F3 - Exit. "
    };

    WINDOW * menwin;
    int row = 0, col = 0, line = 0;
    int fd, width, height;
    char file[MAX_NAME_LEN];
  


    void sig_winch(int signo)
    {
        struct winsize size;
        ioctl(fileno(stdout), TIOCGWINSZ, (char *) &size);
        resizeterm(size.ws_row, size.ws_col);
    }

    void menu()
    {
        refresh();
        echo();
        menwin = newwin(3, width, height - 4, 4);
      

        for (int i = 0; i < 3; i ++)
        {
            wprintw(menwin, m[i]);
            wprintw(menwin, "\n");
        }
        wrefresh(menwin);
    }

    int len(int n)
    {
        int linel = COLS - 1;
        while (mvinch (n, linel) == ' ' && linel >= 0 )
        {
            linel --;
        }
        return linel + 1;
    }


    void button_f2()
    {
        int flag = O_WRONLY | O_TRUNC;
        fd = open(file, flag);
        
        if( fd == -1 )
        {
            endwin();
            perror("Failed to open");
            exit(1);
        }

         int length;
         char c;

         for(int i = 0; i < LINES - 4; i ++)
         {
             length = len(i);
             for(int j = 0; j < length; j ++)
             {
                 c = mvinch(i, j) & A_CHARTEXT;
                 write(fd, &c, 1);
             }
             write(fd, "\n", 1);
         }
         close(fd);
    }

    void button_f1(int flag)
    {
        WINDOW * win;
        char c;

        refresh();
        echo();

        win = newwin(1, MAX_NAME_LEN, 0, 0);

        wprintw(win, "Enter the filename: ");
        wgetnstr(win, file, MAX_NAME_LEN);
    
    
        wrefresh(win);
        delwin(win);
        clear();

        menu();
        fd = open(file, flag);

        if( fd == -1 )
        {
            endwin();
            perror("Failed to open");
            exit(1);
        }
        
        for(;;)
        {
            if(read(fd, &c, 1) == 1)
            {
                addch(c);
                if(c == '\n'){
                    line ++;
                }
            }
            else 
            {
                break;
            }
        }  
        close(fd);
    }

    void buttons()
    {
        noecho();
        int ch = getch();
        switch(ch)
        {
            case KEY_F(1):
                button_f1(O_RDONLY);
            break;

            case KEY_F(2):
                button_f2();
            break;

            case KEY_F(3):
                close(fd);
                delwin(menwin);
                endwin();
                exit(0);
            break;

            case KEY_UP:
                if (row > 0)
                {
                    row --;
                }
            break;

            case KEY_DOWN:
                row ++;
            break;

            case KEY_LEFT:
                if (col > 0)
                {
                    col --;
                }
            break;

            case KEY_RIGHT:
                col ++;
            break;

            case KEY_DC:
                delch();
            break;

            case KEY_BACKSPACE:
                if(col >= 0)
                {
                    delch();
                    col --;
                }
                if (col < 0)
                {
                    col ++;
                }
            break;

            default:
                insch(ch);
                move(row, col ++);
                refresh();
            break;
        }
    }

    int main(int argc, char ** argv)
    {
        initscr();
        signal(SIGWINCH, sig_winch);
        keypad(stdscr, TRUE);


        getmaxyx(stdscr, height, width);


        menu();

        for(;;)
        {
            move(row, col);
            refresh();
            buttons();
        }

        delwin(menwin);
        endwin();
        return 0;
    }
