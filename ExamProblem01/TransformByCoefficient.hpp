#pragma once

#include "TransformFunction.h"

template <typename TSample>
class TransformByCoefficient : public TransformFunction<TSample>
{
	double coeff;

public:
	TransformByCoefficient(double _coeff = 1);
	TSample operator()(const TSample& sample, unsigned inx) override;
};

template<typename TSample>
inline TransformByCoefficient<TSample>::TransformByCoefficient(double _coeff)
{
	coeff = _coeff;
}

template <typename TSample>
TSample TransformByCoefficient<TSample>::operator()(const TSample& sample, unsigned inx)
{
	TSample transformedSample = sample * coeff;
	return transformedSample;
}

