# cub3D

## 概要
cub3D は、Wolfenstein 3D にインスパイアされた 3D グラフィックスプロジェクトです。MiniLibX ライブラリを使用し、  
Ray-Casting アルゴリズムを用いて迷路内の一人称視点のリアルタイスな 3D 表現を実装します。

## 動作環境
- OS: Linux
- コンパイラ: cc
- 必須ライブラリ: MiniLibX, libft, math ライブラリ (-lm)

## 必要条件
- C 言語で記述すること
- メモリリークなし
- 強制終了や未定義動作を起こさない
- Makefile 提供 (all, clean, fclean, re)

## 使い方
1. リポジトリをクローンします。
```
git clone https://github.com/fwatanab/cub3d.git
cd cub3d
```
2. ビルドします。
```
make
```
3. プログラムを実行します。
```
./cub3D map/map.cub
```

## 操作方法
- W, A, S, D: 移動
- 左右矢印: 視点回転
- ESC: 終了

## マップ形式
- 0: 空間
- 1: 壁
- N, S, E, W: プレイヤーの初期位置と向き
- テクスチャ設定例:
```
NO ./path_to_north_texture
SO ./path_to_south_texture
WE ./path_to_west_texture
EA ./path_to_east_texture
F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```

## エラーハンドリング
- 無効なマップや設定があった場合は "Error\n" とメッセージを表示して終了

## 著作権
このプロジェクトは 42Tokyo の教育課題です。

