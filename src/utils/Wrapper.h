#ifndef WRAPPER_H
#define WRAPPER_H

template<class T>
class Wrapper
{
public:
	Wrapper(T* p = 0) : _ptr(p) {}
	Wrapper(const T& rhs) { _ptr = rhs.clone(); }
	Wrapper(const Wrapper<T>& rhs) { if (rhs._ptr != 0) _ptr = rhs._ptr->clone(); else _ptr = 0; }

	~Wrapper() {
		if (_ptr != 0) {
			_ptr = 0;
			delete _ptr;
		}
	}

	Wrapper& operator=(const Wrapper<T>& rhs)
	{
		if (this != &rhs)
		{
			if (_ptr != 0) delete _ptr;
			_ptr = (rhs._ptr != 0) ? rhs._ptr->clone() : 0;
		}
		return *this;
	}

	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }

	const T& operator*() const { return *_ptr; }
	const T* const operator->() const { return _ptr; }

private:
	T* _ptr;
};

#endif