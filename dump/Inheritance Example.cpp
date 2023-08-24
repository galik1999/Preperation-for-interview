#include <string>
#include <iostream>;
using namespace std;

class Sports {
public:
	virtual void printName() = 0;
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
	~Sports()
	{
		cout << "Destructor for " << getName() << "is called" << endl;
	}
private:
	string name;
	//int popularityRating;
	//bool isOlympicSport;
	//long highestSalary;
};

class TableTennis : public Sports {
public:
	TableTennis() : Sports() {
		this->setName("Table Teenis");
	};
	void printName() {
		cout << this->getName() << endl;
	}
};
class Football : public Sports {
public:
	Football() : Sports() {
		this->setName("Football");
	};
	void printName() {
		cout << this->getName() << endl;
	}
};
class Chess : public Sports {
public:
	Chess() : Sports() {
		this->setName("Chess");
	};
	void printName() {
		cout << this->getName() << endl;
	}
};

int main() {
	Sports* sports[3] = {new TableTennis(),new Football(),new Chess()};
	for (auto s : sports) {
		s->printName();
	}
	for (auto s : sports) {
		delete s;
	}
	return 0;
}