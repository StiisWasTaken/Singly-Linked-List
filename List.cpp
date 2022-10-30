#include <iostream>
using namespace std;
struct obiekt   //tworzenie stuktury/obiektu o nazwie "node"
{
	int val;	// struktura zawiera "watosc"  w postaci zmiennej int val
	obiekt* next;// zawiera równierz wskaznik wskazujacy na adres nastepnego obiektu z listy dynamicznej
};
obiekt* H = NULL; // tworzy pierwszy element który jest wskaznikiem listy dynamicznej (HEAD) i przypisuje jej wartosc NULL
obiekt* G = NULL;
obiekt* L = NULL;
int d = 0;
void Add(obiekt*& H, int x)   // funkcja dodawania obiektów zawierających w sobie wstakźnik H(HEAD) i jej wartosć x)
{
	obiekt* p = new obiekt; //tworzenie nowego wskaznika na nowy element tabilicy
	p->val = x; //przipisuje wartosc ("klasy wartosc") obiektowi równą x
	p->next = H; // przypisuje wskaznik (klasy "wskaznik na nastepny obiekt")  wskaźnika H
	H = p; // wskaznik h wskazuje na p czyli nasz nowy obiekt
}
void AddEnd(obiekt*&H,int x) //dodaje na koniec
{
	obiekt* p =H;
	if (p == NULL)
	{
		Add(H, x);
	}
	else
	{
		while (p->next!= NULL)
			{
			p = p->next;
			}
		obiekt* ad = new obiekt;
		ad->val = x;
		ad->next = NULL;
		p->next = ad;
	}
	
}
void AddSortUp(obiekt*&H,int x) //dodaje do sortowanego od najmniejszego do najwiekszego
{
	obiekt* p = H;
	if (p == NULL || p->val>x)
	{
		Add(H, x);
	}
	else
	{
			while (p->next != NULL && p->next->val < x)
			{
				p = p->next;
			}
			obiekt* ad = new obiekt;
			ad->val = x;
			ad->next = p->next;
			p->next = ad;
	}
}
void AddSortDown(obiekt*&H,int x) //dodaje do sortowanego od najwiekszego do najmniejszego
{
	obiekt* p = H;
	if (p == NULL || p->val<x)
	{
		Add(H, x);
	}
	else
	{
		{
			while (p->next != NULL && p->next->val > x)
			{
				p = p->next;
			}
			obiekt* ad = new obiekt;
			ad->val = x;
			ad->next = p->next;
			p->next = ad;
		}
	}
}
void show(obiekt* H) //pokazuje cala tablice 
{
	cout << "H ->";
	obiekt* p = H;  // tworzy wskaznik pomocniczy wskazujacy na to na co wskazuje head
	while (p != NULL) //sprawdzamy czy to nie jest pusta tablica
	{
		cout << p->val << "-> "; // wyswietla wartosc pierwszego elementu tablicy
		p = p->next; //przeskakuje na kolejne elementy tablicy az p==NULL
	}
	cout << "NULL" << endl; //jezeli nie ma kolejnych elementów w tablicy wyswietl NULL
}
void showSort(obiekt*H, int x) //pokazuje cala tablice 
{
	cout << "H -> ";
	obiekt* p = H;  // tworzy wskaznik pomocniczy wskazujacy na to na co wskazuje head
	while (p != NULL && p->val<x) //sprawdzamy czy to nie jest pusta tablica
	{
		cout << p->val << "-> "; // wyswietla wartosc pierwszego elementu tablicy
		p = p->next; //przeskakuje na kolejne elementy tablicy az p==NULL
	}
	cout << "NULL" << endl; //jezeli nie ma kolejnych elementów w tablicy wyswietl NULL
}
bool Search(obiekt* H, int x) //wyszukuje elementu o konkretnej wartosci
{
	obiekt* p = H; // tworzy wskaznik pomocniczy wskazujacy na to na co wskazuje head
	while (p != NULL && p->val != x) //dopoki ( nie jest to pusta tablica(konczy sie na null) i dopoki wartosc p jest rozne od szukanej)
		p = p->next; // skacze na kolejne elementy tablicy
					// po zakonczeniu pętli zostawia p z ostatnią wartoscia tzn NULL lub znaleziona
	if (p != NULL) //warunek odbycia petli
	{
		cout << "jest" << endl;  //jezeli jest nasza szukana wartosc
		return p;
	}
	else
	{
		cout << "nie ma" << endl; // jezeli tablista jest pusta lub nie ma naszej szukanej wartosci
		return p;
	}
}
void del(obiekt*& H)
{
	if (H != NULL)
	{
		obiekt* p = H; //pomocniczy wskaźnik
		H = H->next; // zmiana Heada na kolejny
		delete p; // usunięcie starego H
	}

}
void delEnd(obiekt*& H) //usuwa ostatni wypisywany element
{
	obiekt* p = H;
	if (p == NULL)
	{
		cout << "Lista jest pusta" << endl;
	}
	else if (p->next==NULL)
	{
		del(H);
		}
	else 
	{
		while (p->next->next != NULL)
		{
			p = p->next;
		}
		p->next = NULL;
	}
}
void RemoveEven(obiekt*& H)
{
	while (H != NULL && H->val % 2 == 0)
	{
		del(H);
	}
	obiekt* p = H;
	while (p != NULL && p->next != NULL)
	{
		if (p->next->val % 2 == 0)
		{
			del(p->next);
		}
		else
		{
			p = p->next;
		}
	}
}
void RemoveOdd(obiekt*& H)
{
	while (H != NULL && H->val % 2 != 0)
	{
		del(H);
	}
	obiekt* p = H;
	while (p != NULL && p->next != NULL)
	{
		if (p->next->val % 2 != 0)
		{
			del(p->next);
		}
		else
		{
			p = p->next;
		}
	}
}
void del2(obiekt*& H, int x)
{
	Add(H, 0);  //tworzymy wartownika 
	obiekt* p = H; //tworzymy wskaznik pomocniczy ktory wskazuje na to na co wskazuje  Head
	while (p->next != NULL && p->next->val != x)
		p = p->next;

	if (p->next != NULL)
	{
		obiekt* e = p->next;
		p->next = e->next;
		del(e);
	}
	del(H);
}
void Remove(obiekt*& H, int x) //usuwa wszystkie podane elementy
{
	while (H != NULL && H->val==x)
	{
		del(H);
	}
	obiekt* p = H;
	while (p != NULL && p->next != NULL)
	{
		if (p->next->val ==x)
		{
			del(p->next);
		}
		else
		{
			p = p->next;
		}
	}
}
void RemoveSrednia(obiekt*& H, int x) //usuwa wszystkie podane elementy
{
	while (H != NULL && H->val<x)
	{
		del(H);
	}
	obiekt* p = H;
	while (p != NULL && p->next != NULL)
	{
		if (p->next->val <x)
		{
			del(p->next);
		}
		else
		{
			p = p->next;
		}
	}
}
void RemovePer2(obiekt*&H)
{
	Add(H, 0);
	obiekt* p = H;
	int i = 0;
	while (p != NULL && p->next != NULL)
	{ 
		i++;
		if (i%2==0)
		{
			del(p->next);
		}
		else
		{
			p = p->next;
		}
	}
	del(H);
}
void srednia(obiekt*&H)
{    
	int i = 0; //ilośc powtórzeń
	int b = 0; //suma
	obiekt* p = H; //wskaźnik pomocniczy
	while(p!=NULL)
	{
		b = b + p->val; //dodaje kolejne elemnty
		i++; //kolejne powtórzenie
		p = p->next; //przesuniecie wskaźnika
	}
	d = b / i; // suma przez liczbe elementow
}
void delbothplus(obiekt*& H)
{
	Add(H, 0);
	obiekt* p = H; 
	obiekt* d = p->next;  
	if ( p->next != NULL || p->next->next!=NULL)
	{
		while (p->next->next!=NULL)
		{
			if (d->val + d->next->val > 0)
			{
				p->next = p->next->next->next;
				del(d->next);
				del(d);
			}
			else
			{
				p = p->next;
				d = p->next;
			}
		}

	}
	else
	{
	cout<<"za malo elementow"<<endl;
	show(H);
	}
	del(H);
}
void LinkSorted(obiekt*&H1, obiekt*&H2,obiekt*&H)
{
	Add(H, 0);
	obiekt* T = H;
	while (H1 && H2)
	{
		if (H1->val < H2->val)
		{
			T->next = H1;
			H1 = H1->next;
			T = T->next;
		}
		else
		{
			T->next = H2;
			H2 = H2->next;
			T = T->next;
		}
	}
		if (H1==NULL)
		{
			T->next = H2;
			H2=NULL;
		}
		else
		{
		T->next = H1;
		H1 = NULL;
		}
	del(H);
}
void CopyAfter(obiekt*& H) 
{
	obiekt* p = H;
	if (p == NULL)
	{
		cout << "tablica jest pusta" << endl;
	}
	else
	{
		while (p!= NULL)
		{
			obiekt* ad = new obiekt;
			ad->val = p->val;
			ad->next = p->next;
			p->next = ad;
			p = ad->next;
		}
	}
	
}
void CopyAfterX(obiekt*& H) //kopiuje elemnty tyle razy ile wynosi ich wartość
{
	obiekt* p = H;
	if (p == NULL)
	{
		cout << "tablica jest pusta" << endl;
	}
	else
	{
		Add(H, 0);
		while (p != NULL)
		{
			//obiekt* ad = new obiekt;
			int i = 0;
			while (i !=p->val)
			{
				obiekt* ad = new obiekt;
				i++;
				cout << i << endl;
				cout << "TUTAJ " << p->val << endl;
				ad->val = p->val;
				ad->next = p->next;
				p->next = ad;
				p=p->next;	
			}
			p = p->next;
		}
		del(H);
	}
}
void Merge(obiekt*& H1, obiekt*& H2, obiekt*& H)
{
	Add(H, 0);
	obiekt* T = H;
	while (H1 && H2)
	{
		if (H1->val < H2->val)
		{
			T->next = H1;
			H1 = H1->next;
			T = T->next;
		}
		else
		{
			T->next = H2;
			H2 = H2->next;
			T = T->next;
		}
	}
	if (H1 == NULL)
	{
		T->next = H2;
		H2 = NULL;
	}
	else
	{
		T->next = H1;
		H1 = NULL;
	}
	del(H); 
}
void split(obiekt* H, obiekt* H1, obiekt* H2)
{

}
int main()
{
	AddEnd(H, 2); AddEnd(H, 3); AddEnd(H, 4); //AddEnd(H, 2); //AddEnd(H, -21); AddEnd(H, 57); AddEnd(H, 15); AddEnd(H, -20); AddEnd(H, 19);
	//AddEnd(G, 7); AddEnd(G, -15); AddEnd(G, 20); AddEnd(G, -18); AddEnd(G, 70); AddEnd(G, -92); AddEnd(G, 75);
	show(H);
	CopyAfterX(H);
	show(H);
} 


