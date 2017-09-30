

#include "stdafx.h"
#include <iostream>

using namespace std;


struct n {
	int x;
	n *next;



};
typedef struct n node;

node * ekle(node * r, int x) {
	
	if (r == NULL)
	{
		r = (node *)malloc(sizeof(node));
		r->x = x;
		r->next = r;
		


	}
	else if (r->next == r)
	{
		if (r->x >= x)
		{
			node * temp = (node *)malloc(sizeof(node));
			temp->x = x;
			temp->next = r;
			r->next = temp;
			r = temp;
			return r;

		}
		else
		{
			node * temp = (node *)malloc(sizeof(node));
			temp->x = x;
			r->next = temp;
			temp->next = r;
			return r;
		}
	}
	node *iter = r;
	if (r->next != r) 
	{
		while (iter->next != r) 
		{
			if (iter->x >= x)
			{
				node * temp = (node *)malloc(sizeof(node));
				temp->x = x;
				temp->next = r;
				node * iter = r;
				while (iter->next != r)
				{
					iter = iter->next;
					
				}
				iter->next = temp;
				r = temp; 
				return r;
			}
			else if (iter->x <= x && iter->next->x >= x) 
			{
				node * temp = (node *)malloc(sizeof(node));
				temp->x = x;
				temp->next = iter->next;
				iter->next = temp;

				return r;
			}
			else
			{
			  if(iter->next->next == r && iter->next->x < x)
			  {
				  node *temp = (node *)malloc(sizeof(node));
				  temp->x = x;
				  iter->next->next = temp;
				  temp->next = r;
				  return r;
			  }
			
			}
			

				iter = iter->next;
			
		}

	}
	return r;





}
void yazdir(node *r)
{
	node * iter = r;
	cout << iter->x << "\t";
	iter = iter->next;
	while (iter != r)
	{
		cout << iter->x << "\t";
		iter = iter->next;
	}
	cout << endl;
}
int main()
{
	node *root;
	root = NULL;
	
	root = ekle(root, 10);
	root = ekle(root, 15);
	root = ekle(root, 13); 
	root = ekle(root, 9);
	root = ekle(root, 11);
	root = ekle(root, 17); 
	root = ekle(root, 18);
	root = ekle(root, 8);
	root = ekle(root, 12);
	root = ekle(root, 16);
	root = ekle(root, 14);
	root = ekle(root, 1);
	root = ekle(root, 6);
	root = ekle(root, 7);
	yazdir(root);
	system("pause");
	return 0;
}




