#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "testCubies.h"
#include "../src/Cubie.h"
#include "../src/RubiksCube.h"
#include "../src/RubiksCubeInternal.h"

void CubiesSuitefunc(){
    CU_pSuite CubiesSuite = CU_add_suite("Cubies Suite", NULL, NULL);
    //test cubie moves
    CU_add_test(CubiesSuite, "test update single cubie u", test_updateSingleCubieU);
    CU_add_test(CubiesSuite, "test update single cubie d", test_updateSingleCubieD);
    CU_add_test(CubiesSuite, "test update single cubie d", test_updateSingleCubieF);
    CU_add_test(CubiesSuite, "test update single cubie d", test_updateSingleCubieB);
    CU_add_test(CubiesSuite, "test update single cubie d", test_updateSingleCubieL);
    CU_add_test(CubiesSuite, "test update single cubie d", test_updateSingleCubieR);
}

int main(){
    CU_initialize_registry();
    
    CubiesSuitefunc(); 
    
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    
    //get the number of tests failed and return that number, if its non-zero we dont build the main executable
    unsigned int failures = CU_get_number_of_tests_failed();
    CU_cleanup_registry();
    return (failures > 0) ? 1 : 0;
}