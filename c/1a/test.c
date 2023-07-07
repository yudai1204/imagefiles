#include <stdio.h>
#include <math.h>
double t_sqrtD(double x) 
{
  double         xHalf = 0.5 * x;
  long long int  tmp   = 0x5FE6EB50C7B537AAl - ( *(long long int*)&x >> 1);//initial guess
  double         xRes  = * (double*)&tmp;

  xRes *= ( 1.5 - ( xHalf * xRes * xRes ) );
  xRes *= ( 1.5 - ( xHalf * xRes * xRes ) );//コメントアウトを外すと精度が上がる
  return xRes * x;
}
int main(){
    printf("%lf\n",sqrt(100));
}