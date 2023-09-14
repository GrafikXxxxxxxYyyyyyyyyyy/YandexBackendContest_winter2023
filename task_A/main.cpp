#include <iostream>

int main() {
    long long year1, month1, day1, hour1, min1, sec1;
    long long year2, month2, day2, hour2, min2, sec2;

    // Ввод данных
    std::cin >> year1 >> month1 >> day1 >> hour1 >> min1 >> sec1;
    std::cin >> year2 >> month2 >> day2 >> hour2 >> min2 >> sec2;

    // Количество дней в каждом месяце
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Вычисляем разницу в годах, месяцах, днях, часах, минутах и секундах
    long long yearsDiff = year2 - year1;
    long long monthsDiff = month2 - month1;


    
    long long daysDiff = day2 - day1;
    long long hoursDiff = hour2 - hour1;
    long long minsDiff = min2 - min1;
    long long secsDiff = sec2 - sec1;

    // Вычисляем количество дней

    
    // for (long long year = year1; year < year2; ++year) {
    //     // Добавляем дни в году
    //     for (int month = 1; month <= 12; ++month) {
    //         totalDays += daysInMonth[month - 1];
    //     }
    // }

    // Добавляем разницу в днях между датами
    totalDays += daysDiff;

    // Выводим результат
    std::cout << totalDays << " " << secsDiff + minsDiff * 60 + hoursDiff * 3600 << std::endl;

    return 0;
}
