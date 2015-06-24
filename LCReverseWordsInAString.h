#ifndef LC_REVERSE_WORDS_IN_A_STRING_H
#define LC_REVERSE_WORDS_IN_A_STRING_H

#include "Common.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>

/**********************************************************************************
*
* Given an input string, reverse the string word by word.
*
* For example,
* Given s = "the sky is blue",
* return "blue is sky the".
*
*
* Clarification:
*
* What constitutes a word?
* A sequence of non-space characters constitutes a word.
* Could the input string contain leading or trailing spaces?
* Yes. However, your reversed string should not contain leading or trailing spaces.
* How about multiple spaces between two words?
* Reduce them to a single space in the reversed string.
*
**********************************************************************************/


/************
[Medium]
Time Complexity O(n), Space Complexity O(n)
To remember:
1. Use a map
2. Extend the finding and set the flag
3.
************/

class SolutionReverseString
{
public:
   static void reverseWords(std::string &s) {
      bool wordStart = false;
      std::vector<std::string> v;
      const char *pHead =s.c_str();
      const char *pStr, *pBegin, *pEnd;
      for (pStr=pHead; *pStr!='\0'; pStr++) {
         if (!isspace(*pStr) && wordStart == false){
            wordStart = true;
            pBegin = pStr;
            continue;
         }
         if(isspace(*pStr) && wordStart==true){
            wordStart=false;
            pEnd = pStr;
            v.insert(v.begin(), s.substr(pBegin-pHead, pEnd-pBegin) );
         }
      }

      if (wordStart==true){
         pEnd = pStr;
         v.insert(v.begin(), s.substr(pBegin-pHead, pEnd-pBegin) );
      }

      if (v.size()>0){
         s.clear();
         char space=' ';
         std::vector<std::string>::iterator it;
         for (it=v.begin(); it!=v.end(); ++it) {
            s += *it;
            if (*it != v.back())
               s += space;
         }
      }else{
         s.clear();
      }
      std::cout << "[" << s << "]" << std::endl;
   }
};

void doLCReverseString()
{
   std::string a = "i love cpp";

   std::cout << "---------------------------------\n";
   std::cout << "Reverse Words in a String:\n";
   std::cout << "The string: " << a < "\n";

   SolutionReverseString::reverseWords(a);

}

#endif
