
#include "main.hpp"
#include <stdlib.h>
#include <stdio.h> 

int main()
{
	//subject();
	//subject_arr(4);
	//deepCopyTest();


	Dog basic;
	basic.setAllIdeas("TEST");
	{
		Dog tmp = basic;
		tmp.coutIdeaAtIndex(44);
	}	
	basic.coutIdeaAtIndex(44);

	//wrongSubject();
	//destructorTest();
	//typeTest();
	//copyTest();
}
