/**
 * Summary:
    * 
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

void print_year(struct tm *t)
{
    printf("Year: %d\n", t->tm_year + 1900);// t->tm_year holds the number of years since 1900
}
void print_month(struct tm *t)
{
    printf("Month: ");
    switch (t->tm_mon)
    {
    case 0:
    printf("January\n");
        break;

    case 1:
    printf("February\n");
        break;

    case 2:
    printf("March\n");
        break;

    case 3:
    printf("April\n");
        break;

    case 4:
    printf("May\n");
        break;

    case 5:
    printf("June\n");
        break;

    case 6:
    printf("July\n");
        break;

    case 7:
    printf("August\n");
        break;

    case 8:
    printf("September\n");
        break;

    case 9:
    printf("October\n");
        break;

    case 10:
    printf("November \n");
        break;

    case 11:
    printf("December\n");
        break;
    }
}
void print_day(struct tm *t)
{
    printf("Day: ");
    switch (t->tm_wday)
    {
    case 0:
    printf("Sunday ");
        break;
    case 1:
    printf("Monday ");
        break;  
    case 2:
    printf("Tuesday ");
        break;
    case 3:
    printf("Wednesday ");
        break;
    case 4:
    printf("Thursday ");
        break;
    case 5:
    printf("Friday ");
        break;
    case 6:
    printf("Saturday ");
        break;
    }
    printf("the %d\n", t->tm_mday);
}
int main(int argc, char **argv)
{
    // time(NULL) returns a long int which is the number of seconds
    // since january 1, 1970 at midnight (epoch)
    time_t now = time(NULL);
    printf("now: %ld\n", now);

    // sleep() function is defined in the unistd.h header file
    sleep(2);

    time_t two_secs = time(NULL);
    printf("two_secs: %ld\n", two_secs);

    // difftime returns the difference between the two time_t arguments passed, as as double
    double diff = difftime(two_secs, now);
    printf("diff: %f\n", diff);

    // ctime() allows us to get a calendar date as a string, from a time_t value
    // NOTE: We pass the address of the time_t variable
    char *now_str = ctime(&now);
    printf("now_str: %s\n", now_str);

    /**
     * But, there are times that we will want to access the time values, not only the string, 
     * like the day, the month, the time, etc.
     * The function gmtime() function returns a struct of type tm which contains the values
     * of the time, given by the argument time_t passed as a pointer.
     * We could also see the function gmtime as casting a time_t value into tm.
    */
    struct tm *gm_time = gmtime(&now);
    print_year(gm_time);
    print_month(gm_time);
    print_day(gm_time);
    printf("Greenwich hour: %d\n", gm_time->tm_hour); // tm_hour holds the Grenwich time 
    char *greenwich_tm = asctime(gm_time);
    printf("Greenwich time str: %s\n", greenwich_tm);
    printf("\n");

    struct tm *local = localtime(&now); // Gives the tm struct with values according to my timezone
    printf("Local hour: %d\n", local->tm_hour);

    /**
    * Just as ctime() printed the calendar string from a time_t variable, 
    * asctime() prints the calendar string from a struct tm variable
    * The reason for this is that we might want to manipulate a struct tm
    */
    char *local_str = asctime(local);
    printf("local_string: %s\n", local_str);


    /**
     * If we want to convert from a struct tm to a time_t value we can use the mktime(struct tm t) function
     */
    time_t local_as_time_t = mktime(local);
    printf("local_as_time_t: %ld\n", local_as_time_t); /** NOTE: We are printing local_as_time_t as a time_t, which is a long int*/
    printf("\n");

   char custom[5];
    /** size_t strftime(char * buf, size_t max_length, const char * format_str, const struct tm * time_tm);
     * We may want to customize a string describing the time given by a tm struct.
     * strftime() uses format specifiers that let us format the string. See bibliography for format specifiers
     * The strftime() function returns the length of the string, and if the length of the string surpasses the
     * maximum amount given as an argument, then it returns the value 0.
    */
   int strlength = strftime(custom, 100, "The current time is: %l %p or in other words: %H", local);
   printf("\n");



    /**
     * clock() returns the number of clock tics that the CPU has executed since the start of the program.
     * This value is returned as a long int.
     * This function is very useful to measure performance by measuring how long took the processor to 
     * do an activity.
     * time.h also defines the constant CLOCKS_PER_SEC which is the number of clock tics 
     * that the processor does per second.
     * 
    */
   clock_t clock1, clock2;
   clock1 = clock();
   printf("clock1: %ld\n", clock1);
   // Some activity
   for (int i = 0; i < 100000000; i++) {}
   clock2 = clock();
   printf("clock2: %ld\n", clock2);
   long int clock_diff = clock2 - clock1;
   printf("clock_diff: %ld\n", clock_diff);
   printf("CLOCKS_PER_SEC: %lu\n", CLOCKS_PER_SEC);
   /** If we want to calculate the time it took from the clock tics,
    * we can do it by dividing by CLOCKS_PER_SEC
   */
   double duration_from_clock = (double) clock_diff / CLOCKS_PER_SEC; /** NOTE: if we dont cast to double, the result of the division gets floored*/
   printf("Duration: %fs\n", duration_from_clock);


   return 0;
}

/**
 * Bibliography:
    * Time Library | C Programming Tutorial: https://youtu.be/Qoed2uBwF_o
    * C library function - strftime(): https://www.tutorialspoint.com/c_standard_library/c_function_strftime.htm
*/