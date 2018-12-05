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

class CustomRig : public Node {
	GDCLASS(CustomRig, Node);

public:
	std::vector<Spatial *> controllerList;
	int testProperty = 0;

	CustomRig();
	~CustomRig();

	//UI draw related
	void set_testProperty(int p_testProperty);
	int get_testProperty() { return testProperty; };

	void TestBindMethod();

protected:
	JSONParseResult *hierarchyRef;

	Spatial *CreateCtrlNode(Transform initTransform);

	static void _bind_methods();
};
