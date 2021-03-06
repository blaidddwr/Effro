#include "exception.h"
namespace Effro {



Exception::Exception(const String& domain, const String& what, int line):
   _domain(domain),
   _what(what),
   _line(line)
{
   Trace::lock();
}



const Exception::String& Exception::domain() const
{
   return _domain;
}



const Exception::String& Exception::what() const
{
   return _what;
}



const Exception::String& Exception::detail() const
{
   return _detail;
}



int Exception::line() const
{
   return _line;
}



Exception& Exception::operator<<(short n)
{
   _detail += std::to_string(n);
   return *this;
}



Exception& Exception::operator<<(unsigned short n)
{
   _detail += std::to_string(n);
   return *this;
}



Exception& Exception::operator<<(int n)
{
   _detail += std::to_string(n);
   return *this;
}



Exception& Exception::operator<<(unsigned int n)
{
   _detail += std::to_string(n);
   return *this;
}



Exception& Exception::operator<<(long n)
{
   _detail += std::to_string(n);
   return *this;
}



Exception& Exception::operator<<(unsigned long n)
{
   _detail += std::to_string(n);
   return *this;
}



Exception& Exception::operator<<(long long n)
{
   _detail += std::to_string(n);
   return *this;
}



Exception& Exception::operator<<(unsigned long long n)
{
   _detail += std::to_string(n);
   return *this;
}



Exception& Exception::operator<<(float n)
{
   _detail += std::to_string(n);
   return *this;
}



Exception& Exception::operator<<(double n)
{
   _detail += std::to_string(n);
   return *this;
}



Exception& Exception::operator<<(const char* n)
{
   _detail += n;
   return *this;
}



Exception& Exception::operator<<(const String& n)
{
   _detail += n;
   return *this;
}



}
