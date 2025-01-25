from cs50 import get_float

# Prompt for a valid, non-negative amount
while True:
    try:
        change_owed = float(input("Change owed: "))
        if change_owed >= 0:
            break
    except ValueError:
        pass  # Ignore non-numeric input; will re-prompt

# Convert dollars to cents and round to avoid floating-point inaccuracies
cents = round(change_owed * 100)

# Initialize counter for coins
coins = 0

# Calculate the minimum number of coins needed
for coin in [25, 10, 5, 1]:
    coins += cents // coin
    cents %= coin

# Output the result
print(coins)
