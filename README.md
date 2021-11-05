# Arduino Matrix
Arduino proyect using the 1088AS LED matrix module. 

1088AS is an 8X8 red LED module. It is a modular component, meaning you can join as many modules as you like.

## Install libraries
I use few libraries depending on witch progarms you decide to use.

- LedControl
	- matrix1.ino
	- matrix2.ino
	- matrix2_reverse.ino
	- matrix3.ino
	- matrix4.ino
- MD_MAX72XX and MD_Parola
	- matrix5.ino
	- matrix6.ino
## Hardware
I'm using an arduino UNO (for programs that use MD_MAX and MD_Parola it maters what model your using) and a 4 module of the 1088AS.

### The Schema:

![Schema](https://3.bp.blogspot.com/-mNKvbYvhsQA/WtFbclO87xI/AAAAAAAABjE/oJv2TXM0h8MAclWYh_nsEuCTj_BEz_IqwCLcBGAs/s1600/MAX7219%2BDot%2BMatrix%2B4-in-1%2B8x32%2Bdot%2Bmatrix%2Bcommon%2Bcathode.jpg)

This schema uses the same ports I use in my code.

DIN -> 11

CS -> 10

CLK -> 13