#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <string.h>

int main() {
    int h, m, s, day, month, year;
    char period[3];

    printf("Enter the current date in the format dd mm yyyy\n");
    
    printf("Enter day: ");
    scanf("%d", &day);
    
    printf("Enter month: ");
    scanf("%d", &month);
  
    printf("Enter year: ");
    scanf("%d", &year);

    printf("Enter the current time in the format hh mm ss AM/PM\n");
   
    printf("Enter hours: ");
    scanf("%d", &h);
   
    printf("Enter minutes: ");
    scanf("%d", &m);
   
    printf("Enter seconds: ");
    scanf("%d", &s);
   
    printf("Enter AM/PM: ");
    scanf("%s", period);

    while (1) {
        Sleep(1000); // Sleep for 1 second to simulate the passage of time
        system("cls"); // Clear the console screen

        printf("\t\t\t\t\t\t\t\t\t\t dd/mm/yyyy   HH : MM : SS AM/PM  \n");
        printf("\t\t\t\t\t\t\t\t\t\t %02d/%02d/%04d   %02d : %02d : %02d %s\n", day, month, year, h, m, s, period);

        // Increment seconds
        s++;
        if (s == 60) {
            s = 0;
            m++;
            if (m == 60) {
                m = 0;
                h++;
                if (h == 12) {
                    // Toggle between AM and PM when hours reach 12
                    if (strcmp(period, "AM") == 0) {
                        strcpy(period, "PM");
                    } else {
                        strcpy(period, "AM");
                        // If period changed to AM, increment the date
                        day++;
                        if ((day > 31) ||
                            (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) ||
                            (day > 29 && month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) ||
                            (day > 28 && month == 2 && year % 4 != 0)) {
                            day = 1;
                            month++;
                            if (month == 13) {
                                month = 1;
                                year++;
                            }
                        }
                    }
                }
                if (h == 13) {
                    // Convert 24-hour format to 12-hour format
                    h = 1;
                }
            }
        }
    }
    return 0;
}
