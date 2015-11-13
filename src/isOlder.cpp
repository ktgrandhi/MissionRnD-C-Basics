/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: value=-1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/



int Validity(char *dob)
{
	int date[3];
	date[0] = (dob[0] - 48) * 10 + (dob[1] - 48);
	date[1] = (dob[3] - 48) * 10 + (dob[4] - 48);
	date[2] = (dob[6] - 48) * 1000 + (dob[7] - 48) * 100 + (dob[8] - 48) * 10 + (dob[9] - 48);
	
	if (date[1] > 12 || date[1] < 1)
	{
		return -1;
	}
	if (date[1] == 2)
	{
		if (date[2] % 100 == 0 && date[2] % 400 == 0)
		{
			if (date[0] > 29 || date[0] < 1)
			{
				return -1;
			}
		}
		else
		{
			if (date[2] % 4 == 0){
				if (date[0] > 29 || date[0] < 1)
				{
					return -1;
				}
			}
			else
			{
				if (date[0]>28 || date[0] < 1)
					return -1;
			}
		}
	}
	else
	{
		if (date[1] == 1 || date[1] == 3 || date[1] == 5 || date[1] == 7 || date[1] == 8 || date[1] == 10 || date[1] == 12)
		{
			if (date[0] > 31 || date[0]<1)
				return -1;
		}
		else
		{
			if (date[1]>30 || date[1] < 1)
				return -1;
		}
	}

	return 0;
	
}

int isOlder(char *dob1, char *dob2) {
	
	int index,value,check1,check2;
	for (index = 0; index < 10; index++)
	{
		if (index==2||index==5)
		{
			if (dob1[index] != '-' || dob2[index] != '-')
				return -1;
		}
		else
		{
			if (dob1[index]<'0' || dob1[index]>'9' || dob2[index]<'0' || dob2[index]>'9')
				return -1;
		}
	}
	 check1 = Validity(dob1);
	 check2 = Validity(dob2);
	 
	 if (check1==-1||check2==-1)
	 {
		 return -1;
	 }
	 else
	 {
		 for (index = 6; index < 10; index++)
		 {
			 if (dob1[index]>dob2[index])
				 return 2;
			 else
			 {
				 if (dob1[index] < dob2[index])
					 return 1;
			 }
		 }
		 for (index = 3; index < 5; index++)
		 {
			 if (dob1[index]>dob2[index])
				 return 2;
			 else
			 {
				 if (dob1[index] < dob2[index])
					 return 1;
			 }
		 }
		 for (index = 0; index < 2; index++)
		 {
			 if (dob1[index]>dob2[index])
				 return 2;
			 else
			 {
				 if (dob1[index] < dob2[index])
					 return 1;
			 }
		 }
		 return 0;
		
	 }
	 
}
