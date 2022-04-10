/*
 * Fufezan Mihai, 2012, lab06, ex 05.1
 *
 * Write using references and pointers.
 *
 * Write a C++ application that implements a class called F1Pilot. The class
 * defines the private variables name (array of characters), team (array of
 * characters), age (int), best_time (int) and pole_position_nr(int). As public
 * members, the class contains mutator/setter and accessor/getter methods for
 * each of the class’s attributes.
 * In function main(), create 3 different instances of the F1Pilot class and use
 * the seter methods for initializing each object’s data with the corresponding
 * information read from the keyboard. Using the getter methods, display all the
 * data related to the pilot that has the best time.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class F1Pilot {
  string name, team;
  int age, best_time, pole_position_nr;

public:
  void setName(string x) { name = x; }
  string getName() { return name; }

  void setTeam(string x) { team = x; }
  string getTeam() { return team; }

  void setAge(int x) { age = x; };
  int getAge() { return age; }

  void setTime(int x) { best_time = x; };
  int getTime() { return best_time; }

  void setPolePositionNr(int x) { pole_position_nr = x; };
  int getPolePositionNr() { return pole_position_nr; }
};

void readPilot(string &name, string &team, int &age, int &best_time,
               int &pole_position_nr);
void printPilot(F1Pilot *x);

int main() {
  F1Pilot *a = new F1Pilot;
  F1Pilot *b = new F1Pilot;
  F1Pilot *c = new F1Pilot;
  string name, team;
  int age, best_time, pole_position_nr;

  cout << "Enter F1 pilots' data:\n";

  cout << "\nEnter pilot 1's data:\n";
  readPilot(name, team, age, best_time, pole_position_nr);
  a->setName(name);
  a->setTeam(team);
  a->setAge(age);
  a->setTime(best_time);
  a->setPolePositionNr(pole_position_nr);

  cout << "\nEnter pilot 2's data:\n";
  readPilot(name, team, age, best_time, pole_position_nr);
  b->setName(name);
  b->setTeam(team);
  b->setAge(age);
  b->setTime(best_time);
  b->setPolePositionNr(pole_position_nr);

  cout << "\nEnter pilot 3's data:\n";
  readPilot(name, team, age, best_time, pole_position_nr);
  c->setName(name);
  c->setTeam(team);
  c->setAge(age);
  c->setTime(best_time);
  c->setPolePositionNr(pole_position_nr);

  vector<F1Pilot **> pilots;
  pilots.push_back(&a);
  pilots.push_back(&b);
  pilots.push_back(&c);

  int time = (*pilots[0])->getTime();
  F1Pilot *pos;
  for (auto it : pilots)
    if ((*it)->getTime() < time) {
      time = (*it)->getTime();
      pos = *it;
    }

  cout << "\n\nFastest pilot:\n";
  printPilot(pos);
}

void readPilot(string &name, string &team, int &age, int &best_time,
               int &pole_position_nr) {
  cout << "Name: ";
  getline(cin, name);

  cout << "Team: ";
  getline(cin, team);

  cout << "Age: ";
  cin >> age;

  cout << "Best time: ";
  cin >> best_time;

  cout << "Pole position number: ";
  cin >> pole_position_nr;
  cin.get();
}

void printPilot(F1Pilot *x) {
  cout << "Name: " << x->getName() << "\nTeam: " << x->getTeam()
       << "\nAge: " << x->getAge() << "\nBest time: " << x->getTime()
       << "\nPole position number: " << x->getPolePositionNr();
}
