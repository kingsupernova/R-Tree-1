#ifndef SJTU_RTREECOMMON_HPP
#define SJTU_RTREECOMMON_HPP

#include <cstddef>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cfloat>

namespace sjtu{

struct Bound{
	double lowerBound, upperBound;

	Bound();
	Bound(const double &x, const double &y);

	friend Bound operator +(const Bound &a, const Bound &b) {
		return Bound(std::min(a.lowerBound, b.lowerBound),
				     std::max(a.upperBound, b.upperBound));
	}

};

template<size_t M>
class HyperBound{
friend HyperBound<M> operator +(const HyperBound<M> &a, const HyperBound<M> &b) {
	HyperBound<M> ret;
	for (int i = 0; i < M; i++) {
		ret.bounds[i] = a.bounds[i] + b.bounds[i];
	}
	return ret;
}
private:
	Bound bounds[M];

public:
	HyperBound();
	HyperBound(const std::vector<Bound> &rhs);

	double area()const;
	bool isOverLap(const HyperBound<M> &rhs)const;

};

#include "source/RTreeCommon.cpp"

}

#endif
