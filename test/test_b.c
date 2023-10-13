#include "fff.h"
#include "unity.h"
#include "a.h"  // You'll be faking these
#include "b.h"  // You're testing these

DEFINE_FFF_GLOBALS;

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

void test_b_init(void) {
    a_ctx_t a;
    b_init(&a);
    
    TEST_ASSERT_EQUAL(1, a_init_fake.call_count);
    TEST_ASSERT_EQUAL_PTR(&a, a_init_fake.arg0_val);
}

void test_b_increment_count(void) {
    a_ctx_t a;
    a_get_count_fake.return_val = 3;
    
    b_increment_count(&a);
    
    TEST_ASSERT_EQUAL(1, a_get_count_fake.call_count);
    TEST_ASSERT_EQUAL(1, a_set_count_fake.call_count);
    TEST_ASSERT_EQUAL(4, a_set_count_fake.arg1_val);
}

void test_b_get_count(void) {
    a_ctx_t a;
    a_get_count_fake.return_val = 5;
    
    int result = b_get_count(&a);
    
    TEST_ASSERT_EQUAL(5, result);
    TEST_ASSERT_EQUAL(1, a_get_count_fake.call_count);
    TEST_ASSERT_EQUAL_PTR(&a, a_get_count_fake.arg0_val);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_b_init);
    RUN_TEST(test_b_increment_count);
    RUN_TEST(test_b_get_count);
    return UNITY_END();
}
