/*
 * DemoShm.cpp
 *
 *  Created on: 2015年5月4日
 *      Author: ikelhe84@gmail.com
 */

#include <sys/ipc.h>
#include "DemoShm.h"

DemoShm::DemoShm() : shared_memory((void *)0)
{

}

DemoShm::~DemoShm() {
	// TODO Auto-generated destructor stub
}

// id = 1234 size=sizeof(cust_info_st)
bool DemoShm::CreateShm(int id, int size)
{
	int shmid;
	shmid = shmget((key_t)id, size, 0666 | IPC_CREAT);
	if (shmid == -1)
	{
		fprintf(stderr, "shmget failed\n");
		return false;
	}

	shared_memory = shmat(shmid, (void *)0, 0);
	if (shared_memory == (void *)-1)
	{
		fprintf(stderr, "shamat failed\n");
		return false;
	}

	printf("memory attached at %X\n", (int)shared_memory);


	return true;
}

bool DemoShm::InsertOneRecord(void *oneRec)
{
	struct cust_info_st *custInfo;
	custInfo = (cust_info_st *)shared_memory;
	custInfo->age = 31;
	strcpy(custInfo->cust_no, "000000001");
	strcpy(custInfo->cust_name, "hzt");
	strcpy(custInfo->sex, "M");
	return true;
}

bool DemoShm::GetOneRecord(void **oneRec)
{
	*oneRec = shared_memory;
	printf("GetOneRecord memory attached at %X\n", (int)shared_memory);
	printf("GetOneRecord2 memory attached at %X\n", (int)oneRec);
	return true;
}
