#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	char elem;
	Node* left;
	Node* right;

	Node() 
	{ 
		this->left = nullptr; 
		this->right = nullptr; 
	}
	Node(char elem) 
	{ 
		this->left = nullptr; 
		this->right = nullptr; 
		this->elem = elem; 
	}
};

class List
{
private: 
	char badelem;
	Node* Head;
	Node* Tail;
public:
	List()
	{
		this->Head = nullptr;
		this->Tail = nullptr;
		this->badelem = 'a';
	}
	List(char badelem) 
	{ 
		this->Head = nullptr;
		this->Tail = nullptr;
		this->badelem = badelem; 
	}
	~List()
	{
		while (this->Tail != nullptr)
			this->pop_back();
	}
	void pop_back()
	{
		if (this->Tail == nullptr) return;
		Node* ForDel = this->Tail;
		if (this->Tail == this->Head)
		{
			this->Tail = nullptr;
			this->Head = nullptr;
		}
		else
		{
			this->Tail = this->Tail->left;
			this->Tail->right = nullptr;
			if (this->Tail == this->Head)this->Head->right = this->Tail;
		}
		delete ForDel;
	}
	void push_back(char elem) 
	{
		if (elem == this->badelem)
			pop_back();
		if (this->Tail == nullptr)
		{
			this->Tail = new Node(elem);
			this->Head = this->Tail;
			return;
		}
		else if (this->Tail == this->Head)
		{
			this->Tail->right = new Node(elem);
			this->Tail = this->Tail->right;
			this->Head->right = this->Tail;
			this->Tail->left = this->Head;
		}
		else
		{
			Node* node = this->Tail;
			this->Tail->right = new Node(elem);
			this->Tail = this->Tail->right;
			this->Tail->left = node;
		}
	}
	void print()
	{
		Node* cur = this->Head;
		if (cur == nullptr) return;
		do
		{
			if (cur != nullptr)
			{
				cout << cur->elem << " ";
				cur = cur->right;
			}
			else break;
		}while (cur != this->Tail);
		if (cur != nullptr) cout << cur->elem << " ";
	}
};