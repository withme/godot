#include "custom_rig_json.h"

#include "core/io/json.h"
#include "editor/editor_file_dialog.h"
#include "scene/gui/base_button.h"
#include "scene/gui/file_dialog.h"

//JsonObj::JsonObj() {
//
//}
//
//JsonObj::~JsonObj() {
//
//}

String CustomRigJson::OpenFileDialog() {
	//FileDialog *newFDialog = memnew(FileDialog);
	//newFDialog->set_mode(FileDialog::MODE_OPEN_FILE);
	//newFDialog->connect("file_selected", this, "set_jsonFilePath");
	//newFDialog->set_access(FileDialog::ACCESS_FILESYSTEM);

	//return newFDialog->get_current_file();

	EditorFileDialog *FileDialogPtr = memnew(EditorFileDialog);
	FileDialogPtr->set_mode(EditorFileDialog::MODE_OPEN_FILE);
	FileDialogPtr->set_title("Open Json File");
	FileDialogPtr->popup_centered_ratio();

	return FileDialogPtr->get_current_file();
}

//Attempts to open and parse the json file
void CustomRigJson::set_jsonFilePath(String p_jsonFilePath) {
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
		print_line(tempJsonStr);
	}
}

void CustomRigJson::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_jsonFilePath"), &CustomRigJson::set_jsonFilePath);
	ClassDB::bind_method(D_METHOD("get_jsonFilePath"), &CustomRigJson::get_jsonFilePath);

	ADD_PROPERTY(PropertyInfo(Variant::STRING, "jsonFilePath"), "set_jsonFilePath", "get_jsonFilePath");
	//ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "browseButton"), )
}

Error CustomRigJson::parseJsonFile(String filePath, Dictionary &jsonDict) {
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

void CustomRigJson::closeJsonFile() {
	jsonFile.close();
}
