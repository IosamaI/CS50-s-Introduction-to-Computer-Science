# Prompt for height until it is between 1 and 8
while True:
    try:
        # Ask for input and convert to an integer
        num = int(input("Height: "))
        # Check if the number is within the desired range
        if 1 <= num <= 8:
            break
        else:
            print("Please enter a number between 1 and 8.")
    except ValueError:
        # Handle non-numeric input
        print("Invalid input. Please enter a number between 1 and 8.")

# Generate the right-aligned pyramid
for i in range(num):
    # Print spaces before hashes
    for j in range(num - i - 1):
        print(" ", end="")

    # Print hashes
    for j in range(i + 1):
        print("#", end="")

    # Move to the next line
    print()
