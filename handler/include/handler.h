/*
 * =====================================================================================
 *
 *       Filename:  handler.h
 *
 *    Description:  define the handler interface
 *
 *        Version:  1.0
 *        Created:  2015年06月30日 10时45分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liujun (qihoo inc.), liujun-xy@360.cn
 *        Company:  qihoo inc.
 *
 * =====================================================================================
 */
#ifndef __MULTIREQUEST_HANDLER_H__
#define __MULTIREQUEST_HANDLER_H__

#include<string>
#include<vector>
#include<map>

#define EXPORT_MODULE(m) \
	extern "C" void *CreateModuleInstance() { \
		    return new m(); \
	} \
	extern "C" void DestroyModuleInstance(void *ptr) { \
	    m *p = (m*)ptr; \
	    delete p; \
} // EXPORT_MODULE()


typedef struct{
	std::string res_type; //response_type
	std::string response; //response
}InvokeResult;

//定义了查询参数
typedef struct{
	std::string url;
	std::string args;
	void *data;
}Request;

//定义返回结果
typedef struct{
	std::string body;
	void *data;
}Response;

//定义一个抽象处理器
class Handler
{

public:
	virtual ~Handler(){}

	//初始化handler,允许带一个参数,这个参数一般推荐是配置文件
	virtual bool InitHandler(std::string &args)=0;

	//返回一系列子查询
	virtual std::vector<Request>  LanuchRequest(std::map<std::string,std::string> &params)=0;

	//返回处理后的最终结果
	virtual InvokeResult  HandleResponse(std::vector<Response> &resp)=0;
};

#endif
