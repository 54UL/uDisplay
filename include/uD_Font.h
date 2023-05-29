#ifndef UD_FONT_H
#define UD_FONT_H
//TODO: FIX PROGMEM

#include <stdint.h>
#include <avr/pgmspace.h>

//test defines
// #define UDISPLAY_USE_DEFAULT_FONT
#define UDISPLAY_USE_X_ORG_FONT

//C51 prog mem keyword "code" bypass
#ifndef MEMORY_KEYWORD
#define MEMORY_KEYWORD 
#endif

#if defined(UDISPLAY_LOAD_DEFAULT_FONT)
 //6 x 8 @ 94 characters (default font)
 const uint8_t MEMORY_KEYWORD uD_DefaultFont[] PROGMEM  = 
 {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x2f, 0x00, 0x00, // !
    0x00, 0x00, 0x07, 0x00, 0x07, 0x00, // "
    0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14, // #
    0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12, // $
    0x00, 0x23, 0x13, 0x08, 0x64, 0x62, // %
    0x00, 0x36, 0x49, 0x55, 0x22, 0x50, // &
    0x00, 0x00, 0x05, 0x03, 0x00, 0x00, // '
    0x00, 0x00, 0x1c, 0x22, 0x41, 0x00, // (
    0x00, 0x00, 0x41, 0x22, 0x1c, 0x00, // )
    0x00, 0x14, 0x08, 0x3E, 0x08, 0x14, // *
    0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, // +
    0x00, 0x00, 0x00, 0xA0, 0x60, 0x00, // ,
    0x00, 0x08, 0x08, 0x08, 0x08, 0x08, // -
    0x00, 0x00, 0x60, 0x60, 0x00, 0x00, // .
    0x00, 0x20, 0x10, 0x08, 0x04, 0x02, // /
    0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E, // 0
    0x00, 0x00, 0x42, 0x7F, 0x40, 0x00, // 1
    0x00, 0x42, 0x61, 0x51, 0x49, 0x46, // 2
    0x00, 0x21, 0x41, 0x45, 0x4B, 0x31, // 3
    0x00, 0x18, 0x14, 0x12, 0x7F, 0x10, // 4
    0x00, 0x27, 0x45, 0x45, 0x45, 0x39, // 5
    0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30, // 6
    0x00, 0x01, 0x71, 0x09, 0x05, 0x03, // 7
    0x00, 0x36, 0x49, 0x49, 0x49, 0x36, // 8
    0x00, 0x06, 0x49, 0x49, 0x29, 0x1E, // 9
    0x00, 0x00, 0x36, 0x36, 0x00, 0x00, // :
    0x00, 0x00, 0x56, 0x36, 0x00, 0x00, // ;
    0x00, 0x08, 0x14, 0x22, 0x41, 0x00, // <
    0x00, 0x14, 0x14, 0x14, 0x14, 0x14, // =
    0x00, 0x00, 0x41, 0x22, 0x14, 0x08, // >
    0x00, 0x02, 0x01, 0x51, 0x09, 0x06, // ?
    0x00, 0x32, 0x49, 0x59, 0x51, 0x3E, // @
    0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C, // A
    0x00, 0x7F, 0x49, 0x49, 0x49, 0x36, // B
    0x00, 0x3E, 0x41, 0x41, 0x41, 0x22, // C
    0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C, // D
    0x00, 0x7F, 0x49, 0x49, 0x49, 0x41, // E
    0x00, 0x7F, 0x09, 0x09, 0x09, 0x01, // F
    0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A, // G
    0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F, // H
    0x00, 0x00, 0x41, 0x7F, 0x41, 0x00, // I
    0x00, 0x20, 0x40, 0x41, 0x3F, 0x01, // J
    0x00, 0x7F, 0x08, 0x14, 0x22, 0x41, // K
    0x00, 0x7F, 0x40, 0x40, 0x40, 0x40, // L
    0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F, // M
    0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F, // N
    0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E, // O
    0x00, 0x7F, 0x09, 0x09, 0x09, 0x06, // P
    0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E, // Q
    0x00, 0x7F, 0x09, 0x19, 0x29, 0x46, // R
    0x00, 0x46, 0x49, 0x49, 0x49, 0x31, // S
    0x00, 0x01, 0x01, 0x7F, 0x01, 0x01, // T
    0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F, // U
    0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F, // V
    0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F, // W
    0x00, 0x63, 0x14, 0x08, 0x14, 0x63, // X
    0x00, 0x07, 0x08, 0x70, 0x08, 0x07, // Y
    0x00, 0x61, 0x51, 0x49, 0x45, 0x43, // Z
    0x00, 0x00, 0x7F, 0x41, 0x41, 0x00, // [
    0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, // Backslash (Checker pattern)
    0x00, 0x00, 0x41, 0x41, 0x7F, 0x00, // ]
    0x00, 0x04, 0x02, 0x01, 0x02, 0x04, // ^
    0x00, 0x40, 0x40, 0x40, 0x40, 0x40, // _
    0x00, 0x00, 0x03, 0x05, 0x00, 0x00, // `
    0x00, 0x20, 0x54, 0x54, 0x54, 0x78, // a
    0x00, 0x7F, 0x48, 0x44, 0x44, 0x38, // b
    0x00, 0x38, 0x44, 0x44, 0x44, 0x20, // c
    0x00, 0x38, 0x44, 0x44, 0x48, 0x7F, // d
    0x00, 0x38, 0x54, 0x54, 0x54, 0x18, // e
    0x00, 0x08, 0x7E, 0x09, 0x01, 0x02, // f
    0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C, // g
    0x00, 0x7F, 0x08, 0x04, 0x04, 0x78, // h
    0x00, 0x00, 0x44, 0x7D, 0x40, 0x00, // i
    0x00, 0x40, 0x80, 0x84, 0x7D, 0x00, // j
    0x00, 0x7F, 0x10, 0x28, 0x44, 0x00, // k
    0x00, 0x00, 0x41, 0x7F, 0x40, 0x00, // l
    0x00, 0x7C, 0x04, 0x18, 0x04, 0x78, // m
    0x00, 0x7C, 0x08, 0x04, 0x04, 0x78, // n
    0x00, 0x38, 0x44, 0x44, 0x44, 0x38, // o
    0x00, 0xFC, 0x24, 0x24, 0x24, 0x18, // p
    0x00, 0x18, 0x24, 0x24, 0x18, 0xFC, // q
    0x00, 0x7C, 0x08, 0x04, 0x04, 0x08, // r
    0x00, 0x48, 0x54, 0x54, 0x54, 0x20, // s
    0x00, 0x04, 0x3F, 0x44, 0x40, 0x20, // t
    0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C, // u
    0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C, // v
    0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C, // w
    0x00, 0x44, 0x28, 0x10, 0x28, 0x44, // x
    0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C, // y
    0x00, 0x44, 0x64, 0x54, 0x4C, 0x44, // z
    0x00, 0x00, 0x10, 0x7C, 0x82, 0x00, // {
    0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, // |
    0x00, 0x00, 0x82, 0x7C, 0x10, 0x00, // }
    0x00, 0x00, 0x06, 0x09, 0x09, 0x06  // ~
};
#elif defined (UDISPLAY_USE_X_ORG_FONT)

 //https://gitlab.freedesktop.org/xorg/font/misc-misc/-/blob/master/5x8.bdf
 // 5 x 8 @ 126 characters (default font)
 const uint8_t MEMORY_KEYWORD uD_DefaultFont[] PROGMEM = 
 {
  0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char ' ' (32)
  0x00, 0x00, 0x4f, 0x00, 0x00,  // Code for char '!' (33)
  0x00, 0x07, 0x00, 0x07, 0x00,  // Code for char '"' (34)
  0x14, 0x7f, 0x14, 0x7f, 0x14,  // Code for char '#' (35)
  0x24, 0x2a, 0x7f, 0x2a, 0x12,  // Code for char '$' (36)
  0x23, 0x13, 0x08, 0x64, 0x62,  // Code for char '%' (37)
  0x36, 0x49, 0x55, 0x22, 0x50,  // Code for char '&' (38)
  0x00, 0x05, 0x03, 0x00, 0x00,  // Code for char ''' (39)
  0x00, 0x1c, 0x22, 0x41, 0x00,  // Code for char '(' (40)
  0x00, 0x41, 0x22, 0x1c, 0x00,  // Code for char ')' (41)
  0x14, 0x08, 0x3E, 0x08, 0x14,  // Code for char '*' (42)
  0x08, 0x08, 0x3E, 0x08, 0x08,  // Code for char '+' (43)
  0x00, 0x50, 0x30, 0x00, 0x00,  // Code for char ',' (44)
  0x08, 0x08, 0x08, 0x08, 0x08,  // Code for char '-' (45)
  0x00, 0x60, 0x60, 0x00, 0x00,  // Code for char '.' (46)
  0x20, 0x10, 0x08, 0x04, 0x02,  // Code for char '/' (47)
  0x3E, 0x51, 0x49, 0x45, 0x3E,  // Code for char '0' (48)
  0x00, 0x42, 0x7F, 0x40, 0x00,  // Code for char '1' (49)
  0x42, 0x61, 0x51, 0x49, 0x46,  // Code for char '2' (50)
  0x21, 0x41, 0x45, 0x4B, 0x31,  // Code for char '3' (51)
  0x18, 0x14, 0x12, 0x7F, 0x10,  // Code for char '4' (52)
  0x27, 0x45, 0x45, 0x45, 0x39,  // Code for char '5' (53)
  0x3C, 0x4A, 0x49, 0x49, 0x30,  // Code for char '6' (54)
  0x01, 0x71, 0x09, 0x05, 0x03,  // Code for char '7' (55)
  0x36, 0x49, 0x49, 0x49, 0x36,  // Code for char '8' (56)
  0x06, 0x49, 0x49, 0x29, 0x1E,  // Code for char '9' (57)
  0x00, 0x36, 0x36, 0x00, 0x00,  // Code for char ':' (58)
  0x00, 0x56, 0x36, 0x00, 0x00,  // Code for char ';' (59)
  0x08, 0x14, 0x22, 0x41, 0x00,  // Code for char '<' (60)
  0x14, 0x14, 0x14, 0x14, 0x14,  // Code for char '=' (61)
  0x00, 0x41, 0x22, 0x14, 0x08,  // Code for char '>' (62)
  0x02, 0x01, 0x51, 0x09, 0x06,  // Code for char '?' (63)
  0x32, 0x49, 0x79, 0x41, 0x3E,  // Code for char '@' (64)
  0x7E, 0x11, 0x11, 0x11, 0x7E,  // Code for char 'A' (65)
  0x7F, 0x49, 0x49, 0x49, 0x36,  // Code for char 'B' (66)
  0x3E, 0x41, 0x41, 0x41, 0x22,  // Code for char 'C' (67)
  0x7F, 0x41, 0x41, 0x22, 0x1C,  // Code for char 'D' (68)
  0x7F, 0x49, 0x49, 0x49, 0x41,  // Code for char 'E' (69)
  0x7F, 0x09, 0x09, 0x09, 0x01,  // Code for char 'F' (70)
  0x3E, 0x41, 0x49, 0x49, 0x7A,  // Code for char 'G' (71)
  0x7F, 0x08, 0x08, 0x08, 0x7F,  // Code for char 'H' (72)
  0x00, 0x41, 0x7F, 0x41, 0x00,  // Code for char 'I' (73)
  0x20, 0x40, 0x41, 0x3F, 0x01,  // Code for char 'J' (74)
  0x7F, 0x08, 0x14, 0x22, 0x41,  // Code for char 'K' (75)
  0x7F, 0x40, 0x40, 0x40, 0x40,  // Code for char 'L' (76)
  0x7F, 0x02, 0x0C, 0x02, 0x7F,  // Code for char 'M' (77)
  0x7F, 0x04, 0x08, 0x10, 0x7F,  // Code for char 'N' (78)
  0x3E, 0x41, 0x41, 0x41, 0x3E,  // Code for char 'O' (79)
  0x7F, 0x09, 0x09, 0x09, 0x06,  // Code for char 'P' (80)
  0x3E, 0x41, 0x51, 0x21, 0x5E,  // Code for char 'Q' (81)
  0x7F, 0x09, 0x19, 0x29, 0x46,  // Code for char 'R' (82)
  0x26, 0x49, 0x49, 0x49, 0x32,  // Code for char 'S' (83)
  0x01, 0x01, 0x7F, 0x01, 0x01,  // Code for char 'T' (84)
  0x3F, 0x40, 0x40, 0x40, 0x3F,  // Code for char 'U' (85)
  0x1F, 0x20, 0x40, 0x20, 0x1F,  // Code for char 'V' (86)
  0x7F, 0x20, 0x18, 0x20, 0x7F,  // Code for char 'W' (87)
  0x63, 0x14, 0x08, 0x14, 0x63,  // Code for char 'X' (88)
  0x03, 0x04, 0x78, 0x04, 0x03,  // Code for char 'Y' (89)
  0x61, 0x51, 0x49, 0x45, 0x43,  // Code for char 'Z' (90)
  0x00, 0x00, 0x7F, 0x41, 0x41,  // Code for char '[' (91)
  0x02, 0x04, 0x08, 0x10, 0x20,  // Code for char '\' (92)
  0x41, 0x41, 0x7F, 0x00, 0x00,  // Code for char ']' (93)
  0x04, 0x02, 0x01, 0x02, 0x04,  // Code for char '^' (94)
  0x40, 0x40, 0x40, 0x40, 0x40,  // Code for char '_' (95)
  0x00, 0x01, 0x02, 0x04, 0x00,  // Code for char '`' (96)
  0x20, 0x54, 0x54, 0x54, 0x78,  // Code for char 'a' (97)
  0x7F, 0x44, 0x44, 0x44, 0x38,  // Code for char 'b' (98)
  0x38, 0x44, 0x44, 0x44, 0x44,  // Code for char 'c' (99)
  0x38, 0x44, 0x44, 0x44, 0x7F,  // Code for char 'd' (100)
  0x38, 0x54, 0x54, 0x54, 0x18,  // Code for char 'e' (101)
  0x08, 0x7E, 0x09, 0x09, 0x00,  // Code for char 'f' (102)
  0x18, 0xA4, 0xA4, 0xA4, 0x7C,  // Code for char 'g' (103)
  0x7F, 0x04, 0x04, 0x78, 0x00,  // Code for char 'h' (104)
  0x00, 0x00, 0x7D, 0x40, 0x00,  // Code for char 'i' (105)
  0x40, 0x80, 0x84, 0x7D, 0x00,  // Code for char 'j' (106)
  0x7F, 0x10, 0x28, 0x44, 0x00,  // Code for char 'k' (107)
  0x00, 0x00, 0x7F, 0x40, 0x00,  // Code for char 'l' (108)
  0x7C, 0x04, 0x7C, 0x04, 0x78,  // Code for char 'm' (109)
  0x7C, 0x04, 0x04, 0x78, 0x00,  // Code for char 'n' (110)
  0x38, 0x44, 0x44, 0x44, 0x38,  // Code for char 'o' (111)
  0xFC, 0x24, 0x24, 0x24, 0x18,  // Code for char 'p' (112)
  0x18, 0x24, 0x24, 0x24, 0xFC,  // Code for char 'q' (113)
  0x7C, 0x04, 0x04, 0x04, 0x08,  // Code for char 'r' (114)
  0x48, 0x54, 0x54, 0x54, 0x24,  // Code for char 's' (115)
  0x04, 0x04, 0x3F, 0x44, 0x24,  // Code for char 't' (116)
  0x3C, 0x40, 0x40, 0x20, 0x7C,  // Code for char 'u' (117)
  0x1C, 0x20, 0x40, 0x20, 0x1C,  // Code for char 'v' (118)
  0x3C, 0x40, 0x30, 0x40, 0x3C,  // Code for char 'w' (119)
  0x44, 0x28, 0x10, 0x28, 0x44,  // Code for char 'x' (120)
  0x1C, 0xA0, 0xA0, 0xA0, 0x7C,  // Code for char 'y' (121)
  0x44, 0x64, 0x54, 0x4C, 0x44,  // Code for char 'z' (122)
  0x00, 0x08, 0x36, 0x41, 0x41,  // Code for char '{' (123)
  0x00, 0x00, 0x7F, 0x00, 0x00,  // Code for char '|' (124)
  0x41, 0x41, 0x36, 0x08, 0x00,  // Code for char '}' (125)
  0x10, 0x08, 0x08, 0x10, 0x08,  // Code for char '~' (126)
};

#else
    const uint8_t * DefaultFont;
#endif

#endif /* UD_FONT_H */

