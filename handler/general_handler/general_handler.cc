/*
 * =====================================================================================
 *
 *       Filename:  general_handler.cc
 *
 *    Description:  implement the general_handler
 *
 *        Version:  1.0
 *        Created:  2015年06月30日 11时16分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liujun (qihoo inc.), liujun-xy@360.cn
 *        Company:  qihoo inc.
 *
 * =====================================================================================
 */

#include<iostream>
#include<stdint.h>

#include"general_handler.h"
#include"string_util.h"

bool GeneralHandler::InitHandler(std::string &args)
{
	return true;
}

//这里面可以实现非常复杂的处理逻辑来发起子请求
std::vector<Request> GeneralHandler::LanuchRequest(std::map<std::string,std::string> &params)
{
	std::vector<Request> vec;

	Request req;
	req.url="/subrequest1";
	req.args="";
	req.data=(void*)1;

	vec.push_back(req);

	req.url="/subrequest2";
	req.args="";
	req.data=(void*)2;

	vec.push_back(req);

	return vec;
}

InvokeResult  GeneralHandler::HandleResponse(std::vector<Response> &resp)
{
	InvokeResult ir;
	ir.res_type="text/html";
	ir.response="GeneralHandler:";

	int resp_size=resp.size();

	for(int i=0;i<resp_size;i++){
		Response &rsp=resp[i];
		uint64_t tag=(uint64_t)rsp.data;

		ir.response+="<"+string_util::convert<std::string>(tag)+":"+rsp.body+">";
	}

	return ir;
}

EXPORT_MODULE(GeneralHandler)
