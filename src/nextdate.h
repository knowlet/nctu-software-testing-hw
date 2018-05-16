#include <stdexcept>

const int YEAR_MIN = 1970;
const int YEAR_NOM = 2000;
const int YEAR_MAX = 2018;

enum MONTH {
    JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

const int MONTH_MIN = JAN;
const int MONTH_MAX = DEC;

const int DAY_MIN = 1;
const int DAY_NOM = 15;
const int DAY_MAX[MONTH_MAX + 1] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
 * return a non-zero 8 digit integer as the next date in the format YYYYMMDD from 19700102 to 20150101, ERR_INVALID_DATE(0) if error occurs
 * Thereby, the input range should be from 19700101 to 20141231
 *
 * NOTE!! We do not consider the condition that Feb. has 29 days 
 * 
 * example of usage:
 *  @input  = nextdate( 2001, 1, 1 )
 *  @output = (int)20010102
 */
int nextdate(int year, int month, int day);
