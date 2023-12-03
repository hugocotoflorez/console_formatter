void place_cursor(int x , int y)
{
    printf("\033[%d;%dH", y, x);
}

void move_cursor_above(int lines)
{
    printf("\033[%dA", lines);
}

void move_cursor_left(int lines)
{
    printf("\033[%dH", lines);
}

//linea anterior
void cursor_up(int n)
{
    printf("\033[%dA", n);
}

//linea anterior
void cursor_up_reset(int n)
{
    printf("\033[%dF", n);
}

//siguiente linea
void cursor_down(int n)
{
    printf("\033[%dB", n);
}

//principio siguiente linea 
void cursor_down_reset(int n)
{
    printf("\033[%dE", n);
}

void cursor_right(int n)
{
    printf("\033[%dC", n);
}

void cursor_right_reset(int n)
{
    printf("\033[%dG", n);
}

void cursor_back(int n)
{
    printf("\033[%dD", n);
}

void newline(int amount)
{
    printf("\033[%dE", amount);
}

void carriage_return()
{
    printf("\033[M");
}

void clear_screen()
{
    printf("\033[H\033[J");
}

void bell()
{
    printf("\033[G");
}

//Shows the cursor, from the VT220.
void cursor_show()
{
    printf("\033[?25h");
}
//Hides the cursor.
void cursor_hide()
{
    printf("\033[?25l");
}

/*
^J	0x0A	LF	Line Feed	Moves to next line, scrolls the display up if at bottom of the screen. Usually does not move horizontally, though programs should not rely on this.
^L	0x0C	FF	Form Feed	Move a printer to top of next page. Usually does not move horizontally, though programs should not rely on this. Effect on video terminals varies.
ESC N	0x8E	SS2	Single Shift Two	Select a single character from one of the alternative character sets. SS2 selects the G2 character set, and SS3 selects the G3 character set.[16] In a 7-bit environment, this is followed by one or more GL bytes (0x20–0x7F) specifying a character from that set.[15]: 9.4  In an 8-bit environment, these may instead be GR bytes (0xA0–0xFF).[15]: 8.4 
ESC O	0x8F	SS3	Single Shift Three
ESC P	0x90	DCS	Device Control String	Terminated by ST.[5]: 5.6  Xterm's uses of this sequence include defining User-Defined Keys, and requesting or setting Termcap/Terminfo data.[16]
ESC [	0x9B	CSI	Control Sequence Introducer	Starts most of the useful sequences, terminated by a byte in the range 0x40 through 0x7E.[5]: 5.4 
ESC \	0x9C	ST	String Terminator	Terminates strings in other controls.[5]: 8.3.143 
ESC ]	0x9D	OSC	Operating System Command	Starts a control string for the operating system to use, terminated by ST.[5]: 8.3.89 
ESC X	0x98	SOS	Start of String	Takes an argument of a string of text, terminated by ST.[5]: 5.6  The uses for these string control sequences are defined by the application[5]: 8.3.2, 8.3.128  or privacy discipline.[5]: 8.3.94  These functions are rarely implemented and the arguments are ignored by xterm.[16] Some Kermit clients allow the server to automatically execute Kermit commands on the client by embedding them in APC sequences; this is a potential security risk if the server is untrusted.[17]
ESC ^	0x9E	PM	Privacy Message
ESC _	0x9F	APC	Application Program Command
CSI n A	CUU	Cursor Up	Moves the cursor n (default 1) cells in the given direction. If the cursor is already at the edge of the screen, this has no effect.
CSI n ; m H	CUP	Cursor Position	Moves the cursor to row n, column m. The values are 1-based, and default to 1 (top left corner) if omitted. A sequence such as CSI ;5H is a synonym for CSI 1;5H as well as CSI 17;H is the same as CSI 17H and CSI 17;1H
CSI n J	ED	Erase in Display	Clears part of the screen. If n is 0 (or missing), clear from cursor to end of screen. If n is 1, clear from cursor to beginning of the screen. If n is 2, clear entire screen (and moves cursor to upper left on DOS ANSI.SYS). If n is 3, clear entire screen and delete all lines saved in the scrollback buffer (this feature was added for xterm and is supported by other terminal applications).
CSI n K	EL	Erase in Line	Erases part of the line. If n is 0 (or missing), clear from cursor to the end of the line. If n is 1, clear from cursor to beginning of the line. If n is 2, clear entire line. Cursor position does not change.
CSI n S	SU	Scroll Up	Scroll whole page up by n (default 1) lines. New lines are added at the bottom. (not ANSI.SYS)
CSI n T	SD	Scroll Down	Scroll whole page down by n (default 1) lines. New lines are added at the top. (not ANSI.SYS)
CSI n ; m f	HVP	Horizontal Vertical Position	Same as CUP, but counts as a format effector function (like CR or LF) rather than an editor function (like CUD or CNL). This can lead to different handling in certain terminal modes.[5]: Annex A 
CSI n m	SGR	Select Graphic Rendition	Sets colors and style of the characters following this code
CSI 5i		AUX Port On	Enable aux serial port usually for local serial printer
CSI 4i		AUX Port Off	Disable aux serial port usually for local serial printer

CSI 6n	DSR	Device Status Report	Reports the cursor position (CPR) by transmitting ESC[n;mR, where n is the row and m is the column.
Some popular private sequences
Code	Abbr	Name	Effect
CSI s	SCP, SCOSC	Save Current Cursor Position	Saves the cursor position/state in SCO console mode.[18] In vertical split screen mode, instead used to set (as CSI n ; n s) or reset left and right margins.[19]
CSI u	RCP, SCORC	Restore Saved Cursor Position	Restores the cursor position/state in SCO console mode.[20]
CSI ? 1004 h			Enable reporting focus. Reports whenever terminal emulator enters or exits focus as ESC [I and ESC [O, respectively.
CSI ? 1004 l			Disable reporting focus.
CSI ? 1049 h			Enable alternative screen buffer, from xterm
CSI ? 1049 l			Disable alternative screen buffer, from xterm
CSI ? 2004 h			Turn on bracketed paste mode.[21] In bracketed paste mode, text pasted into the terminal will be surrounded by ESC [200~ and ESC [201~; programs running in the terminal should not treat characters bracketed by those sequences as commands (Vim, for example, does not treat them as commands).[22] From xterm[23]
CSI ? 2004 l			Turn off bracketed paste mode.
SGR (Select Graphic Rendition) parameters
The control sequence CSI n m, named Select Graphic Rendition (SGR), sets display attributes. Several attributes can be set in the same sequence, separated by semicolons.[24] Each display attribute remains in effect until a following occurrence of SGR resets it.[5] If no codes are given, CSI m is treated as CSI 0 m (reset / normal).

n	Name	Note
0	Reset or normal	All attributes become turned off
1	Bold or increased intensity	As with faint, the color change is a PC (SCO / CGA) invention.[25][better source needed]
2	Faint, decreased intensity, or dim	May be implemented as a light font weight like bold.[26]
3	Italic	Not widely supported. Sometimes treated as inverse or blink.[25]
4	Underline	Style extensions exist for Kitty, VTE, mintty, iTerm2 and Konsole.[27][28][29]
5	Slow blink	Sets blinking to less than 150 times per minute
6	Rapid blink	MS-DOS ANSI.SYS, 150+ per minute; not widely supported
7	Reverse video or invert	Swap foreground and background colors; inconsistent emulation[30][dubious – discuss]
8	Conceal or hide	Not widely supported.
9	Crossed-out, or strike	Characters legible but marked as if for deletion. Not supported in Terminal.app.
10	Primary (default) font	
11–19	Alternative font	Select alternative font n − 10
20	Fraktur (Gothic)	Rarely supported
21	Doubly underlined; or: not bold	Double-underline per ECMA-48,[5]: 8.3.117  but instead disables bold intensity on several terminals, including in the Linux kernel's console before version 4.17.[31]
22	Normal intensity	Neither bold nor faint; color changes where intensity is implemented as such.
23	Neither italic, nor blackletter	
24	Not underlined	Neither singly nor doubly underlined
25	Not blinking	Turn blinking off
26	Proportional spacing	ITU T.61 and T.416, not known to be used on terminals
27	Not reversed	
28	Reveal	Not concealed
29	Not crossed out	
30–37	Set foreground color	
38	Set foreground color	Next arguments are 5;n or 2;r;g;b
39	Default foreground color	Implementation defined (according to standard)
40–47	Set background color	
48	Set background color	Next arguments are 5;n or 2;r;g;b
49	Default background color	Implementation defined (according to standard)
50	Disable proportional spacing	T.61 and T.416
51	Framed	Implemented as "emoji variation selector" in mintty.[32]
52	Encircled
53	Overlined	Not supported in Terminal.app
54	Neither framed nor encircled	
55	Not overlined	
58	Set underline color	Not in standard; implemented in Kitty, VTE, mintty, and iTerm2.[27][28] Next arguments are 5;n or 2;r;g;b.
59	Default underline color	Not in standard; implemented in Kitty, VTE, mintty, and iTerm2.[27][28]
60	Ideogram underline or right side line	Rarely supported
61	Ideogram double underline, or double line on the right side
62	Ideogram overline or left side line
63	Ideogram double overline, or double line on the left side
64	Ideogram stress marking
65	No ideogram attributes	Reset the effects of all of 60–64
73	Superscript	Implemented only in mintty[32]
74	Subscript
75	Neither superscript nor subscript
90–97	Set bright foreground color	Not in standard; originally implemented by aixterm[16]
100–107	Set bright background color
Colors
3-bit and 4-bit
The original specification only had 8 colors, and just gave them names. The SGR parameters 30–37 selected the foreground color, while 40–47 selected the background. Quite a few terminals implemented "bold" (SGR code 1) as a brighter color rather than a different font, thus providing 8 additional foreground colors. Usually you could not get these as background colors, though sometimes inverse video (SGR code 7) would allow that. Examples: to get black letters on white background use ESC[30;47m, to get red use ESC[31m, to get bright red use ESC[1;31m. To reset colors to their defaults, use ESC[39;49m (not supported on some terminals), or reset all attributes with ESC[0m. Later terminals added the ability to directly specify the "bright" colors with 90–97 and 100–107.

When hardware started using 8-bit digital-to-analog converters (DACs) several pieces of software assigned 24-bit color numbers to these names. The chart below shows the default values sent to the DAC for some common hardware and software; in most cases they are configurable.[citation needed]

FG	BG	Name	VGA[b]	Windows XP
Console[c]	Windows
PowerShell 6[d]	Visual Studio Code[e]	Windows 10
Console[f]	Terminal.app	PuTTY	mIRC	xterm	Ubuntu[g]	Eclipse Terminal
30	40	Black	0, 0, 0	12, 12, 12	0, 0, 0	1, 1, 1	0, 0, 0
31	41	Red	170, 0, 0	128, 0, 0	205, 49, 49	197, 15, 31	194, 54, 33	187, 0, 0	127, 0, 0	205, 0, 0	222, 56, 43	205, 0, 0
32	42	Green	0, 170, 0	0, 128, 0	13, 188, 121	19, 161, 14	37, 188, 36	0, 187, 0	0, 147, 0	0, 205, 0	57, 181, 74	0, 205, 0
33	43	Yellow	170, 85, 0[h]	128, 128, 0	238, 237, 240	229, 229, 16	193, 156, 0	173, 173, 39	187, 187, 0	252, 127, 0	205, 205, 0	255, 199, 6	205, 205, 0
34	44	Blue	0, 0, 170	0, 0, 128	36, 114, 200	0, 55, 218	73, 46, 225	0, 0, 187	0, 0, 127	0, 0, 238[34]	0, 111, 184	0, 0, 238
35	45	Magenta	170, 0, 170	128, 0, 128	1, 36, 86	188, 63, 188	136, 23, 152	211, 56, 211	187, 0, 187	156, 0, 156	205, 0, 205	118, 38, 113	205, 0, 205
36	46	Cyan	0, 170, 170	0, 128, 128	17, 168, 205	58, 150, 221	51, 187, 200	0, 187, 187	0, 147, 147	0, 205, 205	44, 181, 233	0, 205, 205
37	47	White	170, 170, 170	192, 192, 192	229, 229, 229	204, 204, 204	203, 204, 205	187, 187, 187	210, 210, 210	229, 229, 229	204, 204, 204	229, 229, 229
90	100	Bright Black (Gray)	85, 85, 85	128, 128, 128	102, 102, 102	118, 118, 118	129, 131, 131	85, 85, 85	127, 127, 127	127, 127, 127	128, 128, 128	0, 0, 0
91	101	Bright Red	255, 85, 85	255, 0, 0	241, 76, 76	231, 72, 86	252, 57, 31	255, 85, 85	255, 0, 0
92	102	Bright Green	85, 255, 85	0, 255, 0	35, 209, 139	22, 198, 12	49, 231, 34	85, 255, 85	0, 252, 0	0, 255, 0
93	103	Bright Yellow	255, 255, 85	255, 255, 0	245, 245, 67	249, 241, 165	234, 236, 35	255, 255, 85	255, 255, 0
94	104	Bright Blue	85, 85, 255	0, 0, 255	59, 142, 234	59, 120, 255	88, 51, 255	85, 85, 255	0, 0, 252	92, 92, 255[35]	0, 0, 255	92, 92, 255
95	105	Bright Magenta	255, 85, 255	255, 0, 255	214, 112, 214	180, 0, 158	249, 53, 248	255, 85, 255	255, 0, 255
96	106	Bright Cyan	85, 255, 255	0, 255, 255	41, 184, 219	97, 214, 214	20, 240, 240	85, 255, 255	0, 255, 255
97	107	Bright White	255, 255, 255	229, 229, 229	242, 242, 242	233, 235, 235	255, 255, 255

*/