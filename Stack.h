#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <class S>
class Stack : public LinkedList<S>{
	private:
		int max =10;
	public:
		bool Delete (S &element){
			//first가 0이면 false반환
			if(this->first==0){
				return false;
			}

			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			Node<S>* current=this->first;
			element=current->data;
			this->first=current->link;
			delete current;
			this->current_size--;
			return true;
		}
		bool Insert(S element){
			if(this->current_size>max){
				return false;
			}
			Node<S> *newn = new Node<S>(element);
			newn -> link = this->first;
			this->first = newn;
			this->current_size++;
			return true;
		}
		
};

