/*Background: You are building an inventory management system for a small store. The store sells a
variable number of products, and the inventory needs to be updated dynamically.
Task:
1. Ask the user to input the number of products in the store.
2. Dynamically allocate a 1D array to store the quantity of each product.
3. Populate the array with initial quantities (user input).
4. Implement the following features:
• Add a new product to the inventory (resize the array).
• Remove a product from the inventory (resize the array).
• Update the quantity of a specific product.
• Display the current inventory.
5. Deallocate the memory after use.*/

#include<iostream>
#include<iomanip>
#include<new>

using namespace std;

int main()
{
	int i,j,size,remove,size1;
	char choice1,choice2;
	
	// 1) Storing no. of products
	cout<<"Enter number of products: ";
	cin>>size;
	
	// 2) Dynamic allocation of 1D array
	int *products=new int[size];
	
	// 3) Populating array
	for(i=0;i<size;i++)
	{
		cout<<"\nEnter quantity for Product "<<i+1<<": ";
		cin>>products[i];
	}
	cout<<"\nCurrent Inventory: [ ";
	for(i=0;i<size;i++)
	{
		cout<<products[i]<<"  ";
	}
	cout<<"]\n";
	cout<<"\n-----------------------------------\n";
	// 4) Features:
	
	// i) Adding a product
	cout<<"\n\nDo you want to add products [Y/N]: ";
	cin>>choice1;
	if(choice1=='Y')
	{
		cout<<"\nEnter number of products to be added: ";
	    cin>>size1;
		int *p2=new int[size1];  //Dynamically resize array;

		// storing values from products into p2
		for(i=0;i<size;i++)
	    {
	    	p2[i]=products[i];
	    }
		
	    // Adding products
	    int new_size;
		new_size=size+size1;  //updated size (resized array)
	    for(i=size;i<new_size;i++)
	    {	
	        cout<<"\nEnter quantity for Product "<<i+1<<": ";
		    cin>>p2[i];
		}
		// Displaying Inventory after adding product
		cout<<"\nNew Inventory: [ ";
	    for(i=0;i<new_size;i++)
	    {
		    cout<<p2[i]<<"  ";
	    }
	    cout<<"]\n";
	    delete [] products;
	    products=p2;
	    size=new_size;
	}	
	cout<<"\n-----------------------------------\n";
	
	    // ii) Remove a product
		cout<<"\n\nDo you want to remove Product [Y/N]: ";
	    cin>>choice2;
	    if(choice2=='Y')
	    {
		    cout<<"\nEnter product number (index) you want to remove: ";
		    cin>>remove;
		    for(i=remove;i<size-1;i++)
		    {
			    products[i]=products[i+1];
			}
			size--;
		}
	cout<<"\nNew Inventory: [ ";
	for(i=0;i<size;i++)
	{
		cout<<products[i]<<"  ";
	}
	cout<<"]\n";
	cout<<"\n---------------------------------------------------\n";
	
	// iii) Updating/Modifying a product quantity
	char ch3;
	int modify;
	cout<<"\nDo you want to Modify quantity of a product [Y/N]: ";
	cin>>ch3;
	if(ch3=='Y')
	{
		cout<<"\nEnter product quantity you want to modify: ";
		cin>>modify;
		for(i=0;i<size;i++)
		{
			if(modify==products[i])
		    {
			    cout<<"\nEnter updated quantity for the product: ";
			    cin>>products[i];
			    cout<<"\n-------------------------------------------\n";
			    cout<<"\n\t*Displaying Updated Inventory*\n";
			    cout<<"\n-------------------------------------------\n\n";
		        cout<<"[ ";
		        for(i=0;i<size;i++)
		        {
			       cout<<products[i]<<"  ";
		        }
		        cout<<"]\n";
		   }
	
		}		
	}
	
	delete [] products;
	
	return 0;
}