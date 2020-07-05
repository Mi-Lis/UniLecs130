#include <iostream>
#include <array>

using namespace std;

const size_t DIM = 3;

size_t sum(size_t** m, size_t d) //Сумма элементов подмассива
{
    size_t S = 0;
    for(size_t i = 0; i < d; i++)
        for(size_t j = 0; j < d; j++)
    S+=m[i][j];
    return S;
}
array<array<size_t, DIM>, DIM> getArr(array<array<size_t, DIM>, DIM> Arr) //заполнение основного массива
{
    for(size_t i = 0; i < DIM; i++)
        for(size_t j = 0; j < DIM; j++)
    cin>>Arr[i][j];
    return Arr;
}
auto getPArr(array<array<size_t, DIM>, DIM> Arr, size_t d, size_t i1, size_t j1) //Cозданиеподмассива dxd начиная от элемента i1, j1 в основном массиве
{
    size_t **PArr = new size_t*[d];
    for(size_t k = 0; k<d; k++)
    PArr[k] = new size_t[d];
    for(size_t i=0; i<d; i++, ++i1)
    {
        for(size_t j = 0; j<d; j++, ++j1)
        {
            PArr[i][j]=Arr[i1][j1];
            cout<<PArr[i][j]<<" ";
        }
        cout<<endl;
    }
    return PArr;
}
auto deletePArr(size_t **m, size_t d) //фудаление динамического массива
{
for (int count = 0; count < d; count++)
        delete [] m[count];
}
int main()
{
array <array<size_t, DIM>, DIM> Arr;
Arr = getArr(Arr); //создаем массив
size_t X, cnt = 0;
size_t **parr;
cout<< "Введите число: ";
cin>>X; //Вводим необходимую сумму
for(size_t i = 0; i < DIM; i++)
{
    for(size_t j = 0;  j<DIM; j++)
    {
    //Задаем длину для подмассива
        for(size_t d = 1; d<DIM; d++)
        {
            if(i-d<0||j-d<0)
            continue;
            parr = getPArr(Arr, d, i, j);
            if(sum(parr, d)==X)
            cnt++;
            deletePArr(parr, d);
        }

    }
}
cout<<"Подходит "<<cnt;
}
