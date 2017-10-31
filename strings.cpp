#include "strings.h"

std::string stdString(System::String^ sysS)
{
	std::string stdS = "";

	int i;
	for (i = 0; i < sysS->Length; i++)
	{
		stdS += (char)(sysS->ToCharArray()[i]);
	}

	return stdS;
}

System::String^ sysString(std::string& stdS)
{
	System::String^ sysS = "";

	int i;
	for (i = 0; i < stdS.length(); i++)
	{
		sysS = sysS->Concat(stdS[i]);
	}

	return sysS;
}
