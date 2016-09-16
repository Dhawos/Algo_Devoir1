#include <cstdlib>
#include <string>
using std::string;
class Card
{
public:
	//User defined types
	enum Color { Black, Red };
	//Constructors and Destructor
	Card(); //Default constructor
	~Card(); //Destructor
	//Getters
	short getValue() const;
	string getColor() const;
	short getBonus() const;
	float getPlayingValue() const;
	friend std::ostream& operator<< (std::ostream&, const Card);
private:
	short value = rand() % 10 + 1; //The number of the card (between 1 and 10)
	enum Color color = Card::Color(rand() % 2); //0 for Black, 1 for Red
	short bonus = rand() % 4 + 1; //The bonus of the card (between 1 and 4)
};

