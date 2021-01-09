#ifdef TEST

#include <Any/allocator.h>
#include "../Struct/Point.test.h"
#include "math_ext.test.h"
#include "../Model/ModalModel.test.h"
#include "../Model/ImageModel.test.h"
#include "../Model/ButtonModel.test.h"
#include "../Any/Map.test.h"

namespace ii887522::viewify
{
	static int main()
	{
		testPoint();
		testMathExt();
		testModalModel();
		testImageModel();
		testButtonModel();
		testMap();
		return 0;
	}
}

int main()
{
	return ii887522::viewify::main();
}

#endif
