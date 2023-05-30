/**@mainpage Отчёт к Лабораторной работе №3 
 * @brief Методы программирования. Лабораторная работа №3. Недомолкин И. Э. СКБ201
 * @section intro Введение
 * Отчёт к лабораторной работе №3 по методам программирования. Включающий в себя документацию по коду сгенерированную doxygen, ссылку на репозиторий с кодом программы и результатами её работы, а так же графики. 
 * @section description Описание 
 * Для работы я сгенерировал новые данные большего размера чтобы лучше считать колизии. А то изначальное поле состояло всего из 3 элементов, что очень мало. В итоге я увеличил его до 29296875=3*25^5. Этого вполне достаточно для проверки надёжности хэш функций. Записал я всё это в txt файлы. В каждом количество элементов равно 70 000 / 100 000 / 150 000 / 300 000 / 500 000 / 700 000 / 1 000 000 / 1 500 000 / 3 000 000 соответсвенно
 * @section Link Исходный код программы
 * Ссылка на репозиторий Github с кодов, данными и результатами https://github.com/Nedomolkin-Ilya/Programming-Techniques-lab-3.
 * @section Image График
 * \image latex myplot1.png "Время поиска"
 * \image latex myplot2.png "Количество колизий"
 */
#include <string>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <map>
#include <iomanip>
#include <utility>
#include <vector>
#include <chrono>

using namespace std;

long N;

struct date{
	int day;
	int mounth;
	int year;	
};

struct tim{
	int min;
	int hour;
	int day;
};

class train{
	public:

		void set_hash(long long a){
			/*
			* @param a Задаваемый хэшъ объекту класса
			*/
			t_hash = a;
		}
		
		long long get_hash(){
			return t_hash;
		}

		void set_number(int a){
			/**
			 * @param a Какой номер задать поезду
			 */
			numb = a;
		}
		
		void set_date(int a, int b, int c){
			/**
			 * @param a Задать день даты отправления
			 * @param b Задать месяц даты отправления
			 * @param c Задать год даты отправления
			 */
			data.day = a;
			data.mounth = b;
			data.year = c;
		}

		void set_type(std::string a){
			/**
			 * @param a Задать название поезду
			 */
			type = a;
		}

		void set_time(int a, int b){
			/**
			 * @param a Здать час отправки поезда
			 * @param b Здать минуту отправки поезда
			 */ 
			vremy.hour = a;
			vremy.min = b;
		}

		void set_way(int a, int b){
			/**
			 * @param a Здать количество дней в пути
			 * @param b Здать количество часов в пути
			 */ 
			way.day = a;
			way.hour = b;
		}

		int get_number(){
			/**
			 * return Номер поезда
			 */
			return numb;
		}

		int get_date_d(){
			/**
			 * return День отправки поезда 
			 */
			return data.day;
		}

		int get_date_m(){
			/**
			 * return Месяц отправки поезда
			 */
			return data.mounth;
		}

		int get_date_y(){
			/**
			 * return Год отправки поезда
			 */
			return data.year;
		}

		std::string get_type(){
			/**
			 * return Тип поезда
			 */
			return type;
		}

		int get_time_h(){
			/**
			 * return Час отправки поезда
			 */
			return vremy.hour;
		}

		int get_time_mi(){
			/**
			 * return Минута отправки поезда
			 */
			return vremy.min;
		}

		int get_way_d(){
			/**
			 * return Дней в пути поезду
			 */
			return way.day;
		}

		int get_way_h(){
			/**
			 * return Часов в пути поезду
			 */
			return way.hour;
		}

		friend bool operator> (const train &first, const train &second);
    	friend bool operator<= (const train &first, const train &second);
 
	    friend bool operator< (const train &first, const train &second);
    	friend bool operator>= (const train &first, const train &second);

    	friend bool operator== (const train &first, const train &second);
    	friend bool operator!= (const train &first, const train &second);

	private:
		int numb;
		long long t_hash;
		date data;
		std::string type;
		tim vremy;
		tim way;
};

bool operator >(const train &first, const train &second){
	if (first.type > second.type){
		return true;
	}
	if (first.data.year > second.data.year && first.type == second.type){
		return true;
	}if (first.data.mounth > second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.data.day > second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.vremy.hour > second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth && 
		first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.vremy.min > second.vremy.min && first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && 
		first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.numb > second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.day > second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.hour > second.way.hour && first.way.day == second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && 
		first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}else{
		return false;
	}
}

bool operator >=(const train &first, const train &second){
	if (first.type > second.type){
		return true;
	}if (first.data.year > second.data.year && first.type == second.type){
		return true;
	}if (first.data.mounth > second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.data.day > second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.vremy.hour > second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth && 
		first.data.year == second.data.year && first.type > second.type){
		return true;
	}if (first.vremy.min > second.vremy.min && first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && 
		first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.numb > second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.day > second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.hour > second.way.hour && first.way.day == second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && 
		first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth 
		&& first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.data.year == second.data.year && first.data.mounth == second.data.mounth && first.data.day == second.data.day && 
		first.vremy.hour == second.vremy.hour && first.vremy.min == second.vremy.min && first.numb == second.numb && 
		first.way.day == second.way.day && first.way.hour == second.way.hour && first.type == second.type){
		return true;
	}else{
		return false;
	}
}

bool operator <(const train &first, const train &second){
	if (first.type < second.type){
		return true;
	}
	if (first.data.year < second.data.year && first.type == second.type){
		return true;
	}if (first.data.mounth < second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.data.day < second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.vremy.hour < second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth && 
		first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.vremy.min < second.vremy.min && first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && 
		first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.numb < second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.day < second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.hour < second.way.hour && first.way.day == second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && 
		first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}else{
		return false;
	}
}

bool operator <=(const train &first, const train &second){
	if (first.type < second.type){
		return true;
	}if (first.data.year < second.data.year && first.type == second.type){
		return true;
	}if (first.data.mounth < second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.data.day < second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.vremy.hour < second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth && 
		first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.vremy.min < second.vremy.min && first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && 
		first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.numb < second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.day < second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && first.vremy.hour == second.vremy.hour && 
		first.data.day == second.data.day && first.data.mounth == second.data.mounth && first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.way.hour < second.way.hour && first.way.day == second.way.day && first.numb == second.numb && first.vremy.min == second.vremy.min && 
		first.vremy.hour == second.vremy.hour && first.data.day == second.data.day && first.data.mounth == second.data.mounth 
		&& first.data.year == second.data.year && first.type == second.type){
		return true;
	}if (first.data.year == second.data.year && first.data.mounth == second.data.mounth && first.data.day == second.data.day && 
		first.vremy.hour == second.vremy.hour && first.vremy.min == second.vremy.min && first.numb == second.numb && 
		first.way.day == second.way.day && first.way.hour == second.way.hour && first.type == second.type){
		return true;
	}else{
		return false;
	}
}

bool operator ==(const train &first, const train &second){
	if (first.data.year == second.data.year && first.data.mounth == second.data.mounth && first.data.day == second.data.day && 
		first.vremy.hour == second.vremy.hour && first.vremy.min == second.vremy.min && first.numb == second.numb && 
		first.way.day == second.way.day && first.way.hour == second.way.hour && first.type == second.type) return true;
}

bool operator !=(const train &first, const train &second){
	if (first.data.year != second.data.year or first.data.mounth != second.data.mounth or first.data.day != second.data.day or 
		first.vremy.hour != second.vremy.hour or first.vremy.min != second.vremy.min or first.numb != second.numb or 
		first.way.day != second.way.day or first.way.hour != second.way.hour or first.type != second.type) return true;
}

int RanNum(int min, int max){
	/**
	* @param min Минимально возможное рандомное значение
	* @param max Максимально возможное рандоюное значение
	* @return Рандомное значение из заданного диапозона
	*/ 
	int num = min + rand() % (max - min + 1);
	return num;
}

void generator(std::string name, int count){
	/**
	* @param name Имя создаваемого файла
	* @param count Число элементов которые будут созданы
	*/

	std::ofstream out;

	out.open(name);
	if (out.is_open()){
        for(int i = 0;i<count;i++){
        	int r = RanNum(1,3);
        	std::string Type_of_train;

        	if (r == 1){

        		Type_of_train = "fa";
        		int rand_num;
        		char t;

        		t = 'a';
        		rand_num = RanNum(0,25);
        		t = t + rand_num;
        		Type_of_train = Type_of_train + t;

        		t = 'a';
        		rand_num = RanNum(0,25);
        		t = t + rand_num;
        		Type_of_train = Type_of_train + t;

        		Type_of_train = Type_of_train + 's';

        		rand_num = RanNum(0,25);
        		t = 'a';
        		t = t + rand_num;
        		Type_of_train = Type_of_train + t;
        		Type_of_train = Type_of_train + "te";

        		rand_num = RanNum(0,25);
        		t = 'a';
        		t = t + rand_num;
        		Type_of_train = Type_of_train + t;
        		Type_of_train = Type_of_train + "r";
        		
        		t = 'a';
        		rand_num = RanNum(0,25);
        		t = t + rand_num;
        		Type_of_train = Type_of_train + t;


        	}if (r == 2){

        		Type_of_train = "pas";
        		int rand_num = RanNum(0,25);
        		char t = 'a';

        		t = t + rand_num;
        		Type_of_train = Type_of_train + t;

        		t = 'a';
        		rand_num = RanNum(0,25);
        		t = t + rand_num;
        		Type_of_train = Type_of_train + t;

        		Type_of_train = Type_of_train + "s";

        		rand_num = RanNum(0,25);
        		t = 'a';
        		t = t + rand_num;
        		Type_of_train = Type_of_train + t;
        		Type_of_train = Type_of_train + "ang";

        		rand_num = RanNum(0,25);
        		t = 'a';
        		t = t + rand_num;
        		Type_of_train = Type_of_train + t;
        		Type_of_train = Type_of_train + "er";

        		t = 'a';
        		rand_num = RanNum(0,25);
        		t = t + rand_num;
        		Type_of_train = Type_of_train + t;

        	}if (r == 3){

        		Type_of_train = "tra";
        		int rand_num = RanNum(0,25);
        		char t = 'a';

        		t = t + rand_num;
        		Type_of_train = Type_of_train + t;

        		t = 'a';
        		rand_num = RanNum(0,25);
        		t = t + rand_num;
        		Type_of_train = Type_of_train + t;

        		Type_of_train = Type_of_train + 'n';

        		rand_num = RanNum(0,25);
        		t = 'a';
        		t = t + rand_num;
        		Type_of_train = Type_of_train + t;
        		Type_of_train = Type_of_train + "sp";

        		rand_num = RanNum(0,25);
        		t = 'a';
        		t = t + rand_num;
        		Type_of_train = Type_of_train + t;
        		Type_of_train = Type_of_train + "ort";

        		t = 'a';
        		rand_num = RanNum(0,25);
        		t = t + rand_num;
        		Type_of_train = Type_of_train + t;

        	}

	        out << Type_of_train << ' ' << RanNum(1982,1984) << ' ' << RanNum(6,8) << ' ' << ' ' << RanNum(10,21) 
	        << ' ' <<RanNum(4,9) << ' ' << RanNum(0,59) << ' ' << RanNum(99,123) << ' ' << RanNum(0,2) 
	        << ' ' <<  RanNum(0,23) << std::endl;
    	}
    }
    out.close();
}


void insert(train* trains, long size){
	/**
	* @param trains Массив который должен быть отсортирован
	* @param size Размер массива
	*/ 
	for (long i=1;i<size;i++){
		for (long j=i;j>0 && trains[j-1]>trains[j];j--){
			train t = trains[j-1];
			trains[j-1]=trains[j];
			trains[j]=t;
		}
	}
}

void quick_sort(train* array, long low, long high){
	/**
	* @param array Массив над которым производиться сортировка
	* @param low Нижний элемент
	* @param high Верхний элемент
	*/ 
    long i = low;
    long j = high;
    train pivot;
    pivot = array[(i + j) / 2];
    train temp;

    while (i <= j){
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i <= j){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low) quick_sort(array, low, j);
    if (i < high) quick_sort(array, i, high);
}

void read_file(std::string file_name, train* trains, int size){
	/**
	* @param file_name Имя файла из которого производить чтение
	* @param trains Массив куда производить чтение
	* @param size Количество считываемых данных
	*/ 
	std::ifstream is(file_name);
	if (is.is_open()){
		int d_date, m_date, y_date, h_time, m_time, number, d_way, h_way, i = 0;
		std::string Type_of_train;
		while((is >> Type_of_train >> y_date >>m_date >> d_date >> h_time >> m_time >> number >> d_way >> h_way) and (i < size)){
			trains[i].set_type(Type_of_train);
			trains[i].set_date(d_date, m_date, y_date);
			trains[i].set_time(h_time, m_time);
			trains[i].set_number(number);
			trains[i].set_way(d_way,h_way);
			i++;
		}
	}
}

void write_in_file(std::string file_name, train* trains, int size){
	/**
	* @param file_name Куда записать данные
	* @param trains Массив откуда данные брать
	* @param size Количество данных
	*/ 
	std::ofstream out;
	out.open(file_name);
	if (out.is_open()){
        for(int i = 0;i<size;i++){
	        out << trains[i].get_type() << ' ' << trains[i].get_date_y() << ' ' << trains[i].get_date_m() << ' ' <<  trains[i].get_date_d() << 
	        ' ' << trains[i].get_time_h() << ' ' << trains[i].get_time_mi() << ' ' 
	        << trains[i].get_number() << ' ' << trains[i].get_way_d() << ' ' <<  trains[i].get_way_h() << ' ' << trains[i].get_hash() << std::endl;
    	}
    }
    out.close();
} 

void write_obj_in_file(std::string file_name, train trains){
	std::ofstream out(file_name, ios::app);
	if (out.is_open()){
	    out << trains.get_type() << ' ' << trains.get_date_y() << ' ' << trains.get_date_m() << ' ' <<  trains.get_date_d() << 
	    ' ' << trains.get_time_h() << ' ' << trains.get_time_mi() << ' ' 
	    << trains.get_number() << ' ' << trains.get_way_d() << ' ' <<  trains.get_way_h() << ' ' << trains.get_hash() << std::endl;
    }
    out.close();
}

void merge(train* a, long low, long mid, long high){
	train *b = new train[high+1-low];
	long h,i,j,k;
	h=low;
	i=0;
	j=mid+1;
	
	while((h<=mid)&&(j<=high)){
		if(a[h]<=a[j]){
			b[i]=a[h];
			h++;
		}
		else{
			b[i]=a[j];
			j++;
		}
		i++;
	}

	if(h>mid){
		for(k=j;k<=high;k++){
			b[i]=a[k];
			i++;
		}
	}
	else{
		for(k=h;k<=mid;k++){
			b[i]=a[k];
			i++;
		}
	}

	for(k=0;k<=high-low;k++){
		a[k+low]=b[k];
	}
	delete[] b;
}

void merge_sort(train* a, long low, long high){
	/**
	* @param a Массив на сортровку
	* @param low Нижний элемент
	* @param high Верхний элемент
	*/ 
	long mid;
	if(low<high){
		mid=(low+high)/2;
		merge_sort(a, low,mid);
		merge_sort(a, mid+1,high);
		merge(a, low, mid,high);
	}
}

int liner_search(train* a, long start, long size, std::string key){
    for (int i = start; i <= size; i++) if (a[i].get_type() == key) return i;
    return -1;
}

int binary_search(train* a, int start, int end, std::string key){
	if (start > end) return -1;

	int middle = start + ((end - start)/2);
	if (a[middle].get_type() == key) return middle;
	else if (a[middle].get_type() > key) return binary_search(a, start, middle - 1, key);

	return binary_search(a, middle + 1, end, key);
}

unsigned long long my_hash_function(std::string s, unsigned long long N_hash){
	const int p = 31;
	unsigned long long hash = 0, p_pow = 1;
	for (size_t i = 0; i < s.length(); i++){
		hash += (s[i] + 1) * p_pow;
		p_pow *= p;
	}
	return hash % N_hash;
}

unsigned int ROT13Hash (std::string s, unsigned long long N_hash){
	unsigned int hash = 0;
	unsigned int i = 0;
 
	for (i = 0; i < s.length(); i++) {
		hash += (unsigned char)(s[i]);
		hash -= (hash << 13) | (hash >> 19);
	}
	return hash % N_hash;
}


std::vector<train> find_el_in_hash_table(std::string key, std::vector<train>* trains_hash, unsigned long long hash){
	std::vector<train> find_train;
	if (trains_hash[hash].size() > 0){
		for (int i = 0; i < trains_hash[hash].size(); i++)
			if (trains_hash[hash][i].get_type() == key) find_train.push_back(trains_hash[hash][i]);
		return find_train;
	}
}

int main(){
	// generator("datanew70000.txt", 70000);
	// generator("datanew100000.txt", 100000);
	// generator("datanew150000.txt", 150000);
	// generator("datanew300000.txt", 300000);
	// generator("datanew500000.txt", 500000);
	// generator("datanew700000.txt", 700000);
	// generator("datanew1000000.txt", 1000000);
	// generator("datanew1500000.txt", 1500000);
	// generator("datanew3000000.txt", 3000000);
	bool start = true;
	while(start){
		std::string key = "fabtsnteerp";
		std::cin >> N;
		
		// int N_hash = N / 0.01;

		unsigned long long N_hash = 29296875/0.7;

		train* trains = new train[N];
		std::vector<train>* trains_hash = new std::vector<train>[N_hash];
		std::string s = std::to_string(N);
		std::string name_data = "datanew";
		name_data = name_data + s;
		name_data = name_data + ".txt";

		read_file(name_data,trains,N);

		int counter = 0;
		for (int i = 0; i < N; ++i){
			//unsigned long long hash = my_hash_function(trains[i].get_type(), N_hash);
			unsigned int hash = ROT13Hash (trains[i].get_type(), N_hash);
			hash = hash % N_hash;
			trains[i].set_hash(hash);
			//if (trains_hash[hash].size() != 0) counter++;
			trains_hash[hash].push_back(trains[i]);
		}
	    std::vector<train> find_train;
	    //unsigned long long hash = my_hash_function(key, N_hash);
	    unsigned int hash = ROT13Hash (key, N_hash);



	    auto begin = std::chrono::steady_clock::now();

	    find_train = find_el_in_hash_table(key, trains_hash, hash);

	    auto end = std::chrono::steady_clock::now();
	    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);





	  	for (int i = 0; i < N_hash; i++) if (trains_hash[i].size() > 1){
	  		counter = counter + trains_hash[i].size() - 1;
	  		for (int j = 0; j < trains_hash[i].size(); j++) for (int m = j+1; m < trains_hash[i].size()-1; m++) 
	  			if (trains_hash[i][j].get_type() == trains_hash[i][m].get_type() ) counter--;
	  	}
	    if (find_train.empty()) std::cout << "No results" << std::endl;
	    else for (int i = 0; i < find_train.size(); i++) write_obj_in_file("Result.txt", find_train[i]);
		
		// Подсчёт времени работы программы
	    
	    std::cout << "Total time:"<<  elapsed_ms.count() << std::endl;

	    //write_in_file("Result.txt", trains_hash, N_hash);
	    
	    std::cout << "Coliz = " << counter << std::endl;
		
		delete [] trains;
		delete [] trains_hash;
		std::cin >> start;
	}
	return 1;
}

	    // for (int i = 0; i < N_hash; i++) if (trains_hash[i].size() > 1) for (int j = 0; j < trains_hash[i].size(); j++) for (int m = j+1; m < trains_hash[i].size()-1; m++)
	    // 	if (trains_hash[i][j].get_type() == trains_hash[i][m].get_type() ){
	    // 		std::cout << "----------------\n";
	    // 		std::cout << trains_hash[i][j].get_type() << std::endl;
	    // 		std::cout << "----------------\n\n";
	    // 	}

		// bool fla = true;
		// int res = 0;
		// for (int i = 0; i < N; i++){
		// 	int c = 0;
		// 	for (int j = i+1; j < (N-1); j++){
		// 		if (trains[i].get_type() == trains[j].get_type()) c++;
		// 		std::cout << i << ' ' << j << std::endl;
		// 	}
		// 	if (c >= 2) {
		// 		res = i;
		// 		break;
		// 	}
		// }
		//std::cout << "Hi res is " << res << std::endl;
		//key = trains[res].get_type();