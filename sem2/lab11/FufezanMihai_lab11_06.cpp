/*
 * Fufezan Mihai, 2012, lab11, ex 06
 *
 * Define a class called Record that stores the data related to a melody
 * (artist, title, duration). An abstract class (Playlist) contains as private
 * attribute a pointer to an array of records. The pointer is initialized in the
 * constructor by a memory allocation process (the number of records is defined
 * by the user). The class contains accessor and mutator methods for each of a
 * record’s fields and an abstract method (pure virtual) that sorts the records
 * array according to a criteria coded in the received parameter (1=sorting by
 * title, 2=sorting by artist, 3=sorting by duration). The abstract method is
 * implemented inside another class (PlaylistImplementation) that inherits the
 * Playlist class. In the main( ) function, instantiate the
 * PlaylistImplementation class and initialize and use all the related data and
 * methods.
 */

#include <iostream>
using namespace std;
#include "FufezanMihai_lab11_06.hpp"

int main() {
  PlaylistImplementation pl;
  char title[50], artist[50];
  int n, d;

  cout << "Enter the number of records you want to add: ";
  cin >> n;

  cout << "\nEnter the records:\n";
  for (int i{}; i < n; i++) {
    cout << "\nRecord #" << i << "\n";
    cout << "Title: ";
    cin.ignore();
    cin.getline(title, 50);
    cout << "Artist: ";
    cin.getline(artist, 50);
    cout << "Duration: ";
    cin >> d;

    pl.setRecord(title, artist, d);
  }

  char choice;
  do {
    cout << "\nHow do you want to sort the playlist?\na - artist\nt - title\nd "
            "- duration\nq - quit: ";
    cin >> choice;

    // handle quit
    if (choice == 'q')
      break;

    pl.sort(choice);

    for (int i{}; i < n; i++) {
      cout << "\nRecord #" << i << "\n";
      cout << "Title: " << pl.getRecord(i).getTitle() << '\n';
      cout << "Artist: " << pl.getRecord(i).getArtist() << '\n';
      cout << "Duration: " << pl.getRecord(i).getDuration() << '\n';
    }
  } while (choice != 'q');
}
