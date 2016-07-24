#include "trace.h"
namespace eff {



thread_local Trace::list Trace::_stack {};
thread_local bool Trace::_lock {false};



Trace::Trace(const string& fdesc)
{
   _stack.emplace_back(fdesc);
}



Trace::~Trace()
{
   if (!_lock&&!_stack.empty())
   {
      _stack.pop_back();
   }
}



void Trace::lock()
{
   _lock = true;
}



void Trace::flush()
{
   _stack.clear();
   _lock = false;
}



const Trace::Iterator Trace::begin()
{
   return _stack.begin();
}



const Trace::Iterator Trace::end()
{
   return _stack.end();
}



}
