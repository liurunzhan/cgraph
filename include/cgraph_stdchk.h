#ifndef _CGRAPH_STDCHK_H_
#define _CGRAPH_STDCHK_H_

/** package details */
#define __CGRAPH_VERSION "0.0.0"

/** cpu details */
#ifdef WORDS_BIGENDIAN
#define __CGRAPH_WORDS_BIGENDIAN
#endif

/** compiler details */
#ifdef HAVE_FUNC
#define __CGRAPH_HAVE_FUNC
#endif
#ifdef HAVE_LONG_LONG
#define __CGRAPH_HAVE_LONG_LONG
#endif
#ifdef HAVE_LONG_DOUBLE
#define __CGRAPH_HAVE_LONG_DOUBLE
#endif

/** library details */
#ifdef HAVE_LIBM
#define __CGRAPH_HAVE_LIBM
#endif

#ifdef STDC_HEADERS
#define __CGRAPH_STDC_HEADERS
#endif

#endif /** _CGRAPH_STDCHK_H_ */
