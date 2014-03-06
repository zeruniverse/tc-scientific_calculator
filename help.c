#include"calc.h"
void help(void)
{
     closegraph();
     system("cls");
     printf("******\n");
	 printf("scientific calculator V1.0\n");
	 printf("******\n");
	 printf("You can control the calculator by keyboard and mouse.\n");
	 printf("Left-press bottons and some key(Enter is =) to input.\n");
	 printf("in graphical interface, right-press and press Ecs key can exit the program.\n");
	 printf("There are four modes.");
	 printf("The scientific mode can do calculating for expression with + - * / () \n");
	 printf("And in scientific mode, there're base-n mode to change base and do bitwise calculating.\n");
	 printf("some signs may be confusing.\n");
	 printf("[]means find the greatest integer smaller than the number.\n");
	 printf("'Ans' in scientific mode means print the former result.\n");
	 printf("********\n");
	 printf("You can see some help in some modes which are difficult to use.\n");
	 printf("********\n");
	 printf("********\n");
	 printf("We have detailed instructions in chinese for you to follow if there're more problems.\n");
	 printf("They're attached to our final report.\n");
	 printf("Press any key to turn to standard mode.\n");

     bioskey(0);
     mode=0;
}
