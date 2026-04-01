#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int inputChoice() {
	int choice;
	do {
		printf( "Plase enter selected your option on the menu: " );
		scanf("%d", &choice);
	} while ( choice <=0 && choice != getchar() );
	return choice;
}

void displayMenuOptions() {
	printf("\n=================================\n");
	printf("|             MENU              |\n");
	printf("=================================\n");
	printf("| 1. Optional calculator        |\n");
	printf("| 2. Optional array calculator  |\n");
	printf("| 3. Exit menu                  |\n");
	printf("=================================\n\n");
}

void displayMenuCalculator() {
	printf("\n================================\n");
	printf("|          CALCULATOR          |\n");
	printf("================================\n");
	printf("| 1. Addition (+)              |\n");
	printf("| 2. Subtraction (-)           |\n");
	printf("| 3. Multiplication (*)        |\n");
	printf("| 4. Division (/)              |\n");
	printf("| 5. Back to main menu         |\n");
	printf("================================\n");
}

void displaySortArray() {
	printf("\n===================================================\n");
	printf("|                      ARRAY                      |\n");
	printf("===================================================\n");
	printf("| 1. Create a random array with random elements   |\n");
	printf("| 2. Search for elements in an array              |\n");
	printf("| 3. Sort the array randomly in ascending order   |\n");
	printf("| 4. Sort the array randomly in descending order  |\n");
	printf("| 5. Back to main menu                            |\n");
	printf("===================================================\n");
}

int inputSizeArray() {
	int size = 0;
	printf("Please enter size of array: ");
	scanf("%d", &size);
	return size;
}

int inputSearchKey() {
	int key = 0;
	printf("Please enter key: ");
	scanf("%d", &key);
	return key;
}

int* createRandomArray(int *size_out) {
	int size = inputSizeArray();
	*size_out = size;
	int *array = (int*)malloc(size * sizeof(int));
	srand(time(NULL));
	for(int i = 0; i < size - 1; i++) {
		array[i] = rand() % size;
	}
	return array;
}

int* copyArray(int *original, int size) {
    if (original == NULL) return NULL;
    
    int *newCopy = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        newCopy[i] = original[i];
    }
    return newCopy;
}

void sortArray(int *arr, int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            bool condition = ascending ? (arr[j] > arr[j + 1]) : (arr[j] < arr[j + 1]);
            if (condition) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayArray(int *array, int size) {
	if (array == NULL) {
		printf("Array is empty.\n");
		return;
	}
	printf("The array elements are: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	system("pause");
}

void displayArrayWithoutPause(int *array, int size) {
	if (array == NULL) {
		printf("Array is empty.\n");
		return;
	}
	printf("The array elements are: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int inputNumber(char *index_name) {
	int number = 0;
	printf( "Please enter %s: ", index_name );
	scanf("%d", &number);
	return number;
}

void displaySearchResult(int *array, int size) {
	int key = inputSearchKey();
	if (array == NULL) {
		printf("Array is empty.\n");
		return;
	}
	printf("The array elements are equal key: ");
	for (int i = 0; i < size; i++) {
		if(array[i] == key) {
			printf("[%d] = %d ", i, array[i]);
		}
	}
	printf("\n");
	system("pause");
}

int sumTwoNumbers() {
	char titleFirstNumber[] = "first number";
	char titleSecondNumber[] = "second number";
	int a = inputNumber(titleFirstNumber);
	int b = inputNumber(titleSecondNumber);
	int result = a + b;
	return result;
}

int subTwoNumbers() {
	char titleFirstNumber[] = "first number";
	char titleSecondNumber[] = "second number";
	int a = inputNumber(titleFirstNumber);
	int b = inputNumber(titleSecondNumber);
	int result = a - b;
	return result;
}

int multTwoNumbers() {
	char title_first_number[] = "first number";
	char title_second_number[] = "second number";
	int a = inputNumber(title_first_number);
	int b = inputNumber(title_second_number);
	int result = a * b;
	return result;
}

void divTwoNumbers() {
	float result = 0;
	char titleFirstNumber[] = "first number";
	char titleSecondNumber[] = "second number";
	int a = inputNumber(titleFirstNumber);
	int b = inputNumber(titleSecondNumber);
	result = (float) a / b;
	if( b == 0 ) {
		printf("Second number must be greater than zero\n");
		system("pause");
	} else {
		printf("Result: %.2f\n", result);
		system("pause");
	}
}

void displayResultInInteger(int result) {
	printf("Result: %d\n", result);
	system("pause");
}

void menuCalculator() {
	int choice;
	bool flag = true;
	do {
		int sum = 0;
		int	sub = 0;
		int mult  = 0;
		system("cls");
		displayMenuCalculator();
		choice = inputChoice();
		switch (choice) {
			case 1:
				sum = sumTwoNumbers();
				displayResultInInteger(sum);
				flag = true;
				break;
			case 2:
				sub = subTwoNumbers();
				displayResultInInteger(sub);
				flag = true;
				break;
			case 3:
				mult = multTwoNumbers();
				displayResultInInteger(mult);
				flag = true;
				break;
			case 4:
				divTwoNumbers();
				flag = true;
				break;
			case 5:
				system("cls");
				flag = false;
				break;
			default:
				printf("Invalid selection. Please choose a number between 1 and 5.\n");
				system("pause");
				flag = true;
				break;
		}
	} while (flag);
}

void menuArray() {
	int choice, numberArray;
	bool flag = true;
	int *array = NULL;
	int size;
	do {
		system("cls");
		displaySortArray();
		choice = inputChoice();
		switch (choice) {
			case 1:
				if (array != NULL) {
					free(array);
				}
				array = createRandomArray(&size);
				displayArray(array, size);
				flag = true;
				break;
			case 2:
				if (array == NULL) {
					printf("Must choose option 1 for create array\n");
					system("pause");
				}
				displayArrayWithoutPause(array, size);
				displaySearchResult(array, size);
				flag = true;
				break;
			case 3:
				if (array == NULL) {
					printf("Must choose option 1 for create array\n");
					system("pause");
				} else {
                    int *tempArray = copyArray(array, size); 
                    sortArray(tempArray, size, true);
                    printf("Ascending ");
                    displayArray(tempArray, size);
                    free(tempArray);
                }
				flag = true;
				break;
			case 4:
				if (array == NULL) {
					printf("Must choose option 1 for create array\n");
					system("pause");
				} else {
                    int *tempArray = copyArray(array, size); 
                    sortArray(tempArray, size, false);
                    printf("Descending ");
                    displayArray(tempArray, size); 
                    free(tempArray);
                }
				flag = true;
				break;
			case 5:
				flag = false;
				break;
			default:
				printf("Invalid selection. Please choose a number between 1 and 5.\n");
				system("pause");
				flag = true;
				break;
		}
	} while (flag);
}

void mainMenu () {
	int choice;
	bool flag = false;
	do {
		system("cls");
		displayMenuOptions();

		choice = inputChoice();
		switch (choice) {
			case 1 :
				menuCalculator();
				break;
			case 2 :
				menuArray();
				break;
			case 3 :
				printf("Thanks, see you again!\n");
				break;
			default :
				printf("Invalid selection. Please choose a number between 1 and 3.\n");
				system("pause");
		}
	} while (flag);
}

int main ( void ) {
	mainMenu();
	return 0;
}