
# include "Serializer.hpp"



void toUpper(std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i) {
        str.at(i) = std::toupper(str.at(i));
    }
}

int main(int argc, char **argv)
{
	Data d1;
	Data *d1_PTR = &d1;
	uintptr_t uint_PTR;

	if (argc > 3)
		return 1;
	if (argc >= 2)
		d1.info = argv[1];

	if (argc == 2)
	{
		std::cout << "Your input before serializing: " << d1_PTR->info << std::endl;
		uint_PTR = Serializer::serialize(d1_PTR);
		d1_PTR = Serializer::deserialize(uint_PTR);
		std::cout << "Your input after deserializing: " << d1_PTR->info << std::endl;
		toUpper(d1_PTR->info);
		std::cout << "Your input after toupper: " << d1.info << std::endl;
	}
	else if (argc == 3)
	{
		std::cout << "Your input before serializing and toupper: " << d1.info << std::endl;
		uint_PTR = Serializer::serialize(d1_PTR);
		toUpper(d1.info);
		d1_PTR = Serializer::deserialize(uint_PTR);
		std::cout << "Your input after deserializing and toupper: " << d1.info << std::endl;
	}

}

