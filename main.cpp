
#include "zone.hpp"

int main()
{
    Zone z(10,10);
	z.init();
	z.step(true);
	z.step(true);
	z.step(true);
	z.step(true);
	z.clean();
    return 0;
}