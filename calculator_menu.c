#include <stdio.h>


int inputChoice() {
	int choice;
	printf( "Plase enter selected your option on the menu: " );
	scanf("%d", &choice);
	return choice;
}

int main ( void )
{
	int choice = inputChoice();
	printf( "%d", choice );
	return 0;
}