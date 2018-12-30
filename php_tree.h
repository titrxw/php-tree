
#ifndef PHP_TREE_H
#define PHP_TREE_H

extern zend_module_entry tree_module_entry;
#define phpext_tree_ptr &tree_module_entry

#define PHP_TREE_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_TREE_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_TREE_API __attribute__ ((visibility("default")))
#else
#	define PHP_TREE_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/*
  	Declare any global variables you may need between the BEGIN
	and END macros here:

ZEND_BEGIN_MODULE_GLOBALS(tree)
	zend_long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(tree)
*/

/* Always refer to the globals in your function as TREE_G(variable).
   You are encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/
#define TREE_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(tree, v)

#if defined(ZTS) && defined(COMPILE_DL_TREE)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif	/* PHP_TREE_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
