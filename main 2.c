//  
//  Project 2
//  JR PIERCE
//  ET 2100
//  Ohio University
//  10/25/18
//

#include<stdio.h>

void eventLoop();
void writeMenu();
int eventHandler(char event);
void testLeapYear();
int isLeapYear(int year);
void waitUp();
void testDaysInMonth();
int daysInMonth(int year, int month);
void testDate();
int dateCheck(int month, int day, int year);
void testDaysInYear();
int daysInYear(int month, int day, int year);
void testWriteDate();
void writeDate(int month, int day, int year);


int main(){
    printf("\n\nProject 2.\n\n");
    eventLoop();
    printf("\n\nEnd of Project\n\n");
    return 0;
}

void eventLoop()
{
    int done = 0;
    char event;
    while(!done){
        writeMenu();
        scanf(" %c", &event);
        done = eventHandler(event);
    }
}

void writeMenu()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Program 2 Part 1\t\t\t JR Pierce\n\n");
    printf("Choose one of the following\n\n");
    printf("\tH: Hello from JR\n");
    printf("\tL: Test for Leap Year\n");
    printf("\tT: Test Date\n");
    printf("\tY: Days For Month\n");
    printf("\tZ: Days in Year\n");
    printf("\tW: Write Date\n");
    printf("\tQ: Quit\n\n");
    printf("\tEnter a choice in (H, L, T, Y, Z, W, Q) :  ");
    
}

int eventHandler(char event)
{
    switch(event){
        case 'h':
        case 'H':
            printf("\nHello. My name is JR\n");
            waitUp();
            break;
        case 'l':
        case 'L':
	        testLeapYear();
            break;
        case 'T':
        case 't':
            testDate();
            break;
        case 'y':
        case 'Y':
            testDaysInMonth();
            break;
        case 'z':
        case 'Z':
            testDaysInYear();
            break;
        case 'W':
        case 'w':
            testWriteDate();
            break;
        case 'q':
        case 'Q':
            return 1;
        default:
            printf("\nBad Input %c, Try Again\n", event);
            waitUp();
    }
    return 0;
}
void testLeapYear()
{
    int year;
    printf("\nEnter a year:  ");
    scanf("%d", &year);
    if(isLeapYear(year)){
        printf("\n\n%d is a leap year!", year);
    }
    else{
        printf("\n\n%d is not a leap year", year);
    }
    waitUp();

}
int isLeapYear(int year)
{
    if(year %400==0){
        return 1;
    }
    if(year % 100 == 0){
        return 0;
    }
    if(year % 4 == 0){
        return 1;
    }
    else{
        return 0;
    }

}
void waitUp()
{
    printf("\nEnter any key to continue: ");
    char key;
    scanf(" %c", &key);
}

void testDaysInMonth()
{
    int month, year;
    printf("\nEnter Month: ");
    scanf("%d", &month);
    printf("\nEnter Year: ");
    scanf("%d", &year);
    int amount = daysInMonth(year, month);
    printf("%d has %d", month, amount);
    waitUp();
}

int daysInMonth(int year, int month)
{
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if(isLeapYear(year) == 1){
                return 29;
            }
            if(isLeapYear(year) == 0){
                return 28;
            }
    }
    return 0;
}
void testDate()
{
    int month, day, year;
    printf("\nWhat is the Month? : ");
    scanf("%d", &month);
    printf("\nWhat is the Day? : ");
    scanf("%d", &day);
    printf("\nWhat is the Year? : ");
    scanf("%d", &year);
    
    int ret = dateCheck(month, day, year);
    
    if(ret == 1){
        printf("\n%d/%d/%d Is a Valid date!\n", month, day, year);
    }
    else{
        printf("\n%d/%d/%d Is not a Valid date!\n", month, day, year);
    }
    waitUp();
    
}

int dateCheck(int month, int day, int year)
{
    if(month < 0 || month > 12){
        return 0;
    }
    if(day > daysInMonth(year, month)|| day < 0){
        return 0;
    }
    else return 1;
}

void testDaysInYear()
{
    int month, day, year;
    
    printf("\n\nDays in a Year\n\n");
    printf("\nWhat is the Month? : ");
    scanf("%d", &month);
    printf("\nWhat is the Day? : ");
    scanf("%d", &day);
    printf("\nWhat is the Year? : ");
    scanf("%d", &year);
    
    if(dateCheck(month, day, year) == 1){
        printf("%d is the amount of days for the date %d/%d/%d", daysInYear(month, day, year), month, day, year);
        waitUp();
    }
    else{
        printf("\nThat's an invalid date");
        waitUp();
    }
    
}

int daysInYear(int month, int day, int year)
{
    int sum = day;
    for(int i = 1; i < month; ++i){
        sum += daysInMonth(year, i);
    }
    return sum;
}

void testWriteDate()
{
    int month, day, year; 
    
    printf("\n\nWrite Date Function\n\n");
    printf("\nWhat is the Month? : ");
    scanf("%d", &month);
    printf("\nWhat is the Day? : ");
    scanf("%d", &day);
    printf("\nWhat is the Year? : ");
    scanf("%d", &year);
 
    writeDate(month, day, year);
}

void writeDate(int month, int day, int year)
{
    if(dateCheck(month, day, year) == 1){
        printf("\nYear: %d Month: %d Day %d is number %d in the year!", year, month, day, daysInYear(month, day, year) );
        waitUp();
    }
    else{
        printf("\nYear: %d Month: %d Day %d is an invalid date!", year, month, day);
        waitUp();
    }
}