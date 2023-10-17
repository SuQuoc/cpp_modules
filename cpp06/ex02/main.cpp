
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		Base *basePTR = generate();
		Base& baseREF = *basePTR;

		std::cout << "PTR: ";
		identify(basePTR);
		std::cout << "REF: ";
		identify(baseREF);
		delete basePTR;
	}
	else if (argc == 2)
	{
		std::string in = argv[1];
		Base *basePTR = NULL;
		if (in == "A")
			basePTR = new A();
		else if (in == "B")
			basePTR = new B();
		else if (in == "C")
			basePTR = new C();

		Base& baseREF = *basePTR;
		std::cout << "PTR: ";
		identify(basePTR);
		std::cout << "REF: ";
		identify(baseREF);
		delete basePTR;
	}
}
