# BigInteger

## Библиотека для работы с длинными числами

Тесты, время работы и сравнение с популярными решениями будут добавлены в скором времени.

### Сравнение времени работы

| Операция         | BigInteger C++, сек. | Python, сек. |
|------------------|----------------------|--------------|
| 2 ^ 1 000 000    | 9.69                 | 2.34         |
| 2 ^ 100 000      | 0.15                 | 0.02         |
| factorial 20     | 4.1                  | 1.1          |
| sqrt(2 ^ 10 000) | 3.1                  | eps          |

Для умножения и деления использовались наивные реализации, что,
как видно по замерам, плохо сказывается на времени вычислений.

### Как оптимизировать?

#### Умножение

1. Алгоритм Карацубы
2. Быстрое преобразование Фурье

#### Корень

1. Метод Ньютона
