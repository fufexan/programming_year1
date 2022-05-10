/*
 * Fufezan Mihai, 2012, lab11, ex 05
 *
 * Define an abstract class that contains 3 pure virtual methods declarations
 * for concatenating, interlacing two arrays of characters and for reverting the
 * character array received as parameter. A subclass implements the methods
 * declared in the base class. Instantiate the 2-nd class and display the
 * results produced by applying the methods mentioned above upon some data read
 * from the keyboard. Examine the error given by the attempt of instantiating
 * the base class.
 */

#include <cstring>

class Charr {
public:
  virtual char *concat(char *, char *) = 0;
  virtual char *interlace(char *, char *) = 0;
  virtual char *reverse(char *) = 0;
};

class SubCharr : public Charr {
public:
  virtual char *concat(char *a, char *b) {
    char *str = new char[1000];

    strcpy(str, a);
    strcat(str, b);

    return str;
  }

  virtual char *interlace(char *a, char *b) {
    char *str = new char[1000 * 2];

    int i{}, k{};
    for (; k < min(strlen(a), strlen(b)); i += 2) {
      str[i] = a[k];
      str[i + 1] = b[k++];
    }

    int maxx = max(strlen(a), strlen(b));
    char *amax;
    if (maxx == strlen(a))
      amax = a;
    else
      amax = b;

    for (; k < maxx; i++)
      str[i] = amax[k++];

    return str;
  }

  virtual char *reverse(char *a) {
    char *str = new char[1000];

    int j{};
    for (int i = strlen(a) - 1; i >= 0; i--)
      str[j++] = a[i];
    strcat(a, "\0");

    return str;
  }
};
