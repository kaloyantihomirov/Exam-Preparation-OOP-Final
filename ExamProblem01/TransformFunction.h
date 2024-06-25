#pragma once

template <typename TSample>
class TransformFunction
{
public:
	virtual TSample operator()(const TSample& sample, unsigned ind) = 0;
};