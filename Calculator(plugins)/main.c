#include "header.h"

    void main()
    {
        float result = 0.0;
        float num1 = 0.0, num2 = 0.0;
        int option;
        
        float (*func)(float a, float b);
        
        void * l_h1 = dlopen("./plugins/libsum.so", RTLD_NOW);
        void * l_h2 = dlopen("./plugins/libsubtraction.so", RTLD_NOW);
        void * l_h3 = dlopen("./plugins/libmultiplication.so", RTLD_NOW);
        void * l_h4 = dlopen("./plugins/libdivision.so", RTLD_NOW);
        
        while(1)
        {
        
            system("clear");
            menu(result);
            
            printf("Choose an option: \n");
            
            if(!scanf("%d", &option))
            {
                printf("Error: wrong button!\n");
                break;
            }
            
	    switch(option)
	    {
	        case 1:
	            func = dlsym(l_h1, "sum");
	            result = func(num1, num2);  
	        break;
	        
	        case 2:
                    func = dlsym(l_h2, "subtraction");
                    result = func(num1, num2);     
                break;

	        case 3:
	            func = dlsym(l_h3, "multiplication");
	            result = func(num1, num2);
                break;
                
                case 4:
		    func = dlsym(l_h4, "division");		    
	            result = func(num1, num2);  	           
                break;

                case 5:
		     result = 0.0;
                break;

	        case 6:
                    system("clear");     
                    exit(0);               
		break;
               
            }
        }
         dlclose(l_h1);
         dlclose(l_h2);
         dlclose(l_h3);
         dlclose(l_h4);
    }
