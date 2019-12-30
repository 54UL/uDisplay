# SSD1306_OLED_LIB
## What is this?
This is an implementation of an SSD1306 OLED driver for 8051 arch. (specifically AT89S52) and PIC, this library uses hardware and software communication protocols and has low memory footprint, perfect for usage on microcontrollers such as PIC 12, PIC14 family  and 8051 related archs.


## FUNCTIONALITY
the proyect was already ended and the only propouse was achive the minimun functionality. this proyect was only a learning proyect and can help some one else  to make the same thing i did... maybe just for fun? 


## ADVICES 
the c api is kinda hardcoded, sorry for that but i didn't had the time to make it beauty
any contribiutions are well acepeted.

only the pic exclusive lib is working.

if you achive to run the mixed implementation and achive to run it in a 8051 arch, you would have couple problems with the memory in this arch due to the  poor performance of the device and compiler (keli C51 free licence),i tested it in an at89s52 mcu and the only thing i would say is: don't try to make a larger programs with this lib, neither mix it with F.P calculations.


## AUTORS
adafruit: i took the comand table from the arduino library from their ssd1306 implementation.


## Video example
coming soon...
