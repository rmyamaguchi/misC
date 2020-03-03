
#include <stdlib.h>

#include "Customer.h"
#include "CustomerStrategy.h"
#include "OtherInformation.h"

struct Customer
{
    char* name;
    Address *address;
    CustomerPriceStrategy priceStrategy;
};

CustomerPtr createCustomer(const char* name, const Address *address, CustomerPriceStrategy priceStrategy)
{
    CustomerPtr customer = malloc(sizeof *customer);

    if (NULL != customer)
    {
        customer->name = name;
        customer->address = address;
        customer->priceStrategy = priceStrategy;
    }
    return customer;
}

void changePriceCategory(CustomerPtr customer, CustomerPriceStrategy newPriceStrategy)
{
    if (NULL != customer)
        customer->priceStrategy = newPriceStrategy;
}