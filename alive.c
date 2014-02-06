/*
Program to tell you how long you've been on this earth
input: date of birth
*/

#include <stdio.h>
#include <time.h>

main()
{   
    int day, month, year, thisyr, moday,inyear, curyr, daycuryr,dayinbe,daylife,yearleap,leapday,tillbday,daysleft,bday2end;
    
    printf("Please enter your date of birth in the format: dd/mm/yyyy\n");
    
    //Scanning in Date of Birth
    scanf("%d/%d/%d",&day,&month,&year);
    
    if (day>31||month>12)
    {printf("You done fucked up!...");}
    
    else
    {
        
    if (year<=100&&year>=20)
    {year=year+1900;}
    
    if (year>=0&&year<=20)
    {year=year+2000;}
    
    
    {//Switch statement for first year of life in days
        switch (month)
        {
            case 1:
            {moday=0;
            break;        
            }
            case 2:
            {moday=31;
            break;        
            }
            case 3:
            {moday=59;
            break;        
            }
            case 4:
            {moday=90;
            break;        
            }
            case 5:
            {moday=120;
            break;        
            }
            case 6:
            {moday=151;
            break;        
            }
            case 7:
            {moday=181;
            break;        
            }
            case 8:
            {moday=212;
            break;        
            }
            case 9:
            {moday=243;
            break;        
            }
            case 10:
            {moday=273;
            break;        
            }
            case 11:
            {moday=304;
            break;        
            }
            case 12:
            {moday=334;
            break;        
            }
        
        }
    }
        thisyr = 365-moday-day;
    //Total number of days in first year: thisyr
    //NOT INCLUDING LEAP YEAR
    
    /*Testing that 'thisyr' works, should remove printf when finished!
    printf("%d days in your first year\n\n",thisyr);
    */
    
    
    {/*Gets current day of the year e.g 285th day of year (now->tm_year=285;)
            Also gets current year (curyr=2012)
        */
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    daycuryr=now->tm_yday;
    curyr=now->tm_year+1900;
    }
    
    
    
    
    //Years between year born to current year totalled into days
    //NOT INCLUDING LEAP YEARS
    inyear=curyr-year-1;
    
    /*Testing to see if inyear works
    printf("%d years since you were born.\n",inyear);
    */
    
    dayinbe=inyear*365;
    
    /*Testing dayinbe
    printf("%d",dayinbe);
    */
    
    
    daylife=daycuryr+dayinbe+thisyr;
    
    /*Testing daylife: days since birth date, not including leap years..
    printf("There have been %d days since you were born, not including leap year days..\n\n",daylife);
    */
    
    //Determining leap years
    
    leapday=0;
    yearleap=year;
    
    //If the yearleap doesnt equal the current year, run the while loop
    while (yearleap!=curyr+1)
    {
        if (yearleap%400 == 0 || yearleap%100 != 0 && yearleap%4 == 0)
        {leapday++;
        }
        if (yearleap==curyr)
        {break;}
    //Add a year at the end of every loop
    yearleap++;
    }
    
    //Total of things to output
    int to=daylife;
    int yrto,moto;
    unsigned long hoto,mito,seto;
    
    yrto=to/365;
    moto=to/30;
    //add days to print
    hoto=to*24;
    mito=to*1440;
    seto=to*86400;
    
    
    //Days till your next birthday
    
    daysleft=365-daycuryr;
    bday2end=thisyr;
    if (bday2end>=daysleft)
    {
        tillbday=daysleft+(365-bday2end);
    }
    
    else
    {
        tillbday=daysleft-bday2end;
    }
    
    
    
    
    printf("\n\nYou have been alive for %d days",daylife);
    printf(" and %d of those years were leap years..",leapday);
    
    
    printf("\nThat is the same as:\n\n%d years\nOr\n%d months\nOr\n%d days\nOr\n%lu hours\nOr\n%lu minutes\nOr\n%lu seconds\n",yrto,moto,to,hoto,mito,seto);
    
    printf("\nDays until your next birthday: %d",tillbday);
    }
    getchar();
    getchar();
}
