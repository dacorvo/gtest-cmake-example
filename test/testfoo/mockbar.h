#include "gmock/gmock.h"
#include "ibar.h"

class MockBar: public IBar
{
public:
    MOCK_METHOD0(qux, bool());
    MOCK_METHOD0(norf, bool());
};
