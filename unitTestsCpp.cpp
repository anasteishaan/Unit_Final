#include "pch.h"
#include "CppUnitTest.h"
#include "calculate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit2final
{
    TEST_CLASS(CalculateTests)
    {
    public:
        TEST_METHOD(TestXLessThanOrEqualZero) {
            // Тестуємо випадок x <= 0
            double result = calculate(-1.0, 3);
            Assert::AreEqual(9999, result, 0.001, L"Помилка: x <= 0 не працює");
        }

        TEST_METHOD(TestXGreaterThanZero) {
            // Тестуємо випадок x > 0
            double result = calculate(1.0, 2);
            Assert::AreEqual(3.1667, result, 0.001, L"Помилка: x > 0 не працює");
        }


        TEST_METHOD(TestNZero) {
            // Тестуємо випадок n <= 0 (очікуємо виняток)
            try {
                calculate(1.0, 0);
                Assert::Fail(L"Помилка: очікувався виняток для n <= 0");
            }
            catch (const std::invalid_argument& e) {
                Assert::IsTrue(true);
            }
        }

        TEST_METHOD(TestLargeN) {
            // Тестуємо випадок великого n
            double result = calculate(1.0, 10);
            Assert::IsTrue(result > 0, L"Помилка: результат при великому n");
        }
    };
}