#include <qtflp.h>

N::LP::IRefable:: IRefable ( RefCount x )
                : RefC     (          x )
{
}

N::LP::IRefable::~IRefable (void)
{
}

void N::LP::IRefable::inc(void) const
{
  ++ RefC ;
}

void N::LP::IRefable::dec(void) const
{
  if (RefC<=0) delete this ;
}
