semaphore customers = 0;	// counts number of waiting customers
semaphore chef = 0;			// number of chefs available (0 or 1)
semaphore working = 0;		// can only service one customer at a time
semaphore mutex = 1;		// for mutual exclusion of critical resource, used to prevent num_customers from being changed outside of the thread
int max_customers = n;
int num_customers = 0;		// number of customers 

void chef() 
{
	while(1)
	{
		// --------------- FILL THIS OUT--------------
		// Hints:
		// There are three semaphores used here. Only one is locked and released in this loop.
		// The chef should sleep (watch dramas) when there are no customers and then if there is a customer, start to service the customer. Keep in mind that when a customer is serviced, the number of customers waiting will have to be decremented.
	}
}
void customer() 
{
	while(1)
	{
		// --------------- FILL THIS OUT--------------
		// Hints:
		// There are three semaphores used here. Only one is locked and released
		// When a customer arrive, num_customers can change. However, num_customers will only change it it is less than max_customers. 
	}
}

// Chef helps customer only if there is a customer to request it
// Recall that working is initialized to 0. Chef can acquire the semaphore when working = 1 (customer gets help)
service_customer()
{
	down(working);
}

get_help()
{
	// Customer asks for help so now working = 1 (assuming working was 0 before)
	up(working);
}

down(semaphore s)
{
	if (s > 0)
	{
		s -= 1;
	}
	else
	{
		// sleep and watch all the dramas;
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
