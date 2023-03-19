#ifndef CIS1201_H
#define CIS1201_H

typedef enum {false, true} Boolean;
typedef char String[30];

typedef struct {
	int hour;
	int minute;
	Boolean meridian;				// true => AM; false => PM
} MyTime, *MyTimePtr;

typedef struct {
	MyTime in;
	MyTime out;
} Attendance, *AttendancePtr;

typedef struct {
	String firstname;
	String middlename;
	String lastname;
} Name, *NamePtr;

typedef struct {
	int houseNumber;
	String barangay;
	String city;
	int zip;
} Address, *AddressPtr;

typedef struct {
	int empID;
	Name empName;
	Address empHomeAddress;
	Attendance empDTR[5];			// contains each attendance from Monday to Friday
} Employee, *EmployeePtr;

MyTime newTime(int hour, int minute, Boolean meridian);
Attendance newAttendance(MyTime in, MyTime out);
Name newName(String firstname, String middlename, String lastname);
Address newAddress(int houseNumber, String barangay, String city, int zip);
Employee newEmployee(int empID, Name empName, Address empAddress, Attendance attMon, Attendance attTue, Attendance attWed, Attendance attThu, Attendance attFri);
EmployeePtr populateEmployeeList();
void displayTime24(MyTime t);
void displayTime12(MyTime t);
void displayAddress(Address a);
void displayName(Name n);
void displayEmployees(EmployeePtr list);

/**
 *	Create your own prototypes here for the other features needed.
 *
 *  For No.2 -> For convert time. Allows to convert a given time from
 *		12-hour format and returns the 24-hour format (12:00 AM is equal to
 *		00:00 and 12:00 PM is equal to 12:00. Use the hour numbers from
 *		0-23 for 24-hour format).
 *	
 *	For No.3 -> Create a function that will display the information 
 *		of a single employee based on the output format provided including 
 *		the daily attendance from Monday to Friday. (Single employee only)
 *
 *	For No.4 -> Create a function that will get the late employees in the 
 *		list/collection in the morning of a specified week day.
 *		Ex: Late employees on a Monday morning.
 *  
 *	Write all the function definition in the "cis1201.c".
 */
 
void convertTime(MyTimePtr t);
void displayDTR(EmployeePtr employees, int i, int j);
void pause();



#endif
