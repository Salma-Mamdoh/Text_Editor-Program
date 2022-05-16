#include <iostream>
#include "CS112-203-2nd-s15,16-20210162-20210254-20211014-A4-TextEditorFunc.h"
#include <fstream> //file stream
#include <string>
#include<cstring>

int main()
{
	text c1;
    cout << "Hallo in our Text editor programm :)" << endl;
    cout << "enter file name : \n";
    cin >> c1.file;
   c1.check(c1.file);
START:
   c1.choose_menu();
   cin >> c1.choose;

   if (c1.choose == 16) {
       return 0;
   }
   else if (c1.choose == 1) {
       c1.filter_1(c1.file);
   }
   else if (c1.choose == 2) {
      c1. filter_2(c1.file);
   }
   else if (c1.choose == 3) {
       c1.filter_3(c1.file);
   }
   else if (c1.choose == 4) {
       c1.filter_4(c1.file);
   }
   else if (c1.choose == 5) {
       c1.filter_5(c1.file);
   }

   else if (c1.choose == 6) {
       c1.filter_6(c1.file);
   }

   else if (c1.choose == 7) {
       c1.filter_7(c1.file, c1.counter, c1.str);
   }

   else if (c1.choose == 8) {
       c1.filter_8(c1.file, c1.counter, c1.str);
   }

   else if (c1.choose == 9) {
      c1.filter_9(c1.file, c1.counter);
   }

   else if (c1.choose == 10) {
       c1.filter_10(c1.file, c1.str);
   }
   else if (c1.choose == 11) {
       c1.filter_11(c1.file);
   }
   else if (c1.choose == 12) {
       c1.filter_12(c1.file);
   }
   else if (c1.choose == 13) {
       c1.filter_13(c1.file);
   }
   else if (c1.choose == 14) {
       c1.filter_14(c1.file, c1.str);
   }
   else if (c1.choose == 15) {
       c1.filter_15(c1.file);
   }

   goto START;

}
