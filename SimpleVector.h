#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_
#include <iostream>
#include <algorithm>
using namespace std;
// Ŭ������ �̸��� SimpleVector��� �մϴ�.
template<typename T>
class SimpleVector {
private:
	// Ÿ�Կ� �������� �ʰ� �����͸� ������ �ִ� �迭�� ��������� �����ϴ�.
	T* arr;
	int currentSize;
	int currentCapacity;

public:
	// �����ڴ� �Ʒ��� ���� ���� �մϴ�.

	// - �⺻ �����ڴ� ũ�Ⱑ 10�� �迭�� ����ϴ�.
	// - ���ڸ� �ϳ� �޴� �����ڴ� �ش� ���ڿ� �ش�Ǵ� ũ���� �迭�� ����ϴ�.
	SimpleVector(int capacity = 10) : currentSize(0), currentCapacity(capacity) {
		arr = new T[currentCapacity];
	}

	~SimpleVector() {
		delete[] arr;
	}

	// - size�� ���ڰ� ���� ���� ������ ������ ��ȯ�մϴ�.
	int size() const {
		return currentSize;
	}

	// - capacity ���� ���� �迭�� ũ�⸦ ��ȯ�մϴ�.
	int capacity() const {
		return currentCapacity;
	}

	// �Ʒ��� ���� ����Լ��� ���� �մϴ�.

	// - push_back  ���ڷ� ���� ���Ҹ�  �� �ڿ� �߰� �մϴ�.��ȯ���� �����ϴ�.
	// - push_back���� �迭�� ũ�Ⱑ �� á�µ� ���Ұ� �� ���ð��, ���� �迭���� ũ�⸦ 5��ŭ �� �ø��� ���ο� ���ұ��� �߰��˴ϴ�.(������ �ִ� ���� �����Ǿ� �մϴ�.)
	void push_back(const T& value) {
		if (currentSize >= currentCapacity) {
			resize(currentCapacity + 5);
		}
		arr[currentSize++] = value;
	}

	// - pop_back�� ������ ������ ���Ҹ� ���� �մϴ�. ���� ������ ���Ұ� ���ٸ� �ƹ� ���۵� ���� ������, ���� �� ��ȯ���� �����ϴ�.
	void pop_back() {
		if (currentSize > 0) {
			currentSize--;
		}
	}

	// - resize�� ���� �ϳ��� ���ڷ� �޽��ϴ�.  �ش� ������ ���� �迭�� ũ�⺸�� ������ �ƹ� ���۵� ���� �ʽ��ϴ�. ���� ���� �迭���� ũ�Ⱑ ũ�� �ش� ����ŭ ũ�⸦ ���Ҵ� �մϴ�.(���� ���Ҵ� �״�� �־�� �մϴ�.)
	void resize(int newCapacity) {
		if (newCapacity > currentCapacity) {
			T* newArr = new T[newCapacity];
			for (int i = 0; i < currentSize; i++) {
				newArr[i] = arr[i];
			}
			delete[] arr;
			arr = newArr;
			currentCapacity = newCapacity;
		}
	}

	// - sortData�� ���� �����͸� �����ϴ� �Լ� �Դϴ�.���� �������� �ʰ� STL�� sort�Լ��� Ȱ���ؼ� ���� �մϴ�.
	void sortData() {
		sort(arr, arr + currentSize);
		//sort(arr);
	}

};
#endif // !SIMPLEVECTOR_H_
