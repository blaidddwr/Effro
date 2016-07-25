#define DEBUG
#include <string>
#include "../src/exception.h"
#include "exception.h"
#include "ndexception.h"



using std::string;



class TestClass
{
public:
   EFF_DECLARE(TestClass)
   EFF_EXCEPTION(TestException)
};



void assert(gwr::UTest::Run& rn)
{
   {
      bool test = false;
      try
      {
         try
         {
            EFF_ASSERT(false,TestClass::TestException,__LINE__);
         }
         catch (TestClass::TestException e)
         {
            e << "Test Detail.";
            e << (short)1;
            e << (unsigned short)2;
            e << (int)3;
            e << (unsigned int)4;
            e << (long)5;
            e << (unsigned long)6;
            e << (long long)7;
            e << (unsigned long long)8;
            e << (float)3.14;
            e << (double)3.14;
            e << string("end");
            throw e;
         }
      }
      catch (TestClass::TestException e)
      {
         if (e.domain()!=string("TestClass")||e.what()!=string("TestException")||
             e.detail()!=string("Test Detail.123456783.1400003.140000end"))
         {
            throw gwr::UTest::Run::Fail();
         }
         test = true;
      }
      if (!test)
      {
         throw gwr::UTest::Run::Fail();
      }
   }
   {
      rn.next();
      try
      {
         EFF_ASSERT(true,TestClass::TestException,__LINE__);
      }
      catch (TestClass::TestException)
      {
         throw gwr::UTest::Run::Fail();
      }
   }
}



void check(gwr::UTest::Run& rn)
{
   {
      bool test = false;
      try
      {
         try
         {
            EFF_CHECK(false,TestClass::TestException,__LINE__);
         }
         catch (TestClass::TestException e)
         {
            e << "Test Detail.";
            e << (short)1;
            e << (unsigned short)2;
            e << (int)3;
            e << (unsigned int)4;
            e << (long)5;
            e << (unsigned long)6;
            e << (long long)7;
            e << (unsigned long long)8;
            e << (float)3.14;
            e << (double)3.14;
            e << string("end");
            throw e;
         }
      }
      catch (TestClass::TestException e)
      {
         if (e.domain()!=string("TestClass")||e.what()!=string("TestException")||
             e.detail()!=string("Test Detail.123456783.1400003.140000end"))
         {
            throw gwr::UTest::Run::Fail();
         }
         test = true;
      }
      if (!test)
      {
         throw gwr::UTest::Run::Fail();
      }
   }
   {
      rn.next();
      try
      {
         EFF_CHECK(true,TestClass::TestException,__LINE__);
      }
      catch (TestClass::TestException)
      {
         throw gwr::UTest::Run::Fail();
      }
   }
}



void pass(gwr::UTest::Run& rn)
{
   {
      bool test = false;
      try
      {
         try
         {
            EFF_PASS(1==,2,TestClass::TestException,__LINE__);
         }
         catch (TestClass::TestException e)
         {
            e << "Test Detail.";
            e << (short)1;
            e << (unsigned short)2;
            e << (int)3;
            e << (unsigned int)4;
            e << (long)5;
            e << (unsigned long)6;
            e << (long long)7;
            e << (unsigned long long)8;
            e << (float)3.14;
            e << (double)3.14;
            e << string("end");
            throw e;
         }
      }
      catch (TestClass::TestException e)
      {
         if (e.domain()!=string("TestClass")||e.what()!=string("TestException")||
             e.detail()!=string("Test Detail.123456783.1400003.140000end"))
         {
            throw gwr::UTest::Run::Fail();
         }
         test = true;
      }
      if (!test)
      {
         throw gwr::UTest::Run::Fail();
      }
   }
   {
      rn.next();
      try
      {
         EFF_PASS(2==,2,TestClass::TestException,__LINE__);
      }
      catch (TestClass::TestException)
      {
         throw gwr::UTest::Run::Fail();
      }
   }
}



void func_try(gwr::UTest::Run& rn)
{
   {
      bool test = false;
      try
      {
         try
         {
            EFF_TRY(throw int(1),TestClass::TestException,__LINE__);
         }
         catch (TestClass::TestException e)
         {
            e << "Test Detail.";
            e << (short)1;
            e << (unsigned short)2;
            e << (int)3;
            e << (unsigned int)4;
            e << (long)5;
            e << (unsigned long)6;
            e << (long long)7;
            e << (unsigned long long)8;
            e << (float)3.14;
            e << (double)3.14;
            e << string("end");
            throw e;
         }
      }
      catch (TestClass::TestException e)
      {
         if (e.domain()!=string("TestClass")||e.what()!=string("TestException")||
             e.detail()!=string("Test Detail.123456783.1400003.140000end"))
         {
            throw gwr::UTest::Run::Fail();
         }
         test = true;
      }
      if (!test)
      {
         throw gwr::UTest::Run::Fail();
      }
   }
   {
      rn.next();
      try
      {
         EFF_TRY(;,TestClass::TestException,__LINE__);
      }
      catch (TestClass::TestException)
      {
         throw gwr::UTest::Run::Fail();
      }
   }
}



void exception(gwr::UTest& tests)
{
   gwr::UTest::Run& rn {tests.add("Exception",nullptr,nullptr)};
   rn.add("assert",assert);
   rn.add("check",check);
   rn.add("pass",pass);
   rn.add("try",func_try);
   rn.add("ndassert",ndassert);
   rn.add("ndcheck",ndcheck);
   rn.add("ndpass",ndpass);
   rn.add("ndtry",ndfunc_try);
}
