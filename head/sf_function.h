/*
 * sf_function.h
 *
 *  Created on: 2017年9月7日
 *      Author: us
 */

#ifndef SF_FUNCTION_H_
#define SF_FUNCTION_H_


template<class T>
class LessCompare
{
public:
	bool operator()(const T& left, const T& right) const
	{
		return left < right;
	}
};

template<class T>
class GreaterCompare
{
public:
	bool operator( )( const T& left, const T& right) const
	{
		return left > right;
	}
};



#endif /* SF_FUNCTION_H_ */
