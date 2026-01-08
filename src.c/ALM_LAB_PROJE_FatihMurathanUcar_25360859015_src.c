#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

char isim[501];

const char *gezegenler[8] = {
        "Merkur ", "Venus  ", "Dunya  ", "Mars   ", "Jupiter", "Saturn ", "Uranus ", "Neptun "
};

double gravity[8] = {3.70, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15};

double negatif_deger_uyarisi(double x) {
    if (x < 0) {
        printf("Uyari: Negatif deger girildi; ternary operatoru ile mutlak deger aliniyor.\n");
    }
    return x < 0 ? -x : x;
}

void bilim_insani_adi() {
    printf("Bilim insaninin adini giriniz : ");
    scanf(" %499[^\n]", isim);
    printf("Hosgeldiniz, %s\n", isim);
}

void deney_listesi() {
    printf("\n===== DENEY LISTESI =====\n");
    printf("1  - Serbest Dusme\n");
    printf("2  - Yukari Atis\n");
    printf("3  - Agirlik\n");
    printf("4  - Potansiyel Enerji\n");
    printf("5  - Hidrostatik Basinc\n");
    printf("6  - Arsimet Kuvveti\n");
    printf("7  - Basit Sarkac\n");
    printf("8  - Sabit Ip Gerilmesi\n");
    printf("9  - Asansor Deneyi\n");
    printf("-1 - Cikis\n");
}

void serbest_dusme(double *g) {
    double t;
    printf("Sure (saniye): ");
    scanf("%lf", &t);
    t = negatif_deger_uyarisi(t);

    for (int i = 0; i < 8; i++) {
        double h = 0.5 * (*(g + i)) * t * t;
        printf("%s -> Alinan yol: %.2f m\n", gezegenler[i], h);
    }
}

void yukari_atis(double *g) {
    double v0;
    printf("Baslangic hizi (m/s): ");
    scanf("%lf", &v0);
    v0 = negatif_deger_uyarisi(v0);

    for (int i = 0; i < 8; i++) {
        double hmax = (v0 * v0) / (2 * *(g + i));
        printf("%s -> Max yukseklik: %.2f m\n", gezegenler[i], hmax);
    }
}

void agirlik(double *g) {
    double m;
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    m = negatif_deger_uyarisi(m);

    for (int i = 0; i < 8; i++)
        printf("%s -> Agirlik: %.2f N\n", gezegenler[i], m * *(g + i));
}

void potansiyel_enerji(double *g) {
    double m, h;
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    printf("Yukseklik (m): ");
    scanf("%lf", &h);

    m = negatif_deger_uyarisi(m);
    h = negatif_deger_uyarisi(h);

    for (int i = 0; i < 8; i++)
        printf("%s -> Ep: %.2f J\n", gezegenler[i], m * *(g + i) * h);
}

void hidrostatik_basinc(double *g) {
    double rho, h;
    printf("Sivi yogunlugu (kg/m^3): ");
    scanf("%lf", &rho);
    printf("Derinlik (m): ");
    scanf("%lf", &h);

    rho = negatif_deger_uyarisi(rho);
    h = negatif_deger_uyarisi(h);

    for (int i = 0; i < 8; i++)
        printf("%s -> Basinc: %.2f Pa\n", gezegenler[i], rho * *(g + i) * h);
}

void arsimet(double *g) {
    double rho, V;
    printf("Sivi yogunlugu (kg/m^3): ");
    scanf("%lf", &rho);
    printf("Batan hacim (m^3): ");
    scanf("%lf", &V);

    rho = negatif_deger_uyarisi(rho);
    V = negatif_deger_uyarisi(V);

    for (int i = 0; i < 8; i++)
        printf("%s -> Kaldirma Kuvveti: %.2f N\n", gezegenler[i], rho * *(g + i) * V);
}

void basit_sarkac(double *g) {
    double L;
    printf("Ip uzunlugu (m): ");
    scanf("%lf", &L);
    L = negatif_deger_uyarisi(L);

    for (int i = 0; i < 8; i++) {
        double T = 2 * PI * sqrt(L / *(g + i));
        printf("%s -> Periyot: %.2f s\n", gezegenler[i], T);
    }
}

void ip_gerilmesi(double *g) {
    double m;
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    m = negatif_deger_uyarisi(m);

    for (int i = 0; i < 8; i++)
        printf("%s -> Ip gerilmesi: %.2f N\n", gezegenler[i], m * *(g + i));
}

void asansor(double *g) {
    double m, a;
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    printf("Asansor ivmesi (m/s^2): ");
    scanf("%lf", &a);

    m = negatif_deger_uyarisi(m);

    for (int i = 0; i < 8; i++) {
        double N = a >= 0 ? m * (*(g + i) + a) : m * (*(g + i) - (-a));
        printf("%s -> Hissedilen agirlik: %.2f N\n", gezegenler[i], N);
    }
}

int main() {
    bilim_insani_adi();

    int secim;
    double *g = gravity;

    while (1) {
        deney_listesi();
        printf("Seciminiz: ");
        scanf("%d", &secim);

        if (secim == -1) {
            printf("\nProgram sonlandirildi.\n");
            break;
        }

        switch (secim) {
            case 1: serbest_dusme(g); break;
            case 2: yukari_atis(g); break;
            case 3: agirlik(g); break;
            case 4: potansiyel_enerji(g); break;
            case 5: hidrostatik_basinc(g); break;
            case 6: arsimet(g); break;
            case 7: basit_sarkac(g); break;
            case 8: ip_gerilmesi(g); break;
            case 9: asansor(g); break;
            default: printf("Gecersiz secim!\n");
        }
    }
    return 0;
}
