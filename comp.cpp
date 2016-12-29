#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef priority_queue<ll, vll, greater<>> minHeap;
typedef priority_queue<ll, vll> maxHeap;

#define vec vector

#define mp(a, b) make_pair((a), (b))
#define pb(a) push_back((a))


vvll grid(4, vll(4, 0));
ll arr[] ={1, 3, 5, 7};
//ll count;

vll chkGrid(){
  vll ubIndx;
  ll temp = 0;
  int indx = -1;
  int currIndx;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(grid[j][i] == 1){
	temp++;
      }
    }
    if(temp % 2 != 0){
      ubIndx.pb(i);
    }
    temp = 0;
  }
  return ubIndx;
}

int get_row(int found){
  for(int i = 0; i < 4; i++){
    if(grid[i][found] == 1)
      return i;
  }
  return -1;
}


void gridify(int indx){
  for(int i = 0; i < 4; i++){
    grid[indx][i] = 0;
  }
  int temp = arr[indx];
  int i = 0;
  while(temp != 0){
    grid[indx][i] = temp %2;
    temp = temp /2;
    i++;
  }
}


ll gridify(){
  int count1 = 0;
  for(int a = 0; a < 4; a++){
    count1 += arr[a];
    gridify(a);
  }
  return count1;
}

void printGrid(){   
  for(int i = 0; i < grid.size(); i++){
    for(int j = 0; j < grid[i].size(); j++){
      cout << " " << grid[i][j];
    }
    cout << endl;
  }
}

void printBoard(){
  for(int i = 0; i < 4; i++){
    cout << arr[i] << "\t";
    for(int j = 0; j < arr[i]; j++){
      cout << "1 ";
    }
    cout << endl;
  }
}


int move(int row, int num, int * count){
  if(num <= arr[row-1] && row <= 4 && row >= 1 && num != 0){
    count -= num;
    arr[row-1] -= num;
    gridify(row-1);
    return 1;
  }
  else{
    cout << "put correct input" << endl;
    return 0;
  }
}

int comp(int count){
  vll ubIndx = chkGrid();
  ll found;
  ll temp = 0;
  ll row;
  ll num;
  if(!ubIndx.empty()){
    found = ubIndx.back();
    row = get_row(found);
    temp += pow(2, found);
    for(int i = 0; i < ubIndx.size()-1; i++){
      if(grid[row][ubIndx[i]] == 1){
	temp += pow(2, ubIndx[i]);
      }else{
	temp -= pow(2, ubIndx[i]);
      }
    }
    num = temp;
    row += 1;
    cout << "$$ comp : " << row << " " << num << endl;
    // move(row, num, &count);
  }
  return count;
}

int player(int count, bool p){
  int row;
  int num;
  int m = 0;
  while(m == 0){
    cout << "player " << p << endl;
    cin >> row >> num;
    m = move(row, num, &count);
  }
  if(!p)
    comp(count);
  return count;
}

void play(int count){
  bool p = false;
  while(count != 0){
    //if(!p)
      count = player(count, p);
    //else
    cout << "####################" << endl;
    printBoard();
    cout << "####################" << endl;
    p = p? false : true;
    printGrid();
    cout << "####################" << endl;
    cout << "size : " << chkGrid().size() << endl;
    cout << "####################" << endl;
    if(count == 0){
      cout << endl << endl << "player " << p << " wins!!" << endl;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll count = gridify();
  printGrid();

  play(count);

  return 0;
}
