semaphore customers = 0;	// counts number of waiting customers
semaphore chef = 0;			// number of chefs available (0 or 1)
semaphore working = 0;		// can only service one customer at a time
semaphore mutex = 1;		// for mutual exclusion of critical resource, used to prevent num_customers from being changed outside of the thread
int max_customers = n;
int num_customers = 0;		// number of customers 

void chef() 	// CONSUMER
{
	while(1)
	{
		// --------------- FILL THIS OUT--------------
		// Hints:
		// There are three semaphores used here. Only one is locked and released in this loop.
		// The chef should sleep (watch dramas) when there are no customers and then if there is a customer, start to service the customer. Keep in mind that when a customer is serviced, the number of customers waiting will have to be decremented.
		if (num_customers > 0) {
			down(&chef);		// Chef is busy about to service a customer. So wait for chef to be available before proceeding
			service_customer();	// Service the customer.
			down(&customers);	// CONSUME Customer
			down(&mutex);		// Start critical section
				num_customers -= 1;	// Decrease num_customers waiting by 1
			up(&mutex);			// end critical section
			up(&chef);			// Chef is done working, so is available once again.
		}
		else {
			// No customers to service.  Go back to watching KDrama
			down(&customers);	// sleep and watch KDrama
			up(&chef);			// let store know the chef is in the house! (available)
		}
	}
}


void customer() 	// PRODUCER
{
	while(1)
	{
		// --------------- FILL THIS OUT--------------
		// Hints:
		// There are three semaphores used here. Only one is locked and released
		// When a customer arrive, num_customers can change. However, num_customers will only change it it is less than max_customers.
		if (num_customers < max_customers)  {
			up(&customers);		// PRODUCE a customer
			down(&mutex);		// Start critical section
				num_customers += 1;	// Increase num_customers
			up(&mutex);			// end critical section

			if (num_customers == 1) {
				get_help();			// Tell chef to stop watching KDrama & work/help the customer.
			}
		} else {
			// All seats are taken so customer just leaves
		}
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