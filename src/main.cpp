
#include "zone.hpp"

int main()
{
    Zone z(100,100);
	z.init();
	z.run(5000,false,true);
	z.clean();
    return 0;
}