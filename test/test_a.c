#include "unity.h"
#include "a.h"

/* Global context for 'a' module */
static a_ctx_t a;

void setUp(void) {
    /* This is run before EACH test */
    a_init(&a);
}

void tearDown(void) {
    /* This is run after EACH test */
    /* (Nothing to tear down in this case) */
}

void test_a_init_sets_count_to_zero(void) {
    /* Ensure that a_init sets count to 0 */
    TEST_ASSERT_EQUAL_INT(0, a_get_count(&a));
}

void test_a_set_count_sets_count_correctly(void) {
    /* Ensure that a_set_count sets count correctly */
    a_set_count(&a, 42);
    TEST_ASSERT_EQUAL_INT(42, a_get_count(&a));
}

void test_a_get_count_gets_count_correctly(void) {
    /* Ensure that a_get_count gets count correctly */
    a.count = 100;
    TEST_ASSERT_EQUAL_INT(100, a_get_count(&a));
}

int main(void) {
    UNITY_BEGIN();
    
    /* Run the tests */
    RUN_TEST(test_a_init_sets_count_to_zero);
    RUN_TEST(test_a_set_count_sets_count_correctly);
    RUN_TEST(test_a_get_count_gets_count_correctly);
    
    return UNITY_END();
}
