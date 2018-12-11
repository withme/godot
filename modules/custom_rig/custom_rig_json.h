#pragma once

#ifndef CUSTOMRIGJSON_H
#define CUSTOMRIGJSON_H
#endif // !CUSTOMRIGJSON_H

#include <vector>

//#include "core/reference.h"
//#include "core/object.h"
#include "core/resource.h"
#include "core/bind/core_bind.h"
#include "core/io/json.h"

class CustomRigJson : public Resource {
	GDCLASS(CustomRigJson, Resource);
	OBJ_SAVE_TYPE(CustomRigJson);
	RID jsonObj_RID;

public:
	CustomRigJson(){};
	~CustomRigJson(){};

	virtual RID get_rid() { return jsonObj_RID; };

	String OpenFileDialog();
	String jsonFilePath;

	void set_jsonFilePath(String p_jsonFilePath);
	String get_jsonFilePath() { return jsonFilePath; };

protected:	
	_File jsonFile;
	Variant jsonVar;
	Dictionary jsonDict;
	//JSONParseResult *hierarchyRef;

	Error parseJsonFile(String filePath, Dictionary &josnDict);
	void closeJsonFile();
	static void _bind_methods();
};
