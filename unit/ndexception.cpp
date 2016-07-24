#include "ndexception.h"
#include "../src/exception.h"



void ndassert(gwr::UTest::Run&)
{
   {
      bool test = true;
      try
      {
         EFF_ASSERT(test=false,Foo::Bar,__LINE__);
      }
      catch (...)
      {
         throw gwr::UTest::Run::Fail();
      }
      if (!test)
      {
         throw gwr::UTest::Run::Fail();
      }
   }
}



void ndcheck(gwr::UTest::Run&)
{
   {
      bool test = false;
      try
      {
         EFF_CHECK(test=true,Foo::Bar,__LINE__);
      }
      catch (...)
      {
         throw gwr::UTest::Run::Fail();
      }
      if (!test)
      {
         throw gwr::UTest::Run::Fail();
      }
   }
}



void ndpass(gwr::UTest::Run&)
{
   {
      bool test = false;
      try
      {
         EFF_PASS(false==,test=true,Foo::Bar,__LINE__);
      }
      catch (...)
      {
         throw gwr::UTest::Run::Fail();
      }
      if (!test)
      {
         throw gwr::UTest::Run::Fail();
      }
   }
}



void ndfunc_try(gwr::UTest::Run&)
{
   {
      bool test = false;
      try
      {
         EFF_TRY(test=true,Foo::Bar,__LINE__);
      }
      catch (...)
      {
         throw gwr::UTest::Run::Fail();
      }
      if (!test)
      {
         throw gwr::UTest::Run::Fail();
      }
   }
}
