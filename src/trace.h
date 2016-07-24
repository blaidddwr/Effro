#ifndef GWERS_TRACE_H
#define GWERS_TRACE_H
#include <string>
#include <vector>
#include <sstream>
#ifdef TRACE
#ifndef DEBUG
#error Cannot have TRACE enabled without DEBUG being enabled!
#endif
#define EFF_TRACE(F,...) \
   std::ostringstream EFF__tmp__string;\
   EFF__tmp__string << F;\
   ::eff::Trace::build(EFF__tmp__string,##__VA_ARGS__);\
   ::eff::Trace x_trace(EFF__tmp__string.str());
#else
#define EFF_TRACE(F,...)
#endif
namespace eff {



class Trace
{
public:
   using string = std::string;
   using ostr = std::ostringstream;
   using Iterator = std::vector<string>::iterator;
   Trace(const string& fdesc);
   ~Trace();
   static void lock();
   static void flush();
   static const Iterator begin();
   static const Iterator end();
   static void build(ostr&) {}
   template<class T> static void build(ostr& str, T val);
   template<class T, class... Args> static void build(ostr& str,T val, Args... args);
private:
   using list = std::vector<string>;
   thread_local static list _stack;
   thread_local static bool _lock;
};



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
