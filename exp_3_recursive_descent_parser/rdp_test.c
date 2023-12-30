/*
Tried a symmetrical string of 0s & 1s using RDP using 0S0 & 1S1 but it got stuck
in if loop. Need to find problem & fix later.
*/

#include <stdio.h>
#include <string.h>

char s[100];
int p = 0;

int S();

int main(void) {
  printf("Hello World, enter a string:\n");
  scanf("%s", s);
  strcat(s, "$");
  if (S() && s[p] == '$') {
    printf("\nString accepted\n");
  } else {
    printf("\nInvalid string\n");
  }
  return 0;
}

int S() {
  if (p == (strlen(s) / 2)) {
    return 1;
    /*
      Nor proper RDP implementation, not sure if this can be done using RDP.
    */
  } else if (s[p] == '0') {
    // printf("yes1");
    p++;
    if (S()) {
      if (s[p] == '0') {
        // printf("yes2");
        p++;
        return 1;
      } else {
        p--;
        return 0;
      }
    } else {
      p--;
      return 0;
    }
  } else if (s[p] == '1') {
    // printf("yes1");
    p++;
    if (S()) {
      if (s[p] == '1') {
        // printf("yes2");
        p++;
        return 1;
      } else {
        p--;
        return 0;
      }
    } else {
      p--;
      return 0;
    }
  } else {
    p--;
    return 0; // return 1; ?
    // epsilon
  }
}
