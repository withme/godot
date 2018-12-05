#include "json_obj.h"

//JsonObj::JsonObj() {
//
//}
//
//JsonObj::~JsonObj() {
//
//}

void JsonObj::TestBindMethod() {
	print_line("TestBindMethod successfully called! \n This is good news!");
}

void JsonObj::set_testProperty(int p_testProperty) {
	if (testProperty == p_testProperty)
		return;

	testProperty = p_testProperty;
	_change_notify("testProperty");
}


void JsonObj::_bind_methods() {
	ClassDB::bind_method(D_METHOD("TestBindMethod"), &JsonObj::TestBindMethod);
	ClassDB::bind_method(D_METHOD("set_testProperty"), &JsonObj::set_testProperty);
	ClassDB::bind_method(D_METHOD("get_testProperty"), &JsonObj::get_testProperty);

	//ADD_GROUP("Custom Properties", "");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "TestProperty", PROPERTY_HINT_RANGE, "1,16384,1"), "set_testProperty", "get_testProperty");
}

void JsonObj::openJsonFile(String filePath)
{

}

void JsonObj::closeJsonFile()
{
	jsonFile.close();
}
