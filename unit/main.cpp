#include "exception.h"
#include "trace.h"



int main()
{
   gwr::UTest tests;
   exception(tests);
   trace(tests);
   if (!tests.execute())
   {
      return 1;
   }
   return 0;
}
