#include <list>
#include <iostream>
#include "observer.h"

class WeatherData : public Subject {
public:
    WeatherData() {}
    void registerObserver(Observer* ob) {
        _observer.push_back(ob);
    }

    void removeObserver(Observer* ob) {
        _observer.remove(ob);
    }

    void notifyObservers() {
        for (std::list<Observer*>::iterator iter = _observer.begin(); iter != _observer.end(); iter++) {
            (*iter)->update(temperature, humidity, pressure);
        }
    }

    void measurementsChanged(){
        notifyObservers();
    }

    void setMeasurements(float temperature, float humidity, float pressure) {
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
    }
private:
    std::list<Observer*> _observer;
    float temperature;
    float humidity;
    float pressure;
};


class CurrentConditionDisplay : public Observer, public DisplayElement {
public:
    CurrentConditionDisplay(Subject *weatherData) {
        this->_weatherData = weatherData;
        _weatherData->registerObserver(this);
    }

    void update(float temp, float humidity, float pressure) {
        this->_temperature = temp;
        this->_humidity = humidity;
        display();
    }

    void display() {
        std::cout << "Current condition:" <<std::endl;
        std::cout << "temperature:" << _temperature;
        std::cout << "humidity:" << _humidity;
    }
private:
    float _temperature;
    float _humidity;
    Subject *_weatherData;
};


int main() {
    WeatherData *weatherdata = new WeatherData();
    CurrentConditionDisplay *currentdisplay = new CurrentConditionDisplay(weatherdata);
    weatherdata->setMeasurements(80, 65, 30.4f);
    weatherdata->setMeasurements(82, 89, 98.9f);
    delete weatherdata;
    delete currentdisplay;
}
