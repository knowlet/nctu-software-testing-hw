#include "commission.h"

double count_commission( int lock, int stock, int barrel ) {
	// validate the input sale
	if( lock < LOCK_MIN || stock < STOCK_MIN || barrel < BARREL_MIN || lock > LOCK_MAX || stock > STOCK_MAX || barrel > BARREL_MAX ) 
		throw std::out_of_range("INVALID_SALE");
	return LOCK_PRICE * lock + STOCK_PRICE * stock + BARREL_PRICE * barrel;
}