
# pragma once

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


#define LINE   	std::cout << "-----------------" << std::endl

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

// Bold colors
#define B_RED    "\033[1;31m"
#define B_GREEN  "\033[1;32m"
#define B_YELLOW "\033[1;33m"
#define B_BLUE   "\033[1;34m"



//tester DIR_________________________________________________________
//base_tests
void subject_arr(int n);
void subject(void);
void wrongSubject(void);
void destructorTest(void);
void typeTest(void);

//copy_tests.c
void copyTest(void);
void derivedClassCopyConsTest(void);
void derivedClassCopyAssignTest(void);
void deepCopyTest();
void deepCopyTestWrong();



//utils.c
void deleteAnimals(const Animal *p1, const Animal *p2, const Animal *p3);
void coutTestName(std::string test);
