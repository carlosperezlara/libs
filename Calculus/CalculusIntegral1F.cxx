#include "CHelpers.h"
#include "CalculusIntegral1F.h"
#include <cmath>

//=============
CalculusIntegral1F::CalculusIntegral1F() {
  fPrc=1e-8; // default precision
  Clear();
}
//=============
void CalculusIntegral1F::Clear() {
  fRslt=0;
  fDx=0;
  fY.clear();
}
//=============
float CalculusIntegral1F::Execute() {
  Algrthm1();
  return GetLastResult();
}
//=============
void CalculusIntegral1F::Algrthm1() {
  fRslt = 0;
  if(std::abs(fDx)<fPrc) return; // differential zero fapp: result is zero!
  unsigned int n = fY.size();
  if(n<1) return; // empty array: result is zero!

  // sort promotes addition of smaller terms first then big ones. Is that always desirable?
  std::sort(fY.begin(),fY.end(),__CHelpers_SrtFAbs);

  // add the values that are not zero fapp
  for(unsigned i=0; i!=n; ++i)
    if(std::abs(fY[i])>fPrc)
      fRslt += fY[i];
  fRslt *= fDx; // divide by differential

  if(std::abs(fRslt)<fPrc) fRslt=0; // if result is zero faap: result is zero!

  return; // DONE
}
