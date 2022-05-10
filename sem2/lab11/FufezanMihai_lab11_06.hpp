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

#include <cstdlib>

class Record {
protected:
  char *artist, *title;
  int duration;

public:
  void setArtist(char *a) { artist = a; }
  void setTitle(char *t) { title = t; }
  void setDuration(int d) { duration = d; }

  char *getArtist() { return artist; }
  char *getTitle() { return title; }
  int getDuration() { return duration; }
};

class Playlist : public Record {
  Record *records;
  int nr;

public:
  void setRecord(char *a, char *t, int d) {
    records = (Record *)realloc(records, sizeof(Record) * (nr + 1));
    records[nr].setArtist(a);
    records[nr].setTitle(t);
    records[nr].setDuration(d);
    nr++;
  }
  Record getRecord(int n) { return records[n]; }

  void setArtist(char *a) { Record::setArtist(a); }
  void setTitle(char *t) { Record::setTitle(t); }
  void setDuration(int d) { Record::setDuration(d); }

  char *getArtist() { return Record::getArtist(); }
  char *getTitle() { return Record::getTitle(); }
  int getDuration() { return Record::getDuration(); }

  virtual void sort(int) = 0;
};

class PlaylistImplementation : public Playlist {
public:
  void setRecord(char *a, char *t, int d) { Playlist::setRecord(a, t, d); }
  virtual void sort(int);
};

virtual void PlaylistImplementation::sort(int mode) {
  switch (mode) {
  case 1:
    qsort(records)
  }
}
