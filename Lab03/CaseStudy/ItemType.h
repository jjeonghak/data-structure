// ItemType.h  contains the specifications for the data for the real 
//  estate manipulation program.
const int MAX_ITEMS = 25; 
#include <fstream> 
#include "StrTypeAugmented.h"   // Gain access to String ADT.

enum RelationType {LESS, EQUAL, GREATER};
class HouseType
{ 
public:
   
  void GetFromFile(std::ifstream& file) {
      lastName.GetStringFile(true, NOT_NEW, file);
      firstName.GetStringFile(true, NOT_NEW, file);
      address.GetStringFile(true, NOT_NEW, file);
      file >> price >> squareFeet >> bedRooms >> bathRooms;
  }

  void WriteToFile(std::ofstream& file) {
      using std::endl;
      lastName.PrintToFile(false, file);
      firstName.PrintToFile(true, file);
      address.PrintToFile(true, file);
      file << endl << price << endl;
      file << squareFeet << endl;
      file << bedRooms << endl;
      file << bathRooms << endl;
  }

  void GetFromUser() {
      using namespace std;
      cout << "Enter last name; press return." << endl;
      lastName.GetString(true, NOT_NEW);
      cout << "Enter first name; press return." << endl;
      firstName.GetString(true, NOT_NEW);
      cout << "Enter address; press return." << endl;
      address.GetString(true, NOT_NEW);
      cout << "Enter price, square feet, number of bedrooms, number of bathRooms;"
          << " press return." << endl;
      cin >> price >> squareFeet >> bedRooms >> bathRooms;
  }

  void PrintHouseToScreen() {
      using namespace std;
      firstName.PrintToScreen(false);
      cout << " ";
      lastName.PrintToScreen(false);
      address.PrintToScreen(true);
      cout << endl << "Price: " << price << endl;
      cout << "Square Feet: " << squareFeet << endl;
      cout << "Bedrooms: " << bedRooms << endl;
      cout << "Bathrooms: " << bathRooms << endl;
  }

  void GetNameFromUser() {
      using namespace std;
      cout << "Enter last name;  press return." << endl;
      lastName.GetString(true, NOT_NEW);
      cout << "Enter first name;  press return." << endl;
      firstName.GetString(true, NOT_NEW);
  }

  void PrintNameToScreen() {
      using namespace std;
      firstName.PrintToScreen(false);
      cout << " ";
      lastName.PrintToScreen(false);
      cout << endl;
  }

  bool operator<(const HouseType& other) {
      if (lastName < other.lastName)
          return true;
      else if (firstName < other.firstName)
          return true;
      return false;
  }

  bool operator==(const HouseType& other) {
      return lastName == other.lastName && firstName == other.firstName;
  }

  RelationType ComparedTo(HouseType house) {
      if (*this == house)
          return EQUAL;
      else if (*this < house)
          return LESS;
      else
          return GREATER;
  }

private:
  StrType lastName; 
  StrType firstName; 
  StrType address; 
  float price; 
  int squareFeet; 
  int bedRooms;
  int bathRooms;
}; 

// Make ItemType an alias for HouseType. 
typedef HouseType ItemType;
