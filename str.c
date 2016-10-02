#include <stdio.h>
#include <stdlib.h>

int len( char *s ) {
  
  int i = 0;
  while ( *s ) {
    i++;
    s++;
  }

  return i;
}

char * ncpy( char *dest, char *src, int n ) {

  while( n && *src ) {
    *dest = *src;
    src++; dest++; n--;
  }

  *dest='\0';

  return dest;
}

char * ncat( char *dest, char *src, int n ) {

  while( *dest ) {
    dest++;
  }

  while( n && *src ) {
    *dest = *src;
    src++; dest++; n--;
  }

  *dest='\0';

  return dest;

}

int ncmp( char *s1, char *s2, int n ) {

  while(n && *s1 && *s2) {
    
    int a1 = (int)(*s1);
    int a2 = (int)(*s2);
    
    if(a1 > a2)
      return 1;
    
    if(a1 < a2)
      return -1;
    
    s1++; s2++; n--;
    
  }

  return 0;
  
}

char * chr( char *s, char c ) {

  while( *s ) {
    if( *s == c )
      return s;

    s++;
  }

  return "oops! not found";

}

int main() {
  char str1[50] = "hello\0";
  char str2[50] = "HELLO\0";

  printf("Testing strlen...\n");
  printf("str1: %s\n", str1);
  printf("str2: %s\n", str2);
  printf("Length of str1: %d\n", len(str1));
  printf("Length of str2: %d\n", len(str2));
  
  printf("\nTesting strncpy...\n");
  printf("str1: %s\n", str1);
  printf("str2: %s\n", str2);
  ncpy(str1, str2, 3);
  printf("Copy str2 into str1, n=3: %s\n", str1);
  ncpy(str1, "hello\0", 100); //reset str1

  printf("\nTesting strncat...\n");
  printf("str1: %s\n", str1);
  printf("str2: %s\n", str2);
  ncat(str1, str2, 3);
  printf("Append str2 to str1, n=3: %s\n", str1);
  ncpy(str1, "hello\0", 100); //reset str1
  
  printf("\nTesting strncmp...\n");
  printf("str1: %s\n", str1);
  printf("str2: %s\n", str2);
  printf("Compare str1 to str2, n=3: %d\n", ncmp(str1, str2, 3));
  printf("Compare str2 to str1, n=3: %d\n", ncmp(str2, str1, 3));
  printf("Compare str1 to str1, n=6: %d\n", ncmp(str1, str1, 6));
  
  printf("\nTesting strchr...\n");
  printf("str1: %s\n", str1);
  printf("Find 'e' in str1: %s\n", chr(str1, 'e'));
  printf("Find 'E' in str1: %s\n", chr(str1, 'E'));
  
}
