// ConsoleApplication1.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "windows.h"
#include "MMSystem.h"

using namespace System;
using namespace std;

#define FILAS 35
#define COLUMNAS 70
#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
#define ESC 27
#define YCENTRO 18
#define XCENTRO 34
#define XCUADRO 18
#define YCUADRO 10
#define YENEMIGO1 4
#define YENEMIGO2 31

int color_borde = 'whit';
int color_puntos = 'yell';
int color_vida = 'red';
int color_cofre = 'gree';
int color_nave = 'gray';
int tipo_nave = 1;
int bonus_vidas = 4000;
bool musica = true;

//GENERALES

void cursor(int x,int y)
{
	Console::SetCursorPosition(x, y);
}
void ocultar_cursor()
{
	Console::CursorVisible = false;
}
void color_texto(int color)
{
	if (color == 'blue'){ Console::ForegroundColor = ConsoleColor::Blue; }
	if (color == 'red'){ Console::ForegroundColor = ConsoleColor::Red; }
	if (color == 'cyan'){ Console::ForegroundColor = ConsoleColor::Cyan; }
	if (color == 'yell'){ Console::ForegroundColor = ConsoleColor::Yellow; }
	if (color == 'blac'){ Console::ForegroundColor = ConsoleColor::Black; }
	if (color == 'whit'){ Console::ForegroundColor = ConsoleColor::White; }
	if (color == 'gray'){ Console::ForegroundColor = ConsoleColor::Gray; }
	if (color == 'gree'){ Console::ForegroundColor = ConsoleColor::Green; }
	if (color == 'mage'){ Console::ForegroundColor = ConsoleColor::Magenta; }
	if (color == 'dred'){ Console::ForegroundColor = ConsoleColor::DarkRed; }
	if (color == 'dcya'){ Console::ForegroundColor = ConsoleColor::DarkCyan; }
}
void Color_nave(int color_nave)
{
	switch (color_nave)
	{
		case 'gray':
		{
			color_texto('gray'); break;
		}
		case 'red':
		{
			color_texto('red'); break;
		}
		case 'gree':
		{
			color_texto('gree'); break;
		}
		case 'blue':
		{
			color_texto('blue'); break;
		}
		case 'yell':
		{
			color_texto('yell'); break;
		}
		case 'mage':
		{
			color_texto('mage'); break;
		}
	}
}
void Color_mapa(int color_objeto)
{
	switch (color_objeto)
	{
		case 'gray':
		{
			color_texto('gray'); break;
		}
		case 'red':
		{
			color_texto('red'); break;
		}
		case 'gree':
		{
			color_texto('gree'); break;
		}
		case 'blue':
		{
			color_texto('blue'); break;
		}
		case 'whit':
		{
			color_texto('whit'); break;
		}
		case 'mage':
		{
			color_texto('mage'); break;
		}
		case 'yell':
		{
			color_texto('yell'); break;
		}
	}
}
void Color_enemigo(int color_objeto)
{
	switch (color_objeto)
	{
		case 1:
		{
			color_texto('blue'); break;
		}
		case 2:
		{
			color_texto('red'); break;
		}
		case 3:
		{
			color_texto('gree'); break;
		}
		case 4:
		{
			color_texto('gray'); break;
		}
		case 5:
		{
			color_texto('mage'); break;
		}
		case 6:
		{
			color_texto('yell'); break;
		}
		case 7:
		{
			color_texto('whit'); break;
		}
		case 8:
		{
			color_texto('cyan'); break;
		}
		case 9:
		{
			color_texto('red'); break;
		}
		
	}
}
void segundos(int n)
{
	int x = 0;
	while (x < n)
	{
		x++;
		Sleep(1000);
	}
}

//MUSICA

void detener_musica()
{
	PlaySound(NULL, NULL, 0);
}
void musica_menu()
{
	PlaySound(TEXT("MENU.wav"), NULL, SND_LOOP | SND_ASYNC);
}
void musica_nivel1()
{
	PlaySound(TEXT("NIVEL_1.wav"), NULL, SND_LOOP | SND_ASYNC);
}
void musica_nivel2()
{
	PlaySound(TEXT("NIVEL_2.wav"), NULL, SND_LOOP | SND_ASYNC);
}
void musica_nivel3()
{
	PlaySound(TEXT("NIVEL_3.wav"), NULL, SND_LOOP | SND_ASYNC);
}
void musica_nivel4()
{
	PlaySound(TEXT("NIVEL_4.wav"), NULL, SND_LOOP | SND_ASYNC);
}
void musica_nivel5()
{
	PlaySound(TEXT("NIVEL_5.wav"), NULL, SND_LOOP | SND_ASYNC);
}
void game_over_sound()
{
	PlaySound(TEXT("GAME_OVER.wav"), NULL, SND_ASYNC);
}
void ganaste_sound()
{
	PlaySound(TEXT("NIVEL_COMPLETO.wav"), NULL, SND_ASYNC);
}
void musica_gracias()
{
	PlaySound(TEXT("GRACIAS.wav"), NULL, SND_LOOP | SND_ASYNC);
}

//NAVE

void nave_arriba_1(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)178;
	cursor(x_nave - 1, y_nave); cout << (char)201;
	cursor(x_nave + 1, y_nave); cout << (char)187;
}
void nave_abajo_1(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)178;
	cursor(x_nave - 1, y_nave); cout << (char)200;
	cursor(x_nave + 1, y_nave); cout << (char)188;
}
void nave_izquierda_1(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)178;
	cursor(x_nave, y_nave - 1); cout << (char)201;
	cursor(x_nave, y_nave + 1); cout << (char)200;
}
void nave_derecha_1(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)178;
	cursor(x_nave, y_nave - 1); cout << (char)187;
	cursor(x_nave, y_nave + 1); cout << (char)188;
}
void nave_arriba_2(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)206;
	cursor(x_nave - 1, y_nave); cout << (char)204;
	cursor(x_nave + 1, y_nave); cout << (char)185;
}
void nave_abajo_2(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)206;
	cursor(x_nave - 1, y_nave); cout << (char)204;
	cursor(x_nave + 1, y_nave); cout << (char)185;
}
void nave_izquierda_2(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)206;
	cursor(x_nave, y_nave - 1); cout << (char)203;
	cursor(x_nave, y_nave + 1); cout << (char)202;
}
void nave_derecha_2(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)206;
	cursor(x_nave, y_nave - 1); cout << (char)203;
	cursor(x_nave, y_nave + 1); cout << (char)202;
}
void nave_arriba_3(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)157;
	cursor(x_nave - 1, y_nave); cout << (char)17;
	cursor(x_nave + 1, y_nave); cout << (char)16;
}
void nave_abajo_3(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)157;
	cursor(x_nave - 1, y_nave); cout << (char)17;
	cursor(x_nave + 1, y_nave); cout << (char)16;
}
void nave_izquierda_3(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)157;
	cursor(x_nave, y_nave - 1); cout << (char)30;
	cursor(x_nave, y_nave + 1); cout << (char)31;
}
void nave_derecha_3(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)157;
	cursor(x_nave, y_nave - 1); cout << (char)30;
	cursor(x_nave, y_nave + 1); cout << (char)31;
}
void nave_arriba_4(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)205;
	cursor(x_nave - 1, y_nave); cout << (char)204;
	cursor(x_nave + 1, y_nave); cout << (char)185;
}
void nave_abajo_4(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)205;
	cursor(x_nave - 1, y_nave); cout << (char)204;
	cursor(x_nave + 1, y_nave); cout << (char)185;
}
void nave_izquierda_4(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)186;
	cursor(x_nave, y_nave - 1); cout << (char)203;
	cursor(x_nave, y_nave + 1); cout << (char)202;
}
void nave_derecha_4(int x_nave, int y_nave)
{
	Color_nave(color_nave);

	cursor(x_nave, y_nave); cout << (char)186;
	cursor(x_nave, y_nave - 1); cout << (char)203;
	cursor(x_nave, y_nave + 1); cout << (char)202;
}
void elegir_nave_arriba(int tipo_nave, int x_nave, int y_nave)
{
	if (tipo_nave == 1)
	{
		nave_arriba_1(x_nave, y_nave);
	}
	if (tipo_nave == 2)
	{
		nave_arriba_2(x_nave, y_nave);
	}
	if (tipo_nave == 3)
	{
		nave_arriba_3(x_nave, y_nave);
	}
	if (tipo_nave == 4)
	{
		nave_arriba_4(x_nave, y_nave);
	}
}
void elegir_nave_abajo(int tipo_nave, int x_nave, int y_nave)
{
	if (tipo_nave == 1)
	{
		nave_abajo_1(x_nave, y_nave);
	}
	if (tipo_nave == 2)
	{
		nave_abajo_2(x_nave, y_nave);
	}
	if (tipo_nave == 3)
	{
		nave_abajo_3(x_nave, y_nave);
	}
	if (tipo_nave == 4)
	{
		nave_abajo_4(x_nave, y_nave);
	}
}
void elegir_nave_izquierda(int tipo_nave, int x_nave, int y_nave)
{
	if (tipo_nave == 1)
	{
		nave_izquierda_1(x_nave, y_nave);
	}
	if (tipo_nave == 2)
	{
		nave_izquierda_2(x_nave, y_nave);
	}
	if (tipo_nave == 3)
	{
		nave_izquierda_3(x_nave, y_nave);
	}
	if (tipo_nave == 4)
	{
		nave_izquierda_4(x_nave, y_nave);
	}
}
void elegir_nave_derecha(int tipo_nave, int x_nave, int y_nave)
{
	if (tipo_nave == 1)
	{
		nave_derecha_1(x_nave, y_nave);
	}
	if (tipo_nave == 2)
	{
		nave_derecha_2(x_nave, y_nave);
	}
	if (tipo_nave == 3)
	{
		nave_derecha_3(x_nave, y_nave);
	}
	if (tipo_nave == 4)
	{
		nave_derecha_4(x_nave, y_nave);
	}
}
void borrar_nave(int direccion, int x_nave, int y_nave)
{
	if (direccion == ARRIBA)
	{
		cursor(x_nave, y_nave); cout << " ";
		cursor(x_nave - 1, y_nave); cout << " ";
		cursor(x_nave + 1, y_nave); cout << " ";
	}
	if (direccion == ABAJO)
	{
		cursor(x_nave, y_nave); cout << " ";
		cursor(x_nave - 1, y_nave); cout << " ";
		cursor(x_nave + 1, y_nave); cout << " ";
	}
	if (direccion == IZQUIERDA)
	{
		cursor(x_nave, y_nave); cout << " ";
		cursor(x_nave, y_nave - 1); cout << " ";
		cursor(x_nave, y_nave + 1); cout << " ";
	}
	if (direccion == DERECHA)
	{
		cursor(x_nave, y_nave); cout << " ";
		cursor(x_nave, y_nave - 1); cout << " ";
		cursor(x_nave, y_nave + 1); cout << " ";
	}
}
void reaparecer(int &direccion, int &x_nave, int &y_nave,int x_centro,int y_centro)
{
	direccion = ARRIBA;
	x_nave = x_centro;
	y_nave = y_centro;

	cursor(x_nave, y_nave);
	elegir_nave_arriba(tipo_nave, x_nave, y_nave);
}

//GAMEOVER

void explosion_nave(int x, int y)
{
	int contador = 0;

	while (contador <= 9)
	{
		color_texto('yell');

		cursor(x, y - 1); cout << "*";
		cursor(x, y + 1); cout << "*";
		cursor(x - 1, y); cout << "*";
		cursor(x + 1, y); cout << "*";
		cursor(x + 1, y - 1); cout << " ";
		cursor(x + 1, y + 1); cout << " ";
		cursor(x - 1, y - 1); cout << " ";
		cursor(x - 1, y + 1); cout << " ";
		cursor(x, y); cout << " ";

		Sleep(100);

		color_texto('red');

		cursor(x + 1, y - 1); cout << "*";
		cursor(x + 1, y + 1); cout << "*";
		cursor(x - 1, y - 1); cout << "*";
		cursor(x - 1, y + 1); cout << "*";
		cursor(x, y); cout << "*";

		Sleep(100);

		contador++;
	}
}
void game_over()
{
	int perdiste[17][36] = 
	{
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 0, 0, 0, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	

	for (int f = 0; f < 17; f++)
	{
		cursor(XCUADRO, YCUADRO+f);
		for (int c = 0; c < 36; c++)
		{
			if (perdiste[f][c] == 0){ color_texto('blac'); cout << " "; }
			if (perdiste[f][c] == 1){ color_texto('gree'); cout << (char)201; }
			if (perdiste[f][c] == 2){ color_texto('gree'); cout << (char)205; }
			if (perdiste[f][c] == 3){ color_texto('gree'); cout << (char)187; }
			if (perdiste[f][c] == 4){ color_texto('gree'); cout << (char)186; }
			if (perdiste[f][c] == 5){ color_texto('gree'); cout << (char)200; }
			if (perdiste[f][c] == 6){ color_texto('gree'); cout << (char)188; }
			if (perdiste[f][c] == 7){ color_texto('blue'); cout << (char)219; }
		}
		if (f != 16){ cout << endl; }Sleep(350);
	}
}
void nivel_ganado()
{
	int ganaste[19][58] =
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0 },
		{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
		{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
		{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
		{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
		{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
		{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
		{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
		{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
		{ 0, 4, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 0, 0, 4, 0 },
		{ 0, 4, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 4, 0 },
		{ 0, 4, 0, 0, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 4, 0 },
		{ 0, 4, 0, 0, 7, 7, 0, 0, 0, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
		{ 0, 4, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 0, 0, 4, 0 },
		{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
		{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
		{ 0, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};



	for (int f = 0; f < 19; f++)
	{
		cursor(6,9 + f);
		for (int c = 0; c < 58; c++)
		{
			if (ganaste[f][c] == 0){ color_texto('blac'); cout << " "; }
			if (ganaste[f][c] == 1){ color_texto('gree'); cout << (char)201; }
			if (ganaste[f][c] == 2){ color_texto('gree'); cout << (char)205; }
			if (ganaste[f][c] == 3){ color_texto('gree'); cout << (char)187; }
			if (ganaste[f][c] == 4){ color_texto('gree'); cout << (char)186; }
			if (ganaste[f][c] == 5){ color_texto('gree'); cout << (char)200; }
			if (ganaste[f][c] == 6){ color_texto('gree'); cout << (char)188; }
			if (ganaste[f][c] == 7){ color_texto('yell'); cout << (char)219; }
		}
		if (f != 18){ cout << endl; }Sleep(350);
	}
}
void gracias()
{
	int gracias[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};


	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (gracias[f][c] == 0){ cout << " "; };
			if (gracias[f][c] == 1){ color_texto(color_borde); cout << (char)201; };
			if (gracias[f][c] == 2){ color_texto(color_borde); cout << (char)205; };
			if (gracias[f][c] == 3){ color_texto(color_borde); cout << (char)187; };
			if (gracias[f][c] == 4){ color_texto(color_borde); cout << (char)186; };
			if (gracias[f][c] == 5){ color_texto(color_borde); cout << (char)200; };
			if (gracias[f][c] == 6){ color_texto(color_borde); cout << (char)188; };
			if (gracias[f][c] == 7){ color_texto('yell'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}

	cursor(24, 29); color_texto('cyan'); cout << "PULSE ESC PARA SALIR...";
}
void espera()
{
	int regresar;
	while (1)
	{
		cursor(XCUADRO + 2, YCUADRO + 14); color_texto('whit');
		cout << "Pulsa el boton ESC para salir...";
		Sleep(700);

		cursor(XCUADRO + 2, YCUADRO + 14); color_texto('whit');
		cout << "                                 ";
		Sleep(700);

		if (kbhit())
		{
			regresar = getch();
			if (regresar == ESC){ break; }	
		}
	}
}

//CONTADORES

int vida = 3;
void vidas(int &vida, bool &gameover)
{
	cursor(55, 1); color_texto('cyan');
	cout << "VIDAS: ";
	if (vida >= 3)
		cout << (char)219 << " " << (char)219 << " " << (char)219;
	if (vida == 2)
		cout << (char)219 << " " << (char)219 << "  ";
	if (vida == 1)
		cout << (char)219 << "  " << "  ";
	if (vida == 0)
	{
		cout << "  " << "  " << "  ";
		gameover = true;
	}
}
void puntos(int puntaje)
{
	cursor(5, 1); color_texto('yell');
	cout << "PUNTOS: " << puntaje;	
}
void cofre(bool &mensaje,int mapa)
{
	mensaje = true;
	color_texto('gree');
	cursor(25, 1);
	cout << "COFRE! +"<<500*mapa<<" PUNTOS";
}
void corazones(bool &mensaje)
{
	mensaje = true;
	color_texto('red');
	cursor(25, 1);
	cout << "CORAZON! +1 VIDA";
}
void puntos_vidas(int puntaje, int &vida, bool &mensaje,int mapa)
{
	if (puntaje - bonus_vidas >= 0 && puntaje != 0)
	{
		if (vida < 3)
		{
			cursor(25, 1); cout << bonus_vidas << " PUNTOS! +1 VIDA             ";
			vida++;
			mensaje = true;
			bonus_vidas += 4000;
		}
		else
		{
			bonus_vidas += 4000;
		}
	}
}
void corazones_error(bool &mensaje)
{
	mensaje = true;
	color_texto('red');
	cursor(25, 1);
	cout << "VIDA AL MAXIMO :'(            ";
}
void borrar_aviso(bool &mensaje, int &contador)
{
	if (mensaje == true)
	{
		contador++;
		if (contador == 1500)
		{
			cursor(25, 1);
			cout << "                               ";
			contador = 0; mensaje = false;
		}
	}
}
void regenerar_punto(int x_bala, int y_bala,int n[FILAS][COLUMNAS],int suma)
{
	if (n[y_bala + suma][x_bala] == 7)
	{
		Color_mapa(color_puntos);
		cursor(x_bala, y_bala + suma); cout << (char)219;
	}
	if (n[y_bala + suma][x_bala] == 8)
	{
		Color_mapa(color_vida);
		cursor(x_bala, y_bala + suma); cout << (char)3;
	}
	if (n[y_bala + suma][x_bala] == 9)
	{
		Color_mapa(color_cofre);
		cursor(x_bala, y_bala + suma); cout << (char)220;
	}
	if (n[y_bala + suma][x_bala] == 13)
	{
		Color_mapa(color_borde);
		cursor(x_bala, y_bala + suma); cout << (char)177;
	}
}

//ENEMIGO

int color_enemigos = 1;
void bala(int x_bala, int y_bala)
{
	color_texto('red');

	cursor(x_bala, y_bala); cout << (char)15;
}
void borrar_bala(int x_bala, int y_bala)
{
	cursor(x_bala, y_bala); cout << " ";
}
void imprimir_enemigo_1(int x_enemigo1, int y_enemigo1)
{
	Color_enemigo(color_enemigos);

	cursor(x_enemigo1, y_enemigo1); cout << (char)219;
	cursor(x_enemigo1 - 1, y_enemigo1); cout << (char)17;
	cursor(x_enemigo1 + 1, y_enemigo1); cout << (char)16;
	cursor(x_enemigo1, y_enemigo1 + 1); cout << (char)31;
}
void imprimir_enemigo_2(int x_enemigo2, int y_enemigo2)
{
	Color_enemigo(color_enemigos);

	cursor(x_enemigo2, y_enemigo2); cout << (char)219;
	cursor(x_enemigo2 - 1, y_enemigo2); cout << (char)17;
	cursor(x_enemigo2 + 1, y_enemigo2); cout << (char)16;
	cursor(x_enemigo2, y_enemigo2 - 1); cout << (char)30;
}
void imprimir_enemigo_3(int x_enemigo1, int y_enemigo1)
{
	Color_enemigo(2);

	cursor(x_enemigo1, y_enemigo1); cout << (char)219;
	cursor(x_enemigo1 + 1, y_enemigo1); cout << (char)16;
	cursor(x_enemigo1, y_enemigo1 - 1); cout << (char)30;
	cursor(x_enemigo1, y_enemigo1 + 1); cout << (char)31;
}
void imprimir_enemigo_4(int x_enemigo2, int y_enemigo2)
{
	Color_enemigo(2);

	cursor(x_enemigo2, y_enemigo2); cout << (char)219;
	cursor(x_enemigo2 - 1, y_enemigo2); cout << (char)17;
	cursor(x_enemigo2, y_enemigo2 + 1); cout << (char)31;
	cursor(x_enemigo2, y_enemigo2 - 1); cout << (char)30;
}
void borrar_enemigo_1(int x_enemigo_1, int y_enemigo_1)
{
	cursor(x_enemigo_1, y_enemigo_1); cout << " ";
	cursor(x_enemigo_1 - 1, y_enemigo_1); cout << " ";
	cursor(x_enemigo_1 + 1, y_enemigo_1); cout << " ";
	cursor(x_enemigo_1, y_enemigo_1 + 1); cout << " ";
}
void borrar_enemigo_2(int x_enemigo_2, int y_enemigo_2)
{
	cursor(x_enemigo_2, y_enemigo_2); cout << " ";
	cursor(x_enemigo_2 - 1, y_enemigo_2); cout << " ";
	cursor(x_enemigo_2 + 1, y_enemigo_2); cout << " ";
	cursor(x_enemigo_2, y_enemigo_2 - 1); cout << " ";
}
void borrar_enemigo_3(int x_enemigo1, int y_enemigo1)
{
	cursor(x_enemigo1, y_enemigo1); cout << " ";
	cursor(x_enemigo1 + 1, y_enemigo1); cout << " ";
	cursor(x_enemigo1, y_enemigo1 - 1); cout << " ";
	cursor(x_enemigo1, y_enemigo1 + 1); cout << " ";
}
void borrar_enemigo_4(int x_enemigo2, int y_enemigo2)
{
	cursor(x_enemigo2, y_enemigo2); cout << " ";
	cursor(x_enemigo2 - 1, y_enemigo2); cout << " ";
	cursor(x_enemigo2, y_enemigo2 + 1); cout << " ";
	cursor(x_enemigo2, y_enemigo2 - 1); cout << " ";
}
void colision_bala(int &direccion, int x_bala, int y_bala, int &x_nave, int &y_nave,int x_centro,int y_centro, bool &disparar, bool &activador, int n[FILAS][COLUMNAS])
{
	if (direccion == ARRIBA)
	{
		if (x_nave == x_bala && y_nave == y_bala || x_nave + 1 == x_bala && y_nave == y_bala || x_nave - 1 == x_bala && y_nave == y_bala)
		{
			borrar_nave(direccion, x_nave, y_nave);
			vida--;
			disparar = false;
			activador = true;
			if (vida > 0)
			{
				regenerar_punto(x_nave, y_nave, n, 0);
				regenerar_punto(x_nave + 1, y_nave, n, 0);
				regenerar_punto(x_nave - 1, y_nave, n, 0);
				reaparecer(direccion, x_nave, y_nave,x_centro,y_centro);
			}
		}
	}
	if (direccion == ABAJO)
	{
		if (x_nave == x_bala && y_nave == y_bala || x_nave + 1 == x_bala && y_nave == y_bala || x_nave - 1 == x_bala && y_nave == y_bala)
		{
			borrar_nave(direccion, x_nave, y_nave);
			vida--;
			disparar = false;
			activador = true;
			if (vida > 0)
			{
				regenerar_punto(x_nave, y_nave, n, 0);
				regenerar_punto(x_nave + 1, y_nave, n, 0);
				regenerar_punto(x_nave - 1, y_nave, n, 0);
				reaparecer(direccion, x_nave, y_nave, x_centro, y_centro);
			}
		}
	}
	if (direccion == IZQUIERDA)
	{
		if (x_nave == x_bala&&y_nave == y_bala || x_nave == x_bala && y_nave + 1 == y_bala || x_nave == x_bala && y_nave - 1 == y_bala)
		{
			borrar_nave(direccion, x_nave, y_nave);
			vida--;
			disparar = false;
			activador = true;
			if (vida > 0)
			{
				regenerar_punto(x_nave, y_nave, n, 0);
				regenerar_punto(x_nave, y_nave + 1, n, 0);
				regenerar_punto(x_nave, y_nave - 1, n, 0);				
				reaparecer(direccion, x_nave, y_nave, x_centro, y_centro);
			}
		}
	}
	if (direccion == DERECHA)
	{
		if (x_nave == x_bala&&y_nave == y_bala || x_nave == x_bala && y_nave + 1 == y_bala || x_nave == x_bala && y_nave - 1 == y_bala)
		{
			borrar_nave(direccion, x_nave, y_nave);
			vida--;
			disparar = false;
			activador = true;
			if (vida > 0)
			{
				regenerar_punto(x_nave, y_nave, n, 0);
				regenerar_punto(x_nave, y_nave + 1, n, 0);
				regenerar_punto(x_nave, y_nave - 1, n, 0);
				reaparecer(direccion, x_nave, y_nave, x_centro, y_centro);
			}
		}
	}
}
void colision_enemigo1(int &direccion, int x_enemigo1, int y_enemigo1, int &x_nave, int &y_nave,int x_centro,int y_centro)
{
	if (direccion == ARRIBA)
	{
		if ((y_nave == y_enemigo1 || y_nave == y_enemigo1 + 1) && (x_nave == x_enemigo1 || x_nave == x_enemigo1 - 1 || 
			x_nave == x_enemigo1 + 1 || x_nave + 1 == x_enemigo1 || x_nave + 1 == x_enemigo1 + 1 || x_nave + 1 == x_enemigo1 - 1||
			x_nave - 1 == x_enemigo1 || x_nave - 1 == x_enemigo1 + 1 || x_nave - 1 == x_enemigo1 - 1))
		{
			borrar_nave(direccion, x_nave, y_nave);
			vida--;
			if (vida > 0)
			{
				reaparecer(direccion, x_nave, y_nave, x_centro, y_centro);
			}
		}
	}
	if (direccion == ABAJO)
	{
		if ((y_nave == y_enemigo1 || y_nave == y_enemigo1 + 1) && (x_nave == x_enemigo1 || x_nave == x_enemigo1 - 1 ||
			x_nave == x_enemigo1 + 1 || x_nave + 1 == x_enemigo1 || x_nave + 1 == x_enemigo1 + 1 || x_nave + 1 == x_enemigo1 - 1 ||
			x_nave - 1 == x_enemigo1 || x_nave - 1 == x_enemigo1 + 1 || x_nave - 1 == x_enemigo1 - 1))
		{
			borrar_nave(direccion, x_nave, y_nave);
			vida--;
			if (vida > 0)
			{
				reaparecer(direccion, x_nave, y_nave, x_centro, y_centro);
			}
		}
	}
	if (direccion == IZQUIERDA)
	{
		if ((x_nave == x_enemigo1 + 1 || x_nave == x_enemigo1 - 1 || x_nave == x_enemigo1) && (y_nave == y_enemigo1 ||
			y_nave == y_enemigo1 + 1  || y_nave + 1 == y_enemigo1 || y_nave + 1 == y_enemigo1 + 1 ||
			y_nave - 1 == y_enemigo1 || y_nave - 1 == y_enemigo1 + 1))
		{
			borrar_nave(direccion, x_nave, y_nave);
			vida--;
			if (vida > 0)
			{
				reaparecer(direccion, x_nave, y_nave, x_centro, y_centro);
			}
		}
	}
	if (direccion == DERECHA)
	{
		if ((x_nave == x_enemigo1 + 1 || x_nave == x_enemigo1 - 1 || x_nave == x_enemigo1) && (y_nave == y_enemigo1 ||
			y_nave == y_enemigo1 + 1 || y_nave + 1 == y_enemigo1 || y_nave + 1 == y_enemigo1 + 1 ||
			y_nave - 1 == y_enemigo1 || y_nave - 1 == y_enemigo1 + 1))
		{
			borrar_nave(direccion, x_nave, y_nave);
			vida--;
			if (vida > 0)
			{
				reaparecer(direccion, x_nave, y_nave, x_centro, y_centro);
			}
		}
	}
}
void colision_enemigo2(int &direccion, int x_enemigo2, int y_enemigo2, int &x_nave, int &y_nave, int x_centro,int y_centro)
{
	if (direccion == ARRIBA)
	{
		if ((y_nave == y_enemigo2 || y_nave == y_enemigo2 + 1) && (x_nave == x_enemigo2 || x_nave == x_enemigo2 - 1 ||
			x_nave == x_enemigo2 + 1 || x_nave + 1 == x_enemigo2 || x_nave + 1 == x_enemigo2 + 1 || x_nave + 1 == x_enemigo2 - 1 ||
			x_nave - 1 == x_enemigo2 || x_nave - 1 == x_enemigo2 + 1 || x_nave - 1 == x_enemigo2 - 1))
		{
			borrar_nave(direccion, x_nave, y_nave);
			vida--;
			if (vida > 0)
			{
				reaparecer(direccion, x_nave, y_nave, x_centro, y_centro);
			}
		}
	}
	if (direccion == ABAJO)
	{
		if ((y_nave == y_enemigo2 || y_nave == y_enemigo2 + 1) && (x_nave == x_enemigo2 || x_nave == x_enemigo2 - 1 ||
			x_nave == x_enemigo2 + 1 || x_nave + 1 == x_enemigo2 || x_nave + 1 == x_enemigo2 + 1 || x_nave + 1 == x_enemigo2 - 1 ||
			x_nave - 1 == x_enemigo2 || x_nave - 1 == x_enemigo2 + 1 || x_nave - 1 == x_enemigo2 - 1))
		{
			borrar_nave(direccion, x_nave, y_nave);
			vida--;
			if (vida > 0)
			{
				reaparecer(direccion, x_nave, y_nave, x_centro, y_centro);
			}
		}
	}
	if (direccion == IZQUIERDA)
	{
		if ((x_nave == x_enemigo2 + 1 || x_nave == x_enemigo2 - 1 || x_nave == x_enemigo2) && (y_nave == y_enemigo2 ||
			y_nave == y_enemigo2 - 1 || y_nave + 1 == y_enemigo2 || y_nave + 1 == y_enemigo2 - 1 || 
			y_nave - 1 == y_enemigo2 || y_nave - 1 == y_enemigo2 - 1))
		{
			borrar_nave(direccion, x_nave, y_nave);
			vida--;
			if (vida > 0)
			{
				reaparecer(direccion, x_nave, y_nave, x_centro, y_centro);
			}
		}
	}
	if (direccion == DERECHA)
	{
		if ((x_nave == x_enemigo2 + 1 || x_nave == x_enemigo2 - 1 || x_nave == x_enemigo2) && (y_nave == y_enemigo2 ||
			y_nave == y_enemigo2 - 1 || y_nave + 1 == y_enemigo2 || y_nave + 1 == y_enemigo2 - 1 ||
			y_nave - 1 == y_enemigo2 || y_nave - 1 == y_enemigo2 - 1))
		{
			borrar_nave(direccion, x_nave, y_nave);
			vida--;
			if (vida > 0)
			{
				reaparecer(direccion, x_nave, y_nave, x_centro, y_centro);
			}
		}
	}
}
void posicion_x_bala(int direccion, int &x_bala, int &y_bala, bool activador, int balas_enemigo, int x_nave)
{
	Random r;

	if (activador == true && balas_enemigo>0)
	{
		if (x_nave >= 4 && x_nave <= 24){ x_bala = r.Next(4, 25); }
		if (x_nave >= 25 && x_nave <= 46){ x_bala = r.Next(25, 47); }
		if (x_nave >= 47 && x_nave <= 66){ x_bala = r.Next(47, 67); }
		if (direccion == ARRIBA || direccion == ABAJO){ x_bala = x_nave; }
		y_bala = 0;
	}

}

//NIVELES

void presentacion_nivel_1()
{
	int presentacion_nivel1[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (presentacion_nivel1[f][c] == 0){ cout << " "; };
			if (presentacion_nivel1[f][c] == 1){ color_texto(color_borde); cout << (char)201; };
			if (presentacion_nivel1[f][c] == 2){ color_texto(color_borde); cout << (char)205; };
			if (presentacion_nivel1[f][c] == 3){ color_texto(color_borde); cout << (char)187; };
			if (presentacion_nivel1[f][c] == 4){ color_texto(color_borde); cout << (char)186; };
			if (presentacion_nivel1[f][c] == 5){ color_texto(color_borde); cout << (char)200; };
			if (presentacion_nivel1[f][c] == 6){ color_texto(color_borde); cout << (char)188; };
			if (presentacion_nivel1[f][c] == 7){ color_texto('blue'); cout << (char)219; };
			if (presentacion_nivel1[f][c] == 8){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void presentacion_nivel_2()
{
	int presentacion_nivel2[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (presentacion_nivel2[f][c] == 0){ cout << " "; };
			if (presentacion_nivel2[f][c] == 1){ color_texto(color_borde); cout << (char)201; };
			if (presentacion_nivel2[f][c] == 2){ color_texto(color_borde); cout << (char)205; };
			if (presentacion_nivel2[f][c] == 3){ color_texto(color_borde); cout << (char)187; };
			if (presentacion_nivel2[f][c] == 4){ color_texto(color_borde); cout << (char)186; };
			if (presentacion_nivel2[f][c] == 5){ color_texto(color_borde); cout << (char)200; };
			if (presentacion_nivel2[f][c] == 6){ color_texto(color_borde); cout << (char)188; };
			if (presentacion_nivel2[f][c] == 7){ color_texto('blue'); cout << (char)219; };
			if (presentacion_nivel2[f][c] == 8){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void presentacion_nivel_3()
{
	int presentacion_nivel3[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (presentacion_nivel3[f][c] == 0){ cout << " "; };
			if (presentacion_nivel3[f][c] == 1){ color_texto(color_borde); cout << (char)201; };
			if (presentacion_nivel3[f][c] == 2){ color_texto(color_borde); cout << (char)205; };
			if (presentacion_nivel3[f][c] == 3){ color_texto(color_borde); cout << (char)187; };
			if (presentacion_nivel3[f][c] == 4){ color_texto(color_borde); cout << (char)186; };
			if (presentacion_nivel3[f][c] == 5){ color_texto(color_borde); cout << (char)200; };
			if (presentacion_nivel3[f][c] == 6){ color_texto(color_borde); cout << (char)188; };
			if (presentacion_nivel3[f][c] == 7){ color_texto('blue'); cout << (char)219; };
			if (presentacion_nivel3[f][c] == 8){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void presentacion_nivel_4()
{
	int presentacion_nivel4[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (presentacion_nivel4[f][c] == 0){ cout << " "; };
			if (presentacion_nivel4[f][c] == 1){ color_texto(color_borde); cout << (char)201; };
			if (presentacion_nivel4[f][c] == 2){ color_texto(color_borde); cout << (char)205; };
			if (presentacion_nivel4[f][c] == 3){ color_texto(color_borde); cout << (char)187; };
			if (presentacion_nivel4[f][c] == 4){ color_texto(color_borde); cout << (char)186; };
			if (presentacion_nivel4[f][c] == 5){ color_texto(color_borde); cout << (char)200; };
			if (presentacion_nivel4[f][c] == 6){ color_texto(color_borde); cout << (char)188; };
			if (presentacion_nivel4[f][c] == 7){ color_texto('blue'); cout << (char)219; };
			if (presentacion_nivel4[f][c] == 8){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void presentacion_nivel_5()
{
	int presentacion_nivel5[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (presentacion_nivel5[f][c] == 0){ cout << " "; };
			if (presentacion_nivel5[f][c] == 1){ color_texto(color_borde); cout << (char)201; };
			if (presentacion_nivel5[f][c] == 2){ color_texto(color_borde); cout << (char)205; };
			if (presentacion_nivel5[f][c] == 3){ color_texto(color_borde); cout << (char)187; };
			if (presentacion_nivel5[f][c] == 4){ color_texto(color_borde); cout << (char)186; };
			if (presentacion_nivel5[f][c] == 5){ color_texto(color_borde); cout << (char)200; };
			if (presentacion_nivel5[f][c] == 6){ color_texto(color_borde); cout << (char)188; };
			if (presentacion_nivel5[f][c] == 7){ color_texto('blue'); cout << (char)219; };
			if (presentacion_nivel5[f][c] == 8){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void presentacion_nivel_6()
{
	int presentacion_nivel6[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (presentacion_nivel6[f][c] == 0){ cout << " "; };
			if (presentacion_nivel6[f][c] == 1){ color_texto(color_borde); cout << (char)201; };
			if (presentacion_nivel6[f][c] == 2){ color_texto(color_borde); cout << (char)205; };
			if (presentacion_nivel6[f][c] == 3){ color_texto(color_borde); cout << (char)187; };
			if (presentacion_nivel6[f][c] == 4){ color_texto(color_borde); cout << (char)186; };
			if (presentacion_nivel6[f][c] == 5){ color_texto(color_borde); cout << (char)200; };
			if (presentacion_nivel6[f][c] == 6){ color_texto(color_borde); cout << (char)188; };
			if (presentacion_nivel6[f][c] == 7){ color_texto('blue'); cout << (char)219; };
			if (presentacion_nivel6[f][c] == 8){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void presentacion_nivel_7()
{
	int presentacion_nivel7[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (presentacion_nivel7[f][c] == 0){ cout << " "; };
			if (presentacion_nivel7[f][c] == 1){ color_texto(color_borde); cout << (char)201; };
			if (presentacion_nivel7[f][c] == 2){ color_texto(color_borde); cout << (char)205; };
			if (presentacion_nivel7[f][c] == 3){ color_texto(color_borde); cout << (char)187; };
			if (presentacion_nivel7[f][c] == 4){ color_texto(color_borde); cout << (char)186; };
			if (presentacion_nivel7[f][c] == 5){ color_texto(color_borde); cout << (char)200; };
			if (presentacion_nivel7[f][c] == 6){ color_texto(color_borde); cout << (char)188; };
			if (presentacion_nivel7[f][c] == 7){ color_texto('blue'); cout << (char)219; };
			if (presentacion_nivel7[f][c] == 8){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void presentacion_nivel_8()
{
	int presentacion_nivel8[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (presentacion_nivel8[f][c] == 0){ cout << " "; };
			if (presentacion_nivel8[f][c] == 1){ color_texto(color_borde); cout << (char)201; };
			if (presentacion_nivel8[f][c] == 2){ color_texto(color_borde); cout << (char)205; };
			if (presentacion_nivel8[f][c] == 3){ color_texto(color_borde); cout << (char)187; };
			if (presentacion_nivel8[f][c] == 4){ color_texto(color_borde); cout << (char)186; };
			if (presentacion_nivel8[f][c] == 5){ color_texto(color_borde); cout << (char)200; };
			if (presentacion_nivel8[f][c] == 6){ color_texto(color_borde); cout << (char)188; };
			if (presentacion_nivel8[f][c] == 7){ color_texto('blue'); cout << (char)219; };
			if (presentacion_nivel8[f][c] == 8){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void presentacion_nivel_9()
{
	int presentacion_nivel9[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (presentacion_nivel9[f][c] == 0){ cout << " "; };
			if (presentacion_nivel9[f][c] == 1){ color_texto(color_borde); cout << (char)201; };
			if (presentacion_nivel9[f][c] == 2){ color_texto(color_borde); cout << (char)205; };
			if (presentacion_nivel9[f][c] == 3){ color_texto(color_borde); cout << (char)187; };
			if (presentacion_nivel9[f][c] == 4){ color_texto(color_borde); cout << (char)186; };
			if (presentacion_nivel9[f][c] == 5){ color_texto(color_borde); cout << (char)200; };
			if (presentacion_nivel9[f][c] == 6){ color_texto(color_borde); cout << (char)188; };
			if (presentacion_nivel9[f][c] == 7){ color_texto('blue'); cout << (char)219; };
			if (presentacion_nivel9[f][c] == 8){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void presentacion_nivel_10()
{
	int presentacion_nivel10[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (presentacion_nivel10[f][c] == 0){ cout << " "; };
			if (presentacion_nivel10[f][c] == 1){ color_texto('whit'); cout << (char)201; };
			if (presentacion_nivel10[f][c] == 2){ color_texto('whit'); cout << (char)205; };
			if (presentacion_nivel10[f][c] == 3){ color_texto('whit'); cout << (char)187; };
			if (presentacion_nivel10[f][c] == 4){ color_texto('whit'); cout << (char)186; };
			if (presentacion_nivel10[f][c] == 5){ color_texto('whit'); cout << (char)200; };
			if (presentacion_nivel10[f][c] == 6){ color_texto('whit'); cout << (char)188; };
			if (presentacion_nivel10[f][c] == 7){ color_texto('blue'); cout << (char)219; };
			if (presentacion_nivel10[f][c] == 8){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void vidas_restantes_3()
{
	int vidas_3[5][62] = {
		{ 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0},
	};

	for (int f = 0; f < 5; f++)
	{
		cursor(5, 19 + f);
		for (int c = 0; c < 62; c++)
		{
			if (vidas_3[f][c] == 0){ cout << " "; }
			if (vidas_3[f][c] == 7){ color_texto('cyan'); cout << (char)219; }
			if (vidas_3[f][c] == 8){ color_texto('cyan'); cout << (char)219; }
			if (vidas_3[f][c] == 9){ color_texto('dcya'); cout << (char)177; }
		}
		if (f != 4){ cout << endl; }
	}
}
void vidas_restantes_2()
{
	int vidas_2[5][62] = {
		{ 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0 },
	};

	for (int f = 0; f < 5; f++)
	{
		cursor(5, 19 + f);
		for (int c = 0; c < 62; c++)
		{
			if (vidas_2[f][c] == 0){ cout << " "; }
			if (vidas_2[f][c] == 7){ color_texto('cyan'); cout << (char)219; }
			if (vidas_2[f][c] == 8){ color_texto('cyan'); cout << (char)219; }
			if (vidas_2[f][c] == 9){ color_texto('dcya'); cout << (char)177; }
		}
		if (f != 4){ cout << endl; }
	}
}
void vidas_restantes_1()
{
	int vidas_1[5][62] = {
		{ 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 9, 9, 9, 9, 9, 9, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 9, 9, 9, 9, 9, 9, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 9, 9, 9, 9, 9, 9, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 9, 9, 9, 9, 9, 9, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 9, 9, 9, 9, 9, 9, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0 },
	};

	for (int f = 0; f < 5; f++)
	{
		cursor(5, 19 + f);
		for (int c = 0; c < 62; c++)
		{
			if (vidas_1[f][c] == 0){ cout << " "; }
			if (vidas_1[f][c] == 7){ color_texto('cyan'); cout << (char)219; }
			if (vidas_1[f][c] == 8){ color_texto('cyan'); cout << (char)219; }
			if (vidas_1[f][c] == 9){ color_texto('dcya'); cout << (char)177; }
		}
		if (f != 4){ cout << endl; }
	}
}
void imprime_vidas_restantes()
{
	if (vida == 3){ vidas_restantes_3(); }
	if (vida == 2){ vidas_restantes_2(); }
	if (vida == 1){ vidas_restantes_1(); }
}

int nivel_1[FILAS][COLUMNAS] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 8, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 9, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

int nivel_2[FILAS][COLUMNAS] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 7, 0, 0, 9, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 8, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

int nivel_3[FILAS][COLUMNAS] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 8, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 9, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

int nivel_4[FILAS][COLUMNAS] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

int nivel_5[FILAS][COLUMNAS] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 13, 0, 0, 9, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 7, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 8, 0, 0, 9, 0, 0, 13, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 13, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

int nivel_6[FILAS][COLUMNAS] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 9, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 8, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 13, 0, 0, 7, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 7, 0, 0, 13, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 15, 15, 15, 15, 15, 13, 0, 0, 7, 0, 0, 13, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 13, 0, 0, 9, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 13, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 15, 15, 15, 15, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

int nivel_7[FILAS][COLUMNAS] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 13, 0, 0, 0, 0, 7, 0, 0, 7, 0, 8, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 13, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 0, 0, 0, 0, 13, 0, 0, 9, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 0, 13, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 7, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 13, 13, 13, 13, 13, 13, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 9, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 7, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 7, 0, 0, 13, 13, 13, 13, 13, 13, 13, 0, 0, 7, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 7, 0, 0, 13, 13, 0, 0, 0, 0, 7, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 13, 0, 0, 0, 7, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 13, 13, 13, 13, 13, 13, 0, 0, 7, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 7, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

int nivel_8[FILAS][COLUMNAS] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 15, 15, 15, 15, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 7, 0, 7, 0, 0, 0, 13, 0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 13, 0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 13, 0, 0, 0, 0, 7, 0, 7, 0, 0, 0, 0, 13, 0, 0, 0, 0, 7, 0, 7, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 13, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 13, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 9, 0, 0, 13, 0, 0, 7, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 13, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 7, 0, 0, 13, 0, 0, 7, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 13, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 7, 0, 0, 13, 0, 0, 7, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 13, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 9, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 7, 0, 0, 13, 0, 0, 7, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 13, 0, 8, 0, 0, 0, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 13, 0, 0, 0, 7, 0, 7, 0, 0, 0, 0, 13, 0, 0, 0, 0, 7, 0, 7, 0, 0, 0, 0, 13, 0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 13, 0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 13, 0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 15, 15, 15, 15 , 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

int nivel_9[FILAS][COLUMNAS] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 4, 0 },
	{ 0, 4, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 15, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 15, 15, 15, 15, 15, 13, 0, 4, 0 },
	{ 0, 4, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 9, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 0, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 16, 16, 16, 16, 16, 13, 0, 0, 0, 0, 7, 0, 7, 0, 0, 0, 0, 13, 0, 0, 0, 0, 7, 0, 7, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 16, 16, 16, 16, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 9, 0, 0, 13, 15, 15, 15, 15, 15, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 13, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 15, 0, 13, 0, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 13, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 0, 0, 7, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 16, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 13, 0, 0, 8, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 4, 0 },
	{ 0, 4, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	{ 0, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

bool gameover = false;
void imprimir_pausa()
{
	int pausa[17][41] =
	{
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 4 },
		{ 4, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 4 },
		{ 4, 0, 7, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 7, 7, 0, 4 },
		{ 4, 0, 7, 7, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 4 },
		{ 4, 0, 7, 7, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	for (int f = 0; f < 17; f++)
	{
		cursor(XCUADRO-3, YCUADRO + f);
		for (int c = 0; c < 41; c++)
		{
			if (pausa[f][c] == 0){ color_texto('blac'); cout << " "; }
			if (pausa[f][c] == 1){ color_texto('blue'); cout << (char)201; }
			if (pausa[f][c] == 2){ color_texto('blue'); cout << (char)205; }
			if (pausa[f][c] == 3){ color_texto('blue'); cout << (char)187; }
			if (pausa[f][c] == 4){ color_texto('blue'); cout << (char)186; }
			if (pausa[f][c] == 5){ color_texto('blue'); cout << (char)200; }
			if (pausa[f][c] == 6){ color_texto('blue'); cout << (char)188; }
			if (pausa[f][c] == 7){ color_texto('yell'); cout << (char)219; }
		}
		if (f != 16){ cout << endl; }
	}
	cursor(30, 20); color_texto('whit'); cout << "REANUDAR :)";
	cursor(31, 23); color_texto('whit'); cout << "SALIR :'(";
}
void borrar_pausa()
{
	for (int f = 0; f < 17; f++)
	{
		cursor(XCUADRO - 3, YCUADRO + f);
		for (int c = 0; c < 41; c++)
		{
			color_texto('blac'); cout << " ";
		}
		if (f != 16){ cout << endl; }
	}
}
void disparar_pausa(int y_bala, int &x_bala, int &dx_bala, int incremento, int limite, bool &activador, bool &disparar)
{

	if (activador == true)
	{
		activador = false;
		x_bala = 35 + incremento;
		bala(x_bala, y_bala);
		disparar = true;
	}

	if (disparar == true)
	{
		borrar_bala(x_bala, y_bala);
		x_bala += dx_bala;
		bala(x_bala, y_bala);

		if (x_bala == limite)
		{
			borrar_bala(x_bala, y_bala);
			disparar = false;
			activador = true;
		}
	}
}
void desplazamiento_pausa(int &y)
{
	int x_1 = 20, x_2 = 50, contador1,contador2, x_bala1 = 22, x_bala2 = 48;
	int dx_1 = 1, dx_2 = -1;
	bool activador_1 = true, disparar_1 = false, activador_2 = true, disparar_2 = false;
	y = 20;
	
	imprimir_enemigo_3(x_1, y);
	imprimir_enemigo_4(x_2, y);

	while (1)
	{
		if (contador1 == 2000)
		{
			disparar_pausa(y, x_bala2, dx_2, 13, 41, activador_2, disparar_2);
			contador1 = 0;
		}
		if (contador2 == 2000)
		{
			disparar_pausa(y, x_bala1, dx_1, -13, 29, activador_1, disparar_1);
			contador2 = 0;
		}

		if (kbhit())
		{
			int tecla = _getch();

			if (tecla == ABAJO && y < 23)
			{
				borrar_bala(x_bala1, y);
				borrar_bala(x_bala2, y);
				borrar_enemigo_3(x_1, y);
				borrar_enemigo_4(x_2, y);
				y += 3;
				imprimir_enemigo_3(x_1, y);
				imprimir_enemigo_4(x_2, y);
			}
			else
			{
				if (tecla == ABAJO)
				{
					borrar_bala(x_bala1, y);
					borrar_bala(x_bala2, y);
					borrar_enemigo_3(x_1, y);
					borrar_enemigo_4(x_2, y);
					y = 20;
					imprimir_enemigo_3(x_1, y);
					imprimir_enemigo_4(x_2, y);
				}
			}

			if (tecla == ARRIBA && y > 20)
			{
				borrar_bala(x_bala1, y);
				borrar_bala(x_bala2, y);
				borrar_enemigo_3(x_1, y);
				borrar_enemigo_4(x_2, y);
				y -= 3;
				imprimir_enemigo_3(x_1, y);
				imprimir_enemigo_4(x_2, y);
			}
			else
			{
				if (tecla == ARRIBA)
				{
					borrar_bala(x_bala1, y);
					borrar_bala(x_bala2, y);
					borrar_enemigo_3(x_1, y);
					borrar_enemigo_4(x_2, y);
					y = 23;
					imprimir_enemigo_3(x_1, y);
					imprimir_enemigo_4(x_2, y);
				}
			}

			if (tecla == 13)
			{
				break;
			}
		}
		contador1++;
		contador2++;
	}
}
void imprimir_nivel(int n[FILAS][COLUMNAS])
{
	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (n[f][c] == 0){cout << " "; }
			if (n[f][c] == 1){ Color_mapa(color_borde); cout << (char)201; }
			if (n[f][c] == 2){ Color_mapa(color_borde); cout << (char)205; }
			if (n[f][c] == 3){ Color_mapa(color_borde); cout << (char)187; }
			if (n[f][c] == 4){ Color_mapa(color_borde); cout << (char)186; }
			if (n[f][c] == 5){ Color_mapa(color_borde); cout << (char)200; }
			if (n[f][c] == 6){ Color_mapa(color_borde); cout << (char)188; }
			if (n[f][c] == 7){ Color_mapa(color_puntos); cout << (char)219; }
			if (n[f][c] == 8){ Color_mapa(color_vida); cout << (char)3; }
			if (n[f][c] == 9){ Color_mapa(color_cofre); cout << (char)220; }
			if (n[f][c] == 13){ Color_mapa(color_borde); cout << (char)177; }
			if (n[f][c] == 10){ cout << " "; }
			if (n[f][c] == 11){ cout << " "; }
			if (n[f][c] == 12){ cout << " "; }
			if (n[f][c] == 15 || n[f][c] == 16){ cout << " "; }
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void regenerar_nivel(int n[FILAS][COLUMNAS])
{
	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (n[f][c] == 10)
			{
				n[f][c] = 7;
			}
			if (n[f][c] == 11)
			{
				n[f][c] = 9;
			}
			if (n[f][c] == 12)
			{
				n[f][c] = 8;
			}
			if (n[f][c] == 14)
			{
				n[f][c] = 13;
			}
		}
	}
	bonus_vidas = 4000;
}
void recoge_puntos(int direccion, int &puntaje,bool &mensaje,int &x_nave,int &y_nave, int nivel[FILAS][COLUMNAS],int mapa)
{
	if (direccion == ARRIBA)
	{
		if (nivel[y_nave][x_nave] == 7)
		{
			puntaje += 15;
			puntos(puntaje);
			puntos_vidas(puntaje, vida, mensaje,mapa);
			nivel[y_nave][x_nave] = 10;
		}
		if (nivel[y_nave][x_nave - 1] == 7)
		{
			puntaje += 15;
			puntos(puntaje);
			puntos_vidas(puntaje, vida, mensaje, mapa);
			nivel[y_nave][x_nave - 1] = 10;
		}
		if (nivel[y_nave][x_nave + 1] == 7)
		{
			puntaje += 15;
			puntos(puntaje);
			puntos_vidas(puntaje, vida, mensaje, mapa);
			nivel[y_nave][x_nave + 1] = 10;
		}
	}

	if (direccion == ABAJO)
	{
		if (nivel[y_nave][x_nave] == 7)
		{
			puntaje += 15;
			puntos(puntaje);
			puntos_vidas(puntaje, vida, mensaje, mapa);
			nivel[y_nave][x_nave] = 10;
		}
		if (nivel[y_nave][x_nave - 1] == 7)
		{
			puntaje += 15;
			puntos(puntaje);
			puntos_vidas(puntaje, vida, mensaje, mapa);
			nivel[y_nave][x_nave - 1] = 10;
		}
		if (nivel[y_nave][x_nave + 1] == 7)
		{
			puntaje += 15;
			puntos(puntaje);
			puntos_vidas(puntaje, vida, mensaje, mapa);
			nivel[y_nave][x_nave + 1] = 10;
		}
	}

	if (direccion == IZQUIERDA)
	{
		if (nivel[y_nave][x_nave] == 7)
		{
			puntaje += 15;
			puntos(puntaje);
			puntos_vidas(puntaje, vida, mensaje, mapa);
			nivel[y_nave][x_nave] = 10;
		}
		if (nivel[y_nave - 1][x_nave] == 7)
		{
			puntaje += 15;
			puntos(puntaje);
			puntos_vidas(puntaje, vida, mensaje, mapa);
			nivel[y_nave - 1][x_nave] = 10;
		}
		if (nivel[y_nave + 1][x_nave] == 7)
		{
			puntaje += 15;
			puntos(puntaje);
			puntos_vidas(puntaje, vida, mensaje, mapa);
			nivel[y_nave + 1][x_nave] = 10;
		}
	}

	if (direccion == DERECHA)
	{
		if (nivel[y_nave][x_nave] == 7)
		{
			puntaje += 15;
			puntos(puntaje);
			puntos_vidas(puntaje, vida, mensaje, mapa);
			nivel[y_nave][x_nave] = 10;
		}
		if (nivel[y_nave - 1][x_nave] == 7)
		{
			puntaje += 15;
			puntos(puntaje);
			puntos_vidas(puntaje, vida, mensaje, mapa);
			nivel[y_nave - 1][x_nave] = 10;
		}
		if (nivel[y_nave + 1][x_nave] == 7)
		{
			puntaje += 15;
			puntos(puntaje);
			puntos_vidas(puntaje, vida, mensaje, mapa);
			nivel[y_nave + 1][x_nave] = 10;
		}
	}
}
void recoge_cofres(int direccion, int &puntaje, bool &mensaje, int &x_nave, int &y_nave,int nivel[FILAS][COLUMNAS],int mapa)
{
	if (direccion == ARRIBA)
	{
		if (nivel[y_nave][x_nave] == 9)
		{
			puntaje += 500*mapa;
			puntos(puntaje);
			cofre(mensaje, mapa);
			nivel[y_nave][x_nave] = 11;
		}
		if (nivel[y_nave][x_nave - 1] == 9)
		{
			puntaje += 500 * mapa;
			puntos(puntaje);
			cofre(mensaje, mapa);
			nivel[y_nave][x_nave - 1] = 11;
		}
		if (nivel[y_nave][x_nave + 1] == 9)
		{
			puntaje += 500 * mapa;
			puntos(puntaje);
			cofre(mensaje, mapa);
			nivel[y_nave][x_nave + 1] = 11;
		}
	}

	if (direccion == ABAJO)
	{
		if (nivel[y_nave][x_nave] == 9)
		{
			puntaje += 500 * mapa;
			puntos(puntaje);
			cofre(mensaje, mapa);
			nivel[y_nave][x_nave] = 11;
		}
		if (nivel[y_nave][x_nave - 1] == 9)
		{
			puntaje += 500 * mapa;
			puntos(puntaje);
			cofre(mensaje, mapa);
			nivel[y_nave][x_nave - 1] = 11;
		}
		if (nivel[y_nave][x_nave + 1] == 9)
		{
			puntaje += 500 * mapa;
			puntos(puntaje);
			cofre(mensaje, mapa);
			nivel[y_nave][x_nave + 1] = 11;
		}
	}

	if (direccion == IZQUIERDA)
	{
		if (nivel[y_nave][x_nave] == 9)
		{
			puntaje += 500 * mapa;
			puntos(puntaje);
			cofre(mensaje, mapa);
			nivel[y_nave][x_nave] = 11;
		}
		if (nivel[y_nave - 1][x_nave] == 9)
		{
			puntaje += 500 * mapa;
			puntos(puntaje);
			cofre(mensaje, mapa);
			nivel[y_nave - 1][x_nave] = 11;
		}
		if (nivel[y_nave + 1][x_nave] == 9)
		{
			puntaje += 500 * mapa;
			puntos(puntaje);
			cofre(mensaje, mapa);
			nivel[y_nave + 1][x_nave] = 11;
		}
	}

	if (direccion == DERECHA)
	{
		if (nivel[y_nave][x_nave] == 9)
		{
			puntaje += 500 * mapa;
			puntos(puntaje);
			cofre(mensaje, mapa);
			nivel[y_nave][x_nave] = 11;
		}
		if (nivel[y_nave - 1][x_nave] == 9)
		{
			puntaje += 500 * mapa;
			puntos(puntaje);
			cofre(mensaje, mapa);
			nivel[y_nave - 1][x_nave] = 11;
		}
		if (nivel[y_nave + 1][x_nave] == 9)
		{
			puntaje += 500 * mapa;
			puntos(puntaje);
			cofre(mensaje, mapa);
			nivel[y_nave + 1][x_nave] = 11;
		}
	}
}
void recoge_vidas(int direccion, int &puntaje, bool &mensaje, int &x_nave, int &y_nave,int nivel[FILAS][COLUMNAS])
{
	if (direccion == ARRIBA)
	{
		if (nivel[y_nave][x_nave] == 8)
		{
			if (vida < 3)
			{
				vida++;
				corazones(mensaje);
				nivel[y_nave][x_nave] = 12;
			}
			else { corazones_error(mensaje); nivel[y_nave][x_nave] = 12; }
		}
		if (nivel[y_nave][x_nave - 1] == 8)
		{
			if (vida < 3)
			{
				vida++;
				corazones(mensaje);
				nivel[y_nave][x_nave - 1] = 12;
			}
			else { corazones_error(mensaje); nivel[y_nave][x_nave - 1] = 12; }
		}
		if (nivel[y_nave][x_nave + 1] == 8)
		{
			if (vida < 3)
			{
				vida++;
				corazones(mensaje);
				nivel[y_nave][x_nave + 1] = 12;
			}
			else { corazones_error(mensaje); nivel[y_nave][x_nave + 1] = 12; }
		}
	}

	if (direccion == ABAJO)
	{
		if (nivel[y_nave][x_nave] == 8)
		{
			if (vida < 3)
			{
				vida++;
				corazones(mensaje);
				nivel[y_nave][x_nave] = 12;
			}
			else { corazones_error(mensaje); nivel[y_nave][x_nave] = 12; }
		}
		if (nivel[y_nave][x_nave - 1] == 8)
		{
			if (vida < 3)
			{
				vida++;
				corazones(mensaje);
				nivel[y_nave][x_nave - 1] = 12;
			}
			else { corazones_error(mensaje); nivel[y_nave][x_nave - 1] = 12; }
		}
		if (nivel[y_nave][x_nave + 1] == 8)
		{
			if (vida < 3)
			{
				vida++;
				corazones(mensaje);
				nivel[y_nave][x_nave + 1] = 12;
			}
			else { corazones_error(mensaje); nivel[y_nave][x_nave + 1] = 12; }
		}
	}

	if (direccion == IZQUIERDA)
	{
		if (nivel[y_nave][x_nave] == 8)
		{
			if (vida < 3)
			{
				vida++;
				corazones(mensaje);
				nivel[y_nave][x_nave] = 12;
			}
			else { corazones_error(mensaje); nivel[y_nave][x_nave] = 12; }
		}
		if (nivel[y_nave - 1][x_nave] == 8)
		{
			if (vida < 3)
			{
				vida++;
				corazones(mensaje);
				nivel[y_nave - 1][x_nave] = 12;
			}
			else { corazones_error(mensaje); nivel[y_nave - 1][x_nave] = 12; }
		}
		if (nivel[y_nave + 1][x_nave] == 8)
		{
			if (vida < 3)
			{
				vida++;
				corazones(mensaje);
				nivel[y_nave + 1][x_nave] = 12;
			}
			else { corazones_error(mensaje); nivel[y_nave + 1][x_nave] = 12; }
		}
	}

	if (direccion == DERECHA)
	{
		if (nivel[y_nave][x_nave] == 8)
		{
			if (vida < 3)
			{
				vida++;
				corazones(mensaje);
				nivel[y_nave][x_nave] = 12;
			}
			else { corazones_error(mensaje);  nivel[y_nave][x_nave] = 12; }
		}
		if (nivel[y_nave - 1][x_nave] == 8)
		{
			if (vida < 3)
			{
				vida++;
				corazones(mensaje);
				nivel[y_nave - 1][x_nave] = 12;
			}
			else { corazones_error(mensaje); nivel[y_nave - 1][x_nave] = 12; }
		}
		if (nivel[y_nave + 1][x_nave] == 8)
		{
			if (vida < 3)
			{
				vida++;
				corazones(mensaje);
				nivel[y_nave + 1][x_nave] = 12;
			}
			else { corazones_error(mensaje); nivel[y_nave + 1][x_nave] = 12; }
		}
	}
}
void jugar_nivel_1()
{
	Random r;
	int x_nave = XCENTRO, y_nave = YCENTRO, direccion = ARRIBA, mapa = 1, x_centro = XCENTRO, y_centro = YCENTRO;
	bool mensaje = false, disparar_1 = false, activador_1 = true;
	bool disparar_2 = false, activador_2 = true;
	int puntaje = 0, contador_aviso = 0;
	int x_enemigo1 = 35, y_enemigo1 = YENEMIGO1, contador_enemigo1 = 0, dx_enemigo1 = 1, balas_enemigo_1 = 12;
	int x_enemigo2 = 35, y_enemigo2 = YENEMIGO2, contador_enemigo2 = 0, dx_enemigo2 = -1, balas_enemigo_2 = 12;;
	int x_bala_1, y_bala_1, x_bala_2, y_bala_2;
	
	color_enemigos = 1;
	x_bala_1 = r.Next(5, 66);
	x_bala_2 = r.Next(5, 66);

	if (musica == true){ musica_nivel1(); }
	presentacion_nivel_1();
	imprime_vidas_restantes();
	segundos(4);
	Console::Clear();

	imprimir_nivel(nivel_1);
	puntos(puntaje);

	elegir_nave_arriba(tipo_nave, x_nave, y_nave);
	imprimir_enemigo_1(x_enemigo1, y_enemigo1);
	imprimir_enemigo_2(x_enemigo2, y_enemigo2);

	while (1)
	{
		if (puntaje == 2600)
		{
			if (musica == true){ ganaste_sound(); }
			nivel_ganado(); segundos(6);
			regenerar_nivel(nivel_1);
			detener_musica();
			break;
		}
		borrar_aviso(mensaje, contador_aviso);
		vidas(vida, gameover);

		//Enemigo 1
		if (contador_enemigo1 == 90)
		{
			if (x_enemigo1 == 66 || x_enemigo1 == 3){dx_enemigo1 *= -1;}

			borrar_enemigo_1(x_enemigo1, y_enemigo1);
			x_enemigo1 += dx_enemigo1;
			imprimir_enemigo_1(x_enemigo1, y_enemigo1);
			contador_enemigo1 = 0;

			if (x_bala_1 == x_enemigo1 && activador_1 == true)
			{
				activador_1 = false;
				y_bala_1 = y_enemigo1 + 2;
				bala(x_bala_1, y_bala_1);
				disparar_1 = true;
				balas_enemigo_1--;
			}

			if (disparar_1 == true)
			{
				borrar_bala(x_bala_1, y_bala_1);
				y_bala_1++;
				bala(x_bala_1, y_bala_1);
				regenerar_punto(x_bala_1, y_bala_1, nivel_1, -1);
				colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_1);

				if (y_bala_1 == 31)
				{
					borrar_bala(x_bala_1, y_bala_1);
					disparar_1 = false;
					activador_1 = true;
				}
			}
		}

		colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);

		//Enemigo 2
		if (contador_enemigo2 == 90)
		{
			if (x_enemigo2 == 66 || x_enemigo2 == 3){ dx_enemigo2 *= -1; }

			borrar_enemigo_2(x_enemigo2, y_enemigo2);
			x_enemigo2 += dx_enemigo2;
			imprimir_enemigo_2(x_enemigo2, y_enemigo2);
			contador_enemigo2 = 0;

			if (x_bala_2 == x_enemigo2 && activador_2 == true)
			{
				activador_2 = false;
				y_bala_2 = y_enemigo2 - 2;
				bala(x_bala_2, y_bala_2);
				disparar_2 = true;
				balas_enemigo_2--;
			}

			if (disparar_2 == true)
			{
				borrar_bala(x_bala_2, y_bala_2);
				y_bala_2--;
				bala(x_bala_2, y_bala_2);
				regenerar_punto(x_bala_2, y_bala_2, nivel_1, 1);
				colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_1);

				if (y_bala_2 == 6)
				{
					borrar_bala(x_bala_2, y_bala_2);
					disparar_2 = false;
					activador_2 = true;
				}
			}
		}

		colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);

		//GAMEOVER
		if (gameover == true)
		{
			if (musica == true){ game_over_sound(); }
			explosion_nave(x_nave, y_nave);
			game_over();
			espera();
			vida = 3;
			regenerar_nivel(nivel_1);
			if (musica == true){ musica_menu(); }
			break;
		}
	
		//Movimiento nave
		if (kbhit())
		{
			int  tecla = getch();

			if (tecla == ARRIBA && nivel_1[y_nave - 2][x_nave] != 2)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave--;
				elegir_nave_arriba(tipo_nave, x_nave, y_nave);
				direccion = ARRIBA;
			}
			if (tecla == ABAJO && nivel_1[y_nave + 2][x_nave] != 2)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave++;
				elegir_nave_abajo(tipo_nave, x_nave, y_nave);
				direccion = ABAJO;
			}
			if (tecla == IZQUIERDA && nivel_1[y_nave][x_nave - 2] != 4)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave--;
				elegir_nave_izquierda(tipo_nave, x_nave, y_nave);
				direccion = IZQUIERDA;
			}
			if (tecla == DERECHA && nivel_1[y_nave][x_nave + 2] != 4)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave++;
				elegir_nave_derecha(tipo_nave, x_nave, y_nave);
				direccion = DERECHA;
			}
			if (tecla == 'p')
			{
				int temp = 0;
				imprimir_pausa();
				desplazamiento_pausa(temp);
				{
					if (temp == 20)
					{ Console::Clear(); 
					  imprimir_nivel(nivel_1); 
					  if (direccion == ARRIBA){ elegir_nave_arriba(tipo_nave, x_nave, y_nave); }
					  if (direccion == ABAJO){ elegir_nave_abajo(tipo_nave, x_nave, y_nave); }
					  if (direccion == IZQUIERDA){ elegir_nave_izquierda(tipo_nave, x_nave, y_nave); }
					  if (direccion == DERECHA){ elegir_nave_derecha(tipo_nave, x_nave, y_nave); }
					  continue; 
					}
					if (temp == 23)
					{ regenerar_nivel(nivel_1); 
					  gameover = true; 
					  if (musica == true){ musica_menu(); }
					  break;
					}
				}
			}
			colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_1);
			colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_1);
			colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);
			colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);
		}

		// Posicion balas

		posicion_x_bala(direccion, x_bala_1, y_bala_1, activador_1, balas_enemigo_1, x_nave);
		posicion_x_bala(direccion, x_bala_2, y_bala_2, activador_2, balas_enemigo_2, x_nave);

		//Recoger objetos
		recoge_cofres(direccion, puntaje, mensaje, x_nave, y_nave, nivel_1,mapa);
		recoge_puntos(direccion, puntaje, mensaje, x_nave, y_nave,nivel_1,mapa);
		recoge_vidas(direccion, puntaje, mensaje, x_nave, y_nave, nivel_1);
		
		//Contadores
		contador_enemigo1++;
		contador_enemigo2++;

	}//fin while
}
void jugar_nivel_2()
{
	Random r;
	int x_nave = XCENTRO, y_nave = YCENTRO, direccion = ARRIBA, mapa = 2, x_centro = XCENTRO, y_centro = YCENTRO;
	bool mensaje = false, disparar_1 = false, activador_1 = true;
	bool disparar_2 = false, activador_2 = true;
	int puntaje = 0, contador_aviso = 0;
	int x_enemigo1 = 35, y_enemigo1 = YENEMIGO1, contador_enemigo1 = 0, dx_enemigo1 = 1, balas_enemigo_1 = 12;
	int x_enemigo2 = 35, y_enemigo2 = YENEMIGO2, contador_enemigo2 = 0, dx_enemigo2 = -1, balas_enemigo_2 = 12;;
	int x_bala_1, y_bala_1, x_bala_2, y_bala_2;

	color_enemigos = 2;
	x_bala_1 = r.Next(5, 66);
	x_bala_2 = r.Next(5, 66);

	if (musica == true){ musica_nivel1(); }
	presentacion_nivel_2();
	imprime_vidas_restantes();
	segundos(4);
	Console::Clear();

	imprimir_nivel(nivel_2);
	puntos(puntaje);

	elegir_nave_arriba(tipo_nave, x_nave, y_nave);
	imprimir_enemigo_1(x_enemigo1, y_enemigo1);
	imprimir_enemigo_2(x_enemigo2, y_enemigo2);

	while (1)
	{
		if (puntaje == 2740)
		{
			if (musica == true){ ganaste_sound(); }
			nivel_ganado(); segundos(6);
			regenerar_nivel(nivel_2);
			detener_musica();
			break; 
		}
		borrar_aviso(mensaje, contador_aviso);
		vidas(vida, gameover);

		//Enemigo 1
		if (contador_enemigo1 == 90)
		{
			if (x_enemigo1 == 66 || x_enemigo1 == 3){ dx_enemigo1 *= -1; }

			borrar_enemigo_1(x_enemigo1, y_enemigo1);
			x_enemigo1 += dx_enemigo1;
			imprimir_enemigo_1(x_enemigo1, y_enemigo1);
			contador_enemigo1 = 0;

			if (x_bala_1 == x_enemigo1 && activador_1 == true)
			{
				activador_1 = false;
				y_bala_1 = y_enemigo1 + 2;
				bala(x_bala_1, y_bala_1);
				disparar_1 = true;
				balas_enemigo_1--;
			}

			if (disparar_1 == true)
			{
				borrar_bala(x_bala_1, y_bala_1);
				y_bala_1++;
				bala(x_bala_1, y_bala_1);
				regenerar_punto(x_bala_1, y_bala_1, nivel_2, -1);
				colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_2);

				if (y_bala_1 == 31)
				{
					borrar_bala(x_bala_1, y_bala_1);
					disparar_1 = false;
					activador_1 = true;
				}
			}
		}

		colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);

		//Enemigo 2
		if (contador_enemigo2 == 90)
		{
			if (x_enemigo2 == 66 || x_enemigo2 == 3){ dx_enemigo2 *= -1; }

			borrar_enemigo_2(x_enemigo2, y_enemigo2);
			x_enemigo2 += dx_enemigo2;
			imprimir_enemigo_2(x_enemigo2, y_enemigo2);
			contador_enemigo2 = 0;

			if (x_bala_2 == x_enemigo2 && activador_2 == true)
			{
				activador_2 = false;
				y_bala_2 = y_enemigo2 - 2;
				bala(x_bala_2, y_bala_2);
				disparar_2 = true;
				balas_enemigo_2--;
			}

			if (disparar_2 == true)
			{
				borrar_bala(x_bala_2, y_bala_2);
				y_bala_2--;
				bala(x_bala_2, y_bala_2);
				regenerar_punto(x_bala_2, y_bala_2, nivel_2, 1);
				colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_2);

				if (y_bala_2 == 6)
				{
					borrar_bala(x_bala_2, y_bala_2);
					disparar_2 = false;
					activador_2 = true;
				}
			}
		}

		colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);

		//GAMEOVER
		if (gameover == true)
		{
			if (musica == true){ game_over_sound(); }
			explosion_nave(x_nave, y_nave);
			game_over();
			espera();
			vida = 3;
			regenerar_nivel(nivel_2);			
			if (musica == true){ musica_menu(); }
			break;
		}

		//Movimiento nave
		if (kbhit())
		{
			int  tecla = getch();

			if (tecla == ARRIBA && nivel_2[y_nave - 2][x_nave] != 2)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave--;
				elegir_nave_arriba(tipo_nave, x_nave, y_nave);
				direccion = ARRIBA;
			}
			if (tecla == ABAJO && nivel_2[y_nave + 2][x_nave] != 2)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave++;
				elegir_nave_abajo(tipo_nave, x_nave, y_nave);
				direccion = ABAJO;
			}
			if (tecla == IZQUIERDA && nivel_2[y_nave][x_nave - 2] != 4)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave--;
				elegir_nave_izquierda(tipo_nave, x_nave, y_nave);
				direccion = IZQUIERDA;
			}
			if (tecla == DERECHA && nivel_2[y_nave][x_nave + 2] != 4)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave++;
				elegir_nave_derecha(tipo_nave, x_nave, y_nave);
				direccion = DERECHA;
			}
			if (tecla == 'p')
			{
				int temp = 0;
				imprimir_pausa();
				desplazamiento_pausa(temp);
				{
					if (temp == 20)
					{
						Console::Clear();
						imprimir_nivel(nivel_2);
						if (direccion == ARRIBA){ elegir_nave_arriba(tipo_nave, x_nave, y_nave); }
						if (direccion == ABAJO){ elegir_nave_abajo(tipo_nave, x_nave, y_nave); }
						if (direccion == IZQUIERDA){ elegir_nave_izquierda(tipo_nave, x_nave, y_nave); }
						if (direccion == DERECHA){ elegir_nave_derecha(tipo_nave, x_nave, y_nave); }
						continue;
					}
					if (temp == 23)
					{ 
						regenerar_nivel(nivel_2); 
						gameover = true; 			
						if (musica == true){ musica_menu(); }
						break;
					}
				}
			}
			colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_2);
			colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_2);
			colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);
			colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);
		}

		// Posicion balas

		posicion_x_bala(direccion, x_bala_1, y_bala_1, activador_1, balas_enemigo_1, x_nave);
		posicion_x_bala(direccion, x_bala_2, y_bala_2, activador_2, balas_enemigo_2, x_nave);

		//Recoger objetos
		recoge_cofres(direccion, puntaje, mensaje, x_nave, y_nave, nivel_2,mapa);
		recoge_puntos(direccion, puntaje, mensaje, x_nave, y_nave,nivel_2,mapa);
		recoge_vidas(direccion, puntaje, mensaje, x_nave, y_nave, nivel_2);

		//Contadores
		contador_enemigo1++;
		contador_enemigo2++;

	}//fin while
}
void jugar_nivel_3()
{
	Random r;
	int x_nave = XCENTRO+1, y_nave = YCENTRO-1, direccion = ARRIBA, mapa = 3,x_centro = XCENTRO+1, y_centro = YCENTRO-1;
	bool mensaje = false, disparar_1 = false, activador_1 = true;
	bool disparar_2 = false, activador_2 = true;
	int puntaje = 0, contador_aviso = 0;
	int x_enemigo1 = 35, y_enemigo1 = YENEMIGO1, contador_enemigo1 = 0, dx_enemigo1 = 1, balas_enemigo_1 = 14;
	int x_enemigo2 = 35, y_enemigo2 = YENEMIGO2, contador_enemigo2 = 0, dx_enemigo2 = -1, balas_enemigo_2 = 14;;
	int x_bala_1, y_bala_1, x_bala_2, y_bala_2;

	color_enemigos = 3;
	x_bala_1 = r.Next(5, 66);
	x_bala_2 = r.Next(5, 66);

	if (musica == true){ musica_nivel2(); }
	presentacion_nivel_3();
	imprime_vidas_restantes();
	segundos(4);
	Console::Clear();

	imprimir_nivel(nivel_3);
	puntos(puntaje);

	elegir_nave_arriba(tipo_nave, x_nave, y_nave);
	imprimir_enemigo_1(x_enemigo1, y_enemigo1);
	imprimir_enemigo_2(x_enemigo2, y_enemigo2);

	while (1)
	{
		if (puntaje == 4485)
		{
			if (musica == true){ ganaste_sound(); }
			nivel_ganado(); segundos(6);
			regenerar_nivel(nivel_3);
			detener_musica();
			break; 
		}
		borrar_aviso(mensaje, contador_aviso);
		vidas(vida, gameover);

		//Enemigo 1
		if (contador_enemigo1 == 80)
		{
			if (x_enemigo1 == 66 || x_enemigo1 == 3){ dx_enemigo1 *= -1; }

			borrar_enemigo_1(x_enemigo1, y_enemigo1);
			x_enemigo1 += dx_enemigo1;
			imprimir_enemigo_1(x_enemigo1, y_enemigo1);
			contador_enemigo1 = 0;

			if (x_bala_1 == x_enemigo1 && activador_1 == true)
			{
				activador_1 = false;
				y_bala_1 = y_enemigo1 + 2;
				bala(x_bala_1, y_bala_1);
				disparar_1 = true;
				balas_enemigo_1--;
			}

			if (disparar_1 == true)
			{
				borrar_bala(x_bala_1, y_bala_1);
				y_bala_1++;
				bala(x_bala_1, y_bala_1);
				regenerar_punto(x_bala_1, y_bala_1, nivel_3, -1);
				colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_3);

				if (y_bala_1 == 31)
				{
					borrar_bala(x_bala_1, y_bala_1);
					disparar_1 = false;
					activador_1 = true;
				}
			}
		}

		colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);

		//Enemigo 2
		if (contador_enemigo2 == 80)
		{
			if (x_enemigo2 == 66 || x_enemigo2 == 3){ dx_enemigo2 *= -1; }

			borrar_enemigo_2(x_enemigo2, y_enemigo2);
			x_enemigo2 += dx_enemigo2;
			imprimir_enemigo_2(x_enemigo2, y_enemigo2);
			contador_enemigo2 = 0;

			if (x_bala_2 == x_enemigo2 && activador_2 == true)
			{
				activador_2 = false;
				y_bala_2 = y_enemigo2 - 2;
				bala(x_bala_2, y_bala_2);
				disparar_2 = true;
				balas_enemigo_2--;
			}

			if (disparar_2 == true)
			{
				borrar_bala(x_bala_2, y_bala_2);
				y_bala_2--;
				bala(x_bala_2, y_bala_2);
				regenerar_punto(x_bala_2, y_bala_2, nivel_3, 1);
				colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_3);

				if (y_bala_2 == 5)
				{
					borrar_bala(x_bala_2, y_bala_2);
					disparar_2 = false;
					activador_2 = true;
				}
			}
		}

		colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);

		//GAMEOVER
		if (gameover == true)
		{
			if (musica == true){ game_over_sound(); }
			explosion_nave(x_nave, y_nave);
			game_over();
			espera();
			vida = 3;
			regenerar_nivel(nivel_3);
			if (musica == true){ musica_menu(); }
			break;
		}

		//Movimiento nave
		if (kbhit())
		{
			int  tecla = getch();

			if (tecla == ARRIBA && nivel_3[y_nave - 2][x_nave] != 2)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave--;
				elegir_nave_arriba(tipo_nave, x_nave, y_nave);
				direccion = ARRIBA;
			}
			if (tecla == ABAJO && nivel_3[y_nave + 2][x_nave] != 2)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave++;
				elegir_nave_abajo(tipo_nave, x_nave, y_nave);
				direccion = ABAJO;
			}
			if (tecla == IZQUIERDA && nivel_3[y_nave][x_nave - 2] != 4)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave--;
				elegir_nave_izquierda(tipo_nave, x_nave, y_nave);
				direccion = IZQUIERDA;
			}
			if (tecla == DERECHA && nivel_3[y_nave][x_nave + 2] != 4)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave++;
				elegir_nave_derecha(tipo_nave, x_nave, y_nave);
				direccion = DERECHA;
			}
			if (tecla == 'p' )
			{
				int temp = 0;
				imprimir_pausa();
				desplazamiento_pausa(temp);
				{
					if (temp == 20)
					{
						Console::Clear();
						imprimir_nivel(nivel_3);
						if (direccion == ARRIBA){ elegir_nave_arriba(tipo_nave, x_nave, y_nave); }
						if (direccion == ABAJO){ elegir_nave_abajo(tipo_nave, x_nave, y_nave); }
						if (direccion == IZQUIERDA){ elegir_nave_izquierda(tipo_nave, x_nave, y_nave); }
						if (direccion == DERECHA){ elegir_nave_derecha(tipo_nave, x_nave, y_nave); }
						continue;
					}
					if (temp == 23)
					{ 
						regenerar_nivel(nivel_3); 
						gameover = true; 
						if (musica == true){ musica_menu(); }
						break;
					}
				}
			}
			colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_3);
			colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_3);
			colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);
			colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);
		}

		// Posicion balas

		posicion_x_bala(direccion, x_bala_1, y_bala_1, activador_1, balas_enemigo_1, x_nave);
		posicion_x_bala(direccion, x_bala_2, y_bala_2, activador_2, balas_enemigo_2, x_nave);

		//Recoger objetos
		recoge_cofres(direccion, puntaje, mensaje, x_nave, y_nave, nivel_3, mapa);
		recoge_puntos(direccion, puntaje, mensaje, x_nave, y_nave, nivel_3, mapa);
		recoge_vidas(direccion, puntaje, mensaje, x_nave, y_nave, nivel_3);

		//Contadores
		contador_enemigo1++;
		contador_enemigo2++;

	}//fin while
}
void jugar_nivel_4()
{
	Random r;
	int x_nave = XCENTRO, y_nave = YCENTRO, direccion = ARRIBA, mapa = 4, x_centro = XCENTRO, y_centro = YCENTRO;
	bool mensaje = false, disparar_1 = false, activador_1 = true;
	bool disparar_2 = false, activador_2 = true;
	int puntaje = 0, contador_aviso = 0;
	int x_enemigo1 = 35, y_enemigo1 = YENEMIGO1, contador_enemigo1 = 0, dx_enemigo1 = 1, balas_enemigo_1 = 16;
	int x_enemigo2 = 35, y_enemigo2 = YENEMIGO2, contador_enemigo2 = 0, dx_enemigo2 = -1, balas_enemigo_2 = 16;;
	int x_bala_1, y_bala_1, x_bala_2, y_bala_2;

	color_enemigos = 4;
	x_bala_1 = r.Next(5, 66);
	x_bala_2 = r.Next(5, 66);

	if (musica == true){ musica_nivel2(); }
	presentacion_nivel_4();
	imprime_vidas_restantes();
	segundos(4);
	Console::Clear();

	imprimir_nivel(nivel_4);
	puntos(puntaje);

	elegir_nave_arriba(tipo_nave, x_nave, y_nave);
	imprimir_enemigo_1(x_enemigo1, y_enemigo1);
	imprimir_enemigo_2(x_enemigo2, y_enemigo2);

	while (1)
	{
		if (puntaje == 5200)
		{
			if (musica == true){ ganaste_sound(); }
			nivel_ganado(); segundos(6);
			regenerar_nivel(nivel_4);
			detener_musica();
			break; 
		}
		borrar_aviso(mensaje, contador_aviso);
		vidas(vida, gameover);

		//Enemigo 1
		if (contador_enemigo1 == 70)
		{
			if (x_enemigo1 == 66 || x_enemigo1 == 3){ dx_enemigo1 *= -1; }

			borrar_enemigo_1(x_enemigo1, y_enemigo1);
			x_enemigo1 += dx_enemigo1;
			imprimir_enemigo_1(x_enemigo1, y_enemigo1);
			contador_enemigo1 = 0;

			if (x_bala_1 == x_enemigo1 && activador_1 == true)
			{
				activador_1 = false;
				y_bala_1 = y_enemigo1 + 2;
				bala(x_bala_1, y_bala_1);
				disparar_1 = true;
				balas_enemigo_1--;
			}

			if (disparar_1 == true)
			{
				borrar_bala(x_bala_1, y_bala_1);
				y_bala_1++;
				bala(x_bala_1, y_bala_1);
				regenerar_punto(x_bala_1, y_bala_1, nivel_4, -1);
				colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_4);

				if (y_bala_1 == 31)
				{
					borrar_bala(x_bala_1, y_bala_1);
					disparar_1 = false;
					activador_1 = true;
				}
			}
		}

		colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);

		//Enemigo 2
		if (contador_enemigo2 == 70)
		{
			if (x_enemigo2 == 66 || x_enemigo2 == 3){ dx_enemigo2 *= -1; }

			borrar_enemigo_2(x_enemigo2, y_enemigo2);
			x_enemigo2 += dx_enemigo2;
			imprimir_enemigo_2(x_enemigo2, y_enemigo2);
			contador_enemigo2 = 0;

			if (x_bala_2 == x_enemigo2 && activador_2 == true)
			{
				activador_2 = false;
				y_bala_2 = y_enemigo2 - 2;
				bala(x_bala_2, y_bala_2);
				disparar_2 = true;
				balas_enemigo_2--;
			}

			if (disparar_2 == true)
			{
				borrar_bala(x_bala_2, y_bala_2);
				y_bala_2--;
				bala(x_bala_2, y_bala_2);
				regenerar_punto(x_bala_2, y_bala_2, nivel_4, 1);
				colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_4);

				if (y_bala_2 == 6)
				{
					borrar_bala(x_bala_2, y_bala_2);
					disparar_2 = false;
					activador_2 = true;
				}
			}
		}

		colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);

		//GAMEOVER
		if (gameover == true)
		{
			if (musica == true){ game_over_sound(); }
			explosion_nave(x_nave, y_nave);
			game_over();
			espera();
			vida = 3;
			regenerar_nivel(nivel_4);
			if (musica == true){ musica_menu(); }
			break;
		}

		//Movimiento nave
		if (kbhit())
		{
			int  tecla = getch();

			if (tecla == ARRIBA && nivel_4[y_nave - 2][x_nave] != 2 && nivel_4[y_nave - 2][x_nave] != 13 &&
				nivel_4[y_nave - 2][x_nave - 1] != 13 && nivel_4[y_nave - 2][x_nave + 1] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave--;
				elegir_nave_arriba(tipo_nave, x_nave, y_nave);
				direccion = ARRIBA;
			}
			if (tecla == ABAJO && nivel_4[y_nave + 2][x_nave] != 2 && nivel_4[y_nave + 2][x_nave] != 13 &&
				nivel_4[y_nave + 2][x_nave - 1] != 13 && nivel_4[y_nave + 2][x_nave + 1] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave++;
				elegir_nave_abajo(tipo_nave, x_nave, y_nave);
				direccion = ABAJO;
			}
			if (tecla == IZQUIERDA && nivel_4[y_nave][x_nave - 2] != 4 && nivel_4[y_nave][x_nave - 2] != 13 &&
				nivel_4[y_nave + 1][x_nave - 2] != 13 && nivel_4[y_nave - 1][x_nave - 2] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave--;
				elegir_nave_izquierda(tipo_nave, x_nave, y_nave);
				direccion = IZQUIERDA;
			}
			if (tecla == DERECHA && nivel_4[y_nave][x_nave + 2] != 4 && nivel_4[y_nave][x_nave + 2] != 13 &&
				nivel_4[y_nave + 1][x_nave + 2] != 13 && nivel_4[y_nave - 1][x_nave + 2] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave++;
				elegir_nave_derecha(tipo_nave, x_nave, y_nave);
				direccion = DERECHA;
			}
			if (tecla == 'p' )
			{
				int temp = 0;
				imprimir_pausa();
				desplazamiento_pausa(temp);
				{
					if (temp == 20)
					{
						Console::Clear();
						imprimir_nivel(nivel_4);
						if (direccion == ARRIBA){ elegir_nave_arriba(tipo_nave, x_nave, y_nave); }
						if (direccion == ABAJO){ elegir_nave_abajo(tipo_nave, x_nave, y_nave); }
						if (direccion == IZQUIERDA){ elegir_nave_izquierda(tipo_nave, x_nave, y_nave); }
						if (direccion == DERECHA){ elegir_nave_derecha(tipo_nave, x_nave, y_nave); }
						continue;
					}
					if (temp == 23)
					{ 
						regenerar_nivel(nivel_4); 
						gameover = true; 
						if (musica == true){ musica_menu(); }
						break;
					}
				}
			}
			colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_4);
			colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_4);
			colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);
			colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);
		}

		// Posicion balas

		posicion_x_bala(direccion, x_bala_1, y_bala_1, activador_1, balas_enemigo_1, x_nave);
		posicion_x_bala(direccion, x_bala_2, y_bala_2, activador_2, balas_enemigo_2, x_nave);

		//Recoger objetos
		recoge_cofres(direccion, puntaje, mensaje, x_nave, y_nave, nivel_4, mapa);
		recoge_puntos(direccion, puntaje, mensaje, x_nave, y_nave, nivel_4, mapa);
		recoge_vidas(direccion, puntaje, mensaje, x_nave, y_nave, nivel_4);

		//Contadores
		contador_enemigo1++;
		contador_enemigo2++;

	}//fin while
}
void jugar_nivel_5()
{
	Random r;
	int x_nave = XCENTRO + 2, y_nave = YCENTRO, direccion = ARRIBA, mapa = 5, x_centro = XCENTRO + 2, y_centro = YCENTRO;
	bool mensaje = false, disparar_1 = false, activador_1 = true;
	bool disparar_2 = false, activador_2 = true;
	int puntaje = 0, contador_aviso = 0;
	int x_enemigo1 = 35, y_enemigo1 = YENEMIGO1, contador_enemigo1 = 0, dx_enemigo1 = 1, balas_enemigo_1 = 17;
	int x_enemigo2 = 35, y_enemigo2 = YENEMIGO2, contador_enemigo2 = 0, dx_enemigo2 = -1, balas_enemigo_2 = 17;;
	int x_bala_1, y_bala_1, x_bala_2, y_bala_2;

	color_enemigos = 5;
	x_bala_1 = r.Next(5, 66);
	x_bala_2 = r.Next(5, 66);

	if (musica == true){ musica_nivel3(); }
	presentacion_nivel_5();
	imprime_vidas_restantes();
	segundos(4);
	Console::Clear();

	imprimir_nivel(nivel_5);
	puntos(puntaje);

	elegir_nave_arriba(tipo_nave, x_nave, y_nave);
	imprimir_enemigo_1(x_enemigo1, y_enemigo1);
	imprimir_enemigo_2(x_enemigo2, y_enemigo2);

	while (1)
	{
		if (puntaje == 7205)
		{
			if (musica == true){ ganaste_sound(); }
			nivel_ganado(); segundos(6);
			regenerar_nivel(nivel_5);
			detener_musica();
			break;
		}
		borrar_aviso(mensaje, contador_aviso);
		vidas(vida, gameover);

		//Enemigo 1
		if (contador_enemigo1 == 60)
		{
			if (x_enemigo1 == 66 || x_enemigo1 == 3){ dx_enemigo1 *= -1; }

			borrar_enemigo_1(x_enemigo1, y_enemigo1);
			x_enemigo1 += dx_enemigo1;
			imprimir_enemigo_1(x_enemigo1, y_enemigo1);
			contador_enemigo1 = 0;

			if (x_bala_1 == x_enemigo1 && activador_1 == true)
			{
				activador_1 = false;
				y_bala_1 = y_enemigo1 + 2;
				bala(x_bala_1, y_bala_1);
				disparar_1 = true;
				balas_enemigo_1--;
			}

			if (disparar_1 == true)
			{
				borrar_bala(x_bala_1, y_bala_1);
				y_bala_1++;
				bala(x_bala_1, y_bala_1);
				regenerar_punto(x_bala_1, y_bala_1, nivel_5, -1);
				colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_5);

				if (y_bala_1 == 31)
				{
					borrar_bala(x_bala_1, y_bala_1);
					disparar_1 = false;
					activador_1 = true;
				}
			}
		}

		colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);

		//Enemigo 2
		if (contador_enemigo2 == 60)
		{
			if (x_enemigo2 == 66 || x_enemigo2 == 3){ dx_enemigo2 *= -1; }

			borrar_enemigo_2(x_enemigo2, y_enemigo2);
			x_enemigo2 += dx_enemigo2;
			imprimir_enemigo_2(x_enemigo2, y_enemigo2);
			contador_enemigo2 = 0;

			if (x_bala_2 == x_enemigo2 && activador_2 == true)
			{
				activador_2 = false;
				y_bala_2 = y_enemigo2 - 2;
				bala(x_bala_2, y_bala_2);
				disparar_2 = true;
				balas_enemigo_2--;
			}

			if (disparar_2 == true)
			{
				borrar_bala(x_bala_2, y_bala_2);
				y_bala_2--;
				bala(x_bala_2, y_bala_2);
				regenerar_punto(x_bala_2, y_bala_2, nivel_5, 1);
				colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_5);

				if (y_bala_2 == 6)
				{
					borrar_bala(x_bala_2, y_bala_2);
					disparar_2 = false;
					activador_2 = true;
				}
			}
		}

		colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);

		//GAMEOVER
		if (gameover == true)
		{
			if (musica == true){ game_over_sound(); }
			explosion_nave(x_nave, y_nave);
			game_over();
			espera();
			vida = 3;
			regenerar_nivel(nivel_5);
			if (musica == true){ musica_menu(); }
			break;
		}

		//Movimiento nave
		if (kbhit())
		{
			int  tecla = getch();

			if (tecla == ARRIBA && nivel_5[y_nave - 2][x_nave] != 2 && nivel_5[y_nave - 2][x_nave] != 13 &&
				nivel_5[y_nave - 2][x_nave - 1] != 13 && nivel_5[y_nave - 2][x_nave + 1] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave--;
				elegir_nave_arriba(tipo_nave, x_nave, y_nave);
				direccion = ARRIBA;
			}
			if (tecla == ABAJO && nivel_5[y_nave + 2][x_nave] != 2 && nivel_5[y_nave + 2][x_nave] != 13 &&
				nivel_5[y_nave + 2][x_nave - 1] != 13 && nivel_5[y_nave + 2][x_nave + 1] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave++;
				elegir_nave_abajo(tipo_nave, x_nave, y_nave);
				direccion = ABAJO;
			}
			if (tecla == IZQUIERDA && nivel_5[y_nave][x_nave - 2] != 4 && nivel_5[y_nave][x_nave - 2] != 13 &&
				nivel_5[y_nave + 1][x_nave - 2] != 13 && nivel_5[y_nave - 1][x_nave - 2] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave--;
				elegir_nave_izquierda(tipo_nave, x_nave, y_nave);
				direccion = IZQUIERDA;
			}
			if (tecla == DERECHA && nivel_5[y_nave][x_nave + 2] != 4 && nivel_5[y_nave][x_nave + 2] != 13 &&
				nivel_5[y_nave + 1][x_nave + 2] != 13 && nivel_5[y_nave - 1][x_nave + 2] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave++;
				elegir_nave_derecha(tipo_nave, x_nave, y_nave);
				direccion = DERECHA;
			}
			if (tecla == 'p')
			{
				int temp = 0;
				imprimir_pausa();
				desplazamiento_pausa(temp);
				{
					if (temp == 20)
					{
						Console::Clear();
						imprimir_nivel(nivel_5);
						if (direccion == ARRIBA){ elegir_nave_arriba(tipo_nave, x_nave, y_nave); }
						if (direccion == ABAJO){ elegir_nave_abajo(tipo_nave, x_nave, y_nave); }
						if (direccion == IZQUIERDA){ elegir_nave_izquierda(tipo_nave, x_nave, y_nave); }
						if (direccion == DERECHA){ elegir_nave_derecha(tipo_nave, x_nave, y_nave); }
						continue;
					}
					if (temp == 23)
					{
						regenerar_nivel(nivel_5);
						gameover = true;
						if (musica == true){ musica_menu(); }
						break;
					}
				}
			}
			colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_5);
			colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_5);
			colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);
			colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);
		}

		// Posicion balas

		posicion_x_bala(direccion, x_bala_1, y_bala_1, activador_1, balas_enemigo_1, x_nave);
		posicion_x_bala(direccion, x_bala_2, y_bala_2, activador_2, balas_enemigo_2, x_nave);

		//Recoger objetos
		recoge_cofres(direccion, puntaje, mensaje, x_nave, y_nave, nivel_5, mapa);
		recoge_puntos(direccion, puntaje, mensaje, x_nave, y_nave, nivel_5, mapa);
		recoge_vidas(direccion, puntaje, mensaje, x_nave, y_nave, nivel_5);

		//Contadores
		contador_enemigo1++;
		contador_enemigo2++;

	}//fin while
}
void jugar_nivel_6()
{
	Random r;
	int x_nave = 17, y_nave = 16, direccion = DERECHA, mapa = 6, x_centro = 33, y_centro = 17;
	bool mensaje = false, disparar_1 = false, activador_1 = true;
	bool disparar_2 = false, activador_2 = true;
	int puntaje = 0, contador_aviso = 0;
	int x_enemigo1 = 35, y_enemigo1 = YENEMIGO1, contador_enemigo1 = 0, dx_enemigo1 = 1, balas_enemigo_1 = 17;
	int x_enemigo2 = 35, y_enemigo2 = YENEMIGO2, contador_enemigo2 = 0, dx_enemigo2 = -1, balas_enemigo_2 = 17;;
	int x_bala_1, y_bala_1, x_bala_2, y_bala_2;

	color_enemigos = 6;
	x_bala_1 = r.Next(5, 66);
	x_bala_2 = r.Next(5, 66);

	if (musica == true){ musica_nivel3(); }
	presentacion_nivel_6();
	imprime_vidas_restantes();
	segundos(4);
	Console::Clear();

	imprimir_nivel(nivel_6);
	puntos(puntaje);

	elegir_nave_derecha(tipo_nave, x_nave, y_nave);
	imprimir_enemigo_1(x_enemigo1, y_enemigo1);
	imprimir_enemigo_2(x_enemigo2, y_enemigo2);

	while (1)
	{
		if (puntaje == 8415)
		{
			if (musica == true){ ganaste_sound(); }
			nivel_ganado(); segundos(6);
			regenerar_nivel(nivel_6);
			detener_musica();
			break;
		}
		borrar_aviso(mensaje, contador_aviso);
		vidas(vida, gameover);

		//Enemigo 1
		if (contador_enemigo1 == 60)
		{
			if (x_enemigo1 == 66 || x_enemigo1 == 3){ dx_enemigo1 *= -1; }

			borrar_enemigo_1(x_enemigo1, y_enemigo1);
			x_enemigo1 += dx_enemigo1;
			imprimir_enemigo_1(x_enemigo1, y_enemigo1);
			contador_enemigo1 = 0;

			if (x_bala_1 == x_enemigo1 && activador_1 == true)
			{
				activador_1 = false;
				y_bala_1 = y_enemigo1 + 2;
				bala(x_bala_1, y_bala_1);
				disparar_1 = true;
				balas_enemigo_1--;
			}

			if (disparar_1 == true)
			{
				borrar_bala(x_bala_1, y_bala_1);
				y_bala_1++;
				bala(x_bala_1, y_bala_1);
				regenerar_punto(x_bala_1, y_bala_1, nivel_6, -1);
				colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_6);

				if (y_bala_1 == 31)
				{
					borrar_bala(x_bala_1, y_bala_1);
					disparar_1 = false;
					activador_1 = true;
				}
			}
		}

		colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);

		//Enemigo 2
		if (contador_enemigo2 == 60)
		{
			if (x_enemigo2 == 66 || x_enemigo2 == 3){ dx_enemigo2 *= -1; }

			borrar_enemigo_2(x_enemigo2, y_enemigo2);
			x_enemigo2 += dx_enemigo2;
			imprimir_enemigo_2(x_enemigo2, y_enemigo2);
			contador_enemigo2 = 0;

			if (x_bala_2 == x_enemigo2 && activador_2 == true)
			{
				activador_2 = false;
				y_bala_2 = y_enemigo2 - 2;
				bala(x_bala_2, y_bala_2);
				disparar_2 = true;
				balas_enemigo_2--;
			}

			if (disparar_2 == true)
			{
				borrar_bala(x_bala_2, y_bala_2);
				y_bala_2--;
				bala(x_bala_2, y_bala_2);
				regenerar_punto(x_bala_2, y_bala_2, nivel_6, 1);
				colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_6);

				if (y_bala_2 == 5)
				{
					borrar_bala(x_bala_2, y_bala_2);
					disparar_2 = false;
					activador_2 = true;
				}
			}
		}

		colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);

		//GAMEOVER
		if (gameover == true)
		{
			if (musica == true){ game_over_sound(); }
			explosion_nave(x_nave, y_nave);
			game_over();
			espera();
			vida = 3;
			regenerar_nivel(nivel_6);
			if (musica == true){ musica_menu(); }
			break;
		}

		//Movimiento nave
		if (kbhit())
		{
			int  tecla = getch();

			if (tecla == ARRIBA && nivel_6[y_nave - 2][x_nave] != 2 && nivel_6[y_nave - 2][x_nave] != 13 &&
				nivel_6[y_nave - 2][x_nave - 1] != 13 && nivel_6[y_nave - 2][x_nave + 1] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave--;
				elegir_nave_arriba(tipo_nave, x_nave, y_nave);
				direccion = ARRIBA;
			}
			if (tecla == ABAJO && nivel_6[y_nave + 2][x_nave] != 2 && nivel_6[y_nave + 2][x_nave] != 13 &&
				nivel_6[y_nave + 2][x_nave - 1] != 13 && nivel_6[y_nave + 2][x_nave + 1] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave++;
				elegir_nave_abajo(tipo_nave, x_nave, y_nave);
				direccion = ABAJO;
			}
			if (tecla == IZQUIERDA && nivel_6[y_nave][x_nave - 2] != 4 && nivel_6[y_nave][x_nave - 2] != 13 &&
				nivel_6[y_nave + 1][x_nave - 2] != 13 && nivel_6[y_nave - 1][x_nave - 2] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave--;
				elegir_nave_izquierda(tipo_nave, x_nave, y_nave);
				direccion = IZQUIERDA;
			}
			if (tecla == DERECHA && nivel_6[y_nave][x_nave + 2] != 4 && nivel_6[y_nave][x_nave + 2] != 13 &&
				nivel_6[y_nave + 1][x_nave + 2] != 13 && nivel_6[y_nave - 1][x_nave + 2] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave++;
				elegir_nave_derecha(tipo_nave, x_nave, y_nave);
				direccion = DERECHA;
			}
			if (tecla == 'p')
			{
				int temp = 0;
				imprimir_pausa();
				desplazamiento_pausa(temp);
				{
					if (temp == 20)
					{
						Console::Clear();
						imprimir_nivel(nivel_6);
						if (direccion == ARRIBA){ elegir_nave_arriba(tipo_nave, x_nave, y_nave); }
						if (direccion == ABAJO){ elegir_nave_abajo(tipo_nave, x_nave, y_nave); }
						if (direccion == IZQUIERDA){ elegir_nave_izquierda(tipo_nave, x_nave, y_nave); }
						if (direccion == DERECHA){ elegir_nave_derecha(tipo_nave, x_nave, y_nave); }
						continue;
					}
					if (temp == 23)
					{
						regenerar_nivel(nivel_6);
						gameover = true;
						if (musica == true){ musica_menu(); }
						break;
					}
				}
			}
			colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_6);
			colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_6);
			colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);
			colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);
		}

		if (nivel_6[y_nave][x_nave] == 15 && direccion == ABAJO)
		{
			borrar_nave(direccion, x_nave, y_nave);
			direccion = ARRIBA;
			x_nave = 64; y_nave = 27;
			elegir_nave_arriba(tipo_nave, x_nave, y_nave);
		}

		// Posicion balas

		posicion_x_bala(direccion, x_bala_1, y_bala_1, activador_1, balas_enemigo_1, x_nave);
		posicion_x_bala(direccion, x_bala_2, y_bala_2, activador_2, balas_enemigo_2, x_nave);

		//Recoger objetos
		recoge_cofres(direccion, puntaje, mensaje, x_nave, y_nave, nivel_6, mapa);
		recoge_puntos(direccion, puntaje, mensaje, x_nave, y_nave, nivel_6, mapa);
		recoge_vidas(direccion, puntaje, mensaje, x_nave, y_nave, nivel_6);

		//Contadores
		contador_enemigo1++;
		contador_enemigo2++;

	}//fin while
}
void jugar_nivel_7() 
{
	Random r;
	int x_nave = XCENTRO - 1, y_nave = YCENTRO + 1, direccion = ARRIBA, mapa = 7, x_centro = XCENTRO - 1, y_centro = YCENTRO + 1;
	bool mensaje = false, disparar_1 = false, activador_1 = true;
	bool disparar_2 = false, activador_2 = true;
	int puntaje = 0, contador_aviso = 0;
	int x_enemigo1 = 35, y_enemigo1 = YENEMIGO1, contador_enemigo1 = 0, dx_enemigo1 = 1, balas_enemigo_1 = 18;
	int x_enemigo2 = 35, y_enemigo2 = YENEMIGO2, contador_enemigo2 = 0, dx_enemigo2 = -1, balas_enemigo_2 = 18;;
	int x_bala_1, y_bala_1, x_bala_2, y_bala_2;

	color_enemigos = 7;
	x_bala_1 = r.Next(5, 66);
	x_bala_2 = r.Next(5, 66);

	if (musica == true){ musica_nivel4(); }
	presentacion_nivel_7();
	imprime_vidas_restantes();
	segundos(4);
	Console::Clear();

	imprimir_nivel(nivel_7);
	puntos(puntaje);

	elegir_nave_arriba(tipo_nave, x_nave, y_nave);
	imprimir_enemigo_1(x_enemigo1, y_enemigo1);
	imprimir_enemigo_2(x_enemigo2, y_enemigo2);

	while (1)
	{
		if (puntaje == 8665)
		{
			if (musica == true){ ganaste_sound(); }
			nivel_ganado(); segundos(6);
			regenerar_nivel(nivel_7);
			detener_musica();
			break;
		}
		borrar_aviso(mensaje, contador_aviso);
		vidas(vida, gameover);

		//Enemigo 1
		if (contador_enemigo1 == 55)
		{
			if (x_enemigo1 == 66 || x_enemigo1 == 3){ dx_enemigo1 *= -1; }

			borrar_enemigo_1(x_enemigo1, y_enemigo1);
			x_enemigo1 += dx_enemigo1;
			imprimir_enemigo_1(x_enemigo1, y_enemigo1);
			contador_enemigo1 = 0;

			if (x_bala_1 == x_enemigo1 && activador_1 == true)
			{
				activador_1 = false;
				y_bala_1 = y_enemigo1 + 2;
				bala(x_bala_1, y_bala_1);
				disparar_1 = true;
				balas_enemigo_1--;
			}

			if (disparar_1 == true)
			{
				borrar_bala(x_bala_1, y_bala_1);
				y_bala_1++;
				bala(x_bala_1, y_bala_1);
				regenerar_punto(x_bala_1, y_bala_1, nivel_7, -1);
				colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_7);

				if (y_bala_1 == 31)
				{
					borrar_bala(x_bala_1, y_bala_1);
					disparar_1 = false;
					activador_1 = true;
				}
			}
		}

		colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);

		//Enemigo 2
		if (contador_enemigo2 == 55)
		{
			if (x_enemigo2 == 66 || x_enemigo2 == 3){ dx_enemigo2 *= -1; }

			borrar_enemigo_2(x_enemigo2, y_enemigo2);
			x_enemigo2 += dx_enemigo2;
			imprimir_enemigo_2(x_enemigo2, y_enemigo2);
			contador_enemigo2 = 0;

			if (x_bala_2 == x_enemigo2 && activador_2 == true)
			{
				activador_2 = false;
				y_bala_2 = y_enemigo2 - 2;
				bala(x_bala_2, y_bala_2);
				disparar_2 = true;
				balas_enemigo_2--;
			}

			if (disparar_2 == true)
			{
				borrar_bala(x_bala_2, y_bala_2);
				y_bala_2--;
				bala(x_bala_2, y_bala_2);
				regenerar_punto(x_bala_2, y_bala_2, nivel_7, 1);
				colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_7);

				if (y_bala_2 == 5)
				{
					borrar_bala(x_bala_2, y_bala_2);
					disparar_2 = false;
					activador_2 = true;
				}
			}
		}

		colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);

		//GAMEOVER
		if (gameover == true)
		{
			if (musica == true){ game_over_sound(); }
			explosion_nave(x_nave, y_nave);
			game_over();
			espera();
			vida = 3;
			regenerar_nivel(nivel_7);
			if (musica == true){ musica_menu(); }
			break;
		}

		//Movimiento nave
		if (kbhit())
		{
			int  tecla = getch();

			if (tecla == ARRIBA && nivel_7[y_nave - 2][x_nave] != 2 && nivel_7[y_nave - 2][x_nave] != 13 &&
				nivel_7[y_nave - 2][x_nave - 1] != 13 && nivel_7[y_nave - 2][x_nave + 1] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave--;
				elegir_nave_arriba(tipo_nave, x_nave, y_nave);
				direccion = ARRIBA;
			}
			if (tecla == ABAJO && nivel_7[y_nave + 2][x_nave] != 2 && nivel_7[y_nave + 2][x_nave] != 13 &&
				nivel_7[y_nave + 2][x_nave - 1] != 13 && nivel_7[y_nave + 2][x_nave + 1] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave++;
				elegir_nave_abajo(tipo_nave, x_nave, y_nave);
				direccion = ABAJO;
			}
			if (tecla == IZQUIERDA && nivel_7[y_nave][x_nave - 2] != 4 && nivel_7[y_nave][x_nave - 2] != 13 &&
				nivel_7[y_nave + 1][x_nave - 2] != 13 && nivel_7[y_nave - 1][x_nave - 2] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave--;
				elegir_nave_izquierda(tipo_nave, x_nave, y_nave);
				direccion = IZQUIERDA;
			}
			if (tecla == DERECHA && nivel_7[y_nave][x_nave + 2] != 4 && nivel_7[y_nave][x_nave + 2] != 13 &&
				nivel_7[y_nave + 1][x_nave + 2] != 13 && nivel_7[y_nave - 1][x_nave + 2] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave++;
				elegir_nave_derecha(tipo_nave, x_nave, y_nave);
				direccion = DERECHA;
			}
			if (tecla == 'p')
			{
				int temp = 0;
				imprimir_pausa();
				desplazamiento_pausa(temp);
				{
					if (temp == 20)
					{
						Console::Clear();
						imprimir_nivel(nivel_7);
						if (direccion == ARRIBA){ elegir_nave_arriba(tipo_nave, x_nave, y_nave); }
						if (direccion == ABAJO){ elegir_nave_abajo(tipo_nave, x_nave, y_nave); }
						if (direccion == IZQUIERDA){ elegir_nave_izquierda(tipo_nave, x_nave, y_nave); }
						if (direccion == DERECHA){ elegir_nave_derecha(tipo_nave, x_nave, y_nave); }
						continue;
					}
					if (temp == 23)
					{ 
						regenerar_nivel(nivel_7); 
						gameover = true; 
						if (musica == true){ musica_menu(); }
						break;
					}
				}
			}
			colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_7);
			colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_7);
			colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);
			colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);
		}

		// Posicion balas

		posicion_x_bala(direccion, x_bala_1, y_bala_1, activador_1, balas_enemigo_1, x_nave);
		posicion_x_bala(direccion, x_bala_2, y_bala_2, activador_2, balas_enemigo_2, x_nave);

		//Recoger objetos
		recoge_cofres(direccion, puntaje, mensaje, x_nave, y_nave, nivel_7, mapa);
		recoge_puntos(direccion, puntaje, mensaje, x_nave, y_nave, nivel_7, mapa);
		recoge_vidas(direccion, puntaje, mensaje, x_nave, y_nave, nivel_7);

		//Contadores
		contador_enemigo1++;
		contador_enemigo2++;

	}//fin while
}
void jugar_nivel_8()
{
	Random r;
	int x_nave = XCENTRO, y_nave = YCENTRO, direccion = ARRIBA, mapa = 8, x_centro = XCENTRO, y_centro = YCENTRO;
	bool mensaje = false, disparar_1 = false, activador_1 = true;
	bool disparar_2 = false, activador_2 = true;
	int puntaje = 0, contador_aviso = 0;
	int x_enemigo1 = 35, y_enemigo1 = YENEMIGO1, contador_enemigo1 = 0, dx_enemigo1 = 1, balas_enemigo_1 = 19;
	int x_enemigo2 = 35, y_enemigo2 = YENEMIGO2, contador_enemigo2 = 0, dx_enemigo2 = -1, balas_enemigo_2 = 19;;
	int x_bala_1, y_bala_1, x_bala_2, y_bala_2;

	color_enemigos = 8;
	x_bala_1 = r.Next(5, 66);
	x_bala_2 = r.Next(5, 66);

	if (musica == true){ musica_nivel4(); }
	presentacion_nivel_8();
	imprime_vidas_restantes();
	segundos(4);
	Console::Clear();

	imprimir_nivel(nivel_8);
	puntos(puntaje);

	elegir_nave_arriba(tipo_nave, x_nave, y_nave);
	imprimir_enemigo_1(x_enemigo1, y_enemigo1);
	imprimir_enemigo_2(x_enemigo2, y_enemigo2);

	while (1)
	{
		if (puntaje == 9875)
		{
			if (musica == true){ ganaste_sound(); }
			nivel_ganado(); segundos(6);
			regenerar_nivel(nivel_8);
			detener_musica();
			break;
		}
		borrar_aviso(mensaje, contador_aviso);
		vidas(vida, gameover);

		//Enemigo 1
		if (contador_enemigo1 == 55)
		{
			if (x_enemigo1 == 66 || x_enemigo1 == 3){ dx_enemigo1 *= -1; }

			borrar_enemigo_1(x_enemigo1, y_enemigo1);
			x_enemigo1 += dx_enemigo1;
			imprimir_enemigo_1(x_enemigo1, y_enemigo1);
			contador_enemigo1 = 0;

			if (x_bala_1 == x_enemigo1 && activador_1 == true)
			{
				activador_1 = false;
				y_bala_1 = y_enemigo1 + 2;
				bala(x_bala_1, y_bala_1);
				disparar_1 = true;
				balas_enemigo_1--;
			}

			if (disparar_1 == true)
			{
				borrar_bala(x_bala_1, y_bala_1);
				y_bala_1++;
				bala(x_bala_1, y_bala_1);
				regenerar_punto(x_bala_1, y_bala_1, nivel_8, -1);
				colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_8);

				if (y_bala_1 == 31)
				{
					borrar_bala(x_bala_1, y_bala_1);
					disparar_1 = false;
					activador_1 = true;
				}
			}
		}

		colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);

		//Enemigo 2
		if (contador_enemigo2 == 55)
		{
			if (x_enemigo2 == 66 || x_enemigo2 == 3){ dx_enemigo2 *= -1; }

			borrar_enemigo_2(x_enemigo2, y_enemigo2);
			x_enemigo2 += dx_enemigo2;
			imprimir_enemigo_2(x_enemigo2, y_enemigo2);
			contador_enemigo2 = 0;

			if (x_bala_2 == x_enemigo2 && activador_2 == true)
			{
				activador_2 = false;
				y_bala_2 = y_enemigo2 - 2;
				bala(x_bala_2, y_bala_2);
				disparar_2 = true;
				balas_enemigo_2--;
			}

			if (disparar_2 == true)
			{
				borrar_bala(x_bala_2, y_bala_2);
				y_bala_2--;
				bala(x_bala_2, y_bala_2);
				regenerar_punto(x_bala_2, y_bala_2, nivel_8, 1);
				colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_8);

				if (y_bala_2 == 5)
				{
					borrar_bala(x_bala_2, y_bala_2);
					disparar_2 = false;
					activador_2 = true;
				}
			}
		}

		colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);

		//GAMEOVER
		if (gameover == true)
		{
			if (musica == true){ game_over_sound(); }
			explosion_nave(x_nave, y_nave);
			game_over();
			espera();
			vida = 3;
			regenerar_nivel(nivel_8);
			if (musica == true){ musica_menu(); }
			break;
		}

		//Movimiento nave
		if (kbhit())
		{
			int  tecla = getch();

			if (tecla == ARRIBA && nivel_8[y_nave - 2][x_nave] != 2 && nivel_8[y_nave - 2][x_nave] != 13 &&
				nivel_8[y_nave - 2][x_nave - 1] != 13 && nivel_8[y_nave - 2][x_nave + 1] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave--;
				elegir_nave_arriba(tipo_nave, x_nave, y_nave);
				direccion = ARRIBA;
			}
			if (tecla == ABAJO && nivel_8[y_nave + 2][x_nave] != 2 && nivel_8[y_nave + 2][x_nave] != 13 &&
				nivel_8[y_nave + 2][x_nave - 1] != 13 && nivel_8[y_nave + 2][x_nave + 1] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave++;
				elegir_nave_abajo(tipo_nave, x_nave, y_nave);
				direccion = ABAJO;
			}
			if (tecla == IZQUIERDA && nivel_8[y_nave][x_nave - 2] != 4 && nivel_8[y_nave][x_nave - 2] != 13 &&
				nivel_8[y_nave + 1][x_nave - 2] != 13 && nivel_8[y_nave - 1][x_nave - 2] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave--;
				elegir_nave_izquierda(tipo_nave, x_nave, y_nave);
				direccion = IZQUIERDA;
			}
			if (tecla == DERECHA && nivel_8[y_nave][x_nave + 2] != 4 && nivel_8[y_nave][x_nave + 2] != 13 &&
				nivel_8[y_nave + 1][x_nave + 2] != 13 && nivel_8[y_nave - 1][x_nave + 2] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave++;
				elegir_nave_derecha(tipo_nave, x_nave, y_nave);
				direccion = DERECHA;
			}
			if (tecla == 'p')
			{
				int temp = 0;
				imprimir_pausa();
				desplazamiento_pausa(temp);
				{
					if (temp == 20)
					{
						Console::Clear();
						imprimir_nivel(nivel_8);
						if (direccion == ARRIBA){ elegir_nave_arriba(tipo_nave, x_nave, y_nave); }
						if (direccion == ABAJO){ elegir_nave_abajo(tipo_nave, x_nave, y_nave); }
						if (direccion == IZQUIERDA){ elegir_nave_izquierda(tipo_nave, x_nave, y_nave); }
						if (direccion == DERECHA){ elegir_nave_derecha(tipo_nave, x_nave, y_nave); }
						continue;
					}
					if (temp == 23)
					{
						regenerar_nivel(nivel_8);
						gameover = true;
						if (musica == true){ musica_menu(); }
						break;
					}
				}
			}
			colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_8);
			colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_8);
			colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);
			colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);
		}

		if (nivel_8[y_nave][x_nave] == 15 && direccion == ABAJO)
		{
			borrar_nave(direccion, x_nave, y_nave);
			direccion = ABAJO;
			x_nave = 64; y_nave = 7;
			elegir_nave_abajo(tipo_nave, x_nave, y_nave);
		}
		if (nivel_8[y_nave][x_nave] == 15 && direccion == ARRIBA)
		{
			borrar_nave(direccion, x_nave, y_nave);
			direccion = ARRIBA;
			x_nave = 6; y_nave = 30; 
			elegir_nave_arriba(tipo_nave, x_nave, y_nave);
		}

		// Posicion balas

		posicion_x_bala(direccion, x_bala_1, y_bala_1, activador_1, balas_enemigo_1, x_nave);
		posicion_x_bala(direccion, x_bala_2, y_bala_2, activador_2, balas_enemigo_2, x_nave);

		//Recoger objetos
		recoge_cofres(direccion, puntaje, mensaje, x_nave, y_nave, nivel_8, mapa);
		recoge_puntos(direccion, puntaje, mensaje, x_nave, y_nave, nivel_8, mapa);
		recoge_vidas(direccion, puntaje, mensaje, x_nave, y_nave, nivel_8);

		//Contadores
		contador_enemigo1++;
		contador_enemigo2++;

	}//fin while
}
void jugar_nivel_9()
{
	Random r;
	int x_nave = XCENTRO-1, y_nave = YCENTRO, direccion = ARRIBA, mapa = 9, x_centro = XCENTRO-1, y_centro = YCENTRO+1;
	bool mensaje = false, disparar_1 = false, activador_1 = true;
	bool disparar_2 = false, activador_2 = true;
	int puntaje = 0, contador_aviso = 0;
	int x_enemigo1 = 35, y_enemigo1 = YENEMIGO1, contador_enemigo1 = 0, dx_enemigo1 = 1, balas_enemigo_1 = 20;
	int x_enemigo2 = 35, y_enemigo2 = YENEMIGO2, contador_enemigo2 = 0, dx_enemigo2 = -1, balas_enemigo_2 =20;;
	int x_bala_1, y_bala_1, x_bala_2, y_bala_2;

	color_enemigos = 9;
	x_bala_1 = r.Next(5, 66);
	x_bala_2 = r.Next(5, 66);

	if (musica == true){ musica_nivel5(); }
	presentacion_nivel_9();
	imprime_vidas_restantes();
	segundos(4);
	Console::Clear();

	imprimir_nivel(nivel_9);
	puntos(puntaje);

	elegir_nave_arriba(tipo_nave, x_nave, y_nave);
	imprimir_enemigo_1(x_enemigo1, y_enemigo1);
	imprimir_enemigo_2(x_enemigo2, y_enemigo2);

	while (1)
	{
		if (puntaje == 11220)
		{
			if (musica == true){ ganaste_sound(); }
			nivel_ganado(); segundos(6);
			regenerar_nivel(nivel_9);
			detener_musica();
			break;
		}
		borrar_aviso(mensaje, contador_aviso);
		vidas(vida, gameover);

		//Enemigo 1
		if (contador_enemigo1 == 50)
		{
			if (x_enemigo1 == 66 || x_enemigo1 == 3){ dx_enemigo1 *= -1; }

			borrar_enemigo_1(x_enemigo1, y_enemigo1);
			x_enemigo1 += dx_enemigo1;
			imprimir_enemigo_1(x_enemigo1, y_enemigo1);
			contador_enemigo1 = 0;

			if (x_bala_1 == x_enemigo1 && activador_1 == true)
			{
				activador_1 = false;
				y_bala_1 = y_enemigo1 + 2;
				bala(x_bala_1, y_bala_1);
				disparar_1 = true;
				balas_enemigo_1--;
			}

			if (disparar_1 == true)
			{
				borrar_bala(x_bala_1, y_bala_1);
				y_bala_1++;
				bala(x_bala_1, y_bala_1);
				regenerar_punto(x_bala_1, y_bala_1, nivel_9, -1);
				colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_9);

				if (y_bala_1 == 31)
				{
					borrar_bala(x_bala_1, y_bala_1);
					disparar_1 = false;
					activador_1 = true;
				}
			}
		}

		colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);

		//Enemigo 2
		if (contador_enemigo2 == 50)
		{
			if (x_enemigo2 == 66 || x_enemigo2 == 3){ dx_enemigo2 *= -1; }

			borrar_enemigo_2(x_enemigo2, y_enemigo2);
			x_enemigo2 += dx_enemigo2;
			imprimir_enemigo_2(x_enemigo2, y_enemigo2);
			contador_enemigo2 = 0;

			if (x_bala_2 == x_enemigo2 && activador_2 == true)
			{
				activador_2 = false;
				y_bala_2 = y_enemigo2 - 2;
				bala(x_bala_2, y_bala_2);
				disparar_2 = true;
				balas_enemigo_2--;
			}

			if (disparar_2 == true)
			{
				borrar_bala(x_bala_2, y_bala_2);
				y_bala_2--;
				bala(x_bala_2, y_bala_2);
				regenerar_punto(x_bala_2, y_bala_2, nivel_9, 1);
				colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_9);

				if (y_bala_2 == 5)
				{
					borrar_bala(x_bala_2, y_bala_2);
					disparar_2 = false;
					activador_2 = true;
				}
			}
		}

		colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);

		//GAMEOVER
		if (gameover == true)
		{
			if (musica == true){ game_over_sound(); }
			explosion_nave(x_nave, y_nave);
			game_over();
			espera();
			vida = 3;
			regenerar_nivel(nivel_9);
			if (musica == true){ musica_menu(); }
			break;
		}

		//Movimiento nave
		if (kbhit())
		{
			int  tecla = getch();

			if (tecla == ARRIBA && nivel_9[y_nave - 2][x_nave] != 2 && nivel_9[y_nave - 2][x_nave] != 13 &&
				nivel_9[y_nave - 2][x_nave - 1] != 13 && nivel_9[y_nave - 2][x_nave + 1] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave--;
				elegir_nave_arriba(tipo_nave, x_nave, y_nave);
				direccion = ARRIBA;
			}
			if (tecla == ABAJO && nivel_9[y_nave + 2][x_nave] != 2 && nivel_9[y_nave + 2][x_nave] != 13 &&
				nivel_9[y_nave + 2][x_nave - 1] != 13 && nivel_9[y_nave + 2][x_nave + 1] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				y_nave++;
				elegir_nave_abajo(tipo_nave, x_nave, y_nave);
				direccion = ABAJO;
			}
			if (tecla == IZQUIERDA && nivel_9[y_nave][x_nave - 2] != 4 && nivel_9[y_nave][x_nave - 2] != 13 &&
				nivel_9[y_nave + 1][x_nave - 2] != 13 && nivel_9[y_nave - 1][x_nave - 2] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave--;
				elegir_nave_izquierda(tipo_nave, x_nave, y_nave);
				direccion = IZQUIERDA;
			}
			if (tecla == DERECHA && nivel_9[y_nave][x_nave + 2] != 4 && nivel_9[y_nave][x_nave + 2] != 13 &&
				nivel_9[y_nave + 1][x_nave + 2] != 13 && nivel_9[y_nave - 1][x_nave + 2] != 13)
			{
				borrar_nave(direccion, x_nave, y_nave);
				x_nave++;
				elegir_nave_derecha(tipo_nave, x_nave, y_nave);
				direccion = DERECHA;
			}
			if (tecla == 'p')
			{
				int temp = 0;
				imprimir_pausa();
				desplazamiento_pausa(temp);
				{
					if (temp == 20)
					{
						Console::Clear();
						imprimir_nivel(nivel_9);
						if (direccion == ARRIBA){ elegir_nave_arriba(tipo_nave, x_nave, y_nave); }
						if (direccion == ABAJO){ elegir_nave_abajo(tipo_nave, x_nave, y_nave); }
						if (direccion == IZQUIERDA){ elegir_nave_izquierda(tipo_nave, x_nave, y_nave); }
						if (direccion == DERECHA){ elegir_nave_derecha(tipo_nave, x_nave, y_nave); }
						continue;
					}
					if (temp == 23)
					{
						regenerar_nivel(nivel_9);
						gameover = true;
						if (musica == true){ musica_menu(); }
						break;
					}
				}
			}
			colision_bala(direccion, x_bala_1, y_bala_1, x_nave, y_nave, x_centro, y_centro, disparar_1, activador_1, nivel_9);
			colision_bala(direccion, x_bala_2, y_bala_2, x_nave, y_nave, x_centro, y_centro, disparar_2, activador_2, nivel_9);
			colision_enemigo1(direccion, x_enemigo1, y_enemigo1, x_nave, y_nave, x_centro, y_centro);
			colision_enemigo2(direccion, x_enemigo2, y_enemigo2, x_nave, y_nave, x_centro, y_centro);
		}

		if (nivel_9[y_nave][x_nave] == 15 && direccion == ABAJO)
		{
			borrar_nave(direccion, x_nave, y_nave);
			direccion = ABAJO;
			x_nave = 63; y_nave = 9;
			elegir_nave_abajo(tipo_nave, x_nave, y_nave);
		}
		if (nivel_9[y_nave][x_nave] == 15 && direccion == ARRIBA)
		{
			borrar_nave(direccion, x_nave, y_nave);
			direccion = DERECHA;
			x_nave = 4; y_nave = 8;
			elegir_nave_derecha(tipo_nave, x_nave, y_nave);
		}
		if (nivel_9[y_nave][x_nave] == 15 && direccion == IZQUIERDA)
		{
			borrar_nave(direccion, x_nave, y_nave);
			direccion = IZQUIERDA;
			x_nave = 57; y_nave = 23;
			elegir_nave_izquierda(tipo_nave, x_nave, y_nave);
		}
		if (nivel_9[y_nave][x_nave] == 15 && direccion == DERECHA)
		{
			borrar_nave(direccion, x_nave, y_nave);
			direccion = ARRIBA;
			x_nave = 39; y_nave = 14;
			elegir_nave_arriba(tipo_nave, x_nave, y_nave);
		}
		if (nivel_9[y_nave][x_nave] == 16 && direccion == ARRIBA)
		{
			borrar_nave(direccion, x_nave, y_nave);
			direccion = DERECHA;
			x_nave = 4; y_nave = 27;
			elegir_nave_derecha(tipo_nave, x_nave, y_nave);
		}
		if (nivel_9[y_nave][x_nave] == 16 && direccion == ABAJO)
		{
			borrar_nave(direccion, x_nave, y_nave);
			direccion = ABAJO;
			x_nave = 33; y_nave = 18;
			elegir_nave_abajo(tipo_nave, x_nave, y_nave);
		}
		if (nivel_9[y_nave][x_nave] == 16 && direccion == IZQUIERDA)
		{
			borrar_nave(direccion, x_nave, y_nave);
			direccion = IZQUIERDA;
			x_nave = 34; y_nave = 16;
			elegir_nave_izquierda(tipo_nave, x_nave, y_nave);
		}


		// Posicion balas

		posicion_x_bala(direccion, x_bala_1, y_bala_1, activador_1, balas_enemigo_1, x_nave);
		posicion_x_bala(direccion, x_bala_2, y_bala_2, activador_2, balas_enemigo_2, x_nave);

		//Recoger objetos
		recoge_cofres(direccion, puntaje, mensaje, x_nave, y_nave, nivel_9, mapa);
		recoge_puntos(direccion, puntaje, mensaje, x_nave, y_nave, nivel_9, mapa);
		recoge_vidas(direccion, puntaje, mensaje, x_nave, y_nave, nivel_9);

		//Contadores
		contador_enemigo1++;
		contador_enemigo2++;

	}//fin while
}

//MENU

int SOLAR[5][44] =
{
	{ 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0 },
	{ 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 2, 2, 0, 0, 0 },
	{ 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 2, 2, 2, 2, 2, 0 }
};

int FOX[5][30] =
{
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0 }
};

void desplazamiento_solar(int &x_solar, int &y_solar, int &incremento_solar)
{
	color_texto('yell');

	y_solar = 2;

	for (int f = 0; f < 5; f++)
	{
		for (int c = 3; c < 44; c++)
		{
			cursor(x_solar, y_solar); cout << " ";
		}y_solar++;
	}

	if (x_solar == 24){ incremento_solar *= -1; }
	if (x_solar == 2){ incremento_solar *= -1; }
	y_solar = 2; x_solar += incremento_solar;

	for (int f = 0; f < 5; f++)
	{
		cursor(x_solar, y_solar);
		for (int c = 0; c < 44; c++)
		{
			if (SOLAR[f][c] == 0){ cout << " "; }
			if (SOLAR[f][c] == 2){ cout << (char)219; }
		}y_solar++; cout << endl;
	}
}
void desplazamiento_fox(int &x_fox, int &y_fox, int &incremento_fox)
{
	color_texto('yell');

	y_fox = 9;

	for (int f = 0; f < 5; f++)
	{
		for (int c = 3; c < 30; c++)
		{
			cursor(x_fox, y_fox); cout << " ";
		}y_fox++;
	}

	if (x_fox == 33){ incremento_fox *= -1; }
	if (x_fox == 11){ incremento_fox *= -1; }
	y_fox = 9; x_fox += incremento_fox;

	for (int f = 0; f < 5; f++)
	{
		cursor(x_fox, y_fox);
		for (int c = 0; c < 30; c++)
		{
			if (FOX[f][c] == 0){ cout << " "; }
			if (FOX[f][c] == 1){ cout << (char)219; }
		}y_fox++; cout << endl;
	}
}

void borrar_flecha(int x,int y)
{
	cursor(x, y);         cout << " ";
	cursor(x + 1, y);     cout << " ";
	cursor(x, y + 1);     cout << " ";
	cursor(x + 1, y + 1); cout << " ";
	cursor(x + 2, y + 1); cout << " ";
	cursor(x + 3, y + 1); cout << " ";
	cursor(x, y + 2);     cout << " ";
	cursor(x + 1, y + 2); cout << " ";
	cursor(x + 2, y + 2); cout << " ";
	cursor(x + 3, y + 2); cout << " ";
	cursor(x + 4, y + 2); cout << " ";
	cursor(x, y + 3);     cout << " ";
	cursor(x + 1, y + 3); cout << " ";
	cursor(x + 2, y + 3); cout << " ";
	cursor(x + 3, y + 3); cout << " ";
	cursor(x, y + 4);     cout << " ";
	cursor(x + 1, y + 4); cout << " ";
}
void flecha(int x,int y)
{
	color_texto('red');
	cursor(x, y);         cout << (char)219;
	cursor(x + 1, y);     cout << (char)219;
	cursor(x, y + 1);     cout << (char)219;
	cursor(x + 1, y + 1); cout << (char)219;
	cursor(x + 2, y + 1); cout << (char)219;
	cursor(x + 3, y + 1); cout << (char)219;
	cursor(x, y + 2);     cout << (char)219;
	cursor(x + 1, y + 2); cout << (char)219;
	cursor(x + 2, y + 2); cout << (char)219;
	cursor(x + 3, y + 2); cout << (char)219;
	cursor(x + 4, y + 2); cout << (char)219;
	cursor(x, y + 3);     cout << (char)219;
	cursor(x + 1, y + 3); cout << (char)219;
	cursor(x + 2, y + 3); cout << (char)219;
	cursor(x + 3, y + 3); cout << (char)219;
	cursor(x, y + 4);     cout << (char)219;
	cursor(x + 1, y + 4); cout << (char)219;
}
void desplazamiento_flecha_inicio(int &x, int &y, int incremento,int min,int max)
{
	int contador = 0, x_solar = 3, incremento_solar = 1, y_solar;
	int x_fox = 32, incremento_fox = -1, y_fox;

	ocultar_cursor();

	while (1)
	{
		
		if (contador == 1500)
		{
			desplazamiento_solar(x_solar, y_solar, incremento_solar);
			desplazamiento_fox(x_fox, y_fox, incremento_fox);
			contador = 0;
		}

		if (kbhit())
		{
			int tecla = _getch();
			flecha(x, y);

			if (tecla == ABAJO && y < max)
			{
				borrar_flecha(x, y);
				y += incremento;
				flecha(x, y);
			}
			else
			{
				if (tecla == ABAJO)
				{
					borrar_flecha(x, y);
					y = min;
					flecha(x, y);
				}
			}

			if (tecla == ARRIBA && y > min)
			{
				borrar_flecha(x, y);
				y -= incremento;
				flecha(x, y);
			}
			else
			{
				if (tecla == ARRIBA)
				{
					borrar_flecha(x, y);
					y = max;
					flecha(x, y);
				}
			}

			if (tecla == 13)
			{
				break;
			}
		}
		contador++;
	}
}
void desplazamiento_flecha(int &x, int &y, int incremento, int min, int max,bool &volver)
{
	while (1)
	{
		int tecla = _getch();

		flecha(x, y);

		if (tecla == ABAJO && y < max)
		{
			borrar_flecha(x, y);
			y += incremento;
			flecha(x, y);
		}
		else
		{
			if (tecla == ABAJO)
			{
				borrar_flecha(x, y);
				y = min;
				flecha(x, y);
			}
		}

		if (tecla == ARRIBA && y > min)
		{
			borrar_flecha(x, y);
			y -= incremento;
			flecha(x, y);
		}
		else
		{
			if (tecla == ARRIBA)
			{
				borrar_flecha(x, y);
				y = max;
				flecha(x, y);
			}
		}

		if (tecla == ESC)
		{
			volver = true;
			break;
		}

		if (tecla == 13)
		{
			break;
		}
	}
}
void desplazamiento_flecha_arcade(int &x, int &y, int incremento, int min, int max, bool &volver, int &pagina,bool &jugar)
{
	while (1)
	{
		int tecla = _getch();

		flecha(x, y);

		if (tecla == ABAJO && y < max)
		{
			borrar_flecha(x, y);
			y += incremento;
			flecha(x, y);
		}
		else
		{
			if (tecla == ABAJO)
			{
				borrar_flecha(x, y);
				y = min;
				flecha(x, y);
			}
		}

		if (tecla == ARRIBA && y > min)
		{
			borrar_flecha(x, y);
			y -= incremento;
			flecha(x, y);
		}
		else
		{
			if (tecla == ARRIBA)
			{
				borrar_flecha(x, y);
				y = max;
				flecha(x, y);
			}
		}

		{
			if (tecla == DERECHA)
			{
				if (pagina == 3){ pagina = 1; }
				else{ pagina++; }
				break;
			}
		}

		{
			if (tecla == IZQUIERDA)
			{
				if (pagina == 1){ pagina = 3; }
				else { pagina--; }
				break;
			}
		}

		if (tecla == ESC)
		{
			volver = true;
			break;
		}

		if (tecla == 13)
		{
			jugar = true;
			break;
		}
	}
}
void desplazamiento_flecha_color(int &x, int &y, int incremento, int imcremento_x, int min, int max, bool &volver)
{
	while (1)
	{
		int tecla = _getch();

		flecha(x, y);

		if (tecla == ABAJO && y < max)
		{
			borrar_flecha(x, y);
			y += incremento;
			flecha(x, y);
		}
		else
		{
			if (tecla == ABAJO)
			{
				borrar_flecha(x, y);
				y = min;
				flecha(x, y);
			}
		}

		if (tecla == ARRIBA && y > min)
		{
			borrar_flecha(x, y);
			y -= incremento;
			flecha(x, y);
		}
		else
		{
			if (tecla == ARRIBA)
			{
				borrar_flecha(x, y);
				y = max;
				flecha(x, y);
			}
		}

		if (tecla == DERECHA && x < 41)
		{
			borrar_flecha(x, y);
			x += imcremento_x;
			flecha(x, y);
		}

		if (tecla == IZQUIERDA && x > 6)
		{
			borrar_flecha(x, y);
			x -= imcremento_x;
			flecha(x, y);
		}

		if (tecla == ESC)
		{
			volver = true;
			break;
		}

		if (tecla == 13)
		{
			break;
		}
	}
}

void imprimir_menu_opciones()
{
	int menu_jugar[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 8, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 0, 0, 8, 8, 0, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (menu_jugar[f][c] == 0){ cout << " "; };
			if (menu_jugar[f][c] == 1){ color_texto('gree'); cout << (char)201; };
			if (menu_jugar[f][c] == 2){ color_texto('gree'); cout << (char)205; };
			if (menu_jugar[f][c] == 3){ color_texto('gree'); cout << (char)187; };
			if (menu_jugar[f][c] == 4){ color_texto('gree'); cout << (char)186; };
			if (menu_jugar[f][c] == 5){ color_texto('gree'); cout << (char)200; };
			if (menu_jugar[f][c] == 6){ color_texto('gree'); cout << (char)188; };
			if (menu_jugar[f][c] == 7){ color_texto('yell'); cout << (char)219; };
			if (menu_jugar[f][c] == 8){ color_texto('blue'); cout << (char)178; };
			if (menu_jugar[f][c] == 9){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void desplazamiento_menu_opciones(int &op)
{
	int y = 13, x = 8;
	bool volver = false;

	ocultar_cursor();
	desplazamiento_flecha(x, y, 7, 13, 27, volver);

	Console::Clear();

	if (y == 13){ op = 1; }
	if (y == 20){ op = 2; }
	if (y == 27){ op = 3; }
	if (volver) { op = 0; }
}

void imprimir_menu_color()
{
	int menu_jugar[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 0, 0, 0, 0, 8, 8, 0, 8, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 8, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (menu_jugar[f][c] == 0){ cout << " "; };
			if (menu_jugar[f][c] == 1){ color_texto('gree'); cout << (char)201; };
			if (menu_jugar[f][c] == 2){ color_texto('gree'); cout << (char)205; };
			if (menu_jugar[f][c] == 3){ color_texto('gree'); cout << (char)187; };
			if (menu_jugar[f][c] == 4){ color_texto('gree'); cout << (char)186; };
			if (menu_jugar[f][c] == 5){ color_texto('gree'); cout << (char)200; };
			if (menu_jugar[f][c] == 6){ color_texto('gree'); cout << (char)188; };
			if (menu_jugar[f][c] == 7){ color_texto('yell'); cout << (char)219; };
			if (menu_jugar[f][c] == 8){ color_texto('blue'); cout << (char)178; };
			if (menu_jugar[f][c] == 9){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void desplazamiento_menu_color(int &op)
{
	int y = 14, x = 11;
	bool volver = false;

	ocultar_cursor();
	desplazamiento_flecha(x, y, 8, 14, 22, volver);

	Console::Clear();

	if (y == 14){ op = 1; }
	if (y == 22){ op = 2; }
	if (volver) { op = 0; }
}

void imprimir_menu_elige_nave()
{
	int elige_nave[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 11, 11, 11, 11, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 0, 0, 11, 11, 0, 0, 11, 11, 11, 11, 0, 0, 11, 11, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 9, 0, 9, 9, 9, 9, 9, 0, 0, 0, 0, 9, 9, 9, 9, 9, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 0, 11, 11, 11, 0, 11, 11, 0, 11, 11, 11, 0, 11, 11, 11, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 9, 0, 9, 0, 0, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 9, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 0, 0, 11, 11, 11, 11, 0, 0, 11, 11, 0, 0, 11, 11, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 9, 0, 9, 0, 0, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 9, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 11, 11, 11, 11, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 10, 0, 0, 0, 10, 0, 0, 10, 0, 0, 0, 10, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 14, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 10, 10, 10, 10, 10, 0, 0, 10, 10, 10, 10, 10, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 14, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 10, 10, 10, 10, 10, 0, 0, 10, 10, 10, 10, 10, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 14, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 10, 0, 0, 0, 10, 0, 0, 10, 0, 0, 0, 10, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 14, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (elige_nave[f][c] == 0){ cout << " "; };
			if (elige_nave[f][c] == 1){ color_texto('gree'); cout << (char)201; };
			if (elige_nave[f][c] == 2){ color_texto('gree'); cout << (char)205; };
			if (elige_nave[f][c] == 3){ color_texto('gree'); cout << (char)187; };
			if (elige_nave[f][c] == 4){ color_texto('gree'); cout << (char)186; };
			if (elige_nave[f][c] == 5){ color_texto('gree'); cout << (char)200; };
			if (elige_nave[f][c] == 6){ color_texto('gree'); cout << (char)188; };
			if (elige_nave[f][c] == 7){ color_texto('yell'); cout << (char)219; };
			if (elige_nave[f][c] == 8){ color_texto('red'); cout << (char)219; };
			if (elige_nave[f][c] == 9){ color_texto('gree'); cout << (char)178; };
			if (elige_nave[f][c] == 10){ color_texto('blue'); cout << (char)178; };
			if (elige_nave[f][c] == 11){ color_texto('gray'); cout << (char)178; };
			if (elige_nave[f][c] == 12){ color_texto('mage'); cout << (char)178; };
			if (elige_nave[f][c] == 13){ color_texto('red'); cout << (char)178; };
			if (elige_nave[f][c] == 14){ color_texto('yell'); cout << (char)178; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void desplazamiento_menu_elige_nave()
{
	int y = 12, x = 6;
	bool volver = false;

	ocultar_cursor();
	desplazamiento_flecha_color(x, y, 11, 33, 12, 23, volver);

	Console::Clear();

	if (y == 12 && x == 6 && volver != true){ tipo_nave = 1; }
	if (y == 23 && x == 6 && volver != true){ tipo_nave = 2; }
	if (y == 12 && x == 39 && volver != true){ tipo_nave = 3; }
	if (y == 23 && x == 39 && volver != true){ tipo_nave = 4; }
}

void imprimir_menu_musica()
{
	int menu_musica[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (menu_musica[f][c] == 0){ cout << " "; };
			if (menu_musica[f][c] == 1){ color_texto('gree'); cout << (char)201; };
			if (menu_musica[f][c] == 2){ color_texto('gree'); cout << (char)205; };
			if (menu_musica[f][c] == 3){ color_texto('gree'); cout << (char)187; };
			if (menu_musica[f][c] == 4){ color_texto('gree'); cout << (char)186; };
			if (menu_musica[f][c] == 5){ color_texto('gree'); cout << (char)200; };
			if (menu_musica[f][c] == 6){ color_texto('gree'); cout << (char)188; };
			if (menu_musica[f][c] == 7){ color_texto('yell'); cout << (char)219; };
			if (menu_musica[f][c] == 8){ color_texto('blue'); cout << (char)178; };
			if (menu_musica[f][c] == 9){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}

}
void desplazamiento_menu_musica()
{
	int y = 15, x = 8;
	bool volver = false;

	ocultar_cursor();
	desplazamiento_flecha(x, y, 10, 15, 25, volver);

	Console::Clear();

	if (y == 15 && volver != true){ musica = true; musica_menu(); }
	if (y == 25 && volver != true){ musica = false; detener_musica(); }
}

void imprimir_menu_color_nave()
{
	int menu_jugar[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 4 },
		{ 4, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 4 },
		{ 4, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (menu_jugar[f][c] == 0){ cout << " "; };
			if (menu_jugar[f][c] == 1){ color_texto('gree'); cout << (char)201; };
			if (menu_jugar[f][c] == 2){ color_texto('gree'); cout << (char)205; };
			if (menu_jugar[f][c] == 3){ color_texto('gree'); cout << (char)187; };
			if (menu_jugar[f][c] == 4){ color_texto('gree'); cout << (char)186; };
			if (menu_jugar[f][c] == 5){ color_texto('gree'); cout << (char)200; };
			if (menu_jugar[f][c] == 6){ color_texto('gree'); cout << (char)188; };
			if (menu_jugar[f][c] == 7){ color_texto('yell'); cout << (char)219; };
			if (menu_jugar[f][c] == 8){ color_texto('red'); cout << (char)219; };
			if (menu_jugar[f][c] == 9){ color_texto('gree'); cout << (char)178; };
			if (menu_jugar[f][c] == 10){ color_texto('blue'); cout << (char)178; };
			if (menu_jugar[f][c] == 11){ color_texto('gray'); cout << (char)178; };
			if (menu_jugar[f][c] == 12){ color_texto('mage'); cout << (char)178; };
			if (menu_jugar[f][c] == 13){ color_texto('red'); cout << (char)178; };
			if (menu_jugar[f][c] == 14){ color_texto('yell'); cout << (char)178; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void imprimir_menu_color_nivel()
{
	int menu_jugar[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 8, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 0, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 8, 8, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 0, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 0, 8, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 0, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 8, 8, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (menu_jugar[f][c] == 0){ cout << " "; };
			if (menu_jugar[f][c] == 1){ color_texto('gree'); cout << (char)201; };
			if (menu_jugar[f][c] == 2){ color_texto('gree'); cout << (char)205; };
			if (menu_jugar[f][c] == 3){ color_texto('gree'); cout << (char)187; };
			if (menu_jugar[f][c] == 4){ color_texto('gree'); cout << (char)186; };
			if (menu_jugar[f][c] == 5){ color_texto('gree'); cout << (char)200; };
			if (menu_jugar[f][c] == 6){ color_texto('gree'); cout << (char)188; };
			if (menu_jugar[f][c] == 7){ color_texto('yell'); cout << (char)219; };
			if (menu_jugar[f][c] == 8){ color_texto('blue'); cout << (char)178; };
			if (menu_jugar[f][c] == 9){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void imprimir_menu_color_borde()
{
	int menu_jugar[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (menu_jugar[f][c] == 0){ cout << " "; };
			if (menu_jugar[f][c] == 1){ color_texto('gree'); cout << (char)201; };
			if (menu_jugar[f][c] == 2){ color_texto('gree'); cout << (char)205; };
			if (menu_jugar[f][c] == 3){ color_texto('gree'); cout << (char)187; };
			if (menu_jugar[f][c] == 4){ color_texto('gree'); cout << (char)186; };
			if (menu_jugar[f][c] == 5){ color_texto('gree'); cout << (char)200; };
			if (menu_jugar[f][c] == 6){ color_texto('gree'); cout << (char)188; };
			if (menu_jugar[f][c] == 7){ color_texto('yell'); cout << (char)219; };
			if (menu_jugar[f][c] == 8){ color_texto('red'); cout << (char)219; };
			if (menu_jugar[f][c] == 9){ color_texto('gree'); cout << (char)178; };
			if (menu_jugar[f][c] == 10){ color_texto('blue'); cout << (char)178; };
			if (menu_jugar[f][c] == 11){ color_texto('whit'); cout << (char)178; };
			if (menu_jugar[f][c] == 12){ color_texto('mage'); cout << (char)178; };
			if (menu_jugar[f][c] == 13){ color_texto('red'); cout << (char)178; };
			if (menu_jugar[f][c] == 14){ color_texto('yell'); cout << (char)178; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void imprimir_menu_color_vida()
{
	int menu_jugar[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (menu_jugar[f][c] == 0){ cout << " "; };
			if (menu_jugar[f][c] == 1){ color_texto('gree'); cout << (char)201; };
			if (menu_jugar[f][c] == 2){ color_texto('gree'); cout << (char)205; };
			if (menu_jugar[f][c] == 3){ color_texto('gree'); cout << (char)187; };
			if (menu_jugar[f][c] == 4){ color_texto('gree'); cout << (char)186; };
			if (menu_jugar[f][c] == 5){ color_texto('gree'); cout << (char)200; };
			if (menu_jugar[f][c] == 6){ color_texto('gree'); cout << (char)188; };
			if (menu_jugar[f][c] == 7){ color_texto('yell'); cout << (char)219; };
			if (menu_jugar[f][c] == 8){ color_texto('red'); cout << (char)219; };
			if (menu_jugar[f][c] == 9){ color_texto('gree'); cout << (char)178; };
			if (menu_jugar[f][c] == 10){ color_texto('blue'); cout << (char)178; };
			if (menu_jugar[f][c] == 11){ color_texto('whit'); cout << (char)178; };
			if (menu_jugar[f][c] == 12){ color_texto('mage'); cout << (char)178; };
			if (menu_jugar[f][c] == 13){ color_texto('red'); cout << (char)178; };
			if (menu_jugar[f][c] == 14){ color_texto('yell'); cout << (char)178; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void imprimir_menu_color_cofre()
{
	int menu_jugar[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (menu_jugar[f][c] == 0){ cout << " "; };
			if (menu_jugar[f][c] == 1){ color_texto('gree'); cout << (char)201; };
			if (menu_jugar[f][c] == 2){ color_texto('gree'); cout << (char)205; };
			if (menu_jugar[f][c] == 3){ color_texto('gree'); cout << (char)187; };
			if (menu_jugar[f][c] == 4){ color_texto('gree'); cout << (char)186; };
			if (menu_jugar[f][c] == 5){ color_texto('gree'); cout << (char)200; };
			if (menu_jugar[f][c] == 6){ color_texto('gree'); cout << (char)188; };
			if (menu_jugar[f][c] == 7){ color_texto('yell'); cout << (char)219; };
			if (menu_jugar[f][c] == 8){ color_texto('red'); cout << (char)219; };
			if (menu_jugar[f][c] == 9){ color_texto('gree'); cout << (char)178; };
			if (menu_jugar[f][c] == 10){ color_texto('blue'); cout << (char)178; };
			if (menu_jugar[f][c] == 11){ color_texto('whit'); cout << (char)178; };
			if (menu_jugar[f][c] == 12){ color_texto('mage'); cout << (char)178; };
			if (menu_jugar[f][c] == 13){ color_texto('red'); cout << (char)178; };
			if (menu_jugar[f][c] == 14){ color_texto('yell'); cout << (char)178; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void imprimir_menu_color_puntos()
{
	int menu_jugar[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 0, 7, 7, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (menu_jugar[f][c] == 0){ cout << " "; };
			if (menu_jugar[f][c] == 1){ color_texto('gree'); cout << (char)201; };
			if (menu_jugar[f][c] == 2){ color_texto('gree'); cout << (char)205; };
			if (menu_jugar[f][c] == 3){ color_texto('gree'); cout << (char)187; };
			if (menu_jugar[f][c] == 4){ color_texto('gree'); cout << (char)186; };
			if (menu_jugar[f][c] == 5){ color_texto('gree'); cout << (char)200; };
			if (menu_jugar[f][c] == 6){ color_texto('gree'); cout << (char)188; };
			if (menu_jugar[f][c] == 7){ color_texto('yell'); cout << (char)219; };
			if (menu_jugar[f][c] == 8){ color_texto('red'); cout << (char)219; };
			if (menu_jugar[f][c] == 9){ color_texto('gree'); cout << (char)178; };
			if (menu_jugar[f][c] == 10){ color_texto('blue'); cout << (char)178; };
			if (menu_jugar[f][c] == 11){ color_texto('whit'); cout << (char)178; };
			if (menu_jugar[f][c] == 12){ color_texto('mage'); cout << (char)178; };
			if (menu_jugar[f][c] == 13){ color_texto('red'); cout << (char)178; };
			if (menu_jugar[f][c] == 14){ color_texto('yell'); cout << (char)178; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void desplazamiento_menu_color_nave()
{
	int y = 11, x = 6;
	bool volver = false;

	ocultar_cursor();
	desplazamiento_flecha_color(x, y, 8, 35, 11, 27, volver);

	Console::Clear();

	if (y == 11 && x == 6 && volver!=true){ color_nave = 'gree'; }
	if (y == 19 && x == 6 && volver != true){ color_nave = 'blue'; }
	if (y == 27 && x == 6 && volver != true){ color_nave = 'gray'; }
	if (y == 11 && x == 41 && volver != true){ color_nave = 'mage'; }
	if (y == 19 && x == 41 && volver != true){ color_nave = 'red'; }
	if (y == 27 && x == 41 && volver != true){ color_nave = 'yell'; }
}
void desplazamiento_menu_color_nivel(int &op)
{
	int y = 10, x = 11;
	bool volver = false;

	ocultar_cursor();
	desplazamiento_flecha(x, y, 6, 10, 28, volver);

	Console::Clear();

	if (y == 10){ op = 1; };
	if (y == 16){ op = 2; };
	if (y == 22){ op = 3; };
	if (y == 28){ op = 4; };
	if (volver){ op = 0; };
}
void desplazamiento_menu_color_borde()
{
	int y = 11, x = 6;
	bool volver = false;

	ocultar_cursor();
	desplazamiento_flecha_color(x, y, 8, 35, 11, 27, volver);

	Console::Clear();

	if (y == 11 && x == 6 && volver != true){ color_borde = 'gree'; }
	if (y == 19 && x == 6 && volver != true){ color_borde = 'blue'; }
	if (y == 27 && x == 6 && volver != true){ color_borde = 'whit'; }
	if (y == 11 && x == 41 && volver != true){ color_borde = 'mage'; }
	if (y == 19 && x == 41 && volver != true){ color_borde = 'red'; }
	if (y == 27 && x == 41 && volver != true){ color_borde = 'yell'; }
}
void desplazamiento_menu_color_vida()
{
	int y = 11, x = 6;
	bool volver = false;

	ocultar_cursor();
	desplazamiento_flecha_color(x, y, 8, 35, 11, 27, volver);

	Console::Clear();

	if (y == 11 && x == 6 && volver != true){ color_vida = 'gree'; }
	if (y == 19 && x == 6 && volver != true){ color_vida = 'blue'; }
	if (y == 27 && x == 6 && volver != true){ color_vida = 'whit'; }
	if (y == 11 && x == 41 && volver != true){ color_vida = 'mage'; }
	if (y == 19 && x == 41 && volver != true){ color_vida = 'red'; }
	if (y == 27 && x == 41 && volver != true){ color_vida = 'yell'; }
}
void desplazamiento_menu_color_cofre()
{
	int y = 11, x = 6;
	bool volver = false;

	ocultar_cursor();
	desplazamiento_flecha_color(x, y, 8, 35, 11, 27, volver);

	Console::Clear();

	if (y == 11 && x == 6 && volver != true){ color_cofre = 'gree'; }
	if (y == 19 && x == 6 && volver != true){ color_cofre = 'blue'; }
	if (y == 27 && x == 6 && volver != true){ color_cofre = 'whit'; }
	if (y == 11 && x == 41 && volver != true){ color_cofre = 'mage'; }
	if (y == 19 && x == 41 && volver != true){ color_cofre = 'red'; }
	if (y == 27 && x == 41 && volver != true){ color_cofre = 'yell'; }
}
void desplazamiento_menu_color_puntos()
{
	int y = 11, x = 6;
	bool volver = false;

	ocultar_cursor();
	desplazamiento_flecha_color(x, y, 8, 35, 11, 27, volver);

	Console::Clear();

	if (y == 11 && x == 6 && volver != true){ color_puntos = 'gree'; }
	if (y == 19 && x == 6 && volver != true){ color_puntos = 'blue'; }
	if (y == 27 && x == 6 && volver != true){ color_puntos = 'whit'; }
	if (y == 11 && x == 41 && volver != true){ color_puntos = 'mage'; }
	if (y == 19 && x == 41 && volver != true){ color_puntos = 'red'; }
	if (y == 27 && x == 41 && volver != true){ color_puntos = 'yell'; }
}

void imprimir_menu_principal()
{
	int menu_principal[FILAS][COLUMNAS] =
	{
		{ 5, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 6 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 0, 2, 2, 2, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 0, 2, 2, 2, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (menu_principal[f][c] == 0){ cout << " "; };
			if (menu_principal[f][c] == 1){ color_texto('blue'); cout << (char)178; };
			if (menu_principal[f][c] == 2){ color_texto('yell'); cout << (char)219; };
			if (menu_principal[f][c] == 3){ color_texto('red'); cout << (char)219; };
			if (menu_principal[f][c] == 4){ color_texto('gree'); cout << (char)186; };
			if (menu_principal[f][c] == 5){ color_texto('gree'); cout << (char)201; };
			if (menu_principal[f][c] == 6){ color_texto('gree'); cout << (char)187; };
			if (menu_principal[f][c] == 7){ color_texto('gree'); cout << (char)200; };
			if (menu_principal[f][c] == 8){ color_texto('gree'); cout << (char)205; };
			if (menu_principal[f][c] == 9){ color_texto('gree'); cout << (char)188; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}

}
void desplazamiento_menu_principal(int &op)
{
	int y = 16, x = 3;

	ocultar_cursor();
	desplazamiento_flecha_inicio(x, y, 6, 16, 28);

	Console::Clear();

	if (y == 16){ op = 1; };
	if (y == 22){ op = 2; };
	if (y == 28){ op = 3; };
}

void imprimir_menu_jugar()
{
	int menu_jugar[FILAS][COLUMNAS] = {
		{ 5, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 6 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 4 },
		{ 4, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 2, 2, 0, 2, 2, 2, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 2, 2, 0, 2, 2, 0, 2, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 2, 2, 0, 2, 2, 0, 0, 2, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 2, 2, 2, 0, 2, 2, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 2, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 2, 0, 2, 2, 0, 2, 2, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 2, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 2, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9 }
	};
	
	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (menu_jugar[f][c] == 0){ cout << " "; };
			if (menu_jugar[f][c] == 1){ color_texto('blue'); cout << (char)178; };
			if (menu_jugar[f][c] == 2){ color_texto('yell'); cout << (char)219; };
			if (menu_jugar[f][c] == 3){ color_texto('red'); cout << (char)219; };
			if (menu_jugar[f][c] == 4){ color_texto('gree'); cout << (char)186; };
			if (menu_jugar[f][c] == 5){ color_texto('gree'); cout << (char)201; };
			if (menu_jugar[f][c] == 6){ color_texto('gree'); cout << (char)187; };
			if (menu_jugar[f][c] == 7){ color_texto('gree'); cout << (char)200; };
			if (menu_jugar[f][c] == 8){ color_texto('gree'); cout << (char)205; };
			if (menu_jugar[f][c] == 9){ color_texto('gree'); cout << (char)188; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void desplazamiento_menu_jugar(int &op)
{
	int y = 19, x = 9;
	bool volver=false;

	ocultar_cursor();
	desplazamiento_flecha(x, y, 7, 19, 26,volver);

	Console::Clear();

	if (y == 19){ op = 1; }
	if (y == 26){ op = 2; }
	if (volver) { op = 0; }
}

void imprimir_arcade_1()
{
	int menu_arcade1[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 0, 0, 0, 0, 8, 8, 0, 8, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 8, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 8, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (menu_arcade1 [f][c] == 0){ cout << " "; };
			if (menu_arcade1[f][c] == 1){ color_texto('gree'); cout << (char)201; };
			if (menu_arcade1[f][c] == 2){ color_texto('gree'); cout << (char)205; };
			if (menu_arcade1[f][c] == 3){ color_texto('gree'); cout << (char)187; };
			if (menu_arcade1[f][c] == 4){ color_texto('gree'); cout << (char)186; };
			if (menu_arcade1[f][c] == 5){ color_texto('gree'); cout << (char)200; };
			if (menu_arcade1[f][c] == 6){ color_texto('gree'); cout << (char)188; };
			if (menu_arcade1[f][c] == 7){ color_texto('yell'); cout << (char)219; };
			if (menu_arcade1[f][c] == 8){ color_texto('blue'); cout << (char)178; };
			if (menu_arcade1[f][c] == 9){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void imprimir_arcade_2()
{
	int menu_arcade2[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 0, 0, 0, 0, 8, 8, 0, 8, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 8, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 8, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 }
	};

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (menu_arcade2[f][c] == 0){ cout << " "; };
			if (menu_arcade2[f][c] == 1){ color_texto('gree'); cout << (char)201; };
			if (menu_arcade2[f][c] == 2){ color_texto('gree'); cout << (char)205; };
			if (menu_arcade2[f][c] == 3){ color_texto('gree'); cout << (char)187; };
			if (menu_arcade2[f][c] == 4){ color_texto('gree'); cout << (char)186; };
			if (menu_arcade2[f][c] == 5){ color_texto('gree'); cout << (char)200; };
			if (menu_arcade2[f][c] == 6){ color_texto('gree'); cout << (char)188; };
			if (menu_arcade2[f][c] == 7){ color_texto('yell'); cout << (char)219; };
			if (menu_arcade2[f][c] == 8){ color_texto('blue'); cout << (char)178; };
			if (menu_arcade2[f][c] == 9){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void imprimir_arcade_3()
{
	int menu_arcade3[FILAS][COLUMNAS] = {
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 7, 7, 7, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 0, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 0, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 7, 7, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 0, 7, 7, 7, 7, 7, 7, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 0, 0, 0, 0, 8, 8, 0, 8, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 8, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 8, 0, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 8, 8, 8, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 8, 8, 8, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 0, 8, 8, 0, 0, 0, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6 } };

	cursor(0, 0);

	for (int f = 0; f < FILAS; f++)
	{
		for (int c = 0; c < COLUMNAS; c++)
		{
			if (menu_arcade3[f][c] == 0){ cout << " "; };
			if (menu_arcade3[f][c] == 1){ color_texto('gree'); cout << (char)201; };
			if (menu_arcade3[f][c] == 2){ color_texto('gree'); cout << (char)205; };
			if (menu_arcade3[f][c] == 3){ color_texto('gree'); cout << (char)187; };
			if (menu_arcade3[f][c] == 4){ color_texto('gree'); cout << (char)186; };
			if (menu_arcade3[f][c] == 5){ color_texto('gree'); cout << (char)200; };
			if (menu_arcade3[f][c] == 6){ color_texto('gree'); cout << (char)188; };
			if (menu_arcade3[f][c] == 7){ color_texto('yell'); cout << (char)219; };
			if (menu_arcade3[f][c] == 8){ color_texto('blue'); cout << (char)178; };
			if (menu_arcade3[f][c] == 9){ color_texto('red'); cout << (char)219; };
		}
		if (f != FILAS - 1){ cout << endl; }
	}
}
void desplazamiento_menu_arcade1(int &op,int &pagina, bool &volver, bool &jugar)
{
	int y = 13, x = 8;

	ocultar_cursor();
	desplazamiento_flecha_arcade(x, y, 7, 13, 27, volver, pagina, jugar);

	Console::Clear();

	if (y == 13){ op = 1; }
	if (y == 20){ op = 2; }
	if (y == 27){ op = 3; }
	if (volver) { op = 0; }
}
void desplazamiento_menu_arcade2(int &op, int &pagina, bool &volver, bool &jugar)
{
	int y = 13, x = 8;

	ocultar_cursor();
	desplazamiento_flecha_arcade(x, y, 7, 13, 27, volver, pagina, jugar);

	Console::Clear();

	if (y == 13){ op = 4; }
	if (y == 20){ op = 5; }
	if (y == 27){ op = 6; }
	if (volver) { op = 0; }
}
void desplazamiento_menu_arcade3(int &op, int &pagina, bool &volver, bool &jugar)
{
	int y = 13, x = 8;

	ocultar_cursor();
	desplazamiento_flecha_arcade(x, y, 7, 13, 27, volver, pagina, jugar);

	Console::Clear();

	if (y == 13){ op = 7; }
	if (y == 20){ op = 8; }
	if (y == 27){ op = 9; }
	if (volver) { op = 0; }
}

void MENU_musica()
{
	imprimir_menu_musica();
	desplazamiento_menu_musica();
}
void MENU_elige_nave()
{
	imprimir_menu_elige_nave();
	desplazamiento_menu_elige_nave();
}
void MENU_ARCADE()
{
	int pagina = 1;
	bool volver = false, jugar = false;

	while (1)
	{
		int op = 0;
		if (pagina == 1)
		{
			imprimir_arcade_1();
			desplazamiento_menu_arcade1(op, pagina,volver,jugar);
		}
		if (pagina == 2)
		{
			imprimir_arcade_2();
			desplazamiento_menu_arcade2(op, pagina,volver,jugar);
		}
		if (pagina == 3)
		{
			imprimir_arcade_3();
			desplazamiento_menu_arcade3(op, pagina, volver,jugar);
		}
		if (volver == true){ break; }
		if (op == 1 && jugar == true){ vida = 3; gameover = false; jugar_nivel_1(); if (musica == true){ musica_menu(); } break; }
		if (op == 2 && jugar == true){ vida = 3; gameover = false; jugar_nivel_2(); if (musica == true){ musica_menu(); } break; }
		if (op == 3 && jugar == true){ vida = 3; gameover = false; jugar_nivel_3(); if (musica == true){ musica_menu(); } break; }
		if (op == 4 && jugar == true){ vida = 3; gameover = false; jugar_nivel_4(); if (musica == true){ musica_menu(); } break; }
		if (op == 5 && jugar == true){ vida = 3; gameover = false; jugar_nivel_5(); if (musica == true){ musica_menu(); } break; }
		if (op == 6 && jugar == true){ vida = 3; gameover = false; jugar_nivel_6(); if (musica == true){ musica_menu(); } break; }
		if (op == 7 && jugar == true){ vida = 3; gameover = false; jugar_nivel_7(); if (musica == true){ musica_menu(); } break; }
		if (op == 8 && jugar == true){ vida = 3; gameover = false; jugar_nivel_8(); if (musica == true){ musica_menu(); } break; }
		if (op == 9 && jugar == true){ vida = 3; gameover = false; jugar_nivel_9(); if (musica == true){ musica_menu(); } break; }
	}
}
void MENU_jugar()
{
	int op_j;
	int tecla;

	imprimir_menu_jugar();
	desplazamiento_menu_jugar(op_j);
	switch (op_j)
	{
	case 1:
	{	gameover = false; vida = 3;
	
		jugar_nivel_1(); if (gameover){ break; }
		Console::Clear();

		jugar_nivel_2(); if (gameover){ break; }
		Console::Clear();

		jugar_nivel_3(); if (gameover){ break; }
		Console::Clear();

		jugar_nivel_4(); if (gameover){ break; }
		Console::Clear();

		jugar_nivel_5(); if (gameover){ break; }
		Console::Clear();

		jugar_nivel_6(); if (gameover){ break; }
		Console::Clear();

		jugar_nivel_7(); if (gameover){ break; }
		Console::Clear(); 

		jugar_nivel_8(); if (gameover){ break; }
		Console::Clear();

		jugar_nivel_9(); if (gameover){ break; }
		Console::Clear();

		if (musica == true){ musica_gracias(); }
		gracias();

		do
		{
			tecla = getch();
			if (tecla == ESC){ break; }
		} while (tecla != ESC);

		detener_musica(); if (musica == true){ musica_menu(); }

		break;
	}
	case 2:
	{
		MENU_ARCADE();

		break;
	}
	case 0:
	{
		break;
	}
	}
}
void MENU_color_nivel()
{
	int op_c;

	while (1)
	{
		imprimir_menu_color_nivel();
		desplazamiento_menu_color_nivel(op_c);

		if (op_c == 1)
		{
			imprimir_menu_color_borde();
			desplazamiento_menu_color_borde();
		}
		if (op_c == 2)
		{
			imprimir_menu_color_vida();
			desplazamiento_menu_color_vida();
		}
		if (op_c == 3)
		{
			imprimir_menu_color_cofre();
			desplazamiento_menu_color_cofre();
		}
		if (op_c == 4)
		{
			imprimir_menu_color_puntos();
			desplazamiento_menu_color_puntos();
		}
		if (op_c == 0)
		{
			break;
		}
	}
}
void MENU_color()
{
	int op_c;

	while (1)
	{
		imprimir_menu_color();
		desplazamiento_menu_color(op_c);
		
		if (op_c == 1)
		{
			imprimir_menu_color_nave();
			desplazamiento_menu_color_nave();		
		}
		if (op_c == 2)
		{
			MENU_color_nivel();
		}
		if (op_c == 0)
		{
			break;
		}
	}
}
void MENU_opciones()
{
	int op_o;

	while (1)
	{
		imprimir_menu_opciones();
		desplazamiento_menu_opciones(op_o);
		
		if (op_o == 1)
		{
			MENU_color();
		}
		if (op_o == 2)
		{
			MENU_elige_nave();
		}
		if (op_o == 3)
		{
			MENU_musica();
		}
		if (op_o == 0)
		{
			break;
		}
	}
}

void JUEGO()
{
	int op;

	if (musica == true){ musica_menu(); }

	while (1)
	{
		imprimir_menu_principal();
		desplazamiento_menu_principal(op);
		
		if (op == 1)
		{
			MENU_jugar();
		}
		if (op == 2)
		{
			MENU_opciones();
		}
		if (op == 3)
		{
			break;
		}
	}
}

int main(array<System::String ^> ^args)
{
	Console::SetWindowSize(70, 35);

	JUEGO();

	return 0;
} 