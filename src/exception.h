#ifndef GWERS_EXCEPTION_HH
#define GWERS_EXCEPTION_HH
#include <string>
#include "trace.h"
#ifdef DEBUG
#define EFF_DECLARE(N) \
   static inline const char* EFFRO__get__who() { return #N; }
#define EFF_EXCEPTION(X) \
   struct X : public ::Effro::Exception\
   {\
      X(int l):\
         ::Effro::Exception(EFFRO__get__who(),#X,l)\
      {}\
   };
#define EFF_ASSERT(T,X,L) \
   ::Effro::Exception::assert<X>(T,L);
#define EFF_CHECK(T,X,L) \
   ::Effro::Exception::assert<X>(T,L);
#define EFF_PASS(T,F,X,L) \
   ::Effro::Exception::assert<X>(T F,L);
#define EFF_TRY(S,X,L) \
   try { S; } catch(...) { throw X(L); }
#else
#define EFF_DECLARE(N)
#define EFF_EXCEPTION(X)
#define EFF_ASSERT(T,X,L)
#define EFF_CHECK(T,X,L) T;
#define EFF_PASS(T,F,X,L) F;
#define EFF_TRY(S,X,L) S;
#endif
namespace Effro {



class Exception
{
public:
   using string = std::string;
   Exception(const string& domain, const string& what, int line);
   const string& domain() const;
   const string& what() const;
   const string& detail() const;
   int line() const;
   template<class X> static void assert(bool cond, int line);
   Exception& operator<<(short);
   Exception& operator<<(unsigned short);
   Exception& operator<<(int);
   Exception& operator<<(unsigned int);
   Exception& operator<<(long);
   Exception& operator<<(unsigned long);
   Exception& operator<<(long long);
   Exception& operator<<(unsigned long long);
   Exception& operator<<(float);
   Exception& operator<<(double);
   Exception& operator<<(const char*);
   Exception& operator<<(const string&);
private:
   string _domain;
   string _what;
   string _detail;
   int _line;
};



template<class X> void Exception::assert(bool cond, int line)
{
   if (!cond)
   {
      throw X(line);
   }
}



}
#endif
