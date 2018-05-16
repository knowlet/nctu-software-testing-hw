#include "nextdate.h"
#include "gtest/gtest.h"

namespace {
TEST(NextDateProblem, BoundaryValueNormal)
{
	EXPECT_EQ(20000102, nextdate(YEAR_NOM, JAN, DAY_MIN));
	EXPECT_EQ(20000103, nextdate(YEAR_NOM, JAN, DAY_MIN + 1));
    EXPECT_EQ(20000116, nextdate(YEAR_NOM, JAN, DAY_NOM));
	EXPECT_EQ(20000131, nextdate(YEAR_NOM, JAN, DAY_MAX[JAN] - 1));
	EXPECT_EQ(20000201, nextdate(YEAR_NOM, JAN, DAY_MAX[JAN]));

	EXPECT_EQ(20000202, nextdate(YEAR_NOM, FEB, DAY_MIN));
	EXPECT_EQ(20000203, nextdate(YEAR_NOM, FEB, DAY_MIN + 1));
    EXPECT_EQ(20000216, nextdate(YEAR_NOM, FEB, DAY_NOM));
	EXPECT_EQ(20000228, nextdate(YEAR_NOM, FEB, DAY_MAX[FEB] - 1));
    // c1
	EXPECT_EQ(20000229, nextdate(YEAR_NOM, FEB, DAY_MAX[FEB]));
    // c0
    EXPECT_EQ(20180301, nextdate(YEAR_MAX, FEB, DAY_MAX[FEB]));

    EXPECT_EQ(20000302, nextdate(YEAR_NOM, MAR, DAY_MIN));
	EXPECT_EQ(20000303, nextdate(YEAR_NOM, MAR, DAY_MIN + 1));
    EXPECT_EQ(20000316, nextdate(YEAR_NOM, MAR, DAY_NOM));
	EXPECT_EQ(20000331, nextdate(YEAR_NOM, MAR, DAY_MAX[MAR] - 1));
	EXPECT_EQ(20000401, nextdate(YEAR_NOM, MAR, DAY_MAX[MAR]));

    EXPECT_EQ(20000402, nextdate(YEAR_NOM, APR, DAY_MIN));
	EXPECT_EQ(20000403, nextdate(YEAR_NOM, APR, DAY_MIN + 1));
    EXPECT_EQ(20000416, nextdate(YEAR_NOM, APR, DAY_NOM));
	EXPECT_EQ(20000430, nextdate(YEAR_NOM, APR, DAY_MAX[APR] - 1));
	EXPECT_EQ(20000501, nextdate(YEAR_NOM, APR, DAY_MAX[APR]));

    EXPECT_EQ(20000502, nextdate(YEAR_NOM, MAY, DAY_MIN));
	EXPECT_EQ(20000503, nextdate(YEAR_NOM, MAY, DAY_MIN + 1));
    EXPECT_EQ(20000516, nextdate(YEAR_NOM, MAY, DAY_NOM));
	EXPECT_EQ(20000531, nextdate(YEAR_NOM, MAY, DAY_MAX[MAY] - 1));
	EXPECT_EQ(20000601, nextdate(YEAR_NOM, MAY, DAY_MAX[MAY]));

    EXPECT_EQ(20000602, nextdate(YEAR_NOM, JUN, DAY_MIN));
	EXPECT_EQ(20000603, nextdate(YEAR_NOM, JUN, DAY_MIN + 1));
    EXPECT_EQ(20000616, nextdate(YEAR_NOM, JUN, DAY_NOM));
	EXPECT_EQ(20000630, nextdate(YEAR_NOM, JUN, DAY_MAX[JUN] - 1));
	EXPECT_EQ(20000701, nextdate(YEAR_NOM, JUN, DAY_MAX[JUN]));

    EXPECT_EQ(20000702, nextdate(YEAR_NOM, JUL, DAY_MIN));
	EXPECT_EQ(20000703, nextdate(YEAR_NOM, JUL, DAY_MIN + 1));
    EXPECT_EQ(20000716, nextdate(YEAR_NOM, JUL, DAY_NOM));
	EXPECT_EQ(20000731, nextdate(YEAR_NOM, JUL, DAY_MAX[JUL] - 1));
	EXPECT_EQ(20000801, nextdate(YEAR_NOM, JUL, DAY_MAX[JUL]));

    EXPECT_EQ(20000802, nextdate(YEAR_NOM, AUG, DAY_MIN));
	EXPECT_EQ(20000803, nextdate(YEAR_NOM, AUG, DAY_MIN + 1));
    EXPECT_EQ(20000816, nextdate(YEAR_NOM, AUG, DAY_NOM));
	EXPECT_EQ(20000831, nextdate(YEAR_NOM, AUG, DAY_MAX[AUG] - 1));
	EXPECT_EQ(20000901, nextdate(YEAR_NOM, AUG, DAY_MAX[AUG]));

    EXPECT_EQ(20000902, nextdate(YEAR_NOM, SEP, DAY_MIN));
	EXPECT_EQ(20000903, nextdate(YEAR_NOM, SEP, DAY_MIN + 1));
    EXPECT_EQ(20000916, nextdate(YEAR_NOM, SEP, DAY_NOM));
	EXPECT_EQ(20000930, nextdate(YEAR_NOM, SEP, DAY_MAX[SEP] - 1));
	EXPECT_EQ(20001001, nextdate(YEAR_NOM, SEP, DAY_MAX[SEP]));

    EXPECT_EQ(20001002, nextdate(YEAR_NOM, OCT, DAY_MIN));
	EXPECT_EQ(20001003, nextdate(YEAR_NOM, OCT, DAY_MIN + 1));
    EXPECT_EQ(20001016, nextdate(YEAR_NOM, OCT, DAY_NOM));
	EXPECT_EQ(20001031, nextdate(YEAR_NOM, OCT, DAY_MAX[OCT] - 1));
	EXPECT_EQ(20001101, nextdate(YEAR_NOM, OCT, DAY_MAX[OCT]));

    EXPECT_EQ(20001102, nextdate(YEAR_NOM, NOV, DAY_MIN));
	EXPECT_EQ(20001103, nextdate(YEAR_NOM, NOV, DAY_MIN + 1));
    EXPECT_EQ(20001116, nextdate(YEAR_NOM, NOV, DAY_NOM));
	EXPECT_EQ(20001130, nextdate(YEAR_NOM, NOV, DAY_MAX[NOV] - 1));
	EXPECT_EQ(20001201, nextdate(YEAR_NOM, NOV, DAY_MAX[NOV]));

    EXPECT_EQ(20001202, nextdate(YEAR_NOM, DEC, DAY_MIN));
	EXPECT_EQ(20001203, nextdate(YEAR_NOM, DEC, DAY_MIN + 1));
    EXPECT_EQ(20001216, nextdate(YEAR_NOM, DEC, DAY_NOM));
	EXPECT_EQ(20001231, nextdate(YEAR_NOM, DEC, DAY_MAX[DEC] - 1));
	EXPECT_EQ(20010101, nextdate(YEAR_NOM, DEC, DAY_MAX[DEC]));

}

TEST(NextDateProblem, BoundaryValueRobust)
{
    // year min - 1
	EXPECT_THROW(nextdate(YEAR_MIN - 1, MONTH_MIN, DAY_MIN), std::out_of_range);
	// month min - 1
	EXPECT_THROW(nextdate(YEAR_NOM, MONTH_MIN - 1, 1), std::out_of_range);
	// day min - 1
	EXPECT_THROW(nextdate(YEAR_NOM, 1, DAY_MIN - 1), std::out_of_range);

	// year max + 1
	EXPECT_THROW(nextdate(YEAR_MAX + 1, 1, 1), std::out_of_range);

	// month max + 1
	EXPECT_THROW(nextdate(YEAR_NOM, MONTH_MAX + 1, 1), std::out_of_range);

	// day max + 1 for months with 31/30/28 days
	EXPECT_THROW(nextdate(YEAR_NOM, 1, DAY_MAX[JAN] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_NOM, 4, DAY_MAX[APR] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_NOM, 2, DAY_MAX[FEB] + 2), std::out_of_range);
    // year min-1, month min-1
	EXPECT_THROW(nextdate(YEAR_MIN - 1, MONTH_MIN - 1, 1), std::out_of_range);

	// year min-1, day min-1
	EXPECT_THROW(nextdate(YEAR_MIN - 1, 1, DAY_MIN - 1), std::out_of_range);

	// month min-1, day min-1
	EXPECT_THROW(nextdate(YEAR_NOM, MONTH_MIN - 1, DAY_MIN - 1), std::out_of_range);

	// year min-1, month min-1, day min-1
	EXPECT_THROW(nextdate(YEAR_MIN - 1, MONTH_MIN - 1, DAY_MIN - 1), std::out_of_range);

	/* ----------------------------------- */

	// year max+1, month max+1
	EXPECT_THROW(nextdate(YEAR_MAX + 1, MONTH_MAX + 1, 1), std::out_of_range);

	// year max+1, day max+1
	EXPECT_THROW(nextdate(YEAR_MAX + 1, MONTH_MIN, DAY_MAX[JAN] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_MAX + 1, MONTH_MIN, DAY_MAX[APR] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_MAX + 1, MONTH_MIN, DAY_MAX[FEB] + 1), std::out_of_range);

	// month max+1, day max+1
	EXPECT_THROW(nextdate(YEAR_NOM, MONTH_MAX + 1, DAY_MAX[JAN] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_NOM, MONTH_MAX + 1, DAY_MAX[APR] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_NOM, MONTH_MAX + 1, DAY_MAX[FEB] + 1), std::out_of_range);

	// year max+1, month max+1, day max+1
	EXPECT_THROW(nextdate(YEAR_MAX + 1, MONTH_MAX + 1, DAY_MAX[JAN] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_MAX + 1, MONTH_MAX + 1, DAY_MAX[APR] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_MAX + 1, MONTH_MAX + 1, DAY_MAX[FEB] + 1), std::out_of_range);


	// one max+1, one min-1, one normal
	EXPECT_THROW(nextdate(YEAR_NOM, MONTH_MAX + 1, DAY_MIN - 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_NOM, MONTH_MIN - 1, DAY_MAX[JAN] + 1), std::out_of_range);

	EXPECT_THROW(nextdate(YEAR_MAX + 1, 1, DAY_MIN - 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_MIN - 1, 1, DAY_MAX[JAN] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_MIN - 1, 1, DAY_MAX[APR] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_MIN - 1, 1, DAY_MAX[FEB] + 1), std::out_of_range);

	EXPECT_THROW(nextdate(YEAR_MAX + 1, MONTH_MIN - 1, 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_MIN - 1, MONTH_MAX + 1, 1), std::out_of_range);

	// one max+1, two min-1
	EXPECT_THROW(nextdate(YEAR_MAX + 1, MONTH_MIN - 1, DAY_MIN - 1), std::out_of_range);

	EXPECT_THROW(nextdate(YEAR_MIN - 1, MONTH_MAX + 1, DAY_MIN - 1), std::out_of_range);

	EXPECT_THROW(nextdate(YEAR_MIN - 1, MONTH_MIN - 1, DAY_MAX[JAN] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_MIN - 1, MONTH_MIN - 1, DAY_MAX[APR] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_MIN - 1, MONTH_MIN - 1, DAY_MAX[FEB] + 1), std::out_of_range);

	// two max+1, one min-1
	EXPECT_THROW(nextdate(YEAR_MAX + 1, MONTH_MAX + 1, DAY_MIN - 1), std::out_of_range);

	EXPECT_THROW(nextdate(YEAR_MAX + 1, MONTH_MIN - 1, DAY_MAX[JAN] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_MAX + 1, MONTH_MIN - 1, DAY_MAX[APR] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_MAX + 1, MONTH_MIN - 1, DAY_MAX[FEB] + 1), std::out_of_range);

	EXPECT_THROW(nextdate(YEAR_MIN - 1, MONTH_MAX + 1, DAY_MAX[JAN] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_MIN - 1, MONTH_MAX + 1, DAY_MAX[APR] + 1), std::out_of_range);
	EXPECT_THROW(nextdate(YEAR_MIN - 1, MONTH_MAX + 1, DAY_MAX[FEB] + 1), std::out_of_range);
}

TEST(NextDateProblem, BoundaryValueSpecialValue)
{

    EXPECT_THROW(nextdate(1, 2, 3), std::out_of_range);
    EXPECT_EQ(20180305, nextdate(2018, 3, 4));
}

TEST(NextDateTest, CodeCoverageC0) {
	EXPECT_THROW(nextdate(1811, 13, 30), std::out_of_range);
	EXPECT_EQ(20010101, nextdate(2000, 12, 31));
}

TEST(NextDateTest, CodeCoverageC1) {
	EXPECT_THROW(nextdate(1811, 13, 30), std::out_of_range);
	EXPECT_EQ(20001130, nextdate(2000, 11, 29));
	EXPECT_EQ(20001201, nextdate(2000, 11, 30));
	EXPECT_EQ(20010101, nextdate(2000, 12, 31));
}

TEST(NextDateTest, CodeCoverageC2) {
	EXPECT_THROW(nextdate(1811, 13, 30), std::out_of_range);
	EXPECT_EQ(20001130, nextdate(2000, 11, 29));
	EXPECT_EQ(20001201, nextdate(2000, 11, 30));
	EXPECT_EQ(20010101, nextdate(2000, 12, 31));
}

TEST(NextDateTest, CodeCoverageMCDC) {
	EXPECT_THROW(nextdate(1811, 1, 1), std::out_of_range);
	EXPECT_THROW(nextdate(2000, 0, 1), std::out_of_range);
	EXPECT_THROW(nextdate(1811, 1, 0), std::out_of_range);
	EXPECT_THROW(nextdate(2019, 1, 1), std::out_of_range);
	EXPECT_THROW(nextdate(2000, 13, 1), std::out_of_range);
	EXPECT_THROW(nextdate(2000, 2, 30), std::out_of_range);
}

}  // namespace
