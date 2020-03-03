
#include "CustomerStrategy.h"
#include "OtherInformation.h"

struct Customer
{
    const char* name;
    Address* address;
    Order* orders;
    CustomerPriceStrategy priceStrategy;
};

void placeOrder(struct Customer *customer, Order *order)
{
    double totalAmount = customer->priceStrategy(order->amount, order->shipping);
    /* etc */
}