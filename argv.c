#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
   //Require user to submit two command line arguments 
   if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    
    //Check character by character if input is all digits
    
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (isdigit(argv[1][i]))
        {
            continue;
        }
        else 
        {
            printf("error\n");
            return 1;
        }
    }
    
    //Input passes digit check, convert to integer
    
    int k = atoi(argv[1]);
     
     //Prompt user for plaintext
    
    string text = get_string("plaintext: ");
    int length = strlen(text);
    
    //Iterate over each character of plaintext
    
    
    for (int i = 0; i < length; i++)
    {
        //handles uppercase
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] += + k;
            if (text[i] > 'Z')
            {
                (text[i] = text[i] - 'Z' + 'A' - 1);
            }
            printf("%c", text[i]);
        }
        
       //handles lowercase
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] += k;
            if (text[i] > 'z')
            {
                (text[i] = text[i] - 'z' + 'a' - 1);
            }
            printf("%c", text[i]);
        }
        
        //handles spaces
        else if (isspace(text[i]))
        {
            printf("%c", text[i]);
        }
       
        //handles nums and other characters
        else 
        {
            printf("%c ", text[i]);
        }
    }
    printf("\n");
    
    //
    
    printf("ciphertext: %s\n", text);
    
    printf("Key: %i\n", k);
    
}






/*
    
    //checks the value of integer
    if (k < 0)
    {
        printf("negative integer invalid\n");
        return 1;
    }
    */ 
    