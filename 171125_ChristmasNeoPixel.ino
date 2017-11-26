// 네오픽셀로 크리스마스 트리만들기 프로젝트
/*
code for arduino 
    https://github.com/happythingsmaker/ChristmasNeoPixel/blob/master/171125_ChristmasNeoPixel.ino
3d models 
    https://www.thingiverse.com/thing:2668669
Youtube Video
    https://www.youtube.com/watch?v=257uMjfjePQ
Instruction (Korean) 
    https://happythingsmaker.gitbooks.io/christmasneopixel/content/
Creator's blog 
    http://happyThingsMaker.com
*/
#include <Adafruit_NeoPixel.h>
//#include <Bounce2.h>

#define PIN 4
#define MIC_0_PIN 2
#define MIC_1_PIN 3
//#define DEALY 15
#define DEALY 30
#define BUTTON_DEBOUNCE_PERIOD 20 //ms
#define LED_COUNT 70

//네오픽셀을 사용하기 위해 객체 하나를 생성한다.
//첫번째 인자값은 네오픽셀의 LED의 개수
//두번째 인자값은 네오픽셀이 연결된 아두이노의 핀번호
//세번째 인자값은 네오픽셀의 타입에 따라 바뀌는 flag
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

//Bounce buttonMic = Bounce();

void setup() {
    strip.begin(); //네오픽셀을 초기화하기 위해 모든LED를 off시킨다
    strip.show();
    //pinMode(MICPIN, INPUT);

    //마이크로 입력 하려면 여기를 해제하시오
    //    attachInterrupt(digitalPinToInterrupt(MIC_0_PIN), checkSound, FALLING);
    //    attachInterrupt(digitalPinToInterrupt(MIC_1_PIN), checkSound, FALLING);

}
int cnt = 0;
bool soundFlag = true;
long lastTime = 0;
void loop() {
    while (1) {
        //heartBeat(100, 20, 20, 1500);
        specialDelay(1000);
        //delay(1000);
        //        if (soundFlag == true) {
        //            rotateVisual();
        //        }

        if (lastTime + 15000 < millis()) {
            soundFlag = true;
            lastTime = millis();
        }
    }

}

void specialDelay(long timeMs) {
    while (timeMs--) {
        delay(1);
        if (soundFlag == true) {
            rotateVisual();
        }
    }


}
void rotateVisual() {

    switch (cnt++ % 6) {
        case 0:
            //녹색 랜덤
            colorWipe(strip.Color(random(0, 127), 255, random(0, 127)), DEALY); //녹색 출력
            colorWipe(strip.Color(random(0, 64), 255, random(0, 64)), DEALY); //녹색 출력
            colorWipe(strip.Color(random(0, 20), 255, random(0, 20)), DEALY); //녹색 출력
            break;
        case 1:
            //올랜덤
            colorWipe(strip.Color(random(0, 255), random(0, 255), random(0, 255)), DEALY); //올랜덤 출력
            colorWipe(strip.Color(random(0, 128), random(0, 128), random(0, 128)), DEALY); //올랜덤 출력
            colorWipe(strip.Color(random(0, 50), random(0, 50), random(0, 50)), DEALY); //올랜덤 출력
            break;
        case 2:
            //빨간 랜덤
            colorWipe(strip.Color(255, random(0, 255), random(0, 255)), DEALY); //빨간색 출력
            colorWipe(strip.Color(255, random(0, 127), random(0, 127)), DEALY); //빨간색 출력
            colorWipe(strip.Color(255, random(0, 64), random(0, 64)), DEALY); //빨간색 출력
            break;
        case 3:
            //파란 랜덤
            colorWipe(strip.Color(random(0, 127), random(0, 127), 255), DEALY); //파란색 출력
            colorWipe(strip.Color(random(0, 127), random(0, 127), 255), DEALY); //파란색 출력
            colorWipe(strip.Color(random(0, 127), random(0, 127), 255), DEALY); //파란색 출력
            break;
        case 4:
            // 올컬러 랜덤 올포지션
            colorAllRandom();
            colorAllRandom();
            colorAllRandom();
            break;
        case 5:
            rainbowCycle(DEALY / 2); //레인보우
            rainbowCycle(DEALY / 2); //레인보우
            break;
        case 6:
            theaterChase(strip.Color(random(0, 127), random(0, 127), 255), DEALY * 2); //파란색 출력
            theaterChase(strip.Color(random(0, 127), random(0, 127), 255), DEALY * 2); //파란색 출력
            theaterChase(strip.Color(random(0, 127), random(0, 127), 255), DEALY * 2); //파란색 출력
            break;
        case 7:
            theaterChase(strip.Color(127, 127, 127), DEALY * 2); //흰색 출력
            theaterChase(strip.Color(127, 127, 127), DEALY * 2); //흰색 출력
            theaterChase(strip.Color(127, 127, 127), DEALY * 2); //흰색 출력
            colorWipe(strip.Color(0, 0, 0), DEALY); //off
            break;
        case 8:
            //씨어터 빨간 랜덤
            theaterChase(strip.Color(127,   random(0, 127),   random(0, 127)), DEALY);
            theaterChase(strip.Color(127,   random(0, 127),   random(0, 127)), DEALY);
            theaterChase(strip.Color(127,   random(0, 127),   random(0, 127)), DEALY);
            colorWipe(strip.Color(0, 0, 0), DEALY); //off

            break;
        case 9:
            //빨 녹 파 랜덤 하나씩
            colorWipe(strip.Color(255, random(0, 255), random(0, 255)), DEALY); //빨간색 출력
            colorWipe(strip.Color(random(0, 25), 255, random(0, 25127)), DEALY); //녹색 출력
            colorWipe(strip.Color(random(0, 255), random(0, 255), 255), DEALY); //파란색 출력
            colorWipe(strip.Color(random(0, 255), random(0, 255), random(0, 255)), DEALY); //off
            break;
    }
    colorWipe(strip.Color(0, 0, 0), DEALY); //off
    soundFlag = false;
}

void checkSound() {
    soundFlag = true;
}

void heartBeat(uint16_t r, uint16_t g, uint16_t b, uint16_t msFrequency) {
    uint16_t steps = msFrequency / DEALY;

    for (uint8_t i = 0; i < steps ; i ++) {
        colorAll(strip.Color(r * i / steps , g * i / steps , b * i / steps));
    }
    for (uint8_t i = steps; i > 0; i --) {
        colorAll(strip.Color(r * i / steps , g * i / steps, b * i / steps));
    }
    colorAll(strip.Color(0, 0, 0));
}
void colorAll(uint32_t c) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, c);
        strip.show();
        if (soundFlag == true) {
            return;
        }
    }
}

void colorAllRandom() {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(random(0, 255), random(0, 255), random(0, 255)));
        delay(DEALY);
        strip.show();
    }
}

//NeoPixel에 달린 LED를 각각 주어진 인자값 색으로 채워나가는 함수
void colorWipe(uint32_t c, uint8_t wait) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, c);
        strip.show();
        delay(wait);
    }
}

//모든 LED를 출력가능한 모든색으로 한번씩 보여주는 동작을 한번하는 함수
void rainbow(uint8_t wait) {
    uint16_t i, j;

    for (j = 0; j < 256; j++) {
        for (i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, Wheel((i + j) & 255));
        }
        strip.show();
        delay(wait);
    }
}

//NeoPixel에 달린 LED를 각각 다른색으로 시작하여 다양한색으로 5번 반복한다
void rainbowCycle(uint8_t wait) {
    uint16_t i, j;

    for (j = 0; j < 256 * 5; j++) {
        for (i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
        }
        strip.show();
        delay(wait);
    }
}

//입력한 색으로 LED를 깜빡거리며 표현한다
void theaterChase(uint32_t c, uint8_t wait) {
    for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
        for (int q = 0; q < 3; q++) {
            for (int i = 0; i < strip.numPixels(); i = i + 3) {
                strip.setPixelColor(i + q, c);  //turn every third pixel on
            }
            strip.show();

            delay(wait);

            for (int i = 0; i < strip.numPixels(); i = i + 3) {
                strip.setPixelColor(i + q, 0);      //turn every third pixel off
            }
        }
    }
}

//LED를 다양한색으로 표현하며 깜빡거린다
void theaterChaseRainbow(uint8_t wait) {
    for (int j = 0; j < 256; j++) {   //256가지의 색을 표현
        for (int q = 0; q < 3; q++) {
            for (int i = 0; i < strip.numPixels(); i = i + 3) {
                strip.setPixelColor(i + q, Wheel( (i + j) % 255));
            }
            strip.show();

            delay(wait);

            for (int i = 0; i < strip.numPixels(); i = i + 3) {
                strip.setPixelColor(i + q, 0);
            }
        }
    }
}

//255가지의 색을 나타내는 함수
uint32_t Wheel(byte WheelPos) {
    if (WheelPos < 85) {
        return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    } else if (WheelPos < 170) {
        WheelPos -= 85;
        return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    } else {
        WheelPos -= 170;
        return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
}
