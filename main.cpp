
#include "zone.hpp"

int main()
{
    Zone z(10,10);
	z.init();
	for (int i(0) ; i <= 10 ; i++)
	{
		z.step(false);
	}
	z.clean();
    return 0;
}