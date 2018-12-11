#include "custom_rig.h"
#include "custom_rig_json.h"

#include "scene/gui/file_dialog.h"

CustomRig::CustomRig() {
}

CustomRig::~CustomRig() {
}

void CustomRig::set_customRigJson(Ref<CustomRigJson> p_customRigJson) {
	if (customRigJson == p_customRigJson)
		return;

	if (customRigJson.is_valid())
		customRigJson->remove_change_receptor(this);

	customRigJson = p_customRigJson;

	if (customRigJson.is_valid())
		customRigJson->add_change_receptor(this);
		
	emit_signal("customRigJson_changed");
	_change_notify("customRigJson");
}

//String CustomRig::OpenJsonFile() {
//	FileDialog *newFDialog = new FileDialog();
//	//newFDialog->set_mode(FileDialog::MODE_OPEN_FILE);
//	//newFDialog->set_access(FileDialog::ACCESS_FILESYSTEM);
//	//newFDialog->connect("file_selected", this, "set_jsonFilePath");
//	newFDialog->set_visible(true);
//	//add_child(newFDialog);
//
//	return newFDialog->get_current_file();
//}
//
//void CustomRig::TestBindMethod() {
//	print_line("TestBindMethod successfully called! \n This is good news!");
//}
//
//void CustomRig::set_testProperty(int p_testProperty) {
//	OpenJsonFile();
//
//	if (testProperty == p_testProperty)
//		return;
//
//	testProperty = p_testProperty;
//	_change_notify("testProperty");
//}

Spatial *CustomRig::CreateCtrlNode(Transform initTransform) {
	Spatial *tempPtr = nullptr;
	return tempPtr;
}

void CustomRig::_bind_methods() {
	//ClassDB::bind_method(D_METHOD("TestBindMethod"), &CustomRig::TestBindMethod);
	//ClassDB::bind_method(D_METHOD("set_testProperty"), &CustomRig::set_testProperty);
	//ClassDB::bind_method(D_METHOD("get_testProperty"), &CustomRig::get_testProperty);
	ClassDB::bind_method(D_METHOD("set_customRigJson"), &CustomRig::set_customRigJson);
	ClassDB::bind_method(D_METHOD("get_customRigJson"), &CustomRig::get_customRigJson);

	//ADD_GROUP("Custom Properties", "");
	//ADD_PROPERTY(PropertyInfo(Variant::INT, "TestProperty", PROPERTY_HINT_RANGE, "1,16384,1"), "set_testProperty", "get_testProperty");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "JsonRigObject", PROPERTY_HINT_RESOURCE_TYPE, "CustomRigJson"), "set_customRigJson", "get_customRigJson");
}
