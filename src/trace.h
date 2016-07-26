#ifndef GWERS_TRACE_H
#define GWERS_TRACE_H
#include <string>
#include <vector>
#include <sstream>
#ifdef DEBUG
#define TRACE(F,...) \
   ::Effro::Trace effro__track__trace(F,##__VA_ARGS__);
#else
#define TRACE(F,...)
#endif
namespace Effro {



class Trace
{
public:
   using string = std::string;
   using Iterator = std::vector<string>::iterator;
   Trace(const string& fdesc);
   template<class... Args> Trace(const string& fdesc,Args... args);
   ~Trace();
   static void lock();
   static void flush();
   static const Iterator begin();
   static const Iterator end();
private:
   using ostr = std::ostringstream;
   using list = std::vector<string>;
   template<class T> static void build(ostr& str, T val);
   template<class T, class... Args> static void build(ostr& str,T val, Args... args);
   thread_local static list _stack;
   thread_local static bool _lock;
};



template<class... Args> Trace::Trace(const string& fdesc, Args... args)
{
   ostr odesc;
   odesc << fdesc;
   build(odesc,args...);
   _stack.emplace_back(odesc.str());
}



template<class T> inline void Trace::build(ostr& str, T val)
{
   str << "[" << val << "]";
}



template<class T, class... Args> void Trace::build(ostr& str, T val, Args... args)
{
   str << "[" << val << "],";
   build(str,args...);
}



}
#endif
