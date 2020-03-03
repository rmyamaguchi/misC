#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef struct Customer *CustomerPtr;

CustomerPtr createCustomer(const char* name, const Address *address, CustomerPriceStrategy priceStrategy);
void changePriceCategory(CustomerPtr customer, CustomerPriceStrategy newPriceStrategy);

#endif