// Scrabble
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototype declaration
int compute_score(string word);
void compare_score(int player_1, int player_2);

int main(void)
{
    // do while loop for string only
    // Prompt player 1 input
    string player_1_word = get_string("Player 1: ");
    // Prompt player 2 input
    string player_2_word = get_string("Player 2: ");

    // Compute the score of each word
    int p1_score = compute_score(player_1_word);
    int p2_score = compute_score(player_2_word);

    // Check each player score
    // printf("Player 1 score: %i\n", p1_score);
    // printf("Player 2 score: %i\n", p2_score);

    // Print out the winner
    compare_score(p1_score, p2_score);
}

int compute_score(string word)
{

    // Compute the score of the word
    int letter_score = 0;
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        // Changing alphabet to uppercase
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] -= 32;
        }

        // Set score for each character
        // 1 point - A, E, I, O, U, L, N, S, T, R.
        char one_point[] = {'A', 'E', 'I', 'O', 'U', 'L', 'N', 'S', 'T', 'R'};
        // 2 points - D, G.
        char two_points[] = {'D', 'G'};
        // 3 points - B, C, M, P.
        char three_points[] = {'B', 'C', 'M', 'P'};
        // 4 points - F, H, V, W, Y.
        char four_points[] = {'F', 'H', 'V', 'W', 'Y'};
        // 5 points - K.
        char five_points[] = {'K'};
        // 8 points - J, X.
        char eight_points[] = {'J', 'X'};
        // 10 points - Q, Z.
        char ten_points[] = {'Q', 'Z'};
        // 0 points - Blank Tiles.

        // Loop to find matching letter
        int matched = 0;
        // Accept only alphabet
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            while (matched <= 0)
            {
                // 1 point
                for (int j = 0; j < sizeof(one_point); j++)
                {
                    if (word[i] == one_point[j])
                    {
                        letter_score++;
                        matched++;
                    }
                }

                // 2 points
                for (int j = 0; j < sizeof(two_points); j++)
                {
                    if (word[i] == two_points[j])
                    {
                        letter_score += 2;
                        matched++;
                    }
                }

                // 3 points
                for (int j = 0; j < sizeof(three_points); j++)
                {
                    if (word[i] == three_points[j])
                    {
                        letter_score += 3;
                        matched++;
                    }
                }

                // 4 points
                for (int j = 0; j < sizeof(four_points); j++)
                {
                    if (word[i] == four_points[j])
                    {
                        letter_score += 4;
                        matched++;
                    }
                }

                // 5 points
                for (int j = 0; j < sizeof(five_points); j++)
                {
                    if (word[i] == five_points[j])
                    {
                        letter_score += 5;
                        matched++;
                    }
                }

                // 8 points
                for (int j = 0; j < sizeof(eight_points); j++)
                {
                    if (word[i] == eight_points[j])
                    {
                        letter_score += 8;
                        matched++;
                    }
                }

                // 10 points
                for (int j = 0; j < sizeof(ten_points); j++)
                {
                    if (word[i] == ten_points[j])
                    {
                        letter_score += 10;
                        matched++;
                    }
                }
            }
        }
    }
    // printf("%s\n", word);

    return letter_score;
}

void compare_score(int player_1, int player_2)
{
    // Compare to find the winner
    if (player_1 > player_2)
    {
        printf("Player 1 wins!\n");
    }
    else if (player_2 > player_1)
    {
        printf("Player 2 wins!\n");
    }
    // Print 'Tie!' if player scores are equal
    else
    {
        printf("Tie!\n");
    }
}
