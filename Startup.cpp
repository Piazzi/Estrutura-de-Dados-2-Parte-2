#include "Startup.h";

using namespace std::chrono;
/*
void Startup::StartMergeSort(Registro registros[], int ids[], int indiceEsq, int indiceDir, ofstream &saida)
{
   MergeSort merge;
   {
      auto inicio = high_resolution_clock::now();
      merge.mergeSort(ids, indiceEsq, indiceDir);
      auto resultado = high_resolution_clock::now() - inicio;

      long long microseconds = duration_cast<std::chrono::microseconds>(resultado).count();

      PrintInt("Merge Sort", indiceDir - indiceEsq, saida, microseconds, merge.numComparacoes, merge.numCopias);
   }

   {
      auto inicio = high_resolution_clock::now();
      merge.mergeSortObject(registros, indiceEsq, indiceDir);
      auto resultado = high_resolution_clock::now() - inicio;

      long long microseconds = duration_cast<std::chrono::microseconds>(resultado).count();

      PrintObj("Merge Sort", indiceDir - indiceEsq, saida, microseconds, merge.numComparacoes, merge.numCopias);
   }
}

void Startup::StartQuickSort(Registro registros[], int ids[], int low, int high, ofstream &saida)
{

   QuickSort quick;

   {
      auto inicio = std::chrono::high_resolution_clock::now();
      quick.quickSort(ids, low, high);
      auto resultado = std::chrono::high_resolution_clock::now() - inicio;

      long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

      PrintInt("Quick Sort", high - low + 1, saida, microseconds, quick.numComparacoes, quick.numCopias);
   }

   {
      auto inicio = std::chrono::high_resolution_clock::now();
      quick.quickSortObject(registros, low, high);
      auto resultado = std::chrono::high_resolution_clock::now() - inicio;

      long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

      PrintObj("Quick Sort", high - low + 1, saida, microseconds, quick.numComparacoes, quick.numCopias);
   }
}

void Startup::StartBubbleSort(Registro registros[], int ids[], int TAM, ofstream &saida)
{
   BubbleSort bubble;

   {
      auto inicio = std::chrono::high_resolution_clock::now();
      bubble.bubbleSort(ids, TAM);
      auto resultado = std::chrono::high_resolution_clock::now() - inicio;

      long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

      PrintInt("Bubble Sort", TAM, saida, microseconds, 0, 0);
   }

   {
      auto inicio = std::chrono::high_resolution_clock::now();
      bubble.bubbleSortObject(registros, TAM);
      auto resultado = std::chrono::high_resolution_clock::now() - inicio;

      long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

      PrintObj("Bubble Sort", TAM, saida, microseconds, 0, 0);
   }
}

void Startup::StartSelectionSort(Registro registros[], int ids[], int TAM, ofstream &saida)
{
   SelectionSort selection;

   {
      auto inicio = std::chrono::high_resolution_clock::now();
      selection.selectionSort(ids, TAM);
      auto resultado = std::chrono::high_resolution_clock::now() - inicio;

      long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

      PrintInt("Selection Sort", TAM, saida, microseconds, 0, 0);
   }

   {
      auto inicio = std::chrono::high_resolution_clock::now();
      selection.selectionSortObject(registros, TAM);
      auto resultado = std::chrono::high_resolution_clock::now() - inicio;

      long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

      PrintObj("Selection Sort", TAM, saida, microseconds, 0, 0);
   }
}

void Startup::StartInsertionSort(Registro registros[], int ids[], int TAM, ofstream &saida)
{
   InsertionSort insertion;

   {
      auto inicio = std::chrono::high_resolution_clock::now();
      insertion.insertionSort(ids, TAM);
      auto resultado = std::chrono::high_resolution_clock::now() - inicio;

      long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

      PrintInt("Insertion Sort", TAM, saida, microseconds, insertion.numComparacoes, insertion.numCopias);
   }

   {
      auto inicio = std::chrono::high_resolution_clock::now();
      insertion.insertionSortObject(registros, TAM);
      auto resultado = std::chrono::high_resolution_clock::now() - inicio;

      long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

      PrintObj("Insertion Sort", TAM, saida, microseconds, insertion.numComparacoes, insertion.numCopias);
   }
}

void Startup::StartHeapSort(Registro registros[], int ids[], int TAM, ofstream &saida)
{
   HeapSort heap;

   {
      auto inicio = std::chrono::high_resolution_clock::now();
      heap.heapSort(ids, TAM);
      auto resultado = std::chrono::high_resolution_clock::now() - inicio;

      long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

      PrintInt("Heap Sort", TAM, saida, microseconds, heap.numComparacoes, heap.numCopias);
   }

   {
      auto inicio = std::chrono::high_resolution_clock::now();
      heap.heapSortObject(registros, TAM);
      auto resultado = std::chrono::high_resolution_clock::now() - inicio;

      long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

      PrintObj("Heap Sort", TAM, saida, microseconds, heap.numComparacoes, heap.numCopias);
   }
}

void Startup::StartShellSort(Registro registros[], int TAM, ofstream &saida)
{
   ShellSort shell;

   {
      auto inicio = std::chrono::high_resolution_clock::now();
      shell.shellSort(registros, TAM);
      auto resultado = std::chrono::high_resolution_clock::now() - inicio;

      long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

      PrintInt("Shell Sort", TAM, saida, microseconds, shell.numComparacoes, shell.numCopias);
   }
}

void Startup::StartQuickSortMediana(int userIds[], int low, int high, int k, ofstream &saida)
{
   QuickSort quick;

   {
      auto inicio = std::chrono::high_resolution_clock::now();
      quick.quickSortMediana(userIds, low, high, k);
      auto resultado = std::chrono::high_resolution_clock::now() - inicio;

      long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

      PrintInt("Quick Sort Mediana", high - low + 1, saida, microseconds, quick.numComparacoes, quick.numCopias);
   }
}

void Startup::StartQuickSortInsercao(int userIds[], int low, int high, int m, ofstream &saida)
{
   QuickSort quick;

   {
      auto inicio = std::chrono::high_resolution_clock::now();
      quick.quickSortInsercao(userIds, low, high, m);
      auto resultado = std::chrono::high_resolution_clock::now() - inicio;

      long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

      PrintInt("Quick Sort Insercao", high - low + 1, saida, microseconds, quick.numComparacoes, quick.numCopias);
   }
}

void Startup::PrintInt(const char *nome, int TAM, ofstream &saida, long long tempo, int comparacoes, int copias)
{
   cout << '\n'
        << "Vetor de Inteiros" << "\n";
   saida << '\n'
         << "Vetor de Inteiros" << "\n";

   cout << '\n'
        << "("
        << "N="
        << ")"
        << "Instancia: " << TAM << "\n\n"
        << setw(24) << right << "TEMPO(ms)" << setw(15) << "COMPARACAO" << setw(15) << "TROCAS" << '\n';
   saida << '\n'
         << "("
         << "N="
         << ")"
         << "Instancia: " << TAM << "\n\n"
         << setw(24) << right << "TEMPO(ms)" << setw(15) << "COMPARACAO" << setw(15) << "TROCAS" << '\n';
   cout << left << setw(16) << nome << right << setw(8) << setprecision(4) << setiosflags(ios::fixed | ios::showpoint) << (tempo)
        << setw(15) << comparacoes << setw(15) << copias << '\n';
   saida << left << setw(16) << nome << right << setw(8) << setprecision(4) << setiosflags(ios::fixed | ios::showpoint) << (tempo)
         << setw(15) << comparacoes << setw(15) << copias << '\n';
   saida << '\n\n';

}

void Startup::PrintObj(const char *nome, int TAM, ofstream &saida, long long tempo, int comparacoes, int copias)
{
   cout << '\n'
        << "Vetor de Objetos" << "\n";
   saida << '\n'
         << "Vetor de Objetos" << "\n";

   cout << '\n'
        << "("
        << "N="
        << ")"
        << "Instancia: " << TAM << "\n\n"
        << setw(24) << right << "TEMPO(ms)" << setw(15) << "COMPARACAO" << setw(15) << "TROCAS" << '\n';
   saida << '\n'
         << "("
         << "N="
         << ")"
         << "Instancia: " << TAM << "\n\n"
         << setw(24) << right << "TEMPO(ms)" << setw(15) << "COMPARACAO" << setw(15) << "TROCAS" << '\n';
   cout << left << setw(16) << nome << right << setw(8) << setprecision(4) << setiosflags(ios::fixed | ios::showpoint) << (tempo)
        << setw(15) << comparacoes << setw(15) << copias<< '\n';
   saida << left << setw(16) << nome << right << setw(8) << setprecision(4) << setiosflags(ios::fixed | ios::showpoint) << (tempo)
         << setw(15) << comparacoes << setw(15) << copias << '\n';
   saida << '\n\n';
}
*/
