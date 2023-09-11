#include "Ease.h"
#include <math.h>

namespace Ease
{
	float InQuadFloat(const float start, const float end, const float time)
	{
		float t = powf(time, 2);

		return start * (1.0f - t) + end * t;
	}

	float OutQuadFloat(const float start, const float end, const float time)
	{
		float t = (1 - powf(1 - time, 2));

		return start * (1.0f - t) + end * t;
	}

	float InOutQuadFloat(const float start, const float end, const float time)
	{
		float t;
		if (time < 0.5f)
		{
			t = 2 * powf(time, 2);
		}
		else
		{
			t = (1 - powf(-2 * time + 2, 2) / 2);
		}

		return start * (1.0f - t) + end * t;
	}
}