

#include "stdafx.h"
#include <iostream>

using namespace std;

//Yapı oluşturma
struct n {
	int x;
	n *next;



};
typedef struct n node; // "struct node" ifadesini kısaca "node" şekline çevirdi. 
//Ekle fonksiyonu
node * ekle(node * r, int x) {
	//Eğer root yoksa yeni düğüm yarat ve next ini kendine dönder.
	if (r == NULL)
	{
		r = (node *)malloc(sizeof(node));
		r->x = x;
		r->next = r;
		


	}
	//Eğer 1 tane düğüm varsa,sonraki eklenecek düğüm ya öncesine ya sonrasına eklenecek.
	else if (r->next == r)
	{   //Eğer eklenecek düğüm, ilk düğümden küçükse gerekli işlemleri yap.root u değiştir.
		if (r->x >= x)
		{
			node * temp = (node *)malloc(sizeof(node));
			temp->x = x;
			temp->next = r;
			r->next = temp;
			r = temp;
			return r;

		}
		//Eğer eklenecek düğüm ,ilk düğümden büyükse gerekl işlemleri yap.root sabit.
		else
		{
			node * temp = (node *)malloc(sizeof(node));
			temp->x = x;
			r->next = temp;
			temp->next = r;
			return r;
		}
	}
	//Bundan sonraki işlemler önceki 2 düğüm ile karşılaştırma yapıp ,düğümü sıralı şekilde diz mantığına dayanıyor.
	//Daha sonra oluşturlacak olan düğümlerle de karşılaştırma yapmaktadır. 
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
//Silme fonksiyonu
node * sil(node * r, int x)
{
	node * temp;
	node * iter = r;
	//eğer silenecek eleman ilk elemans(rootsa yada ) ve tek düğüm değilse
	if (r->x == x)
	{      //sondaki roota giden düğümü silinen düğümden sonraki düğüme bağlama
		while (iter->next != r)
		{
			iter = iter->next;
		}
		iter->next = r->next;
		free(r);

		return iter->next;


	}
	//aradığımız düğüm yoksa ilerlet
	while (iter->next != r && iter->next->x != x) {
		iter = iter->next;
	}
	//varsa aşağıdaki gerekli işlemleri uygula
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
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
	setlocale(LC_ALL, "Turkish");
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

	root = sil(root, 10);
	root = sil(root, 15);
	root = sil(root, 13);
	root = sil(root, 1);
	root = sil(root, 11);
	root = sil(root, 18);
	

	yazdir(root);

	root = ekle(root, 19);
	yazdir(root);
	root = ekle(root, 1);
	yazdir(root);
	system("pause");
	return 0;
}




