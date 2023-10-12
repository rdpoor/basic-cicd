#include "unity.h"
#include "fff.h"
#include "a.h"  // You'll be faking these
#include "b.h"  // You're testing these

// Faking a's functions
FAKE_VOID_FUNC(a_init, a_ctx_t*);
FAKE_VOID_FUNC(a_set_count, a_ctx_t*, int);
FAKE_VALUE_FUNC(int, a_get_count, a_ctx_t*);

void setUp(void) {
    RESET_FAKE(a_init)
    RESET_FAKE(a_set_count)
    RESET_FAKE(a_get_count)
}

void tearDown(void) {}

void test_b_increment_count(void) {
    a_ctx_t a;
    a_get_count_fake.return_val = 3;
    
    b_increment_count(&a);
    
    TEST_ASSERT_EQUAL(1, a_get_count_fake.call_count);
    TEST_ASSERT_EQUAL(1, a_set_count_fake.call_count);
    TEST_ASSERT_EQUAL(4, a_set_count_fake.arg1_val);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_b_increment_count);
    return UNITY_END();
}