#include <cs50.h>
#include <stdio.h>

// Create new datatype
typedef struct
{
    string name;
    int votes;
} candidate;

int main(void)
{
    const int num_candidates = 3;
    candidate candidates[num_candidates];

    candidates[0].name = "Carter";
    candidates[0].votes = 10;

    candidates[1].name = "Yuliia";
    candidates[1].votes = 12;

    candidates[2].name = "Inno";
    candidates[2].votes = 7;

    // Find highest number of votes
    int highest_vote = 0;
    for (int i = 0; i < num_candidates; i++)
    {
        if (candidates[i].votes > highest_vote)
        {
            highest_vote = candidates[i].votes;
        }
    }

    // Print name of the candidate with highest number of votes
    for (int i = 0; i < num_candidates; i++)
    {
        if (candidates[i].votes == highest_vote)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
