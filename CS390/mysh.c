#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX 20

int main()
{
    char *p,input[256];
    char *q;
    char *A[MAX];
    char *B[2];
    bool exit = false;
    bool carrRet = true;
    int i,j,c,result;
    char PS1 = '$';
    FILE *sf;
    FILE *df;

    /*
    Main Input Loop
    */
    while(exit == false)
    {
        /* check for if carriage return is needed (usually true) */
        if (carrRet == true)
        {
            printf("%c ",PS1);
        }
        carrRet = true;

        /* get input */
        fgets(input, 256, stdin);
        
        /* modified string tokenizer (base tokenizer provided) */
        p = strtok(input, " ");
        for (i = 0; p != 0 && i < (MAX - 1); ++i)
        {
            A[i] = p;
            p = strtok(0, " \t");
            A[i][strcspn(A[i], "\r\n")] = 0;
        }
        A[i] = 0;

        /* If-Else Block for implemented commands */

        if (!strcmp(A[0], "exit"))
        {
            printf("Exiting Program! \n");
            break;
        }
        else if (!strcmp(A[0], "echo"))
        {
            /* Implementation of the -n arg */
            if (!strcmp(A[1], "-n"))
            {
                carrRet = false;
                for(j = 2; j < i; j++)
                {
                    if ((j + 1) == i)
                    {
                        printf("%s",A[j]);
                    }
                    else
                    {
                        printf("%s ",A[j]);
                    }
                }
            }
            else
            {
                /* no -n arg */
                for(j = 1; j < i; j++)
                {
                    if ((j + 1) == i)
                    {
                        printf("%s\n",A[j]);
                    }
                    else
                    {
                        printf("%s ",A[j]);
                    }
                }
            }     
        }
        else if (strstr(input, "PS1=") != NULL)
        {
            /* tokenizing the token to change PS1 */
            q = strtok(input, "=");
            for (i = 0; q != 0 && i < (MAX - 1); ++i)
            {
                B[i] = q;
                q = strtok(0, " \t");
            }
            B[i] = 0;
            B[1][strcspn(B[1], "\r\n")] = 0;
            PS1 = *B[1];
        }
        else if (!strcmp(A[0], "mkdir"))
        {
            /* mkdir implementation */
            result = mkdir(A[1], 0700);
            printf("%d\n", result);
            if (result == 0)
            {
                printf("Directory created!\n");
            }
            else
            {
                printf("Directory could not be created!\n");
            }
        }
        else if (!strcmp(A[0], "rmdir"))
        {
            /* rmdir implementation */
            result = rmdir(A[1]);
            if (result == 0)
            {
                printf("Directory removed!\n");
            }
            else
            {
                printf("Directory could not be removed!\n");
            }
        }
        else if (!strcmp(A[0], "rm"))
        {
            /* rm implementation */
            result = remove(A[1]);
            if (result == 0)
            {
                printf("File removed!\n");
            }
            else
            {
                printf("File could not be removed!\n");
            }
        }
        else if (!strcmp(A[0], "cp"))
        {
            /* cp implementation
            check for no argument
            then check for null ptr
            then open file
            then check for no second argument
            check again for null pointer (should not happen since it creates the file to be written to)
            then open file
            then read
            then write
            then close files */
            if (A[1] == 0)
            {
                printf("Please try again, specifying the file you wish to copy from.\n");
            }
            else
            {
                sf = fopen(A[1], "r");
                if (sf == NULL)
                {
                    printf("Could not open file, please try again.\n");
                }
                else
                {
                    if (A[2] == 0)
                    {
                        printf("Please try again, specifying the file you wish to copy to.\n");
                    }
                    else
                    {
                        df = fopen(A[2], "w");
                        if (df == NULL)
                        {       
                            printf("Could not open file, please try again.\n");
                        }
                        else
                        {
                            while (1)
                            {   
                                c = fgetc(sf);
                                if (feof(sf))
                                {
                                    break;
                                }
                                fprintf(df, "%c", c);
                            }
                            fclose(sf);
                            fclose(df);
                        }
                    }
                }
            }
        }
        else if (!strcmp(A[0], "cat"))
        {
            /* implementation of cat
            check for no argument
            check for null argument
            then open file
            then read
            then write to terminal
            then close file */
            if (A[1] == 0)
            {
                printf("Please try again, specifying the file you wish to see the contents of.\n");
            }
            else
            {
                sf = fopen(A[1], "r");
                if (sf != NULL)
                {
                    while (1) 
                    {
                        c = fgetc(sf);
                        if (feof(sf))
                        {
                            break;
                        }
                        printf("%c", c);
                    }
                    fclose(sf);
                }
                else
                {
                    printf("Could not read file, please try again.\n");
                }
            }
        }
        else
        {
            /* Error message implementation */
            printf("Command not recognized. Please try another command. \n");
        }

    }
    
    /* Terminate program */
    return 0;

}