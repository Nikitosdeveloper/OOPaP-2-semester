#include "SparesSets.h"

SparesSets::SparesSets()
{
	version_ = "0.001";
}

SparesSets::SparesSets(std::string version)
{
	version_ = version;
}

std::string SparesSets::getVersion()
{
	return version_;
}

std::ostream& operator<<(std::ostream& ous, const SparesSets& sets)
{
	ous << "Версия: ";
	ous << sets.version_;
	return ous;
}
