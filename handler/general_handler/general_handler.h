/*
 * =====================================================================================
 *
 *       Filename:  general_handler.h
 *
 *    Description:  implement the general handler
 *
 *        Version:  1.0
 *        Created:  2015年06月30日 11时11分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liujun (qihoo inc.), liujun-xy@360.cn
 *        Company:  qihoo inc.
 *
 * =====================================================================================
 */

#ifndef __NGX_GENERAL_HANDLER__
#define __NGX_GENERAL_HANDLER__

#include "handler.h"

class GeneralHandler:public Handler
{
	public:
	bool InitHandler(std::string &args);

	std::vector<Request>  LanuchRequest(std::map<std::string,std::string> &params);

	InvokeResult  HandleResponse(std::vector<Response> &resp);
};

#endif
