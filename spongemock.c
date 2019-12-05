#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) 
{
  // if there is no arguments passed, just get data from stdin
  if(argc == 1) 
  {
    FILE *fp = stdin;
    size_t c, last;
    while ((c = getc(fp)) != EOF) 
    {
      // downcase character if it needs to be
      if(c >= 65 && c <= 90)
        c+=32;

      // if the current character is between a-z
      if(c > 96 && c <= 122) 
      {
        // if the last char is between a-z, upcase the current char
        if(last > 96 && last <= 122)
          c -=32;
        last = c; 
      }
      printf("%c", c);
    }
    return 0;
  } else if( (strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help")) == 0) 
  {
      printf("usage: %s 'some text you want to mock'\r\n", argv[0]);
      return 0;
  }

  size_t total_str_len = argc-2;
  size_t i, j, pos;

  // Check the total length of all the arguments.
  for(i = 1; i < argc; i++)
    total_str_len+= strlen(argv[i]);

  // create a new string that long
  char str[total_str_len + 1];
  pos = 0;

  // copy all the args into that long string
  for(i = 1; i < argc; i++) 
  {
    j = 0;
    while(argv[i][j] > 0) 
    {
      str[pos] = argv[i][j];

      // downcase the character if it was upcased
      if(str[pos] >= 65 && str[pos] <= 90)
        str[pos]+=32;

      // if the current character is between a-z
      if(str[pos] > 96 && str[pos] <= 122) 
      {
        // if the last char is between a-z, upcase it
        if(str[pos-1] > 96 && str[pos-1] <= 122)
          str[pos] = str[pos] - 32;
      }

      j++; pos++;
    }
    str[pos++] = 32;
  }
  // add a null terminator at the end for good luck
  str[pos++] = '\0';

  // print the str
  printf("%s", str);
  return 0;
}