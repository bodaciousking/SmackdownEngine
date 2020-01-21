#pragma once
class Initializer
{
public:
	Initializer();
	~Initializer();

	bool CheckInstances();
	bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	DWORD ReadCPUSpeed();
	int MemoryCheck();
};

