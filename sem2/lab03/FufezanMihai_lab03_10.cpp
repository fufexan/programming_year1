/*
 * Fufezan Mihai, 2012, lab03, ex 10
 *
 * Write a C/C++ application that finds and displays the images that represent
 * the closest match to a certain searching key. The searching key is stored in
 * each image's header and it is represented using a structure with the
 * following fields: a filename (string of characters), a path (string of
 * characters), an intensity resolution (integer value) and a dimension in bytes
 * (integer value). Use a different searching technique for each key type. The
 * headers are either stored into a file or the correspondent data is read from
 * the keyboard.
 */

#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("images.txt");

struct image {
  char filename[256];
  char path[1024];
  int resolution;
  int size;
};

void read_images_console(vector<image> &images, int n);
void read_images_file(vector<image> &images);
void print_image(image i);

int main() {
  vector<image> images;
  bool found = false;

  // read images
  if (fin.fail()) {
    cout << "Enter the number of images to read: ";
    static int n;
    cin >> n;

    read_images_console(images, n);
  } else
    read_images_file(images);

  // read key
  cout << "Choose an attribute of the file to search for:\n"
          "f - filename\np - path\nr - resolution\ns - file size: ";
  char c;
  cin >> c;

  switch (c) {
  case 'f':
    static char filename[256];
    found = false;

    // get search key
    cout << "Filename: ";
    cin.get();
    cin.getline(filename, 256);

    // search through vector
    for (image i : images) {
      if (strstr(i.filename, filename)) {
        cout << "\nClosest match was:\n";
        print_image(i);
        found = true;
        break;
      };
      if (!found)
        cout << "Couldn't find a match!";
    }
    break;
  case 'p':
    static char path[1024];
    found = false;

    cout << "Path: ";
    cin.get();
    cin.getline(path, 1024);

    // search through vector
    for (image i : images) {
      if (strstr(i.path, path)) {
        cout << "\nClosest match was:\n";
        print_image(i);
        found = true;
        break;
      };
      if (!found)
        cout << "Couldn't find a match!";
    }
    break;
  case 'r':
    static int resolution;
    found = false;

    cout << "Resolution: ";
    cin >> resolution;

    // search through vector
    for (image i : images) {
      if (i.resolution == resolution) {
        cout << "\nClosest match was:\n";
        print_image(i);
        found = true;
        break;
      };
      if (!found)
        cout << "Couldn't find a match!";
    }
    break;
  case 's':
    static int size;
    found = false;

    cout << "File size: ";
    cin >> size;

    // search through vector
    for (image i : images) {
      if (i.size == size) {
        cout << "\nClosest match was:\n";
        print_image(i);
        found = true;
        break;
      };
      if (!found)
        cout << "Couldn't find a match!";
    }
    break;
  default:
    cout << "Unknown attribute!";
    exit(1);
  }
}

void read_images_console(vector<image> &images, int n) {
  image x;
  for (int i = 0; i < n; i++) {
    cout << "Image #" << i << "\n\n";
    cout << "Filename: ";
    getchar();
    cin.getline(x.filename, 256);
    cout << "Path: ";
    getchar();
    cin.getline(x.path, 1024);
    cout << "Resolution: ";
    cin >> x.resolution;
    cout << "File size: ";
    cin >> x.size;

    images.push_back(x);
  }
}

void read_images_file(vector<image> &images) {
  image x;
  char c;
  while (fin.get(c)) {
    if (fin.eof())
      break;
    fin.getline(x.filename, 256);
    for (int i = strlen(x.filename) - 1; i >= 0; i--)
      x.filename[i + 1] = x.filename[i];
    x.filename[0] = c;
    fin.get();
    fin.getline(x.path, 1024);
    fin >> x.resolution;
    fin >> x.size;

    images.push_back(x);
  }
}

void print_image(image i) {
  cout << "\nFilename: " << i.filename << '\n';
  cout << "Path: " << i.path << '\n';
  cout << "Resolution: " << i.resolution << '\n';
  cout << "File size: " << i.size << '\n';
}
