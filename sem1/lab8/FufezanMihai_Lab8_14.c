/*
 * Fufezan Mihai, 2012, lab08, ex 14
 *
 * Display each occurrence of each character in the English alphabet in a test
 * string, "The quick brown fox jumps over the lazy dog." (Morse code), on a
 * line there will be a triplet of the searched character (Morse code), the
 * offset inside the string where it was found, (relative position to the
 * beginning) and the appropriate character. Display the initial test string
 * with the first occurrence of each character converted to uppercase if
 * necessary (not uppercase or other non-alphabetical characters).
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
  char teststr[] = "the quick brown fox jumps over the lazy dog";
  bool occurence[26] = {};
  char morse[][26] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                      "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                      "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                      "...-", ".--",  "-..-", "-.--", "--.."};

  // convert first occurence of each char to uppercase then display
  printf("The string with first occurence of each character in uppercase:\n\n");
  for(int i = 0; i < strlen(teststr); i++) {
    if(teststr[i] >= 'a' && !occurence[teststr[i] - 97]) {
      teststr[i] -= 32;
      occurence[teststr[i] - 97] = true;
    }
    printf("%c", teststr[i]);
  }

  printf("\n\nThe string converted to morse code is:\n");
  
  // convert string to uppercase and display it
  for(int i = 0; i < strlen(teststr); i++) {
    if(teststr[i] >= 'a') teststr[i] -= 32;
    printf("%s\n", morse[teststr[i] - 65]);
  }
}
