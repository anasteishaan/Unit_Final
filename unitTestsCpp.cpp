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
            // ������� ������� x <= 0
            double result = calculate(-1.0, 3);
            Assert::AreEqual(9999, result, 0.001, L"�������: x <= 0 �� ������");
        }

        TEST_METHOD(TestXGreaterThanZero) {
            // ������� ������� x > 0
            double result = calculate(1.0, 2);
            Assert::AreEqual(3.1667, result, 0.001, L"�������: x > 0 �� ������");
        }


        TEST_METHOD(TestNZero) {
            // ������� ������� n <= 0 (������� �������)
            try {
                calculate(1.0, 0);
                Assert::Fail(L"�������: ���������� ������� ��� n <= 0");
            }
            catch (const std::invalid_argument& e) {
                Assert::IsTrue(true);
            }
        }

        TEST_METHOD(TestLargeN) {
            // ������� ������� �������� n
            double result = calculate(1.0, 10);
            Assert::IsTrue(result > 0, L"�������: ��������� ��� �������� n");
        }
    };
}