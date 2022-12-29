#include<iostream>
#include<vector>
using namespace std;

//1-QUICK SORT

// es prueba
int Particion(int arreglo[], int inicio, int fin)
{
	 int pivote=arreglo[fin];
	 int i=inicio-1;

	 int auxiliar;

	 for(int j=inicio;j<fin;j++){
			if(arreglo[j]<=pivote){
				i=i+1;
				auxiliar=arreglo[i];
				arreglo[i]=arreglo[j];
				arreglo[j]=auxiliar;
			}
	 }
	 auxiliar=arreglo[i+1];
	 arreglo[i+1]=arreglo[fin];
	 arreglo[fin]=auxiliar;
	return i+1;

}
void QuickSort(int arreglo[], int inicio, int fin)
{
	if(inicio<fin){
		int medio=Particion(arreglo,inicio,fin);
		QuickSort(arreglo,inicio,medio-1);

		QuickSort(arreglo,medio+1,fin);
	}
}
void Particion2(int arr[], int left, int right, int &i, int &j) {
   if (right - left <= 1) {
      if (arr[right] < arr[left])
         swap(arr[right], arr[left]);
      i = left;
      j = right;
      return;
}
int mid = left;
int pivot = arr[right];
while (mid <= right) {
   if (arr[mid]<pivot)
      swap(arr[left++], arr[mid++]);
      else if (arr[mid]==pivot)
         mid++;
      else if (arr[mid] > pivot)
         swap(arr[mid], arr[right--]);
   }
   i = left-1;
   j = mid;
}
void QuickSort2(int arreglo[], int inicio, int fin)
{
	if(inicio<fin){
		int i,j;
		Particion2(arreglo,inicio,fin, i, j);
		QuickSort2(arreglo,inicio,i);

		QuickSort2(arreglo,j,fin);
	}
}

void imprimir(int arr[], int n) {
   for (int i = 0; i < n; ++i)
   cout << " " << arr[i];
   cout << endl;
}

int main() {
   int a[] = {4, 9, 4, 3, 1, 9, 4, 3, 9, 4, 3, 1, 4};
   int n = sizeof(a) / sizeof(int);
   cout << "Antes :" << endl;
   imprimir(a, n);
   QuickSort2(a, 0, n - 1);
   cout << "Despues:" << endl;
   imprimir(a, n);
   int a[] = {4, 9, 4, 3, 1, 9, 4, 3, 9, 4, 3, 1, 4};
   int n = sizeof(a) / sizeof(int);
   cout << "Antes2 :" << endl;
   imprimir(a, n);
   QuickSort(a, 0, n - 1);
   cout << "Despues:" << endl;
   imprimir(a, n);
}


