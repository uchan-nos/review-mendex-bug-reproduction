= 索引バグの報告用ドキュメント

片仮名や平仮名の索引，例えば「@<idx>{イテレータ}」や「@<idx>{なると}」はきちんとした索引位置になりますが，「@<idx>{識別子}」は@<list>{dict-file}のような辞書ファイルを用意しても期待した索引位置になりません．「識別子」は「イテレータ」と「なると」の中間に配置されてほしいのですが，一番最後になってしまいます（@<img>{index_sample}）．

//list[dict-file][my.dic辞書ファイル]{
識別子  しきべつし
//}

//image[index_sample][索引の出力][scale=0.3]{
//}

このとき，@<tt>{mendex}に関する設定は@<list>{mendex-config}のようになっています．

//list[mendex-config][mendexの設定]{
  makeindex: true
  makeindex_dic: my.dic
  makeindex_mecab: false
//}

== 回避方法

//list[mendex-options][mendexの設定]{
  makeindex: true
  makeindex_dic: my.dic
  makeindex_mecab: false
  makeindex_options: "-f -r -I utf-8 -d /home/uchan/workspace/review_test/my.dic"
//}

@<list>{mendex-options}のように@<tt>{mendex}のオプションで辞書ファイルを明示すると辞書が有効になるようです（@<img>{index_revised}）．辞書ファイルは絶対パスで指定しないとうまくいきません．なぜなら@<tt>{rake}のビルドが@<tt>{/tmp}以下で実行されるからです．

//image[index_revised][索引の出力が修正された][scale=0.3]{
//}
