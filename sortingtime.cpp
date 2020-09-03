//Kenneth Lai


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <functional>

struct Multstring{//struct used to separate a word with punctuation and with the punctuation removed.
std::string punc;
std::string nopunc;
};


void bubbleSort(std::vector<Multstring> &p, int size);
void selectionSort(std::vector<Multstring> &p, int size);
void insertionSort(std::vector<Multstring> &p, int size);
void mergeSort(std::vector<Multstring> &p, int from, int to);
void merge(std::vector<Multstring> &p, int from, int mid, int to);
void quickSort(std::vector<Multstring> &p, int from, int to);
int partition(std::vector<Multstring> &p, int from, int to);
void generalTimeTwoParam(std::vector<Multstring> &p, int size, long long a[], void (*func)(std::vector<Multstring>&, int));
void generalTimeThreeParam(std::vector<Multstring> &p, int from, int to, long long a[], void(*func)(std::vector<Multstring>&, int, int));
void printTimes1(long long words1[], long long words2[] , long long words3[]);
void printTimes2(long long times1[], long long times2[]);


int main()
{
    //variable declarations
    std::string text;
    std::ifstream infile;
    std::vector<Multstring> play;
    int count = 0;
    int entry, entry2;
    int vecCounter = 0;
    Multstring multstr, multstr2;//temporary structure object
    char cont;
    int choice3;

    //1 sort over multiple sizes array declarations
    long long fivethousand[5];
    long long tenthousand[5];
    long long twentythousand[5];
    //end

    //2 sorts declarations
    long long completetext[5];
    long long completetext2[5];
    //end
do
    {
    std::cout << "Enter a number for the .txt file you want to analyze " << std::endl;
    std::cout << "Press 1 for Romeo and Juliet. " << std::endl;
    std::cout << "Press 2 for Othello. " << std::endl;
    std::cout << "Press 3 for Taming of the Shrew. " << std::endl;
    std::cin >> entry;



    //selection code

    if(entry == 1)
    {
        infile.open("RomeoandJuliet.txt");//opens file
        //std::cout << "enters in romeo\n";debug
        if(infile.fail())
        {
            std::cout << "cannot open file\n";
        }
        else{
            std::cout << "file opened successfully\n";
        }
    }

    else if(entry == 2)
    {
        infile.open("Othello.txt");
        infile >> text;

         if(infile.fail())
        {
            std::cout << "cannot open file\n";
        }
        else{
            std::cout << "file opened successfully\n";
        }

    }
    else if(entry == 3)
    {
        infile.open("The_Taming_of_the_Shrew.txt");
        infile >> text;

         if(infile.fail())
        {
            std::cout << "cannot open file\n";
        }
        else{
            std::cout << "file opened successfully\n";
        }

    }

    else
    {
        std::cout << "You did not enter a valid choice." << std::endl;


    }

    while(!infile.eof())
    {
        infile >> text;
        int str_length = text.size();

        multstr.punc = text;

        for(int i = 0; i < str_length; i++)//eliminate punctuation
        {
            if(ispunct(text[i]))
            {
                text.erase(i--, 1);
                str_length = text.size();

            }
        }
        multstr.nopunc = text;
        count++;
        play.push_back(multstr);//populate vector

    }//end of while loop

    std::cout << "Would you like to compare two of the five sorting algorithms or just look at one? enter 1 for a single algorithm or 2 "//user chooses comparison
    << "for multiple.";
    std::cin >> entry2;

    if(entry2 == 1)
    {
        int choice;

        std::cout << "Which of the algorithms do you want to analyze?\n";
        std::cout << "Enter 1 for bubble sort\n";
        std::cout << "2 for selection sort\n";
        std::cout << "3 for insertion sort\n";
        std::cout << "4 for merge sort\n";
        std::cout << "5 for quick sort\n";
        std::cin >> choice;

        if(choice == 1)
        {
                generalTimeTwoParam(play, 5000, fivethousand, bubbleSort);
                generalTimeTwoParam(play, 10000, tenthousand, bubbleSort);
                generalTimeTwoParam(play, 20000, twentythousand, bubbleSort);
        }
        else if(choice == 2)
        {
                generalTimeTwoParam(play, 5000, fivethousand, selectionSort);
                generalTimeTwoParam(play, 10000, tenthousand, selectionSort);
                generalTimeTwoParam(play, 20000, twentythousand, selectionSort);
        }
        else if(choice == 3)
        {
                generalTimeTwoParam(play, 5000, fivethousand, insertionSort);
                generalTimeTwoParam(play, 10000, tenthousand, insertionSort);
                generalTimeTwoParam(play, 20000, twentythousand, insertionSort);
        }
        else if(choice == 4)
        {
            generalTimeThreeParam(play, 0, 5000, fivethousand, mergeSort);
            generalTimeThreeParam(play, 0, 10000, tenthousand, mergeSort);
            generalTimeThreeParam(play, 0, 20000, twentythousand, mergeSort);

        }
        else if(choice == 5)
        {
            generalTimeThreeParam(play, 0, 5000, fivethousand, quickSort);
            generalTimeThreeParam(play, 0, 10000, tenthousand, quickSort);
            generalTimeThreeParam(play, 0, 20000, twentythousand, quickSort);
        }
        printTimes1(fivethousand, tenthousand, twentythousand);
    }
    else if(entry2 == 2)
    {
        int firstchoice, secondchoice;

        std::cout << "Select the first of the the two algorithms\n";
        std::cout << "Enter 1 for bubble sort\n";
        std::cout << "2 for selection sort\n";
        std::cout << "3 for insertion sort\n";
        std::cout << "4 for merge sort\n";
        std::cout << "5 for quick sort\n";
        std::cin >> firstchoice;

        if(firstchoice == 1)
        {
            generalTimeTwoParam(play, play.size(), completetext, bubbleSort);
        }
        else if(firstchoice == 2)
        {
            generalTimeTwoParam(play, play.size(), completetext, selectionSort);
        }
        else if(firstchoice == 3)
        {
            generalTimeTwoParam(play, play.size(), completetext, insertionSort);
        }
        else if(firstchoice == 4)
        {
            generalTimeThreeParam(play, 0, play.size(), completetext, mergeSort);
        }
        else if(firstchoice == 5)
        {
            generalTimeThreeParam(play, 0, play.size(), completetext, mergeSort);
        }

        std::cout << "Select the second algorithm\n";
        std::cout << "Enter 1 for bubble sort\n";
        std::cout << "2 for selection sort\n";
        std::cout << "3 for insertion sort\n";
        std::cout << "4 for merge sort\n";
        std::cout << "5 for quick sort\n";
        std::cin >> secondchoice;

        if(secondchoice == firstchoice)
        {
            std::cout << "you chose the same sort\n";
            return 0;
        }
        else
        {

            if(firstchoice == 1)
            {
                generalTimeTwoParam(play, play.size(), completetext2, bubbleSort);
            }
            else if(firstchoice == 2)
            {
                generalTimeTwoParam(play, play.size(), completetext2, selectionSort);
            }
            else if(firstchoice == 3)
            {
                generalTimeTwoParam(play, play.size(), completetext2, insertionSort);
            }
            else if(firstchoice == 4)
            {
                generalTimeThreeParam(play, 0, play.size(), completetext2, mergeSort);
            }
            else if(firstchoice == 5)
            {
                generalTimeThreeParam(play, 0, play.size(), completetext2, mergeSort);
            }
        }
        printTimes2(completetext, completetext2);

    }//end of mult comparison
    std::cout << std::endl;
    std::cout << "number of words in vector" << play.size() << std::endl;//debug

    std::cout << "Would you like to see the first or last 50 words of the sorted play? " << std::endl;
    std::cout << "Press 1 for first 50. Press 2 for last 50" << std::endl;
    std::cin >> choice3;

    if(choice3 == 1)
    {
        for(int i = 0; i < 50; i++)

        if(play[i].punc == "|")
        {
            i++;
        }
        else
            {
            std::cout << play[i].nopunc << " ";

        }
    }
    if(choice3 == 2)
    {
        for(int i = 20000 - 50; i < 20000; i++) //for(int i = count; i > count - 50; i--)
        {
            if(play[i].punc == "|")
            {
                i++;
            }
            std::cout << play[i].nopunc << " ";
        }
    }

std::cout << std::endl;
std::cout << "Would you like to run the program again? Press y for yes and n for no " << std::endl;
std::cin >> cont;

}while(cont == 'y');//end of do while


return 0;

}//end of main

void bubbleSort(std::vector<Multstring> &p, int size)
{
    bool notsorted = true;
    while(notsorted)
    {
        notsorted = false;
        for(int i = 1; i < size; i++)
        {
            if(p[i].nopunc < p[i - 1].nopunc)
            {
                Multstring temp;
                temp = p[i];
                p[i] = p[i - 1];
                p[i - 1] = temp;
                notsorted = true;
            }
        }
        size--;
    }
}

void selectionSort(std::vector<Multstring> &p, int size)
{
    Multstring min_storage;

    for(int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        min_storage.nopunc = p[i].nopunc;

        for(int j = i + 1; j < size; j++)
        {
            if(min_storage.nopunc > p[j].nopunc)
            {
                min_storage.nopunc = p[j].nopunc;
                min_index = j;
            }
        }
        if(min_index != i)
        {
            Multstring temp;
            temp = p[i];
            p[i] = p[min_index];
            p[min_index] = temp;
        }
    }
}//end of selectionSort

void insertionSort(std::vector<Multstring> &p, int size)
{
   for (int i = 1; i < size; i++)
   {
      Multstring next = p[i];
      // Move all larger elements up
      int j = i;
      while (j > 0 && p[j - 1].nopunc > next.nopunc)
      {
         p[j] = p[j - 1];
         j--;
      }
      // Insert the element
      p[j] = next;
   }
}//end of insertionSort

void mergeSort(std::vector<Multstring> &p, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(p, l, m);
        mergeSort(p, m + 1, r);
        merge(p, l, m, r);
    }
}

void merge(std::vector<Multstring> &p, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    Multstring L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = p[l + i];
    for (j = 0; j < n2; j++)
        R[j] = p[m + 1 + j];


    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i].nopunc < R[j].nopunc) {
            p[k] = L[i];
            i++;
        }
        else {
            p[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        p[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        p[k] = R[j];
        j++;
        k++;
    }
}

void quickSort(std::vector<Multstring> &p, int from, int to)
{
    if(from >= to)
    {
        return;
    }
    int part = partition(p, from, to);
    quickSort(p, from, part);
    quickSort(p, part + 1, to);
}

int partition(std::vector<Multstring> &p, int from, int to)
{
    std::string pivot = p[from].nopunc;
    int i = from - 1;
    int j = to + 1;
    while(i < j)
    {
        i++; while(p[i].nopunc < pivot){i++;}
        j--; while(p[j].nopunc > pivot){j--;}
        if(i < j)//use swap function if this doesn't work
        {
            Multstring temp;
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
        }
    }
}

void printTimes1(long long words1[], long long words2[], long long words3[])
{
    long long avg1, avg2, avg3;
    avg1 = (words1[1] + words1[2] + words1[3] + words1[4])/4;//average time calculations
    avg2 = (words2[1] + words2[2] + words2[3] + words2[4])/4;
    avg3 = (words3[1] + words3[2] + words3[3] + words3[4])/4;
    std::cout << "Here are the sort times for your selected sort: " << std::endl;
    std::cout << "    5000" << "   " << "10000" << "   " << "20000" << "   " << std::endl;//table display
    std::cout << "run1   " << words1[1] << "   " << words2[1] << "       " << words3[1] << std::endl;
    std::cout << "run2   " << words1[2] << "   " << words2[2] << "       " << words3[2] << std::endl;
    std::cout << "run3   " << words1[3] << "   " << words2[3] << "       " << words3[3] << std::endl;
    std::cout << "run4   " << words1[4] << "   " << words2[4] << "       " << words3[4] << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "avg: " << "  " << avg1 << "  " << avg2 << "  " << avg3 << std::endl;//average display
}

void printTimes2(long long words1[], long long words2[])
{
     long long avg1, avg2;
    avg1 = (words1[1] + words1[2] + words1[3] + words1[4])/4;//average time calculations
    avg2 = (words2[1] + words2[2] + words2[3] + words2[4])/4;


    std::cout << "Here are the sort times for your selected sort: " << std::endl;//table display
    std::cout << "    Sort 1" << "   " << "Sort 2" << "   " << std::endl;
    std::cout << "run1   " << words1[1] << "   " << words2[1] << std::endl;
    std::cout << "run2   " << words1[2] << "   " << words2[2] << std::endl;
    std::cout << "run3   " << words1[3] << "   " << words2[3] << std::endl;
    std::cout << "run4   " << words1[4] << "   " << words2[4] << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "avg: " << "  " << avg1 << "  " << avg2 << std::endl;//average display
}

void generalTimeTwoParam(std::vector<Multstring> &p, int size, long long a[], void(*func)(std::vector<Multstring>&, int))
{
    for(int i = 0; i < 5; i++)
    {


            auto start1 = std::chrono::high_resolution_clock::now();
            func(p, size);
            auto stop1 = std::chrono::high_resolution_clock::now();
            auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);//difference
            auto storabletime1 = duration1.count();
            a[i] = storabletime1;

    }
}

void generalTimeThreeParam(std::vector<Multstring> &p, int from, int to, long long a[], void(*func)(std::vector<Multstring>&, int, int))
{
    for(int i = 0; i < 5; i++)
    {
            auto start1 = std::chrono::high_resolution_clock::now();
            func(p, from, to);
            auto stop1 = std::chrono::high_resolution_clock::now();
            auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);//difference
            auto storabletime1 = duration1.count();
            a[i] = storabletime1;
    }
}
