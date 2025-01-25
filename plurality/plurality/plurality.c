#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Define the maximum number of candidates allowed
#define MAX 9

// Define a structure for candidates, containing their name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array to hold all candidates, and a variable to keep track of the number of candidates
candidate candidates[MAX];
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check if the user provided candidate names as command-line arguments
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Set the candidate count based on the number of arguments, and check for overflow
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Populate the array of candidates with names from the command line
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0; // Initialize each candidate's vote count to zero
    }

    // Ask the user for the number of voters
    int voter_count = get_int("Number of voters: ");

    // Loop over each voter's input and register their vote
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        // Check if the vote is valid; if not, inform the user
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display the winner(s) of the election
    print_winner();
}

// Update the vote totals given a new vote
bool vote(string name)
{
    // Iterate over each candidate to find a matching name
    for (int i = 0; i < candidate_count; i++)
    {
        // Compare the candidate's name with the given name
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++; // Increment the candidate's vote count
            return true;           // Return true indicating a valid vote
        }
    }
    return false; // Return false if no matching candidate name is found
}

// Print the winner(s) of the election
void print_winner(void)
{
    int max_votes = 0;

    // Determine the highest vote count among the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Print the names of the candidate(s) with the maximum votes, handling ties if needed
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
