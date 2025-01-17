#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(void)
{
    // getting the command line arguments..i.e., getting the word size
    int wordSize;

        printf("No of Letters (6 , 7 or 8 Letter Word) :");
        scanf("%d" ,&wordSize);
    
    

    if ( !(wordSize == 5 || wordSize == 6 || wordSize == 7 || wordSize == 8) )
    {
        printf("Error: WordSize must be either 5, 6, 7, or 8\n(Restart the exe file)");
        return 1;
        system("pause");
    }  

    // Getting a Random number between upper and lower limit

    srand(time(NULL));
    int number = rand();
    int upperLimit = 100;
    int lowerLimit = 1  ;
    number =( ( number % ( upperLimit - lowerLimit + 1) ) + lowerLimit );
    
    // Getting the word corresponding to the random number

    FILE *fptr;
    if (wordSize == 5)
    {
        fptr = fopen ("5.txt" , "r");
    }
    else if (wordSize == 6)
    {
        fptr = fopen ("6.txt" , "r");
    }
    else if (wordSize == 7)
    {
        fptr = fopen ("7.txt" , "r");
    }
    else
    {
        fptr = fopen ("8.txt" , "r");
    }
    

    bool keepReading = true;
    int readLine = number;
    int currentLine = 1;
    char word[100];

    while (keepReading)
    {
        fgets(word , 100 , fptr ); 
        if (feof(fptr))
        {
            keepReading = false;
        }
        else if (currentLine == readLine)
        {
            keepReading = false;   
        }
        currentLine++;
        
    }

        printf("\033[1;32mWelcome To Wordle - Made by:Mohammed Irfan \033[0m\n");
        printf("INSTRUCTIONS:- ");
        printf("You get 6 tries to guess a %d-letter word...\n", wordSize);
        printf("The Guesses should only contain Lowercase Alphabets (or else it will keep on repromting)\n");
        printf("Green means the letter is in the word and in the correct spot\n");
        printf("Yellow means the letter is in the word but not in the right spot\n");
        printf("Red means the letter is not even in the word\n");
        printf("The word you need to find always has unique letters..\n");


            bool keepGuessing = true;
            char guess[10] = "guess";
            int guessno = 1;
            do
            {
                bool rePromt = true;

                    // getting the Guesses....
                do
                {

                    printf("Input a %d-letter word: ", wordSize);
                   // scanf("%s",guess);
                    //gets(guess);

                    scanf("%[^\n]s",guess);    // should figure out a way to use this with looping forever
                    scanf("%s",guess);        
                    
                    // PERSONEL NOTE : using     
                    //                     scanf("%[^\n]s",guess);
                    //                     scanf("%s",guess);        
                    //                 together gets the work done :D ... but how??


                    if(strlen(guess) == wordSize)
                    {
                        rePromt = false;

                        for (int i = 0; i < strlen(guess); i++)
                        {
                            if (guess[i] == ' ' )
                            {
                                rePromt = true;
                                break;
                            }
                            
                            if (! (isalpha(guess[i]) && islower(guess[i]) ) )
                            {
                                rePromt = true;
                                break;
                            }
                        }                
                    }

                } while(rePromt);

                int pts[20];

                for (int i = 0; i < wordSize; i++)      // a is actual and g is guess
                {
                   for (int j = 0; j < wordSize ; j++)
                    {
                        if (guess[i] == word[j] && i == j  )
                        {      
                            pts[i] = 2 ;
                            break;
                        }
                        else if (guess[i] == word[j])
                        {                         
                            pts[i] = 1 ;
                            break;
                        }
                        else
                        {
                            pts[i] = 0;
                        }                                    
                    }   
                }

                int points = 0;
                printf("Guess-%d:",guessno);
                

                    for (int k = 0; k < wordSize; k++)
                    {
                        if (pts[k] == 2)
                        {
                            printf("\033[1;32m%c\033[0m", guess[k] );
                        }
                        else if (pts[k] == 1)
                        {
                            printf("\033[1;33m%c\033[0m", guess[k] );
                        }
                        else
                        {
                            printf("\033[1;31m%c\033[0m", guess[k] );
                        }

                        points += pts[k];
                    }

                printf("\n");    

                

              if (2*wordSize == points || guessno == 6 )
              {

                keepGuessing = false;
                    if (2*wordSize == points)
                    {
                        printf("You WIN\n");
                    }
                    else
                    {
                        printf("You Lost...skill issue???\n");
                        printf("The Actual Word: %s",word);
                        //printf("Try again if you got balls...\n");
                    }
                    
              }

              guessno++;
                
            }while (keepGuessing);

    system("pause");
}



