import java.io.*;
import java.util.ArrayList;

import org.omg.CORBA.Current;

public class DesignPattern {
    public interface Subject {
        public void registerObserver(Observer o);
        public void removeObserver(Observer o);
        public void notifyObservers();
    }

    public interface Observer{
        public void update(float temp);
    }

    public interface DisplayElement {
        public void display();
    }

    public class WeatherData implements Subject {
        private Arraylist;
        private float temp;
        
        public WeatherData() {
        	observers = new Arraylist();
        }
        
        public void registerObserver(Observer o) {
        	observers.add();
        }
        
        public void removeObserver(Observer o) {
        	int i = observers.indexof(o);
        	if (i >= 0) {
        		observers.remove(i);      		
        	}
        }
        
        public void notifyObservers() {
        	for (int i = 0; i <= observers.size; i++) {
        		Observer observer = (Observer)observers.get(i);
        		observer.update(temp);
        	}
        }
        
        public void measurementschanged() {  	
        	notifyObservers();
        }
        
        public void setMeasurements (float temp) {
        	this.temp = temp;
        	measurementschanged();
        }
    }
    
    public class CurrentConditionsDisplay implements Observer, DisplayElement {
    	private float temp;
    	private Subject weatherData;
    	
    	public CurrentConditionsDisplay (Subject weatherData) {
    		this.weatherData = weatherData;
    		weatherData.registerObserver(this);
    	}
    	
    	public void update(float temp) {
    		this.temp = temp;
    	}
    	
    	public void display {
    		System.out.println("Current + conditions:" + temp);
    	}
    }

    public static void main (String[] args) {
    	WeatherData weatherData = new WeatherData();
    	CurrentConditionsDisplay currentDisplay = new CurrentConditionsDisplay(weatherData);
    	
    	weatherData.setMeasurements(13.00);
    	weatherData.setMeasurements(25.00);
    	weatherData.setMeasurements(22.00);
    }
}
