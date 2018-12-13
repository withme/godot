#pragma once

#ifndef CUSTOMRIG_H
#define CUSTOMRIG_H
#endif // !CUSTOMRIG_H

#include <vector>

//#include "core/reference.h"
#include "scene/3d/spatial.h"
#include "scene/main/node.h"
//#include "core/io/json.h"
#include "core/bind/core_bind.h"

/*
# Node creation - Load and parse json file
# Parsed json result - Create spatial node hierarchy based on json
# Spatial hierarchy - Bind spatial node transform to custom_bone_pose based on json constraint information
*/

//class CustomRigJson;

class CustomRig : public Node {
	GDCLASS(CustomRig, Node);

public:
	//Ref<CustomRigJson> customRigJson;
	String jsonFilePath;

	void set_jsonFilePath(String p_jsonFilePath);
	String get_jsonFilePath() { return jsonFilePath; };

	Dictionary get_jsonDictionary() { return jsonDict; };

	CustomRig();
	~CustomRig();

	//void set_customRigJson(Ref<CustomRigJson> p_customRigJson);
	//Ref<CustomRigJson> get_customRigJson() { return customRigJson; };

	//void generateNodeTreeFromJson(Dictionary jsonDict);

	Spatial tempPtr;

protected:
	_File jsonFile;
	Variant jsonVar;
	Dictionary jsonDict;

	Spatial *CreateCtrlNode(Transform initTransform);

	Error parseJsonFile(String filePath, Dictionary &josnDict);
	void closeJsonFile();

	static void _bind_methods();
};
