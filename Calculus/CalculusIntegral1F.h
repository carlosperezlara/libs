#ifndef __CalculusIntegral1F__H__
#define __CalculusIntegral1F__H__
#include <vector>
#include <cmath>

class CalculusIntegral1F {
 public:
  CalculusIntegral1F();
  ~CalculusIntegral1F() {}
  void Fill(const float y) {fY.push_back(y);}
  void SetDx(const float dx) {fDx=dx;}
  float Execute();
  void SetPrc(float p) {fPrc=p;}
  float GetLastResult() {return fRslt;}

 protected:
  bool MySrt(const float,const float);
  void Clear();
  void Algrthm1();

  float fDx;
  std::vector<float> fY;
  float fRslt;
  float fPrc;
};

#endif
