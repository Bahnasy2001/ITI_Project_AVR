/*
 * STD_TYPES.h
 *
 * Created: 8/25/2023 9:53:20 AM
 *  Author: Pc
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/************************************************************************/
/*			               signed data types	                        */
/************************************************************************/
typedef signed char   s8;
typedef signed short int  s16;
typedef signed long int   s32;
typedef signed long long int s64;
typedef float f32;
typedef double f64;

/************************************************************************/
/*                           unsigned data types                        */
/************************************************************************/
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;
/************************************************************************/
/*                    volatile data types                                    */
/************************************************************************/

typedef volatile signed char   vs8;
typedef volatile signed short int vs16;
typedef volatile signed long int   vs32;
typedef volatile signed long long int vs64;
typedef volatile float vf32;
typedef volatile double vf64;

typedef volatile unsigned char vu8;
typedef volatile unsigned short int vu16;
typedef volatile unsigned long int vu32;
typedef volatile unsigned long long int vu64;

#endif /* STD_TYPES_H_ */