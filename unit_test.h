
#ifndef UNIT_TEST_H__
#define UNIT_TEST_H__

#include <stdio.h>

/*Defining "namescapes" by prefixing everything with namespace:
 * UNIT_TEST_ for internal unit_test code
 * UT_ for public unit_test interface (asserts, etc)*/


#define UNIT_TEST_PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
#define UNIT_TEST_CAT(a, ...) UNIT_TEST_PRIMITIVE_CAT(a, __VA_ARGS__)

#define UNIT_TEST_INC(X) UNIT_TEST_PRIMITIVE_CAT(UNIT_TEST_INC_, X)
#define UNIT_TEST_INC_0 1
#define UNIT_TEST_INC_1 2
#define UNIT_TEST_INC_2 3
#define UNIT_TEST_INC_3 4
#define UNIT_TEST_INC_4 5
#define UNIT_TEST_INC_5 6
#define UNIT_TEST_INC_6 7
#define UNIT_TEST_INC_7 8
#define UNIT_TEST_INC_8 9
#define UNIT_TEST_INC_9 10
#define UNIT_TEST_INC_10 11
#define UNIT_TEST_INC_11 12
#define UNIT_TEST_INC_12 13
#define UNIT_TEST_INC_13 14
#define UNIT_TEST_INC_14 15
#define UNIT_TEST_INC_15 16
#define UNIT_TEST_INC_16 17
#define UNIT_TEST_INC_17 18
#define UNIT_TEST_INC_18 19
#define UNIT_TEST_INC_19 20
#define UNIT_TEST_INC_20 21
#define UNIT_TEST_INC_21 22
#define UNIT_TEST_INC_22 23
#define UNIT_TEST_INC_23 24
#define UNIT_TEST_INC_24 25
#define UNIT_TEST_INC_25 26
#define UNIT_TEST_INC_26 27
#define UNIT_TEST_INC_27 28
#define UNIT_TEST_INC_28 29
#define UNIT_TEST_INC_29 30
#define UNIT_TEST_INC_30 31
#define UNIT_TEST_INC_31 32
#define UNIT_TEST_INC_32 33
#define UNIT_TEST_INC_33 34
#define UNIT_TEST_INC_34 35
#define UNIT_TEST_INC_35 36
#define UNIT_TEST_INC_36 37
#define UNIT_TEST_INC_37 38
#define UNIT_TEST_INC_38 39
#define UNIT_TEST_INC_39 40
#define UNIT_TEST_INC_40 41
#define UNIT_TEST_INC_41 42
#define UNIT_TEST_INC_42 43
#define UNIT_TEST_INC_43 44
#define UNIT_TEST_INC_44 45
#define UNIT_TEST_INC_45 46
#define UNIT_TEST_INC_46 47
#define UNIT_TEST_INC_47 48
#define UNIT_TEST_INC_48 49
#define UNIT_TEST_INC_49 50
#define UNIT_TEST_INC_50 51
#define UNIT_TEST_INC_51 52
#define UNIT_TEST_INC_52 53
#define UNIT_TEST_INC_53 54
#define UNIT_TEST_INC_54 55
#define UNIT_TEST_INC_55 56
#define UNIT_TEST_INC_56 57
#define UNIT_TEST_INC_57 58
#define UNIT_TEST_INC_58 59
#define UNIT_TEST_INC_59 60
#define UNIT_TEST_INC_60 61
#define UNIT_TEST_INC_61 62
#define UNIT_TEST_INC_62 63
#define UNIT_TEST_INC_63 64
#define UNIT_TEST_INC_64 65
#define UNIT_TEST_INC_65 66
#define UNIT_TEST_INC_66 67
#define UNIT_TEST_INC_67 68
#define UNIT_TEST_INC_68 69
#define UNIT_TEST_INC_69 70
#define UNIT_TEST_INC_70 71
#define UNIT_TEST_INC_71 72
#define UNIT_TEST_INC_72 73
#define UNIT_TEST_INC_73 74
#define UNIT_TEST_INC_74 75
#define UNIT_TEST_INC_75 76
#define UNIT_TEST_INC_76 77
#define UNIT_TEST_INC_77 78
#define UNIT_TEST_INC_78 79
#define UNIT_TEST_INC_79 80
#define UNIT_TEST_INC_80 81
#define UNIT_TEST_INC_81 82
#define UNIT_TEST_INC_82 83
#define UNIT_TEST_INC_83 84
#define UNIT_TEST_INC_84 85
#define UNIT_TEST_INC_85 86
#define UNIT_TEST_INC_86 87
#define UNIT_TEST_INC_87 88
#define UNIT_TEST_INC_88 89
#define UNIT_TEST_INC_89 90
#define UNIT_TEST_INC_90 91
#define UNIT_TEST_INC_91 92
#define UNIT_TEST_INC_92 93
#define UNIT_TEST_INC_93 94
#define UNIT_TEST_INC_94 95
#define UNIT_TEST_INC_95 96
#define UNIT_TEST_INC_96 97
#define UNIT_TEST_INC_97 98
#define UNIT_TEST_INC_98 99
#define UNIT_TEST_INC_99 100
#define UNIT_TEST_INC_100 101
#define UNIT_TEST_INC_101 102
#define UNIT_TEST_INC_102 103
#define UNIT_TEST_INC_103 104
#define UNIT_TEST_INC_104 105
#define UNIT_TEST_INC_105 106
#define UNIT_TEST_INC_106 107
#define UNIT_TEST_INC_107 108
#define UNIT_TEST_INC_108 109
#define UNIT_TEST_INC_109 110
#define UNIT_TEST_INC_110 111
#define UNIT_TEST_INC_111 112
#define UNIT_TEST_INC_112 113
#define UNIT_TEST_INC_113 114
#define UNIT_TEST_INC_114 115
#define UNIT_TEST_INC_115 116
#define UNIT_TEST_INC_116 117
#define UNIT_TEST_INC_117 118
#define UNIT_TEST_INC_118 119
#define UNIT_TEST_INC_119 120
#define UNIT_TEST_INC_120 121
#define UNIT_TEST_INC_121 122
#define UNIT_TEST_INC_122 123
#define UNIT_TEST_INC_123 124
#define UNIT_TEST_INC_124 125
#define UNIT_TEST_INC_125 126
#define UNIT_TEST_INC_126 127
#define UNIT_TEST_INC_127 128
#define UNIT_TEST_INC_128 129
#define UNIT_TEST_INC_129 130
#define UNIT_TEST_INC_130 131
#define UNIT_TEST_INC_131 132
#define UNIT_TEST_INC_132 133
#define UNIT_TEST_INC_133 134
#define UNIT_TEST_INC_134 135
#define UNIT_TEST_INC_135 136
#define UNIT_TEST_INC_136 137
#define UNIT_TEST_INC_137 138
#define UNIT_TEST_INC_138 139
#define UNIT_TEST_INC_139 140
#define UNIT_TEST_INC_140 141
#define UNIT_TEST_INC_141 142
#define UNIT_TEST_INC_142 143
#define UNIT_TEST_INC_143 144
#define UNIT_TEST_INC_144 145
#define UNIT_TEST_INC_145 146
#define UNIT_TEST_INC_146 147
#define UNIT_TEST_INC_147 148
#define UNIT_TEST_INC_148 149
#define UNIT_TEST_INC_149 150
#define UNIT_TEST_INC_150 151
#define UNIT_TEST_INC_151 152
#define UNIT_TEST_INC_152 153
#define UNIT_TEST_INC_153 154
#define UNIT_TEST_INC_154 155
#define UNIT_TEST_INC_155 156
#define UNIT_TEST_INC_156 157
#define UNIT_TEST_INC_157 158
#define UNIT_TEST_INC_158 159
#define UNIT_TEST_INC_159 160
#define UNIT_TEST_INC_160 161
#define UNIT_TEST_INC_161 162
#define UNIT_TEST_INC_162 163
#define UNIT_TEST_INC_163 164
#define UNIT_TEST_INC_164 165
#define UNIT_TEST_INC_165 166
#define UNIT_TEST_INC_166 167
#define UNIT_TEST_INC_167 168
#define UNIT_TEST_INC_168 169
#define UNIT_TEST_INC_169 170
#define UNIT_TEST_INC_170 171
#define UNIT_TEST_INC_171 172
#define UNIT_TEST_INC_172 173
#define UNIT_TEST_INC_173 174
#define UNIT_TEST_INC_174 175
#define UNIT_TEST_INC_175 176
#define UNIT_TEST_INC_176 177
#define UNIT_TEST_INC_177 178
#define UNIT_TEST_INC_178 179
#define UNIT_TEST_INC_179 180
#define UNIT_TEST_INC_180 181
#define UNIT_TEST_INC_181 182
#define UNIT_TEST_INC_182 183
#define UNIT_TEST_INC_183 184
#define UNIT_TEST_INC_184 185
#define UNIT_TEST_INC_185 186
#define UNIT_TEST_INC_186 187
#define UNIT_TEST_INC_187 188
#define UNIT_TEST_INC_188 189
#define UNIT_TEST_INC_189 190
#define UNIT_TEST_INC_190 191
#define UNIT_TEST_INC_191 192
#define UNIT_TEST_INC_192 193
#define UNIT_TEST_INC_193 194
#define UNIT_TEST_INC_194 195
#define UNIT_TEST_INC_195 196
#define UNIT_TEST_INC_196 197
#define UNIT_TEST_INC_197 198
#define UNIT_TEST_INC_198 199
#define UNIT_TEST_INC_199 200
#define UNIT_TEST_INC_200 201
#define UNIT_TEST_INC_201 202
#define UNIT_TEST_INC_202 203
#define UNIT_TEST_INC_203 204
#define UNIT_TEST_INC_204 205
#define UNIT_TEST_INC_205 206
#define UNIT_TEST_INC_206 207
#define UNIT_TEST_INC_207 208
#define UNIT_TEST_INC_208 209
#define UNIT_TEST_INC_209 210
#define UNIT_TEST_INC_210 211
#define UNIT_TEST_INC_211 212
#define UNIT_TEST_INC_212 213
#define UNIT_TEST_INC_213 214
#define UNIT_TEST_INC_214 215
#define UNIT_TEST_INC_215 216
#define UNIT_TEST_INC_216 217
#define UNIT_TEST_INC_217 218
#define UNIT_TEST_INC_218 219
#define UNIT_TEST_INC_219 220
#define UNIT_TEST_INC_220 221
#define UNIT_TEST_INC_221 222
#define UNIT_TEST_INC_222 223
#define UNIT_TEST_INC_223 224
#define UNIT_TEST_INC_224 225
#define UNIT_TEST_INC_225 226
#define UNIT_TEST_INC_226 227
#define UNIT_TEST_INC_227 228
#define UNIT_TEST_INC_228 229
#define UNIT_TEST_INC_229 230
#define UNIT_TEST_INC_230 231
#define UNIT_TEST_INC_231 232
#define UNIT_TEST_INC_232 233
#define UNIT_TEST_INC_233 234
#define UNIT_TEST_INC_234 235
#define UNIT_TEST_INC_235 236
#define UNIT_TEST_INC_236 237
#define UNIT_TEST_INC_237 238
#define UNIT_TEST_INC_238 239
#define UNIT_TEST_INC_239 240
#define UNIT_TEST_INC_240 241
#define UNIT_TEST_INC_241 242
#define UNIT_TEST_INC_242 243
#define UNIT_TEST_INC_243 244
#define UNIT_TEST_INC_244 245
#define UNIT_TEST_INC_245 246
#define UNIT_TEST_INC_246 247
#define UNIT_TEST_INC_247 248
#define UNIT_TEST_INC_248 249
#define UNIT_TEST_INC_249 250
#define UNIT_TEST_INC_250 251
#define UNIT_TEST_INC_251 252
#define UNIT_TEST_INC_252 253
#define UNIT_TEST_INC_253 254
#define UNIT_TEST_INC_254 255
#define UNIT_TEST_INC_255 255
#define MAX_NUM_TESTS 255


#define UNIT_TEST_ASSERT(X) if(!(X)) { fprintf(stderr, "'" #X "' failed assert, on line %d", __LINE__); }

struct UNIT_TEST_test {
    const char * test_name;
    int (*test_function)(void);
    struct UNIT_TEST_test (*next_test)(void);
};

#define UNIT_TEST_CREATE_TEST(FUNCTION, NUM) \
/*Forward declare next get_test function*/\
struct UNIT_TEST_test UNIT_TEST_CAT(UNIT_TEST_get_test, UNIT_TEST_INC(NUM)) (void);\
/*Forward declare user test function so we can return it in the get_test function*/\
int FUNCTION (void);\
/*Define get_test function that returns the test function to run and points to the next get_test function*/\
struct UNIT_TEST_test UNIT_TEST_CAT(UNIT_TEST_get_test, NUM) (void) { \
    struct UNIT_TEST_test t = { #FUNCTION, FUNCTION, UNIT_TEST_CAT(UNIT_TEST_get_test, UNIT_TEST_INC(NUM)) }; \
    UNIT_TEST_ASSERT(NUM < MAX_NUM_TESTS); \
    return t; \
} \
/*Test function definition. We just give the function declaration part.*/\
int FUNCTION (void) 


struct UNIT_TEST_test UNIT_TEST_get_test0(void);
int UNIT_TEST_test_initial_test(void) {
    return 0;
}
int UNIT_TEST_test_last_test(void) {
    return 0;
}

struct UNIT_TEST_test UNIT_TEST_get_initial_test(void) { 
    struct UNIT_TEST_test t =  {"initial_test", UNIT_TEST_test_initial_test, UNIT_TEST_get_test0};
    return t;
}

int main(void) {
    /*We're skipping the first test because it's ours and we don't care about it*/
    struct UNIT_TEST_test test = UNIT_TEST_get_initial_test().next_test();
    /*This way we don't run the last test (which is ours) because it has the test.next_test NULL*/
    fprintf(stderr, "Beginning running tests:\n");
    while (test.next_test != NULL) {
        if(test.test_function() == 0) {
            fprintf(stderr, "  [Success] - %s\n", test.test_name);
        } else {
            fprintf(stderr, "  [Failed ] - %s\n", test.test_name);
        }

        test = test.next_test();
    }
    return 0;
}

/*Public interface */

/* __COUNTER__ is not standard :(. Passing __COUNTER__ to another macro so we don't use it twice, thus incrementing twice*/
#define UT_TEST(FUNCTION) UNIT_TEST_CREATE_TEST(FUNCTION, __COUNTER__)

#define UT_ASSERT_TRUE(expr) do { if (!(expr)) { fprintf(stderr, "    Failed evaluating '" #expr "' at: %s:%d\n", __FILE__, __LINE__); return 100; } } while(0)

#define UT_ASSERT_FALSE(expr) UT_ASSERT_TRUE(!(expr))

#define UT_PRINTF(FORMAT, ...) do { fprintf(stderr, "    " FORMAT "\n", __VA_ARGS__);} while (0)

#define UT_ENDTEST \
    struct UNIT_TEST_test UNIT_TEST_CAT(UNIT_TEST_get_test, __COUNTER__)(void) { \
        struct UNIT_TEST_test t = { "last_test", UNIT_TEST_test_last_test, NULL}; \
        return t; \
    }

#endif /*UNIT_TEST_H__*/
