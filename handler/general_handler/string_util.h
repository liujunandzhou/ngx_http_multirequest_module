/*
 * =====================================================================================
 *
 *       Filename:  string_util.h
 *
 *    Description:  define the string_util interface
 *
 *        Version:  1.0
 *        Created:  2015年07月14日 14时26分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liujun (qihoo inc.), liujun-xy@360.cn
 *        Company:  qihoo inc.
 *
 * =====================================================================================
 */

#ifndef __SPIDER_STRING_UTIL__
#define __SPIDER_STRING_UTIL__

#include<string>
#include<sstream>

namespace string_util
{
	template<typename out_type,typename in_value>
		out_type convert(const in_value &t) 
		{
			std::stringstream stream;
			stream<<t;

			out_type result;
			stream>>result;

			return result;
		}
};

#endif
