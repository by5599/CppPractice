
#include "AlgorithmLinkedList.h"
#include "AlgorithmStack.h"
#include "AlgorithmQueue.h"
#include "AlgorithmTree.h"
#include "AlgorithmSearching.h"
#include "AlgorithmSorting.h"
#include "CppExamples.h"
#include "LCChapter2.h"
#include "LCChapter3.h"
#include "LCChapter4.h"
#include "LCChapter5.h"
#include "LCChapter6.h"
#include "LCChapter7.h"
#include "LCChapter8.h"
#include "LCChapter9.h"
#include "LCChapter10.h"
#include "LCChapter11.h"
#include "LCChapter12.h"
#include "LCChapter13.h"
#include "LCChapter14.h"
#include "LCChapter15.h"
#include "LCChapterOthers.h"
#include "LCReverseWordsInAString.h"

#include <thread>
#include <windows.h>
#include "Common.h"

using namespace std;

void doLinkedListExample1()
{
   LinkedList linkedList;
   linkedList.doLinkedListExample1();
}

void doSorting()
{
   Sorting sorting;
   sorting.doMergeSort();
   sorting.doQuickSort();
   sorting.doBubbleSort();
   sorting.doSelectionSort();
   sorting.doInsertionSort();
}

void doTestSizeOfNoneClass()
{
   cout << sizeof(None) << endl;
   cout << sizeof(Empty) << endl;
   cout << sizeof(PureAbstract) << endl;
   cout << sizeof(Something) << endl;
}

void doCppExample1()
{
   //Base base;
   Base* derived = new Derived();
   derived->func1();
   derived->func2();
   derived->func3();
   derived->func4();

   Base* d2 = new Derived2();
   //d2->func1(1); // this line won't compile
   d2->func3();

   Derived2* d2obj = new Derived2();
   d2obj->func1(1);
   d2obj->func3();
}

void foo(string msg)
{
    cout << "thread1 says: " << msg;
}

void bar(string msg)
{
    cout << "thread2 says: " << msg;
}
void doTestPointer()
{
short s;
short *ps = &s;
char c;
char *pc = &c;
printf("Content of ps before: %d %p %p\n",ps,ps,&ps);
ps = ps + 1;
printf("Content of ps after: %d %p %p\n",ps,ps,&ps);
printf("Content of pc before: %d %p %p\n",pc,pc,&pc);
pc = pc + 1;
printf("Content of pc after: %d %p %p\n",pc,pc,&pc);
printf("sizeof ps is: %d\n", sizeof(*ps));
printf("sizeof pc is: %d\n", sizeof(*pc));
}

void print(const int ia[10])
{
for (size_t i = 0; i != 10; ++i)
cout << ia[i] << endl;
}

#define IGNORE_LEETCODE 1

void doAlgorithms()
{
#if (IGNORE_LEETCODE == 1)
   doChapter2();
   doChapter3();
   doChapter4();
   doChapter5();
   doChapter6();
   doChapter7();
   doChapter8();
   doChapter9();
   doChapter10();
   doChapter11();
   doChapter12();
   doChapter13();
   doChapter14();
   doChapter15();
   doChapterOthers();

   doLCReverseString();
#endif
    doLinkedListExample1();
    //doMergeSort();
    //doCppExample1();
    //doTestSizeOfNoneClass();

   //Searching::doBinarySearch();
   //doSorting();
   //TestStack();
   //TestQueue();
   TestBinaryTree();
}

#define HEADER_LENGTH 12
#define WIFI_BLOCK_SIZE 64
uint16_t WifiCalculateBufferSize(uint16_t dataLength)
{
  uint16_t buffer_size = 0;
  uint8_t  num_of_blocks = 0;

  buffer_size = dataLength + HEADER_LENGTH;
  if (buffer_size % WIFI_BLOCK_SIZE != 0)
  {
    num_of_blocks = (uint16_t)((buffer_size + WIFI_BLOCK_SIZE) / WIFI_BLOCK_SIZE);
    buffer_size = num_of_blocks * WIFI_BLOCK_SIZE;
  }

  return buffer_size;
}

void dummyfunc(void)
{
}

#define AT_COMMAND_STR "AT+YHD=7"
#define _CR_  "\r"
void dumpDebugInfo(void)
{
  char cmd[20] = {0};

  printf("Run AT command: %s\n", AT_COMMAND_STR);
  sprintf(cmd, AT_COMMAND_STR _CR_);
  for (int i = 0; i < 10; i++)
    printf("%02X ", cmd[i]);
  printf("\n");

  printf("AT command: %s Result: OK\n", AT_COMMAND_STR);
}


#define pf(...) printf("%d: ", 30);\
   printf(__VA_ARGS__)

extern void testnoarg(int i, int j);

int getSecretNumber( int maxNum ) {
    int x = rand();
    int y = x % maxNum + 1;
    printf ("%d %d %d\n", maxNum, x, y);
    return y;
}

typedef struct {
    uint8_t major;
    uint8_t minor;
    uint8_t mod;
} VersionInfo;

void parseVersionString(const char *versionStr, VersionInfo *versionInfo)
{
    // Initialize struct fields to 0
    versionInfo->major = 0;
    versionInfo->minor = 0;
    versionInfo->mod = 0;

    // Tokenize the string using "."
    char versionCopy[50];
    strncpy(versionCopy, versionStr, sizeof(versionCopy) - 1);
    versionCopy[sizeof(versionCopy) - 1] = '\0'; // Ensure null-termination

    char *token = strtok(versionCopy, ".");
    if (token != NULL)
    {
        versionInfo->major = (uint8_t)atoi(token);
    }

    token = strtok(NULL, ".");
    if (token != NULL)
    {
        versionInfo->minor = (uint8_t)atoi(token);
    }

    token = strtok(NULL, ".");
    if (token != NULL)
    {
        versionInfo->mod = (uint8_t)atoi(token);
    }
}

int myAtoi(char * str)
{
  int res = 0;

  for (int i = 0; str[i] != '\0'; ++i) res = res*10 + str[i] - '0';

  return res;
}

uint8_t parseVersionString1(const char vstring[], VersionInfo * version)
{

  int len = strlen(vstring);
  static const char delim = '.';
  int delimIndex = -1;
  for (int i = 0; i < len; i++)
  {
    if (vstring[i] == delim)
    {
      delimIndex = i;
      break;
    }
  }

  if (delimIndex < 0)
  {
    return 0;
  }

  char majorStr[10] = {0};
  memcpy(majorStr, vstring, delimIndex);
  majorStr[delimIndex] = 0;
  version->major = myAtoi(majorStr);

  char minorAndModStr[10] = {0};
  int mlen = len - delimIndex - 1;
  memcpy(minorAndModStr, vstring + delimIndex + 1, mlen);

  // check last char to see if it is a mod
  char c = minorAndModStr[mlen-1];

  if (mlen > 1 && isalpha(c))
  {
    version->mod = c;
    minorAndModStr[mlen-1] = 0; // erase the modifier char.
  }
  else
  {
    version->mod = 0;
  }

  version->minor = myAtoi(minorAndModStr);

  return 1;
}

int func(int value)
{
    return value;
}

int func_log(char const* caller, int value)
{
    printf("Called from %s\n", caller);
    return func(value);
}

#define func(x) func_log(__func__, x)

int main()
{
    int i, &ri = i;
    i = 5; ri = 10;
    //std::cout << i << " " << ri << std::endl;

    #if 0
   doTestPointer();
   TestPointers();
   TestDataTypesAndAlignments();
   testConstness();
   test5();
   test6();
   test7();

   doAlgorithms();
   #endif

   uint8_t char1 = 0xA5, char2 = 0x88;
   uint16_t test_char; // = 0xA588;

   //test_char =
   //printf("0X%04X 0X%04X\n", test_char, (uint8_t)test_char);

   uint16_t val = 0x1234;
   uint8_t val1 = (uint8_t)val;
   uint8_t val2 = (uint8_t)((val >>8) & 0x00FF);
   // Print: 34 12
   printf("%02X %02X\n", val1, val2);

   int value = 120;

   int divide_res = (int)((value+64) / 64);
   int res = value % 64;
   printf("value: %d divide_res: %d res: %d\n", value, divide_res, res);

   value = 192;
   divide_res = (int)((value+64) / 64);
   res = value % 64;
   printf("value: %d divide_res: %d res: %d\n", value, divide_res, res);
   printf("value: %d final value: %d\n", 30, WifiCalculateBufferSize(30));
   printf("value: %d final value: %d\n", 63, WifiCalculateBufferSize(63));
   printf("value: %d final value: %d\n", 64, WifiCalculateBufferSize(64));
   printf("value: %d final value: %d\n", 180, WifiCalculateBufferSize(180));
   printf("value: %d final value: %d\n", 243, WifiCalculateBufferSize(243));
   printf("value: %d final value: %d\n", 512, WifiCalculateBufferSize(512));
   printf("value: %d final value: %d\n", 480, WifiCalculateBufferSize(480));

   char arr1[] = "hello world";

   memcpy(arr1, arr1+6, 6);
   printf("%s\n", arr1);
   pf("My value: %d\n", 100);

   dumpDebugInfo();

   if (strstr("AT+RESET=,2,3", "AT+RESET=1") != NULL)
   {
       printf("It includes it\n");
   }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < 5; i++) {
        int x = rand();
        getSecretNumber(x);
        //printf("%d %d\n", x, getSecretNumber(x));
    }

    VersionInfo version;
    const char *versionString1 = "4.2";
    const char *versionString2 = "5.1";

    // Parse first version string
    parseVersionString1(versionString1, &version);
    printf("Version 1: Major = %d, Minor = %d, Mod = %d\n", version.major, version.minor, version.mod);

    // Parse second version string
    parseVersionString1(versionString2, &version);
    printf("Version 2: Major = %d, Minor = %d, Mod = %d\n", version.major, version.minor, version.mod);

    int func_res = func(0);
    if (func_res)
    {
        printf("func result is non-zero\n");
    }
    else
    {
        printf("func result is 0\n");
    }

    func_res = func(2);
    if (func_res)
    {
        printf("func result is non-zero\n");
    }
    else
    {
        printf("func result is 0\n");
    }

   ::system("pause");
   return 0;
}
