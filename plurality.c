#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Search the candidate in the candidates array
    for (int i = 0; i < candidate_count; i++)
    {
        // candidate founded
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // to store the max votes count
    int maxVotesCount = 0;

    int candidatesPos[candidate_count];

    // count the higher votes count
    for (int i = 0; i < candidate_count; i++)
    {
        // update votes counter
        if (maxVotesCount < candidates[i].votes)
        {
            maxVotesCount = candidates[i].votes;
        }
    }

    // print all candidates that match the max votes count
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == maxVotesCount)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

