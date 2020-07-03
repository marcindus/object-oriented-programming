#include "Observer.hpp"
#include "Ship.hpp"


void ClientCode() {
  Subject *subject = new Subject;
  Ship ship1(*subject);
  Ship ship2(*subject);
  ship1.setName("Czarna perła");
  ship2.setName("Pan Gąbka");

  subject->CreateMessage("Hello World! :D");
  subject->CreateMessage("The weather is hot today! :p");

  ship1.RemoveMeFromTheList();
  subject->SomeBusinessLogic();

  delete subject;
}

int main() {
  ClientCode();
  return 0;
}
