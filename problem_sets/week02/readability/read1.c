
#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int compute_index(string text);
void compute_grade(int index);


int main(void)
{
    // Prompt user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int grade = compute_index(text);

    // Print the grade level
    compute_grade(grade);
}

int compute_index(string text)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;

    int length = strlen(text);

    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int vowels_length = sizeof(vowels);

    // word conditions
    bool cond1 = false;
    bool cond2 = false;
    bool cond3 = false;

    for (int i = 0; i < (length); i++)
    {
        // Compute number of letters
        if (isalpha(text[i]))
        {
            letters ++;
        }

        // Compute number of words
        // 1. contain at least one word; vowels
        // 2. separate by space
        // 3. not have multiple spaces in a row
        // to determine a word, left side of a blank space must be alphabet or punctuation and right side must be alphabet

        // count if left side is alphabet or punctuation and right side is alphabet or punctuation
        if (isblank(text[i]) && (ispunct(text[i - 1]) || (isalpha(text[i - 1]))) && (ispunct(text[i + 1]) || (isalpha(text[i + 1]))) )
        {
            words++;
        }

        // if (isblank(text[i]) && isalpha(text[i + 1]))
        // {
        //     // left side of a word is blank
        //     // Condition 2
        //     cond1 = true;
        // }
        // else if (isalpha(text[i]))
        // {
        //     if (isalpha(text[0]))
        //     {
        //         // first string that doesn't have blank on the left
        //         cond1 = true;
        //     }
        //     // Check for vowels
        //     for (int j = 0; j < vowels_length; j++)
        //     {
        //         if (text[i] == vowels[j])
        //         {
        //             // Condition 1 passed
        //             cond2 = true;
        //             break;
        //         }
        //     }

        //     // if ended with blank or punctuations followed by blank or ended with NUL
        //     if ((isblank(text[i + 1])
        //     || (ispunct(text[i + 1]) && (isblank(text[i + 2]) || (text[i + 2] == 0))))
        //     || (text[i + 1] == 0))
        //     {
        //         // Condition 2 passed
        //         cond3 = true;
        //     }
        // }
        // // If it is a word then count and reset conditions
        // if ((cond1 && cond2 && cond3) == true)
        // {
        //     words++;
        //     cond1 = false;
        //     cond2 = false;
        //     cond3 = false;
        // }

        // Will be a sentence if on the left is an alphabet and on the right is blank, or Null at the end of string
        // if (ispunct(text[i]) && ( ( isalpha(text[i - 1]) && (isblank(text[i + 1]) || (text[i + 1] == 0)) ) ) )
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences ++;
        }

    }
    // last word
    words++;

    // Debugging
    printf("letters : %i\n", letters);
    printf("words: %i\n", words);
    printf("Sentences: %i\n", sentences);

        // // Compute the Coleman-Liau index

    // // index = 0.0588 * L - 0.296 * S - 15.8
    // // L = (Letters ÷ Words) × 100
    // // S = (Sentences ÷ Words) × 100

    float l = 100.0000 * letters / words ;
    float s = 100.0000 * sentences / words;
    float index = 0.0588 * l - 0.296 * s - 15.8;

    // printf("L: %.4f\n", l);
    // printf("S: %.4f\n", s);
    // printf("The Coleman-Liau index: %.3f\n", index);

    return (int)round(index);
}

void compute_grade(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index <= 16 && index >= 1)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}





