#include <gcc-plugin.h>
#include <cp/cp-tree.h>

int plugin_is_GPL_compatible = 1;

static void fn(void *gcc_data, void *user_data)
{
	TYPE_ADDR_SPACE (TREE_TYPE (vtbl_type_node)) = 1;
	TYPE_ADDR_SPACE (TREE_TYPE (vtbl_ptr_type_node)) = 1;
}

int plugin_init (struct plugin_name_args *plugin_info,
		 struct plugin_gcc_version *version)
{
	register_callback("", PLUGIN_START_UNIT, fn, NULL);
	return 0;
}
