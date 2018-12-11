#include "register_types.h"
#include "core/class_db.h"

#include "custom_rig.h"
#include "custom_rig_json.h"

void register_custom_rig_types()
{
  ClassDB::register_class<CustomRig>();
  ClassDB::register_class<CustomRigJson>();
}

void unregister_custom_rig_types() {}
