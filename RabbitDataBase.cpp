#include "RabbitDataBase.h"
#include <fstream>
#include "ReadUtils.h"
using namespace std;

RabbitDataBase::RabbitDataBase() {
    numRabbits = 0;
    read();
  };
void RabbitDataBase::read() {
    ifstream rabbitFile("rabbits.txt");
    numRabbits = 0;
    while (rabbitFile.peek() != EOF && numRabbits < MAX_RABBITS) {
        rabbitArray[numRabbits].readFromFile(rabbitFile);
        numRabbits++;
    }
}
void RabbitDataBase::print(ostream &out, bool printIndex){ 
for (int index = 0; index < MAX_RABBITS; index++) {
  if (rabbitArray[index].getIsValid()) {
    if (printIndex) {
      out << "the index is " << index;
    }
    rabbitArray[index].print(out);
    }
  }
}
void RabbitDataBase::save() {
  ofstream out("rabbits.txt");
    print(out, false);
}
void RabbitDataBase::remove() {
  int index = 0;
    do {
        index = readInt("Enter an index to remove between 0 and 7: ");
    }
    while (index < 0 || index >= MAX_RABBITS);
      rabbitArray[index].makeInValid();
      
}
void RabbitDataBase::add() {
    for (int index = 0; index < MAX_RABBITS; index++) {
        if (rabbitArray[index].getIsValid() == false) {
            rabbitArray[index].readFromUser();
            return;
        }
    }
    cout << "Too many rabbits! No room for more!" << endl;

}