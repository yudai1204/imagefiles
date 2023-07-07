#include<stdio.h>
#define N 24

int sp[N] = {
          1670, 1750, 1280, 1080, 1700, 1850, 2030, 1870, 1920, 1750, 1400, 1560,
          1070, 770,  1150, 1070, 1400, 1120, 1050, 1500, 1400, 1740, 2050, 1780};
int main(void){
  int j, mxp, msf, d;
  printf("/***アルゴリズム1,4**");
  mxp = sp[1] -sp[0];
  msf = sp[0];
  for(j = 1; j <= N -1; j++){
    d = sp[j] -msf;
    if(d > mxp) mxp = d;
    if(sp[j] < msf) msf = sp[j];
  }
  printf("\nmxp = %d\n*/\n", mxp);
}
