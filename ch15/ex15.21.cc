#include <iostream>
#include <string>

// (a)
class graphic {
public:
	graphic() = default;
	graphic(const graphic &) = default;
	virtual std::string info() = 0;
};

class compressedGraph : public graphic {
public:
	virtual std::string info() override{ return "compressed graphic."; }
};

class originalGraph : public graphic {
public:
	virtual std::string info() override{ return "graphic of original size."; }
};

class gif : public originalGraph {
public:
	std::string info() override final{ return "git type."; }
};

class tiff : public originalGraph {
public:
	std::string info() override final { return "tiff type."; }
};

class bmp : public originalGraph {
public:
	std::string info() override final { return "bmp type."; }
};

class jpeg : public originalGraph {
public:
	std::string info() override final { return "jpeg type."; }
};

void print_info(graphic &g)
{
	std:: cout << g.info() << std::endl;
}

using namespace std;

int main()
{
	gif g;
	tiff t;
	bmp b;
	jpeg j;	
	print_info(g);
	print_info(t);
	print_info(b);
	print_info(j);

	return 0;
}
