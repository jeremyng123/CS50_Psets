/**
 * amex uses 15-digit numbers -- starts with 34 or 37
 * mastercard uses 16-digit numbers -- starts with [51,55]
 * visa uses 13 and 16 digit numbers -- starts with 4
 * each number is a decimal number, not binary.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
prototyping in C to give compiler a heads up that we have functions 
the following parameters required...
*/

int parseToInt(char);
char *substring(char *string, int position, int length);
char *validity(char *string);

int main(void){
    char card_number[16], *pointer;

    printf("Validate this number: ");
    gets(card_number);

    pointer = validity(card_number);
    printf("result = %s\n", pointer);
    
}

int parseToInt(char x){
    return (int) x - '0';
}

// int size(char* x){
//     int i = 0;
//     int length = 0;
//     while (x[i] != '\0') {
//         i++;
//         length++;
//     }
//     return length;
// }

// char *substring (char *array, int start, int end){
//     int index = 0;
//     int lengthOfIter = end - start;
//     char *newArray = "0";
//     while (index<= lengthOfIter){
//         newArray[index] = array[start + index];
//         index++;
//     }
//     newArray[end+1] = '\0';
//     printf("substring(card_number[0,1]) = %s\n", newArray);
//     return newArray;
// }

/**
 * C substring function: It returns a pointer to the substring 
 * 
 * need to #include <stdlib.h>!
 * */
char *substring(char *string, int position, int length)
{
   char *pointer;
   int c;
 
   pointer = malloc(length+1);
   
   if (pointer == NULL)
   {
      printf("Unable to allocate memory.\n");
      exit(1);
   }
 
   for (c = 0 ; c < length ; c++)
   {
      *(pointer+c) = *(string+position-1);      
      string++;  
   }
 
   *(pointer+c) = '\0';
 
   return pointer;
}

/**
 * amex uses 15-digit numbers -- starts with 34 or 37
 * mastercard uses 16-digit numbers -- starts with [51,55]
 * visa uses 13 and 16 digit numbers -- starts with 4
 * each number is a decimal number, not binary.
 */
char *validity(char *string){
   char *result, *card;
   int length = strlen(string);
   card = malloc(2);
   result = malloc (length);
   if (card == NULL || result == NULL)
   {
      printf("Unable to allocate memory.\n");
      exit(1);
   }
   *card = substring(string,0,2);
   printf("card = %s\n",card);
   if ((card == "34" || card == "37") && length == 15) result = "AMEX";
   else if ((card == "51" || card == "55") && length == 16) result = "MASTERCARD";
   else if (length == 13 || length == 16) {
      if (card[0] == '4') result = "VISA";
   }
   else result = "INVALID";
   result[strlen(result)] = '\0';
   return result;
}