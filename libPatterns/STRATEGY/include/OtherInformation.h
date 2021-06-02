#ifndef OTHERINFORMATION_H
#define OTHERINFORMATION_H

typedef struct Order
{
    double amount;
    double shipping;
} Order;

typedef struct Address
{
    unsigned int number;
    char *street;
    char *city;
} Address;

#endif