// Sales_data with output iter
#ifndef _ex14_49_Sales_data_h
#define _ex14_49_Sales_data_h

#include <iostream>
#include <string>
#include <memory>

class Sales_data{
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend std::istream& operator>>(std::istream&, Sales_data&);
public:
	Sales_data(): 
		item_name(std::make_shared<std::string>(std::string("default"))), 
		q(std::make_shared<std::size_t>(0)), 
		p(0.0) {}
	Sales_data(const std::string&, double p, std::size_t num = 1);
	Sales_data(const Sales_data&);
	Sales_data(Sales_data&&) noexcept;
	Sales_data& operator=(const Sales_data&);
	Sales_data& operator=(Sales_data&&) noexcept;
	~Sales_data() {}

	double price() const { return p; }
	std::size_t amount() const { return *q; }
	std::string name() const { return *item_name; }
	double total() const { return (*q) * p; }		// quantity * single item price

	// ex14.49 and ex14.48
	explicit operator bool() const { return *q; }
private:
	std::shared_ptr<std::string> item_name;
	std::shared_ptr<std::size_t> q; 	// quantity
	double p;		// single item price
};	// class Sales_data

#endif
