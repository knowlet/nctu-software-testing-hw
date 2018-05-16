#include <stdexcept>

const int LOCK_PRICE = 45;
const int STOCK_PRICE = 30;
const int BARREL_PRICE = 25;

const int LOCK_MIN = 1;
const int LOCK_MAX = 70;

const int STOCK_MIN = 1;
const int STOCK_MAX = 80;

const int BARREL_MIN = 1;
const int BARREL_MAX = 90;

const int SALE_INPUT = 3;

const double SALE_THRESHOLD[SALE_INPUT] = { 0.0, 1000.0, 1800.0 };
const double COMMISSION_PERCENT[SALE_INPUT] = { 0.1, 0.15, 0.2 };

double count_commission( int lock, int stock, int barrel );