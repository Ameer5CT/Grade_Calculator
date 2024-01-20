#include <stdio.h>

#define MAX_EXAMS 100
#define MAX_AVERAGE_LETTERS 9

int main() {
	int i;
	float totalPreWeight = 0;
	float totalPreAverage = 0;
	float grade, weight, minFinal, maxFinal, minGoal, maxGoal;
	char letterGrade[2];
	
	printf("\n ==============================");
	printf("\n ||                          ||");
	printf("\n ||     Grade Calculator     ||");
	printf("\n ||                          ||");
	printf("\n ==============================");
	printf("\n");
	printf("\n This program calculates your grades before the final and informs you of the grade needed in the final to reach your goal");
	
	for(i = 0; i < MAX_EXAMS; i++) {
		if (i > 0) {
			printf("\n ! If there are no other grades enter -1 to get the result !");
		}
		printf("\n Enter grade no.%d (out of 100): ", i + 1);
		scanf("%f", &grade);
		
		if (grade == -1 && i > 0) {
			break;
		}
		
		printf(" How much was its weight (Percent): %%");
		scanf("%f", &weight);
		
		if ( (grade < 0 || 100 < grade) || (weight <= 0 || 100 <= weight) || (100 <= totalPreWeight + weight) ){
			printf("\n Please recheck your inputs.");
			continue;
		}
		
		totalPreAverage = totalPreAverage + (grade * weight / 100);
		totalPreWeight = totalPreWeight + weight;
	}
	
	printf("\n Your average before the final exam is %.1f out of %.1f", totalPreAverage, totalPreWeight);
	printf("\n The weight of the final exam gonna be: %.1f", 100 - totalPreWeight);
	printf("\n The table below shows how much your average gonna be based on the grade that gonna get in the final exam (out of 100)");
	
	printf("\n\n Final_grade \tAverage \tLetter");
	for(i = 0; i < MAX_AVERAGE_LETTERS; i++) {
		switch(i) {
			case 0:
				letterGrade[0] = 'A';
				letterGrade[1] = 'A';
				minGoal = 90;
				maxGoal = 100;
				break;
			case 1:
				letterGrade[0] = 'B';
				letterGrade[1] = 'A';
				minGoal = 85;
				maxGoal = 89.9;
				break;
			case 2:
				letterGrade[0] = 'B';
				letterGrade[1] = 'B';
				minGoal = 80;
				maxGoal = 84.9;
				break;
			case 3:
				letterGrade[0] = 'C';
				letterGrade[1] = 'B';
				minGoal = 75;
				maxGoal = 79.9;
				break;
			case 4:
				letterGrade[0] = 'C';
				letterGrade[1] = 'C';
				minGoal = 70;
				maxGoal = 74.9;
				break;
			case 5:
				letterGrade[0] = 'D';
				letterGrade[1] = 'C';
				minGoal = 65;
				maxGoal = 69.9;
				break;
			case 6:
				letterGrade[0] = 'D';
				letterGrade[1] = 'D';
				minGoal = 60;
				maxGoal = 64.9;
				break;
			case 7:
				letterGrade[0] = 'F';
				letterGrade[1] = 'D';
				minGoal = 50;
				maxGoal = 59.9;
				break;
			case 8:
				letterGrade[0] = 'F';
				letterGrade[1] = 'F';
				minGoal = 0;
				maxGoal = 49.9;
				break;
			default:
				printf("Error");
				break;
		}
		
		minFinal = (minGoal * 100 - totalPreAverage * 100) / (100 - totalPreWeight);
		maxFinal = (maxGoal * 100 - totalPreAverage * 100) / (100 - totalPreWeight);
		
		if (minFinal > 100 || maxFinal < 0) {
			continue;
		}
		
		if (maxFinal > 100) {
			maxFinal = 100;
			maxGoal = totalPreAverage + ( (maxFinal * (100 - totalPreWeight)) / 100);
		}
		if (minFinal < 0) {
			minFinal = 0;
			minGoal = totalPreAverage + ( (minFinal * (100 - totalPreWeight)) / 100);
		}
		
		printf("\n %.1f - %.1f \t%.1f - %.1f \t%c%c", minFinal, maxFinal, minGoal, maxGoal, letterGrade[0], letterGrade[1]);
	}
	
	printf("\n\n Please be aware that the university system may automatically assign an FF grade, regardless of your average, if your final grade falls below a specific threshold.");
	printf("\n\n\n ! Good luck !");
	
	return 0;
}
