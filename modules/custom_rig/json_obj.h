#pragma once

#ifndef JSONOBJ_H
#define JSONOBJ_H
#endif // !CUSTOMRIG_H

#include <vector>

//#include "core/reference.h"
#include "core/object.h"
#include "core/io/json.h"
#include "core/bind/core_bind.h"

class JsonObj : public Object {
	GDCLASS(JsonObj, Object);

public:
	int testProperty = 0;

	JsonObj(){};
	~JsonObj(){};
	
	void set_testProperty(int p_testProperty);
	int get_testProperty() { return testProperty; };

	void TestBindMethod();

protected:
	_File jsonFile;
	JSONParseResult *hierarchyRef;

	void openJsonFile(String filePath);
	void closeJsonFile();
	static void _bind_methods();
};
