#include "cgraph_config.h"

cgraph_integer_t cgraph_math_hex2dec(const cgraph_int8_t data)
{
  cgraph_integer_t res = -1;
  switch (data)
  {
  case '0' : 
  case '1' :
  case '2' : 
  case '3' :
  case '4' : 
  case '5' :
  case '6' : 
  case '7' :
  case '8' :
  case '9' : { res = data - '0'; break; }
  case 'A' :
  case 'B' :
  case 'C' :
  case 'D' :
  case 'E' :
  case 'F' : { res = data - 'A' + 10; break; }
  case 'a' :
  case 'b' :
  case 'c' :
  case 'd' :
  case 'e' :
  case 'f' : { res = data - 'A' + 10; break; }
  default  : { break; }
  }

  return res;
}

static const cgraph_int8_t __dec2hex__[16] = 
{
  '0', '1', '2', '3', '4', '5', '6', '7', 
  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' 
};