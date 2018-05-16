#include "gtest/gtest.h"
#include "commission.h"

namespace {
TEST(CommissionTest, NormalBoundary) {
	//Barrel
	EXPECT_EQ(2800 , count_commission(35, 40, 1)); //min
	EXPECT_EQ(2825 , count_commission(35, 40, 2)); //min+1
	EXPECT_EQ(5000 , count_commission(35, 40, 89)); //max-1
	EXPECT_EQ(5025 , count_commission(35, 40, 90)); //max
	//Stock
	EXPECT_EQ(2730 , count_commission(35, 1, 45)); //min
	EXPECT_EQ(2760 , count_commission(35, 2, 45)); //min+1
	EXPECT_EQ(5070 , count_commission(35, 79, 45)); //max-1
	EXPECT_EQ(5100 , count_commission(35, 80, 45)); //max
	//Lock
	EXPECT_EQ(2370 , count_commission(1, 40, 45)); //min
	EXPECT_EQ(2415 , count_commission(2, 40, 45)); //min+1
	EXPECT_EQ(5430 , count_commission(69, 40, 45)); //max-1
	EXPECT_EQ(5475 , count_commission(70, 40, 45)); //max
	//all middle
	EXPECT_EQ(3900 , count_commission(35, 40, 45));
}

TEST(CommissionTest, Equivalence) {
	// Weak Normal & Strong Normal Equivalence Class
	EXPECT_EQ(3900 , count_commission(35, 40, 45));
	//Weak Robust Equivalence Class
	EXPECT_THROW(count_commission(0, 40, 45), std::out_of_range);
	EXPECT_THROW(count_commission(71, 40, 45), std::out_of_range);
	EXPECT_THROW(count_commission(35, 0, 45), std::out_of_range);
	EXPECT_THROW(count_commission(35, 81, 45), std::out_of_range);
	EXPECT_THROW(count_commission(35, 40, 0), std::out_of_range);
	EXPECT_THROW(count_commission(35, 40, 91), std::out_of_range);
	//Strong Robust Equivalence Class
	EXPECT_THROW(count_commission(-1, 40, 45), std::out_of_range);
	EXPECT_THROW(count_commission(35, -1, 45), std::out_of_range);
	EXPECT_THROW(count_commission(35, 40, -1), std::out_of_range);
	EXPECT_THROW(count_commission(-1, -1, 45), std::out_of_range);
	EXPECT_THROW(count_commission(-1, 40, -1), std::out_of_range);
	EXPECT_THROW(count_commission(35, -1, -1), std::out_of_range);
	EXPECT_THROW(count_commission(-1, -1, -1), std::out_of_range);
}

TEST(CommissionTest, CodeCoverageC0) {
	EXPECT_THROW(count_commission(0, 1, 1), std::out_of_range);
	EXPECT_EQ(7700 , count_commission(69, 79, 89));
}

TEST(CommissionTest, CodeCoverageC1) {
	EXPECT_THROW(count_commission(0, 1, 1), std::out_of_range);
	EXPECT_EQ(1800 , count_commission(20, 20, 12));
	EXPECT_EQ(7700 , count_commission(69, 79, 89));
}

TEST(CommissionTest, CodeCoverageC2) {
	EXPECT_THROW(count_commission(0, 1, 1), std::out_of_range);
	EXPECT_EQ(1000 , count_commission(10, 10, 10));
	EXPECT_EQ(1800 , count_commission(20, 20, 12));
	EXPECT_EQ(7700 , count_commission(69, 79, 89));
}

TEST(CommissionTest, CodeCoverageMCDC) {
	EXPECT_THROW(count_commission(0, 1, 1), std::out_of_range);
	EXPECT_THROW(count_commission(1, 0, 1), std::out_of_range);
	EXPECT_THROW(count_commission(1, 1, 0), std::out_of_range);
	EXPECT_THROW(count_commission(71, 1, 1), std::out_of_range);
	EXPECT_THROW(count_commission(1, 81, 1), std::out_of_range);
	EXPECT_THROW(count_commission(1, 1, 91), std::out_of_range);
	EXPECT_EQ(1800 , count_commission(20, 20, 12));
}

}