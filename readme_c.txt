* ----- 競プロのためのサンプル (C ver.) -----

* アカウント
アカウントは zakkydaily@gmail.com です!! (パスワード: A........)

* 事前準備
[1] このreadme.txtを別ウィンドウ(テキストエディット)で表示する!!
[2] Google翻訳とChatGPTをChromeで開いておく!!
[3] (問題開始後) 
    1. ターミナルで source paiza-init [問題番号] [入力例数] を実行し, python環境を用意する!!
    2. [問題番号].cを作成
    3. 実行コマンド: c sample.c < input_1.txt

* サンプルは下に書いてあります

* 注意!!
[1] ----- デバッグ用にいれたプログラムは消すこと!! (テストケースを追加して確認すること!!) -----

* 1文字取得
[整数]　  int N; scanf("%d", &N);
[小数]　  double N; scanf("%f", &N);
[文字列]  char N[MAX_CHAR_LENGTH]; scanf("%s", N);

* 複数文字取得
[整数]　  int H, W; scanf("%d%d", &H, &W);
[小数]　  double H, W; scanf("%f%f", &H, &W);
[文字列]  char H[MAX_CHAR_LENGTH], W[MAX_CHAR_LENGTH]; scanf("%s%s", &H, &W);

* リストでの取得
[整数]  　　　　　  int A[W]; for (int i=0; i<W; i++) scanf("%d", A+i);
[小数]　　　　  　  double A[W]; for (int i=0; i<W; i++) scanf("%f", A+i);
[文字列(空白あり)]  char A[W][MAX_CHAR_LENGTH]; for (int i=0; i<W; i++) scanf("%s", A[i]);
[文字列(空白なし)]  char A[W]; scanf("%s", A);

* 2次元リストの取得 (Nは縦方向の回数)
[整数]　　　　  　  int A[H][W]; for (int y=0; y<H; y++) for (int x=0; x<W; x++) scanf("%d", A[y]+x);
[小数]　　　　　    double A[H][W]; for (int y=0; y<H; y++) for (int x=0; x<W; x++) scanf("%f", A[y]+x);
[文字列(空白あり)]  char A[H][W][MAX_CHAR_LENGTH]; for (int y=0; y<H; y++) for (int x=0; x<W; x++) scanf("%s", A[y]+x);
[文字列(空白なし)]  char A[H][W]; for (int y=0; y<H; y++) scanf("%s", A[y]);

* 出力方法 (a, b, ... に変数または数式を入れる | 型 ... int: %d, double: %f, char: %c, char*: %s, pointer: %p)
printf("%d %d\n", a, b)

* 配列の出力 (Aを配列とする | 小数の時は %f に変える)
[整数・小数]　　　　　　　　　　    for (int i=0; i<W; i++) { if (i>0) printf(" "); printf("%d", A[i]); } printf("\n");
[文字列(空白なし, スペース区切り)]  for (int i=0; A[i]!='\0'; i++) { if (i>0) printf(" "); printf("%c", A[i]); } printf("\n");
[文字列(空白なし)]　　　　　　　    printf("%s\n", A);

* 2次元配列の出力 (Aを配列とする | 小数の時は %f に変える)
[整数・小数]　　　　　　　　　　    for (int y=0; y<H; y++) { for (int x=0; x<W; x++) { if (x>0) printf(" "); printf("%d", A[y][x]); } printf("\n"); }
[文字列(空白なし, スペース区切り)]  for (int y=0; y<H; y++) { for (int i=0; A[i]!='\0'; i++) { if (x>0) printf(" "); printf("%c", A[y][i]); } printf("\n"); }
[文字列(空白なし)]　　　　　　　    for (int y=0; y<H; y++) { printf("%s\n", A); }

* 二次元リストの初期化
int A[H][W]; for (int y=0; y<H; y++) for (int x=0; x<W; x++) A[y][x] = 0;

* 順列の総リスト

* 前後探索

* 周囲探索

* クリップ

* 二分探索ライブラリの使い方

* 実行方法
python sample.py < input_1.py
