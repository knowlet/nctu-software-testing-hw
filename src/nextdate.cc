#include "nextdate.h"

int isLeapAndFeb(int yy, int mm) {
    return ((yy % 4 == 0 && yy % 100 != 0 ) || yy % 400 == 0) && mm == FEB;
}

int nextdate(int year, int month, int day)
{
    int n_year  = year,
		n_month = month,
		n_day   = day;
	
	// validate year, month, and day
	if ( year  < YEAR_MIN || month < MONTH_MIN || day < DAY_MIN || year > YEAR_MAX || month > MONTH_MAX || (day > ( isLeapAndFeb(year, month) ? 29 : DAY_MAX[month] )) ) 
		throw std::out_of_range("");
	
	++n_day;
	
	if( (n_day > ( isLeapAndFeb(year, month) ? 29 : DAY_MAX[month] )) ) {
		n_day = DAY_MIN;
		++n_month;
	}
		
	if( n_month > MONTH_MAX ) {
		n_month = MONTH_MIN;
		++n_year;
	}
	
	return (n_year * 10000) + (n_month * 100) + (n_day);
}