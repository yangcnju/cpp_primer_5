#include <string>
#include <iostream>

class Employee {
public:
	Employee();
	Employee(const Employee&) = delete;
	Employee& operator=(const Employee&) = delete;
	~Employee() = default;
	unsigned int show() const { return id; }
	std::string who() const { return name; }
private:
	static unsigned int num;
	std::string name;
	unsigned int id;
};	// class Employee

unsigned int Employee::num = 0;

Employee::Employee():
	name("default"), id(num++)
{
}

int main()
{
	Employee a,b,c;
	std::cout << a.who() << " " << a.show() << std::endl;
	std::cout << b.who() << " " << b.show() << std::endl;
	std::cout << c.who() << " " << c.show() << std::endl;

	return 0;
}
