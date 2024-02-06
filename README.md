### tetris
Dikkat: Bazı durumlarda kod compile edilirken hatalı gösterimler oluşabiliyor (sütun ve satırlar karışabilir). Hatalı gösterimlerde lütfen kod tekrar compile edilsin.

Tetris oyunu C dilinde uygulanmıştır. Oyun, bir karşılama mesajı ve en yüksek skoru göstererek başlar. Kullanıcıya yeni bir oyun başlatması veya çıkmak isteyip istemediği sorulur. Kullanıcı yeni bir oyun başlatmaya karar verirse, oyun alanı için satır ve sütun sayısını girmesi istenir. Oyun alanı daha sonra sıfırlarla başlatılır.
Oyun, kullanıcının çıkmaya karar verene kadar devam eden bir döngüye girer. Döngünün her iterasyonunda rastgele bir Tetris parçası (aynı zamanda Tetrimino olarak da bilinir) oluşturulur. Tetriminolar 3x3 matrislerdir ve yedi farklı türde Tetrimino vardır, her biri farklı bir matrisle temsil edilir. Oluşturulan Tetrimino, kullanıcıya mevcut oyun alanıyla birlikte gösterilir.
Kullanıcı daha sonra Tetrimino'yu döndürmesi istenir. Onu sola, sağa veya hiç döndürmemeyi seçebilir. Dönme işlemi, flip_left ve flip_right fonksiyonları tarafından gerçekleştirilir. Bu fonksiyonlar mevcut Tetrimino'yu ve bir sonuç matrisini parametre olarak alır ve sonuç matrisini döndürülmüş Tetrimino ile doldurur.
Dönmeden sonra, kullanıcı Tetrimino'yu yerleştirmek istediği sütunu belirtmesi istenir. Program, yerleştirmenin geçerli olup olmadığını kontrol eder. Geçerliyse, Tetrimino oyun alanına eklenir. Değilse, kullanıcıdan başka bir sütun girmesi istenir.
Program daha sonra oyun alanında dolu satırlar olup olmadığını kontrol eder. Eğer varsa, bu satırlar kaldırılır, üstlerindeki satırlar aşağı hareket ettirilir ve kullanıcının puanı artar.
Oyun, kullanıcı çıkmaya karar verene kadar bu şekilde devam eder. Eğer kullanıcının puanı en yüksek puandan daha yüksekse, en yüksek puan kullanıcının puanı ile güncellenir.
