
#include "Fixed.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"


/* overload of the insertion («) operator without "friend key word"
*since the fixed_point_number is private i need to call getRawbits()
*if i wanted to add two Fixed Objects i would put the operator overload in the class
*if i wanted to add 2 different Objects i would use the friend keyword but since its not allowed i do this
*/

std::ostream& operator << (std::ostream& stream, const Fixed& rhs)
{
    stream << rhs.toFloat();
    return (stream);
}

void cout_test_name(const std::string& name)
{
    std::cout << BLUE << name << RESET << std::endl;
}

void passed_msg(const Fixed& lhs, const std::string& operation, const Fixed& rhs)
{
    std::cout << lhs << operation << rhs << ": ✅" << std::endl;
}

void arith_status_msg(const Fixed& lhs, const std::string& operation, const Fixed& rhs,  const Fixed& result, const std::string& status)
{
    std::cout << lhs << operation << rhs << " = " << result;
    std::cout << ": " << status << std::endl;
}

void subject_test(void)
{
    cout_test_name("Subject:");

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
}

void comparison_operators_test_ints(int small, int big)
{
    Fixed const int_small( small );
    Fixed const int_big( big );

    cout_test_name("Comparison_operators_test_ints:");

    if (int_big > int_small)
        passed_msg(int_big, " > ", int_small);
    if (int_big >= int_small)
        passed_msg(int_big, " >= ", int_small);
    if (int_big >= int_big)
        passed_msg(int_big, " >= ", int_big);

    if (int_small < int_big)
        passed_msg(int_small, " < ", int_big);        
    if (int_small <= int_big)
        passed_msg(int_small, " <= ", int_big);        
    if (int_big <= int_big)
        passed_msg(int_big, " <= ", int_big);

    if (int_big == int_big)
        passed_msg(int_big, " == ", int_big);
    if (int_big == int_small) //wont be printed
        std::cout << "❌" << std::endl;

    if (int_big != int_small)
        passed_msg(int_big, " != ", int_small);
    if (int_big != int_big) //wont be printed    
        std::cout << "❌" << std::endl;
}

void comparison_operators_test_floats(float small, float big)
{
    Fixed const int_small( small );
    Fixed const int_big( big );

    cout_test_name("Comparison_operators_test_floats:");

    if (int_big > int_small)
        passed_msg(int_big, " > ", int_small);
    if (int_big >= int_small)
        passed_msg(int_big, " >= ", int_small);
    if (int_big >= int_big)
        passed_msg(int_big, " >= ", int_big);        

    if (int_small < int_big)
        passed_msg(int_small, " < ", int_big);        
    if (int_small <= int_big)
        passed_msg(int_small, " <= ", int_big);        
    if (int_big <= int_big)
        passed_msg(int_big, " <= ", int_big);

    if (int_big == int_big)
        passed_msg(int_big, " == ", int_big);
    if (int_big == int_small)
        std::cout << "❌" << std::endl;

    if (int_big != int_small)
        passed_msg(int_big, " != ", int_small);
    if (int_big != int_big)    
        std::cout << "❌" << std::endl;
}

void arithmatic_operators_test_ints(int num1, int num2)
{
    Fixed const n1( num1 );
    Fixed const n2( num2 );
    
    cout_test_name("Arithmetic_operators_test_ints:");
    if (Fixed (num1 + num2) == n1 + n2)
        arith_status_msg(n1, " + ", n2, n1 + n2, "✅");
    else
        arith_status_msg(n1, " + ", n2, n1 + n2, "❌");
    
    if (Fixed (num1 - num2) == n1 - n2)
        arith_status_msg(n1, " - ", n2, n1 - n2, "✅");
    else
        arith_status_msg(n1, " - ", n2, n1 - n2, "❌");

    if (Fixed (num1 * num2) == n1 * n2)
        arith_status_msg(n1, " * ", n2, n1 * n2, "✅");
    else
        arith_status_msg(n1, " * ", n2, n1 * n2, "❌");

    if (Fixed (num1 / num2) == n1 / n2)
        arith_status_msg(n1, " / ", n2, n1 / n2, "✅");
    else
        arith_status_msg(n1, " / ", n2, n1 / n2, "❌");
}

void arithmatic_operators_test_floats(float num1, float num2)
{
    Fixed const n1( num1 );
    Fixed const n2( num2 );
    
    cout_test_name("Arithmetic_operators_test_floats:");
    if (Fixed (num1 + num2) == n1 + n2)
        arith_status_msg(n1, " + ", n2, n1 + n2, "✅");
    else
        arith_status_msg(n1, " + ", n2, n1 + n2, "❌");
    
    if (Fixed (num1 - num2) == n1 - n2)
        arith_status_msg(n1, " - ", n2, n1 - n2, "✅");
    else
        arith_status_msg(n1, " - ", n2, n1 - n2, "❌");

    if (Fixed (num1 * num2) == n1 * n2)
        arith_status_msg(n1, " * ", n2, n1 * n2, "✅");
    else
        arith_status_msg(n1, " * ", n2, n1 * n2, "❌");
    
    if (Fixed (num1 / num2) == n1 / n2)
        arith_status_msg(n1, " / ", n2, n1 / n2, "✅");
    else
        arith_status_msg(n1, " / ", n2, n1 / n2, "❌");
}

void min_max_test_ints(int num1, int num2)
{
    Fixed n1 ( num1 );
    Fixed n2 ( num2 );
    Fixed const num1c ( num1 );
    Fixed const num2c ( num2 );

    cout_test_name("min max test ints:");
    
    std::cout << "This is the min of " << num1 << " and " << num2 << ": " << Fixed::min(num1, num2) << std::endl;
    std::cout << "This is the min of " << num1 << " and " << num2 << " but using const values: " << Fixed::min(num1c, num2c) << std::endl;

    std::cout << "This is the max of " << num1 << " and " << num2 << ": " << Fixed::max(num1, num2) << std::endl;
    std::cout << "This is the max of " << num1 << " and " << num2 << " but using const values: " << Fixed::max(num1c, num2c) << std::endl;    
}

void min_max_test_floats(float num1, float num2)
{
    Fixed n1 ( num1 );
    Fixed n2 ( num2 );
    Fixed const num1c ( num1 );
    Fixed const num2c ( num2 );

    cout_test_name("min max test floats:");

    std::cout << "This is the min of " << num1 << " and " << num2 << ": " << Fixed::min(num1, num2) << std::endl;
    std::cout << "This is the min of " << num1 << " and " << num2 << " but using const values: " << Fixed::min(num1c, num2c) << std::endl;

    std::cout << "This is the max of " << num1 << " and " << num2 << ": " << Fixed::max(num1, num2) << std::endl;
    std::cout << "This is the max of " << num1 << " and " << num2 << " but using const values: " << Fixed::max(num1c, num2c) << std::endl;    
}

int main( void ) 
{
    subject_test();

    comparison_operators_test_ints(10, 12);
    comparison_operators_test_floats(10.5, 12.75);
    
    arithmatic_operators_test_ints(20, 10);
    arithmatic_operators_test_floats(2.5, 2.0);
    arithmatic_operators_test_floats(2.5, 2.5);

    min_max_test_ints(10, 20);
    min_max_test_floats(10.123, 20.456);

    return 0;
}

