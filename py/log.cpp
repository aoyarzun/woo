#include<string>
#include<woo/lib/base/Logging.hpp>
#include<woo/lib/base/Types.hpp>
#include<woo/lib/pyutil/doc_opts.hpp>
#include<woo/core/Master.hpp>
enum{ll_TRACE,ll_DEBUG,ll_INFO,ll_WARN,ll_ERROR,ll_FATAL};

#ifdef WOO_SPDLOG
	static std::shared_ptr<spdlog::logger> logger=spdlog::stdout_color_mt("woo.log");
	void logSetLevel(std::string loggerName, int level){
		// std::string fullName(loggerName.empty()?"woo":("woo."+loggerName));
		spdlog::level::level_enum newLevel;
		switch(level){
				case ll_TRACE: newLevel=spdlog::level::level_enum::trace; break;
				case ll_DEBUG: newLevel=spdlog::level::level_enum::debug; break;
				case ll_INFO:  newLevel=spdlog::level::level_enum::info; break;
				case ll_WARN:  newLevel=spdlog::level::level_enum::warn; break;
				case ll_ERROR: newLevel=spdlog::level::level_enum::err; break;
				case ll_FATAL: newLevel=spdlog::level::level_enum::critical; break;
			default: throw std::invalid_argument("Unrecognized logging level "+lexical_cast<std::string>(level));
		}
		std::shared_ptr<spdlog::logger> log;
		// apply to all loggers (TODO: match wildcard)
		if(loggerName.empty()){
			spdlog::apply_all([&](std::shared_ptr<spdlog::logger> l){
				l->set_level(newLevel);
			});
		} else {
			log=spdlog::get(loggerName);
			if(!log){ LOG_WARN("No logger named '{}', ignoring level setting.",loggerName); return; }
			log->set_level(newLevel);
		}
	}
	// void logLoadConfig(std::string f){ log4cxx::PropertyConfigurator::configure(f); }
	void logLoadConfig(std::string f){ throw std::runtime_error("logLoadConfig: not supported with spdlog."); }
#elif defined(WOO_LOG4CXX)
	static log4cxx::LoggerPtr logger=log4cxx::Logger::getLogger("woo.log");
	#include<log4cxx/logmanager.h>
	void logSetLevel(std::string loggerName,int level){
		std::string fullName(loggerName.empty()?"woo":("woo."+loggerName));
		if(!log4cxx::LogManager::exists(fullName)){
			LOG_WARN("No logger named {}, ignoring level setting.",loggerName);			
			// throw std::invalid_argument("No logger named `"+fullName+"'");
		} 
		log4cxx::LevelPtr l;
		switch(level){
			#ifdef LOG4CXX_TRACE
				case ll_TRACE: l=log4cxx::Level::getTrace(); break;
				case ll_DEBUG: l=log4cxx::Level::getDebug(); break;
				case ll_INFO:  l=log4cxx::Level::getInfo(); break;
				case ll_WARN:  l=log4cxx::Level::getWarn(); break;
				case ll_ERROR: l=log4cxx::Level::getError(); break;
				case ll_FATAL: l=log4cxx::Level::getFatal(); break;
			#else
				case ll_TRACE: l=log4cxx::Level::DEBUG; break;
				case ll_DEBUG: l=log4cxx::Level::DEBUG; break;
				case ll_INFO:  l=log4cxx::Level::INFO; break;
				case ll_WARN:  l=log4cxx::Level::WARN; break;
				case ll_ERROR: l=log4cxx::Level::ERROR; break;
				case ll_FATAL: l=log4cxx::Level::FATAL; break;
			#endif
			default: throw std::invalid_argument("Unrecognized logging level "+lexical_cast<std::string>(level));
		}
		log4cxx::LogManager::getLogger("woo."+loggerName)->setLevel(l);
	}
	void logLoadConfig(std::string f){ log4cxx::PropertyConfigurator::configure(f); }
#else
	bool warnedOnce=false;
	void logSetLevel(std::string loggerName, int level){
		// better somehow python's raise RuntimeWarning, but not sure how to do that from c++
		// it shouldn't be trapped by boost::python's exception translator, just print warning
		// Do like this for now.
		if(warnedOnce) return;
		LOG_WARN("Woo was compiled without log4cxx support. Setting log levels from python will have no effect (warn once).");
		warnedOnce=true;
	}
	void logLoadConfig(std::string f){
		if(warnedOnce) return;
		LOG_WARN("Woo was compiled without log4cxx support. Loading log file will have no effect (warn once).");
		warnedOnce=true;
	}
#endif

WOO_PYTHON_MODULE(log);
#ifdef WOO_PYBIND11
PYBIND11_MODULE(log,mod){
	mod.doc() = "Access and manipulation of log4cxx loggers.";
	WOO_SET_DOCSTRING_OPTS;

	mod.def("setLevel",logSetLevel,WOO_PY_ARGS(py::arg("logger"),py::arg("level")),"Set minimum severity *level* (constants ``TRACE``, ``DEBUG``, ``INFO``, ``WARN``, ``ERROR``, ``FATAL``) for given logger. \nLeading 'woo.' will be appended automatically to the logger name; if logger is '', the root logger 'woo' will be operated on.");
	mod.def("loadConfig",logLoadConfig,WOO_PY_ARGS(py::arg("fileName")),"Load configuration from file (log4cxx::PropertyConfigurator::configure)");
	mod.attr("TRACE")=(int)ll_TRACE;
	mod.attr("DEBUG")=(int)ll_DEBUG;
	mod.attr("INFO")= (int)ll_INFO;
	mod.attr("WARN")= (int)ll_WARN;
	mod.attr("ERROR")=(int)ll_ERROR;
	mod.attr("FATAL")=(int)ll_FATAL;
}
#else
BOOST_PYTHON_MODULE(log){
	py::scope().attr("__doc__") = "Access and manipulation of log4cxx loggers.";

	WOO_SET_DOCSTRING_OPTS;

	py::def("setLevel",logSetLevel,WOO_PY_ARGS(py::arg("logger"),py::arg("level")),"Set minimum severity *level* (constants ``TRACE``, ``DEBUG``, ``INFO``, ``WARN``, ``ERROR``, ``FATAL``) for given logger. \nLeading 'woo.' will be appended automatically to the logger name; if logger is '', the root logger 'woo' will be operated on.");
	py::def("loadConfig",logLoadConfig,WOO_PY_ARGS(py::arg("fileName")),"Load configuration from file (log4cxx::PropertyConfigurator::configure)");
	py::scope().attr("TRACE")=(int)ll_TRACE;
	py::scope().attr("DEBUG")=(int)ll_DEBUG;
	py::scope().attr("INFO")= (int)ll_INFO;
	py::scope().attr("WARN")= (int)ll_WARN;
	py::scope().attr("ERROR")=(int)ll_ERROR;
	py::scope().attr("FATAL")=(int)ll_FATAL;
}
#endif
