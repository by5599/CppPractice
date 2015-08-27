#ifndef LC_CHAPTER3_H
#define LC_CHAPTER3_H

#include "LC0303StringToIntegeratoi008.h"
#include "LC0301ValidPalindrome.h"
#include "LC0302strStr.h"
#include "LC0304AddBinary.h"
#include "LC0305LongestPalindromicSubstring.h"
#include "LC0308LongestCommonPrefix.h"
#include "LC0310IntegerToRoman.h"
#include "LC0311RomanToInteger.h"
#include "LC0312CountAndSay.h"
#include "LC0313Anagrams.h"
#include "LC0314SimplifyPath.h"
#include "LC0315LengthOfLastWord.h"

void doChapter3()
{
   std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Chapter 3\n";
   doLC33atoi();
   doLC0301ValidPalindrome();
   doLC0302strStr();
   doLC0304AddBinary();
   doLC0305LongestPalindromicSubstring();
   doLC0308LongestCommonPrefix();
   doLC0310IntegerToRoman();
   doLC0311RomanToInteger();
   doLC0312CountAndSay();
   doLC0313Anagrams();
   doLC0314SimplifyPath();
   doLC0315LengthOfLastWord();
}

#endif
