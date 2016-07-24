#include "../src/trace.h"
#include "ndtrace.h"
#include <iostream>



using namespace eff;



void ndfoo(int a, int b)
{
   EFF_TRACE("foo(int,int)",a,b);
   Trace::lock();
}



void ndtestall(gwr::UTest::Run&)
{
   {
      ndfoo(1,2);
      if (Trace::begin()!=Trace::end())
      {
         throw gwr::UTest::Run::Fail();
      }
   }
}
