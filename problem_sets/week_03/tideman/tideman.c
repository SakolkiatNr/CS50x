#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool check_cycle(int start, int current);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    // Record voter ranks
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // Loop to each voter
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            // Preference pairs
            int a = ranks[i];
            int b = ranks[j];
            preferences[a][b]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Set max pairs
    int max_pairs = MAX * (MAX - 1) / 2;

    // Iterate to compare elements
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (i != j)
            {
                // Margin of victory
                int a = preferences[i][j];
                int b = preferences[j][i];
                int intensity = a - b;

                // Record position
                if (a > b)
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                    pair_count++;
                }
                else if (a < b)
                {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                    pair_count++;
                }
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

    // Check intensity of each pare
    for (int i = 0; i < pair_count - 1; i++)
    {
        // Store highest margin pair
        int highest_margin = 0;
        int highest_margin_pair;

        // Find highest element in array
        for (int j = i; j < pair_count; j++)
        {

            // Margin of victory
            int winner = pairs[j].winner;
            int loser = pairs[j].loser;
            int margin = preferences[winner][loser] - preferences[loser][winner];

            if (margin > highest_margin)
            {
                highest_margin = margin;
                highest_margin_pair = j;
            }
        }

        // Temporary pair
        pair pair_i = pairs[i];
        // Swap pair
        pairs[i] = pairs[highest_margin_pair];
        pairs[highest_margin_pair] = pair_i;

        // resest highest margin
        highest_margin = 0;
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        bool skip = false;

        if (check_cycle(winner, loser))
        {
            skip = true;
        }

        // Skip if there's a path from loser back to winner

        if (!skip)
        {
            locked[winner][loser] = true;
        }
    }
    return;
}

// Check if create cycle
bool check_cycle(int start, int current)
{
    // Base case
    if (start == current)
        return true;

    // Check for each node
    for (int i = 0; i < candidate_count; i++)
    {
        if (i != current)
        {
            // If node find its way to the start
            if (locked[current][i] && check_cycle(start, i))
                return true;
        }
    }
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    // Check for bool values in each column
    for (int i = 0; i < candidate_count; i++)
    {
        bool winner = true;

        for (int j = 0; j < candidate_count; j++)
        {
            // Break if there is false in the column
            if (locked[j][i] == true)
            {
                winner = false;
            }
        }
        // Print winner
        if (winner == true)
        {
            printf("%s\n", candidates[i]);
            winner = true;
        }
    }
    return;
}
