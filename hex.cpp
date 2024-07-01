#include <stdio.h>
#include <stdlib.h> 
//A bunch of functions that print or manipulate cstrings
//---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---
//returns the length of a cstring
int lengthOfString(const char* val) {
    return (*val == '\0') ? 0 : 1 + lengthOfString(val + 1);
}

//Uses putchar to print the repeated elements of the summary
void printLetterCode(){
    putchar('[');putchar(' ');putchar('h');putchar(' ');putchar('|');putchar(' ');
    putchar('d');putchar(' ');putchar('|');putchar(' ');putchar('b');putchar(' ');
}

//Prints the summary if input is incorrect
void invalidInput(){
    putchar('U');putchar('s');putchar('a');putchar('g');putchar('e');putchar(':');
    putchar(' ');
    putchar('.');putchar('/');putchar('h');putchar('e');putchar('x');
    putchar(' ');
    printLetterCode();
    putchar(']');
    putchar(' ');
    printLetterCode();
    putchar(']');
    putchar('\n');
    exit(0);
}

//Print the word "decimal"
void printDecimal(){
    putchar('d');putchar('e');putchar('c');putchar('i');putchar('m');putchar('a');putchar('l');
    putchar(' ');
}

//Print hexadecimal
void printHexaDecimal(){
    putchar('h');putchar('e');putchar('x');putchar('a');
    printDecimal();
}

//Print binary
void printBinary(){
    putchar('b');putchar('i');putchar('n');putchar('a');putchar('r');putchar('y');
    putchar(' ');
}

//Print is
void printIs(){
    putchar('i');putchar('s');
    putchar(' ');
}

//Print a cstring
void printCstring(char* string, int length, int count) {
    (count == length) ? putchar(' ') : (putchar(string[count]), printCstring(string, length, count + 1), 0);
}
//---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---PRINTING---




//Converts an int into a hexidecimal. If it works then send to MAIN section, otherwise invalid input
//---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---
void hexOutput(char* from, char* orig){
    ((*from - '0') == 50) ? printBinary() : (((*from - '0') == 52) ? printDecimal() : printHexaDecimal());
    printCstring(orig, lengthOfString(orig), 0);
    printIs();
    printHexaDecimal();
}

//Determines which character to print
char whichHexToPrint(int num){
    return (num == 0) ? ('0') : (
        (num == 1) ? ('1') : (
            (num == 2) ? ('2') : (
                (num == 3) ? ('3') : (
                    (num == 4) ? ('4') : (
                        (num == 5) ? ('5') : (
                            (num == 6) ? ('6') : (
                                (num == 7) ? ('7') : (
                                    (num == 8) ? ('8') : (
                                        (num == 9) ? ('9') : (
                                            (num == 10) ? ('a') : (
                                                (num == 11) ? ('b') : (
                                                    (num == 12) ? ('c') : (
                                                        (num == 13) ? ('d') : (
                                                            (num == 14) ? ('e') : ('f')))))))))))))));
}

//Int to hexidecimal helper
void intToHexHelper(int val, int cap, int currentVal){
    (currentVal < cap) ? ( (cap > val) ?  (putchar(whichHexToPrint(currentVal%16))) : (putchar(whichHexToPrint(currentVal%16)), intToHexHelper(val, cap*16, val), 0) , 0) : (intToHexHelper(val, cap, currentVal/16), 0);
}

//Convert an int into a hex string
//Hexidecimal output prints the fromatting
//Call intToHexHelper, this function will convert int to hexidecimal then print the output, after, returns to main
void intToHex(char* from, char* to, int val, char*orig){
    hexOutput(from, orig);
    intToHexHelper(val, 16, val);
}
//---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---INTEGER_TO_HEX---




//Converts an int into a decimal. If it works then send to MAIN section, otherwise invalid input
//---INTEGER_TO_DECIMAL---INTEGER_TO_DECIMAL---INTEGER_TO_DECIMAL---INTEGER_TO_DECIMAL---INTEGER_TO_DECIMAL---INTEGER_TO_DECIMAL---INTEGER_TO_DECIMAL---INTEGER_TO_DECIMAL---
void decOutput(char* from, char* orig){
    ((*from - '0') == 50) ? printBinary() : (((*from - '0') == 52) ? printDecimal() : printHexaDecimal());
    printCstring(orig, lengthOfString(orig), 0);
    printIs();
    printDecimal();
}

//Determines which character to print
char whichDecToPrint(int num){
    return (num == 0) ? ('0') : (
        (num == 1) ? ('1') : (
            (num == 2) ? ('2') : (
                (num == 3) ? ('3') : (
                    (num == 4) ? ('4') : (
                        (num == 5) ? ('5') : (
                            (num == 6) ? ('6') : (
                                (num == 7) ? ('7') : (
                                    (num == 8) ? ('8') : ('9')))))))));
}

//Int to Decimal helper
void intToDecHelper(int val, int cap, int currentVal){
    (currentVal < cap) ? ( (cap > val) ?  (putchar(whichDecToPrint(currentVal%10))) : (putchar(whichDecToPrint(currentVal%10)), intToDecHelper(val, cap*10, val), 0) , 0) : (intToDecHelper(val, cap, currentVal/10), 0);
}

//Convert an int into a decimal string
//Dec output prints the fromatting
//Call intToDecHelper, this function will convert int to decimal then print the output, after, returns to main
void intToDec(char* from, char* to, int val, char*orig){
    decOutput(from, orig);
    intToDecHelper(val, 10, val);
}
//---INTEGER_TO_DECIMAL---INTEGER_TO_DECIMAL---INTEGER_TO_DECIMAL---INTEGER_TO_DECIMAL---INTEGER_TO_DECIMAL---INTEGER_TO_DECIMAL---INTEGER_TO_DECIMAL---INTEGER_TO_DECIMAL---




//Converts an int into a binary. If it works then send to MAIN section, otherwise invalid input
//---INTEGER_TO_BINARY---INTEGER_TO_BINARY---INTEGER_TO_BINARY---INTEGER_TO_BINARY---INTEGER_TO_BINARY---INTEGER_TO_BINARY---INTEGER_TO_BINARY---INTEGER_TO_BINARY---
void binOutput(char* from, char* orig){
    ((*from - '0') == 50) ? printBinary() : (((*from - '0') == 52) ? printDecimal() : printHexaDecimal());
    printCstring(orig, lengthOfString(orig), 0);
    printIs();
    printBinary();
}

//Determines which character to print
char whichBinToPrint(int num){
    return (num == 1) ? ('1') : ('0');
}

//Int to binary helper
void intToBinHelper(int val, int cap, int currentVal){
    (currentVal < cap) ? ( (cap > val) ?  (putchar(whichBinToPrint(currentVal%2))) : (putchar(whichBinToPrint(currentVal%2)), intToBinHelper(val, cap*2, val), 0) , 0) : (intToBinHelper(val, cap, currentVal/2), 0);
}

//Convert an int into a binary string
//Bin output prints the fromatting
//Call intToBinHelper, this function will convert int to binary then print the output, after, returns to main
void intToBin(char* from, char* to, int val, char*orig){
    binOutput(from, orig);
    intToBinHelper(val, 2, val);
}
//---INTEGER_TO_BINARY---INTEGER_TO_BINARY---INTEGER_TO_BINARY---INTEGER_TO_BINARY---INTEGER_TO_BINARY---INTEGER_TO_BINARY---INTEGER_TO_BINARY---INTEGER_TO_BINARY---




//This section checks the second char and sends the values to the proper conversion function, if invalid, then the invalid input is run
//---CHECK_SECOND_LETTER---CHECK_SECOND_LETTER---CHECK_SECOND_LETTER---CHECK_SECOND_LETTER---CHECK_SECOND_LETTER---CHECK_SECOND_LETTER---CHECK_SECOND_LETTER---CHECK_SECOND_LETTER---
void checkH2(char* from, char* to, int val, char*orig){
    //56 is h, if true, sends to HEXIDECIMAL TO BINARY SECTION
    ((*to - '0') == 56) ? intToHex(from, to, val, orig) : invalidInput();
    
}

void checkD2(char* from, char* to, int val, char*orig){
    //52 is d, if true, sends to INT TO DECIMAL SECTION
    ((*to - '0') == 52) ? intToDec(from, to, val, orig) : checkH2(from, to, val, orig);
    
}

//Determine if the char inputted is valid
//Will check if the char is b, if not then it will move onto the function that checks for h, then the function for d, if it doesnt match then the error message will be displayed
void checkB2(char* from, char* to, int val, char*orig){
    //The char can be either b h d, anything else will result in an error
    //50 is b, if true, sends to INT TO BINARY SECTION
    ((*to - '0') == 50) ? intToBin(from, to, val, orig) : checkD2(from, to, val, orig);
}
//---CHECK_SECOND_LETTER---CHECK_SECOND_LETTER---CHECK_SECOND_LETTER---CHECK_SECOND_LETTER---CHECK_SECOND_LETTER---CHECK_SECOND_LETTER---CHECK_SECOND_LETTER---CHECK_SECOND_LETTER---




//Below are functions used in type to int calculations
//---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---
//Multiplies 2 to the power of any num that many times
int twoToThePower(char* val, int count){
    return (count == 0)? 1 : 2 * twoToThePower(val, count - 1);
}

//multiplies num by 10 count times
int tenTimes(int count, int num){
    return (count == 0)? num : 10 * tenTimes(count - 1, num);
}

//Decodes the proper int value from the hex letters cap and lower
int hexLetterDecoder(char character){
    return ((int)character >= 97 && (int)character <= 102) ? ((int)character - 87) : ((int)character - 55);
}

//returns the hexidecimal integer equivalent
int hexDecoder(char character){
    return ((int)character >= 48 && (int)character <= 57) ? ((int)character - '0') : (hexLetterDecoder(character));
}

//multiplies the value by its 16 to the power of its index
int sixteenTimes(int count, int num){
    return (count == 0)? num : 16 * sixteenTimes(count - 1, num);
}
//---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---MATH_OPERATORS---




//Converts a hexidecimal number to an int. If it works then send to CHECK SECOND LETTER section, otherwise invalid input
//---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---
void checkHex(int len, int count, char* val){
    ((count == len) || (val[count] != '0' && val[count] != '1' && val[count] != '2' && val[count] != '3' && val[count] != '4' && val[count]
    != '5' && val[count] != '6' && val[count] != '7' && val[count] != '8' && val[count] != '9' && val[count] != 'a' && val[count] != 'b' && val[count] != 'c' 
    && val[count] != 'd' && val[count] != 'e' && val[count] != 'f' && val[count] != 'A' && val[count] != 'B' && val[count] != 'C' && val[count] != 'D' 
    && val[count] != 'E' && val[count] != 'F')) ? ((val[count] != '0' && val[count]!= '1' && val[count] != '2' && val[count] != '3' 
    && val[count] != '4' && val[count] != '5' && val[count] != '6'&& val[count] != '7' && val[count] != '8' && val[count] != '9' && val[count] != 'a' 
    && val[count] != 'b' && val[count] != 'c' && val[count] != 'd' && val[count] != 'e' && val[count] != 'f' && val[count] != 'A' && val[count] != 'B' 
    && val[count] != 'C' && val[count] != 'D' && val[count] != 'E' && val[count] != 'F' && val[count] != '\0') ? invalidInput() : 
    (void)0 ) : checkHex(len, count + 1, val);
}

//Recursively iterates through the cstring, multiply the value by sixteen to the power of the index and add to the final total
int hexToIntHelper(int length, int count, char* val){
    return (length == count) ? 0 : sixteenTimes(count - length - 1, hexDecoder(val[length])) + hexToIntHelper(length + 1, count, val);
}

//Convert a hex string to an int
//Check Hexidecimal makes sure that the cstring is only made up of valid characters
//Call Check B2 (CHECK SECOND LETTER section), in the arguments call hexToIntHelper which converts the hexidecimal to an int
void hexToInt(char* from, char* to, char* val){
    checkHex(lengthOfString(val), 0, val);
    checkB2(from, to, hexToIntHelper(0, lengthOfString(val) , val), val);
}
//---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---HEX_TO_INT---




//Converts a decimal number to an int. If it works then send to CHECK SECOND LETTER section, otherwise invalid input
//---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---
void checkDecimal(int len, int count, char* val){
    ((count == len) || (val[count] != '0' && val[count] != '1' && val[count] != '2' && val[count] != '3' && val[count] != '4' && val[count]
    != '5' && val[count] != '6' && val[count] != '7' && val[count] != '8' && val[count] != '9')) 
    ? ((val[count] != '0' && val[count]!= '1' && val[count] != '2' && val[count] != '3' && val[count] != '4' && val[count] != '5' && val[count] != '6'
    && val[count] != '7' && val[count] != '8' && val[count] != '9' && val[count] != '\0') ? invalidInput() : (void)0 ) : checkDecimal(len, count + 1, val);
}

//Recursively iterates through the cstring, multiply the value by ten to the power of the index and add to the final total
int decToIntHelper(int start, int count, char* val){
    return (start == count) ? 0 : tenTimes(count - start - 1, (int)(val[start] - '0')) + decToIntHelper(start + 1, count, val);
}

//Convert a decimal string to an int
//Check Decimal makes sure that the cstring is only made up of valid characters
//Call Check B2 (CHECK SECOND LETTER section), in the arguments call decToIntHelper which converts the decimal to an int
void decToInt(char* from, char* to, char* val){
    checkDecimal(lengthOfString(val), 0, val);
    checkB2(from, to, decToIntHelper(0, lengthOfString(val) , val), val);
}
//---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---DECIMAL_TO_INT---




//Converts a binary number to an int. If it works then send to CHECK SECOND LETTER section, otherwise invalid input
//---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---
void checkBinary(int len, int count, char* val){
    ((count == len) || (val[count] != '0' && val[count] != '1')) ? ((val[count] != '0' && val[count]!= '1' && val[count] != '\0') ? invalidInput() : (void)0 ) : checkBinary(len, count + 1, val);
}

//Recursively iterates through the cstring, if the value is 1, multiply by two to the power of the index and add to the final total
int binToIntHelper(int start, int count, char* val) {
    return ((val[start] == '\0') ? 0 : ((val[start] == '1') ? (twoToThePower(val, count)) : 0) + binToIntHelper(start + 1,count - 1, val));
}

//Convert a binary string to an int
//Check Binary makes sure that the cstring is only made up of valid characters
//Call Check B2 (CHECK SECOND LETTER section), in the arguments call binToIntHelper which converts the binary to an int
void binToInt(char* from, char* to, char* val){
    checkBinary(lengthOfString(val), 0, val);
    checkB2(from, to, binToIntHelper(0, lengthOfString(val) , val)/2, val);
}
//---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---BINARY_TO_INT---




//This section checks the first char and sends the values to the proper conversion function, if invalid, then the invalid input is run
//---CHECK_FIRST_LETTER---CHECK_FIRST_LETTER---CHECK_FIRST_LETTER---CHECK_FIRST_LETTER---CHECK_FIRST_LETTER---CHECK_FIRST_LETTER---CHECK_FIRST_LETTER---CHECK_FIRST_LETTER---
void checkH1(char* from, char* to, char* val){
    //56 is h, if true, sends to HEX TO INT SECTION
    (((*from - '0') == 56) && ((*to - '0') == 50 || (*to - '0') == 52 || (*to - '0') == 56)) ? hexToInt(from, to, val) : invalidInput();
    
}

void checkD1(char* from, char* to, char* val){
    //52 is d, if true, sends to DECIMAL TO INT SECTION
    (((*from - '0') == 52) && ((*to - '0') == 50 || (*to - '0') == 52 || (*to - '0') == 56)) ? decToInt(from, to, val) : checkH1(from, to, val);
    
}

//Determine if the char inputted is valid
//Will check if the char is b, if not then it will move onto the function that checks for h, then the function for d, if it doesnt match then the error message will be displayed
void checkB1(char* from, char* to, char* val){
    //The char can be either b h d, anything else will result in an error
    //50 is b, if true, sends to BINARY TO INT SECTION
    (((*from - '0') == 50) && ((*to - '0') == 50 || (*to - '0') == 52 || (*to - '0') == 56)) ? binToInt(from, to, val) : checkD1(from, to, val);
}
//---CHECK_FIRST_LETTER---CHECK_FIRST_LETTER---CHECK_FIRST_LETTER---CHECK_FIRST_LETTER---CHECK_FIRST_LETTER---CHECK_FIRST_LETTER---CHECK_FIRST_LETTER---CHECK_FIRST_LETTER---




int main(int commandArgs, char* argArr[]){
    //Take in files in this format: 
    //A character that shows what the initial format is (h, d, b)
    //Another character telling what to convert to
    //A string of digits representing the number we are converting from
    // Usage: ./hex [ h | d | b ] [ h | d | b]

    //Checks that the array only has three elements in it, if it doesn't then prints the proper input format
    //If the proper number of arguments exist, then checkB will run (CHECK FIRST LETTER SECTION)
    (commandArgs == 4) ? checkB1(argArr[1], argArr[2], argArr[3]) : invalidInput();
    putchar('\n');

    return 0;
}