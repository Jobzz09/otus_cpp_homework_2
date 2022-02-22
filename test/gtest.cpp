#include <gtest/gtest.h>
#include "common.h"

TEST(google_test_1, test1) {
    ASSERT_TRUE(getUlongValueOfIpv4(tmp) == 4244897280);
}