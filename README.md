printf()

|We created custom version of standart printf() function .
|In normally , This function you can find in stdio.h .
|Function give us output for different variable type . They are integer , character , string and percent symbol.
|Sure , you can see other data types in stdio.h library.But we only write this types.


For files' description:
|main.h - it is main file of project
|printfcsp.c - this file for custom version of printf
|man_3_printf - this file for details of programs 
|functions.c - this file catch our program's  functions
|a.out - it was created after compile 
|main.c - it was created after compile

Environment 
>>>Language : C
>>>Style : Betty style
>>>Compiler : gcc 11.4.0
>>>Sandbox: Ubuntu 22.04 Paris

How to install and compile?
1)git clone https://github.com/Mirheybet/holbertonschool-printf.git
2)cd holberton-printf

Sample main program :
int main(void)
{
	_printf("%s %c %d", "Hello, Holberton!", "H", 1234);
	return (0);
}

For compile : 
	>>>gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c -o printf
	>>>./printf
	Hello Holberton! H 1234
