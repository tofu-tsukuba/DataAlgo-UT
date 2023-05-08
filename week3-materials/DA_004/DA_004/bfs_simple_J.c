// Breadth First Search.
// 2020/05 kameda[at]ccs.tsukuba.ac.jp
#include <stdio.h> // printf()
#include "graph3.h"

// 幅優先探索本体
void bfs(int StartingRoom){
	int listed[N]; // 0 未, 1 済
	int queue[N];
	int qhead = 0; // queue head
	int qtail = 0; // queue tail
    
    int CurrentRoom;
    int RoomToCheck;

	for (RoomToCheck = 0; RoomToCheck < N; RoomToCheck++)
		listed[RoomToCheck] = 0;
	
	printf("幅優先探索を 頂点%d から開始します．\n", StartingRoom);
    // StartingRoomをキューに追加する
    queue[qtail] = StartingRoom;
    qtail++;

    // キューに追加したということは訪れる対象として計上（列挙）済みということ
	printf("頂点 %d をこれ以降は列挙済として扱います．\n", StartingRoom);
    listed[StartingRoom] = 1;
 
    // キューに処理対象がある限り作業を継続
	while (qhead < qtail) {
		printf("現在のキュー： 長さ %d, 先頭の頂点は %d, 末尾の頂点は %d\n", qtail - qhead, queue[qhead], queue[qtail - 1]);
    	{int i; printf("現在のキュー： "); for (i = qhead; i < qtail; i++) printf("%d ", queue[i]); printf("\n");}

        // キュー先頭から１つ呼んで作業開始（キューからは削除）
        printf("キュー先頭の頂点 %d をキューから外して処理を開始します．\n", queue[qhead]);
		CurrentRoom = queue[qhead];
        qhead++;

        // ※ここで何かしらの作業を行うのかも．

        // 次にどの頂点を列挙していくか検討
		for (RoomToCheck = 0; RoomToCheck < N; RoomToCheck++) {
            if (edge[CurrentRoom][RoomToCheck] == 0) {
				printf("  (頂点 %d にて) 頂点 %d は隣接していませんでした‥\n", CurrentRoom, RoomToCheck);
            } else if (listed[RoomToCheck] != 0) {
				printf("  (頂点 %d にて) 頂点 %d は隣接はしてますがすでに処理済でした‥\n", CurrentRoom, RoomToCheck);
            } else {         
				printf("  (頂点 %d にて) 頂点 %d は隣接でかつキューに繋いだことがないので、キューの最後尾に追加します。\n", CurrentRoom, RoomToCheck);
                // RoomToCheckをキューに追加する
				queue[qtail] = RoomToCheck;
                qtail++;

                // キューに追加したということは訪れる処理対象として計上（列挙）済みということ
                printf("  (頂点 %d にて) 頂点 %d をこれ以降は列挙済として扱います．\n", CurrentRoom, RoomToCheck);
				listed[RoomToCheck] = 1;
			}
		}
	}
	printf("何も残っていないので幅優先探索を終了します．\n");

	printf("幅優先探索による頂点の列挙．\n");
	for (CurrentRoom = 0; CurrentRoom < N; CurrentRoom++)
		printf("%d ", queue[CurrentRoom]);
    printf("\n");

	return;
}

int main(int argc, char *argv[]){
	bfs(0); // 開始頂点番号を引数にしてbfs関数を呼び出す
	return 0;
}
