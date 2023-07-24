/*
En Fazla 171 Basamaklý Bir Sayýnýn Türkçe Okunuþunu Ekrana Yazdýrýr
*/

#ifndef SAYIOKU_H
#define SAYIOKU_H
#include <stdio.h>
#include "lib/metin.h" // https://github.com/seymenkonuk/Metin-C

void sayiOku(const char sayi[]); // En Fazla 171 Basamaklý Bir Sayýnýn Türkçe Okunuþunu Ekrana Yazdýrýr

void sayiOku(const char sayi[]) {
    if (!tamSayiMi(sayi)) { printf("HATA"); return;}
    if (sayi[0] != '+' && sayi[0] != '-') { sayiOku(formatliMetin(sayi)); return;}
    if (sayi[1] == '0' && sayi[2] != '\0'){ sayiOku(formatliMetin(sayi)); return;}
    int basamak, i, kontrol = 0;
    char okunus[2][10][7] = {
        {"", "Bir", "Iki", "Uc", "Dort", "Bes", "Alti", "Yedi", "Sekiz", "Dokuz"},
        {"", "On", "Yirmi", "Otuz", "Kirk", "Elli", "Altmis", "Yetmis", "Seksen", "Doksan"}
    };
    char basamaklar[57][23] = {
        "", "Bin", "Milyon", "Milyar", 
        "Trilyon", "Katrilyon", "Kentilyon", "Seksilyon", 
        "Septilyon", "Oktilyon", "Nonilyon", "Desilyon", 
        "Undesilyon", "Dodesilyon", "Tredesilyon", "Kattuordesilyon", 
        "Kendesilyon", "Sexdesilyon", "Septendesilyon", "Oktodesilyon",
        "Novemdesilyon", "Vigintilyon", "Unvigintilyon", "Dovigintilyon", 
        "Trevigintilyon", "Kattuorvigintilyon", "Kenvigintilyon", "Sexvigintilyon", 
        "Septenvigintilyon", "Oktovigintilyon", "Novemvigintilyon", "Trigintilyon", 
        "Untrigintilyon", "Dotrigintilyon", "Tretrigintilyon", "Kattuortrigintilyon", 
        "Kentrigintilyon", "Sextrigintilyon", "Septentrigintilyon", "Oktotrigintilyon", 
        "Novemtrigintilyon", "Katragintilyon", "Unkatragintilyon", "Dokatragintilyon", 
        "Trekatragintilyon", "Kattuorkatragintilyon", "Kenkatragintilyon", "Sexkatragintilyon", 
        "Septenkatragintilyon", "Oktokatragintilyon", "Novemkatragintilyon", "Kenquagintilyon", 
        "Unkenquagintilyon", "Dokenquagintilyon", "Trekenquagintilyon", "Kattuorkenquagintilyon", 
        "Kenkenquagintilyon"
    };
    
    // Basamak Sayýsýný Bul
    for (basamak=1; sayi[basamak] != '\0'; basamak++);
    if (basamak == 2 && sayi[1] == '0')
        printf("Sifir");
    else if (sayi[0] == '-')
        printf("Eksi");
    
    for (i=1; i<basamak; i++) {
        int bno = ((basamak-i-1) % 3), rakam = sayi[i]-48;
        
        if (rakam != 0) kontrol = 1;
        
        if (!(bno == 2 && rakam == 1)) // bir yüz deðilse
            printf("%s", okunus[bno % 2][rakam]);
        
        if (bno == 2 && rakam != 0)
            printf("Yuz");
        else if (bno == 0 && kontrol == 1) {
            printf("%s", basamaklar[(basamak-i-1) / 3]);
            kontrol = 0;
        }
    }
}
#endif
