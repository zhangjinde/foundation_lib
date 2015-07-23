/* math.h  -  Foundation library  -  Public Domain  -  2013 Mattias Jansson / Rampant Pixels
 *
 * This library provides a cross-platform foundation library in C11 providing basic support data types and
 * functions to write applications and games in a platform-independent fashion. The latest source code is
 * always available at
 *
 * https://github.com/rampantpixels/foundation_lib
 *
 * This library is put in the public domain; you can redistribute it and/or modify it without any restrictions.
 *
 */

#pragma once

/*!

\file math.h
\brief Math functions
\details Core math functionality, providing single entry points to common math
functions across platforms and floating point notations used (32 or 64 bit real numbers).

Increment/decrement and wrap functions from
http://cellperformance.beyond3d.com/articles/2006/07/increment-and-decrement-wrapping-values.html */

#include <foundation/platform.h>
#include <foundation/types.h>
#include <foundation/assert.h>

#if FOUNDATION_COMPILER_INTEL
#  include <mathimf.h>
#  undef I
#else
#  include <math.h>
#endif

#if FOUNDATION_COMPILER_CLANG
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wbad-function-cast"
#endif

#if FOUNDATION_SIZE_REAL == 32

/*! \brief Epsilon value
Epsilon value. This represents a small number close to zero that can be used
for comparisons or thresholds. Roughly equals 100 floating point units at 1.0 */
#define REAL_EPSILON  0.00001f

/*! \brief Maximum finite number
Maximum finite number representable in the current real number format */
#define REAL_MAX      FLT_MAX

/*! \brief Minimum finite number
Minimum finite number representable in the current real number format */
#define REAL_MIN      FLT_MIN

#else

#define REAL_EPSILON  0.00000000000002

#define REAL_MAX      DBL_MAX
#define REAL_MIN      DBL_MIN

#endif

/*! \brief Constant zero (0.0)
Constant zero (0.0) */
#define REAL_ZERO     REAL_C( 0.0 )

/*! \brief Constant one (1.0)
Constant one (1.0) */
#define REAL_ONE      REAL_C( 1.0 )

/*! \brief Constant two (2.0)
Constant two (2.0) */
#define REAL_TWO      REAL_C( 2.0 )

/*! \brief Constant three (3.0)
Constant three (3.0) */
#define REAL_THREE    REAL_C( 3.0 )

/*! \brief Constant four (4.0)
Constant four (4.0) */
#define REAL_FOUR     REAL_C( 4.0 )

/*! \brief Constant half (0.5)
Constant half (0.5) */
#define REAL_HALF     REAL_C( 0.5 )

/*! \brief Constant quarter (0.25)
Constant quarter (0.25) */
#define REAL_QUARTER  REAL_C( 0.25 )

/*! \brief Constant pi (3.141592...)
Constant pi (3.141592...) */
#define REAL_PI       REAL_C( 3.1415926535897932384626433832795 )

/*! \brief Constant half pi (1.570796...)
Constant half pi (1.570796...) */
#define REAL_HALFPI   REAL_C( 1.5707963267948966192313216916398 )

/*! \brief Constant two pi (6.283185...)
Constant two pi (6.283185...) */
#define REAL_TWOPI    REAL_C( 6.2831853071795864769252867665590 )

/*! \brief Constant square root of two (1.414213...)
Constant square root of two (1.414213...) */
#define REAL_SQRT2    REAL_C( 1.4142135623730950488016887242097 )

/*! \brief Constant square root of three (1.732050...)
Constant square root of three (1.732050...) */
#define REAL_SQRT3    REAL_C( 1.7320508075688772935274463415059 )

/*! \brief Constant number e (2.718281...)
Constant number e (2.718281...) */
#define REAL_E        REAL_C( 2.7182818284590452353602874713527 )

/*! \brief Constant natural logarithm of two (0.693147...)
Constant natural logarithm of two (0.693147...) */
#define REAL_LOGN2    REAL_C( 0.6931471805599453094172321214582 )

/*! \brief Constant natural logarithm of ten (2.302585...)
Constant natural logarithm of ten (2.302585...) */
#define REAL_LOGN10   REAL_C( 2.3025850929940456840179914546844 )

/*! \brief Sine function
Sine function
\param x Argument
\return Sine of argument */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_sin( real x );

/*! \brief Cosine function
Cosine function
\param x Argument
\return Cosine of argument */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_cos( real x );

/*! \brief Tangent function
Tangent function
\param x Argument
\return Tangent of argument */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_tan( real x );

/*! \brief Arcsine function
Arcsine function
\param x Argument
\return Arcsine of argument */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_asin( real x );

/*! \brief Arccosine function
Arccosine function
\param x Argument
\return Arccosine of argument */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_acos( real x );

/*! \brief Arctangent function
Arctangent function
\param x Argument
\return Arctangent of argument */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_atan( real x );

/*! \brief Calculate angle for point
Calculate the angle in radians between the positive x-axis of a plane and the point given
by the coordinates (x, y) on it. The angle is positive for counter-clockwise angles (upper
half-plane, y > 0), and negative for clockwise angles (lower half-plane, y < 0).
\param x X coordinate
\param y Y coordinate
\return Angle in radians */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_atan2( real x, real y );

/*! \brief Square root function
Square root function
\param x Argument
\return Square root of argument */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_sqrt( real x );

/*! \brief Inverse square root
Inverse square root (1/sqrt) function
\param x Argument
\return Inverse square root of argument */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_rsqrt( real x );

/*! \brief Absolute function
Absolute function
\param x Argument
\return Absulute of argument */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_abs( real x );

/*! \brief Modulo function
Floating point modulo function
\param x Value
\param y Base
\return x modulo y */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_mod( real x, real y );

/*! \brief Natural exponential function
Natural exponential function
\param x Argument
\return e^x */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_exp( real x );

/*! \brief Power (exponential) function
Power (exponential) function
\param x Base
\param y Exponent
\return x^y */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_pow( real x, real y );

/*! \brief Natural logarithm function
Natural logarithm function
\param x Argument
\return Natural logarithm of argument */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_logn( real x );

/*! \brief Binary logarithm (base 2) function
\details Binary logarithm (base 2) function
\param x Argument
\return Binary logarithm of argument */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_log2( real x );

/*! \brief Floor function
Floor (largest previous integer) function
\param x Argument
\return Largest integer not greater than x */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL int
math_floor( real x );

/*! \brief Floor function
Floor (largest previous 64 bit integer) function
\param x Argument
\return Largest 64 bit integer not greater than x */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL int64_t
math_floor64( real x );

/*! \brief Ceiling function
Ceiling (smallest following integer) function
\param x Argument
\return Smallest integer greater than x */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL int
math_ceil( real x );

/*! \brief Ceiling function
Ceiling (smallest following 64 bit integer) function
\param x Argument
\return Smallest 64 bit integer greater than x */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL int64_t
math_ceil64( real x );

/*! \brief Round function
Round to nearest floating point function
\param x Argument
\return Argument rounded to nearest integer */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL int
math_round( real x );

/*! \brief Truncation (integral part) function
Truncation (integral part) function
\param x Argument
\return Integral part of argument */
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL int
math_trunc( real x );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL unsigned int
math_align_poweroftwo( unsigned int x );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool
math_is_poweroftwo( unsigned int x );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL unsigned int
math_align_up( unsigned int x, unsigned int alignment );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_smoothstep( real t );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_smootherstep( real t );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_lerp( real t, real x, real y );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_unlerp( real v, real x, real y );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_linear_remap( real x, real xmin, real xmax, real ymin, real ymax );

#define math_max( x, y ) ( (x) < (y) ? (y) : (x) )
#define math_min( x, y ) ( (x) < (y) ? (x) : (y) )
#define math_clamp( x, minval, maxval ) ( (x) < (minval) ? (minval) : ( (x) > (maxval) ? (maxval) : (x) ) )

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool
math_realeq( real, real, int ulps );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool
math_realeqns( real, real, int ulps );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool
math_realiszero( real val );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool
math_realisone( real val );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_realdec( real val, int units );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_realinc( real val, int units );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool
math_realisnan( real val );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool
math_realisinf( real val );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool
math_realisuninitialized( real val );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool
math_realisfinite( real val );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool
math_realisdenormalized( real val );

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real
math_realundenormalize( real val );

#if BUILD_ENABLE_ASSERT
#  define FOUNDATION_ASSERT_FINITE( value ) \
	/*lint -save -e717 */ do { FOUNDATION_ASSERT_MSG( math_realisfinite( (value), "Non-finite float value" ); } while(0) /*lint -restore */
#else
#  define FOUNDATION_ASSERT_FINITE( value ) /*lint -save -e717 */ do { (void)sizeof( value ); } while(0) /*lint -restore */
#endif


#define FOUNDATION_DECLARE_INCREMENT_AND_WRAP( suffix, type, signed_type, bit_mask ) \
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL type math_inc_wrap_##suffix( const type val, const type min, const type max ); \
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL type math_inc_wrap_##suffix( const type val, const type min, const type max ) { \
	const type increased    = val + 1; \
	const type max_diff     = max - val; \
	const type max_diff_nz  = (type)( ( (signed_type)max_diff | -(signed_type)max_diff ) >> bit_mask ); \
	const type max_diff_eqz = ~max_diff_nz; \
	const type result       = ( increased & max_diff_nz ) | ( min & max_diff_eqz ); \
	return result; }

FOUNDATION_DECLARE_INCREMENT_AND_WRAP( uint8,  uint8_t,  int8_t,  7  )
FOUNDATION_DECLARE_INCREMENT_AND_WRAP( uint16, uint16_t, int16_t, 15 )
FOUNDATION_DECLARE_INCREMENT_AND_WRAP( uint32, uint32_t, int32_t, 31 )
FOUNDATION_DECLARE_INCREMENT_AND_WRAP( uint64, uint64_t, int64_t, 63ULL )
FOUNDATION_DECLARE_INCREMENT_AND_WRAP( int8,   int8_t,   int8_t,  7  )
FOUNDATION_DECLARE_INCREMENT_AND_WRAP( int16,  int16_t,  int16_t, 15 )
FOUNDATION_DECLARE_INCREMENT_AND_WRAP( int32,  int32_t,  int32_t, 31 )
FOUNDATION_DECLARE_INCREMENT_AND_WRAP( int64,  int64_t,  int64_t, 63ULL )
#undef FOUNDATION_DECLARE_INCREMENT_AND_WRAP

#define FOUNDATION_DECLARE_DECREMENT_AND_WRAP( suffix, type, signed_type, bit_mask ) \
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL type math_dec_wrap_##suffix( const type val, const type min, const type max ); \
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL type math_dec_wrap_##suffix( const type val, const type min, const type max ) { \
	const type decreased    = val - 1; \
	const type min_diff     = min - val; \
	const type min_diff_nz  = (type)( ( (signed_type)min_diff | -(signed_type)min_diff ) >> bit_mask ); \
	const type min_diff_eqz = ~min_diff_nz; \
	const type result       = ( decreased & min_diff_nz ) | ( max & min_diff_eqz ); \
	return result; }

FOUNDATION_DECLARE_DECREMENT_AND_WRAP( uint8,  uint8_t,  int8_t,  7  )
FOUNDATION_DECLARE_DECREMENT_AND_WRAP( uint16, uint16_t, int16_t, 15 )
FOUNDATION_DECLARE_DECREMENT_AND_WRAP( uint32, uint32_t, int32_t, 31 )
FOUNDATION_DECLARE_DECREMENT_AND_WRAP( uint64, uint64_t, int64_t, 63ULL )
FOUNDATION_DECLARE_DECREMENT_AND_WRAP( int8,  int8_t,   int8_t,  7  )
FOUNDATION_DECLARE_DECREMENT_AND_WRAP( int16, int16_t,  int16_t, 15 )
FOUNDATION_DECLARE_DECREMENT_AND_WRAP( int32, int32_t,  int32_t, 31 )
FOUNDATION_DECLARE_DECREMENT_AND_WRAP( int64, int64_t,  int64_t, 63ULL )
#undef FOUNDATION_DECLARE_DECREMENT_AND_WRAP


#ifndef FOUNDATION_PLATFORM_DOXYGEN
// IMPLEMENTATIONS

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL unsigned int math_align_poweroftwo( unsigned int x )
{
	FOUNDATION_ASSERT( x > 1 );

#if FOUNDATION_COMPILER_INTEL && ( FOUNDATION_ARCH_X86 || FOUNDATION_ARCH_X86_64 )
	--x;
	__asm__( "bsrl %1,%0"
		:"=r" (x)
		:"rm" (x) );
	return ( 1 << ( x + 1 ) );
#else
	--x;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return ++x;
#endif
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_is_poweroftwo( unsigned int x )
{
	return ( x & ( x - 1 ) ) == 0;
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL unsigned int math_align_up( unsigned int x, unsigned int alignment )
{
	unsigned int aligned = x;
	unsigned int remain = x % alignment;
	if( remain )
		aligned += alignment - remain;
	return aligned;
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real math_smoothstep( real t ) { return ( REAL_C(3.0) - REAL_C(2.0)*t ) * ( t * t ); }
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real math_smootherstep( real t ) { return ( t * t * t ) * ( t * ( t * REAL_C(6.0) - REAL_C(15.0) ) + REAL_C(10.0) ); }

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real math_lerp( real t, real x, real y ) { return ( x + ( t * ( y - x ) ) ); }
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real math_unlerp( real v, real x, real y ) { return ( ( v - x ) / ( y - x ) ); }
static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real math_linear_remap( real x, real xmin, real xmax, real ymin, real ymax ) { return math_lerp( math_unlerp( x, xmin, xmax ), ymin, ymax ); }

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real math_log2( real x ) { return math_logn( x ) * REAL_C( 1.4426950408889634073599246810019 ); }

#if FOUNDATION_COMPILER_MSVC

#if FOUNDATION_SIZE_REAL == 64

static FOUNDATION_FORCEINLINE real     math_sin( real x ) { return sin( x ); }
static FOUNDATION_FORCEINLINE real     math_cos( real x ) { return cos( x ); }
static FOUNDATION_FORCEINLINE real     math_tan( real x ) { return tan( x ); }
static FOUNDATION_FORCEINLINE real     math_asin( real x ) { return asin( x ); }
static FOUNDATION_FORCEINLINE real     math_acos( real x ) { return acos( x ); }
static FOUNDATION_FORCEINLINE real     math_atan( real x ) { return atan( x ); }
static FOUNDATION_FORCEINLINE real     math_atan2( real x, real y ) { return atan2( x, y ); }
static FOUNDATION_FORCEINLINE real     math_sqrt( real x ) { return sqrt( x ); }
#  if FOUNDATION_COMPILER_MSVC
static FOUNDATION_FORCEINLINE real     math_rsqrt( real x ) { return REAL_C( 1.0 ) / sqrtf( x ); }
#  else
static FOUNDATION_FORCEINLINE real     math_rsqrt( real x ) { return invsqrt( x ); }
#  endif
static FOUNDATION_FORCEINLINE real     math_abs( real x ) { return fabs( x ); }
static FOUNDATION_FORCEINLINE real     math_mod( real x, real y ) { return fmod( x, y ); }
static FOUNDATION_FORCEINLINE real     math_exp( real x ) { return exp( x ); }
static FOUNDATION_FORCEINLINE real     math_pow( real x, real y ) { return pow( x, y ); }
static FOUNDATION_FORCEINLINE real     math_logn( real x ) { return log( x ); }
static FOUNDATION_FORCEINLINE int      math_floor( real x ) { return (int)floor( x ); }
static FOUNDATION_FORCEINLINE int      math_ceil( real x ) { return (int)ceil( x ); }
static FOUNDATION_FORCEINLINE int      math_round( real x ) { return (int)( x + 0.5f ); }
static FOUNDATION_FORCEINLINE int      math_trunc( real x ) { return (int)x; }
static FOUNDATION_FORCEINLINE int64_t  math_floor64( real x ) { return (int64_t)floor( x ); }
static FOUNDATION_FORCEINLINE int64_t  math_ceil64( real x ) { return (int64_t)ceil( x ); }

#elif FOUNDATION_ARCH_X86

_CRTIMP double  __cdecl ceil(_In_ double _X);

static FOUNDATION_FORCEINLINE real     math_sin( real x ) { return (real)sin( x ); }
static FOUNDATION_FORCEINLINE real     math_cos( real x ) { return (real)cos( x ); }
static FOUNDATION_FORCEINLINE real     math_tan( real x ) { return (real)tan( x ); }
static FOUNDATION_FORCEINLINE real     math_asin( real x ) { return (real)asin( x ); }
static FOUNDATION_FORCEINLINE real     math_acos( real x ) { return (real)acos( x ); }
static FOUNDATION_FORCEINLINE real     math_atan( real x ) { return (real)atan( x ); }
static FOUNDATION_FORCEINLINE real     math_atan2( real x, real y ) { return (real)atan2( x, y ); }
static FOUNDATION_FORCEINLINE real     math_sqrt( real x ) { return (real)sqrt( x ); }
static FOUNDATION_FORCEINLINE real     math_rsqrt( real x ) { return REAL_C( 1.0 ) / (real)sqrt( x ); }
static FOUNDATION_FORCEINLINE real     math_abs( real x ) { return (real)fabs( x ); }
static FOUNDATION_FORCEINLINE real     math_mod( real x, real y ) { return (real)fmod( x, y ); }
static FOUNDATION_FORCEINLINE real     math_exp( real x ) { return (real)exp( x ); }
static FOUNDATION_FORCEINLINE real     math_pow( real x, real y ) { return (real)pow( x, y ); }
static FOUNDATION_FORCEINLINE real     math_logn( real x ) { return (real)log( x ); }
static FOUNDATION_FORCEINLINE int      math_floor( real x ) { return (int)floor( x ); }
static FOUNDATION_FORCEINLINE int      math_ceil( real x ) { return (int)ceil( x ); }
static FOUNDATION_FORCEINLINE int      math_round( real x ) { return (int)( x + 0.5f ); }
static FOUNDATION_FORCEINLINE int      math_trunc( real x ) { return (int)x; }
static FOUNDATION_FORCEINLINE int64_t  math_floor64( real x ) { return (int64_t)floor( x ); }
static FOUNDATION_FORCEINLINE int64_t  math_ceil64( real x ) { return (int64_t)ceil( x ); }

#else

static FOUNDATION_FORCEINLINE real     math_sin( real x ) { return sinf( x ); }
static FOUNDATION_FORCEINLINE real     math_cos( real x ) { return cosf( x ); }
static FOUNDATION_FORCEINLINE real     math_tan( real x ) { return tanf( x ); }
static FOUNDATION_FORCEINLINE real     math_asin( real x ) { return asinf( x ); }
static FOUNDATION_FORCEINLINE real     math_acos( real x ) { return acosf( x ); }
static FOUNDATION_FORCEINLINE real     math_atan( real x ) { return atanf( x ); }
static FOUNDATION_FORCEINLINE real     math_atan2( real x, real y ) { return atan2f( x, y ); }
static FOUNDATION_FORCEINLINE real     math_sqrt( real x ) { return sqrtf( x ); }
static FOUNDATION_FORCEINLINE real     math_rsqrt( real x ) { return REAL_C( 1.0 ) / sqrtf( x ); }
static FOUNDATION_FORCEINLINE real     math_abs( real x ) { return (real)fabs( x ); }
static FOUNDATION_FORCEINLINE real     math_mod( real x, real y ) { return fmodf( x, y ); }
static FOUNDATION_FORCEINLINE real     math_exp( real x ) { return expf( x ); }
static FOUNDATION_FORCEINLINE real     math_pow( real x, real y ) { return powf( x, y ); }
static FOUNDATION_FORCEINLINE real     math_logn( real x ) { return logf( x ); }
static FOUNDATION_FORCEINLINE int      math_floor( real x ) { return (int)floorf( x ); }
static FOUNDATION_FORCEINLINE int      math_ceil( real x ) { return (int)ceilf( x ); }
static FOUNDATION_FORCEINLINE int      math_round( real x ) { return (int)( x + 0.5f ); }
static FOUNDATION_FORCEINLINE int      math_trunc( real x ) { return (int)x; }
static FOUNDATION_FORCEINLINE int64_t  math_floor64( real x ) { return (int64_t)floor( x ); }
static FOUNDATION_FORCEINLINE int64_t  math_ceil64( real x ) { return (int64_t)ceil( x ); }

#endif

#elif FOUNDATION_COMPILER_INTEL

#if FOUNDATION_SIZE_REAL == 64

static FOUNDATION_FORCEINLINE real     math_sin( real x ) { return sin( x ); }
static FOUNDATION_FORCEINLINE real     math_cos( real x ) { return cos( x ); }
static FOUNDATION_FORCEINLINE real     math_tan( real x ) { return tan( x ); }
static FOUNDATION_FORCEINLINE real     math_asin( real x ) { return asin( x ); }
static FOUNDATION_FORCEINLINE real     math_acos( real x ) { return acos( x ); }
static FOUNDATION_FORCEINLINE real     math_atan( real x ) { return atan( x ); }
static FOUNDATION_FORCEINLINE real     math_atan2( real x, real y ) { return atan2( x, y ); }
static FOUNDATION_FORCEINLINE real     math_sqrt( real x ) { return sqrt( x ); }
static FOUNDATION_FORCEINLINE real     math_rsqrt( real x ) { return invsqrt( x ); }
static FOUNDATION_FORCEINLINE real     math_abs( real x ) { return fabs( x ); }
static FOUNDATION_FORCEINLINE real     math_mod( real x, real y ) { return fmod( x, y ); }
static FOUNDATION_FORCEINLINE real     math_exp( real x ) { return exp( x ); }
static FOUNDATION_FORCEINLINE real     math_pow( real x, real y ) { return pow( x, y ); }
static FOUNDATION_FORCEINLINE real     math_logn( real x ) { return log( x ); }
static FOUNDATION_FORCEINLINE int      math_floor( real x ) { return (int)floor( x ); }
static FOUNDATION_FORCEINLINE int      math_ceil( real x ) { return (int)ceil( x ); }
static FOUNDATION_FORCEINLINE int      math_round( real x ) { return (int)( x + 0.5f ); }
static FOUNDATION_FORCEINLINE int      math_trunc( real x ) { return (int)x; }
static FOUNDATION_FORCEINLINE int64_t  math_floor64( real x ) { return (int64_t)floor( x ); }
static FOUNDATION_FORCEINLINE int64_t  math_ceil64( real x ) { return (int64_t)ceil( x ); }

#else

static FOUNDATION_FORCEINLINE real     math_sin( real x ) { return sinf( x ); }
static FOUNDATION_FORCEINLINE real     math_cos( real x ) { return cosf( x ); }
static FOUNDATION_FORCEINLINE real     math_tan( real x ) { return tanf( x ); }
static FOUNDATION_FORCEINLINE real     math_asin( real x ) { return asinf( x ); }
static FOUNDATION_FORCEINLINE real     math_acos( real x ) { return acosf( x ); }
static FOUNDATION_FORCEINLINE real     math_atan( real x ) { return atanf( x ); }
static FOUNDATION_FORCEINLINE real     math_atan2( real x, real y ) { return atan2f( x, y ); }
static FOUNDATION_FORCEINLINE real     math_sqrt( real x ) { return sqrtf( x ); }
static FOUNDATION_FORCEINLINE real     math_rsqrt( real x ) { return invsqrtf( x ); }
static FOUNDATION_FORCEINLINE real     math_abs( real x ) { return fabsf( x ); }
static FOUNDATION_FORCEINLINE real     math_mod( real x, real y ) { return fmodf( x, y ); }
static FOUNDATION_FORCEINLINE real     math_exp( real x ) { return expf( x ); }
static FOUNDATION_FORCEINLINE real     math_pow( real x, real y ) { return powf( x, y ); }
static FOUNDATION_FORCEINLINE real     math_logn( real x ) { return logf( x ); }
static FOUNDATION_FORCEINLINE int      math_floor( real x ) { return (int)floorf( x ); }
static FOUNDATION_FORCEINLINE int      math_ceil( real x ) { return (int)ceilf( x ); }
static FOUNDATION_FORCEINLINE int      math_round( real x ) { return (int)( x + 0.5f ); }
static FOUNDATION_FORCEINLINE int      math_trunc( real x ) { return (int)x; }
static FOUNDATION_FORCEINLINE int64_t  math_floor64( real x ) { return (int64_t)floor( x ); }
static FOUNDATION_FORCEINLINE int64_t  math_ceil64( real x ) { return (int64_t)ceil( x ); }

#endif

#elif FOUNDATION_COMPILER_GCC || FOUNDATION_COMPILER_CLANG

static FOUNDATION_FORCEINLINE real     math_sin( real x ) { return (real)__builtin_sin( x ); }
static FOUNDATION_FORCEINLINE real     math_cos( real x ) { return (real)__builtin_cos( x ); }
static FOUNDATION_FORCEINLINE real     math_tan( real x ) { return (real)__builtin_tan( x ); }
static FOUNDATION_FORCEINLINE real     math_asin( real x ) { return (real)__builtin_asin( x ); }
static FOUNDATION_FORCEINLINE real     math_acos( real x ) { return (real)__builtin_acos( x ); }
static FOUNDATION_FORCEINLINE real     math_atan( real x ) { return (real)__builtin_atan( x ); }
static FOUNDATION_FORCEINLINE real     math_atan2( real x, real y ) { return (real)__builtin_atan2( x, y ); }
static FOUNDATION_FORCEINLINE real     math_sqrt( real x ) { return (real)__builtin_sqrt( x ); }
static FOUNDATION_FORCEINLINE real     math_rsqrt( real x ) { return (real)(REAL_C( 1.0 ) / __builtin_sqrt( x )); }
static FOUNDATION_FORCEINLINE real     math_abs( real x ) { return (real)__builtin_fabs( x ); }
static FOUNDATION_FORCEINLINE real     math_mod( real x, real y ) { return (real)__builtin_fmod( x, y ); }
static FOUNDATION_FORCEINLINE real     math_exp( real x ) { return (real)__builtin_exp( x ); }
static FOUNDATION_FORCEINLINE real     math_pow( real x, real y ) { return (real)__builtin_pow( x, y ); }
static FOUNDATION_FORCEINLINE real     math_logn( real x ) { return (real)__builtin_log( x ); }

#if FOUNDATION_SIZE_REAL == 64

static FOUNDATION_FORCEINLINE int      math_floor( real x ) { return (int)__builtin_floor( x ); }
static FOUNDATION_FORCEINLINE int      math_ceil( real x ) { return (int)__builtin_ceil( x ); }
static FOUNDATION_FORCEINLINE int64_t  math_floor64( real x ) { return (int64_t)__builtin_floor( x ); }
static FOUNDATION_FORCEINLINE int64_t  math_ceil64( real x ) { return (int64_t)__builtin_ceil( x ); }
#if FOUNDATION_PLATFORM_APPLE || FOUNDATION_PLATFORM_WINDOWS
static FOUNDATION_FORCEINLINE int      math_round( real x ) { return (int)( x + 0.5 ); }
static FOUNDATION_FORCEINLINE int      math_trunc( real x ) { return (int)( x ); }
#else
static FOUNDATION_FORCEINLINE int      math_round( real x ) { return (int)__builtin_round( x ); }
static FOUNDATION_FORCEINLINE int      math_trunc( real x ) { return (int)__builtin_trunc( x ); }
#endif

#else

static FOUNDATION_FORCEINLINE int      math_ceil( real x ) { return (int)__builtin_ceilf( x ); }
static FOUNDATION_FORCEINLINE int      math_floor( real x ) { return (int)__builtin_floorf( x ); }
static FOUNDATION_FORCEINLINE int64_t  math_ceil64( real x ) { return (int64_t)__builtin_ceil( x ); }
static FOUNDATION_FORCEINLINE int64_t  math_floor64( real x ) { return (int64_t)__builtin_floor( x ); }
#if FOUNDATION_PLATFORM_APPLE || FOUNDATION_PLATFORM_WINDOWS
static FOUNDATION_FORCEINLINE int      math_round( real x ) { return (int)( x + 0.5f ); }
static FOUNDATION_FORCEINLINE int      math_trunc( real x ) { return (int)( x ); }
#else
static FOUNDATION_FORCEINLINE int      math_round( real x ) { return (int)__builtin_roundf( x ); }
static FOUNDATION_FORCEINLINE int      math_trunc( real x ) { return (int)__builtin_truncf( x ); }
#endif

#endif

#else
#  error Unknown compiler
#endif


#if FOUNDATION_SIZE_REAL == 64

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realisnan( real val )
{
#if !defined( __cplusplus ) && !FOUNDATION_COMPILER_MSVC
	const real_cast_t conv = { .rval=val };
#else
	real_cast_t conv; conv.rval = val;
#endif
	return ( ( ( (const uint64_t)conv.ival & 0x7F80000000000000ULL ) >> 55ULL ) == 0xff ) & ( ( (const uint64_t)conv.ival & 0xFFFFFFFFFFFFFULL ) != 0 );
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realisinf( real val )
{
#if !defined( __cplusplus ) && !FOUNDATION_COMPILER_MSVC
	const real_cast_t conv = { .rval=val };
#else
	real_cast_t conv; conv.rval = val;
#endif
	return ( ( ( (const uint64_t)conv.ival & 0x7F80000000000000ULL ) >> 55ULL ) == 0xff ) & ( ( (const uint64_t)conv.ival & 0xFFFFFFFFFFFFFULL ) == 0 );
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realisuninitialized( real val )
{
#if !defined( __cplusplus ) && !FOUNDATION_COMPILER_MSVC
	const real_cast_t conv = { .rval=val };
#else
	real_cast_t conv; conv.rval = val;
#endif
	return ( (const uint64_t)conv.ival == 0xCDCDCDCDCDCDCDCDULL ) | ( (const uint64_t)conv.ival == 0xFEEEFEEEFEEEFEEEULL );
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realisfinite( real val )
{
	return !( math_realisnan( val ) || math_realisinf( val ) || math_realisuninitialized( val ) );
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realisdenormalized( real val )
{
#if !defined( __cplusplus ) && !FOUNDATION_COMPILER_MSVC
	const real_cast_t conv = { .rval=val };
#else
	real_cast_t conv; conv.rval = val;
#endif
	return ( ( (const uint64_t)conv.ival & 0x7F80000000000000ULL ) == 0 );
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real math_realundenormalize( real val )
{
#if !defined( __cplusplus ) && !FOUNDATION_COMPILER_MSVC
	const real_cast_t conv = { .rval=val };
#else
	real_cast_t conv; conv.rval = val;
#endif
	if( ( (const uint64_t)conv.ival & 0x7F80000000000000ULL ) == 0 )
		return 0;
	return val;
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realeq( real a, real b, int32_t ulps )
{
	real_cast_t ca;
	real_cast_t cb;
	int64_t ai, bi, diff;
	ca.rval = a;
	cb.rval = b;

	ai = ca.ival;
	if( ai < 0 )
		ai = 0x8000000000000000LL - ai;

	bi = cb.ival;
	if( bi < 0 )
		bi = 0x8000000000000000LL - bi;

	diff = ( ai - bi );
	if( ( diff <= ulps ) && ( diff >= -ulps ) )
		return true;

	return false;
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realeqns( real a, real b, int32_t ulps )
{
	real_cast_t ca;
	real_cast_t cb;
	int64_t diff;

	ca.rval = a;
	cb.rval = b;

	diff = ( ca.ival - cb.ival );
	if( ( diff <= ulps ) && ( diff >= -ulps ) )
		return true;
	return false;
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realiszero( real val )
{
#if 0
	real_cast_t ca;
	int64_t ai;

	ca.rval = val;

	ai = ca.ival;
	if( ai < 0 )
		ai = 0x8000000000000000LL - ai;

	if( ( ai <= 100 ) && ( ai >= -100 ) )
		return true;

	return false;
#else

	return math_abs( val ) < REAL_EPSILON;

#endif
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realisone( real val )
{
#if 0
	real_cast_t ca;
	int64_t ai, diff;
	ca.rval = val;

	ai = ca.ival;
	if( ai < 0 )
		ai = 0x8000000000000000LL - ai;

	diff = ( ai - 0x3ff0000000000000LL );
	if( ( diff <= 100 ) && ( diff >= -100 ) )
		return true;

	return false;
#else
	return math_abs( val - REAL_ONE ) < REAL_EPSILON;
#endif
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real math_realdec( real val, int units )
{
	real_cast_t ca; ca.rval = val;

	ca.ival -= ( ca.ival < 0 ? -units : units );

	return ca.rval;
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real math_realinc( real val, int units )
{
	real_cast_t ca; ca.rval = val;

	ca.ival += ( ca.ival < 0 ? -units : units );

	return ca.rval;
}

#else

static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realisnan( real val )
{
#if !defined( __cplusplus ) && !FOUNDATION_COMPILER_MSVC
	const real_cast_t conv = { .rval=val };
#else
	real_cast_t conv; conv.rval = val;
#endif
	return ( ( ( (const uint32_t)conv.ival & 0x7F800000 ) >> 23 ) == 0xFF ) & ( ( (const uint32_t)conv.ival & 0x7FFFFF ) != 0 );
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realisinf( real val )
{
#if !defined( __cplusplus ) && !FOUNDATION_COMPILER_MSVC
	const real_cast_t conv = { .rval=val };
#else
	real_cast_t conv; conv.rval = val;
#endif
	return ( ( ( (const uint32_t)conv.ival & 0x7F800000) >> 23 ) == 0xFF ) & ( ( (const uint32_t)conv.ival & 0x7FFFFF ) == 0 );
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realisuninitialized( real val )
{
#if !defined( __cplusplus ) && !FOUNDATION_COMPILER_MSVC
	const real_cast_t conv = { .rval=val };
#else
	real_cast_t conv; conv.rval = val;
#endif
	//Some common debugger uninitialized filler values
	return ( (const uint32_t)conv.ival == 0xFEEEFEEEU ) || ( (const uint32_t)conv.ival == 0xCDCDCDCDU );
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realisfinite( real val )
{
	return !( math_realisnan( val ) || math_realisinf( val ) || math_realisuninitialized( val ) );
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realisdenormalized( real val )
{
#if !defined( __cplusplus ) && !FOUNDATION_COMPILER_MSVC
	const real_cast_t conv = { .rval=val };
#else
	real_cast_t conv; conv.rval = val;
#endif
	return ( ( (const uint32_t)conv.ival & 0x7F800000ULL ) == 0 );
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real math_realundenormalize( real val )
{
#if !defined( __cplusplus ) && !FOUNDATION_COMPILER_MSVC
	const real_cast_t conv = { .rval=val };
#else
	real_cast_t conv; conv.rval = val;
#endif
	if( ( (const uint32_t)conv.ival & 0x7F800000 ) == 0 )
		return 0;
	return val;
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realeq( real a, real b, int ulps )
{
	real_cast_t ca;
	real_cast_t cb;
	int32_t ai, bi, diff;
	ca.rval = a;
	cb.rval = b;

	ai = ca.ival;
	if( ai < 0 )
		ai = (int32_t)0x80000000 - ai;

	bi = cb.ival;
	if( bi < 0 )
		bi = (int32_t)0x80000000 - bi;

	diff = ( ai - bi );
	if( ( diff <= ulps ) && ( diff >= -ulps ) )
		return true;

	return false;
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realeqns( real a, real b, int ulps )
{
	real_cast_t ca;
	real_cast_t cb;
	int32_t diff;
	ca.rval = a;
	cb.rval = b;

	diff = ( ca.ival - cb.ival );
	if( ( diff <= ulps ) && ( diff >= -ulps ) )
		return true;
	return false;
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realiszero( real val )
{
#if 0
	real_cast_t ca;
	int32_t ai;
	ca.rval = val;

	ai = ca.ival;
	if( ai < 0 )
		ai = 0x80000000 - ai;

	if( ( ai <= 100 ) && ( ai >= -100 ) )
		return true;

	return false;
#else
	return math_abs( val ) < REAL_EPSILON;
#endif
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL bool math_realisone( real val )
{
#if 0
	real_cast_t ca;
	int32_t ai, diff;
	ca.rval = val;

	ai = ca.ival;
	if( ai < 0 )
		ai = 0x80000000 - ai;

	diff = ( ai - 0x3f800000 );
	if( ( diff <= 100 ) && ( diff >= -100 ) )
		return true;

	return false;
#else
	return math_abs( val - 1.0f ) < REAL_EPSILON;
#endif
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real math_realdec( real val, int units )
{
	real_cast_t ca; ca.rval = val;

	ca.ival -= ( ca.ival < 0 ? -units : units );

	return ca.rval;
}


static FOUNDATION_FORCEINLINE FOUNDATION_CONSTCALL real math_realinc( real val, int units )
{
	real_cast_t ca; ca.rval = val;

	ca.ival += ( ca.ival < 0 ? -units : units );

	return ca.rval;
}

#endif

#endif

#if FOUNDATION_COMPILER_CLANG
#  pragma clang diagnostic pop
#endif
