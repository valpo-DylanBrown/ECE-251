/* PROGRAM 4b */
#include <stdio.h>

int main()
{
	int age;
	
	printf("Please enter your age: ");
	scanf("%d", &age);
	
	if ((age >= 5) && (age <= 10))
	{
		printf("You are most likely in elementary school.");
		printf("\nYou are not old enough to drive.");
		printf("\nYou are not old enough to vote.");
		printf("\nYou are not old enough to drink.");
		printf("\nYou are not old enough to to be president.");
		printf("\nYou are not old enough to receive social security.");
	}
	else if ((age > 10) && (age <= 17))
	{
		if (age <= 13)
		{
			printf("You are most likely in middle school.");
			printf("\nYou are not old enough to drive.");
			printf("\nYou are not old enough to vote.");
			printf("\nYou are not old enough to drink.");
			printf("\nYou are not old enough to to be president.");
			printf("\nYou are not old enough to receive social security.");
		}
		else if ((age >= 13) && (age < 16))
		{
			printf("You are most likely in high school.");
			printf("\nYou are not old enough to drive.");
			printf("\nYou are not old enough to vote.");
			printf("\nYou are not old enough to drink.");
			printf("\nYou are not old enough to to be president.");
			printf("\nYou are not old enough to receive social security.");
		}
		else 
		{
			printf("You are most likely in high school.");
			printf("\nYou are old enough to drive.");
			printf("\nYou are not old enough to vote.");
			printf("\nYou are not old enough to drink.");
			printf("\nYou are not old enough to to be president.");
			printf("\nYou are not old enough to receive social security.");
		}
			
	}
	else if ((age > 17) && (age < 21))
	{
		printf("You are most likely in college.");
		printf("\nYou are old enough to drive.");
		printf("\nYou are old enough to vote.");
		printf("\nYou are not old enough to drink.");
		printf("\nYou are not old enough to to be president.");
		printf("\nYou are not old enough to receive social security.");
	}	
	else if ((age > 21) && (age < 35))
	{
		if (age <= 22)
		{
			printf("You are most likely in college.");
			printf("\nYou are old enough to drive.");
			printf("\nYou are old enough to vote.");
			printf("\nYou are old enough to drink.");
			printf("\nYou are not old enough to to be president.");
			printf("\nYou are not old enough to receive social security.");
		}
		else 
		{
			printf("You are most likely out of school.");
			printf("\nYou are old enough to drive.");
			printf("\nYou are old enough to vote.");
			printf("\nYou are old enough to drink.");
			printf("\nYou are not old enough to to be president.");
			printf("\nYou are not old enough to receive social security.");
		}
	}
	else if ((age > 35) && (age < 65))
	{
		printf("You are most likely out of school.");
		printf("\nYou are old enough to drive.");
		printf("\nYou are old enough to vote.");
		printf("\nYou are old enough to drink.");
		printf("\nYou are old enough to to be president.");
		printf("\nYou are not old enough to receive social security.");
	}
	else if ((age >= 65))
	{
		printf("You are most likely out of school.");
		printf("\nYou are old enough to drive.");
		printf("\nYou are old enough to vote.");
		printf("\nYou are old enough to drink.");
		printf("\nYou are old enough to to be president.");
		printf("\nYou are old enough to receive social security.");
	}
	else
	{
		printf("Why are you here?");
	}
	return 0;
}
