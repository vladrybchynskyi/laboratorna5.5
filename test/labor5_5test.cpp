#include <gtest/gtest.h>
#include <cmath>
#include "../labor5_5.hpp"


TEST(FunctionTest, HandlesSinCos) {
    EXPECT_NEAR(f(0), 0.0, 1e-6);  // Перевірка на нулі, sin(0) - cos(0) = -1
    EXPECT_NEAR(f(Pi / 4), 0.0, 1e-6);  // sin(Pi/4) - cos(Pi/4) = 0
    EXPECT_NEAR(f(Pi / 2), 1.0, 1e-6);  // sin(Pi/2) - cos(Pi/2) = 1
}

// Тести для функції findRoot
TEST(BisectionMethodTest, HandlesRootFinding) {
    int depth = 0;
    double a = 0;
    double b = Pi / 2;
    double eps = 1e-6;
    
    double root = findRoot(a, b, eps, depth);
    EXPECT_NEAR(root, Pi / 4, eps);  // Корінь функції має бути біля Pi/4
    
    EXPECT_GT(depth, 0);  // Перевірка, що алгоритм бісекції виконався хоча б один раз
}

TEST(BisectionMethodTest, HandlesAnotherRange) {
    int depth = 0;
    double a = -Pi / 2;
    double b = 0;
    double eps = 1e-6;
    
    double root = findRoot(a, b, eps, depth);
    EXPECT_NEAR(root, -Pi / 4, eps);  // Корінь функції має бути біля -Pi/4
    
    EXPECT_GT(depth, 0);  // Перевірка глибини рекурсії
}

TEST(BisectionMethodTest, HandlesPrecision) {
    int depth = 0;
    double a = 0;
    double b = Pi / 2;
    double eps = 1e-10;  // Тест на більшу точність
    
    double root = findRoot(a, b, eps, depth);
    EXPECT_NEAR(root, Pi / 4, eps);  // Перевірка точнішого знаходження кореня
    
    EXPECT_GT(depth, 0);  // Алгоритм повинен виконатися
}

TEST(BisectionMethodTest, HandlesInvalidRange) {
    int depth = 0;
    double a = 0;
    double b = 0;  // Інтервал без зміни знаку функції
    double eps = 1e-6;
    
    EXPECT_EQ(findRoot(a, b, eps, depth), 0.0);  // Алгоритм не повинен знаходити корінь
}
