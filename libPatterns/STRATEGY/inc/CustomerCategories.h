#ifndef CUSTOMERCATEGORIES_H
#define CUSTOMERCATEGORIES_H

#define PRICESTRATEGY(CATEGORY) double CATEGORY##PriceStrategy(double amount, double shipping)

double bronzePriceStrategy(double amount, double shipping);
double silverPriceStrategy(double amount, double shipping);
double goldPriceStrategy(double amount, double shipping);

#endif