#ifndef __TFT_ILI9163C_CPU_H
	#define __TFT_ILI9163C_CPU_H
	#include <stdint.h>

	#if defined(ESP8266)
		#define _smCharType	uint8_t
		#if defined(SPI_HAS_TRANSACTION)
			static const uint32_t TFT_ILI9163C_SPI_SPEED 	= 80000000;
		#endif
	#elif defined(__AVR__)
		#include <avr/pgmspace.h>
		#define _FORCE_PROGMEM__
		#define _smCharType	uint8_t
		#if defined(SPI_HAS_TRANSACTION)
			static const uint32_t TFT_ILI9163C_SPI_SPEED 	= 8000000;
		#endif
	#elif defined(__SAM3X8E__)
		#include <include/pio.h>
		#define _FORCE_PROGMEM__
		#define PROGMEM
		#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
		#define pgm_read_word(addr) (*(const unsigned short *)(addr))
		typedef unsigned char prog_uchar;
		#define _smCharType	unsigned char
		#if defined(SPI_HAS_TRANSACTION)
			const uint32_t TFT_ILI9163C_SPI_SPEED 			= 24000000;
		#endif
	#elif defined(__MKL26Z64__)	|| defined(__MK20DX128__) || defined(__MK20DX256__)
		//#include <avr/pgmspace.h>
		//#define _FORCE_PROGMEM__
		#define _smCharType	unsigned char
		static const uint32_t TFT_ILI9163C_SPI_SPEED 		= 30000000;
	#else
		#define _smCharType	uint8_t
		#if defined(SPI_HAS_TRANSACTION)
			static const uint32_t TFT_ILI9163C_SPI_SPEED 	= 8000000;
		#endif
	#endif

	#if defined(_FORCE_PROGMEM__)
		template <typename T> void PROGMEM_read (const T * sce, T& dest) { memcpy_P(&dest, sce, sizeof(T)); }
	#endif
#endif
