
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_php-tree.h"

/* If you declare any globals in php_php-tree.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(php-tree)
*/

/* True global resources - no need for thread safety here */
static int le_php-tree;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("php-tree.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_php-tree_globals, php-tree_globals)
    STD_PHP_INI_ENTRY("php-tree.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_php-tree_globals, php-tree_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_php-tree_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_php-tree_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "php-tree", arg);

	RETURN_STR(strg);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_php-tree_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_php-tree_init_globals(zend_php-tree_globals *php-tree_globals)
{
	php-tree_globals->global_value = 0;
	php-tree_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(php-tree)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(php-tree)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(php-tree)
{
#if defined(COMPILE_DL_PHP-TREE) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(php-tree)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(php-tree)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "php-tree support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ php-tree_functions[]
 *
 * Every user visible function must have an entry in php-tree_functions[].
 */
const zend_function_entry php-tree_functions[] = {
	PHP_FE(confirm_php-tree_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in php-tree_functions[] */
};
/* }}} */

/* {{{ php-tree_module_entry
 */
zend_module_entry php-tree_module_entry = {
	STANDARD_MODULE_HEADER,
	"php-tree",
	php-tree_functions,
	PHP_MINIT(php-tree),
	PHP_MSHUTDOWN(php-tree),
	PHP_RINIT(php-tree),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(php-tree),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(php-tree),
	PHP_PHP-TREE_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PHP-TREE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(php-tree)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */