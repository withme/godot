#include "custom_rig.h"

CustomRig::CustomRig()
{

}

CustomRig::~CustomRig()
{

}

void CustomRig::TestBindMethod()
{
	print_line("TestBindMethod successfully called! \n This is good news!");
}

void CustomRig::set_testProperty(int p_testProperty)
{
	if (testProperty == p_testProperty)
		return;

	testProperty = p_testProperty;
	_change_notify("testProperty");
}

Spatial *CustomRig::CreateCtrlNode(Transform initTransform)
{
	Spatial *tempPtr = nullptr;
	return tempPtr;
}

void CustomRig::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("TestBindMethod"), &CustomRig::TestBindMethod);
	ClassDB::bind_method(D_METHOD("set_testProperty"), &CustomRig::set_testProperty);
	ClassDB::bind_method(D_METHOD("get_testProperty"), &CustomRig::get_testProperty);

	//ADD_GROUP("Custom Properties", "");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "TestProperty", PROPERTY_HINT_RANGE, "1,16384,1"), "set_testProperty", "get_testProperty");
}
