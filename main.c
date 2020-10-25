semaphore customers = 0;	// counts number of waiting customers
semaphore chef = 0;			// number of chefs available (0 or 1)
semaphore working = 0;		// can only service one customer at a time
semaphore mutex = 1;		// for mutual exclusion of critical resource
int num_customers = 0;		// number of customers 

void chef() 
{

}
void customer() 
{

}

// Chef helps customer
service_customer()
{
	service(); // assume this busy function is already written
}

// Customer is helped
get_help()
{

}

down(semaphore s)
{
	if (s > 0)
	{
		s -= 1;
	}
	else
	{
		// sleep;
	}
}

up(semaphore s)
{
	if(someone is waiting on s)
	{
		// wake up
	}
	else
	{
		s += 1;
	}
}
