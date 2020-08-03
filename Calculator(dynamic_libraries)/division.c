#include "header.h"

    float division(float num1, float num2)
		{

		    printf("Input dividend: \n");
				scanf("%f", &num1);

				printf("Input divider: \n");
				scanf("%f", &num2);


				while (num2 != 0)
				{
				    return (num1 / num2);
				}

				if (num2 == 0)
				{
				    return 0.0;
				}
    }
