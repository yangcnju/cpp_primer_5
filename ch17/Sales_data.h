// Sales_data with output iter
#ifndef _Sales_data_h
#define _Sales_data_h

#include <iostream>
#include <string>
#include <memory>

class Sales_data;
template <> struct std::hash<Sales_data>;


std::ostream& operator<<(std::ostream&, const Sales_data&);
std::istream& operator>>(std::istream&, Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

class Sales_data{
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend std::istream& operator>>(std::istream&, Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	friend struct std::hash<Sales_data>;
	friend bool compareItem(const Sales_data&, const Sales_data&);
public:
	Sales_data(): 
		item_name(std::make_shared<std::string>(std::string())), 
		q(std::make_shared<std::size_t>(1)), 
		p(0.0) {}
	Sales_data(const std::string&, double p=0.0, std::size_t num = 0);
	Sales_data(const Sales_data&);
	Sales_data(Sales_data&&) noexcept;
	Sales_data& operator=(const Sales_data&);
	Sales_data& operator=(Sales_data&&) noexcept;
	~Sales_data() { }

	double price() const { return p; }
	std::size_t amount() const { return *q; }
	std::string name() const { return *item_name; }
	double total() const { return (*q) * p; }		// quantity * single item price

	// conversions for ex14.45
	explicit operator std::string() const { return *item_name; }
	explicit operator double() const { return total(); }

private:
	std::shared_ptr<std::string> item_name;
	std::shared_ptr<std::size_t> q; 	// quantity
	double p;		// single item price
};	// class Sales_data

bool compareItem(const Sales_data&, const Sales_data&);

#endif
