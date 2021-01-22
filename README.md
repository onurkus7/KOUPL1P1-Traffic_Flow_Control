# KOUPL1P1-Traffic_Flow_Control
 The 1st project of the KOU Programming Laboratory lesson: "Control of Traffic Flow".
TRAFİK AKIŞININ MODELLENMESİ

Onur Kuş	-	170201030
Aziz Yelbay	-	170201046

Bu readme.txt dosyası, trafik akışı modellenmesi projesine aittir.



1-PAKETİN İÇERİĞİ:
----------
170201046-170201030 .txt - Projenin tek dosyaya indirgenmiş salt kaynak kodu.
readme.txt - Bu dosya.
Prolab1p1.zip - Projenin kaynak kodunun ve yardımcı dosyaların ziplenmiş hali.
rapor.docx - Proje raporu.
----------


2-SİSTEM GEREKSİNİMLERİ:
-------------------
CodeBlocks geliştirme ortamı ve allegro kütüphanesi
-------------------


3-PROJEYİ ÇALIŞTIRMAK:
-------------------
Paket içeriğini yukarıda görebilirsiniz.

CodeBlocks ortamında derleyip çalıştırmak yeterlidir.


4- PARAMETRELER
---------------------------
Kodun çalışması için başlangıçta herhangi bir parametre gerekmiyor.
------------------


5- PROGRAMIN KULLANIMI
-----------------------------
Trafik akışı modellenmesi programımız kullanıcıya 2 adet harita seçimi sunar. 
Seçim yapıldıktan sonra seçilen harita üzerinden 2’şerli olmak üzere giriş-çıkış (kullanıcı ikiden fazla giriş ya da çıkış verisi girmesi engellenmiştir) ve bu ana yollara bağlı ara yolların yönleri şekiller ile tayin ettirilir. 
Ardından kullanıcı istediği caddelere ortalama araç sayısını girmesini ve değeri bilinmeyen caddeler içinse -1 değeri girilmesi istenir.
Kesişimlere göre denklemler olusturulur.Denklemlerdeki bilinmeyenlerin katsayilari ve sabit degerler matrise yazdirir.Matrise göre program bilinmeyenleri bularak ekrana yazdırır.
