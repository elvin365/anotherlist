#include "stdio.h"
#include "stdlib.h"
#include <conio.h>
struct list
{
	int field; // поле данных
	struct list *next; // указатель на следующий элемент
	struct list *prev; // указатель на предыдущий элемент
};

struct list * init(int a)  // а- значение первого узла
{
	struct list *lst;
	// выделение памяти под корень списка
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->next = NULL; // указатель на следующий узел
	lst->prev = NULL; // указатель на предыдущий узел
	return(lst);
}
struct list * addelem(list *lst, int number)
{
	struct list *temp, *p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->field = number; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий узел
	temp->prev = lst; // созданный узел указывает на предыдущий узел
	if (p != NULL)
		p->prev = temp;
	return(temp);
}
void listprint(list *lst)
{
	struct list *p;
	p = lst;
	do {
		printf("%d ", p->field); // вывод значения элемента p
		p = p->next; // переход к следующему узлу
	} while (p != NULL); // условие окончания обхода
}
void listprintr(list *lst)
{
	struct list *p;
	p = lst;
	while (p->next != NULL)
		p = p->next;  // переход к концу списка
	do {
		printf("%d ", p->field); // вывод значения элемента p
		p = p->prev; // переход к предыдущему узлу
	} while (p != NULL); // условие окончания обхода
}
list* find(list* cur, int value)
{
	while (cur)
	{
		if (cur->field == value)
			return cur;
		else cur = cur->next;
	}
}
	struct list * deletelem(list *lst)
	{
		struct list *prev, *next;
		prev = lst->prev; // узел, предшествующий lst
		next = lst->next; // узел, следующий за lst
		if (prev != NULL)
			prev->next = lst->next; // переставляем указатель
		if (next != NULL)
			next->prev = lst->prev; // переставляем указатель
		free(lst); // освобождаем память удаляемого элемента
		return(prev);
	}
	struct list * deletehead(list *root)
	{
		struct list *temp;
		temp = root->next;
		temp->prev = NULL;
		free(root);   // освобождение памяти текущего корня
		return(temp); // новый корень списка
	}
	list* addelem2(list* lst)
	{
		list* t;
		t = (list*)malloc(sizeof(list));
		t->field = 666;
		t->next = lst;
		t->prev = NULL;
		return t;
	   }
	list* addelem3(list* lst,list* head)
	{
		list* t,*p;
		t = (list*)malloc(sizeof(list));
		t->field = 333;
		p = lst->prev;
		lst->prev = t;
		if (p != NULL)
			p->next= t;
		t->next = lst;
		t->prev = p;
		return head;
	}
int main()
{
	list* head, *cur;
	head=init(777);
	cur = head;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		head = addelem(head, i);
	}
	
	listprint(cur);//в прямом
	putchar('\n');
	listprintr(cur);// в обратном вывод
	list* f = find(cur,2);
	f = addelem(f, 888);
	putchar('\n');
	listprint(cur);//в прямом
	list *w= deletelem(f);
	putchar('\n');
	listprint(cur);
	w = deletehead(cur);
	putchar('\n');
	listprint(w);
	cur = addelem2(w);
	putchar('\n');
	listprint(cur);//в прямом
	f = find(cur, 2);
	list* k=addelem3(f,cur);
	putchar('\n');
	listprint(k);//в прямом
	_getch();
	return 0;
}