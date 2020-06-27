#include <ctype.h>
#include <math.h>
#include "cgraph_math.h"

cgraph_integer_t cgraph_math_hex2dec(cgraph_char_t data, cgraph_boolean_t *error)
{
  cgraph_integer_t res = 0;
  if(NULL != error)
  {
    *error = CGRAPH_FALSE; 
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
      default  : { *error = CGRAPH_TRUE; break; }
    }
  }

  return res;
}

static const cgraph_char_t __dec2hex_upper__[16] = 
{
  '0', '1', '2', '3', '4', '5', '6', '7', 
  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' 
};

cgraph_char_t cgraph_math_dec2uhex(const cgraph_integer_t data, cgraph_boolean_t *error)
{
  cgraph_char_t ch = 0;
  if(NULL != error)
  {
    *error = CGRAPH_TRUE;
    if(data >= 0 && data < 16)
    {
      ch = __dec2hex_upper__[data];
      *error = CGRAPH_FALSE;
    }
  }

  return  ch;
}

static const cgraph_char_t __dec2hex_lower__[16] = 
{
  '0', '1', '2', '3', '4', '5', '6', '7', 
  '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' 
};

cgraph_char_t cgraph_math_dec2lhex(const cgraph_integer_t data, cgraph_boolean_t *error)
{
  cgraph_char_t ch = 0;
  if(NULL != error)
  {
    *error = CGRAPH_TRUE;
    if(data >= 0 && data < 16)
    {
      ch = __dec2hex_lower__[data];
      *error = CGRAPH_FALSE;
    }
  }

  return  ch;
}

cgraph_char_t cgraph_math_toupper(cgraph_char_t data)
{
  return isupper(data) ? toupper(data) : MATH_ERROR;
}

cgraph_char_t cgraph_math_tolower(cgraph_char_t data)
{
  return islower(data) ? tolower(data) : MATH_ERROR;
}

cgraph_size_t cgraph_math_baseoflen(const cgraph_integer_t data, const cgraph_integer_t base)
{
  cgraph_size_t len = 0;
  cgraph_integer_t new_data = data;
  while(0 != new_data)
  { 
    new_data = new_data / base; 
    len += 1;
  }

  return len;
}

cgraph_boolean_t cgraph_math_prime(const cgraph_integer_t data)
{
  cgraph_boolean_t flag = CGRAPH_TRUE;
  cgraph_integer_t tmp;
  if(2 > data)
  { flag = CGRAPH_FALSE; }
  else if((2 == data) || (3 == data))
  { flag = CGRAPH_TRUE; }
  else if((1 != (tmp=(data%6))) && (5 != tmp))
  { flag = CGRAPH_FALSE; }
  else
  {
    cgraph_integer_t root = sqrt(data), i;
    for(i=5; i<=root; i++)
    {
      if((0 == (data%i)) || (0 == (data%(i+2))))
      {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }
  
  return flag;
}

cgraph_size_t cgraph_math_primes(cgraph_integer_t *primes, cgraph_integer_t *isprime, const cgraph_integer_t data)
{
  cgraph_size_t counter = 0;
  if((NULL != primes) && (NULL != isprime) && (data > 1))
  {
    cgraph_size_t i, j;
    for(i=0; i<data; i++)
    {
      primes[i] = 0;
      isprime[i] = CGRAPH_TRUE;
    }
    for(i=2; i<data; i++)
    {
      if(isprime[i] == CGRAPH_TRUE)
      { primes[counter++] = i; }
      for(j=0; j<counter && i*primes[j]<data ; j++)
      {
        isprime[i*primes[j]] = CGRAPH_FALSE;
        if (i % primes[j] == 0)
        { break; }
      }
    }
  }

  return counter;
}

static cgraph_integer_t cgraph_seed = 0;

void cgraph_random_seed(cgraph_integer_t seed)
{
  cgraph_seed = seed;
}

/*
	Author  : Park,  Miller
	Methode : X(n+1) <- (a * X(n) + b) % m
	a = 16807 or 48271
	m = 2147483647 (CGRAPH_RANDOM_MAX, 2^31 - 1 or 2 << 31 - 1)
	b = 0
	returning a 32bit integer [1, 2147483647]
	X(0) = 1
*/
cgraph_integer_t cgraph_random(void)
{
  const cgraph_integer_t a = 48271, m = CGRAPH_RANDOM_MAX;
  const cgraph_integer_t m_div_a = m / a, m_mod_a = m % a;
  cgraph_integer_t hi = cgraph_seed / m_div_a, lo = cgraph_seed % m_div_a;
  cgraph_seed = (a * lo - m_mod_a * hi);

  return cgraph_seed;
}

cgraph_integer_t cgraph_random_uniform(const cgraph_integer_t min, const cgraph_integer_t max)
{
  return cgraph_random() % (max-min) + min;
}

/*
	Authors : Box and Muller
	mu      : the average value of the normal distribution
	sigma   : the variance of the normal distribution
*/
cgraph_real_t cgraph_random_normal(const cgraph_real_t mu, const cgraph_real_t sigma)
{
	static cgraph_real_t U, V, Z;
	static cgraph_boolean_t phase = CGRAPH_FALSE;
	if(!phase)
	{
		U = (1.0 * cgraph_random() + 1.0) / (CGRAPH_RANDOM_MAX + 2.0);
		V = 1.0 * cgraph_random() / (CGRAPH_RANDOM_MAX + 1.0);
		Z = sqrt(-2.0 * log(U)) * sin(2.0 * MATH_CONST_PI * V);
	}
	else
	{ Z = sqrt(-2.0 * log(U)) * cos(2.0 * MATH_CONST_PI * V); }
	phase  = CGRAPH_TRUE - phase;

	return Z * sigma + mu;
}
