#include <iostream>
#include <string>>

class SparesSets
{
public:
	SparesSets();
	SparesSets(std::string version);

	std::string getVersion();

private:

	friend std::ostream& operator <<(std::ostream& ous, const SparesSets& mach);

	std::string version_;
};
