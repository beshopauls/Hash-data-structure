#include <iostream>
#include<string>
using namespace	std;
const int	Size_table = 20;
struct Hash
{
	string name;
	Hash* next;
};
Hash* table[Size_table];
Hash* ele = NULL;
Hash* ele2 = NULL;
int pos = 0, num = 0;
bool ch = false;
string name;
void set_value_NULL()	//Function for set value NULL in all buckets;
{
	for (int i = 0; i < Size_table; i++)
	{
		table[i] = NULL;
	}
}
int Hash_function(string n)	//Function for calculate length name (hash function);
{
	return n.length();
}
void Add_element()	  //Function for adding elements in table;
{
	cout << "Enter a number of elements you need add : "; cin >> num;
	for (int i = 0; i < num; i++)
	{
		ele = new Hash;
		cout << "Enter a name : "; cin >> name;
		ele->name = name;
		ele->next = table[pos + 1];
		pos = Hash_function(ele->name);
		if (table[pos] == NULL)
			table[pos] = ele;
		else
		{
			for (ele2 = table[pos]; ele2->next != NULL; ele2 = ele2->next);
			ele2->next = ele;

		}
	}
}
void delete_element() //Function for delete elements from table ;
{
	cout << "Enter a number of elements you need delete : "; cin >> num;
	for (int i = 0; i < num; i++)
	{
		cout << "Enetr a name : "; cin >> name;
		pos = Hash_function(name);
		if (table[pos]->name == name)
		{
			ele = table[pos];
			table[pos] = table[pos]->next;
			free(ele);
		}
		else
		{
			for (ele = table[pos]; ele != NULL; ele = ele->next)
			{
				if (ele->next->name == name)
				{
					ele2 = ele->next;
					ele->next = ele->next->next;
					free(ele2);
					break;
				}	
			}
		}
	}
}
void print_table()	//Function for print table ;
{
	for (int i = 0; i < Size_table; i++)
	{
		cout << "Table [" << i << "] : ";
		for (ele = table[i]; ele != NULL; ele = ele->next)
		{

			cout << "--> " << ele->name;

		}
		cout << endl;
	}
}
void search()  //Function for search in table ;
{
	cout << "Enter the name you need searching it : "; cin >> name;
	pos = Hash_function(name);
	for (ele = table[pos]; ele != NULL; ele = ele->next)
	{
		if (name == ele->name)
		{
			cout << "Found : " << ele->name << endl;
			ch = true;
			break;
		}
	}
	if (ch == false)
		cout << "Not found " << endl;
}
void menu()	//Function for menu ;
{
	int choice = 0;
	while (choice != 5)
	{
		cout << "              1: Add elements        \n"
			<< "              2: Delete elements     \n"
			<< "              3: Search              \n"
			<< "              4: Print table         \n"
			<< "              5: End                 \n";
		cout << "Enetr your choise : "; cin >> choice;
		switch (choice)
		{
		case 1:
		{
			Add_element();
			break;
		}
		case 2:
		{
			delete_element();
			break;
		}
		case 3:
		{
			search();
			break;
		}
		case 4:
		{
			print_table();
			break;
		}
		case 5:
		{
			system("pause");
			break;
		}
		default:
		{
			cout << "Your choice not correct : \n";
			break;
		}
		}
	}
}
int main()
{
	menu();
	return 0;
}