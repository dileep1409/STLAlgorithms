#pragma once


class Resource
{
	int i = 1;
	static int objectcount;
public:
	Resource();
	Resource(const Resource& r);
	//Resource& operator=(const Resource&r);
	void setValue(int ii) { i = ii; }
	int getValue() const { return i; }

	~Resource();
};