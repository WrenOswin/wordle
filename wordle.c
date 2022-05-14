#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
extern char words[][6];
extern int length;

void yellow()
{
    printf("\033[1;33m");
}
void green()
{
    printf("\033[1;32m");
}
void reset ()
{
  printf("\033[0m");
}

int candp(char word[], char wordguess[])           
{
    char new[10];
    int correct[5] = {-1, -1, -1, -1, -1};
    int posnot[5] = {-1, -1, -1, -1, -1};
    int top1 = 0;
    int top2 = 0;
    for(int i = 0; i < 5; i++)
    {
        if(word[i]==wordguess[i])
        {
            correct[top1] = i;
            top1++;
        }
    
    }

    for(int i = 0; i < 5; i++)
    {
            for(int j = 0; j < 6; j++)
            {
                if(j!=correct[0] && j!=correct[1] && j!=correct[2] && j!=correct[3] && j!=correct[4])
                {
                    if(word[j]==wordguess[i])
                    {
                        posnot[top2] = i;
                        top2++;
                    }
                }
                
            }
            
    } 
    strcpy(new, wordguess);

    for(int i = 0; i < 5; i++)
        wordguess[i] = toupper(wordguess[i]);

    for(int i = 0; i < 5; i++)
    {
        if(i == correct[0] || i == correct[1] || i == correct[2] || i == correct[3] || i == correct[4])
        {
            reset();
            green();
            printf("%c", wordguess[i]);
            reset();
        }
        else if(i == posnot[0] || i == posnot[1] || i == posnot[2] || i == posnot[3] || i == posnot[4])
        {
            reset();
            yellow();
            printf("%c", wordguess[i]);
            reset();
        }
        else
           printf("%c", wordguess[i]); 

    }

    if(strcmp(word,new)==0)
        return 1;
    else
        return 0;
}                                                       
int main()
{
    srand(time(0));
    int found = 0;
    int tries = 6;
    char word[6];
    char wordguess[10];
    strcpy(word, words[rand() % length]);
    printf("\nWelcome to WORDLE terminal edition :)\n");
    printf("\nInstructions\n");
    printf("____________\n");
    printf("Letter will be GREEN in color if you guessed letter in the correct position\n"); 
    printf("and YELLOW if letter is present in the word but you didnt guess the letter at the right position.\nYou have 6 tries to guess the word!\n");
   
    printf("\n");
    for (int a = 6; a > 0; a--)
    {
        reset();
        printf("\nYou have %d tries left!\n", a);
        printf("Enter a word to guess(5 letters): ");
        scanf("%s", wordguess);
        if(strlen(wordguess)!=5)
        {
            printf("\nWord entered is not a 5 letter word.\n");
            a++;
            continue;
        }

        for (int b = 0; b < 6; b++)
            wordguess[b] = tolower(wordguess[b]);

        found = candp(word, wordguess);
        if(found == 1)
        {
            printf("\nYou found the word!\n");
            return 0;
        }
    }

    for (int b = 0; b < 6; b++)
        word[b] = toupper(word[b]);
    printf("\nYou didn't guess the word. Word was - %s", word);
    return 0;
}