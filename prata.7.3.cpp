/*Here is a structure declaration:
struct box
{
char maker[40];
float height;
float width;
float length;
float volume;
};
a. Write a function that passes a box structure by value and that displays the
value of each member.
b. Write a function that passes the address of a box structure and that sets the
volume member to the product of the other three dimensions.
c. Write a simple program that uses these two functions.*/

#include <iostream>
//structure definition
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
//function prototypes
float volume(box * pb);
void display(box a);



int main(void)
{
//structure initialization
	box mapple = 
	{
		"Syberia",
		2.5,
		3.0,
		6.5
	};
//pointer to the box mapple
	box * pm = &mapple;
//calls volume calculating function
	mapple.volume = volume(pm);
//displays structure
	display(mapple);
	return 0;
};

//function definition for counting the volume using a pointer to the structure
float volume(box * pb)
{
	pb->volume = pb->height * pb->width * pb->length;
	return pb->volume;
};

//function definition for displaying the members or the box structure
void display(box a)
{
	std::cout << a.maker << std::endl << a.height << std::endl << a.width << std::endl << a.length << std::endl << a.volume << std::endl;
};
