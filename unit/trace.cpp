#define DEBUG
#include "../src/trace.h"
#include "trace.h"
#include "ndtrace.h"



using namespace Effro;
using std::string;



void bar(const char* a, float b)
{
   TRACE(__PRETTY_FUNCTION__,a,b);
   Trace::lock();
}



void foo(int a, int b)
{
   TRACE(__PRETTY_FUNCTION__,a,b);
   bar("test",3.14);
}



void boo(int a, int b)
{
   TRACE(__PRETTY_FUNCTION__,a,b);
}



void coo(int a, int b)
{
   TRACE(__PRETTY_FUNCTION__,a,b);
   boo(5,6);
   Trace::lock();
}



void doo(int a, int b)
{
   TRACE(__PRETTY_FUNCTION__,a,b);
   coo(3,4);
}



void goo(int a, int b)
{
   TRACE(__PRETTY_FUNCTION__,a,b);
}



void testall(gwr::UTest::Run& rn)
{
   {
      foo(1,2);
      auto i = Trace::begin();
      if (*i!=string("void foo(int, int) [1], [2]"))
      {
         throw gwr::UTest::Run::Fail();
      }
      ++i;
      if (*i!=string("void bar(const char*, float) [test], [3.14]"))
      {
         throw gwr::UTest::Run::Fail();
      }
      ++i;
      if (i!=Trace::end())
      {
         throw gwr::UTest::Run::Fail();
      }
   }
   {
      rn.next();
      Trace::flush();
      foo(1,2);
      auto i = Trace::begin();
      if (*i!=string("void foo(int, int) [1], [2]"))
      {
         throw gwr::UTest::Run::Fail();
      }
      ++i;
      if (*i!=string("void bar(const char*, float) [test], [3.14]"))
      {
         throw gwr::UTest::Run::Fail();
      }
      ++i;
      if (i!=Trace::end())
      {
         throw gwr::UTest::Run::Fail();
      }
   }
   {
      rn.next();
      Trace::flush();
      doo(1,2);
      auto i = Trace::begin();
      if (*i!=string("void doo(int, int) [1], [2]"))
      {
         throw gwr::UTest::Run::Fail();
      }
      ++i;
      if (*i!=string("void coo(int, int) [3], [4]"))
      {
         throw gwr::UTest::Run::Fail();
      }
      ++i;
      if (i!=Trace::end())
      {
         throw gwr::UTest::Run::Fail();
      }
   }
   {
      rn.next();
      Trace::flush();
      goo(1,2);
      if (Trace::begin()!=Trace::end())
      {
         throw gwr::UTest::Run::Fail();
      }
   }
}



void trace(gwr::UTest& tests)
{
   gwr::UTest::Run& rn = tests.add("Trace",nullptr,nullptr);
   rn.add("testall",testall);
   rn.add("ndtestall",ndtestall);
}
