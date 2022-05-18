//program to demostrate a race condition
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
using namespace std;

int balance = 0;
void *computebal(void *arg){
	int b;
	b = balance;
	for(int i=0;i < 5000; i++){
	     int c = 5000 * 1234;
	}
	b += 10;
	balance = b;
	return NULL;
}

int main(){
	int i;
	pthread_t thread_id[200];
	cout << "Balance Before Thread: " << balance << endl;
	for(i=0;i < 200;i++){
		pthread_create(&thread_id[i],NULL,computebal,NULL);
	}
	for(i=0;i < 200;i++){
		pthread_join(thread_id[i],NULL);
	}
	cout << "Balance After Thread: " << balance << endl;
	exit(EXIT_SUCCESS);
}


