/*
    2034. Stock Price Fluctuation :-

    LINK:   https://leetcode.com/problems/stock-price-fluctuation/
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class StockPrice
{
    map<int, int> stock;
    map<int, int> prices;
    pair<int, int> currentStock = {-1, -1};

public:
    StockPrice()
    {
    }

    void update(int timestamp, int price)
    {

        // Update current stock price if we get a new greater timestamp
        if (timestamp >= currentStock.first)
        {
            currentStock = {timestamp, price};
        }

        if (stock.find(timestamp) != stock.end())
        {
            // Case 2
            int old_price = stock[timestamp]; // Get old price for timestamp

            prices[old_price]--; // Reduce count
            if (prices[old_price] == 0)
                prices.erase(old_price); // Remove if no timestamp has old price
        }

        // Case 1
        prices[price]++;
        stock[timestamp] = price;
    }

    int current()
    {
        return currentStock.second;
    }

    int maximum()
    {
        return prices.rbegin()->first; // GET last element
    }

    int minimum()
    {
        return prices.begin()->first; // Get first element
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */