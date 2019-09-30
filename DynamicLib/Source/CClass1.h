#ifndef C_CLASS_1_H
#define C_CLASS_1_H

#include "IClass1.h"

namespace dlib
{
	class CClass1 : public IClass1
	{
	public:
		virtual ~CClass1();
		virtual unsigned int Get0() const override;
		virtual unsigned int Get1() const override;
		virtual unsigned int Get2() const override;
		virtual unsigned int Get3() const override;
		virtual unsigned int Get4() const override;
		virtual unsigned int Get5() const override { return 0; }
		virtual unsigned int Get6() const override { return 0; }
		virtual unsigned int Get7() const override { return 0; }
		virtual unsigned int Get8() const override { return 0; }
		virtual unsigned int Get9() const override { return 0; }
		virtual unsigned int Get10() const override { return 0; }
		virtual unsigned int Get11() const override { return 0; }
		virtual unsigned int Get12() const override { return 0; }
		virtual unsigned int Get13() const override { return 0; }
		virtual unsigned int Get14() const override { return 0; }
		virtual unsigned int Get15() const override { return 0; }
		virtual unsigned int Get16() const override { return 0; }
		virtual unsigned int Get17() const override { return 0; }
		virtual unsigned int Get18() const override { return 0; }
		virtual unsigned int Get19() const override { return 0; }
		virtual unsigned int Get20() const override { return 0; }
		virtual unsigned int Get21() const override { return 0; }
		virtual unsigned int Get22() const override { return 0; }
		virtual unsigned int Get23() const override { return 0; }
		virtual unsigned int Get24() const override { return 0; }
		virtual unsigned int Get25() const override { return 0; }
		virtual unsigned int Get26() const override { return 0; }
		virtual unsigned int Get27() const override { return 0; }
		virtual unsigned int Get28() const override { return 0; }
		virtual unsigned int Get29() const override { return 0; }
		virtual unsigned int Get30() const override { return 0; }
		virtual void ProcessStruct1(const sStruct1& aStruct1, const sStruct2& aStruct2) const override;
	};
}

#endif
