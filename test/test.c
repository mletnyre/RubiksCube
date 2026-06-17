#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "../src/Cubie.h"
#include "../src/RubiksCube.h"

void test_addition(void){
    CU_ASSERT(2+2 == 4);
}

int main(){
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Suite_1", NULL, NULL);
    CU_add_test(suite, "test of addition", test_addition);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    
    //get the number of tests failed and return that number, if its non-zero we dont build the main executable
    unsigned int failures = CU_get_number_of_tests_failed();
    CU_cleanup_registry();
    return (failures > 0) ? 1 : 0;
}