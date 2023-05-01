#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
deque<int> q;
for (int i = 0 ; i<n; i++)
{//the front of queue must always contain the gratest value in window
//If front contains a max value not in that window or from previous window
//pop the front
    if(!q.empty() && q.front()==i-k)
    {
        q.pop_front();
    }
//main condition that identifies the index with highest value in the window
//keeps track of index
    while(!q.empty()&& arr[i]>arr[q.back()])
    {
        q.pop_back();
    }
    q.push_back(i);
    //prints everytime an i greater than window is encountered
    //in other words prints after shifting window by 1 
    if(!q.empty()&&i>=k-1)
    {
        cout<<arr[q.front()]<<" ";
    }
}
cout<<endl;
}
       

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
