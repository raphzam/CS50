#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
require / accept a single command line argument
check the input to see if all the characters are digits
convert the key from a string value to an integer value
prompt the user for plain text
iterate over each character of the plaintext
if upper, retain casing, rotate the letter by the key
if lower, retain casing, rotate the letter by the key
if else (nums, spaces, special characters), print as is
use arithmetic function to make sure letters wrap around
return ciphered text
*/

string cipher(string plain, int length);


int main(int argc, string argv[])
{
    //Require command line argument
    if (argc != 2)
    {
        printf("missing command line argument\n");
        return 1;
    }

    //Check that each charcter in the Key is a digit
    int length = strlen(argv[1]);
    for (int i = 0; i < length; i++)
    {
        if isdigit(argv[1][i])
        {
            continue;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //convert key from string value to integer value
    int k = atoi(argv[1]);
    //printf("key: %i\n", k);

    //Prompt user for plaintext
    string p = get_string("plaintext: ");
    printf("ciphertext: %s\n", cipher(p, k));

}

//Ciper function that requires the plain text and the key,
//use null character to iterate to the end of the string

string cipher(string plain, int key)
{

    //
    char upper[26];
    int A = 'A';
    for (int i = 0; i < 26 && A <= 'Z'; i++, A++)
    {
        upper[i] = A;
    }

    //lowercase wrap index
    char lower[26];
    int a = 'a';
    for (int i = 0; i < 26 && a <= 'z'; i++, a++)
    {
        lower[i] = a;
    }

    //

    for (int i = 0; plain[i] != '\0'; i++)
    {
        if isupper(plain[i])
        {

            if (plain[i] += + key > 'Z')
            {
                //plain[i] = plain[i] - key - 65;
                int n = (plain[i] + key - 65) % 26;
                plain[i] = upper[n];
            }
            else
            {
                plain[i] += + key;
            }
        }
        else if islower(plain[i])
        {
            //plain[i] += + key;
            if (plain[i] += + key > 'z')
            {
                //plain[i] = plain[i] - key - 97;
                int n = (plain[i] + key - 97) % 26;
                plain[i] = lower[n];
            }
            else
            {
                plain[i] += + key;
            }
        }
        else
        {
            plain[i] = plain[i];
        }
    }
    return plain ;
}

