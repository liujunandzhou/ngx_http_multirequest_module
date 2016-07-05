/*
 * =====================================================================================
 *
 *       Filename:  module_loader.h
 *
 *    Description:  define the module loader interface
 *
 *        Version:  1.0
 *        Created:  2015年06月30日 11时59分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liujun (qihoo inc.), liujun-xy@360.cn
 *        Company:  qihoo inc.
 *
 * =====================================================================================
 */

#ifndef __MODULE_LOADER_H__
#define __MODULE_LOADER_H__

#include <string>
#include <boost/shared_ptr.hpp>

class Handler;

typedef Handler* (*CreateModuleFn)();
typedef void (*DestroyModuleFn)(Handler*);

class ModuleLoader
{
	public:
		ModuleLoader(std::string &module_name,std::string &module_path,std::string &module_args)
		{
			this->module_name=module_name;
			this->module_path=module_path;
			this->module_args=module_args;
			this->dh_=NULL;
			this->create_module_=NULL;
			this->destroy_module_=NULL;
		}
		
		~ModuleLoader();

		bool InitModule();

		boost::shared_ptr<Handler> &GetHandler();

	private:
		boost::shared_ptr<Handler> Load(const std::string& path);


	private:

		std::string module_name;
		std::string module_path;
		std::string module_args;

	    boost::shared_ptr<Handler> handler;

		void* dh_;

		CreateModuleFn create_module_;
		DestroyModuleFn destroy_module_;
};

#endif
