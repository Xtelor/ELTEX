#include "header.h"

    void menu(float Result)
    {
       struct dirent **namelist;
       int  n = scandir("./plugins/", &namelist, 0, alphasort);
       
        if (n < 0)
        {
            perror("Error");
            exit(EXIT_FAILURE);
        }
        
        if (n == 2)
        {
             printf("Folder is empty.\n");
        }
        
        int a = 0;
        
        printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("   Libraries:\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
        
        while( a < n)
        {
            if(a > 1)
            {
            printf("  %s\n", namelist[a]->d_name);
            }
            free(namelist[a]);
            a++;
        }
        free(namelist);
    
         printf("~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        printf("   Calculator \n");
	 printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("    Options:  \n");
        printf("  1)    +     \n");
        printf("  2)    -     \n");
        printf("  3)    *     \n");
        printf("  4)    /     \n");
        printf("  5)    C     \n");
        printf("  6)  Close   \n");
         printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("    Result:   \n");
        printf(" %10.4f      \n", Result);
         printf("~~~~~~~~~~~~~~~~~~~~~~~\n");

    }
