'''
Coin change
Coin change algorithm gives user way to pay specific price.
This algorithm receives coin type and price from user.
For example, you have 100, 500 coin and want pay 1200 won.
You can pay two 500 coins and two 100 coins or one 500 coin and seven 100 coins or twelve 100 coins.
'''
import copy
returnList = []


# fillCoin function
# This function fill payment top to bottom way.
# First, fill payment with largest coin
# Second, pop largest coin one by one.
# Last, call fillCoin function with second largest coin
# Repeat these process untill call fillCoin function with the smallest coin.
def fillCoin(current, coinType, result, restPayment):
    max_coins = restPayment//coinType[current]
    coin = coinType[current]

    # Check case that restPayment != 0 but current coin can't fill payment
    # Check whether it can call smaller coin
    if(restPayment < coin):
        if current < len(coinType)-1:
            fillCoin(current + 1, coinType, result, restPayment)
            max_coins = -1
        else: return

    # Fill payment with current coin as much as possible
    for i in range(max_coins+1):
        result.append(coin)
    restPayment -= coin*(max_coins+1)

    for i in range(max_coins+1):
        result.pop()
        restPayment += coin

        # When restPayment == 0, add it to list which have way to pay
        if restPayment == 0:
            returnList.append(copy.deepcopy(result))
        else:
            if current < len(coinType) - 1:
                fillCoin(current + 1, coinType, result, restPayment)


#  coinChange function
#  It control fillCoin function
def coinChange(coins, payment):
    list = []
    result = []
    sorted_coins = sorted(coins, reverse=True)
    fillCoin(0, sorted_coins, list, payment)


# Main
coins = [100,500]
n = 1200
coinChange(coins, n)
print(returnList)
