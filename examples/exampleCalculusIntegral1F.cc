#include "CalculusIntegral1F.h"
#include <iostream>

using namespace std;

int main() {
  CalculusIntegral1F *inte = new CalculusIntegral1F();
  int N = 1000; // partition size
  float xA = 0.2;
  float xB = 3.0;
  cout << "Testing with function  f(x) = ln(x)" << endl;
  cout << "Using as limits  x_A = " << xA;
  cout << ", x_B = " << xB << endl;
  cout << "Using a partition with  N = " << N << endl;
  float dx = (xB-xA) / N;
  inte->SetDx( dx );
  float prc = 1e-6;
  cout << "Setting precision to " << prc << endl;  
  inte->SetPrc( prc );
  for(int i=0; i!=N; ++i) {
    float x = xA + dx/2 + i*dx;
    float y = std::log( x );
    inte->Fill( y );
  }
  float res = inte->Execute();
  float sol = xB*std::log(xB)-xB -1*(xA*std::log(xA)-xA);
  cout << "Numerical integral: " << res << endl;
  cout << "Analytical solution: " << sol << endl;
  cout << "Difference: " << abs(res-sol) << endl;
}
