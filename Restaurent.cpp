#include<conio.h>
#include<stdio.h>
#include<string>
#include<iostream>
#include<assert.h>
using namespace std;
const MAX_DISHES=200;

class Introduction 
{
	public:

	void MainIntroduction()
	{
		cout<<"THIS IS A RESTAURENT MANAGEMENT SYSTEM";
	}

	void MenuIntroduction()
	{
		cout<<"\n***MENU***\n";
	}

	void DisplayOptions()
	{
		cout<<"\nEnter one option\n";
		cout<<"\n1.Display Menu \n2.Edit Menu \n3.Take Order \n4.Order Summary \n5.Total Price \n6.Exit";

	}

};


class dish
{

	string Name;
	int Price;
	bool Availabality;

	public:

		void Modify()
		{
			cout<<"\n Enter the name of the new dish:";
			cin>>Name;
			cout<<"\n Enter the price of the new dish:";
			cin>>Price;

		}

		void Get()
		{
		    cout<<"\n Enter the dish name:";
		    cin>>Name;
		    cout<<"\n Enter the dish price:";
		    cin>>Price;
		}

		void Availability(bool temp)
		{
		    Availabality = temp;
		}

		void Display()
		{
		    cout<<"\n Name : "<<Name<<"  Price : "<<Price;
		}

		char Name()
		{
		    return(Name);
		}

		int Price()
		{
		    return(Price);
		}


};


class menu:public Introduction
{
	int NumbofDishes;
	dish Menu[MAX_DISHES];
	int repeat = 0;
    int Option;
    int MenuLength = 0;
    int MenuCount = 0;

	public:

    void GetMenu()
    {
        bool Temp = true;
        int option;
        while(Temp)
        {
            cout<<"\n 1.Add Dish";
            cout<<"\n 2.Exit";
            cin>>option;
            switch(option)
            {
            case 1:
                Menu[MenuLength].Get();
                MenuLength += 1;
                break;
            case 2:
                Temp = false;
                break;
            default:
                cout<<"\n Invalid Choice \n Please Enter a Valid Option";
                break;
            }
        }
    }


	void ModifyMenu()
	{
		cout<<"\n Enter the dish no to modify";
		cin>>DishNumber;
		Menu[DishNumber].Modify();

	}

	void AddDish()
	{
	   cout<<"\n Enter the dish Details";
	   MenuLength += 1;
	   Menu[MenuLength].Get();
	}


	void DisplayMenu() 
	{
		MainIntroduction();
		for(int i = 0;i < MenuLength; i++)
        {
            cout<<i+1<<"."<<Menu[MenuLength].Name<<"    "<<Menu[MenuLength].Price<<endl;
        }

	}
};

class Order:private menu  
{
	int QuantityOfDish;
	int OrderDishNo[100][2]; 
	int NoOfDishes;        
	int Ordersize;         

	public:

	void TakeOrder() 
	{
	    bool temp;
	    int temp1;
		while(temp)
        {
            Ordersize += 1;
            cout<<"\n Enter the Dish number ";
            cin>>temp1;
            OrderDishNo[Ordersize-1][0] = temp1;
            cout<<"\n Enter the Dish Quantity ";
            cin>>temp2;
            OrderDishNo[Ordersize-1][1] = temp1;
        }
	}



	void OrderSummary()  
	{
		cout<<"\n Your Order :";
		for(int i = 0;i<Ordersize;i++)
		{
			cout<<OrderDishNo[i][1]<<" of "<<menu[OrderDishNo[i-1][0]].Name<<endl;
		}

	}
};


class Bill:private Order
{

    int OrderAmount = 0;
    float Taxes;
    float TotalAmount;


	public:


		void BillAmount()  
		{
		    for(int i = 0;i<Ordersize;i++)
		    OrderAmount += menu[OrderDishNo[i-1][0]].Price * OrderDishNo[i][1];
		}


		void Taxes()  
		{
		    Taxes = (float)OrderAmount * 14.5;
		}


		void TotalPrice() 
		{
		    TotalPrice = (float)OrderAmount + Taxes;
		}



};


int main()
{
	int RepeatMainOptions=1;
	int MainDisplayOption;
	Introduction Intro1;
	Bill MainBill;
	menu Mainmenu;
	Order MainOrder;
	Intro1.MainIntroduction();
	Intro1.DisplayOptions();
    cin>>MainDisplayOption;

    do
    {


    switch(MainDisplayOption)
    {
    	case 1:

    		Mainmenu.DisplayMenu();
    		break;

    	case 2:

    		Mainmenu.ModifyMenu();
    		break;

    	case 3:
    		MainOrder.TakeOrder();
    		break;

    	case 4:
    		MainOrder.OrderSummary();
    		break;

    	case 5:
    		MainBill.TotalPrice();
    		break;

    	case 6:

    		RepeatMainOptions=0;
    		break;


    	default:

    		assert (MainDisplayOption>)


	};

    }while(RepeatMainOptions);

	getch();

}