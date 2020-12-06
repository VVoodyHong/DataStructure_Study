#ifndef DLINKEDQUEUE_H
#define DLINKEDQUEUE_H
#pragma warning(disable:4290)
#include "RuntimeException.h"

/////////////////////////////////////////////////////////////////////////////////////
typedef string Elem;								// 원소 타입
class DNode											// 이중 연결 리스트 노드
{
private:
	Elem elem;										// 노드 원소 값
	DNode* prev;									// 리스트의 이전 노드
	DNode* next;									// 리스트의 다음 노드
	friend class DLinkedList;						// DLinkedList에게 접근 허용
};
class DLinkedList									// 이중 연결 리스트
{
public:
	DLinkedList();									// 생성장
	~DLinkedList();									// 소멸자
	bool empty() const;								// 비었나?
	const Elem& front() const;						// 앞의 원소
	const Elem& back() const;						// 뒤의 원소
	void addFront(const Elem& e);					// 리스트 앞에 추가
	void addBack(const Elem& e);					// 리스트 뒤에 추가
	void removeFront();								// 앞에서 제거
	void removeBack();								// 뒤에서 제거
private:
	DNode* header;									// 리스트 센티널
	DNode* trailer;
protected:
	void add(DNode* v, const Elem& e);				// v 전에 새로운 노드 삽입
	void remove(DNode* v);							// v 노드 제거
};
DLinkedList::DLinkedList()
{
	header = new DNode;
	trailer = new DNode;

	header->elem = "HEADER";
	trailer->elem = "trailer";

	header->next = trailer;
	header->prev = trailer;
	trailer->next = header;
	trailer->prev = header;
}
DLinkedList::~DLinkedList()
{
	while (!empty()) removeFront();
	delete header;
	delete trailer;
}
bool DLinkedList::empty() const
{
	return (header->next == trailer);
}
const Elem& DLinkedList::front() const
{
	return header->next->elem;
}
const Elem& DLinkedList::back() const
{
	return trailer->prev->elem;
}
void DLinkedList::add(DNode* v, const Elem& e)
{
	DNode* u = new DNode;
	u->elem = e;
	u->next = v->next;
	v->next->prev = u;
	u->prev = v;
	v->next = u;
}
void DLinkedList::addFront(const Elem& e)
{
	add(header, e);
}
void DLinkedList::addBack(const Elem& e)
{
	add(trailer->prev, e);
}
void DLinkedList::remove(DNode* v)
{
	DNode* u = v->prev;
	DNode* w = v->next;
	u->next = w;
	w->prev = u;
	delete v;
}
void DLinkedList::removeFront()
{
	remove(header->next);
}
void DLinkedList::removeBack()
{
	remove(trailer->prev);
}
/////////////////////////////////////////////////////////////////////////////////////

class DLinkedDeque									// 이중 연결 리스트 데크
{
public:
	DLinkedDeque();									// 생성자
	int size() const;								// 데크 내의 원소 개수
	bool empty() const;								// 비었나?
	const Elem& front() const throw(DequeEmpty);	// 첫 번째 원소
	const Elem& back() const throw(DequeEmpty);		// 마지막 원소
	void insertFront(const Elem& e);				// 첫 번째 원소 삽입
	void insertBack(const Elem& e);					// 마지막 원소 삽입
	void removeFront() throw(DequeEmpty);			// 첫 번째 원소 삭제
	void removeBack() throw(DequeEmpty);			// 마지막 원소 삭제
private:
	DLinkedList D;									// 원소들의 이중 연결 리스트
	int n;											// 원소의 개수
};

DLinkedDeque::DLinkedDeque() : D(), n(0) {}
int DLinkedDeque::size() const { return n; }
bool DLinkedDeque::empty() const { return n == 0; }
const Elem& DLinkedDeque::front() const throw(DequeEmpty)
{
	return D.front();
}
const Elem& DLinkedDeque::back() const throw(DequeEmpty)
{
	return D.back();
}
void DLinkedDeque::insertFront(const Elem& e)
{
	D.addFront(e);
	n++;
}
void DLinkedDeque::insertBack(const Elem& e)
{
	D.addBack(e);
	n++;
}
void DLinkedDeque::removeFront() throw(DequeEmpty)
{
	if (empty())	throw DequeEmpty("removeFront of empty deque");
	D.removeFront();
	n--;
}
void DLinkedDeque::removeBack() throw(DequeEmpty)
{
	if (empty())	throw DequeEmpty("removeBack of empty deque");
	D.removeBack();
	n--;
}
#endif