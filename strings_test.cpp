#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>


void strings_tests() {

char * str_c1 = (char*)"word1";
char str_c2[] = "word2";

printf("my word:\n%s\n%s\n",str_c1, str_c2);
printf("length of null string %ld\n", strlen(str_c1)) ;
/*
 * create string on heap
 */
char * str_c3 = new char[100];
printf(" empty string %s\n",str_c3);
strcat(str_c3, str_c1);
strcat(str_c3, " + ");
strcat(str_c3,   str_c2);

printf("contacanation result %s\n",str_c3);

std::string str1 {str_c1};
std::string str2 {str_c2};
std::cout << "string object contacanation ->" << str1+" - " +str2 << std::endl;

printf("data from string object %s\n", str1.data());

std::cout << "find a part of string " << str1.find("ord") << std::endl;
std::cout << "find not existing part of string " << str1.find("Maja") << std::endl;

str1.at(0) = 'W';
printf("data from string object %s\n", str1.data());

str1.append(" text ");
printf("data from string object %s\n", str1.data());



delete[] str_c3;
}
