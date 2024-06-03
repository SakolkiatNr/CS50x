// Problem to solve

// According to Scholastic, E.B. White’s Charlotte’s Web is between a second- and fourth-grade reading level, and Lois Lowry’s The Giver is between an eighth- and twelfth-grade reading level. What does it mean, though, for a book to be at a particular reading level?

// Well, in many cases, a human expert might read a book and make a decision on the grade (i.e., year in school) for which they think the book is most appropriate. But an algorithm could likely figure that out too!

// In a file called readability.c in a folder called readability, you’ll implement a program that calculates the approximate grade level needed to comprehend some text. Your program should print as output “Grade X” where “X” is the grade level computed, rounded to the nearest integer. If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output “Grade 16+” instead of giving the exact index number. If the grade level is less than 1, your program should output “Before Grade 1”.
// --------------------------------------------------------------------------------
// Background
// So what sorts of traits are characteristic of higher reading levels? Well, longer words probably correlate with higher reading levels. Likewise, longer sentences probably correlate with higher reading levels, too.

// A number of “readability tests” have been developed over the years that define formulas for computing the reading level of a text. One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is

// index = 0.0588 * L - 0.296 * S - 15.8

// where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

// --------------------------------------------------------------------------------

#include <cs50.h>
#include <ctype.h>
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

    // word conditions
    bool cond1 = false;
    bool cond2 = false;
    bool cond3 = false;

    for (int i = 0; i < (length); i++)
    {
        // Compute number of letters
        if (isalpha(text[i]))
        {
            letters++;
        }

        // Compute number of words
        // 1. contain at least one word;
        // 2. separate by space
        // 3. not have multiple spaces in a row

        // count if left side is alphabet or punctuation and right side is alphabet or punctuation
        if (isblank(text[i]) && (ispunct(text[i - 1]) || (isalpha(text[i - 1]))) &&
        (ispunct(text[i + 1]) || (isalpha(text[i + 1]))))
        {
            words++;
        }

        // Will be a sentence if on the left is an alphabet and on the right is blank, or Null at the end of string
        // if (ispunct(text[i]) && ( ( isalpha(text[i - 1]) && (isblank(text[i + 1]) || (text[i + 1] == 0)) ) ) )
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
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

    float l = 100.0000 * letters / words;
    float s = 100.0000 * sentences / words;
    float index = 0.0588 * l - 0.296 * s - 15.8;

    // printf("L: %.4f\n", l);
    // printf("S: %.4f\n", s);
    // printf("The Coleman-Liau index: %.3f\n", index);

    return (int) round(index);
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
