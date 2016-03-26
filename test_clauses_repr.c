
#include "unit_test.h"
#include "clauses_repr.h"

UT_TEST(ex1) {
    struct new_clauses_repr_from_file ret = new_clauses_repr_from_file("test/ex1.in");
    UT_ASSERT_TRUE(ret.success);
    struct clauses_repr *cr = ret.clauses_repr;
    UT_ASSERT_TRUE(clauses_repr_num_vars(cr) == 3);
    UT_ASSERT_TRUE(clauses_repr_num_clauses(cr) == 4);
   
    {
        struct clauses_repr_clause crc;
        crc = clauses_repr_clause(cr, 0);
        UT_ASSERT_TRUE(crc.len == 1);
        UT_ASSERT_TRUE(crc.first[0] == -1);

        crc = clauses_repr_clause(cr, 1);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == 2);

        crc = clauses_repr_clause(cr, 2);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == 3);

        crc = clauses_repr_clause(cr, 3);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == -3);

     }
    {
        struct  clauses_repr_clauses_of crco;
        crco = clauses_repr_clauses_of(cr, 0);
        UT_ASSERT_TRUE(crco.len == 0);

        crco = clauses_repr_clauses_of(cr, 1);
        UT_ASSERT_TRUE(crco.len == 3);
        UT_ASSERT_TRUE(crco.first[0] == 0);
        UT_ASSERT_TRUE(crco.first[1] == 1);
        UT_ASSERT_TRUE(crco.first[2] == 3);

        crco = clauses_repr_clauses_of(cr, 2);
        UT_ASSERT_TRUE(crco.len == 3);
        UT_ASSERT_TRUE(crco.first[0] == 1);
        UT_ASSERT_TRUE(crco.first[1] == 2);
        UT_ASSERT_TRUE(crco.first[2] == 3);

        crco = clauses_repr_clauses_of(cr, 3);
        UT_ASSERT_TRUE(crco.len == 2);
        UT_ASSERT_TRUE(crco.first[0] == 2);
        UT_ASSERT_TRUE(crco.first[1] == 3);

     }


    free_clauses_repr(cr);
    return 0;
}

UT_TEST(ex2) {
    struct new_clauses_repr_from_file ret = new_clauses_repr_from_file("test/ex2.in");
    UT_ASSERT_TRUE(ret.success);
    struct clauses_repr *cr = ret.clauses_repr;
    UT_ASSERT_TRUE(clauses_repr_num_vars(cr) == 10);
    UT_ASSERT_TRUE(clauses_repr_num_clauses(cr) == 70);

	{
        struct clauses_repr_clause crc;
        crc = clauses_repr_clause(cr, 0);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == 3);

        crc = clauses_repr_clause(cr, 1);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -3);

        crc = clauses_repr_clause(cr, 2);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == 5);

        crc = clauses_repr_clause(cr, 3);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -5);

        crc = clauses_repr_clause(cr, 4);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == 7);

        crc = clauses_repr_clause(cr, 5);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -7);

        crc = clauses_repr_clause(cr, 6);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == 8);

        crc = clauses_repr_clause(cr, 7);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -8);

        crc = clauses_repr_clause(cr, 8);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == 9);

        crc = clauses_repr_clause(cr, 9);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -9);

        crc = clauses_repr_clause(cr, 10);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 3);

        crc = clauses_repr_clause(cr, 11);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -3);

        crc = clauses_repr_clause(cr, 12);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 4);

        crc = clauses_repr_clause(cr, 13);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -4);

        crc = clauses_repr_clause(cr, 14);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 5);

        crc = clauses_repr_clause(cr, 15);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -5);

        crc = clauses_repr_clause(cr, 16);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 6);

        crc = clauses_repr_clause(cr, 17);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -6);

        crc = clauses_repr_clause(cr, 18);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 7);

        crc = clauses_repr_clause(cr, 19);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -7);

        crc = clauses_repr_clause(cr, 20);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 8);

        crc = clauses_repr_clause(cr, 21);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -8);

        crc = clauses_repr_clause(cr, 22);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 9);

        crc = clauses_repr_clause(cr, 23);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -9);

        crc = clauses_repr_clause(cr, 24);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 10);

        crc = clauses_repr_clause(cr, 25);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -10);

        crc = clauses_repr_clause(cr, 26);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 4);

        crc = clauses_repr_clause(cr, 27);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -4);

        crc = clauses_repr_clause(cr, 28);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 5);

        crc = clauses_repr_clause(cr, 29);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -5);

        crc = clauses_repr_clause(cr, 30);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 6);

        crc = clauses_repr_clause(cr, 31);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -6);

        crc = clauses_repr_clause(cr, 32);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 7);

        crc = clauses_repr_clause(cr, 33);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -7);

        crc = clauses_repr_clause(cr, 34);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 8);

        crc = clauses_repr_clause(cr, 35);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -8);

        crc = clauses_repr_clause(cr, 36);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 9);

        crc = clauses_repr_clause(cr, 37);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -9);

        crc = clauses_repr_clause(cr, 38);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 10);

        crc = clauses_repr_clause(cr, 39);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -10);

        crc = clauses_repr_clause(cr, 40);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == 5);

        crc = clauses_repr_clause(cr, 41);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == -5);

        crc = clauses_repr_clause(cr, 42);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == 8);

        crc = clauses_repr_clause(cr, 43);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == -8);

        crc = clauses_repr_clause(cr, 44);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == 9);

        crc = clauses_repr_clause(cr, 45);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == -9);

        crc = clauses_repr_clause(cr, 46);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 6);

        crc = clauses_repr_clause(cr, 47);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -6);

        crc = clauses_repr_clause(cr, 48);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 7);

        crc = clauses_repr_clause(cr, 49);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -7);

        crc = clauses_repr_clause(cr, 50);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 8);

        crc = clauses_repr_clause(cr, 51);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -8);

        crc = clauses_repr_clause(cr, 52);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 9);

        crc = clauses_repr_clause(cr, 53);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -9);

        crc = clauses_repr_clause(cr, 54);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 10);

        crc = clauses_repr_clause(cr, 55);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -10);

        crc = clauses_repr_clause(cr, 56);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 8);

        crc = clauses_repr_clause(cr, 57);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == -8);

        crc = clauses_repr_clause(cr, 58);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 9);

        crc = clauses_repr_clause(cr, 59);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == -9);

        crc = clauses_repr_clause(cr, 60);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 10);

        crc = clauses_repr_clause(cr, 61);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == -10);

        crc = clauses_repr_clause(cr, 62);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == 10);

        crc = clauses_repr_clause(cr, 63);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == -10);

        crc = clauses_repr_clause(cr, 64);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == 9);

        crc = clauses_repr_clause(cr, 65);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -9);

        crc = clauses_repr_clause(cr, 66);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == 10);

        crc = clauses_repr_clause(cr, 67);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -10);

        crc = clauses_repr_clause(cr, 68);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == 10);

        crc = clauses_repr_clause(cr, 69);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -10);

    }

    {
        struct  clauses_repr_clauses_of crco;
        crco = clauses_repr_clauses_of(cr, 0);
        UT_ASSERT_TRUE(crco.len == 0);

        crco = clauses_repr_clauses_of(cr, 1);
        UT_ASSERT_TRUE(crco.len == 10);
        UT_ASSERT_TRUE(crco.first[0] == 0);
        UT_ASSERT_TRUE(crco.first[1] == 1);
        UT_ASSERT_TRUE(crco.first[2] == 2);
        UT_ASSERT_TRUE(crco.first[3] == 3);
        UT_ASSERT_TRUE(crco.first[4] == 4);
        UT_ASSERT_TRUE(crco.first[5] == 5);
        UT_ASSERT_TRUE(crco.first[6] == 6);
        UT_ASSERT_TRUE(crco.first[7] == 7);
        UT_ASSERT_TRUE(crco.first[8] == 8);
        UT_ASSERT_TRUE(crco.first[9] == 9);

        crco = clauses_repr_clauses_of(cr, 2);
        UT_ASSERT_TRUE(crco.len == 16);
        UT_ASSERT_TRUE(crco.first[0] == 10);
        UT_ASSERT_TRUE(crco.first[1] == 11);
        UT_ASSERT_TRUE(crco.first[2] == 12);
        UT_ASSERT_TRUE(crco.first[3] == 13);
        UT_ASSERT_TRUE(crco.first[4] == 14);
        UT_ASSERT_TRUE(crco.first[5] == 15);
        UT_ASSERT_TRUE(crco.first[6] == 16);
        UT_ASSERT_TRUE(crco.first[7] == 17);
        UT_ASSERT_TRUE(crco.first[8] == 18);
        UT_ASSERT_TRUE(crco.first[9] == 19);
        UT_ASSERT_TRUE(crco.first[10] == 20);
        UT_ASSERT_TRUE(crco.first[11] == 21);
        UT_ASSERT_TRUE(crco.first[12] == 22);
        UT_ASSERT_TRUE(crco.first[13] == 23);
        UT_ASSERT_TRUE(crco.first[14] == 24);
        UT_ASSERT_TRUE(crco.first[15] == 25);

        crco = clauses_repr_clauses_of(cr, 3);
        UT_ASSERT_TRUE(crco.len == 18);
        UT_ASSERT_TRUE(crco.first[0] == 0);
        UT_ASSERT_TRUE(crco.first[1] == 1);
        UT_ASSERT_TRUE(crco.first[2] == 10);
        UT_ASSERT_TRUE(crco.first[3] == 11);
        UT_ASSERT_TRUE(crco.first[4] == 26);
        UT_ASSERT_TRUE(crco.first[5] == 27);
        UT_ASSERT_TRUE(crco.first[6] == 28);
        UT_ASSERT_TRUE(crco.first[7] == 29);
        UT_ASSERT_TRUE(crco.first[8] == 30);
        UT_ASSERT_TRUE(crco.first[9] == 31);
        UT_ASSERT_TRUE(crco.first[10] == 32);
        UT_ASSERT_TRUE(crco.first[11] == 33);
        UT_ASSERT_TRUE(crco.first[12] == 34);
        UT_ASSERT_TRUE(crco.first[13] == 35);
        UT_ASSERT_TRUE(crco.first[14] == 36);
        UT_ASSERT_TRUE(crco.first[15] == 37);
        UT_ASSERT_TRUE(crco.first[16] == 38);
        UT_ASSERT_TRUE(crco.first[17] == 39);

        crco = clauses_repr_clauses_of(cr, 4);
        UT_ASSERT_TRUE(crco.len == 10);
        UT_ASSERT_TRUE(crco.first[0] == 12);
        UT_ASSERT_TRUE(crco.first[1] == 13);
        UT_ASSERT_TRUE(crco.first[2] == 26);
        UT_ASSERT_TRUE(crco.first[3] == 27);
        UT_ASSERT_TRUE(crco.first[4] == 40);
        UT_ASSERT_TRUE(crco.first[5] == 41);
        UT_ASSERT_TRUE(crco.first[6] == 42);
        UT_ASSERT_TRUE(crco.first[7] == 43);
        UT_ASSERT_TRUE(crco.first[8] == 44);
        UT_ASSERT_TRUE(crco.first[9] == 45);

        crco = clauses_repr_clauses_of(cr, 5);
        UT_ASSERT_TRUE(crco.len == 18);
        UT_ASSERT_TRUE(crco.first[0] == 2);
        UT_ASSERT_TRUE(crco.first[1] == 3);
        UT_ASSERT_TRUE(crco.first[2] == 14);
        UT_ASSERT_TRUE(crco.first[3] == 15);
        UT_ASSERT_TRUE(crco.first[4] == 28);
        UT_ASSERT_TRUE(crco.first[5] == 29);
        UT_ASSERT_TRUE(crco.first[6] == 40);
        UT_ASSERT_TRUE(crco.first[7] == 41);
        UT_ASSERT_TRUE(crco.first[8] == 46);
        UT_ASSERT_TRUE(crco.first[9] == 47);
        UT_ASSERT_TRUE(crco.first[10] == 48);
        UT_ASSERT_TRUE(crco.first[11] == 49);
        UT_ASSERT_TRUE(crco.first[12] == 50);
        UT_ASSERT_TRUE(crco.first[13] == 51);
        UT_ASSERT_TRUE(crco.first[14] == 52);
        UT_ASSERT_TRUE(crco.first[15] == 53);
        UT_ASSERT_TRUE(crco.first[16] == 54);
        UT_ASSERT_TRUE(crco.first[17] == 55);

        crco = clauses_repr_clauses_of(cr, 6);
        UT_ASSERT_TRUE(crco.len == 12);
        UT_ASSERT_TRUE(crco.first[0] == 16);
        UT_ASSERT_TRUE(crco.first[1] == 17);
        UT_ASSERT_TRUE(crco.first[2] == 30);
        UT_ASSERT_TRUE(crco.first[3] == 31);
        UT_ASSERT_TRUE(crco.first[4] == 46);
        UT_ASSERT_TRUE(crco.first[5] == 47);
        UT_ASSERT_TRUE(crco.first[6] == 56);
        UT_ASSERT_TRUE(crco.first[7] == 57);
        UT_ASSERT_TRUE(crco.first[8] == 58);
        UT_ASSERT_TRUE(crco.first[9] == 59);
        UT_ASSERT_TRUE(crco.first[10] == 60);
        UT_ASSERT_TRUE(crco.first[11] == 61);

        crco = clauses_repr_clauses_of(cr, 7);
        UT_ASSERT_TRUE(crco.len == 10);
        UT_ASSERT_TRUE(crco.first[0] == 4);
        UT_ASSERT_TRUE(crco.first[1] == 5);
        UT_ASSERT_TRUE(crco.first[2] == 18);
        UT_ASSERT_TRUE(crco.first[3] == 19);
        UT_ASSERT_TRUE(crco.first[4] == 32);
        UT_ASSERT_TRUE(crco.first[5] == 33);
        UT_ASSERT_TRUE(crco.first[6] == 48);
        UT_ASSERT_TRUE(crco.first[7] == 49);
        UT_ASSERT_TRUE(crco.first[8] == 62);
        UT_ASSERT_TRUE(crco.first[9] == 63);

        crco = clauses_repr_clauses_of(cr, 8);
        UT_ASSERT_TRUE(crco.len == 16);
        UT_ASSERT_TRUE(crco.first[0] == 6);
        UT_ASSERT_TRUE(crco.first[1] == 7);
        UT_ASSERT_TRUE(crco.first[2] == 20);
        UT_ASSERT_TRUE(crco.first[3] == 21);
        UT_ASSERT_TRUE(crco.first[4] == 34);
        UT_ASSERT_TRUE(crco.first[5] == 35);
        UT_ASSERT_TRUE(crco.first[6] == 42);
        UT_ASSERT_TRUE(crco.first[7] == 43);
        UT_ASSERT_TRUE(crco.first[8] == 50);
        UT_ASSERT_TRUE(crco.first[9] == 51);
        UT_ASSERT_TRUE(crco.first[10] == 56);
        UT_ASSERT_TRUE(crco.first[11] == 57);
        UT_ASSERT_TRUE(crco.first[12] == 64);
        UT_ASSERT_TRUE(crco.first[13] == 65);
        UT_ASSERT_TRUE(crco.first[14] == 66);
        UT_ASSERT_TRUE(crco.first[15] == 67);

        crco = clauses_repr_clauses_of(cr, 9);
        UT_ASSERT_TRUE(crco.len == 16);
        UT_ASSERT_TRUE(crco.first[0] == 8);
        UT_ASSERT_TRUE(crco.first[1] == 9);
        UT_ASSERT_TRUE(crco.first[2] == 22);
        UT_ASSERT_TRUE(crco.first[3] == 23);
        UT_ASSERT_TRUE(crco.first[4] == 36);
        UT_ASSERT_TRUE(crco.first[5] == 37);
        UT_ASSERT_TRUE(crco.first[6] == 44);
        UT_ASSERT_TRUE(crco.first[7] == 45);
        UT_ASSERT_TRUE(crco.first[8] == 52);
        UT_ASSERT_TRUE(crco.first[9] == 53);
        UT_ASSERT_TRUE(crco.first[10] == 58);
        UT_ASSERT_TRUE(crco.first[11] == 59);
        UT_ASSERT_TRUE(crco.first[12] == 64);
        UT_ASSERT_TRUE(crco.first[13] == 65);
        UT_ASSERT_TRUE(crco.first[14] == 68);
        UT_ASSERT_TRUE(crco.first[15] == 69);

        crco = clauses_repr_clauses_of(cr, 10);
        UT_ASSERT_TRUE(crco.len == 14);
        UT_ASSERT_TRUE(crco.first[0] == 24);
        UT_ASSERT_TRUE(crco.first[1] == 25);
        UT_ASSERT_TRUE(crco.first[2] == 38);
        UT_ASSERT_TRUE(crco.first[3] == 39);
        UT_ASSERT_TRUE(crco.first[4] == 54);
        UT_ASSERT_TRUE(crco.first[5] == 55);
        UT_ASSERT_TRUE(crco.first[6] == 60);
        UT_ASSERT_TRUE(crco.first[7] == 61);
        UT_ASSERT_TRUE(crco.first[8] == 62);
        UT_ASSERT_TRUE(crco.first[9] == 63);
        UT_ASSERT_TRUE(crco.first[10] == 66);
        UT_ASSERT_TRUE(crco.first[11] == 67);
        UT_ASSERT_TRUE(crco.first[12] == 68);
        UT_ASSERT_TRUE(crco.first[13] == 69);
    }

    free_clauses_repr(cr);
    return 0;
}

UT_TEST(ex3) {
    struct new_clauses_repr_from_file ret = new_clauses_repr_from_file("test/ex3.in");
    UT_ASSERT_TRUE(ret.success);
    struct clauses_repr *cr = ret.clauses_repr;
    UT_ASSERT_TRUE(clauses_repr_num_vars(cr) == 25);
    UT_ASSERT_TRUE(clauses_repr_num_clauses(cr) == 500);


    {
        struct clauses_repr_clause crc;
        crc = clauses_repr_clause(cr, 0);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 1);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 2);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 3);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 4);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -19);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 5);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 6);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 7);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 8);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 9);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 10);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 11);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 12);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 13);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 14);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 15);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == -19);

        crc = clauses_repr_clause(cr, 16);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 17);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 18);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 19);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 20);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 21);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 22);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 23);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 24);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 25);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 26);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 17);

        crc = clauses_repr_clause(cr, 27);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 28);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 29);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 30);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 31);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 32);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 33);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 34);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 35);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 36);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 37);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 38);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 39);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 40);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 41);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 42);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 43);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 44);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 45);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 46);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 47);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 48);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 49);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 50);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 51);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 52);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 53);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 54);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 55);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 56);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 57);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 58);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 59);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 60);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 61);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 62);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 63);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 64);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 65);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 66);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 67);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 68);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 69);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 70);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == -8);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 71);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == 10);

        crc = clauses_repr_clause(cr, 72);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 73);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 74);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 75);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 76);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 77);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 78);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 79);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == -19);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 80);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 81);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 82);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 83);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 84);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 85);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 86);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 87);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 88);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 89);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 90);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 91);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 92);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 93);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 94);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == 8);

        crc = clauses_repr_clause(cr, 95);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 96);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 97);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 25);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 98);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 99);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == -22);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 100);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 101);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 102);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == 14);

        crc = clauses_repr_clause(cr, 103);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 104);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 105);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 106);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 107);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 108);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 109);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 110);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 111);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 112);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 113);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 114);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 115);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 116);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 117);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 118);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 119);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 120);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == 8);

        crc = clauses_repr_clause(cr, 121);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 122);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 123);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 124);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 125);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 126);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 127);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 128);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 129);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 130);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 131);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -22);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 132);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 133);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 134);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 135);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 136);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 137);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -19);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 138);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 139);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == 8);

        crc = clauses_repr_clause(cr, 140);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 141);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == -1);

        crc = clauses_repr_clause(cr, 142);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 143);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 144);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == -22);
        UT_ASSERT_TRUE(crc.first[2] == 17);

        crc = clauses_repr_clause(cr, 145);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 146);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 14);

        crc = clauses_repr_clause(cr, 147);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 148);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 149);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 150);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 151);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == 10);

        crc = clauses_repr_clause(cr, 152);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 153);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 154);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 155);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 156);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 157);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 158);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 159);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 160);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 161);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 162);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 163);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 164);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 165);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 166);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 167);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 168);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 169);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 170);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 171);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 172);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 173);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 174);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 175);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 176);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 177);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 178);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 179);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 180);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 181);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 182);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 183);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 184);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 185);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 186);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 187);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 188);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 189);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 190);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == -1);

        crc = clauses_repr_clause(cr, 191);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 192);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 193);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 194);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 195);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 196);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 197);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == -22);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 198);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 199);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 200);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 201);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 202);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 203);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 204);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 205);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 206);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 207);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 208);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 209);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 210);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 211);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 212);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 213);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 214);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 215);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == -19);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 216);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 217);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 218);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 219);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 220);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 221);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 222);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == 10);

        crc = clauses_repr_clause(cr, 223);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 224);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 225);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 226);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 227);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 228);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 229);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 230);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 231);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 232);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 233);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 234);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 235);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 236);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 237);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 238);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 239);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 240);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 241);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 242);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 243);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 244);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 245);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 246);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 247);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 248);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -8);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 249);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 250);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 251);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 252);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 8);

        crc = clauses_repr_clause(cr, 253);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == -1);

        crc = clauses_repr_clause(cr, 254);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 255);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 256);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 257);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 258);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 259);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 260);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 261);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 262);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 263);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 264);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 25);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 265);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 266);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 267);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 268);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 269);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 270);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 271);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 272);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 273);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 274);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -22);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 275);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 276);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 277);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 278);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 279);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 280);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 281);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 282);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 283);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 284);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 285);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 286);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 287);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 288);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 289);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 290);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 291);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == -19);

        crc = clauses_repr_clause(cr, 292);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 293);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 294);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 295);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 296);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 297);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 298);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 299);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 300);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 301);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 302);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 303);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 304);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 305);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 306);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 307);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 308);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 309);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 310);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 311);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 312);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 313);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 314);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 315);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 316);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == -19);

        crc = clauses_repr_clause(cr, 317);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 318);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 319);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 320);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 321);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 322);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == 10);

        crc = clauses_repr_clause(cr, 323);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 324);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 325);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 326);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 327);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 328);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == -19);

        crc = clauses_repr_clause(cr, 329);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 330);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 331);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 332);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == 14);

        crc = clauses_repr_clause(cr, 333);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 334);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 335);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 336);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 337);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 17);

        crc = clauses_repr_clause(cr, 338);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 339);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 340);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 341);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 342);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 343);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 344);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == -22);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 345);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 346);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 347);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 348);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 349);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 350);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 351);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 352);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 353);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 354);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 355);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 356);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 357);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == -22);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 358);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 359);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 360);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 361);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == 8);

        crc = clauses_repr_clause(cr, 362);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 363);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 364);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 365);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == -19);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 366);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 367);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 368);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -22);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 369);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 370);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 371);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 372);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 373);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 374);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 375);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 376);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 377);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 378);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 379);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 380);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 381);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 382);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 383);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 384);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 385);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 386);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 387);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 388);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 389);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 390);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 391);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 392);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == 8);

        crc = clauses_repr_clause(cr, 393);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 394);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 395);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == 8);

        crc = clauses_repr_clause(cr, 396);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -22);
        UT_ASSERT_TRUE(crc.first[2] == 14);

        crc = clauses_repr_clause(cr, 397);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == -8);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 398);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 399);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 400);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 401);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 402);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 403);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 404);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 405);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 406);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 407);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 408);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 409);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 410);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 411);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 412);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 413);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 414);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 415);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 416);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 417);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 418);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 419);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 420);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 421);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 422);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 423);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == 17);

        crc = clauses_repr_clause(cr, 424);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 425);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 426);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 427);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == 10);

        crc = clauses_repr_clause(cr, 428);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 429);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 430);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 431);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 432);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 433);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 434);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 435);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == -1);

        crc = clauses_repr_clause(cr, 436);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 437);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 438);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 439);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 440);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == 17);

        crc = clauses_repr_clause(cr, 441);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 442);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == -19);

        crc = clauses_repr_clause(cr, 443);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 444);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 445);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 446);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 447);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 448);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 449);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 450);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 451);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 452);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 453);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 454);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 455);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 456);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 457);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 458);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 459);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 460);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 461);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 462);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 463);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 464);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 465);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 466);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 467);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 25);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 468);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 469);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 470);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 471);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 472);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 473);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 474);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 475);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 476);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 477);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 478);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 14);

        crc = clauses_repr_clause(cr, 479);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 480);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == 10);

        crc = clauses_repr_clause(cr, 481);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 482);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 483);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 484);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == -1);

        crc = clauses_repr_clause(cr, 485);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 486);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 487);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 488);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 489);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 490);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 491);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 492);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 493);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 494);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == -22);
        UT_ASSERT_TRUE(crc.first[2] == 8);

        crc = clauses_repr_clause(cr, 495);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 496);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 497);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 498);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 499);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == -17);

    }
    {
        struct  clauses_repr_clauses_of crco;
        crco = clauses_repr_clauses_of(cr, 0);
        UT_ASSERT_TRUE(crco.len == 0);

        crco = clauses_repr_clauses_of(cr, 1);
        UT_ASSERT_TRUE(crco.len == 52);
        UT_ASSERT_TRUE(crco.first[0] == 2);
        UT_ASSERT_TRUE(crco.first[1] == 27);
        UT_ASSERT_TRUE(crco.first[2] == 40);
        UT_ASSERT_TRUE(crco.first[3] == 47);
        UT_ASSERT_TRUE(crco.first[4] == 65);
        UT_ASSERT_TRUE(crco.first[5] == 72);
        UT_ASSERT_TRUE(crco.first[6] == 82);
        UT_ASSERT_TRUE(crco.first[7] == 99);
        UT_ASSERT_TRUE(crco.first[8] == 117);
        UT_ASSERT_TRUE(crco.first[9] == 119);
        UT_ASSERT_TRUE(crco.first[10] == 122);
        UT_ASSERT_TRUE(crco.first[11] == 141);
        UT_ASSERT_TRUE(crco.first[12] == 168);
        UT_ASSERT_TRUE(crco.first[13] == 178);
        UT_ASSERT_TRUE(crco.first[14] == 184);
        UT_ASSERT_TRUE(crco.first[15] == 190);
        UT_ASSERT_TRUE(crco.first[16] == 191);
        UT_ASSERT_TRUE(crco.first[17] == 208);
        UT_ASSERT_TRUE(crco.first[18] == 212);
        UT_ASSERT_TRUE(crco.first[19] == 220);
        UT_ASSERT_TRUE(crco.first[20] == 229);
        UT_ASSERT_TRUE(crco.first[21] == 231);
        UT_ASSERT_TRUE(crco.first[22] == 244);
        UT_ASSERT_TRUE(crco.first[23] == 245);
        UT_ASSERT_TRUE(crco.first[24] == 248);
        UT_ASSERT_TRUE(crco.first[25] == 249);
        UT_ASSERT_TRUE(crco.first[26] == 251);
        UT_ASSERT_TRUE(crco.first[27] == 253);
        UT_ASSERT_TRUE(crco.first[28] == 271);
        UT_ASSERT_TRUE(crco.first[29] == 286);
        UT_ASSERT_TRUE(crco.first[30] == 293);
        UT_ASSERT_TRUE(crco.first[31] == 309);
        UT_ASSERT_TRUE(crco.first[32] == 310);
        UT_ASSERT_TRUE(crco.first[33] == 311);
        UT_ASSERT_TRUE(crco.first[34] == 326);
        UT_ASSERT_TRUE(crco.first[35] == 332);
        UT_ASSERT_TRUE(crco.first[36] == 336);
        UT_ASSERT_TRUE(crco.first[37] == 359);
        UT_ASSERT_TRUE(crco.first[38] == 364);
        UT_ASSERT_TRUE(crco.first[39] == 374);
        UT_ASSERT_TRUE(crco.first[40] == 386);
        UT_ASSERT_TRUE(crco.first[41] == 401);
        UT_ASSERT_TRUE(crco.first[42] == 404);
        UT_ASSERT_TRUE(crco.first[43] == 410);
        UT_ASSERT_TRUE(crco.first[44] == 428);
        UT_ASSERT_TRUE(crco.first[45] == 435);
        UT_ASSERT_TRUE(crco.first[46] == 440);
        UT_ASSERT_TRUE(crco.first[47] == 443);
        UT_ASSERT_TRUE(crco.first[48] == 449);
        UT_ASSERT_TRUE(crco.first[49] == 464);
        UT_ASSERT_TRUE(crco.first[50] == 470);
        UT_ASSERT_TRUE(crco.first[51] == 484);

        crco = clauses_repr_clauses_of(cr, 2);
        UT_ASSERT_TRUE(crco.len == 59);
        UT_ASSERT_TRUE(crco.first[0] == 10);
        UT_ASSERT_TRUE(crco.first[1] == 22);
        UT_ASSERT_TRUE(crco.first[2] == 24);
        UT_ASSERT_TRUE(crco.first[3] == 27);
        UT_ASSERT_TRUE(crco.first[4] == 31);
        UT_ASSERT_TRUE(crco.first[5] == 36);
        UT_ASSERT_TRUE(crco.first[6] == 54);
        UT_ASSERT_TRUE(crco.first[7] == 67);
        UT_ASSERT_TRUE(crco.first[8] == 69);
        UT_ASSERT_TRUE(crco.first[9] == 77);
        UT_ASSERT_TRUE(crco.first[10] == 81);
        UT_ASSERT_TRUE(crco.first[11] == 84);
        UT_ASSERT_TRUE(crco.first[12] == 90);
        UT_ASSERT_TRUE(crco.first[13] == 114);
        UT_ASSERT_TRUE(crco.first[14] == 119);
        UT_ASSERT_TRUE(crco.first[15] == 121);
        UT_ASSERT_TRUE(crco.first[16] == 123);
        UT_ASSERT_TRUE(crco.first[17] == 135);
        UT_ASSERT_TRUE(crco.first[18] == 143);
        UT_ASSERT_TRUE(crco.first[19] == 164);
        UT_ASSERT_TRUE(crco.first[20] == 167);
        UT_ASSERT_TRUE(crco.first[21] == 191);
        UT_ASSERT_TRUE(crco.first[22] == 216);
        UT_ASSERT_TRUE(crco.first[23] == 231);
        UT_ASSERT_TRUE(crco.first[24] == 232);
        UT_ASSERT_TRUE(crco.first[25] == 235);
        UT_ASSERT_TRUE(crco.first[26] == 239);
        UT_ASSERT_TRUE(crco.first[27] == 240);
        UT_ASSERT_TRUE(crco.first[28] == 251);
        UT_ASSERT_TRUE(crco.first[29] == 263);
        UT_ASSERT_TRUE(crco.first[30] == 264);
        UT_ASSERT_TRUE(crco.first[31] == 277);
        UT_ASSERT_TRUE(crco.first[32] == 286);
        UT_ASSERT_TRUE(crco.first[33] == 295);
        UT_ASSERT_TRUE(crco.first[34] == 296);
        UT_ASSERT_TRUE(crco.first[35] == 308);
        UT_ASSERT_TRUE(crco.first[36] == 310);
        UT_ASSERT_TRUE(crco.first[37] == 311);
        UT_ASSERT_TRUE(crco.first[38] == 330);
        UT_ASSERT_TRUE(crco.first[39] == 346);
        UT_ASSERT_TRUE(crco.first[40] == 365);
        UT_ASSERT_TRUE(crco.first[41] == 367);
        UT_ASSERT_TRUE(crco.first[42] == 374);
        UT_ASSERT_TRUE(crco.first[43] == 376);
        UT_ASSERT_TRUE(crco.first[44] == 380);
        UT_ASSERT_TRUE(crco.first[45] == 394);
        UT_ASSERT_TRUE(crco.first[46] == 405);
        UT_ASSERT_TRUE(crco.first[47] == 415);
        UT_ASSERT_TRUE(crco.first[48] == 419);
        UT_ASSERT_TRUE(crco.first[49] == 425);
        UT_ASSERT_TRUE(crco.first[50] == 433);
        UT_ASSERT_TRUE(crco.first[51] == 440);
        UT_ASSERT_TRUE(crco.first[52] == 446);
        UT_ASSERT_TRUE(crco.first[53] == 454);
        UT_ASSERT_TRUE(crco.first[54] == 459);
        UT_ASSERT_TRUE(crco.first[55] == 468);
        UT_ASSERT_TRUE(crco.first[56] == 472);
        UT_ASSERT_TRUE(crco.first[57] == 488);
        UT_ASSERT_TRUE(crco.first[58] == 490);

        crco = clauses_repr_clauses_of(cr, 3);
        UT_ASSERT_TRUE(crco.len == 61);
        UT_ASSERT_TRUE(crco.first[0] == 8);
        UT_ASSERT_TRUE(crco.first[1] == 19);
        UT_ASSERT_TRUE(crco.first[2] == 21);
        UT_ASSERT_TRUE(crco.first[3] == 24);
        UT_ASSERT_TRUE(crco.first[4] == 28);
        UT_ASSERT_TRUE(crco.first[5] == 29);
        UT_ASSERT_TRUE(crco.first[6] == 38);
        UT_ASSERT_TRUE(crco.first[7] == 46);
        UT_ASSERT_TRUE(crco.first[8] == 59);
        UT_ASSERT_TRUE(crco.first[9] == 62);
        UT_ASSERT_TRUE(crco.first[10] == 63);
        UT_ASSERT_TRUE(crco.first[11] == 68);
        UT_ASSERT_TRUE(crco.first[12] == 72);
        UT_ASSERT_TRUE(crco.first[13] == 73);
        UT_ASSERT_TRUE(crco.first[14] == 88);
        UT_ASSERT_TRUE(crco.first[15] == 89);
        UT_ASSERT_TRUE(crco.first[16] == 92);
        UT_ASSERT_TRUE(crco.first[17] == 98);
        UT_ASSERT_TRUE(crco.first[18] == 106);
        UT_ASSERT_TRUE(crco.first[19] == 133);
        UT_ASSERT_TRUE(crco.first[20] == 139);
        UT_ASSERT_TRUE(crco.first[21] == 163);
        UT_ASSERT_TRUE(crco.first[22] == 165);
        UT_ASSERT_TRUE(crco.first[23] == 187);
        UT_ASSERT_TRUE(crco.first[24] == 196);
        UT_ASSERT_TRUE(crco.first[25] == 199);
        UT_ASSERT_TRUE(crco.first[26] == 206);
        UT_ASSERT_TRUE(crco.first[27] == 216);
        UT_ASSERT_TRUE(crco.first[28] == 217);
        UT_ASSERT_TRUE(crco.first[29] == 219);
        UT_ASSERT_TRUE(crco.first[30] == 220);
        UT_ASSERT_TRUE(crco.first[31] == 223);
        UT_ASSERT_TRUE(crco.first[32] == 261);
        UT_ASSERT_TRUE(crco.first[33] == 262);
        UT_ASSERT_TRUE(crco.first[34] == 266);
        UT_ASSERT_TRUE(crco.first[35] == 282);
        UT_ASSERT_TRUE(crco.first[36] == 317);
        UT_ASSERT_TRUE(crco.first[37] == 324);
        UT_ASSERT_TRUE(crco.first[38] == 329);
        UT_ASSERT_TRUE(crco.first[39] == 334);
        UT_ASSERT_TRUE(crco.first[40] == 343);
        UT_ASSERT_TRUE(crco.first[41] == 345);
        UT_ASSERT_TRUE(crco.first[42] == 350);
        UT_ASSERT_TRUE(crco.first[43] == 364);
        UT_ASSERT_TRUE(crco.first[44] == 369);
        UT_ASSERT_TRUE(crco.first[45] == 384);
        UT_ASSERT_TRUE(crco.first[46] == 385);
        UT_ASSERT_TRUE(crco.first[47] == 400);
        UT_ASSERT_TRUE(crco.first[48] == 416);
        UT_ASSERT_TRUE(crco.first[49] == 417);
        UT_ASSERT_TRUE(crco.first[50] == 423);
        UT_ASSERT_TRUE(crco.first[51] == 431);
        UT_ASSERT_TRUE(crco.first[52] == 462);
        UT_ASSERT_TRUE(crco.first[53] == 465);
        UT_ASSERT_TRUE(crco.first[54] == 474);
        UT_ASSERT_TRUE(crco.first[55] == 475);
        UT_ASSERT_TRUE(crco.first[56] == 478);
        UT_ASSERT_TRUE(crco.first[57] == 483);
        UT_ASSERT_TRUE(crco.first[58] == 485);
        UT_ASSERT_TRUE(crco.first[59] == 489);
        UT_ASSERT_TRUE(crco.first[60] == 499);

        crco = clauses_repr_clauses_of(cr, 4);
        UT_ASSERT_TRUE(crco.len == 55);
        UT_ASSERT_TRUE(crco.first[0] == 11);
        UT_ASSERT_TRUE(crco.first[1] == 19);
        UT_ASSERT_TRUE(crco.first[2] == 25);
        UT_ASSERT_TRUE(crco.first[3] == 30);
        UT_ASSERT_TRUE(crco.first[4] == 39);
        UT_ASSERT_TRUE(crco.first[5] == 55);
        UT_ASSERT_TRUE(crco.first[6] == 69);
        UT_ASSERT_TRUE(crco.first[7] == 86);
        UT_ASSERT_TRUE(crco.first[8] == 93);
        UT_ASSERT_TRUE(crco.first[9] == 103);
        UT_ASSERT_TRUE(crco.first[10] == 111);
        UT_ASSERT_TRUE(crco.first[11] == 115);
        UT_ASSERT_TRUE(crco.first[12] == 128);
        UT_ASSERT_TRUE(crco.first[13] == 132);
        UT_ASSERT_TRUE(crco.first[14] == 143);
        UT_ASSERT_TRUE(crco.first[15] == 148);
        UT_ASSERT_TRUE(crco.first[16] == 150);
        UT_ASSERT_TRUE(crco.first[17] == 156);
        UT_ASSERT_TRUE(crco.first[18] == 162);
        UT_ASSERT_TRUE(crco.first[19] == 193);
        UT_ASSERT_TRUE(crco.first[20] == 201);
        UT_ASSERT_TRUE(crco.first[21] == 211);
        UT_ASSERT_TRUE(crco.first[22] == 214);
        UT_ASSERT_TRUE(crco.first[23] == 232);
        UT_ASSERT_TRUE(crco.first[24] == 244);
        UT_ASSERT_TRUE(crco.first[25] == 253);
        UT_ASSERT_TRUE(crco.first[26] == 265);
        UT_ASSERT_TRUE(crco.first[27] == 266);
        UT_ASSERT_TRUE(crco.first[28] == 272);
        UT_ASSERT_TRUE(crco.first[29] == 299);
        UT_ASSERT_TRUE(crco.first[30] == 315);
        UT_ASSERT_TRUE(crco.first[31] == 335);
        UT_ASSERT_TRUE(crco.first[32] == 341);
        UT_ASSERT_TRUE(crco.first[33] == 342);
        UT_ASSERT_TRUE(crco.first[34] == 350);
        UT_ASSERT_TRUE(crco.first[35] == 356);
        UT_ASSERT_TRUE(crco.first[36] == 359);
        UT_ASSERT_TRUE(crco.first[37] == 362);
        UT_ASSERT_TRUE(crco.first[38] == 373);
        UT_ASSERT_TRUE(crco.first[39] == 374);
        UT_ASSERT_TRUE(crco.first[40] == 387);
        UT_ASSERT_TRUE(crco.first[41] == 394);
        UT_ASSERT_TRUE(crco.first[42] == 398);
        UT_ASSERT_TRUE(crco.first[43] == 409);
        UT_ASSERT_TRUE(crco.first[44] == 417);
        UT_ASSERT_TRUE(crco.first[45] == 422);
        UT_ASSERT_TRUE(crco.first[46] == 424);
        UT_ASSERT_TRUE(crco.first[47] == 434);
        UT_ASSERT_TRUE(crco.first[48] == 436);
        UT_ASSERT_TRUE(crco.first[49] == 439);
        UT_ASSERT_TRUE(crco.first[50] == 447);
        UT_ASSERT_TRUE(crco.first[51] == 451);
        UT_ASSERT_TRUE(crco.first[52] == 459);
        UT_ASSERT_TRUE(crco.first[53] == 466);
        UT_ASSERT_TRUE(crco.first[54] == 498);

        crco = clauses_repr_clauses_of(cr, 5);
        UT_ASSERT_TRUE(crco.len == 58);
        UT_ASSERT_TRUE(crco.first[0] == 20);
        UT_ASSERT_TRUE(crco.first[1] == 35);
        UT_ASSERT_TRUE(crco.first[2] == 36);
        UT_ASSERT_TRUE(crco.first[3] == 66);
        UT_ASSERT_TRUE(crco.first[4] == 73);
        UT_ASSERT_TRUE(crco.first[5] == 79);
        UT_ASSERT_TRUE(crco.first[6] == 97);
        UT_ASSERT_TRUE(crco.first[7] == 110);
        UT_ASSERT_TRUE(crco.first[8] == 122);
        UT_ASSERT_TRUE(crco.first[9] == 131);
        UT_ASSERT_TRUE(crco.first[10] == 174);
        UT_ASSERT_TRUE(crco.first[11] == 175);
        UT_ASSERT_TRUE(crco.first[12] == 179);
        UT_ASSERT_TRUE(crco.first[13] == 180);
        UT_ASSERT_TRUE(crco.first[14] == 181);
        UT_ASSERT_TRUE(crco.first[15] == 182);
        UT_ASSERT_TRUE(crco.first[16] == 185);
        UT_ASSERT_TRUE(crco.first[17] == 219);
        UT_ASSERT_TRUE(crco.first[18] == 228);
        UT_ASSERT_TRUE(crco.first[19] == 238);
        UT_ASSERT_TRUE(crco.first[20] == 241);
        UT_ASSERT_TRUE(crco.first[21] == 242);
        UT_ASSERT_TRUE(crco.first[22] == 245);
        UT_ASSERT_TRUE(crco.first[23] == 256);
        UT_ASSERT_TRUE(crco.first[24] == 265);
        UT_ASSERT_TRUE(crco.first[25] == 266);
        UT_ASSERT_TRUE(crco.first[26] == 268);
        UT_ASSERT_TRUE(crco.first[27] == 272);
        UT_ASSERT_TRUE(crco.first[28] == 277);
        UT_ASSERT_TRUE(crco.first[29] == 278);
        UT_ASSERT_TRUE(crco.first[30] == 287);
        UT_ASSERT_TRUE(crco.first[31] == 290);
        UT_ASSERT_TRUE(crco.first[32] == 301);
        UT_ASSERT_TRUE(crco.first[33] == 302);
        UT_ASSERT_TRUE(crco.first[34] == 312);
        UT_ASSERT_TRUE(crco.first[35] == 316);
        UT_ASSERT_TRUE(crco.first[36] == 319);
        UT_ASSERT_TRUE(crco.first[37] == 334);
        UT_ASSERT_TRUE(crco.first[38] == 340);
        UT_ASSERT_TRUE(crco.first[39] == 358);
        UT_ASSERT_TRUE(crco.first[40] == 363);
        UT_ASSERT_TRUE(crco.first[41] == 371);
        UT_ASSERT_TRUE(crco.first[42] == 382);
        UT_ASSERT_TRUE(crco.first[43] == 390);
        UT_ASSERT_TRUE(crco.first[44] == 394);
        UT_ASSERT_TRUE(crco.first[45] == 399);
        UT_ASSERT_TRUE(crco.first[46] == 402);
        UT_ASSERT_TRUE(crco.first[47] == 404);
        UT_ASSERT_TRUE(crco.first[48] == 410);
        UT_ASSERT_TRUE(crco.first[49] == 411);
        UT_ASSERT_TRUE(crco.first[50] == 412);
        UT_ASSERT_TRUE(crco.first[51] == 413);
        UT_ASSERT_TRUE(crco.first[52] == 427);
        UT_ASSERT_TRUE(crco.first[53] == 451);
        UT_ASSERT_TRUE(crco.first[54] == 460);
        UT_ASSERT_TRUE(crco.first[55] == 470);
        UT_ASSERT_TRUE(crco.first[56] == 476);
        UT_ASSERT_TRUE(crco.first[57] == 490);

        crco = clauses_repr_clauses_of(cr, 6);
        UT_ASSERT_TRUE(crco.len == 55);
        UT_ASSERT_TRUE(crco.first[0] == 6);
        UT_ASSERT_TRUE(crco.first[1] == 10);
        UT_ASSERT_TRUE(crco.first[2] == 18);
        UT_ASSERT_TRUE(crco.first[3] == 22);
        UT_ASSERT_TRUE(crco.first[4] == 23);
        UT_ASSERT_TRUE(crco.first[5] == 24);
        UT_ASSERT_TRUE(crco.first[6] == 42);
        UT_ASSERT_TRUE(crco.first[7] == 71);
        UT_ASSERT_TRUE(crco.first[8] == 77);
        UT_ASSERT_TRUE(crco.first[9] == 82);
        UT_ASSERT_TRUE(crco.first[10] == 112);
        UT_ASSERT_TRUE(crco.first[11] == 116);
        UT_ASSERT_TRUE(crco.first[12] == 118);
        UT_ASSERT_TRUE(crco.first[13] == 125);
        UT_ASSERT_TRUE(crco.first[14] == 135);
        UT_ASSERT_TRUE(crco.first[15] == 154);
        UT_ASSERT_TRUE(crco.first[16] == 163);
        UT_ASSERT_TRUE(crco.first[17] == 164);
        UT_ASSERT_TRUE(crco.first[18] == 170);
        UT_ASSERT_TRUE(crco.first[19] == 173);
        UT_ASSERT_TRUE(crco.first[20] == 177);
        UT_ASSERT_TRUE(crco.first[21] == 186);
        UT_ASSERT_TRUE(crco.first[22] == 196);
        UT_ASSERT_TRUE(crco.first[23] == 207);
        UT_ASSERT_TRUE(crco.first[24] == 212);
        UT_ASSERT_TRUE(crco.first[25] == 214);
        UT_ASSERT_TRUE(crco.first[26] == 236);
        UT_ASSERT_TRUE(crco.first[27] == 257);
        UT_ASSERT_TRUE(crco.first[28] == 259);
        UT_ASSERT_TRUE(crco.first[29] == 269);
        UT_ASSERT_TRUE(crco.first[30] == 273);
        UT_ASSERT_TRUE(crco.first[31] == 288);
        UT_ASSERT_TRUE(crco.first[32] == 289);
        UT_ASSERT_TRUE(crco.first[33] == 291);
        UT_ASSERT_TRUE(crco.first[34] == 294);
        UT_ASSERT_TRUE(crco.first[35] == 318);
        UT_ASSERT_TRUE(crco.first[36] == 335);
        UT_ASSERT_TRUE(crco.first[37] == 340);
        UT_ASSERT_TRUE(crco.first[38] == 345);
        UT_ASSERT_TRUE(crco.first[39] == 362);
        UT_ASSERT_TRUE(crco.first[40] == 381);
        UT_ASSERT_TRUE(crco.first[41] == 389);
        UT_ASSERT_TRUE(crco.first[42] == 391);
        UT_ASSERT_TRUE(crco.first[43] == 414);
        UT_ASSERT_TRUE(crco.first[44] == 415);
        UT_ASSERT_TRUE(crco.first[45] == 416);
        UT_ASSERT_TRUE(crco.first[46] == 420);
        UT_ASSERT_TRUE(crco.first[47] == 429);
        UT_ASSERT_TRUE(crco.first[48] == 430);
        UT_ASSERT_TRUE(crco.first[49] == 435);
        UT_ASSERT_TRUE(crco.first[50] == 441);
        UT_ASSERT_TRUE(crco.first[51] == 450);
        UT_ASSERT_TRUE(crco.first[52] == 452);
        UT_ASSERT_TRUE(crco.first[53] == 458);
        UT_ASSERT_TRUE(crco.first[54] == 497);

        crco = clauses_repr_clauses_of(cr, 7);
        UT_ASSERT_TRUE(crco.len == 53);
        UT_ASSERT_TRUE(crco.first[0] == 7);
        UT_ASSERT_TRUE(crco.first[1] == 25);
        UT_ASSERT_TRUE(crco.first[2] == 26);
        UT_ASSERT_TRUE(crco.first[3] == 28);
        UT_ASSERT_TRUE(crco.first[4] == 29);
        UT_ASSERT_TRUE(crco.first[5] == 44);
        UT_ASSERT_TRUE(crco.first[6] == 52);
        UT_ASSERT_TRUE(crco.first[7] == 60);
        UT_ASSERT_TRUE(crco.first[8] == 74);
        UT_ASSERT_TRUE(crco.first[9] == 76);
        UT_ASSERT_TRUE(crco.first[10] == 80);
        UT_ASSERT_TRUE(crco.first[11] == 81);
        UT_ASSERT_TRUE(crco.first[12] == 89);
        UT_ASSERT_TRUE(crco.first[13] == 102);
        UT_ASSERT_TRUE(crco.first[14] == 112);
        UT_ASSERT_TRUE(crco.first[15] == 115);
        UT_ASSERT_TRUE(crco.first[16] == 116);
        UT_ASSERT_TRUE(crco.first[17] == 121);
        UT_ASSERT_TRUE(crco.first[18] == 126);
        UT_ASSERT_TRUE(crco.first[19] == 131);
        UT_ASSERT_TRUE(crco.first[20] == 153);
        UT_ASSERT_TRUE(crco.first[21] == 157);
        UT_ASSERT_TRUE(crco.first[22] == 170);
        UT_ASSERT_TRUE(crco.first[23] == 178);
        UT_ASSERT_TRUE(crco.first[24] == 179);
        UT_ASSERT_TRUE(crco.first[25] == 190);
        UT_ASSERT_TRUE(crco.first[26] == 196);
        UT_ASSERT_TRUE(crco.first[27] == 232);
        UT_ASSERT_TRUE(crco.first[28] == 237);
        UT_ASSERT_TRUE(crco.first[29] == 244);
        UT_ASSERT_TRUE(crco.first[30] == 269);
        UT_ASSERT_TRUE(crco.first[31] == 279);
        UT_ASSERT_TRUE(crco.first[32] == 284);
        UT_ASSERT_TRUE(crco.first[33] == 290);
        UT_ASSERT_TRUE(crco.first[34] == 298);
        UT_ASSERT_TRUE(crco.first[35] == 302);
        UT_ASSERT_TRUE(crco.first[36] == 307);
        UT_ASSERT_TRUE(crco.first[37] == 308);
        UT_ASSERT_TRUE(crco.first[38] == 330);
        UT_ASSERT_TRUE(crco.first[39] == 346);
        UT_ASSERT_TRUE(crco.first[40] == 382);
        UT_ASSERT_TRUE(crco.first[41] == 386);
        UT_ASSERT_TRUE(crco.first[42] == 395);
        UT_ASSERT_TRUE(crco.first[43] == 396);
        UT_ASSERT_TRUE(crco.first[44] == 403);
        UT_ASSERT_TRUE(crco.first[45] == 410);
        UT_ASSERT_TRUE(crco.first[46] == 424);
        UT_ASSERT_TRUE(crco.first[47] == 429);
        UT_ASSERT_TRUE(crco.first[48] == 433);
        UT_ASSERT_TRUE(crco.first[49] == 438);
        UT_ASSERT_TRUE(crco.first[50] == 448);
        UT_ASSERT_TRUE(crco.first[51] == 492);
        UT_ASSERT_TRUE(crco.first[52] == 494);

        crco = clauses_repr_clauses_of(cr, 8);
        UT_ASSERT_TRUE(crco.len == 54);
        UT_ASSERT_TRUE(crco.first[0] == 1);
        UT_ASSERT_TRUE(crco.first[1] == 62);
        UT_ASSERT_TRUE(crco.first[2] == 70);
        UT_ASSERT_TRUE(crco.first[3] == 85);
        UT_ASSERT_TRUE(crco.first[4] == 94);
        UT_ASSERT_TRUE(crco.first[5] == 105);
        UT_ASSERT_TRUE(crco.first[6] == 110);
        UT_ASSERT_TRUE(crco.first[7] == 113);
        UT_ASSERT_TRUE(crco.first[8] == 120);
        UT_ASSERT_TRUE(crco.first[9] == 133);
        UT_ASSERT_TRUE(crco.first[10] == 134);
        UT_ASSERT_TRUE(crco.first[11] == 139);
        UT_ASSERT_TRUE(crco.first[12] == 142);
        UT_ASSERT_TRUE(crco.first[13] == 149);
        UT_ASSERT_TRUE(crco.first[14] == 154);
        UT_ASSERT_TRUE(crco.first[15] == 165);
        UT_ASSERT_TRUE(crco.first[16] == 170);
        UT_ASSERT_TRUE(crco.first[17] == 172);
        UT_ASSERT_TRUE(crco.first[18] == 200);
        UT_ASSERT_TRUE(crco.first[19] == 203);
        UT_ASSERT_TRUE(crco.first[20] == 210);
        UT_ASSERT_TRUE(crco.first[21] == 214);
        UT_ASSERT_TRUE(crco.first[22] == 218);
        UT_ASSERT_TRUE(crco.first[23] == 221);
        UT_ASSERT_TRUE(crco.first[24] == 242);
        UT_ASSERT_TRUE(crco.first[25] == 248);
        UT_ASSERT_TRUE(crco.first[26] == 251);
        UT_ASSERT_TRUE(crco.first[27] == 252);
        UT_ASSERT_TRUE(crco.first[28] == 257);
        UT_ASSERT_TRUE(crco.first[29] == 263);
        UT_ASSERT_TRUE(crco.first[30] == 274);
        UT_ASSERT_TRUE(crco.first[31] == 280);
        UT_ASSERT_TRUE(crco.first[32] == 283);
        UT_ASSERT_TRUE(crco.first[33] == 294);
        UT_ASSERT_TRUE(crco.first[34] == 312);
        UT_ASSERT_TRUE(crco.first[35] == 325);
        UT_ASSERT_TRUE(crco.first[36] == 361);
        UT_ASSERT_TRUE(crco.first[37] == 392);
        UT_ASSERT_TRUE(crco.first[38] == 393);
        UT_ASSERT_TRUE(crco.first[39] == 395);
        UT_ASSERT_TRUE(crco.first[40] == 397);
        UT_ASSERT_TRUE(crco.first[41] == 413);
        UT_ASSERT_TRUE(crco.first[42] == 432);
        UT_ASSERT_TRUE(crco.first[43] == 457);
        UT_ASSERT_TRUE(crco.first[44] == 467);
        UT_ASSERT_TRUE(crco.first[45] == 476);
        UT_ASSERT_TRUE(crco.first[46] == 477);
        UT_ASSERT_TRUE(crco.first[47] == 478);
        UT_ASSERT_TRUE(crco.first[48] == 481);
        UT_ASSERT_TRUE(crco.first[49] == 485);
        UT_ASSERT_TRUE(crco.first[50] == 491);
        UT_ASSERT_TRUE(crco.first[51] == 493);
        UT_ASSERT_TRUE(crco.first[52] == 494);
        UT_ASSERT_TRUE(crco.first[53] == 496);

        crco = clauses_repr_clauses_of(cr, 9);
        UT_ASSERT_TRUE(crco.len == 59);
        UT_ASSERT_TRUE(crco.first[0] == 0);
        UT_ASSERT_TRUE(crco.first[1] == 6);
        UT_ASSERT_TRUE(crco.first[2] == 8);
        UT_ASSERT_TRUE(crco.first[3] == 14);
        UT_ASSERT_TRUE(crco.first[4] == 17);
        UT_ASSERT_TRUE(crco.first[5] == 18);
        UT_ASSERT_TRUE(crco.first[6] == 36);
        UT_ASSERT_TRUE(crco.first[7] == 50);
        UT_ASSERT_TRUE(crco.first[8] == 53);
        UT_ASSERT_TRUE(crco.first[9] == 66);
        UT_ASSERT_TRUE(crco.first[10] == 67);
        UT_ASSERT_TRUE(crco.first[11] == 80);
        UT_ASSERT_TRUE(crco.first[12] == 83);
        UT_ASSERT_TRUE(crco.first[13] == 87);
        UT_ASSERT_TRUE(crco.first[14] == 95);
        UT_ASSERT_TRUE(crco.first[15] == 99);
        UT_ASSERT_TRUE(crco.first[16] == 104);
        UT_ASSERT_TRUE(crco.first[17] == 123);
        UT_ASSERT_TRUE(crco.first[18] == 149);
        UT_ASSERT_TRUE(crco.first[19] == 152);
        UT_ASSERT_TRUE(crco.first[20] == 159);
        UT_ASSERT_TRUE(crco.first[21] == 173);
        UT_ASSERT_TRUE(crco.first[22] == 180);
        UT_ASSERT_TRUE(crco.first[23] == 204);
        UT_ASSERT_TRUE(crco.first[24] == 205);
        UT_ASSERT_TRUE(crco.first[25] == 213);
        UT_ASSERT_TRUE(crco.first[26] == 218);
        UT_ASSERT_TRUE(crco.first[27] == 225);
        UT_ASSERT_TRUE(crco.first[28] == 230);
        UT_ASSERT_TRUE(crco.first[29] == 250);
        UT_ASSERT_TRUE(crco.first[30] == 252);
        UT_ASSERT_TRUE(crco.first[31] == 267);
        UT_ASSERT_TRUE(crco.first[32] == 270);
        UT_ASSERT_TRUE(crco.first[33] == 283);
        UT_ASSERT_TRUE(crco.first[34] == 298);
        UT_ASSERT_TRUE(crco.first[35] == 310);
        UT_ASSERT_TRUE(crco.first[36] == 314);
        UT_ASSERT_TRUE(crco.first[37] == 317);
        UT_ASSERT_TRUE(crco.first[38] == 319);
        UT_ASSERT_TRUE(crco.first[39] == 321);
        UT_ASSERT_TRUE(crco.first[40] == 324);
        UT_ASSERT_TRUE(crco.first[41] == 333);
        UT_ASSERT_TRUE(crco.first[42] == 338);
        UT_ASSERT_TRUE(crco.first[43] == 343);
        UT_ASSERT_TRUE(crco.first[44] == 351);
        UT_ASSERT_TRUE(crco.first[45] == 352);
        UT_ASSERT_TRUE(crco.first[46] == 356);
        UT_ASSERT_TRUE(crco.first[47] == 390);
        UT_ASSERT_TRUE(crco.first[48] == 399);
        UT_ASSERT_TRUE(crco.first[49] == 400);
        UT_ASSERT_TRUE(crco.first[50] == 401);
        UT_ASSERT_TRUE(crco.first[51] == 406);
        UT_ASSERT_TRUE(crco.first[52] == 408);
        UT_ASSERT_TRUE(crco.first[53] == 412);
        UT_ASSERT_TRUE(crco.first[54] == 431);
        UT_ASSERT_TRUE(crco.first[55] == 457);
        UT_ASSERT_TRUE(crco.first[56] == 462);
        UT_ASSERT_TRUE(crco.first[57] == 469);
        UT_ASSERT_TRUE(crco.first[58] == 499);

        crco = clauses_repr_clauses_of(cr, 10);
        UT_ASSERT_TRUE(crco.len == 63);
        UT_ASSERT_TRUE(crco.first[0] == 1);
        UT_ASSERT_TRUE(crco.first[1] == 7);
        UT_ASSERT_TRUE(crco.first[2] == 10);
        UT_ASSERT_TRUE(crco.first[3] == 11);
        UT_ASSERT_TRUE(crco.first[4] == 17);
        UT_ASSERT_TRUE(crco.first[5] == 18);
        UT_ASSERT_TRUE(crco.first[6] == 19);
        UT_ASSERT_TRUE(crco.first[7] == 41);
        UT_ASSERT_TRUE(crco.first[8] == 51);
        UT_ASSERT_TRUE(crco.first[9] == 52);
        UT_ASSERT_TRUE(crco.first[10] == 64);
        UT_ASSERT_TRUE(crco.first[11] == 71);
        UT_ASSERT_TRUE(crco.first[12] == 78);
        UT_ASSERT_TRUE(crco.first[13] == 93);
        UT_ASSERT_TRUE(crco.first[14] == 100);
        UT_ASSERT_TRUE(crco.first[15] == 103);
        UT_ASSERT_TRUE(crco.first[16] == 124);
        UT_ASSERT_TRUE(crco.first[17] == 133);
        UT_ASSERT_TRUE(crco.first[18] == 135);
        UT_ASSERT_TRUE(crco.first[19] == 140);
        UT_ASSERT_TRUE(crco.first[20] == 141);
        UT_ASSERT_TRUE(crco.first[21] == 144);
        UT_ASSERT_TRUE(crco.first[22] == 151);
        UT_ASSERT_TRUE(crco.first[23] == 152);
        UT_ASSERT_TRUE(crco.first[24] == 155);
        UT_ASSERT_TRUE(crco.first[25] == 158);
        UT_ASSERT_TRUE(crco.first[26] == 160);
        UT_ASSERT_TRUE(crco.first[27] == 178);
        UT_ASSERT_TRUE(crco.first[28] == 186);
        UT_ASSERT_TRUE(crco.first[29] == 188);
        UT_ASSERT_TRUE(crco.first[30] == 190);
        UT_ASSERT_TRUE(crco.first[31] == 192);
        UT_ASSERT_TRUE(crco.first[32] == 195);
        UT_ASSERT_TRUE(crco.first[33] == 198);
        UT_ASSERT_TRUE(crco.first[34] == 207);
        UT_ASSERT_TRUE(crco.first[35] == 213);
        UT_ASSERT_TRUE(crco.first[36] == 215);
        UT_ASSERT_TRUE(crco.first[37] == 216);
        UT_ASSERT_TRUE(crco.first[38] == 220);
        UT_ASSERT_TRUE(crco.first[39] == 222);
        UT_ASSERT_TRUE(crco.first[40] == 250);
        UT_ASSERT_TRUE(crco.first[41] == 260);
        UT_ASSERT_TRUE(crco.first[42] == 263);
        UT_ASSERT_TRUE(crco.first[43] == 268);
        UT_ASSERT_TRUE(crco.first[44] == 287);
        UT_ASSERT_TRUE(crco.first[45] == 291);
        UT_ASSERT_TRUE(crco.first[46] == 320);
        UT_ASSERT_TRUE(crco.first[47] == 322);
        UT_ASSERT_TRUE(crco.first[48] == 354);
        UT_ASSERT_TRUE(crco.first[49] == 377);
        UT_ASSERT_TRUE(crco.first[50] == 406);
        UT_ASSERT_TRUE(crco.first[51] == 411);
        UT_ASSERT_TRUE(crco.first[52] == 423);
        UT_ASSERT_TRUE(crco.first[53] == 427);
        UT_ASSERT_TRUE(crco.first[54] == 432);
        UT_ASSERT_TRUE(crco.first[55] == 436);
        UT_ASSERT_TRUE(crco.first[56] == 450);
        UT_ASSERT_TRUE(crco.first[57] == 456);
        UT_ASSERT_TRUE(crco.first[58] == 461);
        UT_ASSERT_TRUE(crco.first[59] == 464);
        UT_ASSERT_TRUE(crco.first[60] == 480);
        UT_ASSERT_TRUE(crco.first[61] == 482);
        UT_ASSERT_TRUE(crco.first[62] == 495);

        crco = clauses_repr_clauses_of(cr, 11);
        UT_ASSERT_TRUE(crco.len == 60);
        UT_ASSERT_TRUE(crco.first[0] == 2);
        UT_ASSERT_TRUE(crco.first[1] == 13);
        UT_ASSERT_TRUE(crco.first[2] == 21);
        UT_ASSERT_TRUE(crco.first[3] == 30);
        UT_ASSERT_TRUE(crco.first[4] == 31);
        UT_ASSERT_TRUE(crco.first[5] == 35);
        UT_ASSERT_TRUE(crco.first[6] == 38);
        UT_ASSERT_TRUE(crco.first[7] == 42);
        UT_ASSERT_TRUE(crco.first[8] == 45);
        UT_ASSERT_TRUE(crco.first[9] == 78);
        UT_ASSERT_TRUE(crco.first[10] == 79);
        UT_ASSERT_TRUE(crco.first[11] == 80);
        UT_ASSERT_TRUE(crco.first[12] == 106);
        UT_ASSERT_TRUE(crco.first[13] == 107);
        UT_ASSERT_TRUE(crco.first[14] == 109);
        UT_ASSERT_TRUE(crco.first[15] == 130);
        UT_ASSERT_TRUE(crco.first[16] == 136);
        UT_ASSERT_TRUE(crco.first[17] == 139);
        UT_ASSERT_TRUE(crco.first[18] == 147);
        UT_ASSERT_TRUE(crco.first[19] == 158);
        UT_ASSERT_TRUE(crco.first[20] == 161);
        UT_ASSERT_TRUE(crco.first[21] == 163);
        UT_ASSERT_TRUE(crco.first[22] == 181);
        UT_ASSERT_TRUE(crco.first[23] == 211);
        UT_ASSERT_TRUE(crco.first[24] == 222);
        UT_ASSERT_TRUE(crco.first[25] == 229);
        UT_ASSERT_TRUE(crco.first[26] == 248);
        UT_ASSERT_TRUE(crco.first[27] == 254);
        UT_ASSERT_TRUE(crco.first[28] == 255);
        UT_ASSERT_TRUE(crco.first[29] == 264);
        UT_ASSERT_TRUE(crco.first[30] == 277);
        UT_ASSERT_TRUE(crco.first[31] == 283);
        UT_ASSERT_TRUE(crco.first[32] == 288);
        UT_ASSERT_TRUE(crco.first[33] == 293);
        UT_ASSERT_TRUE(crco.first[34] == 296);
        UT_ASSERT_TRUE(crco.first[35] == 305);
        UT_ASSERT_TRUE(crco.first[36] == 306);
        UT_ASSERT_TRUE(crco.first[37] == 309);
        UT_ASSERT_TRUE(crco.first[38] == 315);
        UT_ASSERT_TRUE(crco.first[39] == 324);
        UT_ASSERT_TRUE(crco.first[40] == 325);
        UT_ASSERT_TRUE(crco.first[41] == 329);
        UT_ASSERT_TRUE(crco.first[42] == 333);
        UT_ASSERT_TRUE(crco.first[43] == 337);
        UT_ASSERT_TRUE(crco.first[44] == 340);
        UT_ASSERT_TRUE(crco.first[45] == 345);
        UT_ASSERT_TRUE(crco.first[46] == 355);
        UT_ASSERT_TRUE(crco.first[47] == 367);
        UT_ASSERT_TRUE(crco.first[48] == 373);
        UT_ASSERT_TRUE(crco.first[49] == 387);
        UT_ASSERT_TRUE(crco.first[50] == 388);
        UT_ASSERT_TRUE(crco.first[51] == 395);
        UT_ASSERT_TRUE(crco.first[52] == 421);
        UT_ASSERT_TRUE(crco.first[53] == 430);
        UT_ASSERT_TRUE(crco.first[54] == 438);
        UT_ASSERT_TRUE(crco.first[55] == 452);
        UT_ASSERT_TRUE(crco.first[56] == 453);
        UT_ASSERT_TRUE(crco.first[57] == 463);
        UT_ASSERT_TRUE(crco.first[58] == 471);
        UT_ASSERT_TRUE(crco.first[59] == 484);

        crco = clauses_repr_clauses_of(cr, 12);
        UT_ASSERT_TRUE(crco.len == 62);
        UT_ASSERT_TRUE(crco.first[0] == 0);
        UT_ASSERT_TRUE(crco.first[1] == 8);
        UT_ASSERT_TRUE(crco.first[2] == 13);
        UT_ASSERT_TRUE(crco.first[3] == 16);
        UT_ASSERT_TRUE(crco.first[4] == 17);
        UT_ASSERT_TRUE(crco.first[5] == 20);
        UT_ASSERT_TRUE(crco.first[6] == 39);
        UT_ASSERT_TRUE(crco.first[7] == 47);
        UT_ASSERT_TRUE(crco.first[8] == 51);
        UT_ASSERT_TRUE(crco.first[9] == 63);
        UT_ASSERT_TRUE(crco.first[10] == 64);
        UT_ASSERT_TRUE(crco.first[11] == 65);
        UT_ASSERT_TRUE(crco.first[12] == 78);
        UT_ASSERT_TRUE(crco.first[13] == 93);
        UT_ASSERT_TRUE(crco.first[14] == 97);
        UT_ASSERT_TRUE(crco.first[15] == 108);
        UT_ASSERT_TRUE(crco.first[16] == 117);
        UT_ASSERT_TRUE(crco.first[17] == 122);
        UT_ASSERT_TRUE(crco.first[18] == 140);
        UT_ASSERT_TRUE(crco.first[19] == 142);
        UT_ASSERT_TRUE(crco.first[20] == 149);
        UT_ASSERT_TRUE(crco.first[21] == 156);
        UT_ASSERT_TRUE(crco.first[22] == 174);
        UT_ASSERT_TRUE(crco.first[23] == 176);
        UT_ASSERT_TRUE(crco.first[24] == 195);
        UT_ASSERT_TRUE(crco.first[25] == 197);
        UT_ASSERT_TRUE(crco.first[26] == 205);
        UT_ASSERT_TRUE(crco.first[27] == 219);
        UT_ASSERT_TRUE(crco.first[28] == 230);
        UT_ASSERT_TRUE(crco.first[29] == 250);
        UT_ASSERT_TRUE(crco.first[30] == 271);
        UT_ASSERT_TRUE(crco.first[31] == 278);
        UT_ASSERT_TRUE(crco.first[32] == 297);
        UT_ASSERT_TRUE(crco.first[33] == 307);
        UT_ASSERT_TRUE(crco.first[34] == 311);
        UT_ASSERT_TRUE(crco.first[35] == 315);
        UT_ASSERT_TRUE(crco.first[36] == 316);
        UT_ASSERT_TRUE(crco.first[37] == 320);
        UT_ASSERT_TRUE(crco.first[38] == 322);
        UT_ASSERT_TRUE(crco.first[39] == 334);
        UT_ASSERT_TRUE(crco.first[40] == 338);
        UT_ASSERT_TRUE(crco.first[41] == 341);
        UT_ASSERT_TRUE(crco.first[42] == 349);
        UT_ASSERT_TRUE(crco.first[43] == 362);
        UT_ASSERT_TRUE(crco.first[44] == 370);
        UT_ASSERT_TRUE(crco.first[45] == 376);
        UT_ASSERT_TRUE(crco.first[46] == 378);
        UT_ASSERT_TRUE(crco.first[47] == 379);
        UT_ASSERT_TRUE(crco.first[48] == 383);
        UT_ASSERT_TRUE(crco.first[49] == 385);
        UT_ASSERT_TRUE(crco.first[50] == 392);
        UT_ASSERT_TRUE(crco.first[51] == 407);
        UT_ASSERT_TRUE(crco.first[52] == 409);
        UT_ASSERT_TRUE(crco.first[53] == 415);
        UT_ASSERT_TRUE(crco.first[54] == 421);
        UT_ASSERT_TRUE(crco.first[55] == 439);
        UT_ASSERT_TRUE(crco.first[56] == 453);
        UT_ASSERT_TRUE(crco.first[57] == 468);
        UT_ASSERT_TRUE(crco.first[58] == 475);
        UT_ASSERT_TRUE(crco.first[59] == 476);
        UT_ASSERT_TRUE(crco.first[60] == 479);
        UT_ASSERT_TRUE(crco.first[61] == 488);

        crco = clauses_repr_clauses_of(cr, 13);
        UT_ASSERT_TRUE(crco.len == 68);
        UT_ASSERT_TRUE(crco.first[0] == 2);
        UT_ASSERT_TRUE(crco.first[1] == 12);
        UT_ASSERT_TRUE(crco.first[2] == 14);
        UT_ASSERT_TRUE(crco.first[3] == 15);
        UT_ASSERT_TRUE(crco.first[4] == 32);
        UT_ASSERT_TRUE(crco.first[5] == 35);
        UT_ASSERT_TRUE(crco.first[6] == 40);
        UT_ASSERT_TRUE(crco.first[7] == 42);
        UT_ASSERT_TRUE(crco.first[8] == 44);
        UT_ASSERT_TRUE(crco.first[9] == 48);
        UT_ASSERT_TRUE(crco.first[10] == 49);
        UT_ASSERT_TRUE(crco.first[11] == 50);
        UT_ASSERT_TRUE(crco.first[12] == 54);
        UT_ASSERT_TRUE(crco.first[13] == 57);
        UT_ASSERT_TRUE(crco.first[14] == 60);
        UT_ASSERT_TRUE(crco.first[15] == 72);
        UT_ASSERT_TRUE(crco.first[16] == 76);
        UT_ASSERT_TRUE(crco.first[17] == 81);
        UT_ASSERT_TRUE(crco.first[18] == 87);
        UT_ASSERT_TRUE(crco.first[19] == 92);
        UT_ASSERT_TRUE(crco.first[20] == 104);
        UT_ASSERT_TRUE(crco.first[21] == 106);
        UT_ASSERT_TRUE(crco.first[22] == 110);
        UT_ASSERT_TRUE(crco.first[23] == 113);
        UT_ASSERT_TRUE(crco.first[24] == 126);
        UT_ASSERT_TRUE(crco.first[25] == 127);
        UT_ASSERT_TRUE(crco.first[26] == 128);
        UT_ASSERT_TRUE(crco.first[27] == 129);
        UT_ASSERT_TRUE(crco.first[28] == 138);
        UT_ASSERT_TRUE(crco.first[29] == 153);
        UT_ASSERT_TRUE(crco.first[30] == 157);
        UT_ASSERT_TRUE(crco.first[31] == 159);
        UT_ASSERT_TRUE(crco.first[32] == 166);
        UT_ASSERT_TRUE(crco.first[33] == 167);
        UT_ASSERT_TRUE(crco.first[34] == 175);
        UT_ASSERT_TRUE(crco.first[35] == 193);
        UT_ASSERT_TRUE(crco.first[36] == 194);
        UT_ASSERT_TRUE(crco.first[37] == 198);
        UT_ASSERT_TRUE(crco.first[38] == 201);
        UT_ASSERT_TRUE(crco.first[39] == 202);
        UT_ASSERT_TRUE(crco.first[40] == 205);
        UT_ASSERT_TRUE(crco.first[41] == 208);
        UT_ASSERT_TRUE(crco.first[42] == 222);
        UT_ASSERT_TRUE(crco.first[43] == 223);
        UT_ASSERT_TRUE(crco.first[44] == 226);
        UT_ASSERT_TRUE(crco.first[45] == 228);
        UT_ASSERT_TRUE(crco.first[46] == 229);
        UT_ASSERT_TRUE(crco.first[47] == 233);
        UT_ASSERT_TRUE(crco.first[48] == 235);
        UT_ASSERT_TRUE(crco.first[49] == 241);
        UT_ASSERT_TRUE(crco.first[50] == 254);
        UT_ASSERT_TRUE(crco.first[51] == 281);
        UT_ASSERT_TRUE(crco.first[52] == 305);
        UT_ASSERT_TRUE(crco.first[53] == 319);
        UT_ASSERT_TRUE(crco.first[54] == 320);
        UT_ASSERT_TRUE(crco.first[55] == 355);
        UT_ASSERT_TRUE(crco.first[56] == 366);
        UT_ASSERT_TRUE(crco.first[57] == 372);
        UT_ASSERT_TRUE(crco.first[58] == 384);
        UT_ASSERT_TRUE(crco.first[59] == 385);
        UT_ASSERT_TRUE(crco.first[60] == 416);
        UT_ASSERT_TRUE(crco.first[61] == 437);
        UT_ASSERT_TRUE(crco.first[62] == 438);
        UT_ASSERT_TRUE(crco.first[63] == 443);
        UT_ASSERT_TRUE(crco.first[64] == 450);
        UT_ASSERT_TRUE(crco.first[65] == 473);
        UT_ASSERT_TRUE(crco.first[66] == 482);
        UT_ASSERT_TRUE(crco.first[67] == 489);

        crco = clauses_repr_clauses_of(cr, 14);
        UT_ASSERT_TRUE(crco.len == 66);
        UT_ASSERT_TRUE(crco.first[0] == 4);
        UT_ASSERT_TRUE(crco.first[1] == 5);
        UT_ASSERT_TRUE(crco.first[2] == 25);
        UT_ASSERT_TRUE(crco.first[3] == 38);
        UT_ASSERT_TRUE(crco.first[4] == 41);
        UT_ASSERT_TRUE(crco.first[5] == 54);
        UT_ASSERT_TRUE(crco.first[6] == 56);
        UT_ASSERT_TRUE(crco.first[7] == 61);
        UT_ASSERT_TRUE(crco.first[8] == 68);
        UT_ASSERT_TRUE(crco.first[9] == 83);
        UT_ASSERT_TRUE(crco.first[10] == 86);
        UT_ASSERT_TRUE(crco.first[11] == 94);
        UT_ASSERT_TRUE(crco.first[12] == 102);
        UT_ASSERT_TRUE(crco.first[13] == 109);
        UT_ASSERT_TRUE(crco.first[14] == 111);
        UT_ASSERT_TRUE(crco.first[15] == 113);
        UT_ASSERT_TRUE(crco.first[16] == 127);
        UT_ASSERT_TRUE(crco.first[17] == 140);
        UT_ASSERT_TRUE(crco.first[18] == 143);
        UT_ASSERT_TRUE(crco.first[19] == 146);
        UT_ASSERT_TRUE(crco.first[20] == 147);
        UT_ASSERT_TRUE(crco.first[21] == 162);
        UT_ASSERT_TRUE(crco.first[22] == 165);
        UT_ASSERT_TRUE(crco.first[23] == 166);
        UT_ASSERT_TRUE(crco.first[24] == 169);
        UT_ASSERT_TRUE(crco.first[25] == 172);
        UT_ASSERT_TRUE(crco.first[26] == 177);
        UT_ASSERT_TRUE(crco.first[27] == 179);
        UT_ASSERT_TRUE(crco.first[28] == 180);
        UT_ASSERT_TRUE(crco.first[29] == 185);
        UT_ASSERT_TRUE(crco.first[30] == 186);
        UT_ASSERT_TRUE(crco.first[31] == 187);
        UT_ASSERT_TRUE(crco.first[32] == 188);
        UT_ASSERT_TRUE(crco.first[33] == 215);
        UT_ASSERT_TRUE(crco.first[34] == 233);
        UT_ASSERT_TRUE(crco.first[35] == 243);
        UT_ASSERT_TRUE(crco.first[36] == 246);
        UT_ASSERT_TRUE(crco.first[37] == 247);
        UT_ASSERT_TRUE(crco.first[38] == 255);
        UT_ASSERT_TRUE(crco.first[39] == 265);
        UT_ASSERT_TRUE(crco.first[40] == 267);
        UT_ASSERT_TRUE(crco.first[41] == 272);
        UT_ASSERT_TRUE(crco.first[42] == 299);
        UT_ASSERT_TRUE(crco.first[43] == 317);
        UT_ASSERT_TRUE(crco.first[44] == 318);
        UT_ASSERT_TRUE(crco.first[45] == 331);
        UT_ASSERT_TRUE(crco.first[46] == 332);
        UT_ASSERT_TRUE(crco.first[47] == 353);
        UT_ASSERT_TRUE(crco.first[48] == 354);
        UT_ASSERT_TRUE(crco.first[49] == 366);
        UT_ASSERT_TRUE(crco.first[50] == 368);
        UT_ASSERT_TRUE(crco.first[51] == 377);
        UT_ASSERT_TRUE(crco.first[52] == 390);
        UT_ASSERT_TRUE(crco.first[53] == 396);
        UT_ASSERT_TRUE(crco.first[54] == 405);
        UT_ASSERT_TRUE(crco.first[55] == 418);
        UT_ASSERT_TRUE(crco.first[56] == 421);
        UT_ASSERT_TRUE(crco.first[57] == 422);
        UT_ASSERT_TRUE(crco.first[58] == 432);
        UT_ASSERT_TRUE(crco.first[59] == 439);
        UT_ASSERT_TRUE(crco.first[60] == 444);
        UT_ASSERT_TRUE(crco.first[61] == 446);
        UT_ASSERT_TRUE(crco.first[62] == 447);
        UT_ASSERT_TRUE(crco.first[63] == 473);
        UT_ASSERT_TRUE(crco.first[64] == 478);
        UT_ASSERT_TRUE(crco.first[65] == 493);

        crco = clauses_repr_clauses_of(cr, 15);
        UT_ASSERT_TRUE(crco.len == 47);
        UT_ASSERT_TRUE(crco.first[0] == 0);
        UT_ASSERT_TRUE(crco.first[1] == 6);
        UT_ASSERT_TRUE(crco.first[2] == 11);
        UT_ASSERT_TRUE(crco.first[3] == 84);
        UT_ASSERT_TRUE(crco.first[4] == 90);
        UT_ASSERT_TRUE(crco.first[5] == 96);
        UT_ASSERT_TRUE(crco.first[6] == 103);
        UT_ASSERT_TRUE(crco.first[7] == 124);
        UT_ASSERT_TRUE(crco.first[8] == 130);
        UT_ASSERT_TRUE(crco.first[9] == 142);
        UT_ASSERT_TRUE(crco.first[10] == 151);
        UT_ASSERT_TRUE(crco.first[11] == 153);
        UT_ASSERT_TRUE(crco.first[12] == 166);
        UT_ASSERT_TRUE(crco.first[13] == 169);
        UT_ASSERT_TRUE(crco.first[14] == 177);
        UT_ASSERT_TRUE(crco.first[15] == 192);
        UT_ASSERT_TRUE(crco.first[16] == 199);
        UT_ASSERT_TRUE(crco.first[17] == 218);
        UT_ASSERT_TRUE(crco.first[18] == 236);
        UT_ASSERT_TRUE(crco.first[19] == 240);
        UT_ASSERT_TRUE(crco.first[20] == 273);
        UT_ASSERT_TRUE(crco.first[21] == 275);
        UT_ASSERT_TRUE(crco.first[22] == 278);
        UT_ASSERT_TRUE(crco.first[23] == 282);
        UT_ASSERT_TRUE(crco.first[24] == 289);
        UT_ASSERT_TRUE(crco.first[25] == 295);
        UT_ASSERT_TRUE(crco.first[26] == 300);
        UT_ASSERT_TRUE(crco.first[27] == 326);
        UT_ASSERT_TRUE(crco.first[28] == 331);
        UT_ASSERT_TRUE(crco.first[29] == 339);
        UT_ASSERT_TRUE(crco.first[30] == 350);
        UT_ASSERT_TRUE(crco.first[31] == 361);
        UT_ASSERT_TRUE(crco.first[32] == 380);
        UT_ASSERT_TRUE(crco.first[33] == 403);
        UT_ASSERT_TRUE(crco.first[34] == 411);
        UT_ASSERT_TRUE(crco.first[35] == 412);
        UT_ASSERT_TRUE(crco.first[36] == 422);
        UT_ASSERT_TRUE(crco.first[37] == 424);
        UT_ASSERT_TRUE(crco.first[38] == 425);
        UT_ASSERT_TRUE(crco.first[39] == 426);
        UT_ASSERT_TRUE(crco.first[40] == 442);
        UT_ASSERT_TRUE(crco.first[41] == 449);
        UT_ASSERT_TRUE(crco.first[42] == 451);
        UT_ASSERT_TRUE(crco.first[43] == 463);
        UT_ASSERT_TRUE(crco.first[44] == 477);
        UT_ASSERT_TRUE(crco.first[45] == 491);
        UT_ASSERT_TRUE(crco.first[46] == 492);

        crco = clauses_repr_clauses_of(cr, 16);
        UT_ASSERT_TRUE(crco.len == 64);
        UT_ASSERT_TRUE(crco.first[0] == 21);
        UT_ASSERT_TRUE(crco.first[1] == 31);
        UT_ASSERT_TRUE(crco.first[2] == 46);
        UT_ASSERT_TRUE(crco.first[3] == 53);
        UT_ASSERT_TRUE(crco.first[4] == 56);
        UT_ASSERT_TRUE(crco.first[5] == 73);
        UT_ASSERT_TRUE(crco.first[6] == 85);
        UT_ASSERT_TRUE(crco.first[7] == 91);
        UT_ASSERT_TRUE(crco.first[8] == 100);
        UT_ASSERT_TRUE(crco.first[9] == 108);
        UT_ASSERT_TRUE(crco.first[10] == 112);
        UT_ASSERT_TRUE(crco.first[11] == 121);
        UT_ASSERT_TRUE(crco.first[12] == 123);
        UT_ASSERT_TRUE(crco.first[13] == 124);
        UT_ASSERT_TRUE(crco.first[14] == 132);
        UT_ASSERT_TRUE(crco.first[15] == 137);
        UT_ASSERT_TRUE(crco.first[16] == 148);
        UT_ASSERT_TRUE(crco.first[17] == 162);
        UT_ASSERT_TRUE(crco.first[18] == 182);
        UT_ASSERT_TRUE(crco.first[19] == 187);
        UT_ASSERT_TRUE(crco.first[20] == 203);
        UT_ASSERT_TRUE(crco.first[21] == 217);
        UT_ASSERT_TRUE(crco.first[22] == 221);
        UT_ASSERT_TRUE(crco.first[23] == 234);
        UT_ASSERT_TRUE(crco.first[24] == 235);
        UT_ASSERT_TRUE(crco.first[25] == 236);
        UT_ASSERT_TRUE(crco.first[26] == 237);
        UT_ASSERT_TRUE(crco.first[27] == 243);
        UT_ASSERT_TRUE(crco.first[28] == 256);
        UT_ASSERT_TRUE(crco.first[29] == 258);
        UT_ASSERT_TRUE(crco.first[30] == 260);
        UT_ASSERT_TRUE(crco.first[31] == 269);
        UT_ASSERT_TRUE(crco.first[32] == 274);
        UT_ASSERT_TRUE(crco.first[33] == 276);
        UT_ASSERT_TRUE(crco.first[34] == 280);
        UT_ASSERT_TRUE(crco.first[35] == 281);
        UT_ASSERT_TRUE(crco.first[36] == 284);
        UT_ASSERT_TRUE(crco.first[37] == 285);
        UT_ASSERT_TRUE(crco.first[38] == 308);
        UT_ASSERT_TRUE(crco.first[39] == 329);
        UT_ASSERT_TRUE(crco.first[40] == 331);
        UT_ASSERT_TRUE(crco.first[41] == 336);
        UT_ASSERT_TRUE(crco.first[42] == 346);
        UT_ASSERT_TRUE(crco.first[43] == 353);
        UT_ASSERT_TRUE(crco.first[44] == 360);
        UT_ASSERT_TRUE(crco.first[45] == 371);
        UT_ASSERT_TRUE(crco.first[46] == 372);
        UT_ASSERT_TRUE(crco.first[47] == 376);
        UT_ASSERT_TRUE(crco.first[48] == 377);
        UT_ASSERT_TRUE(crco.first[49] == 386);
        UT_ASSERT_TRUE(crco.first[50] == 397);
        UT_ASSERT_TRUE(crco.first[51] == 402);
        UT_ASSERT_TRUE(crco.first[52] == 414);
        UT_ASSERT_TRUE(crco.first[53] == 431);
        UT_ASSERT_TRUE(crco.first[54] == 445);
        UT_ASSERT_TRUE(crco.first[55] == 454);
        UT_ASSERT_TRUE(crco.first[56] == 458);
        UT_ASSERT_TRUE(crco.first[57] == 459);
        UT_ASSERT_TRUE(crco.first[58] == 466);
        UT_ASSERT_TRUE(crco.first[59] == 472);
        UT_ASSERT_TRUE(crco.first[60] == 481);
        UT_ASSERT_TRUE(crco.first[61] == 486);
        UT_ASSERT_TRUE(crco.first[62] == 487);
        UT_ASSERT_TRUE(crco.first[63] == 497);

        crco = clauses_repr_clauses_of(cr, 17);
        UT_ASSERT_TRUE(crco.len == 52);
        UT_ASSERT_TRUE(crco.first[0] == 16);
        UT_ASSERT_TRUE(crco.first[1] == 26);
        UT_ASSERT_TRUE(crco.first[2] == 43);
        UT_ASSERT_TRUE(crco.first[3] == 44);
        UT_ASSERT_TRUE(crco.first[4] == 45);
        UT_ASSERT_TRUE(crco.first[5] == 49);
        UT_ASSERT_TRUE(crco.first[6] == 51);
        UT_ASSERT_TRUE(crco.first[7] == 71);
        UT_ASSERT_TRUE(crco.first[8] == 90);
        UT_ASSERT_TRUE(crco.first[9] == 107);
        UT_ASSERT_TRUE(crco.first[10] == 108);
        UT_ASSERT_TRUE(crco.first[11] == 120);
        UT_ASSERT_TRUE(crco.first[12] == 128);
        UT_ASSERT_TRUE(crco.first[13] == 130);
        UT_ASSERT_TRUE(crco.first[14] == 144);
        UT_ASSERT_TRUE(crco.first[15] == 155);
        UT_ASSERT_TRUE(crco.first[16] == 158);
        UT_ASSERT_TRUE(crco.first[17] == 168);
        UT_ASSERT_TRUE(crco.first[18] == 175);
        UT_ASSERT_TRUE(crco.first[19] == 181);
        UT_ASSERT_TRUE(crco.first[20] == 184);
        UT_ASSERT_TRUE(crco.first[21] == 189);
        UT_ASSERT_TRUE(crco.first[22] == 206);
        UT_ASSERT_TRUE(crco.first[23] == 223);
        UT_ASSERT_TRUE(crco.first[24] == 226);
        UT_ASSERT_TRUE(crco.first[25] == 230);
        UT_ASSERT_TRUE(crco.first[26] == 234);
        UT_ASSERT_TRUE(crco.first[27] == 252);
        UT_ASSERT_TRUE(crco.first[28] == 297);
        UT_ASSERT_TRUE(crco.first[29] == 302);
        UT_ASSERT_TRUE(crco.first[30] == 304);
        UT_ASSERT_TRUE(crco.first[31] == 321);
        UT_ASSERT_TRUE(crco.first[32] == 326);
        UT_ASSERT_TRUE(crco.first[33] == 333);
        UT_ASSERT_TRUE(crco.first[34] == 335);
        UT_ASSERT_TRUE(crco.first[35] == 337);
        UT_ASSERT_TRUE(crco.first[36] == 339);
        UT_ASSERT_TRUE(crco.first[37] == 347);
        UT_ASSERT_TRUE(crco.first[38] == 367);
        UT_ASSERT_TRUE(crco.first[39] == 369);
        UT_ASSERT_TRUE(crco.first[40] == 384);
        UT_ASSERT_TRUE(crco.first[41] == 414);
        UT_ASSERT_TRUE(crco.first[42] == 419);
        UT_ASSERT_TRUE(crco.first[43] == 423);
        UT_ASSERT_TRUE(crco.first[44] == 426);
        UT_ASSERT_TRUE(crco.first[45] == 440);
        UT_ASSERT_TRUE(crco.first[46] == 455);
        UT_ASSERT_TRUE(crco.first[47] == 463);
        UT_ASSERT_TRUE(crco.first[48] == 474);
        UT_ASSERT_TRUE(crco.first[49] == 479);
        UT_ASSERT_TRUE(crco.first[50] == 489);
        UT_ASSERT_TRUE(crco.first[51] == 499);

        crco = clauses_repr_clauses_of(cr, 18);
        UT_ASSERT_TRUE(crco.len == 76);
        UT_ASSERT_TRUE(crco.first[0] == 3);
        UT_ASSERT_TRUE(crco.first[1] == 27);
        UT_ASSERT_TRUE(crco.first[2] == 34);
        UT_ASSERT_TRUE(crco.first[3] == 37);
        UT_ASSERT_TRUE(crco.first[4] == 43);
        UT_ASSERT_TRUE(crco.first[5] == 47);
        UT_ASSERT_TRUE(crco.first[6] == 48);
        UT_ASSERT_TRUE(crco.first[7] == 49);
        UT_ASSERT_TRUE(crco.first[8] == 53);
        UT_ASSERT_TRUE(crco.first[9] == 57);
        UT_ASSERT_TRUE(crco.first[10] == 58);
        UT_ASSERT_TRUE(crco.first[11] == 59);
        UT_ASSERT_TRUE(crco.first[12] == 65);
        UT_ASSERT_TRUE(crco.first[13] == 75);
        UT_ASSERT_TRUE(crco.first[14] == 83);
        UT_ASSERT_TRUE(crco.first[15] == 86);
        UT_ASSERT_TRUE(crco.first[16] == 88);
        UT_ASSERT_TRUE(crco.first[17] == 91);
        UT_ASSERT_TRUE(crco.first[18] == 92);
        UT_ASSERT_TRUE(crco.first[19] == 95);
        UT_ASSERT_TRUE(crco.first[20] == 101);
        UT_ASSERT_TRUE(crco.first[21] == 104);
        UT_ASSERT_TRUE(crco.first[22] == 120);
        UT_ASSERT_TRUE(crco.first[23] == 125);
        UT_ASSERT_TRUE(crco.first[24] == 129);
        UT_ASSERT_TRUE(crco.first[25] == 134);
        UT_ASSERT_TRUE(crco.first[26] == 136);
        UT_ASSERT_TRUE(crco.first[27] == 145);
        UT_ASSERT_TRUE(crco.first[28] == 147);
        UT_ASSERT_TRUE(crco.first[29] == 155);
        UT_ASSERT_TRUE(crco.first[30] == 159);
        UT_ASSERT_TRUE(crco.first[31] == 161);
        UT_ASSERT_TRUE(crco.first[32] == 164);
        UT_ASSERT_TRUE(crco.first[33] == 182);
        UT_ASSERT_TRUE(crco.first[34] == 183);
        UT_ASSERT_TRUE(crco.first[35] == 185);
        UT_ASSERT_TRUE(crco.first[36] == 189);
        UT_ASSERT_TRUE(crco.first[37] == 194);
        UT_ASSERT_TRUE(crco.first[38] == 204);
        UT_ASSERT_TRUE(crco.first[39] == 212);
        UT_ASSERT_TRUE(crco.first[40] == 224);
        UT_ASSERT_TRUE(crco.first[41] == 225);
        UT_ASSERT_TRUE(crco.first[42] == 227);
        UT_ASSERT_TRUE(crco.first[43] == 238);
        UT_ASSERT_TRUE(crco.first[44] == 239);
        UT_ASSERT_TRUE(crco.first[45] == 240);
        UT_ASSERT_TRUE(crco.first[46] == 245);
        UT_ASSERT_TRUE(crco.first[47] == 247);
        UT_ASSERT_TRUE(crco.first[48] == 249);
        UT_ASSERT_TRUE(crco.first[49] == 255);
        UT_ASSERT_TRUE(crco.first[50] == 258);
        UT_ASSERT_TRUE(crco.first[51] == 259);
        UT_ASSERT_TRUE(crco.first[52] == 260);
        UT_ASSERT_TRUE(crco.first[53] == 261);
        UT_ASSERT_TRUE(crco.first[54] == 290);
        UT_ASSERT_TRUE(crco.first[55] == 295);
        UT_ASSERT_TRUE(crco.first[56] == 298);
        UT_ASSERT_TRUE(crco.first[57] == 299);
        UT_ASSERT_TRUE(crco.first[58] == 318);
        UT_ASSERT_TRUE(crco.first[59] == 327);
        UT_ASSERT_TRUE(crco.first[60] == 328);
        UT_ASSERT_TRUE(crco.first[61] == 342);
        UT_ASSERT_TRUE(crco.first[62] == 352);
        UT_ASSERT_TRUE(crco.first[63] == 372);
        UT_ASSERT_TRUE(crco.first[64] == 373);
        UT_ASSERT_TRUE(crco.first[65] == 393);
        UT_ASSERT_TRUE(crco.first[66] == 413);
        UT_ASSERT_TRUE(crco.first[67] == 418);
        UT_ASSERT_TRUE(crco.first[68] == 433);
        UT_ASSERT_TRUE(crco.first[69] == 434);
        UT_ASSERT_TRUE(crco.first[70] == 465);
        UT_ASSERT_TRUE(crco.first[71] == 466);
        UT_ASSERT_TRUE(crco.first[72] == 470);
        UT_ASSERT_TRUE(crco.first[73] == 471);
        UT_ASSERT_TRUE(crco.first[74] == 486);
        UT_ASSERT_TRUE(crco.first[75] == 497);

        crco = clauses_repr_clauses_of(cr, 19);
        UT_ASSERT_TRUE(crco.len == 54);
        UT_ASSERT_TRUE(crco.first[0] == 3);
        UT_ASSERT_TRUE(crco.first[1] == 4);
        UT_ASSERT_TRUE(crco.first[2] == 9);
        UT_ASSERT_TRUE(crco.first[3] == 13);
        UT_ASSERT_TRUE(crco.first[4] == 15);
        UT_ASSERT_TRUE(crco.first[5] == 32);
        UT_ASSERT_TRUE(crco.first[6] == 33);
        UT_ASSERT_TRUE(crco.first[7] == 39);
        UT_ASSERT_TRUE(crco.first[8] == 61);
        UT_ASSERT_TRUE(crco.first[9] == 70);
        UT_ASSERT_TRUE(crco.first[10] == 74);
        UT_ASSERT_TRUE(crco.first[11] == 79);
        UT_ASSERT_TRUE(crco.first[12] == 95);
        UT_ASSERT_TRUE(crco.first[13] == 98);
        UT_ASSERT_TRUE(crco.first[14] == 102);
        UT_ASSERT_TRUE(crco.first[15] == 129);
        UT_ASSERT_TRUE(crco.first[16] == 136);
        UT_ASSERT_TRUE(crco.first[17] == 137);
        UT_ASSERT_TRUE(crco.first[18] == 145);
        UT_ASSERT_TRUE(crco.first[19] == 184);
        UT_ASSERT_TRUE(crco.first[20] == 194);
        UT_ASSERT_TRUE(crco.first[21] == 197);
        UT_ASSERT_TRUE(crco.first[22] == 210);
        UT_ASSERT_TRUE(crco.first[23] == 215);
        UT_ASSERT_TRUE(crco.first[24] == 228);
        UT_ASSERT_TRUE(crco.first[25] == 286);
        UT_ASSERT_TRUE(crco.first[26] == 289);
        UT_ASSERT_TRUE(crco.first[27] == 291);
        UT_ASSERT_TRUE(crco.first[28] == 296);
        UT_ASSERT_TRUE(crco.first[29] == 300);
        UT_ASSERT_TRUE(crco.first[30] == 304);
        UT_ASSERT_TRUE(crco.first[31] == 306);
        UT_ASSERT_TRUE(crco.first[32] == 307);
        UT_ASSERT_TRUE(crco.first[33] == 316);
        UT_ASSERT_TRUE(crco.first[34] == 321);
        UT_ASSERT_TRUE(crco.first[35] == 328);
        UT_ASSERT_TRUE(crco.first[36] == 330);
        UT_ASSERT_TRUE(crco.first[37] == 343);
        UT_ASSERT_TRUE(crco.first[38] == 357);
        UT_ASSERT_TRUE(crco.first[39] == 358);
        UT_ASSERT_TRUE(crco.first[40] == 365);
        UT_ASSERT_TRUE(crco.first[41] == 378);
        UT_ASSERT_TRUE(crco.first[42] == 407);
        UT_ASSERT_TRUE(crco.first[43] == 435);
        UT_ASSERT_TRUE(crco.first[44] == 436);
        UT_ASSERT_TRUE(crco.first[45] == 442);
        UT_ASSERT_TRUE(crco.first[46] == 455);
        UT_ASSERT_TRUE(crco.first[47] == 460);
        UT_ASSERT_TRUE(crco.first[48] == 467);
        UT_ASSERT_TRUE(crco.first[49] == 469);
        UT_ASSERT_TRUE(crco.first[50] == 472);
        UT_ASSERT_TRUE(crco.first[51] == 477);
        UT_ASSERT_TRUE(crco.first[52] == 485);
        UT_ASSERT_TRUE(crco.first[53] == 496);

        crco = clauses_repr_clauses_of(cr, 20);
        UT_ASSERT_TRUE(crco.len == 58);
        UT_ASSERT_TRUE(crco.first[0] == 16);
        UT_ASSERT_TRUE(crco.first[1] == 23);
        UT_ASSERT_TRUE(crco.first[2] == 33);
        UT_ASSERT_TRUE(crco.first[3] == 58);
        UT_ASSERT_TRUE(crco.first[4] == 69);
        UT_ASSERT_TRUE(crco.first[5] == 75);
        UT_ASSERT_TRUE(crco.first[6] == 77);
        UT_ASSERT_TRUE(crco.first[7] == 84);
        UT_ASSERT_TRUE(crco.first[8] == 94);
        UT_ASSERT_TRUE(crco.first[9] == 96);
        UT_ASSERT_TRUE(crco.first[10] == 98);
        UT_ASSERT_TRUE(crco.first[11] == 141);
        UT_ASSERT_TRUE(crco.first[12] == 150);
        UT_ASSERT_TRUE(crco.first[13] == 171);
        UT_ASSERT_TRUE(crco.first[14] == 173);
        UT_ASSERT_TRUE(crco.first[15] == 193);
        UT_ASSERT_TRUE(crco.first[16] == 198);
        UT_ASSERT_TRUE(crco.first[17] == 200);
        UT_ASSERT_TRUE(crco.first[18] == 203);
        UT_ASSERT_TRUE(crco.first[19] == 207);
        UT_ASSERT_TRUE(crco.first[20] == 225);
        UT_ASSERT_TRUE(crco.first[21] == 227);
        UT_ASSERT_TRUE(crco.first[22] == 249);
        UT_ASSERT_TRUE(crco.first[23] == 257);
        UT_ASSERT_TRUE(crco.first[24] == 259);
        UT_ASSERT_TRUE(crco.first[25] == 261);
        UT_ASSERT_TRUE(crco.first[26] == 276);
        UT_ASSERT_TRUE(crco.first[27] == 285);
        UT_ASSERT_TRUE(crco.first[28] == 303);
        UT_ASSERT_TRUE(crco.first[29] == 313);
        UT_ASSERT_TRUE(crco.first[30] == 325);
        UT_ASSERT_TRUE(crco.first[31] == 332);
        UT_ASSERT_TRUE(crco.first[32] == 336);
        UT_ASSERT_TRUE(crco.first[33] == 338);
        UT_ASSERT_TRUE(crco.first[34] == 344);
        UT_ASSERT_TRUE(crco.first[35] == 349);
        UT_ASSERT_TRUE(crco.first[36] == 352);
        UT_ASSERT_TRUE(crco.first[37] == 357);
        UT_ASSERT_TRUE(crco.first[38] == 358);
        UT_ASSERT_TRUE(crco.first[39] == 359);
        UT_ASSERT_TRUE(crco.first[40] == 365);
        UT_ASSERT_TRUE(crco.first[41] == 381);
        UT_ASSERT_TRUE(crco.first[42] == 383);
        UT_ASSERT_TRUE(crco.first[43] == 397);
        UT_ASSERT_TRUE(crco.first[44] == 407);
        UT_ASSERT_TRUE(crco.first[45] == 408);
        UT_ASSERT_TRUE(crco.first[46] == 428);
        UT_ASSERT_TRUE(crco.first[47] == 434);
        UT_ASSERT_TRUE(crco.first[48] == 441);
        UT_ASSERT_TRUE(crco.first[49] == 444);
        UT_ASSERT_TRUE(crco.first[50] == 455);
        UT_ASSERT_TRUE(crco.first[51] == 461);
        UT_ASSERT_TRUE(crco.first[52] == 469);
        UT_ASSERT_TRUE(crco.first[53] == 474);
        UT_ASSERT_TRUE(crco.first[54] == 483);
        UT_ASSERT_TRUE(crco.first[55] == 486);
        UT_ASSERT_TRUE(crco.first[56] == 491);
        UT_ASSERT_TRUE(crco.first[57] == 493);

        crco = clauses_repr_clauses_of(cr, 21);
        UT_ASSERT_TRUE(crco.len == 71);
        UT_ASSERT_TRUE(crco.first[0] == 9);
        UT_ASSERT_TRUE(crco.first[1] == 33);
        UT_ASSERT_TRUE(crco.first[2] == 34);
        UT_ASSERT_TRUE(crco.first[3] == 37);
        UT_ASSERT_TRUE(crco.first[4] == 46);
        UT_ASSERT_TRUE(crco.first[5] == 50);
        UT_ASSERT_TRUE(crco.first[6] == 57);
        UT_ASSERT_TRUE(crco.first[7] == 59);
        UT_ASSERT_TRUE(crco.first[8] == 68);
        UT_ASSERT_TRUE(crco.first[9] == 88);
        UT_ASSERT_TRUE(crco.first[10] == 101);
        UT_ASSERT_TRUE(crco.first[11] == 111);
        UT_ASSERT_TRUE(crco.first[12] == 114);
        UT_ASSERT_TRUE(crco.first[13] == 115);
        UT_ASSERT_TRUE(crco.first[14] == 118);
        UT_ASSERT_TRUE(crco.first[15] == 125);
        UT_ASSERT_TRUE(crco.first[16] == 138);
        UT_ASSERT_TRUE(crco.first[17] == 146);
        UT_ASSERT_TRUE(crco.first[18] == 151);
        UT_ASSERT_TRUE(crco.first[19] == 152);
        UT_ASSERT_TRUE(crco.first[20] == 156);
        UT_ASSERT_TRUE(crco.first[21] == 168);
        UT_ASSERT_TRUE(crco.first[22] == 176);
        UT_ASSERT_TRUE(crco.first[23] == 189);
        UT_ASSERT_TRUE(crco.first[24] == 191);
        UT_ASSERT_TRUE(crco.first[25] == 195);
        UT_ASSERT_TRUE(crco.first[26] == 201);
        UT_ASSERT_TRUE(crco.first[27] == 202);
        UT_ASSERT_TRUE(crco.first[28] == 209);
        UT_ASSERT_TRUE(crco.first[29] == 211);
        UT_ASSERT_TRUE(crco.first[30] == 227);
        UT_ASSERT_TRUE(crco.first[31] == 242);
        UT_ASSERT_TRUE(crco.first[32] == 243);
        UT_ASSERT_TRUE(crco.first[33] == 254);
        UT_ASSERT_TRUE(crco.first[34] == 256);
        UT_ASSERT_TRUE(crco.first[35] == 267);
        UT_ASSERT_TRUE(crco.first[36] == 270);
        UT_ASSERT_TRUE(crco.first[37] == 275);
        UT_ASSERT_TRUE(crco.first[38] == 276);
        UT_ASSERT_TRUE(crco.first[39] == 279);
        UT_ASSERT_TRUE(crco.first[40] == 287);
        UT_ASSERT_TRUE(crco.first[41] == 293);
        UT_ASSERT_TRUE(crco.first[42] == 301);
        UT_ASSERT_TRUE(crco.first[43] == 303);
        UT_ASSERT_TRUE(crco.first[44] == 305);
        UT_ASSERT_TRUE(crco.first[45] == 306);
        UT_ASSERT_TRUE(crco.first[46] == 312);
        UT_ASSERT_TRUE(crco.first[47] == 323);
        UT_ASSERT_TRUE(crco.first[48] == 351);
        UT_ASSERT_TRUE(crco.first[49] == 360);
        UT_ASSERT_TRUE(crco.first[50] == 363);
        UT_ASSERT_TRUE(crco.first[51] == 370);
        UT_ASSERT_TRUE(crco.first[52] == 375);
        UT_ASSERT_TRUE(crco.first[53] == 378);
        UT_ASSERT_TRUE(crco.first[54] == 379);
        UT_ASSERT_TRUE(crco.first[55] == 380);
        UT_ASSERT_TRUE(crco.first[56] == 391);
        UT_ASSERT_TRUE(crco.first[57] == 392);
        UT_ASSERT_TRUE(crco.first[58] == 393);
        UT_ASSERT_TRUE(crco.first[59] == 398);
        UT_ASSERT_TRUE(crco.first[60] == 400);
        UT_ASSERT_TRUE(crco.first[61] == 404);
        UT_ASSERT_TRUE(crco.first[62] == 417);
        UT_ASSERT_TRUE(crco.first[63] == 418);
        UT_ASSERT_TRUE(crco.first[64] == 420);
        UT_ASSERT_TRUE(crco.first[65] == 427);
        UT_ASSERT_TRUE(crco.first[66] == 441);
        UT_ASSERT_TRUE(crco.first[67] == 449);
        UT_ASSERT_TRUE(crco.first[68] == 464);
        UT_ASSERT_TRUE(crco.first[69] == 480);
        UT_ASSERT_TRUE(crco.first[70] == 487);

        crco = clauses_repr_clauses_of(cr, 22);
        UT_ASSERT_TRUE(crco.len == 70);
        UT_ASSERT_TRUE(crco.first[0] == 5);
        UT_ASSERT_TRUE(crco.first[1] == 32);
        UT_ASSERT_TRUE(crco.first[2] == 34);
        UT_ASSERT_TRUE(crco.first[3] == 40);
        UT_ASSERT_TRUE(crco.first[4] == 52);
        UT_ASSERT_TRUE(crco.first[5] == 55);
        UT_ASSERT_TRUE(crco.first[6] == 63);
        UT_ASSERT_TRUE(crco.first[7] == 67);
        UT_ASSERT_TRUE(crco.first[8] == 70);
        UT_ASSERT_TRUE(crco.first[9] == 74);
        UT_ASSERT_TRUE(crco.first[10] == 87);
        UT_ASSERT_TRUE(crco.first[11] == 89);
        UT_ASSERT_TRUE(crco.first[12] == 91);
        UT_ASSERT_TRUE(crco.first[13] == 96);
        UT_ASSERT_TRUE(crco.first[14] == 99);
        UT_ASSERT_TRUE(crco.first[15] == 105);
        UT_ASSERT_TRUE(crco.first[16] == 107);
        UT_ASSERT_TRUE(crco.first[17] == 131);
        UT_ASSERT_TRUE(crco.first[18] == 144);
        UT_ASSERT_TRUE(crco.first[19] == 154);
        UT_ASSERT_TRUE(crco.first[20] == 160);
        UT_ASSERT_TRUE(crco.first[21] == 176);
        UT_ASSERT_TRUE(crco.first[22] == 183);
        UT_ASSERT_TRUE(crco.first[23] == 192);
        UT_ASSERT_TRUE(crco.first[24] == 197);
        UT_ASSERT_TRUE(crco.first[25] == 200);
        UT_ASSERT_TRUE(crco.first[26] == 206);
        UT_ASSERT_TRUE(crco.first[27] == 209);
        UT_ASSERT_TRUE(crco.first[28] == 217);
        UT_ASSERT_TRUE(crco.first[29] == 224);
        UT_ASSERT_TRUE(crco.first[30] == 231);
        UT_ASSERT_TRUE(crco.first[31] == 234);
        UT_ASSERT_TRUE(crco.first[32] == 262);
        UT_ASSERT_TRUE(crco.first[33] == 268);
        UT_ASSERT_TRUE(crco.first[34] == 273);
        UT_ASSERT_TRUE(crco.first[35] == 274);
        UT_ASSERT_TRUE(crco.first[36] == 285);
        UT_ASSERT_TRUE(crco.first[37] == 292);
        UT_ASSERT_TRUE(crco.first[38] == 294);
        UT_ASSERT_TRUE(crco.first[39] == 297);
        UT_ASSERT_TRUE(crco.first[40] == 303);
        UT_ASSERT_TRUE(crco.first[41] == 309);
        UT_ASSERT_TRUE(crco.first[42] == 314);
        UT_ASSERT_TRUE(crco.first[43] == 322);
        UT_ASSERT_TRUE(crco.first[44] == 328);
        UT_ASSERT_TRUE(crco.first[45] == 344);
        UT_ASSERT_TRUE(crco.first[46] == 347);
        UT_ASSERT_TRUE(crco.first[47] == 348);
        UT_ASSERT_TRUE(crco.first[48] == 354);
        UT_ASSERT_TRUE(crco.first[49] == 356);
        UT_ASSERT_TRUE(crco.first[50] == 357);
        UT_ASSERT_TRUE(crco.first[51] == 360);
        UT_ASSERT_TRUE(crco.first[52] == 366);
        UT_ASSERT_TRUE(crco.first[53] == 368);
        UT_ASSERT_TRUE(crco.first[54] == 375);
        UT_ASSERT_TRUE(crco.first[55] == 383);
        UT_ASSERT_TRUE(crco.first[56] == 388);
        UT_ASSERT_TRUE(crco.first[57] == 391);
        UT_ASSERT_TRUE(crco.first[58] == 396);
        UT_ASSERT_TRUE(crco.first[59] == 401);
        UT_ASSERT_TRUE(crco.first[60] == 406);
        UT_ASSERT_TRUE(crco.first[61] == 419);
        UT_ASSERT_TRUE(crco.first[62] == 443);
        UT_ASSERT_TRUE(crco.first[63] == 445);
        UT_ASSERT_TRUE(crco.first[64] == 454);
        UT_ASSERT_TRUE(crco.first[65] == 456);
        UT_ASSERT_TRUE(crco.first[66] == 457);
        UT_ASSERT_TRUE(crco.first[67] == 482);
        UT_ASSERT_TRUE(crco.first[68] == 494);
        UT_ASSERT_TRUE(crco.first[69] == 495);

        crco = clauses_repr_clauses_of(cr, 23);
        UT_ASSERT_TRUE(crco.len == 64);
        UT_ASSERT_TRUE(crco.first[0] == 1);
        UT_ASSERT_TRUE(crco.first[1] == 9);
        UT_ASSERT_TRUE(crco.first[2] == 22);
        UT_ASSERT_TRUE(crco.first[3] == 23);
        UT_ASSERT_TRUE(crco.first[4] == 26);
        UT_ASSERT_TRUE(crco.first[5] == 28);
        UT_ASSERT_TRUE(crco.first[6] == 29);
        UT_ASSERT_TRUE(crco.first[7] == 30);
        UT_ASSERT_TRUE(crco.first[8] == 37);
        UT_ASSERT_TRUE(crco.first[9] == 45);
        UT_ASSERT_TRUE(crco.first[10] == 48);
        UT_ASSERT_TRUE(crco.first[11] == 61);
        UT_ASSERT_TRUE(crco.first[12] == 66);
        UT_ASSERT_TRUE(crco.first[13] == 75);
        UT_ASSERT_TRUE(crco.first[14] == 85);
        UT_ASSERT_TRUE(crco.first[15] == 117);
        UT_ASSERT_TRUE(crco.first[16] == 146);
        UT_ASSERT_TRUE(crco.first[17] == 148);
        UT_ASSERT_TRUE(crco.first[18] == 157);
        UT_ASSERT_TRUE(crco.first[19] == 160);
        UT_ASSERT_TRUE(crco.first[20] == 169);
        UT_ASSERT_TRUE(crco.first[21] == 171);
        UT_ASSERT_TRUE(crco.first[22] == 183);
        UT_ASSERT_TRUE(crco.first[23] == 202);
        UT_ASSERT_TRUE(crco.first[24] == 221);
        UT_ASSERT_TRUE(crco.first[25] == 238);
        UT_ASSERT_TRUE(crco.first[26] == 239);
        UT_ASSERT_TRUE(crco.first[27] == 241);
        UT_ASSERT_TRUE(crco.first[28] == 246);
        UT_ASSERT_TRUE(crco.first[29] == 247);
        UT_ASSERT_TRUE(crco.first[30] == 253);
        UT_ASSERT_TRUE(crco.first[31] == 258);
        UT_ASSERT_TRUE(crco.first[32] == 279);
        UT_ASSERT_TRUE(crco.first[33] == 280);
        UT_ASSERT_TRUE(crco.first[34] == 281);
        UT_ASSERT_TRUE(crco.first[35] == 282);
        UT_ASSERT_TRUE(crco.first[36] == 288);
        UT_ASSERT_TRUE(crco.first[37] == 300);
        UT_ASSERT_TRUE(crco.first[38] == 301);
        UT_ASSERT_TRUE(crco.first[39] == 313);
        UT_ASSERT_TRUE(crco.first[40] == 337);
        UT_ASSERT_TRUE(crco.first[41] == 341);
        UT_ASSERT_TRUE(crco.first[42] == 342);
        UT_ASSERT_TRUE(crco.first[43] == 348);
        UT_ASSERT_TRUE(crco.first[44] == 368);
        UT_ASSERT_TRUE(crco.first[45] == 369);
        UT_ASSERT_TRUE(crco.first[46] == 382);
        UT_ASSERT_TRUE(crco.first[47] == 387);
        UT_ASSERT_TRUE(crco.first[48] == 388);
        UT_ASSERT_TRUE(crco.first[49] == 399);
        UT_ASSERT_TRUE(crco.first[50] == 403);
        UT_ASSERT_TRUE(crco.first[51] == 425);
        UT_ASSERT_TRUE(crco.first[52] == 429);
        UT_ASSERT_TRUE(crco.first[53] == 461);
        UT_ASSERT_TRUE(crco.first[54] == 465);
        UT_ASSERT_TRUE(crco.first[55] == 471);
        UT_ASSERT_TRUE(crco.first[56] == 473);
        UT_ASSERT_TRUE(crco.first[57] == 479);
        UT_ASSERT_TRUE(crco.first[58] == 483);
        UT_ASSERT_TRUE(crco.first[59] == 488);
        UT_ASSERT_TRUE(crco.first[60] == 492);
        UT_ASSERT_TRUE(crco.first[61] == 495);
        UT_ASSERT_TRUE(crco.first[62] == 496);
        UT_ASSERT_TRUE(crco.first[63] == 498);

        crco = clauses_repr_clauses_of(cr, 24);
        UT_ASSERT_TRUE(crco.len == 65);
        UT_ASSERT_TRUE(crco.first[0] == 3);
        UT_ASSERT_TRUE(crco.first[1] == 5);
        UT_ASSERT_TRUE(crco.first[2] == 12);
        UT_ASSERT_TRUE(crco.first[3] == 43);
        UT_ASSERT_TRUE(crco.first[4] == 55);
        UT_ASSERT_TRUE(crco.first[5] == 60);
        UT_ASSERT_TRUE(crco.first[6] == 76);
        UT_ASSERT_TRUE(crco.first[7] == 82);
        UT_ASSERT_TRUE(crco.first[8] == 101);
        UT_ASSERT_TRUE(crco.first[9] == 105);
        UT_ASSERT_TRUE(crco.first[10] == 116);
        UT_ASSERT_TRUE(crco.first[11] == 126);
        UT_ASSERT_TRUE(crco.first[12] == 127);
        UT_ASSERT_TRUE(crco.first[13] == 132);
        UT_ASSERT_TRUE(crco.first[14] == 134);
        UT_ASSERT_TRUE(crco.first[15] == 138);
        UT_ASSERT_TRUE(crco.first[16] == 145);
        UT_ASSERT_TRUE(crco.first[17] == 161);
        UT_ASSERT_TRUE(crco.first[18] == 167);
        UT_ASSERT_TRUE(crco.first[19] == 171);
        UT_ASSERT_TRUE(crco.first[20] == 172);
        UT_ASSERT_TRUE(crco.first[21] == 174);
        UT_ASSERT_TRUE(crco.first[22] == 199);
        UT_ASSERT_TRUE(crco.first[23] == 208);
        UT_ASSERT_TRUE(crco.first[24] == 209);
        UT_ASSERT_TRUE(crco.first[25] == 224);
        UT_ASSERT_TRUE(crco.first[26] == 226);
        UT_ASSERT_TRUE(crco.first[27] == 246);
        UT_ASSERT_TRUE(crco.first[28] == 270);
        UT_ASSERT_TRUE(crco.first[29] == 271);
        UT_ASSERT_TRUE(crco.first[30] == 292);
        UT_ASSERT_TRUE(crco.first[31] == 304);
        UT_ASSERT_TRUE(crco.first[32] == 313);
        UT_ASSERT_TRUE(crco.first[33] == 323);
        UT_ASSERT_TRUE(crco.first[34] == 327);
        UT_ASSERT_TRUE(crco.first[35] == 339);
        UT_ASSERT_TRUE(crco.first[36] == 348);
        UT_ASSERT_TRUE(crco.first[37] == 349);
        UT_ASSERT_TRUE(crco.first[38] == 353);
        UT_ASSERT_TRUE(crco.first[39] == 363);
        UT_ASSERT_TRUE(crco.first[40] == 370);
        UT_ASSERT_TRUE(crco.first[41] == 371);
        UT_ASSERT_TRUE(crco.first[42] == 375);
        UT_ASSERT_TRUE(crco.first[43] == 381);
        UT_ASSERT_TRUE(crco.first[44] == 389);
        UT_ASSERT_TRUE(crco.first[45] == 402);
        UT_ASSERT_TRUE(crco.first[46] == 405);
        UT_ASSERT_TRUE(crco.first[47] == 408);
        UT_ASSERT_TRUE(crco.first[48] == 420);
        UT_ASSERT_TRUE(crco.first[49] == 426);
        UT_ASSERT_TRUE(crco.first[50] == 430);
        UT_ASSERT_TRUE(crco.first[51] == 437);
        UT_ASSERT_TRUE(crco.first[52] == 442);
        UT_ASSERT_TRUE(crco.first[53] == 445);
        UT_ASSERT_TRUE(crco.first[54] == 448);
        UT_ASSERT_TRUE(crco.first[55] == 452);
        UT_ASSERT_TRUE(crco.first[56] == 453);
        UT_ASSERT_TRUE(crco.first[57] == 458);
        UT_ASSERT_TRUE(crco.first[58] == 462);
        UT_ASSERT_TRUE(crco.first[59] == 468);
        UT_ASSERT_TRUE(crco.first[60] == 475);
        UT_ASSERT_TRUE(crco.first[61] == 480);
        UT_ASSERT_TRUE(crco.first[62] == 484);
        UT_ASSERT_TRUE(crco.first[63] == 490);
        UT_ASSERT_TRUE(crco.first[64] == 498);

        crco = clauses_repr_clauses_of(cr, 25);
        UT_ASSERT_TRUE(crco.len == 54);
        UT_ASSERT_TRUE(crco.first[0] == 4);
        UT_ASSERT_TRUE(crco.first[1] == 7);
        UT_ASSERT_TRUE(crco.first[2] == 12);
        UT_ASSERT_TRUE(crco.first[3] == 14);
        UT_ASSERT_TRUE(crco.first[4] == 15);
        UT_ASSERT_TRUE(crco.first[5] == 20);
        UT_ASSERT_TRUE(crco.first[6] == 41);
        UT_ASSERT_TRUE(crco.first[7] == 56);
        UT_ASSERT_TRUE(crco.first[8] == 58);
        UT_ASSERT_TRUE(crco.first[9] == 62);
        UT_ASSERT_TRUE(crco.first[10] == 64);
        UT_ASSERT_TRUE(crco.first[11] == 97);
        UT_ASSERT_TRUE(crco.first[12] == 100);
        UT_ASSERT_TRUE(crco.first[13] == 109);
        UT_ASSERT_TRUE(crco.first[14] == 114);
        UT_ASSERT_TRUE(crco.first[15] == 118);
        UT_ASSERT_TRUE(crco.first[16] == 119);
        UT_ASSERT_TRUE(crco.first[17] == 137);
        UT_ASSERT_TRUE(crco.first[18] == 150);
        UT_ASSERT_TRUE(crco.first[19] == 188);
        UT_ASSERT_TRUE(crco.first[20] == 204);
        UT_ASSERT_TRUE(crco.first[21] == 210);
        UT_ASSERT_TRUE(crco.first[22] == 213);
        UT_ASSERT_TRUE(crco.first[23] == 233);
        UT_ASSERT_TRUE(crco.first[24] == 237);
        UT_ASSERT_TRUE(crco.first[25] == 262);
        UT_ASSERT_TRUE(crco.first[26] == 264);
        UT_ASSERT_TRUE(crco.first[27] == 275);
        UT_ASSERT_TRUE(crco.first[28] == 284);
        UT_ASSERT_TRUE(crco.first[29] == 292);
        UT_ASSERT_TRUE(crco.first[30] == 314);
        UT_ASSERT_TRUE(crco.first[31] == 323);
        UT_ASSERT_TRUE(crco.first[32] == 327);
        UT_ASSERT_TRUE(crco.first[33] == 344);
        UT_ASSERT_TRUE(crco.first[34] == 347);
        UT_ASSERT_TRUE(crco.first[35] == 351);
        UT_ASSERT_TRUE(crco.first[36] == 355);
        UT_ASSERT_TRUE(crco.first[37] == 361);
        UT_ASSERT_TRUE(crco.first[38] == 364);
        UT_ASSERT_TRUE(crco.first[39] == 379);
        UT_ASSERT_TRUE(crco.first[40] == 389);
        UT_ASSERT_TRUE(crco.first[41] == 398);
        UT_ASSERT_TRUE(crco.first[42] == 409);
        UT_ASSERT_TRUE(crco.first[43] == 428);
        UT_ASSERT_TRUE(crco.first[44] == 437);
        UT_ASSERT_TRUE(crco.first[45] == 444);
        UT_ASSERT_TRUE(crco.first[46] == 446);
        UT_ASSERT_TRUE(crco.first[47] == 447);
        UT_ASSERT_TRUE(crco.first[48] == 448);
        UT_ASSERT_TRUE(crco.first[49] == 456);
        UT_ASSERT_TRUE(crco.first[50] == 460);
        UT_ASSERT_TRUE(crco.first[51] == 467);
        UT_ASSERT_TRUE(crco.first[52] == 481);
        UT_ASSERT_TRUE(crco.first[53] == 487);
    }

    free_clauses_repr(cr);
    return 0;
}

UT_TEST(ex4) {
    struct new_clauses_repr_from_file ret = new_clauses_repr_from_file("test/ex4.in");
    UT_ASSERT_TRUE(ret.success);
    struct clauses_repr *cr = ret.clauses_repr;
    UT_ASSERT_TRUE(clauses_repr_num_vars(cr) == 30);
    UT_ASSERT_TRUE(clauses_repr_num_clauses(cr) == 500);

    {
        struct clauses_repr_clause crc;
        crc = clauses_repr_clause(cr, 0);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == -21);

        crc = clauses_repr_clause(cr, 1);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == -29);

        crc = clauses_repr_clause(cr, 2);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 28);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 3);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -29);

        crc = clauses_repr_clause(cr, 4);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 5);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == -9);

        crc = clauses_repr_clause(cr, 6);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 7);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == -20);

        crc = clauses_repr_clause(cr, 8);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 27);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 9);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 30);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == -1);

        crc = clauses_repr_clause(cr, 10);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 28);

        crc = clauses_repr_clause(cr, 11);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == -13);

        crc = clauses_repr_clause(cr, 12);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == -4);

        crc = clauses_repr_clause(cr, 13);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -27);

        crc = clauses_repr_clause(cr, 14);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 21);

        crc = clauses_repr_clause(cr, 15);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -29);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == 27);

        crc = clauses_repr_clause(cr, 16);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 17);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 5);

        crc = clauses_repr_clause(cr, 18);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == -16);

        crc = clauses_repr_clause(cr, 19);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == 21);

        crc = clauses_repr_clause(cr, 20);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == -25);

        crc = clauses_repr_clause(cr, 21);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 27);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 22);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == 13);

        crc = clauses_repr_clause(cr, 23);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == -29);
        UT_ASSERT_TRUE(crc.first[2] == -27);

        crc = clauses_repr_clause(cr, 24);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 25);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 26);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == -28);

        crc = clauses_repr_clause(cr, 27);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 28);

        crc = clauses_repr_clause(cr, 28);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == 24);

        crc = clauses_repr_clause(cr, 29);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == -29);

        crc = clauses_repr_clause(cr, 30);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 31);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == 27);

        crc = clauses_repr_clause(cr, 32);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 17);

        crc = clauses_repr_clause(cr, 33);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == -1);

        crc = clauses_repr_clause(cr, 34);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 30);

        crc = clauses_repr_clause(cr, 35);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == -4);

        crc = clauses_repr_clause(cr, 36);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == -6);

        crc = clauses_repr_clause(cr, 37);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == -7);

        crc = clauses_repr_clause(cr, 38);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -18);

        crc = clauses_repr_clause(cr, 39);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 40);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == -4);

        crc = clauses_repr_clause(cr, 41);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 42);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == -6);

        crc = clauses_repr_clause(cr, 43);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 44);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -28);
        UT_ASSERT_TRUE(crc.first[1] == -30);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 45);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -14);

        crc = clauses_repr_clause(cr, 46);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 14);

        crc = clauses_repr_clause(cr, 47);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == 27);

        crc = clauses_repr_clause(cr, 48);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 27);
        UT_ASSERT_TRUE(crc.first[2] == 30);

        crc = clauses_repr_clause(cr, 49);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -21);

        crc = clauses_repr_clause(cr, 50);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 51);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == 18);

        crc = clauses_repr_clause(cr, 52);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 30);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 53);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == -21);

        crc = clauses_repr_clause(cr, 54);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 55);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 56);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == -17);

        crc = clauses_repr_clause(cr, 57);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == -5);

        crc = clauses_repr_clause(cr, 58);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 15);

        crc = clauses_repr_clause(cr, 59);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 21);

        crc = clauses_repr_clause(cr, 60);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 61);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == -30);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 62);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == 30);

        crc = clauses_repr_clause(cr, 63);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == -4);

        crc = clauses_repr_clause(cr, 64);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == -22);

        crc = clauses_repr_clause(cr, 65);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == -15);

        crc = clauses_repr_clause(cr, 66);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -28);
        UT_ASSERT_TRUE(crc.first[1] == -25);

        crc = clauses_repr_clause(cr, 67);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 29);

        crc = clauses_repr_clause(cr, 68);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == -20);

        crc = clauses_repr_clause(cr, 69);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 10);

        crc = clauses_repr_clause(cr, 70);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == -28);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 71);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == -30);

        crc = clauses_repr_clause(cr, 72);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 73);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 19);

        crc = clauses_repr_clause(cr, 74);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 14);

        crc = clauses_repr_clause(cr, 75);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 28);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 76);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 77);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == 4);

        crc = clauses_repr_clause(cr, 78);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 27);

        crc = clauses_repr_clause(cr, 79);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == -2);

        crc = clauses_repr_clause(cr, 80);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 81);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == -5);

        crc = clauses_repr_clause(cr, 82);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 83);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 84);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == 21);

        crc = clauses_repr_clause(cr, 85);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == -12);

        crc = clauses_repr_clause(cr, 86);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 87);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == 26);

        crc = clauses_repr_clause(cr, 88);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 15);

        crc = clauses_repr_clause(cr, 89);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 17);

        crc = clauses_repr_clause(cr, 90);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -28);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 91);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == 10);

        crc = clauses_repr_clause(cr, 92);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == -4);

        crc = clauses_repr_clause(cr, 93);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 94);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == -29);

        crc = clauses_repr_clause(cr, 95);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 18);

        crc = clauses_repr_clause(cr, 96);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == -8);

        crc = clauses_repr_clause(cr, 97);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == -2);

        crc = clauses_repr_clause(cr, 98);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == 8);

        crc = clauses_repr_clause(cr, 99);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 4);

        crc = clauses_repr_clause(cr, 100);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 101);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 102);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 103);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == -11);

        crc = clauses_repr_clause(cr, 104);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == 3);

        crc = clauses_repr_clause(cr, 105);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -26);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == 10);

        crc = clauses_repr_clause(cr, 106);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == -23);

        crc = clauses_repr_clause(cr, 107);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 108);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -30);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 109);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == -24);

        crc = clauses_repr_clause(cr, 110);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 111);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == -11);

        crc = clauses_repr_clause(cr, 112);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 25);

        crc = clauses_repr_clause(cr, 113);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -30);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 114);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 115);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == -23);

        crc = clauses_repr_clause(cr, 116);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 117);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 13);

        crc = clauses_repr_clause(cr, 118);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 119);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == 6);

        crc = clauses_repr_clause(cr, 120);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 121);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -29);
        UT_ASSERT_TRUE(crc.first[1] == 6);

        crc = clauses_repr_clause(cr, 122);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == -10);

        crc = clauses_repr_clause(cr, 123);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == -29);

        crc = clauses_repr_clause(cr, 124);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == -26);

        crc = clauses_repr_clause(cr, 125);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -8);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 126);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == 4);

        crc = clauses_repr_clause(cr, 127);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 128);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 129);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == 29);

        crc = clauses_repr_clause(cr, 130);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 29);

        crc = clauses_repr_clause(cr, 131);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == 18);

        crc = clauses_repr_clause(cr, 132);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 28);
        UT_ASSERT_TRUE(crc.first[1] == -10);

        crc = clauses_repr_clause(cr, 133);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == 27);

        crc = clauses_repr_clause(cr, 134);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 135);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 14);

        crc = clauses_repr_clause(cr, 136);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 137);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == -16);

        crc = clauses_repr_clause(cr, 138);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == 25);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 139);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == -11);

        crc = clauses_repr_clause(cr, 140);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == -30);

        crc = clauses_repr_clause(cr, 141);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 22);

        crc = clauses_repr_clause(cr, 142);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == -18);

        crc = clauses_repr_clause(cr, 143);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 144);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 30);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 145);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == 1);

        crc = clauses_repr_clause(cr, 146);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == -30);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 147);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 148);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 149);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 150);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 25);

        crc = clauses_repr_clause(cr, 151);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == 10);

        crc = clauses_repr_clause(cr, 152);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 28);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 153);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 154);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 23);

        crc = clauses_repr_clause(cr, 155);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 156);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 157);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == -27);

        crc = clauses_repr_clause(cr, 158);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 159);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -2);

        crc = clauses_repr_clause(cr, 160);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == -14);

        crc = clauses_repr_clause(cr, 161);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == 1);

        crc = clauses_repr_clause(cr, 162);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == -9);

        crc = clauses_repr_clause(cr, 163);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == -12);

        crc = clauses_repr_clause(cr, 164);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == -15);

        crc = clauses_repr_clause(cr, 165);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 166);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 25);

        crc = clauses_repr_clause(cr, 167);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -7);

        crc = clauses_repr_clause(cr, 168);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 169);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 170);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == 18);

        crc = clauses_repr_clause(cr, 171);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == 28);

        crc = clauses_repr_clause(cr, 172);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 173);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 174);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == 24);

        crc = clauses_repr_clause(cr, 175);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == 13);

        crc = clauses_repr_clause(cr, 176);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 177);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == 8);

        crc = clauses_repr_clause(cr, 178);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == -11);

        crc = clauses_repr_clause(cr, 179);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 30);

        crc = clauses_repr_clause(cr, 180);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 19);

        crc = clauses_repr_clause(cr, 181);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -26);
        UT_ASSERT_TRUE(crc.first[1] == -18);

        crc = clauses_repr_clause(cr, 182);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -19);

        crc = clauses_repr_clause(cr, 183);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == -9);

        crc = clauses_repr_clause(cr, 184);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == -4);

        crc = clauses_repr_clause(cr, 185);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == 26);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 186);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == -25);

        crc = clauses_repr_clause(cr, 187);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == -8);

        crc = clauses_repr_clause(cr, 188);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == -9);

        crc = clauses_repr_clause(cr, 189);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 12);

        crc = clauses_repr_clause(cr, 190);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 191);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == 15);

        crc = clauses_repr_clause(cr, 192);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == -4);

        crc = clauses_repr_clause(cr, 193);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == 8);

        crc = clauses_repr_clause(cr, 194);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == 23);

        crc = clauses_repr_clause(cr, 195);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == -2);

        crc = clauses_repr_clause(cr, 196);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == -21);

        crc = clauses_repr_clause(cr, 197);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == -5);

        crc = clauses_repr_clause(cr, 198);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == 22);

        crc = clauses_repr_clause(cr, 199);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -15);

        crc = clauses_repr_clause(cr, 200);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 201);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == 16);

        crc = clauses_repr_clause(cr, 202);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == -8);
        UT_ASSERT_TRUE(crc.first[2] == 27);

        crc = clauses_repr_clause(cr, 203);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -28);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 204);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 205);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 23);

        crc = clauses_repr_clause(cr, 206);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == 16);

        crc = clauses_repr_clause(cr, 207);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == -30);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 208);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == 10);

        crc = clauses_repr_clause(cr, 209);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 210);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == -8);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 211);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 28);
        UT_ASSERT_TRUE(crc.first[1] == 21);

        crc = clauses_repr_clause(cr, 212);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == -14);

        crc = clauses_repr_clause(cr, 213);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == 25);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 214);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -27);

        crc = clauses_repr_clause(cr, 215);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 216);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -29);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 217);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -15);

        crc = clauses_repr_clause(cr, 218);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == 26);

        crc = clauses_repr_clause(cr, 219);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == -1);

        crc = clauses_repr_clause(cr, 220);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == -19);

        crc = clauses_repr_clause(cr, 221);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 21);

        crc = clauses_repr_clause(cr, 222);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == -2);

        crc = clauses_repr_clause(cr, 223);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == 2);

        crc = clauses_repr_clause(cr, 224);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == -23);

        crc = clauses_repr_clause(cr, 225);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 226);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == 11);

        crc = clauses_repr_clause(cr, 227);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 228);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == 19);

        crc = clauses_repr_clause(cr, 229);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 27);

        crc = clauses_repr_clause(cr, 230);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 231);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == 4);

        crc = clauses_repr_clause(cr, 232);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 233);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == 25);

        crc = clauses_repr_clause(cr, 234);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == -4);

        crc = clauses_repr_clause(cr, 235);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == 13);

        crc = clauses_repr_clause(cr, 236);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 237);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 30);
        UT_ASSERT_TRUE(crc.first[1] == 29);

        crc = clauses_repr_clause(cr, 238);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == -19);

        crc = clauses_repr_clause(cr, 239);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == -29);

        crc = clauses_repr_clause(cr, 240);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 241);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == -23);

        crc = clauses_repr_clause(cr, 242);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == -1);

        crc = clauses_repr_clause(cr, 243);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == 5);

        crc = clauses_repr_clause(cr, 244);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -26);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == -27);

        crc = clauses_repr_clause(cr, 245);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 246);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -3);

        crc = clauses_repr_clause(cr, 247);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == 29);

        crc = clauses_repr_clause(cr, 248);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 249);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 22);

        crc = clauses_repr_clause(cr, 250);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 251);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 252);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 253);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == 26);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 254);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == 12);

        crc = clauses_repr_clause(cr, 255);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -17);

        crc = clauses_repr_clause(cr, 256);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == -8);

        crc = clauses_repr_clause(cr, 257);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -17);

        crc = clauses_repr_clause(cr, 258);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 28);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 259);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -29);
        UT_ASSERT_TRUE(crc.first[1] == 12);

        crc = clauses_repr_clause(cr, 260);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -12);

        crc = clauses_repr_clause(cr, 261);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == 8);

        crc = clauses_repr_clause(cr, 262);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 263);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 27);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 264);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == 14);

        crc = clauses_repr_clause(cr, 265);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == 29);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 266);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == -19);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 267);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == -13);

        crc = clauses_repr_clause(cr, 268);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == 28);

        crc = clauses_repr_clause(cr, 269);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == -13);

        crc = clauses_repr_clause(cr, 270);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -26);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 271);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == 2);

        crc = clauses_repr_clause(cr, 272);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -7);

        crc = clauses_repr_clause(cr, 273);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 17);

        crc = clauses_repr_clause(cr, 274);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 11);

        crc = clauses_repr_clause(cr, 275);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == 7);

        crc = clauses_repr_clause(cr, 276);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == 27);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 277);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -29);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 278);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -4);

        crc = clauses_repr_clause(cr, 279);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 280);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == -2);

        crc = clauses_repr_clause(cr, 281);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 28);

        crc = clauses_repr_clause(cr, 282);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == 1);

        crc = clauses_repr_clause(cr, 283);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 284);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == -4);

        crc = clauses_repr_clause(cr, 285);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 286);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 27);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 287);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 28);
        UT_ASSERT_TRUE(crc.first[1] == 14);

        crc = clauses_repr_clause(cr, 288);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == 28);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 289);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == 29);

        crc = clauses_repr_clause(cr, 290);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 291);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == 29);
        UT_ASSERT_TRUE(crc.first[2] == -19);

        crc = clauses_repr_clause(cr, 292);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 28);

        crc = clauses_repr_clause(cr, 293);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -22);

        crc = clauses_repr_clause(cr, 294);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -4);

        crc = clauses_repr_clause(cr, 295);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 296);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 297);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == 28);

        crc = clauses_repr_clause(cr, 298);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -23);

        crc = clauses_repr_clause(cr, 299);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 300);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == 27);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 301);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == -26);

        crc = clauses_repr_clause(cr, 302);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == -27);

        crc = clauses_repr_clause(cr, 303);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == 14);

        crc = clauses_repr_clause(cr, 304);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == -29);

        crc = clauses_repr_clause(cr, 305);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 2);

        crc = clauses_repr_clause(cr, 306);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == -29);

        crc = clauses_repr_clause(cr, 307);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == -22);

        crc = clauses_repr_clause(cr, 308);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 30);
        UT_ASSERT_TRUE(crc.first[1] == 19);

        crc = clauses_repr_clause(cr, 309);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == 26);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 310);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 311);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -1);

        crc = clauses_repr_clause(cr, 312);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 19);

        crc = clauses_repr_clause(cr, 313);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -16);

        crc = clauses_repr_clause(cr, 314);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == 15);

        crc = clauses_repr_clause(cr, 315);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 316);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -17);

        crc = clauses_repr_clause(cr, 317);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == -8);

        crc = clauses_repr_clause(cr, 318);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 26);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 319);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 21);

        crc = clauses_repr_clause(cr, 320);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 321);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 5);

        crc = clauses_repr_clause(cr, 322);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 323);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -29);

        crc = clauses_repr_clause(cr, 324);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 325);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 326);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 5);

        crc = clauses_repr_clause(cr, 327);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -29);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 328);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 329);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == 3);

        crc = clauses_repr_clause(cr, 330);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == 6);

        crc = clauses_repr_clause(cr, 331);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == -27);

        crc = clauses_repr_clause(cr, 332);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == -2);

        crc = clauses_repr_clause(cr, 333);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -13);

        crc = clauses_repr_clause(cr, 334);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == -9);

        crc = clauses_repr_clause(cr, 335);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -15);

        crc = clauses_repr_clause(cr, 336);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == 10);

        crc = clauses_repr_clause(cr, 337);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 28);
        UT_ASSERT_TRUE(crc.first[1] == 17);

        crc = clauses_repr_clause(cr, 338);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 339);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 340);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == -27);

        crc = clauses_repr_clause(cr, 341);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == -19);

        crc = clauses_repr_clause(cr, 342);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == -29);

        crc = clauses_repr_clause(cr, 343);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 344);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 345);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == -16);

        crc = clauses_repr_clause(cr, 346);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -30);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 347);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == -14);

        crc = clauses_repr_clause(cr, 348);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == -18);

        crc = clauses_repr_clause(cr, 349);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == -20);

        crc = clauses_repr_clause(cr, 350);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 351);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == -19);

        crc = clauses_repr_clause(cr, 352);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == 23);

        crc = clauses_repr_clause(cr, 353);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -30);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 354);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 355);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == -2);

        crc = clauses_repr_clause(cr, 356);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 18);

        crc = clauses_repr_clause(cr, 357);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 358);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -15);

        crc = clauses_repr_clause(cr, 359);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 360);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == 26);

        crc = clauses_repr_clause(cr, 361);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == 29);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 362);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == -19);

        crc = clauses_repr_clause(cr, 363);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == 29);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 364);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == -9);

        crc = clauses_repr_clause(cr, 365);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == 30);

        crc = clauses_repr_clause(cr, 366);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == -18);

        crc = clauses_repr_clause(cr, 367);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == 10);

        crc = clauses_repr_clause(cr, 368);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 369);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -28);

        crc = clauses_repr_clause(cr, 370);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 371);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 372);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == 14);

        crc = clauses_repr_clause(cr, 373);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 374);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 375);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 376);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == 20);

        crc = clauses_repr_clause(cr, 377);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -15);

        crc = clauses_repr_clause(cr, 378);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 379);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 380);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == -24);

        crc = clauses_repr_clause(cr, 381);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == 28);

        crc = clauses_repr_clause(cr, 382);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == -29);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 383);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -26);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == 27);

        crc = clauses_repr_clause(cr, 384);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 385);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == -29);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 386);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -18);

        crc = clauses_repr_clause(cr, 387);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 388);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == -8);
        UT_ASSERT_TRUE(crc.first[2] == 27);

        crc = clauses_repr_clause(cr, 389);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == -21);

        crc = clauses_repr_clause(cr, 390);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -28);

        crc = clauses_repr_clause(cr, 391);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 392);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -26);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == 29);

        crc = clauses_repr_clause(cr, 393);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == -20);

        crc = clauses_repr_clause(cr, 394);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 26);
        UT_ASSERT_TRUE(crc.first[2] == 10);

        crc = clauses_repr_clause(cr, 395);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 30);

        crc = clauses_repr_clause(cr, 396);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == 10);

        crc = clauses_repr_clause(cr, 397);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 29);

        crc = clauses_repr_clause(cr, 398);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == -5);

        crc = clauses_repr_clause(cr, 399);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == 22);

        crc = clauses_repr_clause(cr, 400);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 401);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 402);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == 14);

        crc = clauses_repr_clause(cr, 403);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 29);

        crc = clauses_repr_clause(cr, 404);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == 17);

        crc = clauses_repr_clause(cr, 405);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -14);

        crc = clauses_repr_clause(cr, 406);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 26);

        crc = clauses_repr_clause(cr, 407);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 408);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 409);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == 24);

        crc = clauses_repr_clause(cr, 410);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == -28);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 411);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 412);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == 1);

        crc = clauses_repr_clause(cr, 413);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == -21);

        crc = clauses_repr_clause(cr, 414);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 415);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -30);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 416);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == 29);

        crc = clauses_repr_clause(cr, 417);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 418);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 419);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 420);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 421);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == 21);

        crc = clauses_repr_clause(cr, 422);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == -24);

        crc = clauses_repr_clause(cr, 423);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 424);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 425);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 426);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == -29);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 427);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -22);

        crc = clauses_repr_clause(cr, 428);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 25);

        crc = clauses_repr_clause(cr, 429);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 24);

        crc = clauses_repr_clause(cr, 430);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == 14);

        crc = clauses_repr_clause(cr, 431);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -17);

        crc = clauses_repr_clause(cr, 432);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -6);

        crc = clauses_repr_clause(cr, 433);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == -21);

        crc = clauses_repr_clause(cr, 434);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -30);

        crc = clauses_repr_clause(cr, 435);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == -30);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 436);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 28);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 437);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == 28);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 438);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 439);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == -1);

        crc = clauses_repr_clause(cr, 440);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 441);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == -2);

        crc = clauses_repr_clause(cr, 442);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == -30);

        crc = clauses_repr_clause(cr, 443);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == -21);

        crc = clauses_repr_clause(cr, 444);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 445);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == 10);

        crc = clauses_repr_clause(cr, 446);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 447);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == -29);

        crc = clauses_repr_clause(cr, 448);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 449);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 28);

        crc = clauses_repr_clause(cr, 450);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -8);

        crc = clauses_repr_clause(cr, 451);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -30);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 452);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == 6);

        crc = clauses_repr_clause(cr, 453);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 30);

        crc = clauses_repr_clause(cr, 454);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 14);

        crc = clauses_repr_clause(cr, 455);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 456);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == -26);

        crc = clauses_repr_clause(cr, 457);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == 19);

        crc = clauses_repr_clause(cr, 458);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 459);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -10);

        crc = clauses_repr_clause(cr, 460);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 10);

        crc = clauses_repr_clause(cr, 461);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == -25);

        crc = clauses_repr_clause(cr, 462);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 463);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 464);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == 29);

        crc = clauses_repr_clause(cr, 465);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == 8);

        crc = clauses_repr_clause(cr, 466);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 1);

        crc = clauses_repr_clause(cr, 467);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 24);

        crc = clauses_repr_clause(cr, 468);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 469);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 470);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -29);

        crc = clauses_repr_clause(cr, 471);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == -1);

        crc = clauses_repr_clause(cr, 472);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == -22);

        crc = clauses_repr_clause(cr, 473);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 474);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 475);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == -30);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 476);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 477);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 30);

        crc = clauses_repr_clause(cr, 478);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -14);

        crc = clauses_repr_clause(cr, 479);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 480);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == 13);

        crc = clauses_repr_clause(cr, 481);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 27);

        crc = clauses_repr_clause(cr, 482);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 483);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == 20);

        crc = clauses_repr_clause(cr, 484);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 5);

        crc = clauses_repr_clause(cr, 485);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 486);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 487);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == -17);

        crc = clauses_repr_clause(cr, 488);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 489);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 490);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == 16);

        crc = clauses_repr_clause(cr, 491);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -29);
        UT_ASSERT_TRUE(crc.first[1] == -3);

        crc = clauses_repr_clause(cr, 492);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == 14);

        crc = clauses_repr_clause(cr, 493);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 494);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -24);

        crc = clauses_repr_clause(cr, 495);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 496);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 21);

        crc = clauses_repr_clause(cr, 497);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 498);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 499);
        UT_ASSERT_TRUE(crc.len == 2);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -26);

    }
    {
        struct  clauses_repr_clauses_of crco;
        crco = clauses_repr_clauses_of(cr, 0);
        UT_ASSERT_TRUE(crco.len == 0);

        crco = clauses_repr_clauses_of(cr, 1);
        UT_ASSERT_TRUE(crco.len == 40);
        UT_ASSERT_TRUE(crco.first[0] == 1);
        UT_ASSERT_TRUE(crco.first[1] == 9);
        UT_ASSERT_TRUE(crco.first[2] == 30);
        UT_ASSERT_TRUE(crco.first[3] == 33);
        UT_ASSERT_TRUE(crco.first[4] == 41);
        UT_ASSERT_TRUE(crco.first[5] == 62);
        UT_ASSERT_TRUE(crco.first[6] == 87);
        UT_ASSERT_TRUE(crco.first[7] == 107);
        UT_ASSERT_TRUE(crco.first[8] == 119);
        UT_ASSERT_TRUE(crco.first[9] == 145);
        UT_ASSERT_TRUE(crco.first[10] == 161);
        UT_ASSERT_TRUE(crco.first[11] == 168);
        UT_ASSERT_TRUE(crco.first[12] == 172);
        UT_ASSERT_TRUE(crco.first[13] == 185);
        UT_ASSERT_TRUE(crco.first[14] == 210);
        UT_ASSERT_TRUE(crco.first[15] == 219);
        UT_ASSERT_TRUE(crco.first[16] == 240);
        UT_ASSERT_TRUE(crco.first[17] == 242);
        UT_ASSERT_TRUE(crco.first[18] == 243);
        UT_ASSERT_TRUE(crco.first[19] == 247);
        UT_ASSERT_TRUE(crco.first[20] == 248);
        UT_ASSERT_TRUE(crco.first[21] == 252);
        UT_ASSERT_TRUE(crco.first[22] == 270);
        UT_ASSERT_TRUE(crco.first[23] == 280);
        UT_ASSERT_TRUE(crco.first[24] == 282);
        UT_ASSERT_TRUE(crco.first[25] == 288);
        UT_ASSERT_TRUE(crco.first[26] == 311);
        UT_ASSERT_TRUE(crco.first[27] == 320);
        UT_ASSERT_TRUE(crco.first[28] == 375);
        UT_ASSERT_TRUE(crco.first[29] == 403);
        UT_ASSERT_TRUE(crco.first[30] == 412);
        UT_ASSERT_TRUE(crco.first[31] == 416);
        UT_ASSERT_TRUE(crco.first[32] == 423);
        UT_ASSERT_TRUE(crco.first[33] == 427);
        UT_ASSERT_TRUE(crco.first[34] == 439);
        UT_ASSERT_TRUE(crco.first[35] == 462);
        UT_ASSERT_TRUE(crco.first[36] == 466);
        UT_ASSERT_TRUE(crco.first[37] == 471);
        UT_ASSERT_TRUE(crco.first[38] == 473);
        UT_ASSERT_TRUE(crco.first[39] == 488);

        crco = clauses_repr_clauses_of(cr, 2);
        UT_ASSERT_TRUE(crco.len == 48);
        UT_ASSERT_TRUE(crco.first[0] == 3);
        UT_ASSERT_TRUE(crco.first[1] == 25);
        UT_ASSERT_TRUE(crco.first[2] == 38);
        UT_ASSERT_TRUE(crco.first[3] == 39);
        UT_ASSERT_TRUE(crco.first[4] == 49);
        UT_ASSERT_TRUE(crco.first[5] == 76);
        UT_ASSERT_TRUE(crco.first[6] == 79);
        UT_ASSERT_TRUE(crco.first[7] == 86);
        UT_ASSERT_TRUE(crco.first[8] == 93);
        UT_ASSERT_TRUE(crco.first[9] == 97);
        UT_ASSERT_TRUE(crco.first[10] == 147);
        UT_ASSERT_TRUE(crco.first[11] == 159);
        UT_ASSERT_TRUE(crco.first[12] == 167);
        UT_ASSERT_TRUE(crco.first[13] == 177);
        UT_ASSERT_TRUE(crco.first[14] == 195);
        UT_ASSERT_TRUE(crco.first[15] == 216);
        UT_ASSERT_TRUE(crco.first[16] == 222);
        UT_ASSERT_TRUE(crco.first[17] == 223);
        UT_ASSERT_TRUE(crco.first[18] == 225);
        UT_ASSERT_TRUE(crco.first[19] == 250);
        UT_ASSERT_TRUE(crco.first[20] == 255);
        UT_ASSERT_TRUE(crco.first[21] == 260);
        UT_ASSERT_TRUE(crco.first[22] == 271);
        UT_ASSERT_TRUE(crco.first[23] == 278);
        UT_ASSERT_TRUE(crco.first[24] == 280);
        UT_ASSERT_TRUE(crco.first[25] == 291);
        UT_ASSERT_TRUE(crco.first[26] == 293);
        UT_ASSERT_TRUE(crco.first[27] == 305);
        UT_ASSERT_TRUE(crco.first[28] == 311);
        UT_ASSERT_TRUE(crco.first[29] == 315);
        UT_ASSERT_TRUE(crco.first[30] == 331);
        UT_ASSERT_TRUE(crco.first[31] == 332);
        UT_ASSERT_TRUE(crco.first[32] == 355);
        UT_ASSERT_TRUE(crco.first[33] == 357);
        UT_ASSERT_TRUE(crco.first[34] == 363);
        UT_ASSERT_TRUE(crco.first[35] == 373);
        UT_ASSERT_TRUE(crco.first[36] == 407);
        UT_ASSERT_TRUE(crco.first[37] == 418);
        UT_ASSERT_TRUE(crco.first[38] == 441);
        UT_ASSERT_TRUE(crco.first[39] == 447);
        UT_ASSERT_TRUE(crco.first[40] == 467);
        UT_ASSERT_TRUE(crco.first[41] == 473);
        UT_ASSERT_TRUE(crco.first[42] == 481);
        UT_ASSERT_TRUE(crco.first[43] == 482);
        UT_ASSERT_TRUE(crco.first[44] == 489);
        UT_ASSERT_TRUE(crco.first[45] == 495);
        UT_ASSERT_TRUE(crco.first[46] == 497);
        UT_ASSERT_TRUE(crco.first[47] == 498);

        crco = clauses_repr_clauses_of(cr, 3);
        UT_ASSERT_TRUE(crco.len == 33);
        UT_ASSERT_TRUE(crco.first[0] == 8);
        UT_ASSERT_TRUE(crco.first[1] == 16);
        UT_ASSERT_TRUE(crco.first[2] == 44);
        UT_ASSERT_TRUE(crco.first[3] == 89);
        UT_ASSERT_TRUE(crco.first[4] == 100);
        UT_ASSERT_TRUE(crco.first[5] == 104);
        UT_ASSERT_TRUE(crco.first[6] == 120);
        UT_ASSERT_TRUE(crco.first[7] == 127);
        UT_ASSERT_TRUE(crco.first[8] == 138);
        UT_ASSERT_TRUE(crco.first[9] == 165);
        UT_ASSERT_TRUE(crco.first[10] == 166);
        UT_ASSERT_TRUE(crco.first[11] == 203);
        UT_ASSERT_TRUE(crco.first[12] == 213);
        UT_ASSERT_TRUE(crco.first[13] == 246);
        UT_ASSERT_TRUE(crco.first[14] == 274);
        UT_ASSERT_TRUE(crco.first[15] == 279);
        UT_ASSERT_TRUE(crco.first[16] == 292);
        UT_ASSERT_TRUE(crco.first[17] == 322);
        UT_ASSERT_TRUE(crco.first[18] == 324);
        UT_ASSERT_TRUE(crco.first[19] == 329);
        UT_ASSERT_TRUE(crco.first[20] == 332);
        UT_ASSERT_TRUE(crco.first[21] == 359);
        UT_ASSERT_TRUE(crco.first[22] == 361);
        UT_ASSERT_TRUE(crco.first[23] == 371);
        UT_ASSERT_TRUE(crco.first[24] == 403);
        UT_ASSERT_TRUE(crco.first[25] == 420);
        UT_ASSERT_TRUE(crco.first[26] == 432);
        UT_ASSERT_TRUE(crco.first[27] == 435);
        UT_ASSERT_TRUE(crco.first[28] == 439);
        UT_ASSERT_TRUE(crco.first[29] == 455);
        UT_ASSERT_TRUE(crco.first[30] == 474);
        UT_ASSERT_TRUE(crco.first[31] == 491);
        UT_ASSERT_TRUE(crco.first[32] == 493);

        crco = clauses_repr_clauses_of(cr, 4);
        UT_ASSERT_TRUE(crco.len == 46);
        UT_ASSERT_TRUE(crco.first[0] == 5);
        UT_ASSERT_TRUE(crco.first[1] == 9);
        UT_ASSERT_TRUE(crco.first[2] == 12);
        UT_ASSERT_TRUE(crco.first[3] == 35);
        UT_ASSERT_TRUE(crco.first[4] == 40);
        UT_ASSERT_TRUE(crco.first[5] == 52);
        UT_ASSERT_TRUE(crco.first[6] == 63);
        UT_ASSERT_TRUE(crco.first[7] == 64);
        UT_ASSERT_TRUE(crco.first[8] == 70);
        UT_ASSERT_TRUE(crco.first[9] == 77);
        UT_ASSERT_TRUE(crco.first[10] == 92);
        UT_ASSERT_TRUE(crco.first[11] == 99);
        UT_ASSERT_TRUE(crco.first[12] == 101);
        UT_ASSERT_TRUE(crco.first[13] == 102);
        UT_ASSERT_TRUE(crco.first[14] == 124);
        UT_ASSERT_TRUE(crco.first[15] == 126);
        UT_ASSERT_TRUE(crco.first[16] == 127);
        UT_ASSERT_TRUE(crco.first[17] == 157);
        UT_ASSERT_TRUE(crco.first[18] == 160);
        UT_ASSERT_TRUE(crco.first[19] == 183);
        UT_ASSERT_TRUE(crco.first[20] == 184);
        UT_ASSERT_TRUE(crco.first[21] == 192);
        UT_ASSERT_TRUE(crco.first[22] == 197);
        UT_ASSERT_TRUE(crco.first[23] == 227);
        UT_ASSERT_TRUE(crco.first[24] == 231);
        UT_ASSERT_TRUE(crco.first[25] == 234);
        UT_ASSERT_TRUE(crco.first[26] == 250);
        UT_ASSERT_TRUE(crco.first[27] == 278);
        UT_ASSERT_TRUE(crco.first[28] == 284);
        UT_ASSERT_TRUE(crco.first[29] == 290);
        UT_ASSERT_TRUE(crco.first[30] == 294);
        UT_ASSERT_TRUE(crco.first[31] == 296);
        UT_ASSERT_TRUE(crco.first[32] == 324);
        UT_ASSERT_TRUE(crco.first[33] == 325);
        UT_ASSERT_TRUE(crco.first[34] == 360);
        UT_ASSERT_TRUE(crco.first[35] == 382);
        UT_ASSERT_TRUE(crco.first[36] == 385);
        UT_ASSERT_TRUE(crco.first[37] == 404);
        UT_ASSERT_TRUE(crco.first[38] == 415);
        UT_ASSERT_TRUE(crco.first[39] == 423);
        UT_ASSERT_TRUE(crco.first[40] == 426);
        UT_ASSERT_TRUE(crco.first[41] == 444);
        UT_ASSERT_TRUE(crco.first[42] == 446);
        UT_ASSERT_TRUE(crco.first[43] == 468);
        UT_ASSERT_TRUE(crco.first[44] == 480);
        UT_ASSERT_TRUE(crco.first[45] == 485);

        crco = clauses_repr_clauses_of(cr, 5);
        UT_ASSERT_TRUE(crco.len == 41);
        UT_ASSERT_TRUE(crco.first[0] == 4);
        UT_ASSERT_TRUE(crco.first[1] == 16);
        UT_ASSERT_TRUE(crco.first[2] == 17);
        UT_ASSERT_TRUE(crco.first[3] == 24);
        UT_ASSERT_TRUE(crco.first[4] == 53);
        UT_ASSERT_TRUE(crco.first[5] == 57);
        UT_ASSERT_TRUE(crco.first[6] == 81);
        UT_ASSERT_TRUE(crco.first[7] == 93);
        UT_ASSERT_TRUE(crco.first[8] == 143);
        UT_ASSERT_TRUE(crco.first[9] == 159);
        UT_ASSERT_TRUE(crco.first[10] == 165);
        UT_ASSERT_TRUE(crco.first[11] == 173);
        UT_ASSERT_TRUE(crco.first[12] == 197);
        UT_ASSERT_TRUE(crco.first[13] == 200);
        UT_ASSERT_TRUE(crco.first[14] == 227);
        UT_ASSERT_TRUE(crco.first[15] == 243);
        UT_ASSERT_TRUE(crco.first[16] == 251);
        UT_ASSERT_TRUE(crco.first[17] == 263);
        UT_ASSERT_TRUE(crco.first[18] == 271);
        UT_ASSERT_TRUE(crco.first[19] == 282);
        UT_ASSERT_TRUE(crco.first[20] == 296);
        UT_ASSERT_TRUE(crco.first[21] == 315);
        UT_ASSERT_TRUE(crco.first[22] == 319);
        UT_ASSERT_TRUE(crco.first[23] == 321);
        UT_ASSERT_TRUE(crco.first[24] == 326);
        UT_ASSERT_TRUE(crco.first[25] == 333);
        UT_ASSERT_TRUE(crco.first[26] == 341);
        UT_ASSERT_TRUE(crco.first[27] == 351);
        UT_ASSERT_TRUE(crco.first[28] == 356);
        UT_ASSERT_TRUE(crco.first[29] == 358);
        UT_ASSERT_TRUE(crco.first[30] == 369);
        UT_ASSERT_TRUE(crco.first[31] == 386);
        UT_ASSERT_TRUE(crco.first[32] == 398);
        UT_ASSERT_TRUE(crco.first[33] == 408);
        UT_ASSERT_TRUE(crco.first[34] == 419);
        UT_ASSERT_TRUE(crco.first[35] == 425);
        UT_ASSERT_TRUE(crco.first[36] == 440);
        UT_ASSERT_TRUE(crco.first[37] == 442);
        UT_ASSERT_TRUE(crco.first[38] == 451);
        UT_ASSERT_TRUE(crco.first[39] == 484);
        UT_ASSERT_TRUE(crco.first[40] == 495);

        crco = clauses_repr_clauses_of(cr, 6);
        UT_ASSERT_TRUE(crco.len == 48);
        UT_ASSERT_TRUE(crco.first[0] == 14);
        UT_ASSERT_TRUE(crco.first[1] == 36);
        UT_ASSERT_TRUE(crco.first[2] == 37);
        UT_ASSERT_TRUE(crco.first[3] == 40);
        UT_ASSERT_TRUE(crco.first[4] == 42);
        UT_ASSERT_TRUE(crco.first[5] == 47);
        UT_ASSERT_TRUE(crco.first[6] == 57);
        UT_ASSERT_TRUE(crco.first[7] == 86);
        UT_ASSERT_TRUE(crco.first[8] == 89);
        UT_ASSERT_TRUE(crco.first[9] == 92);
        UT_ASSERT_TRUE(crco.first[10] == 101);
        UT_ASSERT_TRUE(crco.first[11] == 104);
        UT_ASSERT_TRUE(crco.first[12] == 112);
        UT_ASSERT_TRUE(crco.first[13] == 114);
        UT_ASSERT_TRUE(crco.first[14] == 116);
        UT_ASSERT_TRUE(crco.first[15] == 119);
        UT_ASSERT_TRUE(crco.first[16] == 121);
        UT_ASSERT_TRUE(crco.first[17] == 127);
        UT_ASSERT_TRUE(crco.first[18] == 149);
        UT_ASSERT_TRUE(crco.first[19] == 189);
        UT_ASSERT_TRUE(crco.first[20] == 200);
        UT_ASSERT_TRUE(crco.first[21] == 209);
        UT_ASSERT_TRUE(crco.first[22] == 221);
        UT_ASSERT_TRUE(crco.first[23] == 258);
        UT_ASSERT_TRUE(crco.first[24] == 297);
        UT_ASSERT_TRUE(crco.first[25] == 318);
        UT_ASSERT_TRUE(crco.first[26] == 323);
        UT_ASSERT_TRUE(crco.first[27] == 328);
        UT_ASSERT_TRUE(crco.first[28] == 330);
        UT_ASSERT_TRUE(crco.first[29] == 344);
        UT_ASSERT_TRUE(crco.first[30] == 366);
        UT_ASSERT_TRUE(crco.first[31] == 367);
        UT_ASSERT_TRUE(crco.first[32] == 373);
        UT_ASSERT_TRUE(crco.first[33] == 387);
        UT_ASSERT_TRUE(crco.first[34] == 389);
        UT_ASSERT_TRUE(crco.first[35] == 399);
        UT_ASSERT_TRUE(crco.first[36] == 400);
        UT_ASSERT_TRUE(crco.first[37] == 419);
        UT_ASSERT_TRUE(crco.first[38] == 425);
        UT_ASSERT_TRUE(crco.first[39] == 426);
        UT_ASSERT_TRUE(crco.first[40] == 432);
        UT_ASSERT_TRUE(crco.first[41] == 436);
        UT_ASSERT_TRUE(crco.first[42] == 446);
        UT_ASSERT_TRUE(crco.first[43] == 452);
        UT_ASSERT_TRUE(crco.first[44] == 460);
        UT_ASSERT_TRUE(crco.first[45] == 468);
        UT_ASSERT_TRUE(crco.first[46] == 474);
        UT_ASSERT_TRUE(crco.first[47] == 479);

        crco = clauses_repr_clauses_of(cr, 7);
        UT_ASSERT_TRUE(crco.len == 36);
        UT_ASSERT_TRUE(crco.first[0] == 17);
        UT_ASSERT_TRUE(crco.first[1] == 25);
        UT_ASSERT_TRUE(crco.first[2] == 37);
        UT_ASSERT_TRUE(crco.first[3] == 48);
        UT_ASSERT_TRUE(crco.first[4] == 55);
        UT_ASSERT_TRUE(crco.first[5] == 80);
        UT_ASSERT_TRUE(crco.first[6] == 101);
        UT_ASSERT_TRUE(crco.first[7] == 140);
        UT_ASSERT_TRUE(crco.first[8] == 146);
        UT_ASSERT_TRUE(crco.first[9] == 153);
        UT_ASSERT_TRUE(crco.first[10] == 156);
        UT_ASSERT_TRUE(crco.first[11] == 162);
        UT_ASSERT_TRUE(crco.first[12] == 167);
        UT_ASSERT_TRUE(crco.first[13] == 172);
        UT_ASSERT_TRUE(crco.first[14] == 220);
        UT_ASSERT_TRUE(crco.first[15] == 238);
        UT_ASSERT_TRUE(crco.first[16] == 239);
        UT_ASSERT_TRUE(crco.first[17] == 240);
        UT_ASSERT_TRUE(crco.first[18] == 253);
        UT_ASSERT_TRUE(crco.first[19] == 264);
        UT_ASSERT_TRUE(crco.first[20] == 272);
        UT_ASSERT_TRUE(crco.first[21] == 275);
        UT_ASSERT_TRUE(crco.first[22] == 301);
        UT_ASSERT_TRUE(crco.first[23] == 322);
        UT_ASSERT_TRUE(crco.first[24] == 325);
        UT_ASSERT_TRUE(crco.first[25] == 338);
        UT_ASSERT_TRUE(crco.first[26] == 375);
        UT_ASSERT_TRUE(crco.first[27] == 383);
        UT_ASSERT_TRUE(crco.first[28] == 387);
        UT_ASSERT_TRUE(crco.first[29] == 391);
        UT_ASSERT_TRUE(crco.first[30] == 400);
        UT_ASSERT_TRUE(crco.first[31] == 411);
        UT_ASSERT_TRUE(crco.first[32] == 415);
        UT_ASSERT_TRUE(crco.first[33] == 450);
        UT_ASSERT_TRUE(crco.first[34] == 458);
        UT_ASSERT_TRUE(crco.first[35] == 484);

        crco = clauses_repr_clauses_of(cr, 8);
        UT_ASSERT_TRUE(crco.len == 47);
        UT_ASSERT_TRUE(crco.first[0] == 4);
        UT_ASSERT_TRUE(crco.first[1] == 21);
        UT_ASSERT_TRUE(crco.first[2] == 67);
        UT_ASSERT_TRUE(crco.first[3] == 96);
        UT_ASSERT_TRUE(crco.first[4] == 98);
        UT_ASSERT_TRUE(crco.first[5] == 107);
        UT_ASSERT_TRUE(crco.first[6] == 110);
        UT_ASSERT_TRUE(crco.first[7] == 123);
        UT_ASSERT_TRUE(crco.first[8] == 125);
        UT_ASSERT_TRUE(crco.first[9] == 155);
        UT_ASSERT_TRUE(crco.first[10] == 158);
        UT_ASSERT_TRUE(crco.first[11] == 177);
        UT_ASSERT_TRUE(crco.first[12] == 186);
        UT_ASSERT_TRUE(crco.first[13] == 187);
        UT_ASSERT_TRUE(crco.first[14] == 193);
        UT_ASSERT_TRUE(crco.first[15] == 196);
        UT_ASSERT_TRUE(crco.first[16] == 202);
        UT_ASSERT_TRUE(crco.first[17] == 204);
        UT_ASSERT_TRUE(crco.first[18] == 209);
        UT_ASSERT_TRUE(crco.first[19] == 210);
        UT_ASSERT_TRUE(crco.first[20] == 215);
        UT_ASSERT_TRUE(crco.first[21] == 216);
        UT_ASSERT_TRUE(crco.first[22] == 225);
        UT_ASSERT_TRUE(crco.first[23] == 236);
        UT_ASSERT_TRUE(crco.first[24] == 247);
        UT_ASSERT_TRUE(crco.first[25] == 248);
        UT_ASSERT_TRUE(crco.first[26] == 254);
        UT_ASSERT_TRUE(crco.first[27] == 256);
        UT_ASSERT_TRUE(crco.first[28] == 261);
        UT_ASSERT_TRUE(crco.first[29] == 268);
        UT_ASSERT_TRUE(crco.first[30] == 279);
        UT_ASSERT_TRUE(crco.first[31] == 283);
        UT_ASSERT_TRUE(crco.first[32] == 286);
        UT_ASSERT_TRUE(crco.first[33] == 292);
        UT_ASSERT_TRUE(crco.first[34] == 294);
        UT_ASSERT_TRUE(crco.first[35] == 298);
        UT_ASSERT_TRUE(crco.first[36] == 317);
        UT_ASSERT_TRUE(crco.first[37] == 339);
        UT_ASSERT_TRUE(crco.first[38] == 379);
        UT_ASSERT_TRUE(crco.first[39] == 388);
        UT_ASSERT_TRUE(crco.first[40] == 390);
        UT_ASSERT_TRUE(crco.first[41] == 450);
        UT_ASSERT_TRUE(crco.first[42] == 456);
        UT_ASSERT_TRUE(crco.first[43] == 465);
        UT_ASSERT_TRUE(crco.first[44] == 470);
        UT_ASSERT_TRUE(crco.first[45] == 478);
        UT_ASSERT_TRUE(crco.first[46] == 483);

        crco = clauses_repr_clauses_of(cr, 9);
        UT_ASSERT_TRUE(crco.len == 38);
        UT_ASSERT_TRUE(crco.first[0] == 5);
        UT_ASSERT_TRUE(crco.first[1] == 6);
        UT_ASSERT_TRUE(crco.first[2] == 29);
        UT_ASSERT_TRUE(crco.first[3] == 45);
        UT_ASSERT_TRUE(crco.first[4] == 51);
        UT_ASSERT_TRUE(crco.first[5] == 110);
        UT_ASSERT_TRUE(crco.first[6] == 118);
        UT_ASSERT_TRUE(crco.first[7] == 128);
        UT_ASSERT_TRUE(crco.first[8] == 134);
        UT_ASSERT_TRUE(crco.first[9] == 149);
        UT_ASSERT_TRUE(crco.first[10] == 156);
        UT_ASSERT_TRUE(crco.first[11] == 162);
        UT_ASSERT_TRUE(crco.first[12] == 183);
        UT_ASSERT_TRUE(crco.first[13] == 188);
        UT_ASSERT_TRUE(crco.first[14] == 192);
        UT_ASSERT_TRUE(crco.first[15] == 204);
        UT_ASSERT_TRUE(crco.first[16] == 217);
        UT_ASSERT_TRUE(crco.first[17] == 232);
        UT_ASSERT_TRUE(crco.first[18] == 251);
        UT_ASSERT_TRUE(crco.first[19] == 252);
        UT_ASSERT_TRUE(crco.first[20] == 262);
        UT_ASSERT_TRUE(crco.first[21] == 265);
        UT_ASSERT_TRUE(crco.first[22] == 275);
        UT_ASSERT_TRUE(crco.first[23] == 284);
        UT_ASSERT_TRUE(crco.first[24] == 295);
        UT_ASSERT_TRUE(crco.first[25] == 320);
        UT_ASSERT_TRUE(crco.first[26] == 328);
        UT_ASSERT_TRUE(crco.first[27] == 334);
        UT_ASSERT_TRUE(crco.first[28] == 348);
        UT_ASSERT_TRUE(crco.first[29] == 351);
        UT_ASSERT_TRUE(crco.first[30] == 352);
        UT_ASSERT_TRUE(crco.first[31] == 364);
        UT_ASSERT_TRUE(crco.first[32] == 377);
        UT_ASSERT_TRUE(crco.first[33] == 379);
        UT_ASSERT_TRUE(crco.first[34] == 384);
        UT_ASSERT_TRUE(crco.first[35] == 401);
        UT_ASSERT_TRUE(crco.first[36] == 405);
        UT_ASSERT_TRUE(crco.first[37] == 455);

        crco = clauses_repr_clauses_of(cr, 10);
        UT_ASSERT_TRUE(crco.len == 53);
        UT_ASSERT_TRUE(crco.first[0] == 16);
        UT_ASSERT_TRUE(crco.first[1] == 41);
        UT_ASSERT_TRUE(crco.first[2] == 69);
        UT_ASSERT_TRUE(crco.first[3] == 82);
        UT_ASSERT_TRUE(crco.first[4] == 83);
        UT_ASSERT_TRUE(crco.first[5] == 87);
        UT_ASSERT_TRUE(crco.first[6] == 91);
        UT_ASSERT_TRUE(crco.first[7] == 95);
        UT_ASSERT_TRUE(crco.first[8] == 105);
        UT_ASSERT_TRUE(crco.first[9] == 122);
        UT_ASSERT_TRUE(crco.first[10] == 132);
        UT_ASSERT_TRUE(crco.first[11] == 135);
        UT_ASSERT_TRUE(crco.first[12] == 140);
        UT_ASSERT_TRUE(crco.first[13] == 151);
        UT_ASSERT_TRUE(crco.first[14] == 161);
        UT_ASSERT_TRUE(crco.first[15] == 164);
        UT_ASSERT_TRUE(crco.first[16] == 202);
        UT_ASSERT_TRUE(crco.first[17] == 203);
        UT_ASSERT_TRUE(crco.first[18] == 208);
        UT_ASSERT_TRUE(crco.first[19] == 214);
        UT_ASSERT_TRUE(crco.first[20] == 233);
        UT_ASSERT_TRUE(crco.first[21] == 236);
        UT_ASSERT_TRUE(crco.first[22] == 245);
        UT_ASSERT_TRUE(crco.first[23] == 285);
        UT_ASSERT_TRUE(crco.first[24] == 289);
        UT_ASSERT_TRUE(crco.first[25] == 314);
        UT_ASSERT_TRUE(crco.first[26] == 322);
        UT_ASSERT_TRUE(crco.first[27] == 323);
        UT_ASSERT_TRUE(crco.first[28] == 328);
        UT_ASSERT_TRUE(crco.first[29] == 336);
        UT_ASSERT_TRUE(crco.first[30] == 343);
        UT_ASSERT_TRUE(crco.first[31] == 346);
        UT_ASSERT_TRUE(crco.first[32] == 350);
        UT_ASSERT_TRUE(crco.first[33] == 367);
        UT_ASSERT_TRUE(crco.first[34] == 374);
        UT_ASSERT_TRUE(crco.first[35] == 382);
        UT_ASSERT_TRUE(crco.first[36] == 388);
        UT_ASSERT_TRUE(crco.first[37] == 394);
        UT_ASSERT_TRUE(crco.first[38] == 396);
        UT_ASSERT_TRUE(crco.first[39] == 401);
        UT_ASSERT_TRUE(crco.first[40] == 402);
        UT_ASSERT_TRUE(crco.first[41] == 407);
        UT_ASSERT_TRUE(crco.first[42] == 414);
        UT_ASSERT_TRUE(crco.first[43] == 416);
        UT_ASSERT_TRUE(crco.first[44] == 438);
        UT_ASSERT_TRUE(crco.first[45] == 443);
        UT_ASSERT_TRUE(crco.first[46] == 445);
        UT_ASSERT_TRUE(crco.first[47] == 448);
        UT_ASSERT_TRUE(crco.first[48] == 459);
        UT_ASSERT_TRUE(crco.first[49] == 460);
        UT_ASSERT_TRUE(crco.first[50] == 468);
        UT_ASSERT_TRUE(crco.first[51] == 485);
        UT_ASSERT_TRUE(crco.first[52] == 486);

        crco = clauses_repr_clauses_of(cr, 11);
        UT_ASSERT_TRUE(crco.len == 34);
        UT_ASSERT_TRUE(crco.first[0] == 1);
        UT_ASSERT_TRUE(crco.first[1] == 4);
        UT_ASSERT_TRUE(crco.first[2] == 24);
        UT_ASSERT_TRUE(crco.first[3] == 39);
        UT_ASSERT_TRUE(crco.first[4] == 43);
        UT_ASSERT_TRUE(crco.first[5] == 79);
        UT_ASSERT_TRUE(crco.first[6] == 103);
        UT_ASSERT_TRUE(crco.first[7] == 111);
        UT_ASSERT_TRUE(crco.first[8] == 118);
        UT_ASSERT_TRUE(crco.first[9] == 129);
        UT_ASSERT_TRUE(crco.first[10] == 139);
        UT_ASSERT_TRUE(crco.first[11] == 158);
        UT_ASSERT_TRUE(crco.first[12] == 172);
        UT_ASSERT_TRUE(crco.first[13] == 178);
        UT_ASSERT_TRUE(crco.first[14] == 207);
        UT_ASSERT_TRUE(crco.first[15] == 226);
        UT_ASSERT_TRUE(crco.first[16] == 248);
        UT_ASSERT_TRUE(crco.first[17] == 274);
        UT_ASSERT_TRUE(crco.first[18] == 276);
        UT_ASSERT_TRUE(crco.first[19] == 279);
        UT_ASSERT_TRUE(crco.first[20] == 299);
        UT_ASSERT_TRUE(crco.first[21] == 302);
        UT_ASSERT_TRUE(crco.first[22] == 334);
        UT_ASSERT_TRUE(crco.first[23] == 336);
        UT_ASSERT_TRUE(crco.first[24] == 340);
        UT_ASSERT_TRUE(crco.first[25] == 342);
        UT_ASSERT_TRUE(crco.first[26] == 359);
        UT_ASSERT_TRUE(crco.first[27] == 372);
        UT_ASSERT_TRUE(crco.first[28] == 398);
        UT_ASSERT_TRUE(crco.first[29] == 417);
        UT_ASSERT_TRUE(crco.first[30] == 418);
        UT_ASSERT_TRUE(crco.first[31] == 424);
        UT_ASSERT_TRUE(crco.first[32] == 433);
        UT_ASSERT_TRUE(crco.first[33] == 440);

        crco = clauses_repr_clauses_of(cr, 12);
        UT_ASSERT_TRUE(crco.len == 31);
        UT_ASSERT_TRUE(crco.first[0] == 50);
        UT_ASSERT_TRUE(crco.first[1] == 52);
        UT_ASSERT_TRUE(crco.first[2] == 63);
        UT_ASSERT_TRUE(crco.first[3] == 85);
        UT_ASSERT_TRUE(crco.first[4] == 141);
        UT_ASSERT_TRUE(crco.first[5] == 148);
        UT_ASSERT_TRUE(crco.first[6] == 152);
        UT_ASSERT_TRUE(crco.first[7] == 163);
        UT_ASSERT_TRUE(crco.first[8] == 171);
        UT_ASSERT_TRUE(crco.first[9] == 187);
        UT_ASSERT_TRUE(crco.first[10] == 189);
        UT_ASSERT_TRUE(crco.first[11] == 227);
        UT_ASSERT_TRUE(crco.first[12] == 254);
        UT_ASSERT_TRUE(crco.first[13] == 259);
        UT_ASSERT_TRUE(crco.first[14] == 260);
        UT_ASSERT_TRUE(crco.first[15] == 262);
        UT_ASSERT_TRUE(crco.first[16] == 273);
        UT_ASSERT_TRUE(crco.first[17] == 295);
        UT_ASSERT_TRUE(crco.first[18] == 310);
        UT_ASSERT_TRUE(crco.first[19] == 331);
        UT_ASSERT_TRUE(crco.first[20] == 367);
        UT_ASSERT_TRUE(crco.first[21] == 374);
        UT_ASSERT_TRUE(crco.first[22] == 378);
        UT_ASSERT_TRUE(crco.first[23] == 391);
        UT_ASSERT_TRUE(crco.first[24] == 407);
        UT_ASSERT_TRUE(crco.first[25] == 417);
        UT_ASSERT_TRUE(crco.first[26] == 418);
        UT_ASSERT_TRUE(crco.first[27] == 435);
        UT_ASSERT_TRUE(crco.first[28] == 448);
        UT_ASSERT_TRUE(crco.first[29] == 466);
        UT_ASSERT_TRUE(crco.first[30] == 474);

        crco = clauses_repr_clauses_of(cr, 13);
        UT_ASSERT_TRUE(crco.len == 38);
        UT_ASSERT_TRUE(crco.first[0] == 6);
        UT_ASSERT_TRUE(crco.first[1] == 11);
        UT_ASSERT_TRUE(crco.first[2] == 22);
        UT_ASSERT_TRUE(crco.first[3] == 54);
        UT_ASSERT_TRUE(crco.first[4] == 56);
        UT_ASSERT_TRUE(crco.first[5] == 71);
        UT_ASSERT_TRUE(crco.first[6] == 83);
        UT_ASSERT_TRUE(crco.first[7] == 117);
        UT_ASSERT_TRUE(crco.first[8] == 144);
        UT_ASSERT_TRUE(crco.first[9] == 154);
        UT_ASSERT_TRUE(crco.first[10] == 169);
        UT_ASSERT_TRUE(crco.first[11] == 173);
        UT_ASSERT_TRUE(crco.first[12] == 175);
        UT_ASSERT_TRUE(crco.first[13] == 207);
        UT_ASSERT_TRUE(crco.first[14] == 235);
        UT_ASSERT_TRUE(crco.first[15] == 236);
        UT_ASSERT_TRUE(crco.first[16] == 245);
        UT_ASSERT_TRUE(crco.first[17] == 267);
        UT_ASSERT_TRUE(crco.first[18] == 269);
        UT_ASSERT_TRUE(crco.first[19] == 309);
        UT_ASSERT_TRUE(crco.first[20] == 310);
        UT_ASSERT_TRUE(crco.first[21] == 317);
        UT_ASSERT_TRUE(crco.first[22] == 333);
        UT_ASSERT_TRUE(crco.first[23] == 342);
        UT_ASSERT_TRUE(crco.first[24] == 354);
        UT_ASSERT_TRUE(crco.first[25] == 359);
        UT_ASSERT_TRUE(crco.first[26] == 361);
        UT_ASSERT_TRUE(crco.first[27] == 371);
        UT_ASSERT_TRUE(crco.first[28] == 422);
        UT_ASSERT_TRUE(crco.first[29] == 446);
        UT_ASSERT_TRUE(crco.first[30] == 455);
        UT_ASSERT_TRUE(crco.first[31] == 462);
        UT_ASSERT_TRUE(crco.first[32] == 469);
        UT_ASSERT_TRUE(crco.first[33] == 476);
        UT_ASSERT_TRUE(crco.first[34] == 480);
        UT_ASSERT_TRUE(crco.first[35] == 486);
        UT_ASSERT_TRUE(crco.first[36] == 487);
        UT_ASSERT_TRUE(crco.first[37] == 493);

        crco = clauses_repr_clauses_of(cr, 14);
        UT_ASSERT_TRUE(crco.len == 44);
        UT_ASSERT_TRUE(crco.first[0] == 2);
        UT_ASSERT_TRUE(crco.first[1] == 21);
        UT_ASSERT_TRUE(crco.first[2] == 45);
        UT_ASSERT_TRUE(crco.first[3] == 46);
        UT_ASSERT_TRUE(crco.first[4] == 74);
        UT_ASSERT_TRUE(crco.first[5] == 90);
        UT_ASSERT_TRUE(crco.first[6] == 91);
        UT_ASSERT_TRUE(crco.first[7] == 113);
        UT_ASSERT_TRUE(crco.first[8] == 125);
        UT_ASSERT_TRUE(crco.first[9] == 135);
        UT_ASSERT_TRUE(crco.first[10] == 136);
        UT_ASSERT_TRUE(crco.first[11] == 146);
        UT_ASSERT_TRUE(crco.first[12] == 148);
        UT_ASSERT_TRUE(crco.first[13] == 153);
        UT_ASSERT_TRUE(crco.first[14] == 160);
        UT_ASSERT_TRUE(crco.first[15] == 168);
        UT_ASSERT_TRUE(crco.first[16] == 209);
        UT_ASSERT_TRUE(crco.first[17] == 212);
        UT_ASSERT_TRUE(crco.first[18] == 215);
        UT_ASSERT_TRUE(crco.first[19] == 231);
        UT_ASSERT_TRUE(crco.first[20] == 264);
        UT_ASSERT_TRUE(crco.first[21] == 277);
        UT_ASSERT_TRUE(crco.first[22] == 283);
        UT_ASSERT_TRUE(crco.first[23] == 285);
        UT_ASSERT_TRUE(crco.first[24] == 287);
        UT_ASSERT_TRUE(crco.first[25] == 290);
        UT_ASSERT_TRUE(crco.first[26] == 295);
        UT_ASSERT_TRUE(crco.first[27] == 299);
        UT_ASSERT_TRUE(crco.first[28] == 303);
        UT_ASSERT_TRUE(crco.first[29] == 313);
        UT_ASSERT_TRUE(crco.first[30] == 329);
        UT_ASSERT_TRUE(crco.first[31] == 347);
        UT_ASSERT_TRUE(crco.first[32] == 350);
        UT_ASSERT_TRUE(crco.first[33] == 372);
        UT_ASSERT_TRUE(crco.first[34] == 402);
        UT_ASSERT_TRUE(crco.first[35] == 405);
        UT_ASSERT_TRUE(crco.first[36] == 430);
        UT_ASSERT_TRUE(crco.first[37] == 431);
        UT_ASSERT_TRUE(crco.first[38] == 434);
        UT_ASSERT_TRUE(crco.first[39] == 454);
        UT_ASSERT_TRUE(crco.first[40] == 463);
        UT_ASSERT_TRUE(crco.first[41] == 478);
        UT_ASSERT_TRUE(crco.first[42] == 492);
        UT_ASSERT_TRUE(crco.first[43] == 494);

        crco = clauses_repr_clauses_of(cr, 15);
        UT_ASSERT_TRUE(crco.len == 41);
        UT_ASSERT_TRUE(crco.first[0] == 28);
        UT_ASSERT_TRUE(crco.first[1] == 41);
        UT_ASSERT_TRUE(crco.first[2] == 46);
        UT_ASSERT_TRUE(crco.first[3] == 58);
        UT_ASSERT_TRUE(crco.first[4] == 65);
        UT_ASSERT_TRUE(crco.first[5] == 88);
        UT_ASSERT_TRUE(crco.first[6] == 94);
        UT_ASSERT_TRUE(crco.first[7] == 96);
        UT_ASSERT_TRUE(crco.first[8] == 109);
        UT_ASSERT_TRUE(crco.first[9] == 115);
        UT_ASSERT_TRUE(crco.first[10] == 143);
        UT_ASSERT_TRUE(crco.first[11] == 147);
        UT_ASSERT_TRUE(crco.first[12] == 148);
        UT_ASSERT_TRUE(crco.first[13] == 164);
        UT_ASSERT_TRUE(crco.first[14] == 176);
        UT_ASSERT_TRUE(crco.first[15] == 191);
        UT_ASSERT_TRUE(crco.first[16] == 199);
        UT_ASSERT_TRUE(crco.first[17] == 208);
        UT_ASSERT_TRUE(crco.first[18] == 214);
        UT_ASSERT_TRUE(crco.first[19] == 217);
        UT_ASSERT_TRUE(crco.first[20] == 226);
        UT_ASSERT_TRUE(crco.first[21] == 239);
        UT_ASSERT_TRUE(crco.first[22] == 261);
        UT_ASSERT_TRUE(crco.first[23] == 277);
        UT_ASSERT_TRUE(crco.first[24] == 307);
        UT_ASSERT_TRUE(crco.first[25] == 314);
        UT_ASSERT_TRUE(crco.first[26] == 330);
        UT_ASSERT_TRUE(crco.first[27] == 335);
        UT_ASSERT_TRUE(crco.first[28] == 358);
        UT_ASSERT_TRUE(crco.first[29] == 368);
        UT_ASSERT_TRUE(crco.first[30] == 377);
        UT_ASSERT_TRUE(crco.first[31] == 391);
        UT_ASSERT_TRUE(crco.first[32] == 393);
        UT_ASSERT_TRUE(crco.first[33] == 444);
        UT_ASSERT_TRUE(crco.first[34] == 452);
        UT_ASSERT_TRUE(crco.first[35] == 457);
        UT_ASSERT_TRUE(crco.first[36] == 458);
        UT_ASSERT_TRUE(crco.first[37] == 463);
        UT_ASSERT_TRUE(crco.first[38] == 465);
        UT_ASSERT_TRUE(crco.first[39] == 482);
        UT_ASSERT_TRUE(crco.first[40] == 488);

        crco = clauses_repr_clauses_of(cr, 16);
        UT_ASSERT_TRUE(crco.len == 45);
        UT_ASSERT_TRUE(crco.first[0] == 6);
        UT_ASSERT_TRUE(crco.first[1] == 10);
        UT_ASSERT_TRUE(crco.first[2] == 13);
        UT_ASSERT_TRUE(crco.first[3] == 18);
        UT_ASSERT_TRUE(crco.first[4] == 20);
        UT_ASSERT_TRUE(crco.first[5] == 30);
        UT_ASSERT_TRUE(crco.first[6] == 34);
        UT_ASSERT_TRUE(crco.first[7] == 54);
        UT_ASSERT_TRUE(crco.first[8] == 76);
        UT_ASSERT_TRUE(crco.first[9] == 80);
        UT_ASSERT_TRUE(crco.first[10] == 86);
        UT_ASSERT_TRUE(crco.first[11] == 108);
        UT_ASSERT_TRUE(crco.first[12] == 116);
        UT_ASSERT_TRUE(crco.first[13] == 131);
        UT_ASSERT_TRUE(crco.first[14] == 136);
        UT_ASSERT_TRUE(crco.first[15] == 137);
        UT_ASSERT_TRUE(crco.first[16] == 157);
        UT_ASSERT_TRUE(crco.first[17] == 171);
        UT_ASSERT_TRUE(crco.first[18] == 173);
        UT_ASSERT_TRUE(crco.first[19] == 179);
        UT_ASSERT_TRUE(crco.first[20] == 201);
        UT_ASSERT_TRUE(crco.first[21] == 206);
        UT_ASSERT_TRUE(crco.first[22] == 234);
        UT_ASSERT_TRUE(crco.first[23] == 249);
        UT_ASSERT_TRUE(crco.first[24] == 251);
        UT_ASSERT_TRUE(crco.first[25] == 257);
        UT_ASSERT_TRUE(crco.first[26] == 262);
        UT_ASSERT_TRUE(crco.first[27] == 300);
        UT_ASSERT_TRUE(crco.first[28] == 303);
        UT_ASSERT_TRUE(crco.first[29] == 312);
        UT_ASSERT_TRUE(crco.first[30] == 313);
        UT_ASSERT_TRUE(crco.first[31] == 320);
        UT_ASSERT_TRUE(crco.first[32] == 345);
        UT_ASSERT_TRUE(crco.first[33] == 354);
        UT_ASSERT_TRUE(crco.first[34] == 364);
        UT_ASSERT_TRUE(crco.first[35] == 378);
        UT_ASSERT_TRUE(crco.first[36] == 412);
        UT_ASSERT_TRUE(crco.first[37] == 414);
        UT_ASSERT_TRUE(crco.first[38] == 424);
        UT_ASSERT_TRUE(crco.first[39] == 428);
        UT_ASSERT_TRUE(crco.first[40] == 440);
        UT_ASSERT_TRUE(crco.first[41] == 476);
        UT_ASSERT_TRUE(crco.first[42] == 490);
        UT_ASSERT_TRUE(crco.first[43] == 497);
        UT_ASSERT_TRUE(crco.first[44] == 498);

        crco = clauses_repr_clauses_of(cr, 17);
        UT_ASSERT_TRUE(crco.len == 41);
        UT_ASSERT_TRUE(crco.first[0] == 19);
        UT_ASSERT_TRUE(crco.first[1] == 27);
        UT_ASSERT_TRUE(crco.first[2] == 32);
        UT_ASSERT_TRUE(crco.first[3] == 33);
        UT_ASSERT_TRUE(crco.first[4] == 35);
        UT_ASSERT_TRUE(crco.first[5] == 42);
        UT_ASSERT_TRUE(crco.first[6] == 46);
        UT_ASSERT_TRUE(crco.first[7] == 56);
        UT_ASSERT_TRUE(crco.first[8] == 65);
        UT_ASSERT_TRUE(crco.first[9] == 89);
        UT_ASSERT_TRUE(crco.first[10] == 100);
        UT_ASSERT_TRUE(crco.first[11] == 103);
        UT_ASSERT_TRUE(crco.first[12] == 108);
        UT_ASSERT_TRUE(crco.first[13] == 147);
        UT_ASSERT_TRUE(crco.first[14] == 155);
        UT_ASSERT_TRUE(crco.first[15] == 175);
        UT_ASSERT_TRUE(crco.first[16] == 193);
        UT_ASSERT_TRUE(crco.first[17] == 225);
        UT_ASSERT_TRUE(crco.first[18] == 245);
        UT_ASSERT_TRUE(crco.first[19] == 255);
        UT_ASSERT_TRUE(crco.first[20] == 257);
        UT_ASSERT_TRUE(crco.first[21] == 266);
        UT_ASSERT_TRUE(crco.first[22] == 273);
        UT_ASSERT_TRUE(crco.first[23] == 283);
        UT_ASSERT_TRUE(crco.first[24] == 290);
        UT_ASSERT_TRUE(crco.first[25] == 297);
        UT_ASSERT_TRUE(crco.first[26] == 309);
        UT_ASSERT_TRUE(crco.first[27] == 316);
        UT_ASSERT_TRUE(crco.first[28] == 327);
        UT_ASSERT_TRUE(crco.first[29] == 337);
        UT_ASSERT_TRUE(crco.first[30] == 376);
        UT_ASSERT_TRUE(crco.first[31] == 381);
        UT_ASSERT_TRUE(crco.first[32] == 387);
        UT_ASSERT_TRUE(crco.first[33] == 404);
        UT_ASSERT_TRUE(crco.first[34] == 424);
        UT_ASSERT_TRUE(crco.first[35] == 431);
        UT_ASSERT_TRUE(crco.first[36] == 464);
        UT_ASSERT_TRUE(crco.first[37] == 469);
        UT_ASSERT_TRUE(crco.first[38] == 473);
        UT_ASSERT_TRUE(crco.first[39] == 477);
        UT_ASSERT_TRUE(crco.first[40] == 487);

        crco = clauses_repr_clauses_of(cr, 18);
        UT_ASSERT_TRUE(crco.len == 36);
        UT_ASSERT_TRUE(crco.first[0] == 31);
        UT_ASSERT_TRUE(crco.first[1] == 38);
        UT_ASSERT_TRUE(crco.first[2] == 39);
        UT_ASSERT_TRUE(crco.first[3] == 51);
        UT_ASSERT_TRUE(crco.first[4] == 54);
        UT_ASSERT_TRUE(crco.first[5] == 95);
        UT_ASSERT_TRUE(crco.first[6] == 128);
        UT_ASSERT_TRUE(crco.first[7] == 129);
        UT_ASSERT_TRUE(crco.first[8] == 131);
        UT_ASSERT_TRUE(crco.first[9] == 133);
        UT_ASSERT_TRUE(crco.first[10] == 134);
        UT_ASSERT_TRUE(crco.first[11] == 142);
        UT_ASSERT_TRUE(crco.first[12] == 150);
        UT_ASSERT_TRUE(crco.first[13] == 170);
        UT_ASSERT_TRUE(crco.first[14] == 181);
        UT_ASSERT_TRUE(crco.first[15] == 182);
        UT_ASSERT_TRUE(crco.first[16] == 199);
        UT_ASSERT_TRUE(crco.first[17] == 242);
        UT_ASSERT_TRUE(crco.first[18] == 246);
        UT_ASSERT_TRUE(crco.first[19] == 252);
        UT_ASSERT_TRUE(crco.first[20] == 263);
        UT_ASSERT_TRUE(crco.first[21] == 272);
        UT_ASSERT_TRUE(crco.first[22] == 281);
        UT_ASSERT_TRUE(crco.first[23] == 316);
        UT_ASSERT_TRUE(crco.first[24] == 335);
        UT_ASSERT_TRUE(crco.first[25] == 343);
        UT_ASSERT_TRUE(crco.first[26] == 348);
        UT_ASSERT_TRUE(crco.first[27] == 353);
        UT_ASSERT_TRUE(crco.first[28] == 356);
        UT_ASSERT_TRUE(crco.first[29] == 366);
        UT_ASSERT_TRUE(crco.first[30] == 386);
        UT_ASSERT_TRUE(crco.first[31] == 419);
        UT_ASSERT_TRUE(crco.first[32] == 425);
        UT_ASSERT_TRUE(crco.first[33] == 459);
        UT_ASSERT_TRUE(crco.first[34] == 479);
        UT_ASSERT_TRUE(crco.first[35] == 499);

        crco = clauses_repr_clauses_of(cr, 19);
        UT_ASSERT_TRUE(crco.len == 42);
        UT_ASSERT_TRUE(crco.first[0] == 7);
        UT_ASSERT_TRUE(crco.first[1] == 18);
        UT_ASSERT_TRUE(crco.first[2] == 58);
        UT_ASSERT_TRUE(crco.first[3] == 61);
        UT_ASSERT_TRUE(crco.first[4] == 72);
        UT_ASSERT_TRUE(crco.first[5] == 73);
        UT_ASSERT_TRUE(crco.first[6] == 74);
        UT_ASSERT_TRUE(crco.first[7] == 85);
        UT_ASSERT_TRUE(crco.first[8] == 94);
        UT_ASSERT_TRUE(crco.first[9] == 99);
        UT_ASSERT_TRUE(crco.first[10] == 110);
        UT_ASSERT_TRUE(crco.first[11] == 116);
        UT_ASSERT_TRUE(crco.first[12] == 126);
        UT_ASSERT_TRUE(crco.first[13] == 134);
        UT_ASSERT_TRUE(crco.first[14] == 138);
        UT_ASSERT_TRUE(crco.first[15] == 170);
        UT_ASSERT_TRUE(crco.first[16] == 174);
        UT_ASSERT_TRUE(crco.first[17] == 180);
        UT_ASSERT_TRUE(crco.first[18] == 182);
        UT_ASSERT_TRUE(crco.first[19] == 190);
        UT_ASSERT_TRUE(crco.first[20] == 220);
        UT_ASSERT_TRUE(crco.first[21] == 223);
        UT_ASSERT_TRUE(crco.first[22] == 228);
        UT_ASSERT_TRUE(crco.first[23] == 230);
        UT_ASSERT_TRUE(crco.first[24] == 238);
        UT_ASSERT_TRUE(crco.first[25] == 266);
        UT_ASSERT_TRUE(crco.first[26] == 267);
        UT_ASSERT_TRUE(crco.first[27] == 276);
        UT_ASSERT_TRUE(crco.first[28] == 291);
        UT_ASSERT_TRUE(crco.first[29] == 304);
        UT_ASSERT_TRUE(crco.first[30] == 308);
        UT_ASSERT_TRUE(crco.first[31] == 312);
        UT_ASSERT_TRUE(crco.first[32] == 341);
        UT_ASSERT_TRUE(crco.first[33] == 351);
        UT_ASSERT_TRUE(crco.first[34] == 362);
        UT_ASSERT_TRUE(crco.first[35] == 408);
        UT_ASSERT_TRUE(crco.first[36] == 410);
        UT_ASSERT_TRUE(crco.first[37] == 413);
        UT_ASSERT_TRUE(crco.first[38] == 414);
        UT_ASSERT_TRUE(crco.first[39] == 454);
        UT_ASSERT_TRUE(crco.first[40] == 457);
        UT_ASSERT_TRUE(crco.first[41] == 485);

        crco = clauses_repr_clauses_of(cr, 20);
        UT_ASSERT_TRUE(crco.len == 36);
        UT_ASSERT_TRUE(crco.first[0] == 7);
        UT_ASSERT_TRUE(crco.first[1] == 11);
        UT_ASSERT_TRUE(crco.first[2] == 12);
        UT_ASSERT_TRUE(crco.first[3] == 47);
        UT_ASSERT_TRUE(crco.first[4] == 55);
        UT_ASSERT_TRUE(crco.first[5] == 60);
        UT_ASSERT_TRUE(crco.first[6] == 61);
        UT_ASSERT_TRUE(crco.first[7] == 68);
        UT_ASSERT_TRUE(crco.first[8] == 77);
        UT_ASSERT_TRUE(crco.first[9] == 82);
        UT_ASSERT_TRUE(crco.first[10] == 90);
        UT_ASSERT_TRUE(crco.first[11] == 102);
        UT_ASSERT_TRUE(crco.first[12] == 133);
        UT_ASSERT_TRUE(crco.first[13] == 153);
        UT_ASSERT_TRUE(crco.first[14] == 155);
        UT_ASSERT_TRUE(crco.first[15] == 165);
        UT_ASSERT_TRUE(crco.first[16] == 184);
        UT_ASSERT_TRUE(crco.first[17] == 190);
        UT_ASSERT_TRUE(crco.first[18] == 219);
        UT_ASSERT_TRUE(crco.first[19] == 250);
        UT_ASSERT_TRUE(crco.first[20] == 285);
        UT_ASSERT_TRUE(crco.first[21] == 306);
        UT_ASSERT_TRUE(crco.first[22] == 349);
        UT_ASSERT_TRUE(crco.first[23] == 370);
        UT_ASSERT_TRUE(crco.first[24] == 376);
        UT_ASSERT_TRUE(crco.first[25] == 380);
        UT_ASSERT_TRUE(crco.first[26] == 392);
        UT_ASSERT_TRUE(crco.first[27] == 393);
        UT_ASSERT_TRUE(crco.first[28] == 400);
        UT_ASSERT_TRUE(crco.first[29] == 409);
        UT_ASSERT_TRUE(crco.first[30] == 462);
        UT_ASSERT_TRUE(crco.first[31] == 475);
        UT_ASSERT_TRUE(crco.first[32] == 483);
        UT_ASSERT_TRUE(crco.first[33] == 486);
        UT_ASSERT_TRUE(crco.first[34] == 493);
        UT_ASSERT_TRUE(crco.first[35] == 497);

        crco = clauses_repr_clauses_of(cr, 21);
        UT_ASSERT_TRUE(crco.len == 45);
        UT_ASSERT_TRUE(crco.first[0] == 0);
        UT_ASSERT_TRUE(crco.first[1] == 2);
        UT_ASSERT_TRUE(crco.first[2] == 14);
        UT_ASSERT_TRUE(crco.first[3] == 19);
        UT_ASSERT_TRUE(crco.first[4] == 36);
        UT_ASSERT_TRUE(crco.first[5] == 43);
        UT_ASSERT_TRUE(crco.first[6] == 49);
        UT_ASSERT_TRUE(crco.first[7] == 53);
        UT_ASSERT_TRUE(crco.first[8] == 59);
        UT_ASSERT_TRUE(crco.first[9] == 62);
        UT_ASSERT_TRUE(crco.first[10] == 84);
        UT_ASSERT_TRUE(crco.first[11] == 114);
        UT_ASSERT_TRUE(crco.first[12] == 139);
        UT_ASSERT_TRUE(crco.first[13] == 158);
        UT_ASSERT_TRUE(crco.first[14] == 178);
        UT_ASSERT_TRUE(crco.first[15] == 196);
        UT_ASSERT_TRUE(crco.first[16] == 200);
        UT_ASSERT_TRUE(crco.first[17] == 211);
        UT_ASSERT_TRUE(crco.first[18] == 212);
        UT_ASSERT_TRUE(crco.first[19] == 221);
        UT_ASSERT_TRUE(crco.first[20] == 228);
        UT_ASSERT_TRUE(crco.first[21] == 241);
        UT_ASSERT_TRUE(crco.first[22] == 264);
        UT_ASSERT_TRUE(crco.first[23] == 265);
        UT_ASSERT_TRUE(crco.first[24] == 296);
        UT_ASSERT_TRUE(crco.first[25] == 305);
        UT_ASSERT_TRUE(crco.first[26] == 319);
        UT_ASSERT_TRUE(crco.first[27] == 344);
        UT_ASSERT_TRUE(crco.first[28] == 350);
        UT_ASSERT_TRUE(crco.first[29] == 355);
        UT_ASSERT_TRUE(crco.first[30] == 360);
        UT_ASSERT_TRUE(crco.first[31] == 368);
        UT_ASSERT_TRUE(crco.first[32] == 379);
        UT_ASSERT_TRUE(crco.first[33] == 389);
        UT_ASSERT_TRUE(crco.first[34] == 401);
        UT_ASSERT_TRUE(crco.first[35] == 413);
        UT_ASSERT_TRUE(crco.first[36] == 421);
        UT_ASSERT_TRUE(crco.first[37] == 433);
        UT_ASSERT_TRUE(crco.first[38] == 438);
        UT_ASSERT_TRUE(crco.first[39] == 443);
        UT_ASSERT_TRUE(crco.first[40] == 444);
        UT_ASSERT_TRUE(crco.first[41] == 445);
        UT_ASSERT_TRUE(crco.first[42] == 458);
        UT_ASSERT_TRUE(crco.first[43] == 476);
        UT_ASSERT_TRUE(crco.first[44] == 496);

        crco = clauses_repr_clauses_of(cr, 22);
        UT_ASSERT_TRUE(crco.len == 35);
        UT_ASSERT_TRUE(crco.first[0] == 24);
        UT_ASSERT_TRUE(crco.first[1] == 26);
        UT_ASSERT_TRUE(crco.first[2] == 43);
        UT_ASSERT_TRUE(crco.first[3] == 59);
        UT_ASSERT_TRUE(crco.first[4] == 60);
        UT_ASSERT_TRUE(crco.first[5] == 64);
        UT_ASSERT_TRUE(crco.first[6] == 69);
        UT_ASSERT_TRUE(crco.first[7] == 72);
        UT_ASSERT_TRUE(crco.first[8] == 75);
        UT_ASSERT_TRUE(crco.first[9] == 102);
        UT_ASSERT_TRUE(crco.first[10] == 141);
        UT_ASSERT_TRUE(crco.first[11] == 190);
        UT_ASSERT_TRUE(crco.first[12] == 198);
        UT_ASSERT_TRUE(crco.first[13] == 204);
        UT_ASSERT_TRUE(crco.first[14] == 222);
        UT_ASSERT_TRUE(crco.first[15] == 224);
        UT_ASSERT_TRUE(crco.first[16] == 249);
        UT_ASSERT_TRUE(crco.first[17] == 269);
        UT_ASSERT_TRUE(crco.first[18] == 293);
        UT_ASSERT_TRUE(crco.first[19] == 307);
        UT_ASSERT_TRUE(crco.first[20] == 326);
        UT_ASSERT_TRUE(crco.first[21] == 327);
        UT_ASSERT_TRUE(crco.first[22] == 353);
        UT_ASSERT_TRUE(crco.first[23] == 357);
        UT_ASSERT_TRUE(crco.first[24] == 371);
        UT_ASSERT_TRUE(crco.first[25] == 397);
        UT_ASSERT_TRUE(crco.first[26] == 399);
        UT_ASSERT_TRUE(crco.first[27] == 427);
        UT_ASSERT_TRUE(crco.first[28] == 429);
        UT_ASSERT_TRUE(crco.first[29] == 437);
        UT_ASSERT_TRUE(crco.first[30] == 472);
        UT_ASSERT_TRUE(crco.first[31] == 475);
        UT_ASSERT_TRUE(crco.first[32] == 477);
        UT_ASSERT_TRUE(crco.first[33] == 489);
        UT_ASSERT_TRUE(crco.first[34] == 498);

        crco = clauses_repr_clauses_of(cr, 23);
        UT_ASSERT_TRUE(crco.len == 47);
        UT_ASSERT_TRUE(crco.first[0] == 8);
        UT_ASSERT_TRUE(crco.first[1] == 23);
        UT_ASSERT_TRUE(crco.first[2] == 25);
        UT_ASSERT_TRUE(crco.first[3] == 32);
        UT_ASSERT_TRUE(crco.first[4] == 34);
        UT_ASSERT_TRUE(crco.first[5] == 50);
        UT_ASSERT_TRUE(crco.first[6] == 60);
        UT_ASSERT_TRUE(crco.first[7] == 70);
        UT_ASSERT_TRUE(crco.first[8] == 71);
        UT_ASSERT_TRUE(crco.first[9] == 73);
        UT_ASSERT_TRUE(crco.first[10] == 78);
        UT_ASSERT_TRUE(crco.first[11] == 88);
        UT_ASSERT_TRUE(crco.first[12] == 93);
        UT_ASSERT_TRUE(crco.first[13] == 100);
        UT_ASSERT_TRUE(crco.first[14] == 106);
        UT_ASSERT_TRUE(crco.first[15] == 107);
        UT_ASSERT_TRUE(crco.first[16] == 115);
        UT_ASSERT_TRUE(crco.first[17] == 128);
        UT_ASSERT_TRUE(crco.first[18] == 144);
        UT_ASSERT_TRUE(crco.first[19] == 154);
        UT_ASSERT_TRUE(crco.first[20] == 180);
        UT_ASSERT_TRUE(crco.first[21] == 194);
        UT_ASSERT_TRUE(crco.first[22] == 205);
        UT_ASSERT_TRUE(crco.first[23] == 224);
        UT_ASSERT_TRUE(crco.first[24] == 238);
        UT_ASSERT_TRUE(crco.first[25] == 241);
        UT_ASSERT_TRUE(crco.first[26] == 242);
        UT_ASSERT_TRUE(crco.first[27] == 244);
        UT_ASSERT_TRUE(crco.first[28] == 286);
        UT_ASSERT_TRUE(crco.first[29] == 298);
        UT_ASSERT_TRUE(crco.first[30] == 318);
        UT_ASSERT_TRUE(crco.first[31] == 324);
        UT_ASSERT_TRUE(crco.first[32] == 325);
        UT_ASSERT_TRUE(crco.first[33] == 339);
        UT_ASSERT_TRUE(crco.first[34] == 345);
        UT_ASSERT_TRUE(crco.first[35] == 346);
        UT_ASSERT_TRUE(crco.first[36] == 352);
        UT_ASSERT_TRUE(crco.first[37] == 362);
        UT_ASSERT_TRUE(crco.first[38] == 368);
        UT_ASSERT_TRUE(crco.first[39] == 384);
        UT_ASSERT_TRUE(crco.first[40] == 417);
        UT_ASSERT_TRUE(crco.first[41] == 436);
        UT_ASSERT_TRUE(crco.first[42] == 449);
        UT_ASSERT_TRUE(crco.first[43] == 453);
        UT_ASSERT_TRUE(crco.first[44] == 463);
        UT_ASSERT_TRUE(crco.first[45] == 482);
        UT_ASSERT_TRUE(crco.first[46] == 489);

        crco = clauses_repr_clauses_of(cr, 24);
        UT_ASSERT_TRUE(crco.len == 43);
        UT_ASSERT_TRUE(crco.first[0] == 28);
        UT_ASSERT_TRUE(crco.first[1] == 30);
        UT_ASSERT_TRUE(crco.first[2] == 78);
        UT_ASSERT_TRUE(crco.first[3] == 80);
        UT_ASSERT_TRUE(crco.first[4] == 97);
        UT_ASSERT_TRUE(crco.first[5] == 109);
        UT_ASSERT_TRUE(crco.first[6] == 114);
        UT_ASSERT_TRUE(crco.first[7] == 117);
        UT_ASSERT_TRUE(crco.first[8] == 130);
        UT_ASSERT_TRUE(crco.first[9] == 145);
        UT_ASSERT_TRUE(crco.first[10] == 169);
        UT_ASSERT_TRUE(crco.first[11] == 174);
        UT_ASSERT_TRUE(crco.first[12] == 176);
        UT_ASSERT_TRUE(crco.first[13] == 205);
        UT_ASSERT_TRUE(crco.first[14] == 215);
        UT_ASSERT_TRUE(crco.first[15] == 229);
        UT_ASSERT_TRUE(crco.first[16] == 230);
        UT_ASSERT_TRUE(crco.first[17] == 270);
        UT_ASSERT_TRUE(crco.first[18] == 310);
        UT_ASSERT_TRUE(crco.first[19] == 315);
        UT_ASSERT_TRUE(crco.first[20] == 321);
        UT_ASSERT_TRUE(crco.first[21] == 343);
        UT_ASSERT_TRUE(crco.first[22] == 344);
        UT_ASSERT_TRUE(crco.first[23] == 357);
        UT_ASSERT_TRUE(crco.first[24] == 380);
        UT_ASSERT_TRUE(crco.first[25] == 384);
        UT_ASSERT_TRUE(crco.first[26] == 394);
        UT_ASSERT_TRUE(crco.first[27] == 395);
        UT_ASSERT_TRUE(crco.first[28] == 402);
        UT_ASSERT_TRUE(crco.first[29] == 406);
        UT_ASSERT_TRUE(crco.first[30] == 408);
        UT_ASSERT_TRUE(crco.first[31] == 409);
        UT_ASSERT_TRUE(crco.first[32] == 422);
        UT_ASSERT_TRUE(crco.first[33] == 429);
        UT_ASSERT_TRUE(crco.first[34] == 441);
        UT_ASSERT_TRUE(crco.first[35] == 448);
        UT_ASSERT_TRUE(crco.first[36] == 451);
        UT_ASSERT_TRUE(crco.first[37] == 461);
        UT_ASSERT_TRUE(crco.first[38] == 467);
        UT_ASSERT_TRUE(crco.first[39] == 488);
        UT_ASSERT_TRUE(crco.first[40] == 494);
        UT_ASSERT_TRUE(crco.first[41] == 495);
        UT_ASSERT_TRUE(crco.first[42] == 496);

        crco = clauses_repr_clauses_of(cr, 25);
        UT_ASSERT_TRUE(crco.len == 44);
        UT_ASSERT_TRUE(crco.first[0] == 20);
        UT_ASSERT_TRUE(crco.first[1] == 55);
        UT_ASSERT_TRUE(crco.first[2] == 66);
        UT_ASSERT_TRUE(crco.first[3] == 68);
        UT_ASSERT_TRUE(crco.first[4] == 75);
        UT_ASSERT_TRUE(crco.first[5] == 76);
        UT_ASSERT_TRUE(crco.first[6] == 82);
        UT_ASSERT_TRUE(crco.first[7] == 83);
        UT_ASSERT_TRUE(crco.first[8] == 84);
        UT_ASSERT_TRUE(crco.first[9] == 105);
        UT_ASSERT_TRUE(crco.first[10] == 106);
        UT_ASSERT_TRUE(crco.first[11] == 112);
        UT_ASSERT_TRUE(crco.first[12] == 113);
        UT_ASSERT_TRUE(crco.first[13] == 118);
        UT_ASSERT_TRUE(crco.first[14] == 122);
        UT_ASSERT_TRUE(crco.first[15] == 125);
        UT_ASSERT_TRUE(crco.first[16] == 138);
        UT_ASSERT_TRUE(crco.first[17] == 143);
        UT_ASSERT_TRUE(crco.first[18] == 149);
        UT_ASSERT_TRUE(crco.first[19] == 150);
        UT_ASSERT_TRUE(crco.first[20] == 151);
        UT_ASSERT_TRUE(crco.first[21] == 166);
        UT_ASSERT_TRUE(crco.first[22] == 185);
        UT_ASSERT_TRUE(crco.first[23] == 186);
        UT_ASSERT_TRUE(crco.first[24] == 188);
        UT_ASSERT_TRUE(crco.first[25] == 194);
        UT_ASSERT_TRUE(crco.first[26] == 213);
        UT_ASSERT_TRUE(crco.first[27] == 232);
        UT_ASSERT_TRUE(crco.first[28] == 233);
        UT_ASSERT_TRUE(crco.first[29] == 240);
        UT_ASSERT_TRUE(crco.first[30] == 253);
        UT_ASSERT_TRUE(crco.first[31] == 301);
        UT_ASSERT_TRUE(crco.first[32] == 349);
        UT_ASSERT_TRUE(crco.first[33] == 354);
        UT_ASSERT_TRUE(crco.first[34] == 363);
        UT_ASSERT_TRUE(crco.first[35] == 375);
        UT_ASSERT_TRUE(crco.first[36] == 385);
        UT_ASSERT_TRUE(crco.first[37] == 410);
        UT_ASSERT_TRUE(crco.first[38] == 420);
        UT_ASSERT_TRUE(crco.first[39] == 423);
        UT_ASSERT_TRUE(crco.first[40] == 428);
        UT_ASSERT_TRUE(crco.first[41] == 461);
        UT_ASSERT_TRUE(crco.first[42] == 471);
        UT_ASSERT_TRUE(crco.first[43] == 490);

        crco = clauses_repr_clauses_of(cr, 26);
        UT_ASSERT_TRUE(crco.len == 30);
        UT_ASSERT_TRUE(crco.first[0] == 87);
        UT_ASSERT_TRUE(crco.first[1] == 105);
        UT_ASSERT_TRUE(crco.first[2] == 124);
        UT_ASSERT_TRUE(crco.first[3] == 136);
        UT_ASSERT_TRUE(crco.first[4] == 163);
        UT_ASSERT_TRUE(crco.first[5] == 176);
        UT_ASSERT_TRUE(crco.first[6] == 181);
        UT_ASSERT_TRUE(crco.first[7] == 185);
        UT_ASSERT_TRUE(crco.first[8] == 193);
        UT_ASSERT_TRUE(crco.first[9] == 210);
        UT_ASSERT_TRUE(crco.first[10] == 218);
        UT_ASSERT_TRUE(crco.first[11] == 232);
        UT_ASSERT_TRUE(crco.first[12] == 244);
        UT_ASSERT_TRUE(crco.first[13] == 253);
        UT_ASSERT_TRUE(crco.first[14] == 270);
        UT_ASSERT_TRUE(crco.first[15] == 301);
        UT_ASSERT_TRUE(crco.first[16] == 309);
        UT_ASSERT_TRUE(crco.first[17] == 318);
        UT_ASSERT_TRUE(crco.first[18] == 360);
        UT_ASSERT_TRUE(crco.first[19] == 373);
        UT_ASSERT_TRUE(crco.first[20] == 378);
        UT_ASSERT_TRUE(crco.first[21] == 383);
        UT_ASSERT_TRUE(crco.first[22] == 392);
        UT_ASSERT_TRUE(crco.first[23] == 394);
        UT_ASSERT_TRUE(crco.first[24] == 406);
        UT_ASSERT_TRUE(crco.first[25] == 421);
        UT_ASSERT_TRUE(crco.first[26] == 430);
        UT_ASSERT_TRUE(crco.first[27] == 437);
        UT_ASSERT_TRUE(crco.first[28] == 456);
        UT_ASSERT_TRUE(crco.first[29] == 499);

        crco = clauses_repr_clauses_of(cr, 27);
        UT_ASSERT_TRUE(crco.len == 57);
        UT_ASSERT_TRUE(crco.first[0] == 0);
        UT_ASSERT_TRUE(crco.first[1] == 8);
        UT_ASSERT_TRUE(crco.first[2] == 13);
        UT_ASSERT_TRUE(crco.first[3] == 15);
        UT_ASSERT_TRUE(crco.first[4] == 21);
        UT_ASSERT_TRUE(crco.first[5] == 22);
        UT_ASSERT_TRUE(crco.first[6] == 23);
        UT_ASSERT_TRUE(crco.first[7] == 31);
        UT_ASSERT_TRUE(crco.first[8] == 47);
        UT_ASSERT_TRUE(crco.first[9] == 48);
        UT_ASSERT_TRUE(crco.first[10] == 50);
        UT_ASSERT_TRUE(crco.first[11] == 67);
        UT_ASSERT_TRUE(crco.first[12] == 78);
        UT_ASSERT_TRUE(crco.first[13] == 98);
        UT_ASSERT_TRUE(crco.first[14] == 111);
        UT_ASSERT_TRUE(crco.first[15] == 120);
        UT_ASSERT_TRUE(crco.first[16] == 133);
        UT_ASSERT_TRUE(crco.first[17] == 137);
        UT_ASSERT_TRUE(crco.first[18] == 142);
        UT_ASSERT_TRUE(crco.first[19] == 152);
        UT_ASSERT_TRUE(crco.first[20] == 156);
        UT_ASSERT_TRUE(crco.first[21] == 157);
        UT_ASSERT_TRUE(crco.first[22] == 168);
        UT_ASSERT_TRUE(crco.first[23] == 169);
        UT_ASSERT_TRUE(crco.first[24] == 191);
        UT_ASSERT_TRUE(crco.first[25] == 195);
        UT_ASSERT_TRUE(crco.first[26] == 201);
        UT_ASSERT_TRUE(crco.first[27] == 202);
        UT_ASSERT_TRUE(crco.first[28] == 213);
        UT_ASSERT_TRUE(crco.first[29] == 214);
        UT_ASSERT_TRUE(crco.first[30] == 218);
        UT_ASSERT_TRUE(crco.first[31] == 229);
        UT_ASSERT_TRUE(crco.first[32] == 244);
        UT_ASSERT_TRUE(crco.first[33] == 256);
        UT_ASSERT_TRUE(crco.first[34] == 258);
        UT_ASSERT_TRUE(crco.first[35] == 263);
        UT_ASSERT_TRUE(crco.first[36] == 276);
        UT_ASSERT_TRUE(crco.first[37] == 286);
        UT_ASSERT_TRUE(crco.first[38] == 288);
        UT_ASSERT_TRUE(crco.first[39] == 299);
        UT_ASSERT_TRUE(crco.first[40] == 300);
        UT_ASSERT_TRUE(crco.first[41] == 302);
        UT_ASSERT_TRUE(crco.first[42] == 331);
        UT_ASSERT_TRUE(crco.first[43] == 339);
        UT_ASSERT_TRUE(crco.first[44] == 340);
        UT_ASSERT_TRUE(crco.first[45] == 347);
        UT_ASSERT_TRUE(crco.first[46] == 365);
        UT_ASSERT_TRUE(crco.first[47] == 370);
        UT_ASSERT_TRUE(crco.first[48] == 374);
        UT_ASSERT_TRUE(crco.first[49] == 383);
        UT_ASSERT_TRUE(crco.first[50] == 388);
        UT_ASSERT_TRUE(crco.first[51] == 420);
        UT_ASSERT_TRUE(crco.first[52] == 430);
        UT_ASSERT_TRUE(crco.first[53] == 438);
        UT_ASSERT_TRUE(crco.first[54] == 479);
        UT_ASSERT_TRUE(crco.first[55] == 481);
        UT_ASSERT_TRUE(crco.first[56] == 492);

        crco = clauses_repr_clauses_of(cr, 28);
        UT_ASSERT_TRUE(crco.len == 31);
        UT_ASSERT_TRUE(crco.first[0] == 2);
        UT_ASSERT_TRUE(crco.first[1] == 10);
        UT_ASSERT_TRUE(crco.first[2] == 26);
        UT_ASSERT_TRUE(crco.first[3] == 27);
        UT_ASSERT_TRUE(crco.first[4] == 44);
        UT_ASSERT_TRUE(crco.first[5] == 66);
        UT_ASSERT_TRUE(crco.first[6] == 70);
        UT_ASSERT_TRUE(crco.first[7] == 75);
        UT_ASSERT_TRUE(crco.first[8] == 90);
        UT_ASSERT_TRUE(crco.first[9] == 120);
        UT_ASSERT_TRUE(crco.first[10] == 132);
        UT_ASSERT_TRUE(crco.first[11] == 152);
        UT_ASSERT_TRUE(crco.first[12] == 171);
        UT_ASSERT_TRUE(crco.first[13] == 203);
        UT_ASSERT_TRUE(crco.first[14] == 211);
        UT_ASSERT_TRUE(crco.first[15] == 258);
        UT_ASSERT_TRUE(crco.first[16] == 268);
        UT_ASSERT_TRUE(crco.first[17] == 281);
        UT_ASSERT_TRUE(crco.first[18] == 287);
        UT_ASSERT_TRUE(crco.first[19] == 288);
        UT_ASSERT_TRUE(crco.first[20] == 292);
        UT_ASSERT_TRUE(crco.first[21] == 297);
        UT_ASSERT_TRUE(crco.first[22] == 337);
        UT_ASSERT_TRUE(crco.first[23] == 369);
        UT_ASSERT_TRUE(crco.first[24] == 381);
        UT_ASSERT_TRUE(crco.first[25] == 390);
        UT_ASSERT_TRUE(crco.first[26] == 410);
        UT_ASSERT_TRUE(crco.first[27] == 436);
        UT_ASSERT_TRUE(crco.first[28] == 437);
        UT_ASSERT_TRUE(crco.first[29] == 449);
        UT_ASSERT_TRUE(crco.first[30] == 469);

        crco = clauses_repr_clauses_of(cr, 29);
        UT_ASSERT_TRUE(crco.len == 51);
        UT_ASSERT_TRUE(crco.first[0] == 1);
        UT_ASSERT_TRUE(crco.first[1] == 3);
        UT_ASSERT_TRUE(crco.first[2] == 15);
        UT_ASSERT_TRUE(crco.first[3] == 23);
        UT_ASSERT_TRUE(crco.first[4] == 29);
        UT_ASSERT_TRUE(crco.first[5] == 67);
        UT_ASSERT_TRUE(crco.first[6] == 81);
        UT_ASSERT_TRUE(crco.first[7] == 94);
        UT_ASSERT_TRUE(crco.first[8] == 121);
        UT_ASSERT_TRUE(crco.first[9] == 123);
        UT_ASSERT_TRUE(crco.first[10] == 129);
        UT_ASSERT_TRUE(crco.first[11] == 130);
        UT_ASSERT_TRUE(crco.first[12] == 198);
        UT_ASSERT_TRUE(crco.first[13] == 206);
        UT_ASSERT_TRUE(crco.first[14] == 216);
        UT_ASSERT_TRUE(crco.first[15] == 230);
        UT_ASSERT_TRUE(crco.first[16] == 235);
        UT_ASSERT_TRUE(crco.first[17] == 237);
        UT_ASSERT_TRUE(crco.first[18] == 239);
        UT_ASSERT_TRUE(crco.first[19] == 247);
        UT_ASSERT_TRUE(crco.first[20] == 259);
        UT_ASSERT_TRUE(crco.first[21] == 265);
        UT_ASSERT_TRUE(crco.first[22] == 266);
        UT_ASSERT_TRUE(crco.first[23] == 277);
        UT_ASSERT_TRUE(crco.first[24] == 289);
        UT_ASSERT_TRUE(crco.first[25] == 291);
        UT_ASSERT_TRUE(crco.first[26] == 300);
        UT_ASSERT_TRUE(crco.first[27] == 304);
        UT_ASSERT_TRUE(crco.first[28] == 306);
        UT_ASSERT_TRUE(crco.first[29] == 323);
        UT_ASSERT_TRUE(crco.first[30] == 327);
        UT_ASSERT_TRUE(crco.first[31] == 338);
        UT_ASSERT_TRUE(crco.first[32] == 342);
        UT_ASSERT_TRUE(crco.first[33] == 361);
        UT_ASSERT_TRUE(crco.first[34] == 362);
        UT_ASSERT_TRUE(crco.first[35] == 363);
        UT_ASSERT_TRUE(crco.first[36] == 382);
        UT_ASSERT_TRUE(crco.first[37] == 385);
        UT_ASSERT_TRUE(crco.first[38] == 392);
        UT_ASSERT_TRUE(crco.first[39] == 396);
        UT_ASSERT_TRUE(crco.first[40] == 397);
        UT_ASSERT_TRUE(crco.first[41] == 403);
        UT_ASSERT_TRUE(crco.first[42] == 411);
        UT_ASSERT_TRUE(crco.first[43] == 416);
        UT_ASSERT_TRUE(crco.first[44] == 426);
        UT_ASSERT_TRUE(crco.first[45] == 442);
        UT_ASSERT_TRUE(crco.first[46] == 447);
        UT_ASSERT_TRUE(crco.first[47] == 464);
        UT_ASSERT_TRUE(crco.first[48] == 470);
        UT_ASSERT_TRUE(crco.first[49] == 472);
        UT_ASSERT_TRUE(crco.first[50] == 491);

        crco = clauses_repr_clauses_of(cr, 30);
        UT_ASSERT_TRUE(crco.len == 34);
        UT_ASSERT_TRUE(crco.first[0] == 9);
        UT_ASSERT_TRUE(crco.first[1] == 15);
        UT_ASSERT_TRUE(crco.first[2] == 34);
        UT_ASSERT_TRUE(crco.first[3] == 44);
        UT_ASSERT_TRUE(crco.first[4] == 48);
        UT_ASSERT_TRUE(crco.first[5] == 52);
        UT_ASSERT_TRUE(crco.first[6] == 61);
        UT_ASSERT_TRUE(crco.first[7] == 62);
        UT_ASSERT_TRUE(crco.first[8] == 71);
        UT_ASSERT_TRUE(crco.first[9] == 72);
        UT_ASSERT_TRUE(crco.first[10] == 108);
        UT_ASSERT_TRUE(crco.first[11] == 113);
        UT_ASSERT_TRUE(crco.first[12] == 140);
        UT_ASSERT_TRUE(crco.first[13] == 144);
        UT_ASSERT_TRUE(crco.first[14] == 146);
        UT_ASSERT_TRUE(crco.first[15] == 179);
        UT_ASSERT_TRUE(crco.first[16] == 207);
        UT_ASSERT_TRUE(crco.first[17] == 237);
        UT_ASSERT_TRUE(crco.first[18] == 308);
        UT_ASSERT_TRUE(crco.first[19] == 338);
        UT_ASSERT_TRUE(crco.first[20] == 346);
        UT_ASSERT_TRUE(crco.first[21] == 353);
        UT_ASSERT_TRUE(crco.first[22] == 365);
        UT_ASSERT_TRUE(crco.first[23] == 370);
        UT_ASSERT_TRUE(crco.first[24] == 395);
        UT_ASSERT_TRUE(crco.first[25] == 411);
        UT_ASSERT_TRUE(crco.first[26] == 415);
        UT_ASSERT_TRUE(crco.first[27] == 434);
        UT_ASSERT_TRUE(crco.first[28] == 435);
        UT_ASSERT_TRUE(crco.first[29] == 442);
        UT_ASSERT_TRUE(crco.first[30] == 451);
        UT_ASSERT_TRUE(crco.first[31] == 453);
        UT_ASSERT_TRUE(crco.first[32] == 475);
        UT_ASSERT_TRUE(crco.first[33] == 477);
    }

    free_clauses_repr(cr);
    return 0;
}

UT_TEST(ex5) {
    struct new_clauses_repr_from_file ret = new_clauses_repr_from_file("test/ex5.in");
    UT_ASSERT_TRUE(ret.success);
    struct clauses_repr *cr = ret.clauses_repr;
    UT_ASSERT_TRUE(clauses_repr_num_vars(cr) == 30);
    UT_ASSERT_TRUE(clauses_repr_num_clauses(cr) == 500);

    {
        struct clauses_repr_clause crc;
        crc = clauses_repr_clause(cr, 0);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 1);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 2);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 3);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == 10);

        crc = clauses_repr_clause(cr, 4);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == 27);

        crc = clauses_repr_clause(cr, 5);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 6);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == 27);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 7);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 8);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 28);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 9);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 10);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == -26);

        crc = clauses_repr_clause(cr, 11);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 12);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -29);

        crc = clauses_repr_clause(cr, 13);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 30);

        crc = clauses_repr_clause(cr, 14);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -29);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 15);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -26);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 16);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 17);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 18);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 19);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 20);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 21);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 22);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -26);

        crc = clauses_repr_clause(cr, 23);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 26);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 24);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 25);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 26);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == -30);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 27);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 25);
        UT_ASSERT_TRUE(crc.first[2] == 10);

        crc = clauses_repr_clause(cr, 28);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 29);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 30);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == 30);

        crc = clauses_repr_clause(cr, 31);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 32);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -30);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 33);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 34);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 35);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 36);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 37);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 38);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 39);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == 25);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 40);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 41);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 42);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == 14);

        crc = clauses_repr_clause(cr, 43);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 44);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 45);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 46);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == 29);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 47);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == -19);

        crc = clauses_repr_clause(cr, 48);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 49);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 50);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 51);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 52);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 53);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 54);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 55);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == 10);

        crc = clauses_repr_clause(cr, 56);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -28);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 57);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == 28);
        UT_ASSERT_TRUE(crc.first[2] == 26);

        crc = clauses_repr_clause(cr, 58);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 25);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 59);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 60);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == 26);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 61);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 62);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -30);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 63);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 64);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 65);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == 29);

        crc = clauses_repr_clause(cr, 66);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 67);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 68);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -30);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 69);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == 29);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 70);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == 26);

        crc = clauses_repr_clause(cr, 71);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 72);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == -26);

        crc = clauses_repr_clause(cr, 73);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == 29);

        crc = clauses_repr_clause(cr, 74);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 75);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 76);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == -30);

        crc = clauses_repr_clause(cr, 77);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 78);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 79);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == 28);
        UT_ASSERT_TRUE(crc.first[2] == 14);

        crc = clauses_repr_clause(cr, 80);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 81);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 28);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == -30);

        crc = clauses_repr_clause(cr, 82);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 83);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 84);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 85);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 86);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == -26);

        crc = clauses_repr_clause(cr, 87);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 88);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == -1);

        crc = clauses_repr_clause(cr, 89);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 90);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 91);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 92);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 93);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 94);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 95);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 96);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 97);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 98);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 99);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 100);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 101);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 102);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 103);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 104);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 105);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 106);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == -8);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 107);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 108);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 109);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 110);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 111);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 112);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -29);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 113);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -30);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 114);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 115);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -29);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 116);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == -29);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 117);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -30);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 118);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 119);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 120);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 121);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 122);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 123);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 124);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == -19);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 125);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 126);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 127);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 28);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 128);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 129);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 130);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 131);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -28);
        UT_ASSERT_TRUE(crc.first[1] == 25);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 132);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == 30);

        crc = clauses_repr_clause(cr, 133);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 134);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 135);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 136);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 137);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -30);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 138);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 139);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 140);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == 25);
        UT_ASSERT_TRUE(crc.first[2] == -30);

        crc = clauses_repr_clause(cr, 141);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 142);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 143);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 144);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -28);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 145);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 146);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == -26);

        crc = clauses_repr_clause(cr, 147);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 148);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == 17);

        crc = clauses_repr_clause(cr, 149);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 150);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == 26);

        crc = clauses_repr_clause(cr, 151);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 152);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == -19);

        crc = clauses_repr_clause(cr, 153);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -30);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 154);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 155);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 156);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == 30);

        crc = clauses_repr_clause(cr, 157);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 158);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 159);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 28);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 160);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 161);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 162);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 163);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == -26);

        crc = clauses_repr_clause(cr, 164);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == -22);
        UT_ASSERT_TRUE(crc.first[2] == -27);

        crc = clauses_repr_clause(cr, 165);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 166);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -19);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 167);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == 26);

        crc = clauses_repr_clause(cr, 168);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 169);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 17);

        crc = clauses_repr_clause(cr, 170);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == 17);

        crc = clauses_repr_clause(cr, 171);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 172);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == 28);

        crc = clauses_repr_clause(cr, 173);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -29);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 174);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 175);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 176);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 29);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 177);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 178);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 179);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -30);

        crc = clauses_repr_clause(cr, 180);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 28);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 181);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -29);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 182);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 183);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 184);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 185);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 186);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 187);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 188);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == 29);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 189);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 190);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == 25);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 191);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 27);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 192);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == 1);
        UT_ASSERT_TRUE(crc.first[2] == 17);

        crc = clauses_repr_clause(cr, 193);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 194);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 195);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == -27);

        crc = clauses_repr_clause(cr, 196);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 197);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 198);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == 28);

        crc = clauses_repr_clause(cr, 199);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 29);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 200);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 201);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 202);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 203);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == 10);

        crc = clauses_repr_clause(cr, 204);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 205);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == 28);

        crc = clauses_repr_clause(cr, 206);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 207);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 208);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 209);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -29);

        crc = clauses_repr_clause(cr, 210);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == -19);

        crc = clauses_repr_clause(cr, 211);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 212);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 213);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == 4);

        crc = clauses_repr_clause(cr, 214);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 215);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 216);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 217);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 218);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 219);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 220);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 221);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == -8);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 222);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 223);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 224);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == 28);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 225);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -29);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 226);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 25);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 227);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == -8);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 228);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 229);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 230);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 231);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 232);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -29);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 233);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 30);

        crc = clauses_repr_clause(cr, 234);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == -19);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 235);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -28);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 236);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == -27);

        crc = clauses_repr_clause(cr, 237);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 238);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 239);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == 14);

        crc = clauses_repr_clause(cr, 240);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 241);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 242);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 30);
        UT_ASSERT_TRUE(crc.first[1] == 27);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 243);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == 6);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 244);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == 29);

        crc = clauses_repr_clause(cr, 245);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 246);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -29);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 247);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == 30);

        crc = clauses_repr_clause(cr, 248);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 249);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 250);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 251);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 252);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 253);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 254);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == -29);

        crc = clauses_repr_clause(cr, 255);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == 29);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 256);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 257);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 258);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 259);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 260);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 261);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 30);

        crc = clauses_repr_clause(cr, 262);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 263);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 264);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 265);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 266);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 267);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -26);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 268);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 269);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == -26);

        crc = clauses_repr_clause(cr, 270);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 271);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 30);
        UT_ASSERT_TRUE(crc.first[1] == 26);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 272);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 273);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == -29);

        crc = clauses_repr_clause(cr, 274);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 275);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 276);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 277);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 278);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 279);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 280);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == -30);

        crc = clauses_repr_clause(cr, 281);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 282);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 283);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -30);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 284);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -30);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 285);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 286);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 287);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 288);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == 26);

        crc = clauses_repr_clause(cr, 289);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 290);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 291);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 26);
        UT_ASSERT_TRUE(crc.first[2] == 8);

        crc = clauses_repr_clause(cr, 292);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -28);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 293);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 294);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 295);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == -1);

        crc = clauses_repr_clause(cr, 296);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 297);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -29);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 298);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == -28);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 299);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == 26);

        crc = clauses_repr_clause(cr, 300);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == 28);

        crc = clauses_repr_clause(cr, 301);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 302);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 303);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == -28);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 304);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 305);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 306);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 307);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 308);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 309);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 310);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == -29);

        crc = clauses_repr_clause(cr, 311);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == 29);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 312);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 313);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 314);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 315);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 316);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 317);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == -22);
        UT_ASSERT_TRUE(crc.first[2] == -8);

        crc = clauses_repr_clause(cr, 318);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 319);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 320);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 321);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -2);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == -29);

        crc = clauses_repr_clause(cr, 322);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 26);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 323);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 324);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == -27);

        crc = clauses_repr_clause(cr, 325);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -30);

        crc = clauses_repr_clause(cr, 326);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -30);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 327);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 328);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == -29);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 329);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == 29);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 330);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 331);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 332);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 30);
        UT_ASSERT_TRUE(crc.first[1] == -28);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 333);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 334);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 335);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 336);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 28);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 337);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 338);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -28);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 339);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == -23);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 340);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == -16);

        crc = clauses_repr_clause(cr, 341);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 26);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 342);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 343);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -29);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 344);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == -26);

        crc = clauses_repr_clause(cr, 345);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 346);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 347);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 30);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 348);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 349);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -27);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == -1);

        crc = clauses_repr_clause(cr, 350);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == -30);

        crc = clauses_repr_clause(cr, 351);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -29);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 352);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 353);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 354);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 355);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -26);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == -15);

        crc = clauses_repr_clause(cr, 356);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 357);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == 8);

        crc = clauses_repr_clause(cr, 358);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 359);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 360);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == 25);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 361);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == -28);
        UT_ASSERT_TRUE(crc.first[2] == 14);

        crc = clauses_repr_clause(cr, 362);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == -19);

        crc = clauses_repr_clause(cr, 363);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 364);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 365);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == 26);

        crc = clauses_repr_clause(cr, 366);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 367);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 368);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == 28);

        crc = clauses_repr_clause(cr, 369);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == 21);

        crc = clauses_repr_clause(cr, 370);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == 30);

        crc = clauses_repr_clause(cr, 371);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -27);

        crc = clauses_repr_clause(cr, 372);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 373);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 374);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 375);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 376);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 11);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 377);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 378);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 379);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 23);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 380);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 30);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 381);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 6);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 382);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == 26);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 383);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 3);
        UT_ASSERT_TRUE(crc.first[1] == -14);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 384);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -20);

        crc = clauses_repr_clause(cr, 385);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 26);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 386);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 387);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -30);
        UT_ASSERT_TRUE(crc.first[1] == 21);
        UT_ASSERT_TRUE(crc.first[2] == -12);

        crc = clauses_repr_clause(cr, 388);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == -5);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 389);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 25);
        UT_ASSERT_TRUE(crc.first[2] == 6);

        crc = clauses_repr_clause(cr, 390);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 28);

        crc = clauses_repr_clause(cr, 391);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 392);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == 30);

        crc = clauses_repr_clause(cr, 393);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 394);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == -19);

        crc = clauses_repr_clause(cr, 395);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == 30);

        crc = clauses_repr_clause(cr, 396);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == -8);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 397);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == -5);

        crc = clauses_repr_clause(cr, 398);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -19);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 399);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 14);
        UT_ASSERT_TRUE(crc.first[1] == 27);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 400);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 401);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -5);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == -11);

        crc = clauses_repr_clause(cr, 402);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == 26);
        UT_ASSERT_TRUE(crc.first[2] == -9);

        crc = clauses_repr_clause(cr, 403);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 404);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == 8);

        crc = clauses_repr_clause(cr, 405);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == 3);
        UT_ASSERT_TRUE(crc.first[2] == 24);

        crc = clauses_repr_clause(cr, 406);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -19);
        UT_ASSERT_TRUE(crc.first[1] == -8);
        UT_ASSERT_TRUE(crc.first[2] == -17);

        crc = clauses_repr_clause(cr, 407);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 408);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == 30);
        UT_ASSERT_TRUE(crc.first[2] == 28);

        crc = clauses_repr_clause(cr, 409);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 28);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 410);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == -10);
        UT_ASSERT_TRUE(crc.first[2] == -18);

        crc = clauses_repr_clause(cr, 411);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == -27);

        crc = clauses_repr_clause(cr, 412);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 413);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -1);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == 22);

        crc = clauses_repr_clause(cr, 414);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == 27);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 415);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == -18);
        UT_ASSERT_TRUE(crc.first[2] == -4);

        crc = clauses_repr_clause(cr, 416);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -20);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == 17);

        crc = clauses_repr_clause(cr, 417);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 5);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == -26);

        crc = clauses_repr_clause(cr, 418);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 4);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == 10);

        crc = clauses_repr_clause(cr, 419);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == -20);
        UT_ASSERT_TRUE(crc.first[2] == 17);

        crc = clauses_repr_clause(cr, 420);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 8);
        UT_ASSERT_TRUE(crc.first[2] == 15);

        crc = clauses_repr_clause(cr, 421);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -13);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == -26);

        crc = clauses_repr_clause(cr, 422);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 28);
        UT_ASSERT_TRUE(crc.first[2] == 23);

        crc = clauses_repr_clause(cr, 423);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 26);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == -30);

        crc = clauses_repr_clause(cr, 424);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == 12);

        crc = clauses_repr_clause(cr, 425);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == 10);

        crc = clauses_repr_clause(cr, 426);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 427);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -26);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == -30);

        crc = clauses_repr_clause(cr, 428);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 429);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 430);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 28);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == -30);

        crc = clauses_repr_clause(cr, 431);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 23);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == -19);

        crc = clauses_repr_clause(cr, 432);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == 24);
        UT_ASSERT_TRUE(crc.first[2] == -30);

        crc = clauses_repr_clause(cr, 433);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 1);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == -3);

        crc = clauses_repr_clause(cr, 434);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 10);
        UT_ASSERT_TRUE(crc.first[2] == 26);

        crc = clauses_repr_clause(cr, 435);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 436);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 12);
        UT_ASSERT_TRUE(crc.first[1] == 4);
        UT_ASSERT_TRUE(crc.first[2] == -27);

        crc = clauses_repr_clause(cr, 437);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 19);
        UT_ASSERT_TRUE(crc.first[1] == -6);
        UT_ASSERT_TRUE(crc.first[2] == 18);

        crc = clauses_repr_clause(cr, 438);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -3);
        UT_ASSERT_TRUE(crc.first[2] == -13);

        crc = clauses_repr_clause(cr, 439);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == -26);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 440);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -16);
        UT_ASSERT_TRUE(crc.first[1] == -17);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 441);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 30);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 442);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -10);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 443);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == 8);

        crc = clauses_repr_clause(cr, 444);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == -7);
        UT_ASSERT_TRUE(crc.first[2] == -2);

        crc = clauses_repr_clause(cr, 445);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 8);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 446);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 447);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -28);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == 8);

        crc = clauses_repr_clause(cr, 448);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -21);
        UT_ASSERT_TRUE(crc.first[1] == -24);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 449);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 450);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == 9);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 451);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 24);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 452);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 453);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == -22);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 454);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -30);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 455);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == 27);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 456);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 22);
        UT_ASSERT_TRUE(crc.first[1] == 19);
        UT_ASSERT_TRUE(crc.first[2] == -23);

        crc = clauses_repr_clause(cr, 457);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == 7);
        UT_ASSERT_TRUE(crc.first[2] == 28);

        crc = clauses_repr_clause(cr, 458);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 17);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == 3);

        crc = clauses_repr_clause(cr, 459);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == 17);

        crc = clauses_repr_clause(cr, 460);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == -1);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 461);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -25);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == 26);

        crc = clauses_repr_clause(cr, 462);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == 14);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 463);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == 22);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 464);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == -8);
        UT_ASSERT_TRUE(crc.first[2] == 7);

        crc = clauses_repr_clause(cr, 465);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 13);
        UT_ASSERT_TRUE(crc.first[1] == 11);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 466);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -22);
        UT_ASSERT_TRUE(crc.first[1] == -30);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 467);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == 26);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 468);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -9);
        UT_ASSERT_TRUE(crc.first[1] == 18);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 469);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 7);
        UT_ASSERT_TRUE(crc.first[1] == 27);
        UT_ASSERT_TRUE(crc.first[2] == -6);

        crc = clauses_repr_clause(cr, 470);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -14);
        UT_ASSERT_TRUE(crc.first[1] == -16);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 471);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 16);
        UT_ASSERT_TRUE(crc.first[1] == 20);
        UT_ASSERT_TRUE(crc.first[2] == -10);

        crc = clauses_repr_clause(cr, 472);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == -25);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 473);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -29);
        UT_ASSERT_TRUE(crc.first[1] == -11);
        UT_ASSERT_TRUE(crc.first[2] == -27);

        crc = clauses_repr_clause(cr, 474);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -30);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 475);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 29);
        UT_ASSERT_TRUE(crc.first[1] == -12);
        UT_ASSERT_TRUE(crc.first[2] == -30);

        crc = clauses_repr_clause(cr, 476);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 18);
        UT_ASSERT_TRUE(crc.first[1] == -4);
        UT_ASSERT_TRUE(crc.first[2] == -27);

        crc = clauses_repr_clause(cr, 477);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -7);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == 11);

        crc = clauses_repr_clause(cr, 478);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -11);
        UT_ASSERT_TRUE(crc.first[1] == 16);
        UT_ASSERT_TRUE(crc.first[2] == 2);

        crc = clauses_repr_clause(cr, 479);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 10);
        UT_ASSERT_TRUE(crc.first[1] == 13);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 480);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 2);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == -27);

        crc = clauses_repr_clause(cr, 481);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 27);
        UT_ASSERT_TRUE(crc.first[1] == -22);
        UT_ASSERT_TRUE(crc.first[2] == 13);

        crc = clauses_repr_clause(cr, 482);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -18);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -14);

        crc = clauses_repr_clause(cr, 483);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -28);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == -24);

        crc = clauses_repr_clause(cr, 484);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -3);
        UT_ASSERT_TRUE(crc.first[1] == 5);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 485);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 486);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -6);
        UT_ASSERT_TRUE(crc.first[1] == -15);
        UT_ASSERT_TRUE(crc.first[2] == 16);

        crc = clauses_repr_clause(cr, 487);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 21);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == 14);

        crc = clauses_repr_clause(cr, 488);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -26);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == 19);

        crc = clauses_repr_clause(cr, 489);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -24);
        UT_ASSERT_TRUE(crc.first[1] == 25);
        UT_ASSERT_TRUE(crc.first[2] == 20);

        crc = clauses_repr_clause(cr, 490);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -15);
        UT_ASSERT_TRUE(crc.first[1] == 12);
        UT_ASSERT_TRUE(crc.first[2] == 5);

        crc = clauses_repr_clause(cr, 491);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 15);
        UT_ASSERT_TRUE(crc.first[1] == -21);
        UT_ASSERT_TRUE(crc.first[2] == -28);

        crc = clauses_repr_clause(cr, 492);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == -9);
        UT_ASSERT_TRUE(crc.first[2] == -22);

        crc = clauses_repr_clause(cr, 493);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 20);
        UT_ASSERT_TRUE(crc.first[1] == 17);
        UT_ASSERT_TRUE(crc.first[2] == -7);

        crc = clauses_repr_clause(cr, 494);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -4);
        UT_ASSERT_TRUE(crc.first[1] == 2);
        UT_ASSERT_TRUE(crc.first[2] == 9);

        crc = clauses_repr_clause(cr, 495);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == 9);
        UT_ASSERT_TRUE(crc.first[1] == 15);
        UT_ASSERT_TRUE(crc.first[2] == -25);

        crc = clauses_repr_clause(cr, 496);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -23);
        UT_ASSERT_TRUE(crc.first[1] == 29);
        UT_ASSERT_TRUE(crc.first[2] == -21);

        crc = clauses_repr_clause(cr, 497);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -8);
        UT_ASSERT_TRUE(crc.first[1] == -2);
        UT_ASSERT_TRUE(crc.first[2] == 25);

        crc = clauses_repr_clause(cr, 498);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -17);
        UT_ASSERT_TRUE(crc.first[1] == -13);
        UT_ASSERT_TRUE(crc.first[2] == 1);

        crc = clauses_repr_clause(cr, 499);
        UT_ASSERT_TRUE(crc.len == 3);
        UT_ASSERT_TRUE(crc.first[0] == -12);
        UT_ASSERT_TRUE(crc.first[1] == -27);
        UT_ASSERT_TRUE(crc.first[2] == 9);

    }
    {
        struct  clauses_repr_clauses_of crco;
        crco = clauses_repr_clauses_of(cr, 0);
        UT_ASSERT_TRUE(crco.len == 0);

        crco = clauses_repr_clauses_of(cr, 1);
        UT_ASSERT_TRUE(crco.len == 48);
        UT_ASSERT_TRUE(crco.first[0] == 1);
        UT_ASSERT_TRUE(crco.first[1] == 17);
        UT_ASSERT_TRUE(crco.first[2] == 21);
        UT_ASSERT_TRUE(crco.first[3] == 23);
        UT_ASSERT_TRUE(crco.first[4] == 39);
        UT_ASSERT_TRUE(crco.first[5] == 48);
        UT_ASSERT_TRUE(crco.first[6] == 51);
        UT_ASSERT_TRUE(crco.first[7] == 62);
        UT_ASSERT_TRUE(crco.first[8] == 68);
        UT_ASSERT_TRUE(crco.first[9] == 82);
        UT_ASSERT_TRUE(crco.first[10] == 88);
        UT_ASSERT_TRUE(crco.first[11] == 94);
        UT_ASSERT_TRUE(crco.first[12] == 98);
        UT_ASSERT_TRUE(crco.first[13] == 99);
        UT_ASSERT_TRUE(crco.first[14] == 101);
        UT_ASSERT_TRUE(crco.first[15] == 105);
        UT_ASSERT_TRUE(crco.first[16] == 122);
        UT_ASSERT_TRUE(crco.first[17] == 139);
        UT_ASSERT_TRUE(crco.first[18] == 147);
        UT_ASSERT_TRUE(crco.first[19] == 166);
        UT_ASSERT_TRUE(crco.first[20] == 172);
        UT_ASSERT_TRUE(crco.first[21] == 192);
        UT_ASSERT_TRUE(crco.first[22] == 194);
        UT_ASSERT_TRUE(crco.first[23] == 198);
        UT_ASSERT_TRUE(crco.first[24] == 221);
        UT_ASSERT_TRUE(crco.first[25] == 236);
        UT_ASSERT_TRUE(crco.first[26] == 278);
        UT_ASSERT_TRUE(crco.first[27] == 280);
        UT_ASSERT_TRUE(crco.first[28] == 287);
        UT_ASSERT_TRUE(crco.first[29] == 292);
        UT_ASSERT_TRUE(crco.first[30] == 293);
        UT_ASSERT_TRUE(crco.first[31] == 295);
        UT_ASSERT_TRUE(crco.first[32] == 309);
        UT_ASSERT_TRUE(crco.first[33] == 311);
        UT_ASSERT_TRUE(crco.first[34] == 319);
        UT_ASSERT_TRUE(crco.first[35] == 349);
        UT_ASSERT_TRUE(crco.first[36] == 351);
        UT_ASSERT_TRUE(crco.first[37] == 353);
        UT_ASSERT_TRUE(crco.first[38] == 393);
        UT_ASSERT_TRUE(crco.first[39] == 400);
        UT_ASSERT_TRUE(crco.first[40] == 408);
        UT_ASSERT_TRUE(crco.first[41] == 413);
        UT_ASSERT_TRUE(crco.first[42] == 426);
        UT_ASSERT_TRUE(crco.first[43] == 433);
        UT_ASSERT_TRUE(crco.first[44] == 442);
        UT_ASSERT_TRUE(crco.first[45] == 460);
        UT_ASSERT_TRUE(crco.first[46] == 467);
        UT_ASSERT_TRUE(crco.first[47] == 498);

        crco = clauses_repr_clauses_of(cr, 2);
        UT_ASSERT_TRUE(crco.len == 61);
        UT_ASSERT_TRUE(crco.first[0] == 1);
        UT_ASSERT_TRUE(crco.first[1] == 5);
        UT_ASSERT_TRUE(crco.first[2] == 20);
        UT_ASSERT_TRUE(crco.first[3] == 48);
        UT_ASSERT_TRUE(crco.first[4] == 50);
        UT_ASSERT_TRUE(crco.first[5] == 51);
        UT_ASSERT_TRUE(crco.first[6] == 52);
        UT_ASSERT_TRUE(crco.first[7] == 63);
        UT_ASSERT_TRUE(crco.first[8] == 81);
        UT_ASSERT_TRUE(crco.first[9] == 90);
        UT_ASSERT_TRUE(crco.first[10] == 93);
        UT_ASSERT_TRUE(crco.first[11] == 96);
        UT_ASSERT_TRUE(crco.first[12] == 102);
        UT_ASSERT_TRUE(crco.first[13] == 111);
        UT_ASSERT_TRUE(crco.first[14] == 115);
        UT_ASSERT_TRUE(crco.first[15] == 120);
        UT_ASSERT_TRUE(crco.first[16] == 129);
        UT_ASSERT_TRUE(crco.first[17] == 160);
        UT_ASSERT_TRUE(crco.first[18] == 162);
        UT_ASSERT_TRUE(crco.first[19] == 171);
        UT_ASSERT_TRUE(crco.first[20] == 177);
        UT_ASSERT_TRUE(crco.first[21] == 180);
        UT_ASSERT_TRUE(crco.first[22] == 186);
        UT_ASSERT_TRUE(crco.first[23] == 199);
        UT_ASSERT_TRUE(crco.first[24] == 200);
        UT_ASSERT_TRUE(crco.first[25] == 206);
        UT_ASSERT_TRUE(crco.first[26] == 216);
        UT_ASSERT_TRUE(crco.first[27] == 222);
        UT_ASSERT_TRUE(crco.first[28] == 224);
        UT_ASSERT_TRUE(crco.first[29] == 277);
        UT_ASSERT_TRUE(crco.first[30] == 283);
        UT_ASSERT_TRUE(crco.first[31] == 288);
        UT_ASSERT_TRUE(crco.first[32] == 289);
        UT_ASSERT_TRUE(crco.first[33] == 299);
        UT_ASSERT_TRUE(crco.first[34] == 318);
        UT_ASSERT_TRUE(crco.first[35] == 319);
        UT_ASSERT_TRUE(crco.first[36] == 321);
        UT_ASSERT_TRUE(crco.first[37] == 333);
        UT_ASSERT_TRUE(crco.first[38] == 341);
        UT_ASSERT_TRUE(crco.first[39] == 342);
        UT_ASSERT_TRUE(crco.first[40] == 346);
        UT_ASSERT_TRUE(crco.first[41] == 349);
        UT_ASSERT_TRUE(crco.first[42] == 358);
        UT_ASSERT_TRUE(crco.first[43] == 377);
        UT_ASSERT_TRUE(crco.first[44] == 378);
        UT_ASSERT_TRUE(crco.first[45] == 381);
        UT_ASSERT_TRUE(crco.first[46] == 390);
        UT_ASSERT_TRUE(crco.first[47] == 394);
        UT_ASSERT_TRUE(crco.first[48] == 417);
        UT_ASSERT_TRUE(crco.first[49] == 432);
        UT_ASSERT_TRUE(crco.first[50] == 443);
        UT_ASSERT_TRUE(crco.first[51] == 444);
        UT_ASSERT_TRUE(crco.first[52] == 446);
        UT_ASSERT_TRUE(crco.first[53] == 452);
        UT_ASSERT_TRUE(crco.first[54] == 458);
        UT_ASSERT_TRUE(crco.first[55] == 460);
        UT_ASSERT_TRUE(crco.first[56] == 465);
        UT_ASSERT_TRUE(crco.first[57] == 478);
        UT_ASSERT_TRUE(crco.first[58] == 480);
        UT_ASSERT_TRUE(crco.first[59] == 494);
        UT_ASSERT_TRUE(crco.first[60] == 497);

        crco = clauses_repr_clauses_of(cr, 3);
        UT_ASSERT_TRUE(crco.len == 46);
        UT_ASSERT_TRUE(crco.first[0] == 13);
        UT_ASSERT_TRUE(crco.first[1] == 29);
        UT_ASSERT_TRUE(crco.first[2] == 33);
        UT_ASSERT_TRUE(crco.first[3] == 41);
        UT_ASSERT_TRUE(crco.first[4] == 54);
        UT_ASSERT_TRUE(crco.first[5] == 58);
        UT_ASSERT_TRUE(crco.first[6] == 91);
        UT_ASSERT_TRUE(crco.first[7] == 93);
        UT_ASSERT_TRUE(crco.first[8] == 94);
        UT_ASSERT_TRUE(crco.first[9] == 95);
        UT_ASSERT_TRUE(crco.first[10] == 109);
        UT_ASSERT_TRUE(crco.first[11] == 113);
        UT_ASSERT_TRUE(crco.first[12] == 129);
        UT_ASSERT_TRUE(crco.first[13] == 136);
        UT_ASSERT_TRUE(crco.first[14] == 137);
        UT_ASSERT_TRUE(crco.first[15] == 142);
        UT_ASSERT_TRUE(crco.first[16] == 145);
        UT_ASSERT_TRUE(crco.first[17] == 151);
        UT_ASSERT_TRUE(crco.first[18] == 165);
        UT_ASSERT_TRUE(crco.first[19] == 171);
        UT_ASSERT_TRUE(crco.first[20] == 174);
        UT_ASSERT_TRUE(crco.first[21] == 199);
        UT_ASSERT_TRUE(crco.first[22] == 217);
        UT_ASSERT_TRUE(crco.first[23] == 222);
        UT_ASSERT_TRUE(crco.first[24] == 224);
        UT_ASSERT_TRUE(crco.first[25] == 231);
        UT_ASSERT_TRUE(crco.first[26] == 261);
        UT_ASSERT_TRUE(crco.first[27] == 264);
        UT_ASSERT_TRUE(crco.first[28] == 302);
        UT_ASSERT_TRUE(crco.first[29] == 312);
        UT_ASSERT_TRUE(crco.first[30] == 320);
        UT_ASSERT_TRUE(crco.first[31] == 334);
        UT_ASSERT_TRUE(crco.first[32] == 338);
        UT_ASSERT_TRUE(crco.first[33] == 351);
        UT_ASSERT_TRUE(crco.first[34] == 354);
        UT_ASSERT_TRUE(crco.first[35] == 356);
        UT_ASSERT_TRUE(crco.first[36] == 362);
        UT_ASSERT_TRUE(crco.first[37] == 383);
        UT_ASSERT_TRUE(crco.first[38] == 405);
        UT_ASSERT_TRUE(crco.first[39] == 429);
        UT_ASSERT_TRUE(crco.first[40] == 433);
        UT_ASSERT_TRUE(crco.first[41] == 438);
        UT_ASSERT_TRUE(crco.first[42] == 446);
        UT_ASSERT_TRUE(crco.first[43] == 455);
        UT_ASSERT_TRUE(crco.first[44] == 458);
        UT_ASSERT_TRUE(crco.first[45] == 484);

        crco = clauses_repr_clauses_of(cr, 4);
        UT_ASSERT_TRUE(crco.len == 41);
        UT_ASSERT_TRUE(crco.first[0] == 14);
        UT_ASSERT_TRUE(crco.first[1] == 29);
        UT_ASSERT_TRUE(crco.first[2] == 37);
        UT_ASSERT_TRUE(crco.first[3] == 43);
        UT_ASSERT_TRUE(crco.first[4] == 66);
        UT_ASSERT_TRUE(crco.first[5] == 73);
        UT_ASSERT_TRUE(crco.first[6] == 75);
        UT_ASSERT_TRUE(crco.first[7] == 90);
        UT_ASSERT_TRUE(crco.first[8] == 116);
        UT_ASSERT_TRUE(crco.first[9] == 128);
        UT_ASSERT_TRUE(crco.first[10] == 139);
        UT_ASSERT_TRUE(crco.first[11] == 140);
        UT_ASSERT_TRUE(crco.first[12] == 148);
        UT_ASSERT_TRUE(crco.first[13] == 155);
        UT_ASSERT_TRUE(crco.first[14] == 158);
        UT_ASSERT_TRUE(crco.first[15] == 184);
        UT_ASSERT_TRUE(crco.first[16] == 189);
        UT_ASSERT_TRUE(crco.first[17] == 196);
        UT_ASSERT_TRUE(crco.first[18] == 213);
        UT_ASSERT_TRUE(crco.first[19] == 230);
        UT_ASSERT_TRUE(crco.first[20] == 251);
        UT_ASSERT_TRUE(crco.first[21] == 252);
        UT_ASSERT_TRUE(crco.first[22] == 253);
        UT_ASSERT_TRUE(crco.first[23] == 272);
        UT_ASSERT_TRUE(crco.first[24] == 273);
        UT_ASSERT_TRUE(crco.first[25] == 288);
        UT_ASSERT_TRUE(crco.first[26] == 301);
        UT_ASSERT_TRUE(crco.first[27] == 318);
        UT_ASSERT_TRUE(crco.first[28] == 327);
        UT_ASSERT_TRUE(crco.first[29] == 336);
        UT_ASSERT_TRUE(crco.first[30] == 377);
        UT_ASSERT_TRUE(crco.first[31] == 382);
        UT_ASSERT_TRUE(crco.first[32] == 401);
        UT_ASSERT_TRUE(crco.first[33] == 409);
        UT_ASSERT_TRUE(crco.first[34] == 415);
        UT_ASSERT_TRUE(crco.first[35] == 418);
        UT_ASSERT_TRUE(crco.first[36] == 433);
        UT_ASSERT_TRUE(crco.first[37] == 435);
        UT_ASSERT_TRUE(crco.first[38] == 436);
        UT_ASSERT_TRUE(crco.first[39] == 476);
        UT_ASSERT_TRUE(crco.first[40] == 494);

        crco = clauses_repr_clauses_of(cr, 5);
        UT_ASSERT_TRUE(crco.len == 57);
        UT_ASSERT_TRUE(crco.first[0] == 8);
        UT_ASSERT_TRUE(crco.first[1] == 15);
        UT_ASSERT_TRUE(crco.first[2] == 23);
        UT_ASSERT_TRUE(crco.first[3] == 34);
        UT_ASSERT_TRUE(crco.first[4] == 47);
        UT_ASSERT_TRUE(crco.first[5] == 65);
        UT_ASSERT_TRUE(crco.first[6] == 82);
        UT_ASSERT_TRUE(crco.first[7] == 85);
        UT_ASSERT_TRUE(crco.first[8] == 86);
        UT_ASSERT_TRUE(crco.first[9] == 88);
        UT_ASSERT_TRUE(crco.first[10] == 101);
        UT_ASSERT_TRUE(crco.first[11] == 109);
        UT_ASSERT_TRUE(crco.first[12] == 111);
        UT_ASSERT_TRUE(crco.first[13] == 132);
        UT_ASSERT_TRUE(crco.first[14] == 134);
        UT_ASSERT_TRUE(crco.first[15] == 141);
        UT_ASSERT_TRUE(crco.first[16] == 150);
        UT_ASSERT_TRUE(crco.first[17] == 154);
        UT_ASSERT_TRUE(crco.first[18] == 174);
        UT_ASSERT_TRUE(crco.first[19] == 184);
        UT_ASSERT_TRUE(crco.first[20] == 190);
        UT_ASSERT_TRUE(crco.first[21] == 191);
        UT_ASSERT_TRUE(crco.first[22] == 201);
        UT_ASSERT_TRUE(crco.first[23] == 211);
        UT_ASSERT_TRUE(crco.first[24] == 216);
        UT_ASSERT_TRUE(crco.first[25] == 219);
        UT_ASSERT_TRUE(crco.first[26] == 228);
        UT_ASSERT_TRUE(crco.first[27] == 240);
        UT_ASSERT_TRUE(crco.first[28] == 248);
        UT_ASSERT_TRUE(crco.first[29] == 250);
        UT_ASSERT_TRUE(crco.first[30] == 251);
        UT_ASSERT_TRUE(crco.first[31] == 260);
        UT_ASSERT_TRUE(crco.first[32] == 272);
        UT_ASSERT_TRUE(crco.first[33] == 275);
        UT_ASSERT_TRUE(crco.first[34] == 284);
        UT_ASSERT_TRUE(crco.first[35] == 294);
        UT_ASSERT_TRUE(crco.first[36] == 300);
        UT_ASSERT_TRUE(crco.first[37] == 305);
        UT_ASSERT_TRUE(crco.first[38] == 328);
        UT_ASSERT_TRUE(crco.first[39] == 356);
        UT_ASSERT_TRUE(crco.first[40] == 363);
        UT_ASSERT_TRUE(crco.first[41] == 372);
        UT_ASSERT_TRUE(crco.first[42] == 375);
        UT_ASSERT_TRUE(crco.first[43] == 388);
        UT_ASSERT_TRUE(crco.first[44] == 390);
        UT_ASSERT_TRUE(crco.first[45] == 393);
        UT_ASSERT_TRUE(crco.first[46] == 397);
        UT_ASSERT_TRUE(crco.first[47] == 401);
        UT_ASSERT_TRUE(crco.first[48] == 417);
        UT_ASSERT_TRUE(crco.first[49] == 423);
        UT_ASSERT_TRUE(crco.first[50] == 428);
        UT_ASSERT_TRUE(crco.first[51] == 429);
        UT_ASSERT_TRUE(crco.first[52] == 445);
        UT_ASSERT_TRUE(crco.first[53] == 454);
        UT_ASSERT_TRUE(crco.first[54] == 470);
        UT_ASSERT_TRUE(crco.first[55] == 484);
        UT_ASSERT_TRUE(crco.first[56] == 490);

        crco = clauses_repr_clauses_of(cr, 6);
        UT_ASSERT_TRUE(crco.len == 39);
        UT_ASSERT_TRUE(crco.first[0] == 2);
        UT_ASSERT_TRUE(crco.first[1] == 18);
        UT_ASSERT_TRUE(crco.first[2] == 20);
        UT_ASSERT_TRUE(crco.first[3] == 25);
        UT_ASSERT_TRUE(crco.first[4] == 29);
        UT_ASSERT_TRUE(crco.first[5] == 35);
        UT_ASSERT_TRUE(crco.first[6] == 37);
        UT_ASSERT_TRUE(crco.first[7] == 89);
        UT_ASSERT_TRUE(crco.first[8] == 92);
        UT_ASSERT_TRUE(crco.first[9] == 108);
        UT_ASSERT_TRUE(crco.first[10] == 114);
        UT_ASSERT_TRUE(crco.first[11] == 124);
        UT_ASSERT_TRUE(crco.first[12] == 130);
        UT_ASSERT_TRUE(crco.first[13] == 142);
        UT_ASSERT_TRUE(crco.first[14] == 144);
        UT_ASSERT_TRUE(crco.first[15] == 160);
        UT_ASSERT_TRUE(crco.first[16] == 173);
        UT_ASSERT_TRUE(crco.first[17] == 178);
        UT_ASSERT_TRUE(crco.first[18] == 183);
        UT_ASSERT_TRUE(crco.first[19] == 187);
        UT_ASSERT_TRUE(crco.first[20] == 193);
        UT_ASSERT_TRUE(crco.first[21] == 200);
        UT_ASSERT_TRUE(crco.first[22] == 207);
        UT_ASSERT_TRUE(crco.first[23] == 229);
        UT_ASSERT_TRUE(crco.first[24] == 233);
        UT_ASSERT_TRUE(crco.first[25] == 243);
        UT_ASSERT_TRUE(crco.first[26] == 244);
        UT_ASSERT_TRUE(crco.first[27] == 263);
        UT_ASSERT_TRUE(crco.first[28] == 276);
        UT_ASSERT_TRUE(crco.first[29] == 293);
        UT_ASSERT_TRUE(crco.first[30] == 314);
        UT_ASSERT_TRUE(crco.first[31] == 381);
        UT_ASSERT_TRUE(crco.first[32] == 389);
        UT_ASSERT_TRUE(crco.first[33] == 414);
        UT_ASSERT_TRUE(crco.first[34] == 437);
        UT_ASSERT_TRUE(crco.first[35] == 444);
        UT_ASSERT_TRUE(crco.first[36] == 449);
        UT_ASSERT_TRUE(crco.first[37] == 469);
        UT_ASSERT_TRUE(crco.first[38] == 486);

        crco = clauses_repr_clauses_of(cr, 7);
        UT_ASSERT_TRUE(crco.len == 64);
        UT_ASSERT_TRUE(crco.first[0] == 0);
        UT_ASSERT_TRUE(crco.first[1] == 11);
        UT_ASSERT_TRUE(crco.first[2] == 19);
        UT_ASSERT_TRUE(crco.first[3] == 39);
        UT_ASSERT_TRUE(crco.first[4] == 50);
        UT_ASSERT_TRUE(crco.first[5] == 54);
        UT_ASSERT_TRUE(crco.first[6] == 66);
        UT_ASSERT_TRUE(crco.first[7] == 67);
        UT_ASSERT_TRUE(crco.first[8] == 68);
        UT_ASSERT_TRUE(crco.first[9] == 78);
        UT_ASSERT_TRUE(crco.first[10] == 79);
        UT_ASSERT_TRUE(crco.first[11] == 105);
        UT_ASSERT_TRUE(crco.first[12] == 114);
        UT_ASSERT_TRUE(crco.first[13] == 122);
        UT_ASSERT_TRUE(crco.first[14] == 138);
        UT_ASSERT_TRUE(crco.first[15] == 143);
        UT_ASSERT_TRUE(crco.first[16] == 163);
        UT_ASSERT_TRUE(crco.first[17] == 165);
        UT_ASSERT_TRUE(crco.first[18] == 169);
        UT_ASSERT_TRUE(crco.first[19] == 177);
        UT_ASSERT_TRUE(crco.first[20] == 185);
        UT_ASSERT_TRUE(crco.first[21] == 210);
        UT_ASSERT_TRUE(crco.first[22] == 215);
        UT_ASSERT_TRUE(crco.first[23] == 218);
        UT_ASSERT_TRUE(crco.first[24] == 222);
        UT_ASSERT_TRUE(crco.first[25] == 232);
        UT_ASSERT_TRUE(crco.first[26] == 248);
        UT_ASSERT_TRUE(crco.first[27] == 262);
        UT_ASSERT_TRUE(crco.first[28] == 268);
        UT_ASSERT_TRUE(crco.first[29] == 269);
        UT_ASSERT_TRUE(crco.first[30] == 275);
        UT_ASSERT_TRUE(crco.first[31] == 277);
        UT_ASSERT_TRUE(crco.first[32] == 280);
        UT_ASSERT_TRUE(crco.first[33] == 286);
        UT_ASSERT_TRUE(crco.first[34] == 297);
        UT_ASSERT_TRUE(crco.first[35] == 307);
        UT_ASSERT_TRUE(crco.first[36] == 310);
        UT_ASSERT_TRUE(crco.first[37] == 315);
        UT_ASSERT_TRUE(crco.first[38] == 316);
        UT_ASSERT_TRUE(crco.first[39] == 331);
        UT_ASSERT_TRUE(crco.first[40] == 337);
        UT_ASSERT_TRUE(crco.first[41] == 362);
        UT_ASSERT_TRUE(crco.first[42] == 366);
        UT_ASSERT_TRUE(crco.first[43] == 367);
        UT_ASSERT_TRUE(crco.first[44] == 368);
        UT_ASSERT_TRUE(crco.first[45] == 379);
        UT_ASSERT_TRUE(crco.first[46] == 383);
        UT_ASSERT_TRUE(crco.first[47] == 384);
        UT_ASSERT_TRUE(crco.first[48] == 388);
        UT_ASSERT_TRUE(crco.first[49] == 412);
        UT_ASSERT_TRUE(crco.first[50] == 440);
        UT_ASSERT_TRUE(crco.first[51] == 444);
        UT_ASSERT_TRUE(crco.first[52] == 449);
        UT_ASSERT_TRUE(crco.first[53] == 452);
        UT_ASSERT_TRUE(crco.first[54] == 455);
        UT_ASSERT_TRUE(crco.first[55] == 457);
        UT_ASSERT_TRUE(crco.first[56] == 459);
        UT_ASSERT_TRUE(crco.first[57] == 462);
        UT_ASSERT_TRUE(crco.first[58] == 464);
        UT_ASSERT_TRUE(crco.first[59] == 469);
        UT_ASSERT_TRUE(crco.first[60] == 477);
        UT_ASSERT_TRUE(crco.first[61] == 484);
        UT_ASSERT_TRUE(crco.first[62] == 485);
        UT_ASSERT_TRUE(crco.first[63] == 493);

        crco = clauses_repr_clauses_of(cr, 8);
        UT_ASSERT_TRUE(crco.len == 54);
        UT_ASSERT_TRUE(crco.first[0] == 27);
        UT_ASSERT_TRUE(crco.first[1] == 34);
        UT_ASSERT_TRUE(crco.first[2] == 42);
        UT_ASSERT_TRUE(crco.first[3] == 44);
        UT_ASSERT_TRUE(crco.first[4] == 67);
        UT_ASSERT_TRUE(crco.first[5] == 71);
        UT_ASSERT_TRUE(crco.first[6] == 106);
        UT_ASSERT_TRUE(crco.first[7] == 132);
        UT_ASSERT_TRUE(crco.first[8] == 133);
        UT_ASSERT_TRUE(crco.first[9] == 135);
        UT_ASSERT_TRUE(crco.first[10] == 136);
        UT_ASSERT_TRUE(crco.first[11] == 150);
        UT_ASSERT_TRUE(crco.first[12] == 155);
        UT_ASSERT_TRUE(crco.first[13] == 157);
        UT_ASSERT_TRUE(crco.first[14] == 164);
        UT_ASSERT_TRUE(crco.first[15] == 179);
        UT_ASSERT_TRUE(crco.first[16] == 182);
        UT_ASSERT_TRUE(crco.first[17] == 189);
        UT_ASSERT_TRUE(crco.first[18] == 196);
        UT_ASSERT_TRUE(crco.first[19] == 221);
        UT_ASSERT_TRUE(crco.first[20] == 227);
        UT_ASSERT_TRUE(crco.first[21] == 232);
        UT_ASSERT_TRUE(crco.first[22] == 233);
        UT_ASSERT_TRUE(crco.first[23] == 235);
        UT_ASSERT_TRUE(crco.first[24] == 245);
        UT_ASSERT_TRUE(crco.first[25] == 249);
        UT_ASSERT_TRUE(crco.first[26] == 256);
        UT_ASSERT_TRUE(crco.first[27] == 257);
        UT_ASSERT_TRUE(crco.first[28] == 258);
        UT_ASSERT_TRUE(crco.first[29] == 263);
        UT_ASSERT_TRUE(crco.first[30] == 275);
        UT_ASSERT_TRUE(crco.first[31] == 279);
        UT_ASSERT_TRUE(crco.first[32] == 291);
        UT_ASSERT_TRUE(crco.first[33] == 294);
        UT_ASSERT_TRUE(crco.first[34] == 308);
        UT_ASSERT_TRUE(crco.first[35] == 315);
        UT_ASSERT_TRUE(crco.first[36] == 317);
        UT_ASSERT_TRUE(crco.first[37] == 357);
        UT_ASSERT_TRUE(crco.first[38] == 371);
        UT_ASSERT_TRUE(crco.first[39] == 373);
        UT_ASSERT_TRUE(crco.first[40] == 386);
        UT_ASSERT_TRUE(crco.first[41] == 396);
        UT_ASSERT_TRUE(crco.first[42] == 404);
        UT_ASSERT_TRUE(crco.first[43] == 406);
        UT_ASSERT_TRUE(crco.first[44] == 412);
        UT_ASSERT_TRUE(crco.first[45] == 420);
        UT_ASSERT_TRUE(crco.first[46] == 438);
        UT_ASSERT_TRUE(crco.first[47] == 439);
        UT_ASSERT_TRUE(crco.first[48] == 443);
        UT_ASSERT_TRUE(crco.first[49] == 445);
        UT_ASSERT_TRUE(crco.first[50] == 447);
        UT_ASSERT_TRUE(crco.first[51] == 450);
        UT_ASSERT_TRUE(crco.first[52] == 464);
        UT_ASSERT_TRUE(crco.first[53] == 497);

        crco = clauses_repr_clauses_of(cr, 9);
        UT_ASSERT_TRUE(crco.len == 57);
        UT_ASSERT_TRUE(crco.first[0] == 2);
        UT_ASSERT_TRUE(crco.first[1] == 3);
        UT_ASSERT_TRUE(crco.first[2] == 7);
        UT_ASSERT_TRUE(crco.first[3] == 16);
        UT_ASSERT_TRUE(crco.first[4] == 22);
        UT_ASSERT_TRUE(crco.first[5] == 32);
        UT_ASSERT_TRUE(crco.first[6] == 36);
        UT_ASSERT_TRUE(crco.first[7] == 56);
        UT_ASSERT_TRUE(crco.first[8] == 74);
        UT_ASSERT_TRUE(crco.first[9] == 78);
        UT_ASSERT_TRUE(crco.first[10] == 84);
        UT_ASSERT_TRUE(crco.first[11] == 85);
        UT_ASSERT_TRUE(crco.first[12] == 97);
        UT_ASSERT_TRUE(crco.first[13] == 98);
        UT_ASSERT_TRUE(crco.first[14] == 99);
        UT_ASSERT_TRUE(crco.first[15] == 103);
        UT_ASSERT_TRUE(crco.first[16] == 110);
        UT_ASSERT_TRUE(crco.first[17] == 112);
        UT_ASSERT_TRUE(crco.first[18] == 118);
        UT_ASSERT_TRUE(crco.first[19] == 133);
        UT_ASSERT_TRUE(crco.first[20] == 158);
        UT_ASSERT_TRUE(crco.first[21] == 167);
        UT_ASSERT_TRUE(crco.first[22] == 181);
        UT_ASSERT_TRUE(crco.first[23] == 205);
        UT_ASSERT_TRUE(crco.first[24] == 212);
        UT_ASSERT_TRUE(crco.first[25] == 220);
        UT_ASSERT_TRUE(crco.first[26] == 221);
        UT_ASSERT_TRUE(crco.first[27] == 229);
        UT_ASSERT_TRUE(crco.first[28] == 252);
        UT_ASSERT_TRUE(crco.first[29] == 257);
        UT_ASSERT_TRUE(crco.first[30] == 259);
        UT_ASSERT_TRUE(crco.first[31] == 267);
        UT_ASSERT_TRUE(crco.first[32] == 286);
        UT_ASSERT_TRUE(crco.first[33] == 289);
        UT_ASSERT_TRUE(crco.first[34] == 327);
        UT_ASSERT_TRUE(crco.first[35] == 329);
        UT_ASSERT_TRUE(crco.first[36] == 335);
        UT_ASSERT_TRUE(crco.first[37] == 343);
        UT_ASSERT_TRUE(crco.first[38] == 345);
        UT_ASSERT_TRUE(crco.first[39] == 353);
        UT_ASSERT_TRUE(crco.first[40] == 358);
        UT_ASSERT_TRUE(crco.first[41] == 365);
        UT_ASSERT_TRUE(crco.first[42] == 379);
        UT_ASSERT_TRUE(crco.first[43] == 392);
        UT_ASSERT_TRUE(crco.first[44] == 394);
        UT_ASSERT_TRUE(crco.first[45] == 402);
        UT_ASSERT_TRUE(crco.first[46] == 426);
        UT_ASSERT_TRUE(crco.first[47] == 448);
        UT_ASSERT_TRUE(crco.first[48] == 450);
        UT_ASSERT_TRUE(crco.first[49] == 462);
        UT_ASSERT_TRUE(crco.first[50] == 468);
        UT_ASSERT_TRUE(crco.first[51] == 482);
        UT_ASSERT_TRUE(crco.first[52] == 485);
        UT_ASSERT_TRUE(crco.first[53] == 492);
        UT_ASSERT_TRUE(crco.first[54] == 494);
        UT_ASSERT_TRUE(crco.first[55] == 495);
        UT_ASSERT_TRUE(crco.first[56] == 499);

        crco = clauses_repr_clauses_of(cr, 10);
        UT_ASSERT_TRUE(crco.len == 44);
        UT_ASSERT_TRUE(crco.first[0] == 3);
        UT_ASSERT_TRUE(crco.first[1] == 24);
        UT_ASSERT_TRUE(crco.first[2] == 27);
        UT_ASSERT_TRUE(crco.first[3] == 44);
        UT_ASSERT_TRUE(crco.first[4] == 45);
        UT_ASSERT_TRUE(crco.first[5] == 53);
        UT_ASSERT_TRUE(crco.first[6] == 55);
        UT_ASSERT_TRUE(crco.first[7] == 78);
        UT_ASSERT_TRUE(crco.first[8] == 84);
        UT_ASSERT_TRUE(crco.first[9] == 119);
        UT_ASSERT_TRUE(crco.first[10] == 127);
        UT_ASSERT_TRUE(crco.first[11] == 131);
        UT_ASSERT_TRUE(crco.first[12] == 138);
        UT_ASSERT_TRUE(crco.first[13] == 159);
        UT_ASSERT_TRUE(crco.first[14] == 163);
        UT_ASSERT_TRUE(crco.first[15] == 195);
        UT_ASSERT_TRUE(crco.first[16] == 201);
        UT_ASSERT_TRUE(crco.first[17] == 202);
        UT_ASSERT_TRUE(crco.first[18] == 203);
        UT_ASSERT_TRUE(crco.first[19] == 204);
        UT_ASSERT_TRUE(crco.first[20] == 209);
        UT_ASSERT_TRUE(crco.first[21] == 263);
        UT_ASSERT_TRUE(crco.first[22] == 264);
        UT_ASSERT_TRUE(crco.first[23] == 279);
        UT_ASSERT_TRUE(crco.first[24] == 289);
        UT_ASSERT_TRUE(crco.first[25] == 294);
        UT_ASSERT_TRUE(crco.first[26] == 298);
        UT_ASSERT_TRUE(crco.first[27] == 303);
        UT_ASSERT_TRUE(crco.first[28] == 311);
        UT_ASSERT_TRUE(crco.first[29] == 325);
        UT_ASSERT_TRUE(crco.first[30] == 326);
        UT_ASSERT_TRUE(crco.first[31] == 337);
        UT_ASSERT_TRUE(crco.first[32] == 345);
        UT_ASSERT_TRUE(crco.first[33] == 363);
        UT_ASSERT_TRUE(crco.first[34] == 374);
        UT_ASSERT_TRUE(crco.first[35] == 395);
        UT_ASSERT_TRUE(crco.first[36] == 410);
        UT_ASSERT_TRUE(crco.first[37] == 418);
        UT_ASSERT_TRUE(crco.first[38] == 425);
        UT_ASSERT_TRUE(crco.first[39] == 426);
        UT_ASSERT_TRUE(crco.first[40] == 434);
        UT_ASSERT_TRUE(crco.first[41] == 442);
        UT_ASSERT_TRUE(crco.first[42] == 471);
        UT_ASSERT_TRUE(crco.first[43] == 479);

        crco = clauses_repr_clauses_of(cr, 11);
        UT_ASSERT_TRUE(crco.len == 42);
        UT_ASSERT_TRUE(crco.first[0] == 12);
        UT_ASSERT_TRUE(crco.first[1] == 18);
        UT_ASSERT_TRUE(crco.first[2] == 33);
        UT_ASSERT_TRUE(crco.first[3] == 35);
        UT_ASSERT_TRUE(crco.first[4] == 44);
        UT_ASSERT_TRUE(crco.first[5] == 71);
        UT_ASSERT_TRUE(crco.first[6] == 74);
        UT_ASSERT_TRUE(crco.first[7] == 91);
        UT_ASSERT_TRUE(crco.first[8] == 93);
        UT_ASSERT_TRUE(crco.first[9] == 104);
        UT_ASSERT_TRUE(crco.first[10] == 106);
        UT_ASSERT_TRUE(crco.first[11] == 125);
        UT_ASSERT_TRUE(crco.first[12] == 129);
        UT_ASSERT_TRUE(crco.first[13] == 141);
        UT_ASSERT_TRUE(crco.first[14] == 142);
        UT_ASSERT_TRUE(crco.first[15] == 145);
        UT_ASSERT_TRUE(crco.first[16] == 153);
        UT_ASSERT_TRUE(crco.first[17] == 156);
        UT_ASSERT_TRUE(crco.first[18] == 168);
        UT_ASSERT_TRUE(crco.first[19] == 213);
        UT_ASSERT_TRUE(crco.first[20] == 215);
        UT_ASSERT_TRUE(crco.first[21] == 225);
        UT_ASSERT_TRUE(crco.first[22] == 236);
        UT_ASSERT_TRUE(crco.first[23] == 237);
        UT_ASSERT_TRUE(crco.first[24] == 238);
        UT_ASSERT_TRUE(crco.first[25] == 253);
        UT_ASSERT_TRUE(crco.first[26] == 272);
        UT_ASSERT_TRUE(crco.first[27] == 281);
        UT_ASSERT_TRUE(crco.first[28] == 283);
        UT_ASSERT_TRUE(crco.first[29] == 287);
        UT_ASSERT_TRUE(crco.first[30] == 333);
        UT_ASSERT_TRUE(crco.first[31] == 352);
        UT_ASSERT_TRUE(crco.first[32] == 374);
        UT_ASSERT_TRUE(crco.first[33] == 376);
        UT_ASSERT_TRUE(crco.first[34] == 380);
        UT_ASSERT_TRUE(crco.first[35] == 384);
        UT_ASSERT_TRUE(crco.first[36] == 386);
        UT_ASSERT_TRUE(crco.first[37] == 401);
        UT_ASSERT_TRUE(crco.first[38] == 465);
        UT_ASSERT_TRUE(crco.first[39] == 473);
        UT_ASSERT_TRUE(crco.first[40] == 477);
        UT_ASSERT_TRUE(crco.first[41] == 478);

        crco = clauses_repr_clauses_of(cr, 12);
        UT_ASSERT_TRUE(crco.len == 53);
        UT_ASSERT_TRUE(crco.first[0] == 4);
        UT_ASSERT_TRUE(crco.first[1] == 17);
        UT_ASSERT_TRUE(crco.first[2] == 30);
        UT_ASSERT_TRUE(crco.first[3] == 38);
        UT_ASSERT_TRUE(crco.first[4] == 52);
        UT_ASSERT_TRUE(crco.first[5] == 74);
        UT_ASSERT_TRUE(crco.first[6] == 75);
        UT_ASSERT_TRUE(crco.first[7] == 76);
        UT_ASSERT_TRUE(crco.first[8] == 80);
        UT_ASSERT_TRUE(crco.first[9] == 87);
        UT_ASSERT_TRUE(crco.first[10] == 99);
        UT_ASSERT_TRUE(crco.first[11] == 110);
        UT_ASSERT_TRUE(crco.first[12] == 111);
        UT_ASSERT_TRUE(crco.first[13] == 123);
        UT_ASSERT_TRUE(crco.first[14] == 124);
        UT_ASSERT_TRUE(crco.first[15] == 125);
        UT_ASSERT_TRUE(crco.first[16] == 130);
        UT_ASSERT_TRUE(crco.first[17] == 136);
        UT_ASSERT_TRUE(crco.first[18] == 145);
        UT_ASSERT_TRUE(crco.first[19] == 147);
        UT_ASSERT_TRUE(crco.first[20] == 151);
        UT_ASSERT_TRUE(crco.first[21] == 175);
        UT_ASSERT_TRUE(crco.first[22] == 177);
        UT_ASSERT_TRUE(crco.first[23] == 182);
        UT_ASSERT_TRUE(crco.first[24] == 193);
        UT_ASSERT_TRUE(crco.first[25] == 223);
        UT_ASSERT_TRUE(crco.first[26] == 228);
        UT_ASSERT_TRUE(crco.first[27] == 246);
        UT_ASSERT_TRUE(crco.first[28] == 250);
        UT_ASSERT_TRUE(crco.first[29] == 253);
        UT_ASSERT_TRUE(crco.first[30] == 256);
        UT_ASSERT_TRUE(crco.first[31] == 258);
        UT_ASSERT_TRUE(crco.first[32] == 287);
        UT_ASSERT_TRUE(crco.first[33] == 310);
        UT_ASSERT_TRUE(crco.first[34] == 323);
        UT_ASSERT_TRUE(crco.first[35] == 338);
        UT_ASSERT_TRUE(crco.first[36] == 344);
        UT_ASSERT_TRUE(crco.first[37] == 345);
        UT_ASSERT_TRUE(crco.first[38] == 348);
        UT_ASSERT_TRUE(crco.first[39] == 357);
        UT_ASSERT_TRUE(crco.first[40] == 361);
        UT_ASSERT_TRUE(crco.first[41] == 387);
        UT_ASSERT_TRUE(crco.first[42] == 397);
        UT_ASSERT_TRUE(crco.first[43] == 413);
        UT_ASSERT_TRUE(crco.first[44] == 422);
        UT_ASSERT_TRUE(crco.first[45] == 424);
        UT_ASSERT_TRUE(crco.first[46] == 425);
        UT_ASSERT_TRUE(crco.first[47] == 427);
        UT_ASSERT_TRUE(crco.first[48] == 436);
        UT_ASSERT_TRUE(crco.first[49] == 451);
        UT_ASSERT_TRUE(crco.first[50] == 475);
        UT_ASSERT_TRUE(crco.first[51] == 490);
        UT_ASSERT_TRUE(crco.first[52] == 499);

        crco = clauses_repr_clauses_of(cr, 13);
        UT_ASSERT_TRUE(crco.len == 53);
        UT_ASSERT_TRUE(crco.first[0] == 2);
        UT_ASSERT_TRUE(crco.first[1] == 16);
        UT_ASSERT_TRUE(crco.first[2] == 28);
        UT_ASSERT_TRUE(crco.first[3] == 31);
        UT_ASSERT_TRUE(crco.first[4] == 33);
        UT_ASSERT_TRUE(crco.first[5] == 40);
        UT_ASSERT_TRUE(crco.first[6] == 45);
        UT_ASSERT_TRUE(crco.first[7] == 49);
        UT_ASSERT_TRUE(crco.first[8] == 58);
        UT_ASSERT_TRUE(crco.first[9] == 64);
        UT_ASSERT_TRUE(crco.first[10] == 80);
        UT_ASSERT_TRUE(crco.first[11] == 128);
        UT_ASSERT_TRUE(crco.first[12] == 135);
        UT_ASSERT_TRUE(crco.first[13] == 153);
        UT_ASSERT_TRUE(crco.first[14] == 156);
        UT_ASSERT_TRUE(crco.first[15] == 166);
        UT_ASSERT_TRUE(crco.first[16] == 168);
        UT_ASSERT_TRUE(crco.first[17] == 173);
        UT_ASSERT_TRUE(crco.first[18] == 178);
        UT_ASSERT_TRUE(crco.first[19] == 182);
        UT_ASSERT_TRUE(crco.first[20] == 185);
        UT_ASSERT_TRUE(crco.first[21] == 187);
        UT_ASSERT_TRUE(crco.first[22] == 196);
        UT_ASSERT_TRUE(crco.first[23] == 197);
        UT_ASSERT_TRUE(crco.first[24] == 204);
        UT_ASSERT_TRUE(crco.first[25] == 206);
        UT_ASSERT_TRUE(crco.first[26] == 214);
        UT_ASSERT_TRUE(crco.first[27] == 217);
        UT_ASSERT_TRUE(crco.first[28] == 228);
        UT_ASSERT_TRUE(crco.first[29] == 241);
        UT_ASSERT_TRUE(crco.first[30] == 252);
        UT_ASSERT_TRUE(crco.first[31] == 267);
        UT_ASSERT_TRUE(crco.first[32] == 296);
        UT_ASSERT_TRUE(crco.first[33] == 306);
        UT_ASSERT_TRUE(crco.first[34] == 323);
        UT_ASSERT_TRUE(crco.first[35] == 324);
        UT_ASSERT_TRUE(crco.first[36] == 343);
        UT_ASSERT_TRUE(crco.first[37] == 350);
        UT_ASSERT_TRUE(crco.first[38] == 369);
        UT_ASSERT_TRUE(crco.first[39] == 391);
        UT_ASSERT_TRUE(crco.first[40] == 400);
        UT_ASSERT_TRUE(crco.first[41] == 414);
        UT_ASSERT_TRUE(crco.first[42] == 415);
        UT_ASSERT_TRUE(crco.first[43] == 416);
        UT_ASSERT_TRUE(crco.first[44] == 421);
        UT_ASSERT_TRUE(crco.first[45] == 438);
        UT_ASSERT_TRUE(crco.first[46] == 452);
        UT_ASSERT_TRUE(crco.first[47] == 465);
        UT_ASSERT_TRUE(crco.first[48] == 474);
        UT_ASSERT_TRUE(crco.first[49] == 479);
        UT_ASSERT_TRUE(crco.first[50] == 481);
        UT_ASSERT_TRUE(crco.first[51] == 487);
        UT_ASSERT_TRUE(crco.first[52] == 498);

        crco = clauses_repr_clauses_of(cr, 14);
        UT_ASSERT_TRUE(crco.len == 41);
        UT_ASSERT_TRUE(crco.first[0] == 9);
        UT_ASSERT_TRUE(crco.first[1] == 11);
        UT_ASSERT_TRUE(crco.first[2] == 14);
        UT_ASSERT_TRUE(crco.first[3] == 18);
        UT_ASSERT_TRUE(crco.first[4] == 25);
        UT_ASSERT_TRUE(crco.first[5] == 42);
        UT_ASSERT_TRUE(crco.first[6] == 49);
        UT_ASSERT_TRUE(crco.first[7] == 54);
        UT_ASSERT_TRUE(crco.first[8] == 55);
        UT_ASSERT_TRUE(crco.first[9] == 69);
        UT_ASSERT_TRUE(crco.first[10] == 77);
        UT_ASSERT_TRUE(crco.first[11] == 79);
        UT_ASSERT_TRUE(crco.first[12] == 109);
        UT_ASSERT_TRUE(crco.first[13] == 138);
        UT_ASSERT_TRUE(crco.first[14] == 161);
        UT_ASSERT_TRUE(crco.first[15] == 186);
        UT_ASSERT_TRUE(crco.first[16] == 239);
        UT_ASSERT_TRUE(crco.first[17] == 243);
        UT_ASSERT_TRUE(crco.first[18] == 257);
        UT_ASSERT_TRUE(crco.first[19] == 260);
        UT_ASSERT_TRUE(crco.first[20] == 266);
        UT_ASSERT_TRUE(crco.first[21] == 277);
        UT_ASSERT_TRUE(crco.first[22] == 302);
        UT_ASSERT_TRUE(crco.first[23] == 303);
        UT_ASSERT_TRUE(crco.first[24] == 312);
        UT_ASSERT_TRUE(crco.first[25] == 331);
        UT_ASSERT_TRUE(crco.first[26] == 339);
        UT_ASSERT_TRUE(crco.first[27] == 342);
        UT_ASSERT_TRUE(crco.first[28] == 361);
        UT_ASSERT_TRUE(crco.first[29] == 370);
        UT_ASSERT_TRUE(crco.first[30] == 373);
        UT_ASSERT_TRUE(crco.first[31] == 377);
        UT_ASSERT_TRUE(crco.first[32] == 383);
        UT_ASSERT_TRUE(crco.first[33] == 399);
        UT_ASSERT_TRUE(crco.first[34] == 409);
        UT_ASSERT_TRUE(crco.first[35] == 411);
        UT_ASSERT_TRUE(crco.first[36] == 412);
        UT_ASSERT_TRUE(crco.first[37] == 462);
        UT_ASSERT_TRUE(crco.first[38] == 470);
        UT_ASSERT_TRUE(crco.first[39] == 482);
        UT_ASSERT_TRUE(crco.first[40] == 487);

        crco = clauses_repr_clauses_of(cr, 15);
        UT_ASSERT_TRUE(crco.len == 61);
        UT_ASSERT_TRUE(crco.first[0] == 6);
        UT_ASSERT_TRUE(crco.first[1] == 7);
        UT_ASSERT_TRUE(crco.first[2] == 21);
        UT_ASSERT_TRUE(crco.first[3] == 24);
        UT_ASSERT_TRUE(crco.first[4] == 31);
        UT_ASSERT_TRUE(crco.first[5] == 36);
        UT_ASSERT_TRUE(crco.first[6] == 42);
        UT_ASSERT_TRUE(crco.first[7] == 53);
        UT_ASSERT_TRUE(crco.first[8] == 56);
        UT_ASSERT_TRUE(crco.first[9] == 65);
        UT_ASSERT_TRUE(crco.first[10] == 83);
        UT_ASSERT_TRUE(crco.first[11] == 86);
        UT_ASSERT_TRUE(crco.first[12] == 89);
        UT_ASSERT_TRUE(crco.first[13] == 92);
        UT_ASSERT_TRUE(crco.first[14] == 97);
        UT_ASSERT_TRUE(crco.first[15] == 100);
        UT_ASSERT_TRUE(crco.first[16] == 101);
        UT_ASSERT_TRUE(crco.first[17] == 119);
        UT_ASSERT_TRUE(crco.first[18] == 120);
        UT_ASSERT_TRUE(crco.first[19] == 143);
        UT_ASSERT_TRUE(crco.first[20] == 148);
        UT_ASSERT_TRUE(crco.first[21] == 149);
        UT_ASSERT_TRUE(crco.first[22] == 170);
        UT_ASSERT_TRUE(crco.first[23] == 192);
        UT_ASSERT_TRUE(crco.first[24] == 205);
        UT_ASSERT_TRUE(crco.first[25] == 227);
        UT_ASSERT_TRUE(crco.first[26] == 234);
        UT_ASSERT_TRUE(crco.first[27] == 238);
        UT_ASSERT_TRUE(crco.first[28] == 240);
        UT_ASSERT_TRUE(crco.first[29] == 264);
        UT_ASSERT_TRUE(crco.first[30] == 270);
        UT_ASSERT_TRUE(crco.first[31] == 274);
        UT_ASSERT_TRUE(crco.first[32] == 290);
        UT_ASSERT_TRUE(crco.first[33] == 295);
        UT_ASSERT_TRUE(crco.first[34] == 296);
        UT_ASSERT_TRUE(crco.first[35] == 306);
        UT_ASSERT_TRUE(crco.first[36] == 316);
        UT_ASSERT_TRUE(crco.first[37] == 320);
        UT_ASSERT_TRUE(crco.first[38] == 329);
        UT_ASSERT_TRUE(crco.first[39] == 334);
        UT_ASSERT_TRUE(crco.first[40] == 339);
        UT_ASSERT_TRUE(crco.first[41] == 350);
        UT_ASSERT_TRUE(crco.first[42] == 355);
        UT_ASSERT_TRUE(crco.first[43] == 359);
        UT_ASSERT_TRUE(crco.first[44] == 373);
        UT_ASSERT_TRUE(crco.first[45] == 375);
        UT_ASSERT_TRUE(crco.first[46] == 380);
        UT_ASSERT_TRUE(crco.first[47] == 385);
        UT_ASSERT_TRUE(crco.first[48] == 396);
        UT_ASSERT_TRUE(crco.first[49] == 419);
        UT_ASSERT_TRUE(crco.first[50] == 420);
        UT_ASSERT_TRUE(crco.first[51] == 428);
        UT_ASSERT_TRUE(crco.first[52] == 429);
        UT_ASSERT_TRUE(crco.first[53] == 447);
        UT_ASSERT_TRUE(crco.first[54] == 449);
        UT_ASSERT_TRUE(crco.first[55] == 454);
        UT_ASSERT_TRUE(crco.first[56] == 483);
        UT_ASSERT_TRUE(crco.first[57] == 486);
        UT_ASSERT_TRUE(crco.first[58] == 490);
        UT_ASSERT_TRUE(crco.first[59] == 491);
        UT_ASSERT_TRUE(crco.first[60] == 495);

        crco = clauses_repr_clauses_of(cr, 16);
        UT_ASSERT_TRUE(crco.len == 49);
        UT_ASSERT_TRUE(crco.first[0] == 4);
        UT_ASSERT_TRUE(crco.first[1] == 15);
        UT_ASSERT_TRUE(crco.first[2] == 59);
        UT_ASSERT_TRUE(crco.first[3] == 62);
        UT_ASSERT_TRUE(crco.first[4] == 80);
        UT_ASSERT_TRUE(crco.first[5] == 88);
        UT_ASSERT_TRUE(crco.first[6] == 89);
        UT_ASSERT_TRUE(crco.first[7] == 113);
        UT_ASSERT_TRUE(crco.first[8] == 158);
        UT_ASSERT_TRUE(crco.first[9] == 161);
        UT_ASSERT_TRUE(crco.first[10] == 162);
        UT_ASSERT_TRUE(crco.first[11] == 165);
        UT_ASSERT_TRUE(crco.first[12] == 179);
        UT_ASSERT_TRUE(crco.first[13] == 186);
        UT_ASSERT_TRUE(crco.first[14] == 197);
        UT_ASSERT_TRUE(crco.first[15] == 206);
        UT_ASSERT_TRUE(crco.first[16] == 218);
        UT_ASSERT_TRUE(crco.first[17] == 223);
        UT_ASSERT_TRUE(crco.first[18] == 231);
        UT_ASSERT_TRUE(crco.first[19] == 240);
        UT_ASSERT_TRUE(crco.first[20] == 241);
        UT_ASSERT_TRUE(crco.first[21] == 245);
        UT_ASSERT_TRUE(crco.first[22] == 262);
        UT_ASSERT_TRUE(crco.first[23] == 269);
        UT_ASSERT_TRUE(crco.first[24] == 273);
        UT_ASSERT_TRUE(crco.first[25] == 304);
        UT_ASSERT_TRUE(crco.first[26] == 306);
        UT_ASSERT_TRUE(crco.first[27] == 313);
        UT_ASSERT_TRUE(crco.first[28] == 340);
        UT_ASSERT_TRUE(crco.first[29] == 347);
        UT_ASSERT_TRUE(crco.first[30] == 356);
        UT_ASSERT_TRUE(crco.first[31] == 359);
        UT_ASSERT_TRUE(crco.first[32] == 364);
        UT_ASSERT_TRUE(crco.first[33] == 365);
        UT_ASSERT_TRUE(crco.first[34] == 386);
        UT_ASSERT_TRUE(crco.first[35] == 389);
        UT_ASSERT_TRUE(crco.first[36] == 397);
        UT_ASSERT_TRUE(crco.first[37] == 398);
        UT_ASSERT_TRUE(crco.first[38] == 403);
        UT_ASSERT_TRUE(crco.first[39] == 410);
        UT_ASSERT_TRUE(crco.first[40] == 424);
        UT_ASSERT_TRUE(crco.first[41] == 440);
        UT_ASSERT_TRUE(crco.first[42] == 445);
        UT_ASSERT_TRUE(crco.first[43] == 463);
        UT_ASSERT_TRUE(crco.first[44] == 470);
        UT_ASSERT_TRUE(crco.first[45] == 471);
        UT_ASSERT_TRUE(crco.first[46] == 474);
        UT_ASSERT_TRUE(crco.first[47] == 478);
        UT_ASSERT_TRUE(crco.first[48] == 486);

        crco = clauses_repr_clauses_of(cr, 17);
        UT_ASSERT_TRUE(crco.len == 51);
        UT_ASSERT_TRUE(crco.first[0] == 5);
        UT_ASSERT_TRUE(crco.first[1] == 16);
        UT_ASSERT_TRUE(crco.first[2] == 22);
        UT_ASSERT_TRUE(crco.first[3] == 50);
        UT_ASSERT_TRUE(crco.first[4] == 61);
        UT_ASSERT_TRUE(crco.first[5] == 70);
        UT_ASSERT_TRUE(crco.first[6] == 75);
        UT_ASSERT_TRUE(crco.first[7] == 92);
        UT_ASSERT_TRUE(crco.first[8] == 130);
        UT_ASSERT_TRUE(crco.first[9] == 134);
        UT_ASSERT_TRUE(crco.first[10] == 139);
        UT_ASSERT_TRUE(crco.first[11] == 146);
        UT_ASSERT_TRUE(crco.first[12] == 148);
        UT_ASSERT_TRUE(crco.first[13] == 169);
        UT_ASSERT_TRUE(crco.first[14] == 170);
        UT_ASSERT_TRUE(crco.first[15] == 174);
        UT_ASSERT_TRUE(crco.first[16] == 175);
        UT_ASSERT_TRUE(crco.first[17] == 176);
        UT_ASSERT_TRUE(crco.first[18] == 192);
        UT_ASSERT_TRUE(crco.first[19] == 194);
        UT_ASSERT_TRUE(crco.first[20] == 202);
        UT_ASSERT_TRUE(crco.first[21] == 207);
        UT_ASSERT_TRUE(crco.first[22] == 209);
        UT_ASSERT_TRUE(crco.first[23] == 214);
        UT_ASSERT_TRUE(crco.first[24] == 216);
        UT_ASSERT_TRUE(crco.first[25] == 218);
        UT_ASSERT_TRUE(crco.first[26] == 223);
        UT_ASSERT_TRUE(crco.first[27] == 241);
        UT_ASSERT_TRUE(crco.first[28] == 246);
        UT_ASSERT_TRUE(crco.first[29] == 268);
        UT_ASSERT_TRUE(crco.first[30] == 270);
        UT_ASSERT_TRUE(crco.first[31] == 293);
        UT_ASSERT_TRUE(crco.first[32] == 305);
        UT_ASSERT_TRUE(crco.first[33] == 308);
        UT_ASSERT_TRUE(crco.first[34] == 309);
        UT_ASSERT_TRUE(crco.first[35] == 330);
        UT_ASSERT_TRUE(crco.first[36] == 334);
        UT_ASSERT_TRUE(crco.first[37] == 372);
        UT_ASSERT_TRUE(crco.first[38] == 374);
        UT_ASSERT_TRUE(crco.first[39] == 378);
        UT_ASSERT_TRUE(crco.first[40] == 406);
        UT_ASSERT_TRUE(crco.first[41] == 407);
        UT_ASSERT_TRUE(crco.first[42] == 416);
        UT_ASSERT_TRUE(crco.first[43] == 419);
        UT_ASSERT_TRUE(crco.first[44] == 434);
        UT_ASSERT_TRUE(crco.first[45] == 440);
        UT_ASSERT_TRUE(crco.first[46] == 458);
        UT_ASSERT_TRUE(crco.first[47] == 459);
        UT_ASSERT_TRUE(crco.first[48] == 463);
        UT_ASSERT_TRUE(crco.first[49] == 493);
        UT_ASSERT_TRUE(crco.first[50] == 498);

        crco = clauses_repr_clauses_of(cr, 18);
        UT_ASSERT_TRUE(crco.len == 56);
        UT_ASSERT_TRUE(crco.first[0] == 6);
        UT_ASSERT_TRUE(crco.first[1] == 9);
        UT_ASSERT_TRUE(crco.first[2] == 20);
        UT_ASSERT_TRUE(crco.first[3] == 32);
        UT_ASSERT_TRUE(crco.first[4] == 41);
        UT_ASSERT_TRUE(crco.first[5] == 48);
        UT_ASSERT_TRUE(crco.first[6] == 57);
        UT_ASSERT_TRUE(crco.first[7] == 59);
        UT_ASSERT_TRUE(crco.first[8] == 64);
        UT_ASSERT_TRUE(crco.first[9] == 67);
        UT_ASSERT_TRUE(crco.first[10] == 96);
        UT_ASSERT_TRUE(crco.first[11] == 97);
        UT_ASSERT_TRUE(crco.first[12] == 103);
        UT_ASSERT_TRUE(crco.first[13] == 114);
        UT_ASSERT_TRUE(crco.first[14] == 115);
        UT_ASSERT_TRUE(crco.first[15] == 118);
        UT_ASSERT_TRUE(crco.first[16] == 121);
        UT_ASSERT_TRUE(crco.first[17] == 126);
        UT_ASSERT_TRUE(crco.first[18] == 135);
        UT_ASSERT_TRUE(crco.first[19] == 152);
        UT_ASSERT_TRUE(crco.first[20] == 159);
        UT_ASSERT_TRUE(crco.first[21] == 169);
        UT_ASSERT_TRUE(crco.first[22] == 175);
        UT_ASSERT_TRUE(crco.first[23] == 181);
        UT_ASSERT_TRUE(crco.first[24] == 191);
        UT_ASSERT_TRUE(crco.first[25] == 208);
        UT_ASSERT_TRUE(crco.first[26] == 226);
        UT_ASSERT_TRUE(crco.first[27] == 227);
        UT_ASSERT_TRUE(crco.first[28] == 230);
        UT_ASSERT_TRUE(crco.first[29] == 247);
        UT_ASSERT_TRUE(crco.first[30] == 249);
        UT_ASSERT_TRUE(crco.first[31] == 254);
        UT_ASSERT_TRUE(crco.first[32] == 274);
        UT_ASSERT_TRUE(crco.first[33] == 284);
        UT_ASSERT_TRUE(crco.first[34] == 299);
        UT_ASSERT_TRUE(crco.first[35] == 327);
        UT_ASSERT_TRUE(crco.first[36] == 331);
        UT_ASSERT_TRUE(crco.first[37] == 335);
        UT_ASSERT_TRUE(crco.first[38] == 340);
        UT_ASSERT_TRUE(crco.first[39] == 346);
        UT_ASSERT_TRUE(crco.first[40] == 353);
        UT_ASSERT_TRUE(crco.first[41] == 364);
        UT_ASSERT_TRUE(crco.first[42] == 366);
        UT_ASSERT_TRUE(crco.first[43] == 382);
        UT_ASSERT_TRUE(crco.first[44] == 396);
        UT_ASSERT_TRUE(crco.first[45] == 402);
        UT_ASSERT_TRUE(crco.first[46] == 410);
        UT_ASSERT_TRUE(crco.first[47] == 415);
        UT_ASSERT_TRUE(crco.first[48] == 430);
        UT_ASSERT_TRUE(crco.first[49] == 437);
        UT_ASSERT_TRUE(crco.first[50] == 441);
        UT_ASSERT_TRUE(crco.first[51] == 457);
        UT_ASSERT_TRUE(crco.first[52] == 467);
        UT_ASSERT_TRUE(crco.first[53] == 468);
        UT_ASSERT_TRUE(crco.first[54] == 476);
        UT_ASSERT_TRUE(crco.first[55] == 482);

        crco = clauses_repr_clauses_of(cr, 19);
        UT_ASSERT_TRUE(crco.len == 36);
        UT_ASSERT_TRUE(crco.first[0] == 43);
        UT_ASSERT_TRUE(crco.first[1] == 47);
        UT_ASSERT_TRUE(crco.first[2] == 76);
        UT_ASSERT_TRUE(crco.first[3] == 121);
        UT_ASSERT_TRUE(crco.first[4] == 123);
        UT_ASSERT_TRUE(crco.first[5] == 124);
        UT_ASSERT_TRUE(crco.first[6] == 133);
        UT_ASSERT_TRUE(crco.first[7] == 134);
        UT_ASSERT_TRUE(crco.first[8] == 152);
        UT_ASSERT_TRUE(crco.first[9] == 166);
        UT_ASSERT_TRUE(crco.first[10] == 210);
        UT_ASSERT_TRUE(crco.first[11] == 211);
        UT_ASSERT_TRUE(crco.first[12] == 214);
        UT_ASSERT_TRUE(crco.first[13] == 225);
        UT_ASSERT_TRUE(crco.first[14] == 234);
        UT_ASSERT_TRUE(crco.first[15] == 247);
        UT_ASSERT_TRUE(crco.first[16] == 281);
        UT_ASSERT_TRUE(crco.first[17] == 282);
        UT_ASSERT_TRUE(crco.first[18] == 285);
        UT_ASSERT_TRUE(crco.first[19] == 308);
        UT_ASSERT_TRUE(crco.first[20] == 312);
        UT_ASSERT_TRUE(crco.first[21] == 332);
        UT_ASSERT_TRUE(crco.first[22] == 337);
        UT_ASSERT_TRUE(crco.first[23] == 344);
        UT_ASSERT_TRUE(crco.first[24] == 352);
        UT_ASSERT_TRUE(crco.first[25] == 362);
        UT_ASSERT_TRUE(crco.first[26] == 394);
        UT_ASSERT_TRUE(crco.first[27] == 395);
        UT_ASSERT_TRUE(crco.first[28] == 398);
        UT_ASSERT_TRUE(crco.first[29] == 406);
        UT_ASSERT_TRUE(crco.first[30] == 431);
        UT_ASSERT_TRUE(crco.first[31] == 437);
        UT_ASSERT_TRUE(crco.first[32] == 439);
        UT_ASSERT_TRUE(crco.first[33] == 441);
        UT_ASSERT_TRUE(crco.first[34] == 456);
        UT_ASSERT_TRUE(crco.first[35] == 488);

        crco = clauses_repr_clauses_of(cr, 20);
        UT_ASSERT_TRUE(crco.len == 44);
        UT_ASSERT_TRUE(crco.first[0] == 0);
        UT_ASSERT_TRUE(crco.first[1] == 19);
        UT_ASSERT_TRUE(crco.first[2] == 25);
        UT_ASSERT_TRUE(crco.first[3] == 28);
        UT_ASSERT_TRUE(crco.first[4] == 38);
        UT_ASSERT_TRUE(crco.first[5] == 55);
        UT_ASSERT_TRUE(crco.first[6] == 59);
        UT_ASSERT_TRUE(crco.first[7] == 64);
        UT_ASSERT_TRUE(crco.first[8] == 70);
        UT_ASSERT_TRUE(crco.first[9] == 90);
        UT_ASSERT_TRUE(crco.first[10] == 95);
        UT_ASSERT_TRUE(crco.first[11] == 104);
        UT_ASSERT_TRUE(crco.first[12] == 112);
        UT_ASSERT_TRUE(crco.first[13] == 121);
        UT_ASSERT_TRUE(crco.first[14] == 154);
        UT_ASSERT_TRUE(crco.first[15] == 171);
        UT_ASSERT_TRUE(crco.first[16] == 187);
        UT_ASSERT_TRUE(crco.first[17] == 190);
        UT_ASSERT_TRUE(crco.first[18] == 201);
        UT_ASSERT_TRUE(crco.first[19] == 231);
        UT_ASSERT_TRUE(crco.first[20] == 237);
        UT_ASSERT_TRUE(crco.first[21] == 242);
        UT_ASSERT_TRUE(crco.first[22] == 245);
        UT_ASSERT_TRUE(crco.first[23] == 262);
        UT_ASSERT_TRUE(crco.first[24] == 266);
        UT_ASSERT_TRUE(crco.first[25] == 296);
        UT_ASSERT_TRUE(crco.first[26] == 297);
        UT_ASSERT_TRUE(crco.first[27] == 314);
        UT_ASSERT_TRUE(crco.first[28] == 320);
        UT_ASSERT_TRUE(crco.first[29] == 323);
        UT_ASSERT_TRUE(crco.first[30] == 325);
        UT_ASSERT_TRUE(crco.first[31] == 330);
        UT_ASSERT_TRUE(crco.first[32] == 358);
        UT_ASSERT_TRUE(crco.first[33] == 367);
        UT_ASSERT_TRUE(crco.first[34] == 368);
        UT_ASSERT_TRUE(crco.first[35] == 381);
        UT_ASSERT_TRUE(crco.first[36] == 384);
        UT_ASSERT_TRUE(crco.first[37] == 398);
        UT_ASSERT_TRUE(crco.first[38] == 416);
        UT_ASSERT_TRUE(crco.first[39] == 419);
        UT_ASSERT_TRUE(crco.first[40] == 435);
        UT_ASSERT_TRUE(crco.first[41] == 471);
        UT_ASSERT_TRUE(crco.first[42] == 489);
        UT_ASSERT_TRUE(crco.first[43] == 493);

        crco = clauses_repr_clauses_of(cr, 21);
        UT_ASSERT_TRUE(crco.len == 53);
        UT_ASSERT_TRUE(crco.first[0] == 35);
        UT_ASSERT_TRUE(crco.first[1] == 40);
        UT_ASSERT_TRUE(crco.first[2] == 46);
        UT_ASSERT_TRUE(crco.first[3] == 49);
        UT_ASSERT_TRUE(crco.first[4] == 61);
        UT_ASSERT_TRUE(crco.first[5] == 63);
        UT_ASSERT_TRUE(crco.first[6] == 87);
        UT_ASSERT_TRUE(crco.first[7] == 91);
        UT_ASSERT_TRUE(crco.first[8] == 98);
        UT_ASSERT_TRUE(crco.first[9] == 107);
        UT_ASSERT_TRUE(crco.first[10] == 116);
        UT_ASSERT_TRUE(crco.first[11] == 125);
        UT_ASSERT_TRUE(crco.first[12] == 144);
        UT_ASSERT_TRUE(crco.first[13] == 155);
        UT_ASSERT_TRUE(crco.first[14] == 170);
        UT_ASSERT_TRUE(crco.first[15] == 176);
        UT_ASSERT_TRUE(crco.first[16] == 188);
        UT_ASSERT_TRUE(crco.first[17] == 198);
        UT_ASSERT_TRUE(crco.first[18] == 200);
        UT_ASSERT_TRUE(crco.first[19] == 203);
        UT_ASSERT_TRUE(crco.first[20] == 212);
        UT_ASSERT_TRUE(crco.first[21] == 234);
        UT_ASSERT_TRUE(crco.first[22] == 243);
        UT_ASSERT_TRUE(crco.first[23] == 255);
        UT_ASSERT_TRUE(crco.first[24] == 256);
        UT_ASSERT_TRUE(crco.first[25] == 259);
        UT_ASSERT_TRUE(crco.first[26] == 265);
        UT_ASSERT_TRUE(crco.first[27] == 266);
        UT_ASSERT_TRUE(crco.first[28] == 276);
        UT_ASSERT_TRUE(crco.first[29] == 279);
        UT_ASSERT_TRUE(crco.first[30] == 282);
        UT_ASSERT_TRUE(crco.first[31] == 322);
        UT_ASSERT_TRUE(crco.first[32] == 324);
        UT_ASSERT_TRUE(crco.first[33] == 326);
        UT_ASSERT_TRUE(crco.first[34] == 347);
        UT_ASSERT_TRUE(crco.first[35] == 348);
        UT_ASSERT_TRUE(crco.first[36] == 354);
        UT_ASSERT_TRUE(crco.first[37] == 366);
        UT_ASSERT_TRUE(crco.first[38] == 369);
        UT_ASSERT_TRUE(crco.first[39] == 371);
        UT_ASSERT_TRUE(crco.first[40] == 387);
        UT_ASSERT_TRUE(crco.first[41] == 393);
        UT_ASSERT_TRUE(crco.first[42] == 403);
        UT_ASSERT_TRUE(crco.first[43] == 405);
        UT_ASSERT_TRUE(crco.first[44] == 448);
        UT_ASSERT_TRUE(crco.first[45] == 461);
        UT_ASSERT_TRUE(crco.first[46] == 464);
        UT_ASSERT_TRUE(crco.first[47] == 466);
        UT_ASSERT_TRUE(crco.first[48] == 477);
        UT_ASSERT_TRUE(crco.first[49] == 480);
        UT_ASSERT_TRUE(crco.first[50] == 487);
        UT_ASSERT_TRUE(crco.first[51] == 491);
        UT_ASSERT_TRUE(crco.first[52] == 496);

        crco = clauses_repr_clauses_of(cr, 22);
        UT_ASSERT_TRUE(crco.len == 54);
        UT_ASSERT_TRUE(crco.first[0] == 11);
        UT_ASSERT_TRUE(crco.first[1] == 26);
        UT_ASSERT_TRUE(crco.first[2] == 34);
        UT_ASSERT_TRUE(crco.first[3] == 37);
        UT_ASSERT_TRUE(crco.first[4] == 38);
        UT_ASSERT_TRUE(crco.first[5] == 53);
        UT_ASSERT_TRUE(crco.first[6] == 71);
        UT_ASSERT_TRUE(crco.first[7] == 72);
        UT_ASSERT_TRUE(crco.first[8] == 83);
        UT_ASSERT_TRUE(crco.first[9] == 87);
        UT_ASSERT_TRUE(crco.first[10] == 96);
        UT_ASSERT_TRUE(crco.first[11] == 104);
        UT_ASSERT_TRUE(crco.first[12] == 123);
        UT_ASSERT_TRUE(crco.first[13] == 143);
        UT_ASSERT_TRUE(crco.first[14] == 162);
        UT_ASSERT_TRUE(crco.first[15] == 164);
        UT_ASSERT_TRUE(crco.first[16] == 189);
        UT_ASSERT_TRUE(crco.first[17] == 193);
        UT_ASSERT_TRUE(crco.first[18] == 202);
        UT_ASSERT_TRUE(crco.first[19] == 210);
        UT_ASSERT_TRUE(crco.first[20] == 211);
        UT_ASSERT_TRUE(crco.first[21] == 220);
        UT_ASSERT_TRUE(crco.first[22] == 229);
        UT_ASSERT_TRUE(crco.first[23] == 230);
        UT_ASSERT_TRUE(crco.first[24] == 235);
        UT_ASSERT_TRUE(crco.first[25] == 237);
        UT_ASSERT_TRUE(crco.first[26] == 244);
        UT_ASSERT_TRUE(crco.first[27] == 254);
        UT_ASSERT_TRUE(crco.first[28] == 270);
        UT_ASSERT_TRUE(crco.first[29] == 281);
        UT_ASSERT_TRUE(crco.first[30] == 290);
        UT_ASSERT_TRUE(crco.first[31] == 298);
        UT_ASSERT_TRUE(crco.first[32] == 305);
        UT_ASSERT_TRUE(crco.first[33] == 307);
        UT_ASSERT_TRUE(crco.first[34] == 313);
        UT_ASSERT_TRUE(crco.first[35] == 317);
        UT_ASSERT_TRUE(crco.first[36] == 328);
        UT_ASSERT_TRUE(crco.first[37] == 355);
        UT_ASSERT_TRUE(crco.first[38] == 360);
        UT_ASSERT_TRUE(crco.first[39] == 363);
        UT_ASSERT_TRUE(crco.first[40] == 369);
        UT_ASSERT_TRUE(crco.first[41] == 370);
        UT_ASSERT_TRUE(crco.first[42] == 376);
        UT_ASSERT_TRUE(crco.first[43] == 378);
        UT_ASSERT_TRUE(crco.first[44] == 399);
        UT_ASSERT_TRUE(crco.first[45] == 413);
        UT_ASSERT_TRUE(crco.first[46] == 424);
        UT_ASSERT_TRUE(crco.first[47] == 450);
        UT_ASSERT_TRUE(crco.first[48] == 453);
        UT_ASSERT_TRUE(crco.first[49] == 456);
        UT_ASSERT_TRUE(crco.first[50] == 463);
        UT_ASSERT_TRUE(crco.first[51] == 466);
        UT_ASSERT_TRUE(crco.first[52] == 481);
        UT_ASSERT_TRUE(crco.first[53] == 492);

        crco = clauses_repr_clauses_of(cr, 23);
        UT_ASSERT_TRUE(crco.len == 63);
        UT_ASSERT_TRUE(crco.first[0] == 5);
        UT_ASSERT_TRUE(crco.first[1] == 7);
        UT_ASSERT_TRUE(crco.first[2] == 10);
        UT_ASSERT_TRUE(crco.first[3] == 13);
        UT_ASSERT_TRUE(crco.first[4] == 28);
        UT_ASSERT_TRUE(crco.first[5] == 31);
        UT_ASSERT_TRUE(crco.first[6] == 47);
        UT_ASSERT_TRUE(crco.first[7] == 52);
        UT_ASSERT_TRUE(crco.first[8] == 61);
        UT_ASSERT_TRUE(crco.first[9] == 77);
        UT_ASSERT_TRUE(crco.first[10] == 85);
        UT_ASSERT_TRUE(crco.first[11] == 94);
        UT_ASSERT_TRUE(crco.first[12] == 106);
        UT_ASSERT_TRUE(crco.first[13] == 117);
        UT_ASSERT_TRUE(crco.first[14] == 126);
        UT_ASSERT_TRUE(crco.first[15] == 127);
        UT_ASSERT_TRUE(crco.first[16] == 160);
        UT_ASSERT_TRUE(crco.first[17] == 161);
        UT_ASSERT_TRUE(crco.first[18] == 180);
        UT_ASSERT_TRUE(crco.first[19] == 183);
        UT_ASSERT_TRUE(crco.first[20] == 194);
        UT_ASSERT_TRUE(crco.first[21] == 207);
        UT_ASSERT_TRUE(crco.first[22] == 215);
        UT_ASSERT_TRUE(crco.first[23] == 217);
        UT_ASSERT_TRUE(crco.first[24] == 219);
        UT_ASSERT_TRUE(crco.first[25] == 249);
        UT_ASSERT_TRUE(crco.first[26] == 250);
        UT_ASSERT_TRUE(crco.first[27] == 251);
        UT_ASSERT_TRUE(crco.first[28] == 255);
        UT_ASSERT_TRUE(crco.first[29] == 258);
        UT_ASSERT_TRUE(crco.first[30] == 260);
        UT_ASSERT_TRUE(crco.first[31] == 261);
        UT_ASSERT_TRUE(crco.first[32] == 265);
        UT_ASSERT_TRUE(crco.first[33] == 278);
        UT_ASSERT_TRUE(crco.first[34] == 282);
        UT_ASSERT_TRUE(crco.first[35] == 291);
        UT_ASSERT_TRUE(crco.first[36] == 301);
        UT_ASSERT_TRUE(crco.first[37] == 304);
        UT_ASSERT_TRUE(crco.first[38] == 318);
        UT_ASSERT_TRUE(crco.first[39] == 321);
        UT_ASSERT_TRUE(crco.first[40] == 322);
        UT_ASSERT_TRUE(crco.first[41] == 335);
        UT_ASSERT_TRUE(crco.first[42] == 339);
        UT_ASSERT_TRUE(crco.first[43] == 342);
        UT_ASSERT_TRUE(crco.first[44] == 346);
        UT_ASSERT_TRUE(crco.first[45] == 357);
        UT_ASSERT_TRUE(crco.first[46] == 359);
        UT_ASSERT_TRUE(crco.first[47] == 379);
        UT_ASSERT_TRUE(crco.first[48] == 385);
        UT_ASSERT_TRUE(crco.first[49] == 391);
        UT_ASSERT_TRUE(crco.first[50] == 407);
        UT_ASSERT_TRUE(crco.first[51] == 411);
        UT_ASSERT_TRUE(crco.first[52] == 420);
        UT_ASSERT_TRUE(crco.first[53] == 422);
        UT_ASSERT_TRUE(crco.first[54] == 428);
        UT_ASSERT_TRUE(crco.first[55] == 431);
        UT_ASSERT_TRUE(crco.first[56] == 451);
        UT_ASSERT_TRUE(crco.first[57] == 453);
        UT_ASSERT_TRUE(crco.first[58] == 456);
        UT_ASSERT_TRUE(crco.first[59] == 460);
        UT_ASSERT_TRUE(crco.first[60] == 472);
        UT_ASSERT_TRUE(crco.first[61] == 492);
        UT_ASSERT_TRUE(crco.first[62] == 496);

        crco = clauses_repr_clauses_of(cr, 24);
        UT_ASSERT_TRUE(crco.len == 40);
        UT_ASSERT_TRUE(crco.first[0] == 9);
        UT_ASSERT_TRUE(crco.first[1] == 12);
        UT_ASSERT_TRUE(crco.first[2] == 30);
        UT_ASSERT_TRUE(crco.first[3] == 41);
        UT_ASSERT_TRUE(crco.first[4] == 46);
        UT_ASSERT_TRUE(crco.first[5] == 66);
        UT_ASSERT_TRUE(crco.first[6] == 69);
        UT_ASSERT_TRUE(crco.first[7] == 100);
        UT_ASSERT_TRUE(crco.first[8] == 107);
        UT_ASSERT_TRUE(crco.first[9] == 108);
        UT_ASSERT_TRUE(crco.first[10] == 122);
        UT_ASSERT_TRUE(crco.first[11] == 126);
        UT_ASSERT_TRUE(crco.first[12] == 137);
        UT_ASSERT_TRUE(crco.first[13] == 154);
        UT_ASSERT_TRUE(crco.first[14] == 157);
        UT_ASSERT_TRUE(crco.first[15] == 172);
        UT_ASSERT_TRUE(crco.first[16] == 197);
        UT_ASSERT_TRUE(crco.first[17] == 238);
        UT_ASSERT_TRUE(crco.first[18] == 239);
        UT_ASSERT_TRUE(crco.first[19] == 285);
        UT_ASSERT_TRUE(crco.first[20] == 314);
        UT_ASSERT_TRUE(crco.first[21] == 316);
        UT_ASSERT_TRUE(crco.first[22] == 340);
        UT_ASSERT_TRUE(crco.first[23] == 341);
        UT_ASSERT_TRUE(crco.first[24] == 348);
        UT_ASSERT_TRUE(crco.first[25] == 364);
        UT_ASSERT_TRUE(crco.first[26] == 376);
        UT_ASSERT_TRUE(crco.first[27] == 404);
        UT_ASSERT_TRUE(crco.first[28] == 405);
        UT_ASSERT_TRUE(crco.first[29] == 431);
        UT_ASSERT_TRUE(crco.first[30] == 432);
        UT_ASSERT_TRUE(crco.first[31] == 435);
        UT_ASSERT_TRUE(crco.first[32] == 442);
        UT_ASSERT_TRUE(crco.first[33] == 443);
        UT_ASSERT_TRUE(crco.first[34] == 448);
        UT_ASSERT_TRUE(crco.first[35] == 451);
        UT_ASSERT_TRUE(crco.first[36] == 472);
        UT_ASSERT_TRUE(crco.first[37] == 483);
        UT_ASSERT_TRUE(crco.first[38] == 485);
        UT_ASSERT_TRUE(crco.first[39] == 489);

        crco = clauses_repr_clauses_of(cr, 25);
        UT_ASSERT_TRUE(crco.len == 45);
        UT_ASSERT_TRUE(crco.first[0] == 8);
        UT_ASSERT_TRUE(crco.first[1] == 21);
        UT_ASSERT_TRUE(crco.first[2] == 26);
        UT_ASSERT_TRUE(crco.first[3] == 27);
        UT_ASSERT_TRUE(crco.first[4] == 36);
        UT_ASSERT_TRUE(crco.first[5] == 39);
        UT_ASSERT_TRUE(crco.first[6] == 58);
        UT_ASSERT_TRUE(crco.first[7] == 72);
        UT_ASSERT_TRUE(crco.first[8] == 83);
        UT_ASSERT_TRUE(crco.first[9] == 100);
        UT_ASSERT_TRUE(crco.first[10] == 102);
        UT_ASSERT_TRUE(crco.first[11] == 107);
        UT_ASSERT_TRUE(crco.first[12] == 110);
        UT_ASSERT_TRUE(crco.first[13] == 131);
        UT_ASSERT_TRUE(crco.first[14] == 140);
        UT_ASSERT_TRUE(crco.first[15] == 149);
        UT_ASSERT_TRUE(crco.first[16] == 151);
        UT_ASSERT_TRUE(crco.first[17] == 157);
        UT_ASSERT_TRUE(crco.first[18] == 185);
        UT_ASSERT_TRUE(crco.first[19] == 190);
        UT_ASSERT_TRUE(crco.first[20] == 204);
        UT_ASSERT_TRUE(crco.first[21] == 226);
        UT_ASSERT_TRUE(crco.first[22] == 248);
        UT_ASSERT_TRUE(crco.first[23] == 271);
        UT_ASSERT_TRUE(crco.first[24] == 278);
        UT_ASSERT_TRUE(crco.first[25] == 292);
        UT_ASSERT_TRUE(crco.first[26] == 304);
        UT_ASSERT_TRUE(crco.first[27] == 315);
        UT_ASSERT_TRUE(crco.first[28] == 319);
        UT_ASSERT_TRUE(crco.first[29] == 330);
        UT_ASSERT_TRUE(crco.first[30] == 333);
        UT_ASSERT_TRUE(crco.first[31] == 360);
        UT_ASSERT_TRUE(crco.first[32] == 389);
        UT_ASSERT_TRUE(crco.first[33] == 400);
        UT_ASSERT_TRUE(crco.first[34] == 418);
        UT_ASSERT_TRUE(crco.first[35] == 421);
        UT_ASSERT_TRUE(crco.first[36] == 446);
        UT_ASSERT_TRUE(crco.first[37] == 453);
        UT_ASSERT_TRUE(crco.first[38] == 459);
        UT_ASSERT_TRUE(crco.first[39] == 461);
        UT_ASSERT_TRUE(crco.first[40] == 472);
        UT_ASSERT_TRUE(crco.first[41] == 479);
        UT_ASSERT_TRUE(crco.first[42] == 489);
        UT_ASSERT_TRUE(crco.first[43] == 495);
        UT_ASSERT_TRUE(crco.first[44] == 497);

        crco = clauses_repr_clauses_of(cr, 26);
        UT_ASSERT_TRUE(crco.len == 57);
        UT_ASSERT_TRUE(crco.first[0] == 0);
        UT_ASSERT_TRUE(crco.first[1] == 10);
        UT_ASSERT_TRUE(crco.first[2] == 15);
        UT_ASSERT_TRUE(crco.first[3] == 22);
        UT_ASSERT_TRUE(crco.first[4] == 23);
        UT_ASSERT_TRUE(crco.first[5] == 24);
        UT_ASSERT_TRUE(crco.first[6] == 40);
        UT_ASSERT_TRUE(crco.first[7] == 43);
        UT_ASSERT_TRUE(crco.first[8] == 57);
        UT_ASSERT_TRUE(crco.first[9] == 60);
        UT_ASSERT_TRUE(crco.first[10] == 70);
        UT_ASSERT_TRUE(crco.first[11] == 72);
        UT_ASSERT_TRUE(crco.first[12] == 77);
        UT_ASSERT_TRUE(crco.first[13] == 84);
        UT_ASSERT_TRUE(crco.first[14] == 86);
        UT_ASSERT_TRUE(crco.first[15] == 105);
        UT_ASSERT_TRUE(crco.first[16] == 117);
        UT_ASSERT_TRUE(crco.first[17] == 118);
        UT_ASSERT_TRUE(crco.first[18] == 146);
        UT_ASSERT_TRUE(crco.first[19] == 149);
        UT_ASSERT_TRUE(crco.first[20] == 150);
        UT_ASSERT_TRUE(crco.first[21] == 163);
        UT_ASSERT_TRUE(crco.first[22] == 167);
        UT_ASSERT_TRUE(crco.first[23] == 183);
        UT_ASSERT_TRUE(crco.first[24] == 184);
        UT_ASSERT_TRUE(crco.first[25] == 208);
        UT_ASSERT_TRUE(crco.first[26] == 213);
        UT_ASSERT_TRUE(crco.first[27] == 259);
        UT_ASSERT_TRUE(crco.first[28] == 267);
        UT_ASSERT_TRUE(crco.first[29] == 269);
        UT_ASSERT_TRUE(crco.first[30] == 271);
        UT_ASSERT_TRUE(crco.first[31] == 288);
        UT_ASSERT_TRUE(crco.first[32] == 291);
        UT_ASSERT_TRUE(crco.first[33] == 299);
        UT_ASSERT_TRUE(crco.first[34] == 322);
        UT_ASSERT_TRUE(crco.first[35] == 336);
        UT_ASSERT_TRUE(crco.first[36] == 341);
        UT_ASSERT_TRUE(crco.first[37] == 344);
        UT_ASSERT_TRUE(crco.first[38] == 355);
        UT_ASSERT_TRUE(crco.first[39] == 365);
        UT_ASSERT_TRUE(crco.first[40] == 382);
        UT_ASSERT_TRUE(crco.first[41] == 385);
        UT_ASSERT_TRUE(crco.first[42] == 388);
        UT_ASSERT_TRUE(crco.first[43] == 392);
        UT_ASSERT_TRUE(crco.first[44] == 402);
        UT_ASSERT_TRUE(crco.first[45] == 403);
        UT_ASSERT_TRUE(crco.first[46] == 407);
        UT_ASSERT_TRUE(crco.first[47] == 417);
        UT_ASSERT_TRUE(crco.first[48] == 421);
        UT_ASSERT_TRUE(crco.first[49] == 423);
        UT_ASSERT_TRUE(crco.first[50] == 425);
        UT_ASSERT_TRUE(crco.first[51] == 427);
        UT_ASSERT_TRUE(crco.first[52] == 434);
        UT_ASSERT_TRUE(crco.first[53] == 439);
        UT_ASSERT_TRUE(crco.first[54] == 461);
        UT_ASSERT_TRUE(crco.first[55] == 467);
        UT_ASSERT_TRUE(crco.first[56] == 488);

        crco = clauses_repr_clauses_of(cr, 27);
        UT_ASSERT_TRUE(crco.len == 52);
        UT_ASSERT_TRUE(crco.first[0] == 1);
        UT_ASSERT_TRUE(crco.first[1] == 4);
        UT_ASSERT_TRUE(crco.first[2] == 6);
        UT_ASSERT_TRUE(crco.first[3] == 10);
        UT_ASSERT_TRUE(crco.first[4] == 17);
        UT_ASSERT_TRUE(crco.first[5] == 19);
        UT_ASSERT_TRUE(crco.first[6] == 45);
        UT_ASSERT_TRUE(crco.first[7] == 51);
        UT_ASSERT_TRUE(crco.first[8] == 73);
        UT_ASSERT_TRUE(crco.first[9] == 82);
        UT_ASSERT_TRUE(crco.first[10] == 95);
        UT_ASSERT_TRUE(crco.first[11] == 103);
        UT_ASSERT_TRUE(crco.first[12] == 108);
        UT_ASSERT_TRUE(crco.first[13] == 119);
        UT_ASSERT_TRUE(crco.first[14] == 120);
        UT_ASSERT_TRUE(crco.first[15] == 146);
        UT_ASSERT_TRUE(crco.first[16] == 152);
        UT_ASSERT_TRUE(crco.first[17] == 164);
        UT_ASSERT_TRUE(crco.first[18] == 167);
        UT_ASSERT_TRUE(crco.first[19] == 178);
        UT_ASSERT_TRUE(crco.first[20] == 188);
        UT_ASSERT_TRUE(crco.first[21] == 191);
        UT_ASSERT_TRUE(crco.first[22] == 195);
        UT_ASSERT_TRUE(crco.first[23] == 208);
        UT_ASSERT_TRUE(crco.first[24] == 220);
        UT_ASSERT_TRUE(crco.first[25] == 236);
        UT_ASSERT_TRUE(crco.first[26] == 242);
        UT_ASSERT_TRUE(crco.first[27] == 265);
        UT_ASSERT_TRUE(crco.first[28] == 276);
        UT_ASSERT_TRUE(crco.first[29] == 286);
        UT_ASSERT_TRUE(crco.first[30] == 290);
        UT_ASSERT_TRUE(crco.first[31] == 295);
        UT_ASSERT_TRUE(crco.first[32] == 300);
        UT_ASSERT_TRUE(crco.first[33] == 302);
        UT_ASSERT_TRUE(crco.first[34] == 313);
        UT_ASSERT_TRUE(crco.first[35] == 317);
        UT_ASSERT_TRUE(crco.first[36] == 324);
        UT_ASSERT_TRUE(crco.first[37] == 349);
        UT_ASSERT_TRUE(crco.first[38] == 360);
        UT_ASSERT_TRUE(crco.first[39] == 371);
        UT_ASSERT_TRUE(crco.first[40] == 399);
        UT_ASSERT_TRUE(crco.first[41] == 411);
        UT_ASSERT_TRUE(crco.first[42] == 414);
        UT_ASSERT_TRUE(crco.first[43] == 436);
        UT_ASSERT_TRUE(crco.first[44] == 455);
        UT_ASSERT_TRUE(crco.first[45] == 469);
        UT_ASSERT_TRUE(crco.first[46] == 473);
        UT_ASSERT_TRUE(crco.first[47] == 476);
        UT_ASSERT_TRUE(crco.first[48] == 480);
        UT_ASSERT_TRUE(crco.first[49] == 481);
        UT_ASSERT_TRUE(crco.first[50] == 488);
        UT_ASSERT_TRUE(crco.first[51] == 499);

        crco = clauses_repr_clauses_of(cr, 28);
        UT_ASSERT_TRUE(crco.len == 46);
        UT_ASSERT_TRUE(crco.first[0] == 8);
        UT_ASSERT_TRUE(crco.first[1] == 56);
        UT_ASSERT_TRUE(crco.first[2] == 57);
        UT_ASSERT_TRUE(crco.first[3] == 60);
        UT_ASSERT_TRUE(crco.first[4] == 79);
        UT_ASSERT_TRUE(crco.first[5] == 81);
        UT_ASSERT_TRUE(crco.first[6] == 102);
        UT_ASSERT_TRUE(crco.first[7] == 127);
        UT_ASSERT_TRUE(crco.first[8] == 131);
        UT_ASSERT_TRUE(crco.first[9] == 141);
        UT_ASSERT_TRUE(crco.first[10] == 144);
        UT_ASSERT_TRUE(crco.first[11] == 159);
        UT_ASSERT_TRUE(crco.first[12] == 168);
        UT_ASSERT_TRUE(crco.first[13] == 172);
        UT_ASSERT_TRUE(crco.first[14] == 180);
        UT_ASSERT_TRUE(crco.first[15] == 198);
        UT_ASSERT_TRUE(crco.first[16] == 205);
        UT_ASSERT_TRUE(crco.first[17] == 212);
        UT_ASSERT_TRUE(crco.first[18] == 219);
        UT_ASSERT_TRUE(crco.first[19] == 224);
        UT_ASSERT_TRUE(crco.first[20] == 235);
        UT_ASSERT_TRUE(crco.first[21] == 268);
        UT_ASSERT_TRUE(crco.first[22] == 274);
        UT_ASSERT_TRUE(crco.first[23] == 285);
        UT_ASSERT_TRUE(crco.first[24] == 292);
        UT_ASSERT_TRUE(crco.first[25] == 298);
        UT_ASSERT_TRUE(crco.first[26] == 300);
        UT_ASSERT_TRUE(crco.first[27] == 301);
        UT_ASSERT_TRUE(crco.first[28] == 303);
        UT_ASSERT_TRUE(crco.first[29] == 332);
        UT_ASSERT_TRUE(crco.first[30] == 336);
        UT_ASSERT_TRUE(crco.first[31] == 338);
        UT_ASSERT_TRUE(crco.first[32] == 352);
        UT_ASSERT_TRUE(crco.first[33] == 354);
        UT_ASSERT_TRUE(crco.first[34] == 361);
        UT_ASSERT_TRUE(crco.first[35] == 368);
        UT_ASSERT_TRUE(crco.first[36] == 390);
        UT_ASSERT_TRUE(crco.first[37] == 408);
        UT_ASSERT_TRUE(crco.first[38] == 409);
        UT_ASSERT_TRUE(crco.first[39] == 422);
        UT_ASSERT_TRUE(crco.first[40] == 430);
        UT_ASSERT_TRUE(crco.first[41] == 447);
        UT_ASSERT_TRUE(crco.first[42] == 457);
        UT_ASSERT_TRUE(crco.first[43] == 468);
        UT_ASSERT_TRUE(crco.first[44] == 483);
        UT_ASSERT_TRUE(crco.first[45] == 491);

        crco = clauses_repr_clauses_of(cr, 29);
        UT_ASSERT_TRUE(crco.len == 39);
        UT_ASSERT_TRUE(crco.first[0] == 12);
        UT_ASSERT_TRUE(crco.first[1] == 14);
        UT_ASSERT_TRUE(crco.first[2] == 46);
        UT_ASSERT_TRUE(crco.first[3] == 60);
        UT_ASSERT_TRUE(crco.first[4] == 63);
        UT_ASSERT_TRUE(crco.first[5] == 65);
        UT_ASSERT_TRUE(crco.first[6] == 69);
        UT_ASSERT_TRUE(crco.first[7] == 73);
        UT_ASSERT_TRUE(crco.first[8] == 112);
        UT_ASSERT_TRUE(crco.first[9] == 115);
        UT_ASSERT_TRUE(crco.first[10] == 116);
        UT_ASSERT_TRUE(crco.first[11] == 128);
        UT_ASSERT_TRUE(crco.first[12] == 173);
        UT_ASSERT_TRUE(crco.first[13] == 176);
        UT_ASSERT_TRUE(crco.first[14] == 181);
        UT_ASSERT_TRUE(crco.first[15] == 188);
        UT_ASSERT_TRUE(crco.first[16] == 199);
        UT_ASSERT_TRUE(crco.first[17] == 209);
        UT_ASSERT_TRUE(crco.first[18] == 225);
        UT_ASSERT_TRUE(crco.first[19] == 232);
        UT_ASSERT_TRUE(crco.first[20] == 239);
        UT_ASSERT_TRUE(crco.first[21] == 244);
        UT_ASSERT_TRUE(crco.first[22] == 246);
        UT_ASSERT_TRUE(crco.first[23] == 254);
        UT_ASSERT_TRUE(crco.first[24] == 255);
        UT_ASSERT_TRUE(crco.first[25] == 273);
        UT_ASSERT_TRUE(crco.first[26] == 297);
        UT_ASSERT_TRUE(crco.first[27] == 310);
        UT_ASSERT_TRUE(crco.first[28] == 311);
        UT_ASSERT_TRUE(crco.first[29] == 321);
        UT_ASSERT_TRUE(crco.first[30] == 328);
        UT_ASSERT_TRUE(crco.first[31] == 329);
        UT_ASSERT_TRUE(crco.first[32] == 343);
        UT_ASSERT_TRUE(crco.first[33] == 351);
        UT_ASSERT_TRUE(crco.first[34] == 372);
        UT_ASSERT_TRUE(crco.first[35] == 391);
        UT_ASSERT_TRUE(crco.first[36] == 473);
        UT_ASSERT_TRUE(crco.first[37] == 475);
        UT_ASSERT_TRUE(crco.first[38] == 496);

        crco = clauses_repr_clauses_of(cr, 30);
        UT_ASSERT_TRUE(crco.len == 54);
        UT_ASSERT_TRUE(crco.first[0] == 3);
        UT_ASSERT_TRUE(crco.first[1] == 13);
        UT_ASSERT_TRUE(crco.first[2] == 26);
        UT_ASSERT_TRUE(crco.first[3] == 30);
        UT_ASSERT_TRUE(crco.first[4] == 32);
        UT_ASSERT_TRUE(crco.first[5] == 62);
        UT_ASSERT_TRUE(crco.first[6] == 68);
        UT_ASSERT_TRUE(crco.first[7] == 76);
        UT_ASSERT_TRUE(crco.first[8] == 81);
        UT_ASSERT_TRUE(crco.first[9] == 113);
        UT_ASSERT_TRUE(crco.first[10] == 117);
        UT_ASSERT_TRUE(crco.first[11] == 132);
        UT_ASSERT_TRUE(crco.first[12] == 137);
        UT_ASSERT_TRUE(crco.first[13] == 140);
        UT_ASSERT_TRUE(crco.first[14] == 147);
        UT_ASSERT_TRUE(crco.first[15] == 153);
        UT_ASSERT_TRUE(crco.first[16] == 156);
        UT_ASSERT_TRUE(crco.first[17] == 179);
        UT_ASSERT_TRUE(crco.first[18] == 195);
        UT_ASSERT_TRUE(crco.first[19] == 203);
        UT_ASSERT_TRUE(crco.first[20] == 226);
        UT_ASSERT_TRUE(crco.first[21] == 233);
        UT_ASSERT_TRUE(crco.first[22] == 242);
        UT_ASSERT_TRUE(crco.first[23] == 247);
        UT_ASSERT_TRUE(crco.first[24] == 261);
        UT_ASSERT_TRUE(crco.first[25] == 271);
        UT_ASSERT_TRUE(crco.first[26] == 280);
        UT_ASSERT_TRUE(crco.first[27] == 283);
        UT_ASSERT_TRUE(crco.first[28] == 284);
        UT_ASSERT_TRUE(crco.first[29] == 307);
        UT_ASSERT_TRUE(crco.first[30] == 309);
        UT_ASSERT_TRUE(crco.first[31] == 325);
        UT_ASSERT_TRUE(crco.first[32] == 326);
        UT_ASSERT_TRUE(crco.first[33] == 332);
        UT_ASSERT_TRUE(crco.first[34] == 347);
        UT_ASSERT_TRUE(crco.first[35] == 350);
        UT_ASSERT_TRUE(crco.first[36] == 367);
        UT_ASSERT_TRUE(crco.first[37] == 370);
        UT_ASSERT_TRUE(crco.first[38] == 375);
        UT_ASSERT_TRUE(crco.first[39] == 380);
        UT_ASSERT_TRUE(crco.first[40] == 387);
        UT_ASSERT_TRUE(crco.first[41] == 392);
        UT_ASSERT_TRUE(crco.first[42] == 395);
        UT_ASSERT_TRUE(crco.first[43] == 404);
        UT_ASSERT_TRUE(crco.first[44] == 408);
        UT_ASSERT_TRUE(crco.first[45] == 423);
        UT_ASSERT_TRUE(crco.first[46] == 427);
        UT_ASSERT_TRUE(crco.first[47] == 430);
        UT_ASSERT_TRUE(crco.first[48] == 432);
        UT_ASSERT_TRUE(crco.first[49] == 441);
        UT_ASSERT_TRUE(crco.first[50] == 454);
        UT_ASSERT_TRUE(crco.first[51] == 466);
        UT_ASSERT_TRUE(crco.first[52] == 474);
        UT_ASSERT_TRUE(crco.first[53] == 475);
    }

    free_clauses_repr(cr);
    return 0;
}

UT_ENDTEST
