/*
 * test.cpp
 *
 *  Created on: 2015年5月4日
 *      Author: ikelhe84@gmail.com
 */

#include "DemoShm.h"

int main(int argc,char *argv[])
{
	struct cust_info_st *custInfo;
	struct cust_info_st *custInfo2;
	void *poneRec;

	DemoShm demoShm;
	if (!demoShm.CreateShm(1234, sizeof(cust_info_st)))
	{
		return false;
	}
	demoShm.InsertOneRecord((void *)NULL);
	printf("out memory bef attached at %X\n", (int)poneRec);
	demoShm.GetOneRecord(&poneRec);
	char cust_no[11];
	char cust_name[20];
	char sex[2];
	int  age;
	printf("out memory0 attached at %X\n", (int)&poneRec);
	custInfo2 = (cust_info_st *)poneRec;
	printf("out memory attached at %X\n", (int)poneRec);

	printf("out address[%X]\n", (int)custInfo2);
	printf("cust_no[%s]\n", custInfo2->cust_no);
	printf("cust_name[%s]\n", custInfo2->cust_name);
	printf("age[%d]\n", custInfo2->age);

	return 0;
}

