//-слэш - разрез /слэш в гору \слэш с горы
//Маркеры памяти
//void - пустота - космос - ничего - не использует память
//int  - интеджер - целое - память для чисел 12345
//char - символы - буквы
//long - для всего
//------setup - Название{}
//------() - круглые скобки (SHIFT+9, SHIFT+0) настройки
//------{} - фигурные скобки (SHIFT+Х, SHIFT+Ъ) Начало и конец
//Сложных приказов
//--------------------------
#include <FastLED.h>

#define NUM_LEDS 64     // Количество светодиодов (8x8=64)
#define DATA_PIN 3       // Порта для передачи сигнала (D3)

CRGB leds[NUM_LEDS];    // Массив объектов CRGB для хранения цвета каждого светодиода



// способности 
// узнать время с помощью DS1302
int k[5]={0,0,0,0};
int s_k=sizeof(k)/sizeof(k[0]);


void knop(int a){
    k[a]=1;
}

void reset(){
  for (int a=1; a<s_k; a++){
    k[a]=0;
  }
}

/*
* Включает пиксель на заданных координатах XY с определенным цветом
*/
void setPixelColor(uint8_t x, uint8_t y, const CRGB& color) {
  if (x >= 0 && x < 8 && y >= 0 && y < 8) {
    uint8_t index = y * 8 + x;           // Преобразуем двумерные координаты в индекс массива
    leds[index] = color;                 // Присваиваем цвет данному элементу массива
  }
}

/*
* Полностью очищает всю матрицу
*/
void clearAllPixels() {
  fill_solid(leds, NUM_LEDS, CRGB::Black);  // Заполняем массив черным цветом
}

void clearPix(){                    // Задержка 2 секунды
  clearAllPixels();                // Очищаем всю матрицу  
}
void pixel(int x, int y, int c){
  setPixelColor(x, y, c);  // Например, включаем красный пиксель в позиции (X=3, Y=5)
  FastLED.show();                  // Обновляем состояние всех светодиодов
                    // Повтор цикла
}

void setup() {  
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(64);  // Устанавливаем яркость (0–255)
   clearPix();
}


// 1 ждёт
// 2 игра 
// 3 проиграл 
// 4 выиграл
// 5 разряжено
   int s=1;
void loop() {

    if(s==1){
      for (int a=0;a<8;a++){
        pixel(0,a,CRGB::Red);
      }
      for (int a=0;a<8;a++){
        pixel(a,0,CRGB::Red);
      }

        for (int a=0;a<8;a++){
        pixel(7,a,CRGB::Red);
      }
      for (int a=0;a<8;a++){
        pixel(a,7,CRGB::Red);
      }
      // pixel(1,1,CRGB::Blue);
    }
  
  if(s==2){
      
    }
  
  if(s==3){
      
    }
  
  if(s==4){
      
    }
  
  if(s==5){
      
    }
}
