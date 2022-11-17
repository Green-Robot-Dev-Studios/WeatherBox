#ifndef WEATHER_H
#define WEATHER_H

void set_weather();

double get_temp(int hour);
double get_percipitation(int hour);
double get_wind(int hour);
const char* get_sunrise();
const char* get_sunset();

#endif