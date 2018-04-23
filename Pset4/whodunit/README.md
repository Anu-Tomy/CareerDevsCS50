
What's stdint.h?
stdint.h is a header file in the C standard library that allows programmers to write more portable code by providing a set of typedefs that specify exact-width integer types, along with the defined minimum and maximum values for each type, using macros.

What's the point of using uint8_t, uint32_t, int32_t, and uint16_t in a program?
U stands for unsigned integer type.The number refers to the number of bits it can allocate.

How many bytes is a BYTE, a DWORD, a LONG, and a WORD, respectively?
Byte is 8 bits, or 1 byte
DWORD is 32 bits ,or 4 bytes
LONG is 32 bits, or 4 bytes
WORD is 16 bits or 2 bytess

What's the difference between bfSize and biSize?
biSize = the file size in bytes of the header part of a BMP
bfsize = the file size in bytes of the full BMP (including both header and image itself)

What field in BITMAPINFOHEADER specifies the BMP's color depth (i.e., bits per pixel)?
biBitCount

What does fseek do?
Skips over any padding and then looks for the next pixel represented by RGB triple.

What is SEEK_CUR?
This is the current position of the file pointer.
