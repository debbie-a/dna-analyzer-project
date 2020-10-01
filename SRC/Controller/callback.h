#ifndef __CALLBACK_H__
#define __CALLBACK_H__

#include <string>
#include <vector>


class CallbackBase
{
public:
        virtual ~CallbackBase();
  	virtual std::string operator()(const std::string &, std::vector<std::string>&) const;
  	
};


inline CallbackBase::~CallbackBase() 
{}

inline std::string CallbackBase::operator()(const std::string &, std::vector<std::string>&) const 
{ 
        return ""; 
}


template<typename T>
class Callback : public CallbackBase
{
public:
	typedef typename std::string (T::*F)(const std::string &, std::vector<std::string>&) const;
        
        Callback(T& t, F f);

  	/*virtual*/ std::string operator()(const std::string &str, std::vector<std::string>& vec) const;

private:
  	T* t_;
  	F  f_;
};


template<typename T>
inline Callback<T>::Callback(T& t, F f) : t_(&t),f_(f)
{}

template<typename T>
inline std::string Callback<T>::operator()(const std::string &str, std::vector<std::string>& vec) const
{ 
        return (t_->*f_)(str, vec); 
}

template<typename T>
inline Callback<T> makeCallback(T& t, std::string(T::*f)(const std::string &, std::vector<std::string>&)const)
{
  	return Callback<T>(t, f);
}

#endif /*__CALLBACK_H__*/
