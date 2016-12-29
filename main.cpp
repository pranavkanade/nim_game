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



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll count = 0;
  vvll grid(4, vll(4, 0));
  ll arr[] ={1, 3, 5, 7};
  int temp;
  for(int a = 0; a < 4; a++){
    temp = arr[a];
    count += temp;
    int i = 0;
    while(temp != 0){
      grid[a][i] = temp % 2;
      temp = temp / 2;
      i++;
    }
  }
  
  for(int i = 0; i < grid.size(); i++){
    for(int j = 0; j < grid[i].size(); j++){
      cout << " " << grid[i][j];
    }
    cout << endl;
  }
  ll row;
  ll num;
  bool p = false;
  while(count != 0){
    bool m = true;
    while(m){
      cout << "player " << p << endl;
      cin >> row >> num;
      if(num <= arr[row-1] && row <= 4 && row >= 1 && num != 0){
  	count -= num;
  	arr[row-1] -= num;
  	m = false;
  	if(count == 0){
  	  cout << endl << endl << "player " << p << " wins!!" << endl;
  	  break;
  	}
      }
      else
  	cout << "put correct input" << endl;
    }
    cout << "####################" << endl;
    for(int i = 0; i < 4; i++){
      cout << arr[i] << "\t";
      for(int j = 0; j < arr[i]; j++){
	cout << "1 ";
      }
      cout << endl;
    }
    cout << "####################" << endl;
    p = p? false : true;
  }
  return 0;
}
