
extern zend_class_entry *utils_stringut_ce;

ZEPHIR_INIT_CLASS(Utils_StringUt);

PHP_METHOD(Utils_StringUt, hasPrefix);
PHP_METHOD(Utils_StringUt, hasSuffix);
PHP_METHOD(Utils_StringUt, contains);

ZEND_BEGIN_ARG_INFO_EX(arginfo_utils_stringut_hasprefix, 0, 0, 2)
	ZEND_ARG_INFO(0, hackstack)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_INFO(0, bIgnoreCase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_utils_stringut_hassuffix, 0, 0, 2)
	ZEND_ARG_INFO(0, strHackstack)
	ZEND_ARG_INFO(0, strNeedle)
	ZEND_ARG_INFO(0, bIgnoreCase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_utils_stringut_contains, 0, 0, 2)
	ZEND_ARG_INFO(0, strHackstack)
	ZEND_ARG_INFO(0, strNeedle)
	ZEND_ARG_INFO(0, bIgnoreCase)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(utils_stringut_method_entry) {
	PHP_ME(Utils_StringUt, hasPrefix, arginfo_utils_stringut_hasprefix, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Utils_StringUt, hasSuffix, arginfo_utils_stringut_hassuffix, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Utils_StringUt, contains, arginfo_utils_stringut_contains, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
