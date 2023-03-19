#include <stdio.h>
#include <stdlib.h>
#include "cis1201.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {


	printf("[1.0 ] Employee List (ID & Name): \n\n");
	// start of no.1
	// make the code below work by updating the populateEmployeeList() in cis1201.c
	EmployeePtr employees = populateEmployeeList();
	displayEmployees(employees);
	// end of no.1
	printf("\n\n\n");
	pause();
	printf("\n\n\n");
	

	printf("[2.0 ] Convert 12-hour time format to 24-hour time format:\n");
	// start of no.2
	/* make your declaration and function calls here for no.2
	 * utilize the newly created function and usable functions in cis1201 files
	 */
	 MyTime t = newTime(01,01,false);
	 printf("\t12 HOUR FORMAT: "); displayTime12(t);
	 convertTime(&t);
	 printf("\n\t24 HOUR FORMAT: "); displayTime24(t);
	//end of no.2
	
	printf("\n\n\n");
	pause();
	printf("\n\n\n");
	
	printf("[3.0 ] Employee Information (DISPLAY):\n\n");
	// start of no.3
	/* using the employee list in no.1 display all there information
	 * utilizing the display employee info (single employee) function
	 * create necessary decleration here for no.3
	 */
	int i, j;
	while(employees[i].empID!=0){
		printf("ID: %d", employees[i].empID);printf("\n");
		printf("NAME: "); displayName(employees[i].empName);printf("\n");
		printf("ADDRESS: "); displayAddress(employees[i].empHomeAddress);
		printf("\nDAILY TIME RECORD:");
		for(j = 0; j < 5; j++){
			if(j==0){
			   printf("\n%10s:", "Monday");printf("\t");
			   displayDTR(employees, i, j);
			}
			if(j==1){
			   printf("\n%10s:", "Tuesday");printf("\t");
			   displayDTR(employees, i, j);
			}
			if(j==2){
			   printf("\n%10s:", "Wednesday");printf("\t");
			   displayDTR(employees, i, j);
			}
			if(j==3){
			   printf("\n%10s:", "Thursday");printf("\t");
			   displayDTR(employees, i, j);
			}
			if(j==4){
			   printf("\n%10s:", "Friday");printf("\t");
			   displayDTR(employees, i, j);
			}
		}
		printf("\n\n");
		i++;
	}
	// end of no.3
	
	printf("\n\n\n");
	pause();
	printf("\n\n\n");
	
	printf("[4.0 ] Employees that are late on a specified day in the morning(DISPLAY NAMES):\n\n");
	// start of no.4
	// display all the late employees and make you necessary declaration here
	int count = 1;
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			if(employees[j].empDTR[i].in.hour > 8 || (employees[j].empDTR[i].in.hour == 8 && employees[j].empDTR[i].in.minute > 0)){
				if(count==1){
					printf("\nIncurred lates on ");
			        if(i == 0){ printf("Monday\n");} if(i == 1){printf("Tuesday\n");} if(i == 2){printf("Wednesday\n");} if(i == 3){printf("Thursday\n");} if(i == 4){printf("Friday\n");}
				}
		     	printf("[%d.0] ", count++);
			    displayName(employees[j].empName);
			    printf("\n");
		    }
		}
		 count = 1; 
	}
	//end of no.4
	
	printf("\n\n\n");
	pause();
	printf("\n\n\n");
	return 0;
}
