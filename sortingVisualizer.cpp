
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <time.h>

using namespace std;

void printArr(int sortArr[], int numEl){
  for(int i = 0; i < numEl; i++){
    cout << sortArr[i] << " ";
  }
  cout << endl;
}
void visualizeArr(int sortArr[], int numEl){
  int max = 0;
  for (int i = 0; i < numEl; i++){
    if(sortArr[i] > max){
      max = sortArr[i];
    }
  }
  printArr(sortArr, numEl);
  for(int i = max; i >= 0; i--){
    for(int j = 0; j < numEl; j++){
      if(sortArr[j] > i){
        cout << "||" << " ";
      }else{
        cout << "   ";
      }
    }
    cout << endl;
  }
}

void BubbleSortWithVisualizer(int sortArr[], int numEl, int speed, bool shouldClear){
  int numSwaps = 1;
  int startEl, endEl, tempVal;
  startEl = 0;
  endEl = 1;
  while(numSwaps != 0){
    numSwaps = 0;
    while(endEl != numEl){
      if(sortArr[endEl] < sortArr[startEl]){
        tempVal = sortArr[startEl];
        sortArr[startEl] = sortArr[endEl];
        sortArr[endEl] = tempVal;
        numSwaps++;
        
      }
      startEl++;
      endEl++;
      visualizeArr(sortArr, numEl);

      std::this_thread::sleep_for(std::chrono::milliseconds(speed));
      if(shouldClear) system("clear");
    }
    startEl = 0;
    endEl = 1;
    
  }
  
}

void BubbleSortText(uint64_t sortArr[], int numEl){
  int numSwaps = 1;
  int startEl, endEl, tempVal;
  startEl = 0;
  endEl = 1;
  while(numSwaps != 0){
    numSwaps = 0;
    while(endEl != numEl){
      if(sortArr[endEl] < sortArr[startEl]){
        tempVal = sortArr[startEl];
        sortArr[startEl] = sortArr[endEl];
        sortArr[endEl] = tempVal;
        numSwaps++;
        
      }
      startEl++;
      endEl++;

    }
    startEl = 0;
    endEl = 1;
    
  }
  
}

void BubbleSortText(int sortArr[], int numEl, int printSpeed, bool shouldClear){
  int numSwaps = 1;
  int startEl, endEl, tempVal;
  startEl = 0;
  endEl = 1;
  while(numSwaps != 0){
    numSwaps = 0;
    while(endEl != numEl){
      if(sortArr[endEl] < sortArr[startEl]){
        tempVal = sortArr[startEl];
        sortArr[startEl] = sortArr[endEl];
        sortArr[endEl] = tempVal;
        numSwaps++;
        
      }
      startEl++;
      endEl++;
      printArr(sortArr, numEl);
      std::this_thread::sleep_for(std::chrono::milliseconds(printSpeed));
      if(shouldClear) system("clear");
    }
    startEl = 0;
    endEl = 1;
    
  }
  
}

void InsertionSortWithVisualizer(int sortArr[], int numEl, int sleepTime, bool shouldClear){
    int currEl;
    int tempVal;
    visualizeArr(sortArr, numEl);
    for(int i = 0; i < numEl; i++){
        currEl = sortArr[i];
        for(int j = (i-1); j >= 0; j--){
            if(sortArr[j] > currEl){
                tempVal = sortArr[j];
                sortArr[j] = currEl;
                sortArr[j+1] = tempVal;
            }
            visualizeArr(sortArr, numEl);
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
            if(shouldClear){
              system("clear");
            }
        }
    }
    
}

void InsertionSortText(int sortArr[], int numEl, int sleepTime, bool shouldClear){
    int currEl;
    int tempVal;
    printArr(sortArr, numEl);
    for(int i = 0; i < numEl; i++){
        currEl = sortArr[i];
        for(int j = (i-1); j >= 0; j--){
            if(sortArr[j] > currEl){
                tempVal = sortArr[j];
                sortArr[j] = currEl;
                sortArr[j+1] = tempVal;
            }
            printArr(sortArr, numEl);
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
            if(shouldClear){
              system("clear");
            }
        }
    }
    
}

void SelectionSortWithVisualizer(int sortArr[], int numEl, int sleepTime, bool shouldClear){
    int tempVal;
    int minVal;
    int minValInd;
    for(int i = 0; i < numEl; i++){
        minVal = sortArr[i];
        for(int j = i+1; j < numEl; j++){
            if(sortArr[j] < minVal){
                minVal = sortArr[j];
                minValInd= j;
            }
        }
        if(sortArr[i] != minVal){
            int tempVal = sortArr[i];
            sortArr[i] = minVal;
            sortArr[minValInd] = tempVal;
        }
        visualizeArr(sortArr, numEl);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        if(shouldClear){
          system("clear");
        }
    }
    
}

void SelectionSortText(int sortArr[], int numEl, int sleepTime, bool shouldClear){
    int tempVal;
    int minVal;
    int minValInd;
    for(int i = 0; i < numEl; i++){
        minVal = sortArr[i];
        for(int j = i+1; j < numEl; j++){
            if(sortArr[j] < minVal){
                minVal = sortArr[j];
                minValInd= j;
            }
        }
        if(sortArr[i] != minVal){
            int tempVal = sortArr[i];
            sortArr[i] = minVal;
            sortArr[minValInd] = tempVal;
        }
        printArr(sortArr, numEl);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        if(shouldClear){
          system("clear");
        }
    }
    
}

void shuffle(int sortArr[], int numEl){
  int tempVal;
  int tempInd;
  for (int i = 0; i < numEl; i++){
    tempInd = rand() % numEl;
    tempVal = sortArr[i];
    sortArr[i] = sortArr[tempInd];
    sortArr[tempInd] = tempVal;
  }
}

void BOGOSortWithVisualizer(int sortArr[], int numEl, int printSpeed, bool shouldClear){
  bool isStupidlySorted = false;
  while(!isStupidlySorted){
    visualizeArr(sortArr, numEl);
    for(int i = 1; i < numEl; i++){
      if (sortArr[i-1] > sortArr[i]){
        break;
      }
      if(i == (numEl - 1)){
        isStupidlySorted = true;
      }
    }
    shuffle(sortArr, numEl);
    std::this_thread::sleep_for(std::chrono::milliseconds(printSpeed));
    if(shouldClear){
      system("clear");
    }
  }
}

void BOGOSortText(int sortArr[], int numEl, int printSpeed, bool shouldClear){
  bool isStupidlySorted = false;
  while(!isStupidlySorted){
    printArr(sortArr, numEl);
    for(int i = 1; i < numEl; i++){
      if (sortArr[i-1] > sortArr[i]){
        break;
      }
      if(i == (numEl - 1)){
        isStupidlySorted = true;
      }
    }
    shuffle(sortArr, numEl);
    std::this_thread::sleep_for(std::chrono::milliseconds(printSpeed));
    if(shouldClear){
      system("clear");
    }
  }
}

uint64_t BOGOSort(int sortArr[], int numEl){
  uint64_t Counter = 0;
  bool isStupidlySorted = false;
  while(!isStupidlySorted){

    for(int i = 1; i < numEl; i++){
      if (sortArr[i-1] > sortArr[i]){
        break;
      }
      if(i == (numEl - 1)){
        return Counter;
      }
    }
    shuffle(sortArr, numEl);
    Counter++; 
  }
  return Counter;
}

void BOGOAnalyzer(){
  cout << "Generating Arrays..." << endl;
  uint64_t testResults[10];
  int arraysToTest[10][10];
  uint64_t total= 0;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10;j++){
      arraysToTest[i][j] = rand() % 10 + 1;
    }
  }
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10;j++){
      cout << arraysToTest[i][j] << " ";
    }
    cout << endl;
  }
  cout << "Running BOGOSort...";
  for(int i = 0; i < 10; i++){
    testResults[i] = BOGOSort(arraysToTest[i], 10);
    cout << ".";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
  cout << endl;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10;j++){
      cout << arraysToTest[i][j] << " ";
    }
    cout << "\t" << testResults[i] << endl;
  }
  cout << "Analyzing Results..." << endl;
  cout << "Mean: \t";
  for (int i = 0; i < 10; i ++){
    total += testResults[i];
  } 
  total /= 10;
  cout << total << endl;
  cout << "Median: ";
  BubbleSortText(testResults, 10);
  cout << testResults[5] << "\t (And No I Didn't Use BOGOSort For This One)" << endl;

}

void printMenu(bool doesArrNeedInit = false){
  if(doesArrNeedInit){
    cout << endl << "*Please Initialize the Array (4) First Before Running Sorts*" << endl;
  }
  cout << endl << "Choose one of the following options:" << endl
       << "\t1. Change Print Speed " << endl
       << "\t2. Clear Screen Y/N " << endl
       << "\t3. Change Sort Array Size " << endl
       << "\t4. Change Sort Array Elements " << endl
       << "\t5. Randomize Sort Array Elements" << endl
       << "\t6. Bubble Sort with Visualizer " << endl
       << "\t7. Insertion Sort with Visualizer " << endl
       << "\t8. Selection Sort with Visualizer " << endl
       << "\t9. Bubble Sort Text Mode " << endl
       << "\t0. Insertion Sort Text Mode " << endl
       << "\tA. Selection Sort Text Mode " << endl
       << "BOGO Sort Stuff" << endl
       << "\tB. BOGO Sort with Visualizer *Not recommended to do more than 6 Elements*" << endl
       << "\tC. BOGO Sort Text Mode" << endl
       << "\tD. BOGO Sort Analysis *Does not use user inputted arrays*" << endl
       << "\tE. Exit" << endl;
}

int changeSpeed(){
  char userInput;
  int speed = 100;
  cin >> userInput;
  if(tolower(userInput) == 's'){
    speed = 600;
  }else if(tolower(userInput) == 'm'){
    speed = 400;
  }else{
    speed = 200;
  }
  return speed;
}

void clearArr(int sortArr[],int numEl){
  for(int i = 0; i < numEl; i++){
    sortArr[i] = 0;
  }
}

int main() {
  int numEl = 10;
  char userChoice;
  int sortArr[100] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int printSpeed = 400;
  int tempNum = 0;
  bool shouldClear = false;
  bool doesArrayNeedInit = true;
  srand(time(NULL));
  while(true){
    printMenu(doesArrayNeedInit);
    cout << "Choose: ";
    cin >> userChoice;
    switch(tolower(userChoice)){
      case '1':
        cout << "Please Choose Speed: (S, M, F): ";
        printSpeed = changeSpeed();
        break;
      case '2':
        cout << "Would you like to clear the screen between images? (Y/N) ";
        char tempInput;
        cin >> tempInput;
        if(tolower(tempInput) == 'y') shouldClear = true;
        else {shouldClear = false;}
        break;
      case '3':
        cout << "Choose new size (1-100): ";
        tempNum = 0;
        cin >> tempNum;
        if(tempNum > 100 || tempNum < 1){
          cout << "Invalid Input. Please try again.";
        }else{
          numEl = tempNum;
          clearArr(sortArr, numEl);
          doesArrayNeedInit = true;
        }
        break;
      case '4':
        tempNum = 0;
        for(int i = 0; i < numEl; i++){
          cout << "Please enter element " << i << ": ";
          cin >> tempNum;
          cout << endl;
          sortArr[i] = tempNum;
        }
        doesArrayNeedInit = false;
        break;
      case '5':
        for(int i = 0; i < numEl; i++){
          sortArr[i] = (rand() % numEl) + 1;
        }
        doesArrayNeedInit = false;
        break;
      case '6':
        if(doesArrayNeedInit){
          cout << endl << "*Please Initialize the Array (4) First Before Running Sorts*" << endl;
          break;
        }
        BubbleSortWithVisualizer(sortArr, numEl, printSpeed, shouldClear);
        break;
      case '7':
        if(doesArrayNeedInit){
          cout << endl << "*Please Initialize the Array (4) First Before Running Sorts*" << endl;
          break;
        }
        InsertionSortWithVisualizer(sortArr, numEl, printSpeed, shouldClear);
        break;
      case '8':
        if(doesArrayNeedInit){
          cout << endl << "*Please Initialize the Array (4) First Before Running Sorts*" << endl;
          break;
        }
        SelectionSortWithVisualizer(sortArr, numEl, printSpeed, shouldClear);
        break;
      case '9':
        if(doesArrayNeedInit){
          cout << endl << "*Please Initialize the Array (4) First Before Running Sorts*" << endl;
          break;
        }
        BubbleSortText(sortArr, numEl, printSpeed, shouldClear);
        break;
      case '0':
        if(doesArrayNeedInit){
          cout << endl << "*Please Initialize the Array (4) First Before Running Sorts*" << endl;
          break;
        }
        InsertionSortText(sortArr, numEl, printSpeed, shouldClear);
        break;
      case 'a':
        if(doesArrayNeedInit){
          cout << endl << "*Please Initialize the Array (4) First Before Running Sorts*" << endl;
          break;
        }
        SelectionSortText(sortArr, numEl, printSpeed, shouldClear);
        break;
      case 'b':
        if(doesArrayNeedInit){
          cout << endl << "*Please Initialize the Array (4) First Before Running Sorts*" << endl;
          break;
        }
        BOGOSortWithVisualizer(sortArr, numEl, printSpeed, shouldClear);
        break;
      case 'c':
        if(doesArrayNeedInit){
          cout << endl << "*Please Initialize the Array (4) First Before Running Sorts*" << endl;
          break;
        }
        BOGOSortText(sortArr, numEl, printSpeed, shouldClear);
        break;
      case 'd':
        BOGOAnalyzer();
        break;
      case 'e':
        cout << "Exiting...";
        return 0;
        break;
      default:
        cout << "Invalid Input. Please Try Again" << endl;
    }
    
  }
  return 0;
}

