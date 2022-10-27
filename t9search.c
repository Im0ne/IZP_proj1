#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  const int count = 100; // maximum count of contacts
  size_t n = 0; // variable that depends of real number of contacts
  int result = 1; // variable for check about state of input or output
  char lettonum[10][20] = {{"abcABC"}, {"defDEF"}, {"ghiGHI"}, {"jklJKL"}, 
  {"mnoMNO"}, {"pqrsPQRS"}, {"tuvTUV"}, {"wxyzWXYZ"}, {"+"}};             // 2d array of letters to transform
  char list[count][101]; //contacts                                                                                                              
  char arr[count][101];  //array for transformed contacts                                                                                                              

  if(argc>2){
    result=2;
  }

  if (argv[1] != NULL){
  for(int j = 0; j<strlen(argv[1]);j++) //checking if input only in numbers
  {
    if(argv[1][j]<48||argv[1][j]>57||argv[2]!=NULL){ 
      result=2;

    }
  }
  }

  if(result==1){ //checking if all ok with input
  
  while (n < count && fgets(list[n], sizeof(*list), stdin) != NULL){
    ++n; // getting the contacts from .txt file
  }
  
  for (size_t i = 0; i < n ; i++) 
  {
    list[i][strcspn(list[i], "\n")] = 0; // deleting the new line character from 2d array of contacts
    
    memcpy(&arr[i], &list[i], sizeof(arr[count])); // copy from 2d array of contacts to 2d array for transformation contacts
    
    if (argv[1] == NULL)// defining if there's any input for search contacts
    { 
      printf("%s, %s", list[i], list[i + 1]);
      i++;
      result = 0;
    }

    else if (strstr(list[i], argv[1]) != NULL) // trying to find contact depending on number of contact
    { 
      printf("%s, %s\n", list[i - 1], list[i]);
      result = 0; 
    }
    
    else if (strncmp(list[i], argv[1], strlen(argv[1])) != 0)// trying to find contact depending on name of contact
    { 
      for (int g = 0; g < 101; g++)
      {
        // converting letters to numbers
        for (int j = 0; j < 6; j++)
        {
          if (arr[i][g] == lettonum[0][j])
          {
            arr[i][g] = '2';
          }
          else if (arr[i][g] == lettonum[1][j])
          {
            arr[i][g] = '3';
          }
          else if (arr[i][g] == lettonum[2][j])
          {
            arr[i][g] = '4';
          }
          else if (arr[i][g] == lettonum[3][j])
          {
            arr[i][g] = '5';
          }
          else if (arr[i][g] == lettonum[4][j])
          {
            arr[i][g] = '6';
          }
          else if (arr[i][g] == lettonum[6][j])
          {
            arr[i][g] = '8';
          }
        }
        for (int j = 0; j < 8; j++)
        {
          if (arr[i][g] == lettonum[5][j])
          {
            arr[i][g] = '7';
          }
          else if (arr[i][g] == lettonum[7][j])
          {
            arr[i][g] = '9';
          }
        }
        if (arr[i][g] == lettonum[8][0])
        {
          arr[i][g] = '0';
        }
      }

      if (strstr(arr[i], argv[1]) != NULL) // comparing transformed name to input
      { 
        if(arr[i][0]=='0'){ //checking if list of contacts was number thats starts with +
          printf("%s, %s\n", list[i-1], list[i]);
          result = 0;
        }
        else{
        printf("%s, %s\n", list[i], list[i + 1]);
        result = 0;
        }
        }
    }
  }
  }
  if (result == 1)
  {
    printf("Not found"); // output for not finding any contacts
    result=0;
  }
  else if (result == 2)
  {
    fprintf(stderr,"Invalid input"); // output for error   
  }
  return result;
}
