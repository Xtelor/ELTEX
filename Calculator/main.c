#include "header.h"

    int main()
    {
        float result = 0.0;
        float num1 = 0.0, num2 = 0.0;
        int option;

        while(1)
        {
            system("clear");
            menu(result);

            printf("Choose an option: ");
	          scanf("%d", &option);

	          switch(option)
	          {
	              case 1:
		                result = sum(num1, num2);
                break;

		            case 2:
		                result = subtraction(num1, num2);
                break;

	              case 3:
				            result = multiplication(num1, num2);
                break;

			          case 4:
				            result = division(num1, num2);
                break;

			          case 5:
				            result = 0.0;
                break;

			          case 6:
                    system("clear");
				            exit(0);
                break;

			          default:
				            printf("Error: wrong option.\n");
                    exit(0);
				        break;
		       }
        }
        return 0;
    }
