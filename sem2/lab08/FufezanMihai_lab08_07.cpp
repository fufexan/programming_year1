/*
 * Fufezan Mihai, 2012, lab08, ex 07
 *
 * A kiosk sells newspapers, magazines and books. Each publication has a name,
 * an editorial house, a number of pages, the number of copies and a price (no
 * VAT). Write the class that models the publications. Introduce a static member
 * named VAT_value (percentage) and a static method that modifies the value of
 * this variable. Determine the total income and the average price per page for
 * each publication type. Modify the VAT and redo the calculations. Order the
 * printing houses by the total income and display the result.
 */

#include <cstring>
#include <iostream>

using namespace std;

// publication implementation
class Pub {
  char *name, *editorial_house;
  int pages, copies;
  double price;

  int nsize, esize;

  // percentage
  static double VAT;

public:
  Pub(char *name = (char *)"Unknown", char *editorial_house = (char *)"Unknown",
      int pages = 0, int copies = 0, double price = 0);
  ~Pub();

  double avgPricePerPage();
  double totalIncome();

  // setters
  void setPrice(double x) { price = x; }
  static void setVAT(double x) { VAT = x; }

  // getters
  char *getName() { return name; }
  char *getEditorialHouse() { return editorial_house; }

  void read_pub();
};

double Pub::VAT;

int cmp(void const *a, void const *b) {
  return ((Pub *)b)->totalIncome() - ((Pub *)a)->totalIncome();
}

int main() {
  int n;

  // read number of pubs
  cout << "How many publications does a kiosk sell? ";
  cin >> n;

  // init pubs
  Pub *pubs = new Pub[n];

  // read pubs
  cout << "\nEnter publications:\n";
  for (int i{}; i < n; i++) {
    cout << "\nPublication #" << i;
    pubs[i].read_pub();
  }

  // vat
  cout << "\nEnter a VAT percentage: ";
  double vat;
  cin >> vat;
  pubs[0].setVAT(vat);

  cout << "\nThe average price per page and total income, for each "
          "publication, is:\n";
  for (int i{}; i < n; i++)
    cout << "\nName: " << pubs[i].getName()
         << "\nAverage price per page: " << pubs[i].avgPricePerPage()
         << "\nTotal income: " << pubs[i].totalIncome() << '\n';

  qsort(pubs, n, sizeof(Pub), cmp);
  cout << "\nThe editorial houses, in the order of the total income, are:\n";
  for (int i{}; i < n; i++)
    cout << pubs[i].getEditorialHouse() << "\n";

  // free memory
  delete[] pubs;
}

void Pub::read_pub() {
  cin.get();
  cout << "\nName: ";
  cin.getline(name, nsize);

  cout << "Editorial house: ";
  cin.getline(editorial_house, esize);

  cout << "Number of pages: ";
  cin >> pages;

  cout << "Number of copies: ";
  cin >> copies;

  cout << "Price: ";
  cin >> price;
}

Pub::Pub(char *name, char *editorial_house, int pages, int copies,
         double price) {
  nsize = 50;
  esize = 50;

  this->name = new char[nsize];
  this->editorial_house = new char[esize];

  strcpy(this->name, name);
  strcpy(this->editorial_house, editorial_house);

  this->pages = pages;
  this->copies = copies;
  this->price = price;
}

Pub::~Pub() {
  delete[] name;
  delete[] editorial_house;
}
double Pub::avgPricePerPage() { return VAT * price / pages; }
double Pub::totalIncome() { return VAT * price * copies; }
