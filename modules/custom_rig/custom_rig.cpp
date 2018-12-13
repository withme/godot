#include "custom_rig.h"
#include "custom_rig_json.h"

#include "scene/gui/file_dialog.h"

CustomRig::CustomRig() {
}

CustomRig::~CustomRig() {
}

//void CustomRig::set_customRigJson(Ref<CustomRigJson> p_customRigJson) {
//	if (customRigJson == p_customRigJson)
//		return;
//
//	if (customRigJson.is_valid())
//		customRigJson->remove_change_receptor(this);
//
//	customRigJson = p_customRigJson;
//
//	if (customRigJson.is_valid())
//		customRigJson->add_change_receptor(this);
//		
//	emit_signal("customRigJson_changed");
//	_change_notify("customRigJson");
//}

//Attempts to open and parse the json file
void CustomRig::set_jsonFilePath(String p_jsonFilePath) {
	//OpenFileDialog();
	if (p_jsonFilePath == jsonFilePath)
		return;

	jsonFilePath = p_jsonFilePath;
	Error err = parseJsonFile(jsonFilePath, jsonDict);
	if (err != Error::OK) {
		print_error("Error parsing json file.");
		return;
	} else {
		String tempJsonStr = JSON::print(jsonVar);
		print_line("Json file parsed.");
		//print_line(tempJsonStr);
	}
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

Error CustomRig::parseJsonFile(String filePath, Dictionary &jsonDict) {
	Error err = jsonFile.open(filePath, FileAccess::ModeFlags::READ);
	if (err != Error::OK) {
		//print_error("Error attemping to open file, please double check file path.");
		return err;
	}

	String jsonStrObj;
	while (!jsonFile.eof_reached()) {
		jsonStrObj += jsonFile.get_line();
	}

	//Variant jsonVar;
	String errorStr;
	int errorLn = -1;

	err = JSON::parse(jsonStrObj, jsonVar, errorStr, errorLn);
	jsonDict = Dictionary(jsonVar);

	return err;
}

void CustomRig::closeJsonFile() {
	jsonFile.close();
}

void CustomRig::_bind_methods() {
	//ClassDB::bind_method(D_METHOD("set_customRigJson"), &CustomRig::set_customRigJson);
	//ClassDB::bind_method(D_METHOD("get_customRigJson"), &CustomRig::get_customRigJson);
	ClassDB::bind_method(D_METHOD("set_jsonFilePath"), &CustomRig::set_jsonFilePath);
	ClassDB::bind_method(D_METHOD("get_jsonFilePath"), &CustomRig::get_jsonFilePath);
	ClassDB::bind_method(D_METHOD("get_jsonDictionary"), &CustomRig::get_jsonDictionary);

	//ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "JsonRigObject", PROPERTY_HINT_RESOURCE_TYPE, "CustomRigJson"), "set_customRigJson", "get_customRigJson");
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "jsonFilePath"), "set_jsonFilePath", "get_jsonFilePath");
	//ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY, "jsonDict"), "set_jsonDict", "get_jsonDict");
}
