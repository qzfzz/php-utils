
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Utils_StringUt) {

	ZEPHIR_REGISTER_CLASS(Utils, StringUt, utils, stringut, utils_stringut_method_entry, 0);

	return SUCCESS;

}

/**
 *
 * StringUt::hasPrefix( string strHackstack, string strNeedle, boolean bIgnoreCase = false ) -> boolean
 *
 * @param string hackstack 
 * @param string needle
 * @param boolean bIgnoreCase = false
 *
 *  return boolean
 */
PHP_METHOD(Utils_StringUt, hasPrefix) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool bIgnoreCase, _0;
	zval *hackstack_param = NULL, *needle_param = NULL, *bIgnoreCase_param = NULL, _1, _2;
	zval hackstack, needle;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&hackstack);
	ZVAL_UNDEF(&needle);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &hackstack_param, &needle_param, &bIgnoreCase_param);

	zephir_get_strval(&hackstack, hackstack_param);
	zephir_get_strval(&needle, needle_param);
	if (!bIgnoreCase_param) {
		bIgnoreCase = 0;
	} else {
		bIgnoreCase = zephir_get_boolval(bIgnoreCase_param);
	}


	_0 = ZEPHIR_IS_STRING(&hackstack, "");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING(&needle, "");
	}
	if (unlikely(_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_1);
	if (bIgnoreCase) {
		ZVAL_LONG(&_2, 0);
		ZEPHIR_CALL_FUNCTION(&_1, "stripos", NULL, 1, &hackstack, &needle, &_2);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		zephir_fast_strpos(&_1, &hackstack, &needle, 0 );
	}
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 *
 * StringUt::hasSuffix( string strHackstack, string strNeedle, boolean bIgnoreCase = false ) -> boolean
 *
 * @param string hackstack 
 * @param string needle
 * @param boolean bIgnoreCase = false
 *
 *  return boolean
 */
PHP_METHOD(Utils_StringUt, hasSuffix) {

	int ZEPHIR_LAST_CALL_STATUS, iHSLen, iStart;
	zend_bool bIgnoreCase, _0, _1;
	zval *strHackstack_param = NULL, *strNeedle_param = NULL, *bIgnoreCase_param = NULL, _2, _3;
	zval strHackstack, strNeedle;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&strHackstack);
	ZVAL_UNDEF(&strNeedle);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &strHackstack_param, &strNeedle_param, &bIgnoreCase_param);

	zephir_get_strval(&strHackstack, strHackstack_param);
	zephir_get_strval(&strNeedle, strNeedle_param);
	if (!bIgnoreCase_param) {
		bIgnoreCase = 0;
	} else {
		bIgnoreCase = zephir_get_boolval(bIgnoreCase_param);
	}


	_0 = ZEPHIR_IS_STRING(&strHackstack, "");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING(&strNeedle, "");
	}
	if (unlikely(_0)) {
		RETURN_MM_BOOL(0);
	}
	iHSLen = zephir_fast_strlen_ev(&strHackstack);
	iStart = (iHSLen - zephir_fast_strlen_ev(&strNeedle));
	_1 = iStart > iHSLen;
	if (!(_1)) {
		_1 = iStart < 0;
	}
	if (_1) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_2);
	if (bIgnoreCase) {
		ZVAL_LONG(&_3, iStart);
		ZEPHIR_CALL_FUNCTION(&_2, "stripos", NULL, 1, &strHackstack, &strNeedle, &_3);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_3, iStart);
		ZEPHIR_INIT_NVAR(&_2);
		zephir_fast_strpos(&_2, &strHackstack, &strNeedle, zephir_get_intval(&_3) );
	}
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_2)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 *
 * StringUt::contains( string strHackstack, string strNeedle, boolean bIgnoreCase = false ) -> boolean
 *
 * @param string hackstack 
 * @param string needle
 * @param boolean bIgnoreCase = false
 *
 *  return boolean
 */
PHP_METHOD(Utils_StringUt, contains) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool bIgnoreCase, _0;
	zval *strHackstack_param = NULL, *strNeedle_param = NULL, *bIgnoreCase_param = NULL, _1;
	zval strHackstack, strNeedle;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&strHackstack);
	ZVAL_UNDEF(&strNeedle);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &strHackstack_param, &strNeedle_param, &bIgnoreCase_param);

	zephir_get_strval(&strHackstack, strHackstack_param);
	zephir_get_strval(&strNeedle, strNeedle_param);
	if (!bIgnoreCase_param) {
		bIgnoreCase = 0;
	} else {
		bIgnoreCase = zephir_get_boolval(bIgnoreCase_param);
	}


	_0 = ZEPHIR_IS_STRING(&strHackstack, "");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING(&strNeedle, "");
	}
	if (unlikely(_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_1);
	if (bIgnoreCase) {
		ZEPHIR_CALL_FUNCTION(&_1, "stripos", NULL, 1, &strHackstack, &strNeedle);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		zephir_fast_strpos(&_1, &strHackstack, &strNeedle, 0 );
	}
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

