#include <ctype.h>
#include "cgraph_math.h"

cgraph_integer_t cgraph_math_hex2dec(cgraph_char_t data)
{
  cgraph_integer_t res = MATH_ERROR;
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
    case 'f' : { res = data - 'a' + 10; break; }
    default  : { break; }
  }

  return res;
}

static cgraph_char_t __dec2hex__[16] = 
{
  '0', '1', '2', '3', '4', '5', '6', '7', 
  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' 
};

cgraph_char_t cgraph_math_dec2hex(const cgraph_integer_t data)
{
  return (data >= 0 && data < 16) ? __dec2hex__[data] : MATH_ERROR;
}

cgraph_char_t cgraph_math_toupper(cgraph_char_t data)
{
  return isupper(data) ? toupper(data) : MATH_ERROR;
}

cgraph_char_t cgraph_math_tolower(cgraph_char_t data)
{
  return islower(data) ? tolower(data) : MATH_ERROR;
}