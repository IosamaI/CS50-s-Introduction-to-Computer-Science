import csv
import sys


def main():
    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Read database file into a variable
    # Open the CSV file specified as the first command-line argument
    with open(sys.argv[1], newline="") as csvfile:
        reader = csv.DictReader(csvfile)
        # Convert the CSV rows to a list of dictionaries for easy access
        database = list(reader)
        # Get the list of STRs from the CSV header (excluding the 'name' column)
        str_names = reader.fieldnames[1:]  # Exclude 'name' from STR list

    # Read DNA sequence file into a variable
    # Open the text file specified as the second command-line argument
    with open(sys.argv[2], "r") as file:
        # Read the entire file content as a single string
        dna_sequence = file.read().strip()

    # Find longest match of each STR in DNA sequence
    # Initialize a dictionary to store longest counts of each STR
    str_counts = {}
    for str_name in str_names:
        # Calculate the longest consecutive run for each STR and store it
        str_counts[str_name] = longest_match(dna_sequence, str_name)

    # Check database for matching profiles
    # Loop through each person in the database
    for person in database:
        # Check if this person's STR counts match the sequence STR counts
        # We use all() to ensure all STR counts match
        if all(str_counts[str_name] == int(person[str_name]) for str_name in str_names):
            # If a match is found, print the person's name and return
            print(person["name"])
            return

    # If no match found after checking all people in the database
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize the longest run count to zero
    longest_run = 0
    # Get the length of the subsequence (STR) and sequence (DNA)
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each position in the sequence for runs of the subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Continue looking for consecutive matches in the sequence
        while True:
            # Calculate start and end indices for the substring
            start = i + count * subsequence_length
            end = start + subsequence_length

            # Check if there's a match in this substring
            if sequence[start:end] == subsequence:
                # If a match is found, increase the count
                count += 1
            else:
                # Break the loop if no further consecutive match is found
                break

        # Update longest run if this count is the highest found
        longest_run = max(longest_run, count)

    # Return the longest run found
    return longest_run


# Run the main function if the script is run directly
if __name__ == "__main__":
    main()
